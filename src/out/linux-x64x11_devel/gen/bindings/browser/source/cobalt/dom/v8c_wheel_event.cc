

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
// Auto-generated from template: bindings/v8c/templates/interface.cc.template

#include "cobalt/dom/v8c_wheel_event.h"

#include "base/trace_event/trace_event.h"
#include "cobalt/base/polymorphic_downcast.h"
#include "cobalt/script/global_environment.h"
#include "cobalt/script/script_value.h"
#include "cobalt/script/value_handle.h"
#include "cobalt/dom/event_target.h"
#include "cobalt/dom/mouse_event.h"
#include "cobalt/dom/v8c_event_target.h"
#include "cobalt/dom/v8c_mouse_event.h"
#include "cobalt/dom/v8c_window.h"
#include "cobalt/dom/wheel_event_init.h"
#include "cobalt/dom/window.h"

#include "v8c_gen_type_conversion.h"

#include "cobalt/script/callback_interface_traits.h"
#include "cobalt/script/v8c/v8c_array_buffer.h"
#include "cobalt/script/v8c/v8c_array_buffer_view.h"
#include "cobalt/script/v8c/callback_function_conversion.h"
#include "cobalt/script/v8c/conversion_helpers.h"
#include "cobalt/script/v8c/entry_scope.h"
#include "cobalt/script/v8c/helpers.h"
#include "cobalt/script/v8c/native_promise.h"
#include "cobalt/script/v8c/type_traits.h"
#include "cobalt/script/v8c/v8c_typed_arrays.h"
#include "cobalt/script/v8c/v8c_data_view.h"
#include "cobalt/script/v8c/v8c_callback_function.h"
#include "cobalt/script/v8c/v8c_callback_interface_holder.h"
#include "cobalt/script/v8c/v8c_engine.h"
#include "cobalt/script/v8c/v8c_exception_state.h"
#include "cobalt/script/v8c/v8c_global_environment.h"
#include "cobalt/script/v8c/v8c_property_enumerator.h"
#include "cobalt/script/v8c/v8c_value_handle.h"
#include "cobalt/script/v8c/wrapper_private.h"
#include "v8/include/v8.h"


namespace {
using cobalt::dom::WheelEvent;
using cobalt::dom::V8cWheelEvent;
using cobalt::dom::EventTarget;
using cobalt::dom::MouseEvent;
using cobalt::dom::V8cEventTarget;
using cobalt::dom::V8cMouseEvent;
using cobalt::dom::V8cWindow;
using cobalt::dom::WheelEventInit;
using cobalt::dom::Window;
using cobalt::script::CallbackInterfaceTraits;
using cobalt::script::GlobalEnvironment;
using cobalt::script::ScriptValue;
using cobalt::script::ValueHandle;
using cobalt::script::ValueHandle;
using cobalt::script::ValueHandleHolder;
using cobalt::script::Wrappable;

using cobalt::script::v8c::EntryScope;
using cobalt::script::v8c::EscapableEntryScope;
using cobalt::script::v8c::FromJSValue;
using cobalt::script::v8c::kConversionFlagClamped;
using cobalt::script::v8c::kConversionFlagNullable;
using cobalt::script::v8c::kConversionFlagObjectOnly;
using cobalt::script::v8c::kConversionFlagRestricted;
using cobalt::script::v8c::kConversionFlagTreatNullAsEmptyString;
using cobalt::script::v8c::kConversionFlagTreatUndefinedAsEmptyString;
using cobalt::script::v8c::kNoConversionFlags;
using cobalt::script::v8c::NewInternalString;
using cobalt::script::v8c::ToJSValue;
using cobalt::script::v8c::TypeTraits;
using cobalt::script::v8c::V8cExceptionState;
using cobalt::script::v8c::V8cGlobalEnvironment;
using cobalt::script::v8c::V8cPropertyEnumerator;
using cobalt::script::v8c::WrapperFactory;
using cobalt::script::v8c::WrapperPrivate;
}  // namespace

namespace cobalt {
namespace dom {


namespace {

const int kInterfaceUniqueId = 219;









void Constructor(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  V8cExceptionState exception_state(isolate);
  const size_t kMinArguments = 1;
  if (info.Length() < kMinArguments) {
    exception_state.SetSimpleException(script::kInvalidNumberOfArguments);
    return;
  }
  // Non-optional arguments
  TypeTraits<std::string >::ConversionType type;
  // Optional arguments
  TypeTraits<WheelEventInit >::ConversionType eventInitDict;
  DCHECK_LT(0, info.Length());
  v8::Local<v8::Value> non_optional_value0 = info[0];
  FromJSValue(isolate,
              non_optional_value0,
              kNoConversionFlags,
              &exception_state, &type);
  if (exception_state.is_exception_set()) {
    return;
  }
  size_t num_set_arguments = 1;
  if (info.Length() > 1) {
    v8::Local<v8::Value> optional_value0 = info[1];
    FromJSValue(isolate,
                optional_value0,
                kNoConversionFlags,
                &exception_state,
                &eventInitDict);
    if (exception_state.is_exception_set()) {
      return;
    }
    ++num_set_arguments;
  }
  switch (num_set_arguments) {
    case 1:
      {  if (!info.IsConstructCall()) {
            exception_state.SetSimpleException(script::kTypeError, "Illegal constructor");
            return;
          }
        
          scoped_refptr<WheelEvent> new_object =
              new WheelEvent(type);
          v8::Local<v8::Value> result_value;
          ToJSValue(isolate, new_object, &result_value);
          DCHECK(result_value->IsObject());
          info.GetReturnValue().Set(result_value);
      }
      break;
    case 2:
      {  if (!info.IsConstructCall()) {
            exception_state.SetSimpleException(script::kTypeError, "Illegal constructor");
            return;
          }
        
          scoped_refptr<WheelEvent> new_object =
              new WheelEvent(type, eventInitDict);
          v8::Local<v8::Value> result_value;
          ToJSValue(isolate, new_object, &result_value);
          DCHECK(result_value->IsObject());
          info.GetReturnValue().Set(result_value);
      }
      break;
    default:
      NOTREACHED();
      return;
  }
}



void deltaXAttributeGetter(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  v8::Local<v8::Object> object = info.Holder();


  V8cGlobalEnvironment* global_environment = V8cGlobalEnvironment::GetFromIsolate(isolate);
  WrapperFactory* wrapper_factory = global_environment->wrapper_factory();
  if (!WrapperPrivate::HasWrapperPrivate(object) ||
      !V8cWheelEvent::GetTemplate(isolate)->HasInstance(object)) {
    V8cExceptionState exception(isolate);
    exception.SetSimpleException(script::kDoesNotImplementInterface);
    return;
  }
  V8cExceptionState exception_state{isolate};
  v8::Local<v8::Value> result_value;

  WrapperPrivate* wrapper_private =
      WrapperPrivate::GetFromWrapperObject(object);
  if (!wrapper_private) {
    NOTIMPLEMENTED();
    return;
  }
  WheelEvent* impl =
      wrapper_private->wrappable<WheelEvent>().get();


  if (!exception_state.is_exception_set()) {
    ToJSValue(isolate,
              impl->delta_x(),
              &result_value);
  }
  if (exception_state.is_exception_set()) {
    return;
  }
  info.GetReturnValue().Set(result_value);
}



void deltaYAttributeGetter(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  v8::Local<v8::Object> object = info.Holder();


  V8cGlobalEnvironment* global_environment = V8cGlobalEnvironment::GetFromIsolate(isolate);
  WrapperFactory* wrapper_factory = global_environment->wrapper_factory();
  if (!WrapperPrivate::HasWrapperPrivate(object) ||
      !V8cWheelEvent::GetTemplate(isolate)->HasInstance(object)) {
    V8cExceptionState exception(isolate);
    exception.SetSimpleException(script::kDoesNotImplementInterface);
    return;
  }
  V8cExceptionState exception_state{isolate};
  v8::Local<v8::Value> result_value;

  WrapperPrivate* wrapper_private =
      WrapperPrivate::GetFromWrapperObject(object);
  if (!wrapper_private) {
    NOTIMPLEMENTED();
    return;
  }
  WheelEvent* impl =
      wrapper_private->wrappable<WheelEvent>().get();


  if (!exception_state.is_exception_set()) {
    ToJSValue(isolate,
              impl->delta_y(),
              &result_value);
  }
  if (exception_state.is_exception_set()) {
    return;
  }
  info.GetReturnValue().Set(result_value);
}



void deltaZAttributeGetter(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  v8::Local<v8::Object> object = info.Holder();


  V8cGlobalEnvironment* global_environment = V8cGlobalEnvironment::GetFromIsolate(isolate);
  WrapperFactory* wrapper_factory = global_environment->wrapper_factory();
  if (!WrapperPrivate::HasWrapperPrivate(object) ||
      !V8cWheelEvent::GetTemplate(isolate)->HasInstance(object)) {
    V8cExceptionState exception(isolate);
    exception.SetSimpleException(script::kDoesNotImplementInterface);
    return;
  }
  V8cExceptionState exception_state{isolate};
  v8::Local<v8::Value> result_value;

  WrapperPrivate* wrapper_private =
      WrapperPrivate::GetFromWrapperObject(object);
  if (!wrapper_private) {
    NOTIMPLEMENTED();
    return;
  }
  WheelEvent* impl =
      wrapper_private->wrappable<WheelEvent>().get();


  if (!exception_state.is_exception_set()) {
    ToJSValue(isolate,
              impl->delta_z(),
              &result_value);
  }
  if (exception_state.is_exception_set()) {
    return;
  }
  info.GetReturnValue().Set(result_value);
}



void deltaModeAttributeGetter(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  v8::Local<v8::Object> object = info.Holder();


  V8cGlobalEnvironment* global_environment = V8cGlobalEnvironment::GetFromIsolate(isolate);
  WrapperFactory* wrapper_factory = global_environment->wrapper_factory();
  if (!WrapperPrivate::HasWrapperPrivate(object) ||
      !V8cWheelEvent::GetTemplate(isolate)->HasInstance(object)) {
    V8cExceptionState exception(isolate);
    exception.SetSimpleException(script::kDoesNotImplementInterface);
    return;
  }
  V8cExceptionState exception_state{isolate};
  v8::Local<v8::Value> result_value;

  WrapperPrivate* wrapper_private =
      WrapperPrivate::GetFromWrapperObject(object);
  if (!wrapper_private) {
    NOTIMPLEMENTED();
    return;
  }
  WheelEvent* impl =
      wrapper_private->wrappable<WheelEvent>().get();


  if (!exception_state.is_exception_set()) {
    ToJSValue(isolate,
              impl->delta_mode(),
              &result_value);
  }
  if (exception_state.is_exception_set()) {
    return;
  }
  info.GetReturnValue().Set(result_value);
}




void initWheelEventMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  v8::Local<v8::Object> object = info.Holder();
  V8cGlobalEnvironment* global_environment = V8cGlobalEnvironment::GetFromIsolate(isolate);
  WrapperFactory* wrapper_factory = global_environment->wrapper_factory();
  if (!WrapperPrivate::HasWrapperPrivate(object) ||
      !V8cWheelEvent::GetTemplate(isolate)->HasInstance(object)) {
    V8cExceptionState exception(isolate);
    exception.SetSimpleException(script::kDoesNotImplementInterface);
    return;
  }
  V8cExceptionState exception_state{isolate};
  v8::Local<v8::Value> result_value;

  WrapperPrivate* wrapper_private =
      WrapperPrivate::GetFromWrapperObject(object);
  if (!wrapper_private) {
    NOTIMPLEMENTED();
    return;
  }
  WheelEvent* impl =
      wrapper_private->wrappable<WheelEvent>().get();
  const size_t kMinArguments = 1;
  if (info.Length() < kMinArguments) {
    exception_state.SetSimpleException(script::kInvalidNumberOfArguments);
    return;
  }
  // Non-optional arguments
  TypeTraits<std::string >::ConversionType type;
  // Optional arguments with default values
  TypeTraits<bool >::ConversionType bubbles =
      false;
  TypeTraits<bool >::ConversionType cancelable =
      false;
  TypeTraits<scoped_refptr<Window> >::ConversionType view =
      NULL;
  TypeTraits<int32_t >::ConversionType detail =
      0;
  TypeTraits<int32_t >::ConversionType screenX =
      0;
  TypeTraits<int32_t >::ConversionType screenY =
      0;
  TypeTraits<int32_t >::ConversionType clientX =
      0;
  TypeTraits<int32_t >::ConversionType clientY =
      0;
  TypeTraits<uint16_t >::ConversionType button =
      0;
  TypeTraits<scoped_refptr<EventTarget> >::ConversionType relatedTarget =
      NULL;
  TypeTraits<std::string >::ConversionType modifiersList =
      "";
  TypeTraits<double >::ConversionType deltaX =
      0;
  TypeTraits<double >::ConversionType deltaY =
      0;
  TypeTraits<double >::ConversionType deltaZ =
      0;
  TypeTraits<uint32_t >::ConversionType deltaMode =
      0;
  DCHECK_LT(0, info.Length());
  v8::Local<v8::Value> non_optional_value0 = info[0];
  FromJSValue(isolate,
              non_optional_value0,
              kNoConversionFlags,
              &exception_state, &type);
  if (exception_state.is_exception_set()) {
    return;
  }
  size_t num_set_arguments = 16;
  if (info.Length() > 1) {
    v8::Local<v8::Value> optional_value0 = info[1];
    FromJSValue(isolate,
                optional_value0,
                kNoConversionFlags,
                &exception_state,
                &bubbles);
    if (exception_state.is_exception_set()) {
      return;
    }
  }
  if (info.Length() > 2) {
    v8::Local<v8::Value> optional_value1 = info[2];
    FromJSValue(isolate,
                optional_value1,
                kNoConversionFlags,
                &exception_state,
                &cancelable);
    if (exception_state.is_exception_set()) {
      return;
    }
  }
  if (info.Length() > 3) {
    v8::Local<v8::Value> optional_value2 = info[3];
    FromJSValue(isolate,
                optional_value2,
                (kConversionFlagNullable),
                &exception_state,
                &view);
    if (exception_state.is_exception_set()) {
      return;
    }
  }
  if (info.Length() > 4) {
    v8::Local<v8::Value> optional_value3 = info[4];
    FromJSValue(isolate,
                optional_value3,
                kNoConversionFlags,
                &exception_state,
                &detail);
    if (exception_state.is_exception_set()) {
      return;
    }
  }
  if (info.Length() > 5) {
    v8::Local<v8::Value> optional_value4 = info[5];
    FromJSValue(isolate,
                optional_value4,
                kNoConversionFlags,
                &exception_state,
                &screenX);
    if (exception_state.is_exception_set()) {
      return;
    }
  }
  if (info.Length() > 6) {
    v8::Local<v8::Value> optional_value5 = info[6];
    FromJSValue(isolate,
                optional_value5,
                kNoConversionFlags,
                &exception_state,
                &screenY);
    if (exception_state.is_exception_set()) {
      return;
    }
  }
  if (info.Length() > 7) {
    v8::Local<v8::Value> optional_value6 = info[7];
    FromJSValue(isolate,
                optional_value6,
                kNoConversionFlags,
                &exception_state,
                &clientX);
    if (exception_state.is_exception_set()) {
      return;
    }
  }
  if (info.Length() > 8) {
    v8::Local<v8::Value> optional_value7 = info[8];
    FromJSValue(isolate,
                optional_value7,
                kNoConversionFlags,
                &exception_state,
                &clientY);
    if (exception_state.is_exception_set()) {
      return;
    }
  }
  if (info.Length() > 9) {
    v8::Local<v8::Value> optional_value8 = info[9];
    FromJSValue(isolate,
                optional_value8,
                kNoConversionFlags,
                &exception_state,
                &button);
    if (exception_state.is_exception_set()) {
      return;
    }
  }
  if (info.Length() > 10) {
    v8::Local<v8::Value> optional_value9 = info[10];
    FromJSValue(isolate,
                optional_value9,
                (kConversionFlagNullable),
                &exception_state,
                &relatedTarget);
    if (exception_state.is_exception_set()) {
      return;
    }
  }
  if (info.Length() > 11) {
    v8::Local<v8::Value> optional_value10 = info[11];
    FromJSValue(isolate,
                optional_value10,
                kNoConversionFlags,
                &exception_state,
                &modifiersList);
    if (exception_state.is_exception_set()) {
      return;
    }
  }
  if (info.Length() > 12) {
    v8::Local<v8::Value> optional_value11 = info[12];
    FromJSValue(isolate,
                optional_value11,
                (kConversionFlagRestricted),
                &exception_state,
                &deltaX);
    if (exception_state.is_exception_set()) {
      return;
    }
  }
  if (info.Length() > 13) {
    v8::Local<v8::Value> optional_value12 = info[13];
    FromJSValue(isolate,
                optional_value12,
                (kConversionFlagRestricted),
                &exception_state,
                &deltaY);
    if (exception_state.is_exception_set()) {
      return;
    }
  }
  if (info.Length() > 14) {
    v8::Local<v8::Value> optional_value13 = info[14];
    FromJSValue(isolate,
                optional_value13,
                (kConversionFlagRestricted),
                &exception_state,
                &deltaZ);
    if (exception_state.is_exception_set()) {
      return;
    }
  }
  if (info.Length() > 15) {
    v8::Local<v8::Value> optional_value14 = info[15];
    FromJSValue(isolate,
                optional_value14,
                kNoConversionFlags,
                &exception_state,
                &deltaMode);
    if (exception_state.is_exception_set()) {
      return;
    }
  }

  impl->InitWheelEvent(type, bubbles, cancelable, view, detail, screenX, screenY, clientX, clientY, button, relatedTarget, modifiersList, deltaX, deltaY, deltaZ, deltaMode);
  result_value = v8::Undefined(isolate);

}



void InitializeTemplate(v8::Isolate* isolate) {
  // https://heycam.github.io/webidl/#interface-object
  // 3.6.1. Interface object
  //
  // The interface object for a given interface is a built-in function object.
  // It has properties that correspond to the constants and static operations
  // defined on that interface, as described in sections 3.6.6 Constants and
  // 3.6.8 Operations.
  //
  // If the interface is declared with a [Constructor] extended attribute,
  // then the interface object can be called as a constructor to create an
  // object that implements that interface. Calling that interface as a
  // function will throw an exception.
  //
  // Interface objects whose interfaces are not declared with a [Constructor]
  // extended attribute will throw when called, both as a function and as a
  // constructor.
  //
  // An interface object for a non-callback interface has an associated object
  // called the interface prototype object. This object has properties that
  // correspond to the regular attributes and regular operations defined on
  // the interface, and is described in more detail in 3.6.3 Interface
  // prototype object.
  v8::Local<v8::FunctionTemplate> function_template =
      v8::FunctionTemplate::New(
          isolate,
          Constructor,
          v8::Local<v8::Value>(),
          v8::Local<v8::Signature>(),
          1);
  function_template->SetLength(1);
  function_template->SetClassName(NewInternalString(isolate, "WheelEvent"));
  function_template->ReadOnlyPrototype();

  v8::Local<v8::ObjectTemplate> prototype_template = function_template->PrototypeTemplate();
  v8::Local<v8::ObjectTemplate> instance_template = function_template->InstanceTemplate();
  instance_template->SetInternalFieldCount(WrapperPrivate::kInternalFieldCount);

  V8cGlobalEnvironment* global_environment = V8cGlobalEnvironment::GetFromIsolate(isolate);
  global_environment->AddInterfaceData(kInterfaceUniqueId, function_template);

  {
    // An interface can be defined to inherit from another interface. If the
    // identifier of the interface is followed by a U+003A COLON (":") character
    // and an identifier, then that identifier identifies the inherited
    // interface. An object that implements an interface that inherits from
    // another also implements that inherited interface. The object therefore
    // will also have members that correspond to the interface members from the
    // inherited interface.
    v8::Local<v8::FunctionTemplate> parent_template = V8cMouseEvent::GetTemplate(isolate);
    function_template->Inherit(parent_template);
    static_assert(
        std::is_base_of<MouseEvent, WheelEvent>::value,
        "Expected WheelEvent to have C++ parent class "
        "MouseEvent, because that is its WebIDL parent.");
  }

  // https://heycam.github.io/webidl/#es-constants
  // 3.6.6. Constants
  //
  // For each exposed constant defined on an interface A, there must be a
  // corresponding property. The property has the following characteristics:
  {
    // The name of the property is the identifier of the constant.
    v8::Local<v8::String> name = NewInternalString(
        isolate,
        "DOM_DELTA_PIXEL");

    // The value of the property is that which is obtained by converting the
    // constant's IDL value to an ECMAScript value.
    v8::Local<v8::Value> constant_value;
    ToJSValue(isolate, 0x00, &constant_value);

    // The property has attributes { [[Writable]]: false, [[Enumerable]]: true,
    // [[Configurable]]: false }.
    v8::PropertyAttribute attributes = static_cast<v8::PropertyAttribute>(
        v8::ReadOnly | v8::DontDelete);

    // The location of the property is determined as follows:
    // Otherwise, if the interface has an interface prototype object, then the
    // property exists on it.
    prototype_template->Set(name, constant_value, attributes);

    // In addition, a property with the same characteristics must exist on the
    // interface object or the legacy callback interface object, if either of
    // those objects exists.
    function_template->Set(name, constant_value, attributes);
  }
  {
    // The name of the property is the identifier of the constant.
    v8::Local<v8::String> name = NewInternalString(
        isolate,
        "DOM_DELTA_LINE");

    // The value of the property is that which is obtained by converting the
    // constant's IDL value to an ECMAScript value.
    v8::Local<v8::Value> constant_value;
    ToJSValue(isolate, 0x01, &constant_value);

    // The property has attributes { [[Writable]]: false, [[Enumerable]]: true,
    // [[Configurable]]: false }.
    v8::PropertyAttribute attributes = static_cast<v8::PropertyAttribute>(
        v8::ReadOnly | v8::DontDelete);

    // The location of the property is determined as follows:
    // Otherwise, if the interface has an interface prototype object, then the
    // property exists on it.
    prototype_template->Set(name, constant_value, attributes);

    // In addition, a property with the same characteristics must exist on the
    // interface object or the legacy callback interface object, if either of
    // those objects exists.
    function_template->Set(name, constant_value, attributes);
  }
  {
    // The name of the property is the identifier of the constant.
    v8::Local<v8::String> name = NewInternalString(
        isolate,
        "DOM_DELTA_PAGE");

    // The value of the property is that which is obtained by converting the
    // constant's IDL value to an ECMAScript value.
    v8::Local<v8::Value> constant_value;
    ToJSValue(isolate, 0x02, &constant_value);

    // The property has attributes { [[Writable]]: false, [[Enumerable]]: true,
    // [[Configurable]]: false }.
    v8::PropertyAttribute attributes = static_cast<v8::PropertyAttribute>(
        v8::ReadOnly | v8::DontDelete);

    // The location of the property is determined as follows:
    // Otherwise, if the interface has an interface prototype object, then the
    // property exists on it.
    prototype_template->Set(name, constant_value, attributes);

    // In addition, a property with the same characteristics must exist on the
    // interface object or the legacy callback interface object, if either of
    // those objects exists.
    function_template->Set(name, constant_value, attributes);
  }

  // https://heycam.github.io/webidl/#es-attributes
  // 3.6.7. Attributes
  //
  // For each exposed attribute of the interface there must exist a
  // corresponding property. The characteristics of this property are as
  // follows:
  {
    // The name of the property is the identifier of the attribute.
    v8::Local<v8::String> name = NewInternalString(
        isolate,
        "deltaX");

    // The property has attributes { [[Get]]: G, [[Set]]: S, [[Enumerable]]:
    // true, [[Configurable]]: configurable }, where: configurable is false if
    // the attribute was declared with the [Unforgeable] extended attribute and
    // true otherwise;
    bool configurable = true;
    v8::PropertyAttribute attributes = static_cast<v8::PropertyAttribute>(
        configurable ? v8::None : v8::DontDelete);

    // G is the attribute getter created given the attribute, the interface, and
    // the relevant Realm of the object that is the location of the property;
    // and
    //
    // S is the attribute setter created given the attribute, the interface, and
    // the relevant Realm of the object that is the location of the property.
    v8::Local<v8::FunctionTemplate> getter =
        v8::FunctionTemplate::New(isolate, deltaXAttributeGetter);
    v8::Local<v8::FunctionTemplate> setter;

    // The location of the property is determined as follows:
    // Otherwise, the property exists solely on the interface's interface
    // prototype object.
    prototype_template->
        SetAccessorProperty(
            name,
            getter,
            setter,
            attributes);

  }
  {
    // The name of the property is the identifier of the attribute.
    v8::Local<v8::String> name = NewInternalString(
        isolate,
        "deltaY");

    // The property has attributes { [[Get]]: G, [[Set]]: S, [[Enumerable]]:
    // true, [[Configurable]]: configurable }, where: configurable is false if
    // the attribute was declared with the [Unforgeable] extended attribute and
    // true otherwise;
    bool configurable = true;
    v8::PropertyAttribute attributes = static_cast<v8::PropertyAttribute>(
        configurable ? v8::None : v8::DontDelete);

    // G is the attribute getter created given the attribute, the interface, and
    // the relevant Realm of the object that is the location of the property;
    // and
    //
    // S is the attribute setter created given the attribute, the interface, and
    // the relevant Realm of the object that is the location of the property.
    v8::Local<v8::FunctionTemplate> getter =
        v8::FunctionTemplate::New(isolate, deltaYAttributeGetter);
    v8::Local<v8::FunctionTemplate> setter;

    // The location of the property is determined as follows:
    // Otherwise, the property exists solely on the interface's interface
    // prototype object.
    prototype_template->
        SetAccessorProperty(
            name,
            getter,
            setter,
            attributes);

  }
  {
    // The name of the property is the identifier of the attribute.
    v8::Local<v8::String> name = NewInternalString(
        isolate,
        "deltaZ");

    // The property has attributes { [[Get]]: G, [[Set]]: S, [[Enumerable]]:
    // true, [[Configurable]]: configurable }, where: configurable is false if
    // the attribute was declared with the [Unforgeable] extended attribute and
    // true otherwise;
    bool configurable = true;
    v8::PropertyAttribute attributes = static_cast<v8::PropertyAttribute>(
        configurable ? v8::None : v8::DontDelete);

    // G is the attribute getter created given the attribute, the interface, and
    // the relevant Realm of the object that is the location of the property;
    // and
    //
    // S is the attribute setter created given the attribute, the interface, and
    // the relevant Realm of the object that is the location of the property.
    v8::Local<v8::FunctionTemplate> getter =
        v8::FunctionTemplate::New(isolate, deltaZAttributeGetter);
    v8::Local<v8::FunctionTemplate> setter;

    // The location of the property is determined as follows:
    // Otherwise, the property exists solely on the interface's interface
    // prototype object.
    prototype_template->
        SetAccessorProperty(
            name,
            getter,
            setter,
            attributes);

  }
  {
    // The name of the property is the identifier of the attribute.
    v8::Local<v8::String> name = NewInternalString(
        isolate,
        "deltaMode");

    // The property has attributes { [[Get]]: G, [[Set]]: S, [[Enumerable]]:
    // true, [[Configurable]]: configurable }, where: configurable is false if
    // the attribute was declared with the [Unforgeable] extended attribute and
    // true otherwise;
    bool configurable = true;
    v8::PropertyAttribute attributes = static_cast<v8::PropertyAttribute>(
        configurable ? v8::None : v8::DontDelete);

    // G is the attribute getter created given the attribute, the interface, and
    // the relevant Realm of the object that is the location of the property;
    // and
    //
    // S is the attribute setter created given the attribute, the interface, and
    // the relevant Realm of the object that is the location of the property.
    v8::Local<v8::FunctionTemplate> getter =
        v8::FunctionTemplate::New(isolate, deltaModeAttributeGetter);
    v8::Local<v8::FunctionTemplate> setter;

    // The location of the property is determined as follows:
    // Otherwise, the property exists solely on the interface's interface
    // prototype object.
    prototype_template->
        SetAccessorProperty(
            name,
            getter,
            setter,
            attributes);

  }

  // https://heycam.github.io/webidl/#es-operations
  // 3.6.8. Operations
  //
  // For each unique identifier of an exposed operation defined on the
  // interface, there must exist a corresponding property, unless the effective
  // overload set for that identifier and operation and with an argument count
  // of 0 has no entries.
  //
  // The characteristics of this property are as follows:
  {
    // The name of the property is the identifier.
    v8::Local<v8::String> name = NewInternalString(
        isolate,
        "initWheelEvent");

    // The property has attributes { [[Writable]]: B, [[Enumerable]]: true,
    // [[Configurable]]: B }, where B is false if the operation is unforgeable
    // on the interface, and true otherwise.
    bool B = true;
    v8::PropertyAttribute attributes = static_cast<v8::PropertyAttribute>(
        B ? v8::None : (v8::ReadOnly | v8::DontDelete));

    v8::Local<v8::FunctionTemplate> method_template =
        v8::FunctionTemplate::New(isolate, initWheelEventMethod);
    method_template->RemovePrototype();
    method_template->SetLength(1);

    // The location of the property is determined as follows:
    // Otherwise, the property exists solely on the interface's interface
    // prototype object.
    prototype_template->
        Set(name, method_template);

    // The value of the property is the result of creating an operation function
    // given the operation, the interface, and the relevant Realm of the object
    // that is the location of the property.

    // Note: that is, even if an includes statement was used to make an
    // operation available on the interface, we pass in the interface which
    // includes the interface mixin, and not the interface mixin on which the
    // operation was originally declared.
  }

  // https://heycam.github.io/webidl/#es-stringifier
  // 3.6.8.2. Stringifiers
  prototype_template->Set(
      v8::Symbol::GetToStringTag(isolate),
      NewInternalString(isolate, "WheelEvent"),
      static_cast<v8::PropertyAttribute>(v8::ReadOnly | v8::DontEnum));





}

}  // namespace


v8::Local<v8::Object> V8cWheelEvent::CreateWrapper(
    v8::Isolate* isolate, const scoped_refptr<Wrappable>& wrappable) {
  EscapableEntryScope entry_scope(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();

  V8cGlobalEnvironment* global_environment = V8cGlobalEnvironment::GetFromIsolate(isolate);
  if (!global_environment->HasInterfaceData(kInterfaceUniqueId)) {
    InitializeTemplate(isolate);
  }
  v8::Local<v8::FunctionTemplate> function_template = global_environment->GetInterfaceData(kInterfaceUniqueId);

  DCHECK(function_template->InstanceTemplate()->InternalFieldCount() == WrapperPrivate::kInternalFieldCount);
  v8::Local<v8::Object> object = function_template->InstanceTemplate()->NewInstance(context).ToLocalChecked();
  DCHECK(object->InternalFieldCount() == WrapperPrivate::kInternalFieldCount);

  // This |WrapperPrivate|'s lifetime will be managed by V8.
  new WrapperPrivate(isolate, wrappable, object);
  return entry_scope.Escape(object);
}


v8::Local<v8::FunctionTemplate> V8cWheelEvent::GetTemplate(v8::Isolate* isolate) {
  V8cGlobalEnvironment* global_environment = V8cGlobalEnvironment::GetFromIsolate(isolate);
  if (!global_environment->HasInterfaceData(kInterfaceUniqueId)) {
    InitializeTemplate(isolate);
  }
  return global_environment->GetInterfaceData(kInterfaceUniqueId);
}


}  // namespace dom
}  // namespace cobalt


