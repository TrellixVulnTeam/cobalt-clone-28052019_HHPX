// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "net/third_party/http2/hpack/tools/hpack_block_builder.h"

#include "net/third_party/http2/platform/api/http2_string_utils.h"
#include "testing/gtest/include/gtest/gtest.h"

#if SB_IS(COMPILER_MSVC)
// Converting 0x12 to char.
#pragma warning(disable : 4838)
#endif

namespace http2 {
namespace test {
namespace {
const bool kUncompressed = false;
const bool kCompressed = true;

// TODO(jamessynge): Once static table code is checked in, switch to using
// constants from there.
const uint32_t kStaticTableMethodGET = 2;
const uint32_t kStaticTablePathSlash = 4;
const uint32_t kStaticTableSchemeHttp = 6;

// Tests of encoding per the RFC. See:
//   http://httpwg.org/specs/rfc7541.html#header.field.representation.examples
// The expected values have been copied from the RFC.
TEST(HpackBlockBuilderTest, ExamplesFromSpecC2) {
  {
    HpackBlockBuilder b;
    b.AppendLiteralNameAndValue(HpackEntryType::kIndexedLiteralHeader,
                                kUncompressed, "custom-key", kUncompressed,
                                "custom-header");
    EXPECT_EQ(26u, b.size());

    const char kExpected[] =
        "\x40"            // == Literal indexed ==
        "\x0a"            // Name length (10)
        "custom-key"      // Name
        "\x0d"            // Value length (13)
        "custom-header";  // Value
    EXPECT_EQ(kExpected, b.buffer());
  }
  {
    HpackBlockBuilder b;
    b.AppendNameIndexAndLiteralValue(HpackEntryType::kUnindexedLiteralHeader, 4,
                                     kUncompressed, "/sample/path");
    EXPECT_EQ(14u, b.size());

    const char kExpected[] =
        "\x04"           // == Literal unindexed, name index 0x04 ==
        "\x0c"           // Value length (12)
        "/sample/path";  // Value
    EXPECT_EQ(kExpected, b.buffer());
  }
  {
    HpackBlockBuilder b;
    b.AppendLiteralNameAndValue(HpackEntryType::kNeverIndexedLiteralHeader,
                                kUncompressed, "password", kUncompressed,
                                "secret");
    EXPECT_EQ(17u, b.size());

    const char kExpected[] =
        "\x10"      // == Literal never indexed ==
        "\x08"      // Name length (8)
        "password"  // Name
        "\x06"      // Value length (6)
        "secret";   // Value
    EXPECT_EQ(kExpected, b.buffer());
  }
  {
    HpackBlockBuilder b;
    b.AppendIndexedHeader(2);
    EXPECT_EQ(1u, b.size());

    const char kExpected[] = "\x82";  // == Indexed (2) ==
    EXPECT_EQ(kExpected, b.buffer());
  }
}

// Tests of encoding per the RFC. See:
//  http://httpwg.org/specs/rfc7541.html#request.examples.without.huffman.coding
TEST(HpackBlockBuilderTest, ExamplesFromSpecC3) {
  {
    // Header block to encode:
    //   :method: GET
    //   :scheme: http
    //   :path: /
    //   :authority: www.example.com
    HpackBlockBuilder b;
    b.AppendIndexedHeader(2);  // :method: GET
    b.AppendIndexedHeader(6);  // :scheme: http
    b.AppendIndexedHeader(4);  // :path: /
    b.AppendNameIndexAndLiteralValue(HpackEntryType::kIndexedLiteralHeader, 1,
                                     kUncompressed, "www.example.com");
    EXPECT_EQ(20u, b.size());

    // Hex dump of encoded data (copied from RFC):
    // 0x0000:  8286 8441 0f77 7777 2e65 7861 6d70 6c65  ...A.www.example
    // 0x0010:  2e63 6f6d                                .com

    const Http2String expected =
        Http2HexDecode("828684410f7777772e6578616d706c652e636f6d");
    EXPECT_EQ(expected, b.buffer());
  }
}

// Tests of encoding per the RFC. See:
//   http://httpwg.org/specs/rfc7541.html#request.examples.with.huffman.coding
TEST(HpackBlockBuilderTest, ExamplesFromSpecC4) {
  {
    // Header block to encode:
    //   :method: GET
    //   :scheme: http
    //   :path: /
    //   :authority: www.example.com  (Huffman encoded)
    HpackBlockBuilder b;
    b.AppendIndexedHeader(kStaticTableMethodGET);
    b.AppendIndexedHeader(kStaticTableSchemeHttp);
    b.AppendIndexedHeader(kStaticTablePathSlash);
    const char kHuffmanWwwExampleCom[] = {0xf1u, 0xe3u, 0xc2u, 0xe5u,
                                          0xf2u, 0x3au, 0x6bu, 0xa0u,
                                          0xabu, 0x90u, 0xf4u, 0xffu};
    b.AppendNameIndexAndLiteralValue(
        HpackEntryType::kIndexedLiteralHeader, 1, kCompressed,
        Http2StringPiece(kHuffmanWwwExampleCom, sizeof kHuffmanWwwExampleCom));
    EXPECT_EQ(17u, b.size());

    // Hex dump of encoded data (copied from RFC):
    // 0x0000:  8286 8441 8cf1 e3c2 e5f2 3a6b a0ab 90f4  ...A......:k....
    // 0x0010:  ff                                       .

    const Http2String expected =
        Http2HexDecode("828684418cf1e3c2e5f23a6ba0ab90f4ff");
    EXPECT_EQ(expected, b.buffer());
  }
}

TEST(HpackBlockBuilderTest, DynamicTableSizeUpdate) {
  {
    HpackBlockBuilder b;
    b.AppendDynamicTableSizeUpdate(0);
    EXPECT_EQ(1u, b.size());

    const char kData[] = {0x20};
    Http2StringPiece expected(kData, sizeof kData);
    EXPECT_EQ(expected, b.buffer());
  }
  {
    HpackBlockBuilder b;
    b.AppendDynamicTableSizeUpdate(4096);  // The default size.
    EXPECT_EQ(3u, b.size());

    const char kData[] = {0x3f, 0xe1u, 0x1f};
    Http2StringPiece expected(kData, sizeof kData);
    EXPECT_EQ(expected, b.buffer());
  }
  {
    HpackBlockBuilder b;
    b.AppendDynamicTableSizeUpdate(1000000000000);  // A very large value.
    EXPECT_EQ(7u, b.size());

    const char kData[] = {0x3fu, 0xe1u, 0x9fu, 0x94u, 0xa5u, 0x8du, 0x1du};
    Http2StringPiece expected(kData, sizeof kData);
    EXPECT_EQ(expected, b.buffer());
  }
}

}  // namespace
}  // namespace test
}  // namespace http2
