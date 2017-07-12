
#include <nan.h>
#include <stdio.h>

#include "addon.h"

namespace canvas {

/*
  Utils
 */

#ifndef CHECK_ARGS_COUNT
#define CHECK_ARGS_COUNT(n)                          \
  if (info.Length() < n) {                           \
    char checkErrorMsg[64];                          \
    snprintf(checkErrorMsg, 64,                      \
        "%d argument required, but only %d present", \
        n, info.Length());                           \
    return Nan::ThrowTypeError(checkErrorMsg);       \
  }
#endif

/*
  Canvas Class
 */

Nan::Persistent<FunctionTemplate> Canvas::constructor;

Canvas::Canvas() {
}

Canvas::~Canvas() {
}

void Canvas::Initialize(Nan::ADDON_REGISTER_FUNCTION_ARGS_TYPE target) {
  Nan::HandleScope scope;

  // Constructor
  auto ctor = Nan::New<FunctionTemplate>(Canvas::New);
  constructor.Reset(ctor);
  ctor->InstanceTemplate()->SetInternalFieldCount(1);
  ctor->SetClassName(Nan::New("Canvas").ToLocalChecked());

  // Template
  auto proto = ctor->PrototypeTemplate();
  Nan::SetPrototypeMethod(ctor, "getContext", GetContext);
  Nan::Set(target, Nan::New("Canvas").ToLocalChecked(), ctor->GetFunction());
}

NAN_METHOD(Canvas::New) {
  if (!info.IsConstructCall()) {
    return Nan::ThrowTypeError("Class constructors cannot be invoked without 'new'");
  }
  info.GetReturnValue().Set(info.This());
}

NAN_METHOD(Canvas::GetContext) {
  CHECK_ARGS_COUNT(1)
  info.GetReturnValue().Set(Nan::Null());
}

/*
  CanvasRenderingContext2D Class
 */

Nan::Persistent<FunctionTemplate> CanvasRenderingContext2D::constructor;

CanvasRenderingContext2D::CanvasRenderingContext2D() {
}

CanvasRenderingContext2D::~CanvasRenderingContext2D() {
}

void CanvasRenderingContext2D::Initialize(Nan::ADDON_REGISTER_FUNCTION_ARGS_TYPE target) {
  Nan::HandleScope scope;

  // Constructor
  auto ctor = Nan::New<FunctionTemplate>(CanvasRenderingContext2D::New);
  constructor.Reset(ctor);
  ctor->InstanceTemplate()->SetInternalFieldCount(1);
  ctor->SetClassName(Nan::New("CanvasRenderingContext2D").ToLocalChecked());

  // Template
  auto proto = ctor->PrototypeTemplate();

  Nan::Set(target, Nan::New("CanvasRenderingContext2D").ToLocalChecked(), ctor->GetFunction());
}

NAN_METHOD(CanvasRenderingContext2D::New) {
  return Nan::ThrowTypeError("Illegal constructor");
}

/*
  Module
 */

NAN_MODULE_INIT(Initialize) {
  Canvas::Initialize(target);
  CanvasRenderingContext2D::Initialize(target);
  target->Set(Nan::New("fourteen").ToLocalChecked(),
      Nan::New(14));
}

NODE_MODULE(canvas_skia, Initialize)

} // namespace canvas

