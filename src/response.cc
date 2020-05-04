#include "response.h"

ResponseCodec::ResponseCodec() {}

ResponseCodec::ResponseCodec(string str) {
    InitString(str);
}

ResponseCodec::ResponseCodec(int status, int key, string client, string server, string data) {
    InitMessage(status, key, client, server, data);
}

void ResponseCodec::InitString(string str) {
    str_ = str;
}

void ResponseCodec::InitMessage(int status, int key, string client, string server, string data) {
    msg_.set_status_(status);
    msg_.set_key_(key);
    msg_.set_client_(client);
    msg_.set_server_(server);
    msg_.set_data_(data);
}

string ResponseCodec::EncodeMessage() {
    msg_.SerializeToString(&str_);
    return str_;
}

void* ResponseCodec::DecodeMessage() {
    msg_.ParseFromString(str_);
    return &msg_;
}

ResponseCodec::~ResponseCodec() {}