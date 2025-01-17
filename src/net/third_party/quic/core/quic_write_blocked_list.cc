// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "net/third_party/quic/core/quic_write_blocked_list.h"

#include "net/third_party/quic/platform/api/quic_flag_utils.h"
#include "net/third_party/quic/platform/api/quic_flags.h"
#include "starboard/memory.h"

namespace quic {

QuicWriteBlockedList::QuicWriteBlockedList() : last_priority_popped_(0) {
  SbMemorySet(batch_write_stream_id_, 0, sizeof(batch_write_stream_id_));
  SbMemorySet(bytes_left_for_batch_write_, 0,
              sizeof(bytes_left_for_batch_write_));
}

QuicWriteBlockedList::~QuicWriteBlockedList() {}

}  // namespace quic
