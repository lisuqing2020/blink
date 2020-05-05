#include "factory.h"

RequestFactory::RequestFactory(string str) {
    str_  = str;
    flag_ = DCOD;
}

RequestFactory::RequestFactory(RequestMessage& reqmes) {
    reqmes_ = reqmes;
    flag_   = ECOD;
}

Codec* RequestFactory::CreateCodec() {
    return flag_  ? new RequestCodec(str_) : new RequestCodec(reqmes_);
}

RequestFactory::~RequestFactory() {}