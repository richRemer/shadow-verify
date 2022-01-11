#include <nan.h>
#include <unistd.h>

using v8::FunctionTemplate;
using v8::Isolate;
using v8::String;
using Nan::GetFunction;
using Nan::New;
using Nan::Set;

NAN_METHOD(Verify) {
  Isolate* isolate = info.GetIsolate();

  info
    .GetReturnValue()
    .Set(String::NewFromUtf8(
      isolate,
      crypt("foo", "$6$V9txQQkn$widChfOgAdGU1dUPVctmdRlM1aAZolyoxS5JhoqMw0c4FjgXVyHmbSoNj4ku/uGxc/rnsyC55.nEBhzfT/HEe1")
    ).ToLocalChecked()
  );
}

NAN_MODULE_INIT(InitAll) {
  auto name = New<String>("verify").ToLocalChecked();
  auto function = GetFunction(New<FunctionTemplate>(Verify)).ToLocalChecked();

  Set(target, name, function);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, InitAll)
