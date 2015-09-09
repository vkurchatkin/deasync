#include <node.h>
#include <v8.h>
#include <nan.h>

NAN_METHOD(Run) {
  uv_run(uv_default_loop(), UV_RUN_ONCE);
  return info.GetReturnValue().SetUndefined();
}

NAN_MODULE_INIT(Init){
  Nan::Set(
      target
    , Nan::New<v8::String>("run").ToLocalChecked()
    , Nan::GetFunction(Nan::New<v8::FunctionTemplate>(Run)).ToLocalChecked()
  );
}

NODE_MODULE(deasync, Init)