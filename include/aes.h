#ifndef _AES_H_
#define _AES_H_

#include <openssl/aes.h>
#include <string>
using std::string;

class Aes {
private:
    string key_;
    AES_KEY enckey_;
    AES_KEY deckey_; 

    void MakeIvec(unsigned char* ivec);
public:
    Aes(string key);
    string Encrypt(string data);
    string Decrypt(string data);
    ~Aes();
};

#endif