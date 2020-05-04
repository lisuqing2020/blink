#ifndef _CODEC_H_
#define _CODEC_H_

#include <string>
using std::string;

class Codec {
public:
    Codec();
    virtual string EncodeMessage() = 0;
    virtual void* DecodeMessage() = 0;
    virtual ~Codec();
};

#endif