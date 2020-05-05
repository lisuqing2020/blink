#ifndef _REQUEST_H_
#define _REQUEST_H_

#include "codec.h"
#include "message.pb.h"
using std::string;

class RequestCodec: public Codec {
private:
    string str_;
    RequestMessage msg_;

    void InitString(string str);
    void InitMessage(int type, string client, string server, string sign, string data);
public:
    RequestCodec();
    RequestCodec(string str);
    RequestCodec(int type, string client, string server, string sign, string data);

    string EncodeMessage();
    void* DecodeMessage();

    ~RequestCodec();
};

#endif