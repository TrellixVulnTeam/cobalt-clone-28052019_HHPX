
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
// Auto-generated from template: bindings/v8c/templates/enumeration-conversion.cc.template

#include "cobalt/dom/captions/caption_color.h"

#include "v8c_gen_type_conversion.h"
#include "base/logging.h"
#include "cobalt/script/exception_state.h"
#include "cobalt/script/v8c/helpers.h"
#include "v8/include/v8.h"

using cobalt::dom::captions::CaptionColor;

namespace cobalt {
namespace script {
namespace v8c {

void ToJSValue(
    v8::Isolate* isolate,
    CaptionColor in_enum,
    v8::Local<v8::Value>* out_value) {
  switch (in_enum) {
    case cobalt::dom::captions::kCaptionColorBlack:
      ToJSValue(isolate, std::string("black"), out_value);
      return;
    case cobalt::dom::captions::kCaptionColorBlue:
      ToJSValue(isolate, std::string("blue"), out_value);
      return;
    case cobalt::dom::captions::kCaptionColorCyan:
      ToJSValue(isolate, std::string("cyan"), out_value);
      return;
    case cobalt::dom::captions::kCaptionColorGreen:
      ToJSValue(isolate, std::string("green"), out_value);
      return;
    case cobalt::dom::captions::kCaptionColorMagenta:
      ToJSValue(isolate, std::string("magenta"), out_value);
      return;
    case cobalt::dom::captions::kCaptionColorRed:
      ToJSValue(isolate, std::string("red"), out_value);
      return;
    case cobalt::dom::captions::kCaptionColorWhite:
      ToJSValue(isolate, std::string("white"), out_value);
      return;
    case cobalt::dom::captions::kCaptionColorYellow:
      ToJSValue(isolate, std::string("yellow"), out_value);
      return;
    default:
      NOTREACHED();
      *out_value = v8::Null(isolate);
  }
}

void FromJSValue(v8::Isolate* isolate, v8::Local<v8::Value> value,
                 int conversion_flags, ExceptionState* exception_state,
                 CaptionColor* out_enum) {
  DCHECK_EQ(0, conversion_flags) << "Unexpected conversion flags.";
  // JSValue -> IDL enum algorithm described here:
  // http://heycam.github.io/webidl/#es-enumeration
  // 1. Let S be the result of calling ToString(V).
  v8::MaybeLocal<v8::String> maybe_string = value->ToString(isolate->GetCurrentContext());
  v8::Local<v8::String> string;
  if (!maybe_string.ToLocal(&string)) {
    exception_state->SetSimpleException(cobalt::script::kConvertToEnumFailed);
    return;
  }

  bool match = false;
// 3. Return the enumeration value of type E that is equal to S.
 if (
      NewInternalString(isolate, "black")->Equals(value))
  {
    *out_enum = cobalt::dom::captions::kCaptionColorBlack;
  }
 else  if (
      NewInternalString(isolate, "blue")->Equals(value))
  {
    *out_enum = cobalt::dom::captions::kCaptionColorBlue;
  }
 else  if (
      NewInternalString(isolate, "cyan")->Equals(value))
  {
    *out_enum = cobalt::dom::captions::kCaptionColorCyan;
  }
 else  if (
      NewInternalString(isolate, "green")->Equals(value))
  {
    *out_enum = cobalt::dom::captions::kCaptionColorGreen;
  }
 else  if (
      NewInternalString(isolate, "magenta")->Equals(value))
  {
    *out_enum = cobalt::dom::captions::kCaptionColorMagenta;
  }
 else  if (
      NewInternalString(isolate, "red")->Equals(value))
  {
    *out_enum = cobalt::dom::captions::kCaptionColorRed;
  }
 else  if (
      NewInternalString(isolate, "white")->Equals(value))
  {
    *out_enum = cobalt::dom::captions::kCaptionColorWhite;
  }
 else  if (
      NewInternalString(isolate, "yellow")->Equals(value))
  {
    *out_enum = cobalt::dom::captions::kCaptionColorYellow;
  }
  else {
    // 2. If S is not one of E's enumeration values, then throw a TypeError.
    exception_state->SetSimpleException(cobalt::script::kConvertToEnumFailed);
    return;
  }
}

}  // namespace v8c
}  // namespace script
}  // namespace cobalt
