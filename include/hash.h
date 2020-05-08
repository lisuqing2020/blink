#ifndef _HASH_H_
#define _HASH_H_

#include <openssl/md5.h>
#include <openssl/sha.h>
#include <string>
#include <cstdio>
using std::string;

enum HashType {
    HASH_MD5, HASH_SHA1, HASH_SHA224, HASH_SHA256, HASH_SHA384, HASH_SHA512
};

class Hash {
private:
    HashType type_;
    MD5_CTX* md5_;
    SHA_CTX* sha_;
    SHA256_CTX* sha224_;
    SHA256_CTX* sha256_;
    SHA512_CTX* sha384_;
    SHA512_CTX* sha512_;
public:
    Hash(HashType type);
    virtual void Add(string str) = 0;
    virtual string Encrypt() = 0;
    ~Hash();
};

#endif