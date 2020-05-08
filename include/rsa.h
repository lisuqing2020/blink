#ifndef _RSA_H_
#define _RSA_H_

#include <openssl/rsa.h>
#include <openssl/bio.h>
#include <openssl/pem.h>
#include <string>
using std::string;

class Rsa {
private:
    RSA* pub_;
    RSA* pri_;
public:
    Rsa(int bits);
    string PubEncrypt(string data);
    string PubDecrypt(string data);
    string PriEncrypt(string data);
    string PriDecrypt(string data);
    ~Rsa();
};

#endif