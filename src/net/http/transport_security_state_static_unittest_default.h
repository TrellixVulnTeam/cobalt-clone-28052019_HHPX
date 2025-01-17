// Copyright 2017 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file is generated by net/tools/transport_security_state_generator/.
// See transport_security_state_static.template for more information on the data
// in this file.

// For Cobalt, we just copied the generated file from Chomium instead of
// generating it at build time.

#include <stdint.h>

#include "base/stl_util.h"
#include "net/http/transport_security_state_source.h"

static const char kSPKIHash_GoodPin1[] =
    "\x36\x7f\x23\x93\x90\x72\xe1\x59\x2a\xe8\x17\x8e\x55\x9e\xd1\xec"
    "\x00\xba\x5d\x45\x01\x66\xc5\xa6\x51\xb2\x51\xd5\xfd\x58\xe4\x56";

static const char kSPKIHash_TestSPKI1[] =
    "\xc3\x7c\xbb\x62\x0d\xd1\xce\x40\x32\x84\x27\x81\xa0\xb1\xe6\xef"
    "\x56\x11\x9e\xeb\x94\x5b\xce\xc0\x01\x1f\xc3\x56\x92\xcc\x4f\x0e";

static const char* const kExpectCTReportURIs[] = {
    "http://report-uri.preloaded.test/expect-ct", nullptr,
};

static const char* const kNoRejectedPublicKeys[] = {
    NULL,
};

static const char* const kWithRejectedPinsAcceptableCerts[] = {
    kSPKIHash_GoodPin1, nullptr,
};
static const char* const kWithRejectedPinsRejectedCerts[] = {
    kSPKIHash_TestSPKI1, nullptr,
};

static const char* const kWithReportUriAcceptableCerts[] = {
    kSPKIHash_GoodPin1, nullptr,
};
static const char kWithReportUriReportURI[] =
    "http://report-uri.preloaded.test/pkp";

static const char* const kWithoutRejectedPinsAcceptableCerts[] = {
    kSPKIHash_TestSPKI1, kSPKIHash_GoodPin1, nullptr,
};

static const struct net::TransportSecurityStateSource::Pinset kPinsets[] = {
    {kWithRejectedPinsAcceptableCerts, kWithRejectedPinsRejectedCerts,
     kNoReportURI},
    {kWithReportUriAcceptableCerts, kNoRejectedPublicKeys,
     kWithReportUriReportURI},
    {kWithoutRejectedPinsAcceptableCerts, kNoRejectedPublicKeys, kNoReportURI},
};

static const uint8_t kHSTSHuffmanTree[] = {
    0xee, 0xf7, 0x00, 0xf3, 0x01, 0xe5, 0xf8, 0xe3, 0x03, 0xf4, 0x04, 0xff,
    0x02, 0x05, 0xe2, 0xe7, 0xea, 0x07, 0x08, 0xeb, 0xe4, 0x09, 0x0a, 0x80,
    0xae, 0xef, 0xad, 0x0c, 0x0b, 0x0d, 0xf5, 0xe8, 0xf2, 0x0f, 0x10, 0xf0,
    0xec, 0xed, 0xe1, 0xe9, 0x12, 0x13, 0x11, 0x14, 0x0e, 0x15, 0x06, 0x16,
};

static const uint8_t kPreloadedHSTSData[] = {
    0xef, 0xfb, 0xb2, 0x24, 0x3c, 0x10, 0xc8, 0x90, 0xff, 0xfb, 0x17, 0xb1,
    0xe6, 0xf7, 0xc8, 0x36, 0xe1, 0xe1, 0x04, 0x91, 0xff, 0xff, 0x5d, 0x36,
    0x3c, 0xde, 0xf9, 0x06, 0xdc, 0xff, 0xbb, 0x22, 0x43, 0xff, 0x47, 0xb9,
    0xd0, 0xa8, 0xe7, 0x26, 0x43, 0xff, 0xff, 0xc2, 0x0f, 0xfb, 0xb7, 0x84,
    0x56, 0x43, 0x46, 0x19, 0x71, 0x20, 0xfc, 0xdf, 0x28, 0xe7, 0x24, 0xa3,
    0xf5, 0x6d, 0x47, 0x18, 0xc2, 0xd5, 0xff, 0xfe, 0xc6, 0x54, 0xb8, 0xbe,
    0x9c, 0x56, 0x6b, 0xf0, 0xc8, 0x88, 0xff, 0xff, 0x81, 0xfd, 0xa8, 0x15,
    0x49, 0x88, 0x71, 0x57, 0x04, 0x89, 0x0f, 0xa3, 0xda, 0xfa, 0x31, 0x45,
    0x85, 0xf6, 0xc7, 0xb2, 0x24, 0x83, 0xff, 0x26, 0x95, 0x27, 0x50, 0x64,
    0x21, 0x46, 0x9d, 0xb5, 0x14, 0x6a, 0xb4, 0xff, 0xc6, 0x1e, 0xbf, 0x0e,
    0x36, 0x93, 0xaf, 0xb4, 0x71, 0xcf, 0xf7, 0x37, 0xbe, 0x41, 0x91, 0x21,
    0xf8, 0x4a, 0xda, 0x08, 0x87, 0x2a, 0x8d, 0x16, 0xb8, 0x29, 0xd5, 0xf5,
    0x97, 0x00, 0xc0,
};

static const unsigned kPreloadedHSTSBits = 1170;
static const unsigned kHSTSRootPosition = 1110;

static const net::TransportSecurityStateSource kHSTSSource = {
    kHSTSHuffmanTree,   sizeof(kHSTSHuffmanTree), kPreloadedHSTSData,
    kPreloadedHSTSBits, kHSTSRootPosition,        kExpectCTReportURIs,
    kPinsets,           base::size(kPinsets)};