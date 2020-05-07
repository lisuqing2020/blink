#include "hash.h"

Hash::Hash(HashType type) {
    type_ = type;
    switch(type_) {
        case HASH_MD5:
        MD5_Init(md5ctx_);
        break;
    }
}

void Hash::Add(string str) {
    switch(type_) {
        case HASH_MD5:
        MD5_Update(md5ctx_, str.c_str(), str.size());
        break;
    }
}

string Hash::Encrypt() {
    switch(type_) {
        case HASH_MD5:
        unsigned char md[MD5_DIGEST_LENGTH];
        char ret[MD5_DIGEST_LENGTH*2+1] = {0};
        MD5_Final(md, md5ctx_);
        for(int i = 0; i < MD5_DIGEST_LENGTH; ++i) {
            sprintf(&ret[i*2], "%02x", md[i]);
        }
        return string(ret);
    }
}

Hash::~Hash() {}