#include "codec.h"

ResponseCodec::ResponseCodec(string str) {
    InitString(str);
}

ResponseCodec::ResponseCodec(ResponseMessage& resmes) {
    InitMessage(resmes);
}

void ResponseCodec::InitString(string str) {
    str_ = str;
}

void ResponseCodec::InitMessage(ResponseMessage& resmes) {
    resmsg_ = resmes;
}

string ResponseCodec::EncodeMessage() {
    resmsg_.SerializeToString(&str_);
    return str_;
}

void* ResponseCodec::DecodeMessage() {
    resmsg_.ParseFromString(str_);
    return &resmsg_;
}

ResponseCodec::~ResponseCodec() {}