// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "net/base/upload_bytes_element_reader.h"

#include "base/logging.h"
#include "net/base/io_buffer.h"
#include "net/base/net_errors.h"

#include "starboard/client_porting/poem/string_poem.h"
#include "starboard/memory.h"

namespace net {

UploadBytesElementReader::UploadBytesElementReader(const char* bytes,
                                                   uint64_t length)
    : bytes_(bytes), length_(length), offset_(0) {
}

UploadBytesElementReader::~UploadBytesElementReader() = default;

const UploadBytesElementReader*
UploadBytesElementReader::AsBytesReader() const {
  return this;
}

int UploadBytesElementReader::Init(CompletionOnceCallback callback) {
  offset_ = 0;
  return OK;
}

uint64_t UploadBytesElementReader::GetContentLength() const {
  return length_;
}

uint64_t UploadBytesElementReader::BytesRemaining() const {
  return length_ - offset_;
}

bool UploadBytesElementReader::IsInMemory() const {
  return true;
}

int UploadBytesElementReader::Read(IOBuffer* buf,
                                   int buf_length,
                                   CompletionOnceCallback callback) {
  DCHECK_LT(0, buf_length);

  const int num_bytes_to_read = static_cast<int>(
      std::min(BytesRemaining(), static_cast<uint64_t>(buf_length)));

  // Check if we have anything to copy first, because we are getting
  // the address of an element in |bytes_| and that will throw an
  // exception if |bytes_| is an empty vector.
  if (num_bytes_to_read > 0)
    SbMemoryCopy(buf->data(), bytes_ + offset_, num_bytes_to_read);

  offset_ += num_bytes_to_read;
  return num_bytes_to_read;
}

UploadOwnedBytesElementReader::UploadOwnedBytesElementReader(
    std::vector<char>* data)
    : UploadBytesElementReader(data->data(), data->size()) {
  data_.swap(*data);
}

UploadOwnedBytesElementReader::~UploadOwnedBytesElementReader() = default;

UploadOwnedBytesElementReader*
UploadOwnedBytesElementReader::CreateWithString(const std::string& string) {
  std::vector<char> data(string.begin(), string.end());
  return new UploadOwnedBytesElementReader(&data);
}

}  // namespace net
