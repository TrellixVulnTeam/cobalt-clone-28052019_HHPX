// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "net/third_party/quic/core/quic_epoll_connection_helper.h"

#include <errno.h>
#include <sys/socket.h>

#include "net/third_party/quic/core/crypto/quic_random.h"
#include "net/third_party/quic/platform/impl/quic_socket_utils.h"
#include "net/tools/epoll_server/epoll_server.h"
#include "starboard/types.h"

namespace quic {

QuicEpollConnectionHelper::QuicEpollConnectionHelper(
    net::EpollServer* epoll_server,
    QuicAllocator type)
    : clock_(epoll_server),
      random_generator_(QuicRandom::GetInstance()),
      allocator_type_(type) {}

QuicEpollConnectionHelper::~QuicEpollConnectionHelper() = default;

const QuicClock* QuicEpollConnectionHelper::GetClock() const {
  return &clock_;
}

QuicRandom* QuicEpollConnectionHelper::GetRandomGenerator() {
  return random_generator_;
}

QuicBufferAllocator* QuicEpollConnectionHelper::GetStreamSendBufferAllocator() {
  if (allocator_type_ == QuicAllocator::BUFFER_POOL) {
    return &stream_buffer_allocator_;
  } else {
    DCHECK(allocator_type_ == QuicAllocator::SIMPLE);
    return &simple_buffer_allocator_;
  }
}

}  // namespace quic
