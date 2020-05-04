#include "request.h"

RequestCodec::RequestCodec() {}

RequestCodec::RequestCodec(string str) {
    InitString(str);
}

RequestCodec::RequestCodec(int type, string client, string server, string sign, string data) {
    InitMessage(type, client, server, sign, data);
}

void RequestCodec::InitString(string str) {
    str_ = str;
}

void RequestCodec::InitMessage(int type, string client, string server, string sign, string data) {
    msg_.set_type_(type);
    msg_.set_client_(client);
    msg_.set_server_(server);
    msg_.set_sign_(sign);
    msg_.set_data_(data);
}

string RequestCodec::EncodeMessage() {
    msg_.SerializeToString(&str_);
    return str_;
}

void* RequestCodec::DecodeMessage() {
    msg_.ParseFromString(str_);
    return &msg_;
}

RequestCodec::~RequestCodec() {}