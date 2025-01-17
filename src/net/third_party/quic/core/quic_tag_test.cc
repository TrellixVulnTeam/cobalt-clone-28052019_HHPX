// Copyright (c) 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "net/third_party/quic/core/quic_tag.h"

#include "net/third_party/quic/core/crypto/crypto_protocol.h"
#include "net/third_party/quic/platform/api/quic_test.h"
#include "starboard/memory.h"

namespace quic {
namespace test {
namespace {

class QuicTagTest : public QuicTest {};

TEST_F(QuicTagTest, TagToString) {
  EXPECT_EQ("SCFG", QuicTagToString(kSCFG));
  EXPECT_EQ("SNO ", QuicTagToString(kServerNonceTag));
  EXPECT_EQ("CRT ", QuicTagToString(kCertificateTag));
  EXPECT_EQ("CHLO", QuicTagToString(MakeQuicTag('C', 'H', 'L', 'O')));
  // A tag that contains a non-printing character will be printed as a decimal
  // number.
  EXPECT_EQ("525092931", QuicTagToString(MakeQuicTag('C', 'H', 'L', '\x1f')));
}

TEST_F(QuicTagTest, MakeQuicTag) {
  QuicTag tag = MakeQuicTag('A', 'B', 'C', 'D');
  char bytes[4];
  SbMemoryCopy(bytes, &tag, 4);
  EXPECT_EQ('A', bytes[0]);
  EXPECT_EQ('B', bytes[1]);
  EXPECT_EQ('C', bytes[2]);
  EXPECT_EQ('D', bytes[3]);
}

}  // namespace
}  // namespace test
}  // namespace quic
