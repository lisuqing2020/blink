#ifndef _RSA_H_
#define _RSA_H_

#include <openssl/rsa.h>
#include <openssl/bio.h>
#include <openssl/pem.h>
#include <string>
using std::string;

enum Level {
    L1 = NID_md5,
    L2 = NID_sha1,
    L3 = NID_sha224,
    L4 = NID_sha256,
    L5 = NID_sha384,
    L6 = NID_sha512
};

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
    string Sign(string data, Level level = L3);
    bool Verify(string data, string sign, Level level = L3);

    ~Rsa();
};

#endif