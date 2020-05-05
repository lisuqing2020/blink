#include "codec.h"

RequestCodec::RequestCodec(string str) {
    InitString(str);
}

RequestCodec::RequestCodec(RequestMessage& reqmes) {
    InitMessage(reqmes);
}

void RequestCodec::InitString(string str) {
    str_ = str;
}

void RequestCodec::InitMessage(RequestMessage& reqmes) {
    reqmsg_ = reqmes;
}

string RequestCodec::EncodeMessage() {
    reqmsg_.SerializeToString(&str_);
    return str_;
}

void* RequestCodec::DecodeMessage() {
    reqmsg_.ParseFromString(str_);
    return &reqmsg_;
}

RequestCodec::~RequestCodec() {}