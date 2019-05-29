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

#ifndef WheelEventInit_h
#define WheelEventInit_h

#include <string>

#include "base/optional.h"
#include "cobalt/script/array_buffer.h"
#include "cobalt/script/array_buffer_view.h"
#include "cobalt/script/script_value.h"
#include "cobalt/script/sequence.h"
#include "cobalt/script/typed_arrays.h"
#include "cobalt/script/value_handle.h"
#include "cobalt/dom/mouse_event_init.h"

using cobalt::dom::MouseEventInit;

namespace cobalt {
namespace dom {

class WheelEventInit : public cobalt::dom::MouseEventInit {
 public:
  WheelEventInit() {
    delta_x_ = 0;
    delta_y_ = 0;
    delta_z_ = 0;
    delta_mode_ = 0;
  }

  WheelEventInit(const WheelEventInit& other)
    : cobalt::dom::MouseEventInit(other) {
    delta_x_ = other.delta_x_;
    delta_y_ = other.delta_y_;
    delta_z_ = other.delta_z_;
    delta_mode_ = other.delta_mode_;
  }

  WheelEventInit& operator=(const WheelEventInit& other) {
    cobalt::dom::MouseEventInit::operator=(other);
    delta_x_ = other.delta_x_;
    delta_y_ = other.delta_y_;
    delta_z_ = other.delta_z_;
    delta_mode_ = other.delta_mode_;
    return *this;
  }

  bool has_delta_x() const {
    return true;
  }
  double delta_x() const {
    return delta_x_;
  }
  void set_delta_x(double value) {
    delta_x_ = value;
  }

  bool has_delta_y() const {
    return true;
  }
  double delta_y() const {
    return delta_y_;
  }
  void set_delta_y(double value) {
    delta_y_ = value;
  }

  bool has_delta_z() const {
    return true;
  }
  double delta_z() const {
    return delta_z_;
  }
  void set_delta_z(double value) {
    delta_z_ = value;
  }

  bool has_delta_mode() const {
    return true;
  }
  uint32_t delta_mode() const {
    return delta_mode_;
  }
  void set_delta_mode(uint32_t value) {
    delta_mode_ = value;
  }


 private:
  double delta_x_;
  double delta_y_;
  double delta_z_;
  uint32_t delta_mode_;
};

// This ostream override is necessary for MOCK_METHODs commonly used
// in idl test code
inline std::ostream& operator<<(
    std::ostream& stream, const cobalt::dom::WheelEventInit& in) {
  SB_UNREFERENCED_PARAMETER(in);
  stream << "[WheelEventInit]";
  return stream;
}

}  // namespace cobalt
}  // namespace dom

#endif  // WheelEventInit_h