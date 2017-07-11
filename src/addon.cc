
#include <nan.h>

NAN_MODULE_INIT(Init) {
  target->Set(Nan::New("fourteen").ToLocalChecked(),
      Nan::New(14));
}

NODE_MODULE(canvas_skia, Init)

