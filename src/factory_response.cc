#include "factory.h"

ResponseFactory::ResponseFactory(string str) {
    str_  = str;
    flag_ = DCOD;
}

ResponseFactory::ResponseFactory(ResponseMessage& resmes) {
    resmes_ = resmes;
    flag_   = ECOD;
}

Codec* ResponseFactory::CreateCodec() {
    return flag_  ? new ResponseCodec(str_) : new ResponseCodec(resmes_);
}

ResponseFactory::~ResponseFactory() {}