#ifndef _CODEC_H_
#define _CODEC_H_

#include <string>
#include "message.pb.h"
using std::string;

class Codec {
public:
    Codec();
    virtual string EncodeMessage() = 0;
    virtual void* DecodeMessage() = 0;
    virtual ~Codec();
};

class RequestCodec: public Codec {
private:
    string str_;
    RequestMessage reqmsg_;

    void InitString(string str);
    void InitMessage(RequestMessage& reqmes);
public:
    RequestCodec(string str);
    RequestCodec(RequestMessage& reqmes);

    string EncodeMessage();
    void* DecodeMessage();

    ~RequestCodec();
};

class ResponseCodec: public Codec {
private:
    string str_;
    ResponseMessage resmsg_;

    void InitString(string str);
    void InitMessage(ResponseMessage& resmes);
public:
    ResponseCodec(string str);
    ResponseCodec(ResponseMessage& resmes);

    string EncodeMessage();
    void* DecodeMessage();

    ~ResponseCodec();
};

#endif