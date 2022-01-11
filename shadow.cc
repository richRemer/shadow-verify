#include <node.h>
#include <unistd.h>

namespace shadowVerify {
  using v8::FunctionCallbackInfo;
  using v8::Isolate;
  using v8::Local;
  using v8::Object;
  using v8::String;
  using v8::Value;

  void Method(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();

    args
      .GetReturnValue()
      .Set(
        String::NewFromUtf8(
          isolate,
          crypt("bar", "$6$V9txQQkn$widChfOgAdGU1dUPVctmdRlM1aAZolyoxS5JhoqMw0c4FjgXVyHmbSoNj4ku/uGxc/rnsyC55.nEBhzfT/HEe1")
        ).ToLocalChecked()
      );
  }

  void Initialize(Local<Object> exports) {
    NODE_SET_METHOD(exports, "verify", Method);
  }

  NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize)
}
