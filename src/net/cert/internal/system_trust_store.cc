// Copyright 2017 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "net/cert/internal/system_trust_store.h"

#if defined(USE_NSS_CERTS)
#include <cert.h>
#include <pk11pub.h>
#elif defined(OS_MACOSX) && !defined(OS_IOS)
#include <Security/Security.h>
#endif

#include <memory>

#include "base/files/file_path.h"
#include "base/files/file_util.h"
#include "build/build_config.h"
#include "net/cert/internal/cert_errors.h"
#include "net/cert/internal/parsed_certificate.h"
#include "net/cert/internal/trust_store_collection.h"
#include "net/cert/internal/trust_store_in_memory.h"
#include "net/cert/test_root_certs.h"
#include "net/cert/x509_certificate.h"
#include "net/cert/x509_util.h"
#include "starboard/types.h"

#if defined(USE_NSS_CERTS)
#include "crypto/nss_util.h"
#include "net/cert/internal/trust_store_nss.h"
#include "net/cert/known_roots_nss.h"
#include "net/cert/scoped_nss_types.h"
#elif defined(OS_MACOSX) && !defined(OS_IOS)
#include "net/cert/internal/trust_store_mac.h"
#include "net/cert/known_roots_mac.h"
#include "net/cert/x509_util_mac.h"
#elif defined(OS_FUCHSIA)
#include "third_party/boringssl/src/include/openssl/pool.h"
#endif

namespace net {

namespace {

// Abstract implementation of SystemTrustStore to be used as a base class.
// Handles the addition of additional trust anchors.
class BaseSystemTrustStore : public SystemTrustStore {
 public:
  BaseSystemTrustStore() {
    trust_store_.AddTrustStore(&additional_trust_store_);
  }

  void AddTrustAnchor(
      const scoped_refptr<ParsedCertificate>& trust_anchor) override {
    additional_trust_store_.AddTrustAnchor(trust_anchor);
  }

  TrustStore* GetTrustStore() override { return &trust_store_; }

  bool IsAdditionalTrustAnchor(
      const ParsedCertificate* trust_anchor) const override {
    return additional_trust_store_.Contains(trust_anchor);
  }

 protected:
  TrustStoreCollection trust_store_;
  TrustStoreInMemory additional_trust_store_;
};

}  // namespace

#if defined(USE_NSS_CERTS)
namespace {

class SystemTrustStoreNSS : public BaseSystemTrustStore {
 public:
  explicit SystemTrustStoreNSS() : trust_store_nss_(trustSSL) {
    trust_store_.AddTrustStore(&trust_store_nss_);
  }

  bool UsesSystemTrustStore() const override { return true; }

  // IsKnownRoot returns true if the given trust anchor is a standard one (as
  // opposed to a user-installed root)
  bool IsKnownRoot(const ParsedCertificate* trust_anchor) const override {
    // TODO(eroman): The overall approach of IsKnownRoot() is inefficient -- it
    // requires searching for the trust anchor by DER in NSS, however path
    // building already had a handle to it.
    SECItem der_cert;
    der_cert.data = const_cast<uint8_t*>(trust_anchor->der_cert().UnsafeData());
    der_cert.len = trust_anchor->der_cert().Length();
    der_cert.type = siDERCertBuffer;
    ScopedCERTCertificate nss_cert(
        CERT_FindCertByDERCert(CERT_GetDefaultCertDB(), &der_cert));
    if (!nss_cert)
      return false;

    if (!net::IsKnownRoot(nss_cert.get()))
      return false;

    return trust_anchor->der_cert() ==
           der::Input(nss_cert->derCert.data, nss_cert->derCert.len);
  }

 private:
  TrustStoreNSS trust_store_nss_;
};

}  // namespace

std::unique_ptr<SystemTrustStore> CreateSslSystemTrustStore() {
  return std::make_unique<SystemTrustStoreNSS>();
}

#elif defined(OS_MACOSX) && !defined(OS_IOS)

class SystemTrustStoreMac : public BaseSystemTrustStore {
 public:
  explicit SystemTrustStoreMac() : trust_store_mac_(kSecPolicyAppleSSL) {
    InitializeKnownRoots();
    trust_store_.AddTrustStore(&trust_store_mac_);

    // When running in test mode, also layer in the test-only root certificates.
    //
    // Note that this integration requires TestRootCerts::HasInstance() to be
    // true by the time SystemTrustStoreMac is created - a limitation which is
    // acceptable for the test-only code that consumes this.
    if (TestRootCerts::HasInstance()) {
      trust_store_.AddTrustStore(
          TestRootCerts::GetInstance()->test_trust_store());
    }
  }

  bool UsesSystemTrustStore() const override { return true; }

  // IsKnownRoot returns true if the given trust anchor is a standard one (as
  // opposed to a user-installed root)
  bool IsKnownRoot(const ParsedCertificate* trust_anchor) const override {
    der::Input bytes = trust_anchor->der_cert();
    base::ScopedCFTypeRef<SecCertificateRef> cert_ref =
        x509_util::CreateSecCertificateFromBytes(bytes.UnsafeData(),
                                                 bytes.Length());
    if (!cert_ref)
      return false;

    return net::IsKnownRoot(cert_ref);
  }

 private:
  TrustStoreMac trust_store_mac_;
};

std::unique_ptr<SystemTrustStore> CreateSslSystemTrustStore() {
  return std::make_unique<SystemTrustStoreMac>();
}

#elif defined(OS_FUCHSIA)

namespace {

constexpr char kRootCertsFileFuchsia[] = "/config/ssl/cert.pem";

class FuchsiaSystemCerts {
 public:
  FuchsiaSystemCerts() {
    base::FilePath filename(kRootCertsFileFuchsia);
    std::string certs_file;
    if (!base::ReadFileToString(filename, &certs_file)) {
      LOG(ERROR) << "Can't load root certificates from " << filename;
      return;
    }

    CertificateList certs = X509Certificate::CreateCertificateListFromBytes(
        certs_file.data(), certs_file.length(), X509Certificate::FORMAT_AUTO);

    for (const auto& cert : certs) {
      CertErrors errors;
      auto parsed = ParsedCertificate::Create(
          bssl::UpRef(cert->cert_buffer()),
          x509_util::DefaultParseCertificateOptions(), &errors);
      CHECK(parsed) << errors.ToDebugString();
      system_trust_store_.AddTrustAnchor(parsed);
    }
  }

  TrustStoreInMemory* system_trust_store() { return &system_trust_store_; }

 private:
  TrustStoreInMemory system_trust_store_;
};

base::LazyInstance<FuchsiaSystemCerts>::Leaky g_root_certs_fuchsia =
    LAZY_INSTANCE_INITIALIZER;

}  // namespace

class SystemTrustStoreFuchsia : public BaseSystemTrustStore {
 public:
  SystemTrustStoreFuchsia() {
    trust_store_.AddTrustStore(g_root_certs_fuchsia.Get().system_trust_store());
    if (TestRootCerts::HasInstance()) {
      trust_store_.AddTrustStore(
          TestRootCerts::GetInstance()->test_trust_store());
    }
  }

  bool UsesSystemTrustStore() const override { return true; }

  bool IsKnownRoot(const ParsedCertificate* trust_anchor) const override {
    return g_root_certs_fuchsia.Get().system_trust_store()->Contains(
        trust_anchor);
  }
};

std::unique_ptr<SystemTrustStore> CreateSslSystemTrustStore() {
  return std::make_unique<SystemTrustStoreFuchsia>();
}

#elif defined(STARBOARD)

// Starboard does not currently provide support for system trust store access,
// so we indicate that it should not be used.
class SystemTrustStoreStarboard : public BaseSystemTrustStore {
 public:
  SystemTrustStoreStarboard() {
    if (TestRootCerts::HasInstance()) {
      trust_store_.AddTrustStore(
          TestRootCerts::GetInstance()->test_trust_store());
    }
  }

  bool UsesSystemTrustStore() const override { return false; }

  bool IsKnownRoot(const ParsedCertificate* trust_anchor) const override {
    return false;
  }
};

std::unique_ptr<SystemTrustStore> CreateSslSystemTrustStore() {
  return std::make_unique<SystemTrustStoreStarboard>();
}

#else

class DummySystemTrustStore : public BaseSystemTrustStore {
 public:
  bool UsesSystemTrustStore() const override { return false; }

  bool IsKnownRoot(const ParsedCertificate* trust_anchor) const override {
    return false;
  }
};

std::unique_ptr<SystemTrustStore> CreateSslSystemTrustStore() {
  return std::make_unique<DummySystemTrustStore>();
}

#endif

}  // namespace net
