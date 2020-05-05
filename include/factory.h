#ifndef _FACTORY_H_
#define _FACTORY_H_

#include "codec.h"

#define ECOD 0
#define DCOD 1

class Factory {
public:
    Factory();
    virtual Codec* CreateCodec() = 0;
    virtual ~Factory();
};

class RequestFactory: public Factory {
private:
    string str_;
    RequestMessage reqmes_;
    int flag_;
public:
    RequestFactory(string str);
    RequestFactory(RequestMessage& reqmes);

    Codec* CreateCodec();

    ~RequestFactory();
};

class ResponseFactory: public Factory {
private:
    string str_;
    ResponseMessage resmes_;
    int flag_;
public:
    ResponseFactory(string str);
    ResponseFactory(ResponseMessage& resmes);

    Codec* CreateCodec();

    ~ResponseFactory();
};

#endif