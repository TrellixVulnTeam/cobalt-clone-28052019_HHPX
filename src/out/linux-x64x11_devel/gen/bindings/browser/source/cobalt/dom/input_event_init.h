// Copyright 2019 The Cobalt Authors. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// clang-format off

// This file has been auto-generated by bindings/code_generator_cobalt.py. DO NOT MODIFY!
// Auto-generated from template: bindings/templates/dictionary.h.template

#ifndef InputEventInit_h
#define InputEventInit_h

#include <string>

#include "base/optional.h"
#include "cobalt/script/array_buffer.h"
#include "cobalt/script/array_buffer_view.h"
#include "cobalt/script/script_value.h"
#include "cobalt/script/sequence.h"
#include "cobalt/script/typed_arrays.h"
#include "cobalt/script/value_handle.h"
#include "cobalt/dom/event_modifier_init.h"

using cobalt::dom::EventModifierInit;

namespace cobalt {
namespace dom {

class InputEventInit : public cobalt::dom::EventModifierInit {
 public:
  InputEventInit() {
    data_ = "";
    is_composing_ = false;
  }

  InputEventInit(const InputEventInit& other)
    : cobalt::dom::EventModifierInit(other) {
    data_ = other.data_;
    is_composing_ = other.is_composing_;
  }

  InputEventInit& operator=(const InputEventInit& other) {
    cobalt::dom::EventModifierInit::operator=(other);
    data_ = other.data_;
    is_composing_ = other.is_composing_;
    return *this;
  }

  bool has_data() const {
    return true;
  }
  const std::string& data() const {
    return data_;
  }
  void set_data(const std::string& value) {
    data_ = value;
  }

  bool has_is_composing() const {
    return true;
  }
  bool is_composing() const {
    return is_composing_;
  }
  void set_is_composing(bool value) {
    is_composing_ = value;
  }


 private:
  std::string data_;
  bool is_composing_;
};

// This ostream override is necessary for MOCK_METHODs commonly used
// in idl test code
inline std::ostream& operator<<(
    std::ostream& stream, const cobalt::dom::InputEventInit& in) {
  SB_UNREFERENCED_PARAMETER(in);
  stream << "[InputEventInit]";
  return stream;
}

}  // namespace cobalt
}  // namespace dom

#endif  // InputEventInit_h