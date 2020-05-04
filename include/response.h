#ifndef _RESPONSE_H_
#define _RESPONSE_H_

#include "codec.h"
#include "message.pb.h"
using std::string;

class ResponseCodec: public Codec {
private:
    std::string str_;
    ResponseMessage msg_;
public:
    ResponseCodec();
    ResponseCodec(string str);
    ResponseCodec(int status, int key, string client, string server, string data);

    void InitString(string str);
    void InitMessage(int status, int key, string client, string server, string data);
    string EncodeMessage();
    void* DecodeMessage();

    ~ResponseCodec();
};

#endif