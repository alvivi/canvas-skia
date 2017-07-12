
#ifndef __CANVAS_SKIA_H__
#define __CANVAS_SKIA_H__

#include <nan.h>

using namespace v8;

namespace canvas {

class Canvas: public Nan::ObjectWrap {
  public:
    static void Initialize(Nan::ADDON_REGISTER_FUNCTION_ARGS_TYPE target);

    static Nan::Persistent<FunctionTemplate> constructor;
    static NAN_METHOD(New);
    static NAN_METHOD(GetContext);

  private:
    Canvas();
    ~Canvas();
};

class CanvasRenderingContext2D: public Nan::ObjectWrap {
  public:
    static void Initialize(Nan::ADDON_REGISTER_FUNCTION_ARGS_TYPE target);
    static Nan::Persistent<FunctionTemplate> constructor;

    static NAN_METHOD(New);

  private:
    CanvasRenderingContext2D();
    ~CanvasRenderingContext2D();
};

} // namespace canvas

#endif

