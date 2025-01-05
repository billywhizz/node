
#include "ffast.h"

namespace ffast {

int32_t getpidFast(void* p);
v8::CTypeInfo cargsgetpid[1] = {
v8::CTypeInfo(v8::CTypeInfo::Type::kV8Value),

};
v8::CTypeInfo rcgetpid = v8::CTypeInfo(v8::CTypeInfo::Type::kInt32);
v8::CFunctionInfo infogetpid = v8::CFunctionInfo(rcgetpid, 1, cargsgetpid);
v8::CFunction pFgetpid = v8::CFunction((const void*)&getpidFast, &infogetpid);


int32_t forkFast(void* p);
v8::CTypeInfo cargsfork[1] = {
v8::CTypeInfo(v8::CTypeInfo::Type::kV8Value),

};
v8::CTypeInfo rcfork = v8::CTypeInfo(v8::CTypeInfo::Type::kInt32);
v8::CFunctionInfo infofork = v8::CFunctionInfo(rcfork, 1, cargsfork);
v8::CFunction pFfork = v8::CFunction((const void*)&forkFast, &infofork);



void getpidSlow(const FunctionCallbackInfo<Value> &args) {

  int32_t rc = getpid();
  args.GetReturnValue().Set(rc);
}

int32_t getpidFast(void* p) {

  return getpid();
}

void forkSlow(const FunctionCallbackInfo<Value> &args) {

  int32_t rc = fork();
  args.GetReturnValue().Set(rc);
}

int32_t forkFast(void* p) {

  return fork();
}

void Initialize(Local<Object> exports) {
  Isolate* isolate = Isolate::GetCurrent();
  NODE_SET_FAST_METHOD(isolate, exports, "getpid", &pFgetpid, getpidSlow);
NODE_SET_FAST_METHOD(isolate, exports, "fork", &pFfork, forkSlow);
  
}

NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize)

}
