#include <nan.h>
#include <unistd.h>

using v8::Boolean;
using v8::FunctionTemplate;
using v8::Isolate;
using v8::String;
using Nan::GetFunction;
using Nan::New;
using Nan::Set;
using Nan::ThrowTypeError;
using Nan::Utf8String;

NAN_METHOD(Verify) {
  if (info.Length() != 2) {
    return ThrowTypeError("function expects two arguments");
  } else if (!info[0]->IsString()) {
    return ThrowTypeError("first argument must be a string");
  } else if (!info[1]->IsString()) {
    return ThrowTypeError("second argument must be non-empty string");
  }

  Isolate* isolate = info.GetIsolate();
  Utf8String secret(info[0]);
  Utf8String hash(info[1]);
  int secret_len = secret.length();
  int hash_len = hash.length();

  if (hash_len <= 0) {
    return ThrowTypeError("second argument must be non-empty string");
  }

  std::string std_secret(*secret, secret_len);
  std::string std_hash(*hash, hash_len);

  // crypt returns a statically allocated buffer; no need to free
  const char* c_hashed = crypt(std_secret.c_str(), std_hash.c_str());

  if (0 == std_hash.compare(c_hashed)) {
    info.GetReturnValue().Set(v8::True(isolate));
  } else {
    info.GetReturnValue().Set(v8::False(isolate));
  }
}

NAN_MODULE_INIT(InitAll) {
  auto name = New<String>("verify").ToLocalChecked();
  auto function = GetFunction(New<FunctionTemplate>(Verify)).ToLocalChecked();

  Set(target, name, function);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, InitAll)
