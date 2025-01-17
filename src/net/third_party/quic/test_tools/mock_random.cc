// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "net/third_party/quic/test_tools/mock_random.h"

#include <string.h>

#include "starboard/memory.h"
#include "starboard/types.h"

namespace quic {
namespace test {

MockRandom::MockRandom() : base_(0xDEADBEEF), increment_(0) {}

MockRandom::MockRandom(uint32_t base) : base_(base), increment_(0) {}

void MockRandom::RandBytes(void* data, size_t len) {
  SbMemorySet(data, 'r' + increment_, len);
}

uint64_t MockRandom::RandUint64() {
  return base_ + increment_;
}

void MockRandom::ChangeValue() {
  increment_++;
}

}  // namespace test
}  // namespace quic
