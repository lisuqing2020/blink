#include "aes.h"

Aes::Aes(string key) {
    if(key.size() == 16 || key.size() == 24 || key.size() == 32) {
        key_ = key;
        const unsigned char* aeskey = (const unsigned char*)key.c_str();
        AES_set_encrypt_key(aeskey, key.size()*8, &enckey_);
        AES_set_decrypt_key(aeskey, key.size()*8, &deckey_);
    }
}

string Aes::Encrypt(string data) {
    size_t length = data.size()+1;
    if(length % 16 != 0) {
        length = (length/16+1)*16;
    }
    char* out = new char[length];

    unsigned char ivec[AES_BLOCK_SIZE];
    MakeIvec(ivec);
    AES_cbc_encrypt((unsigned char*)data.c_str(), (unsigned char*)out, length, &enckey_, ivec, AES_ENCRYPT);

    string ret = string(out);
    delete[] out;
    return ret;
}

string Aes::Decrypt(string data) {
    size_t length = data.size()+1;
    if(length % 16 != 0) {
        length = (length/16+1)*16;
    }
    char* out = new char[length];

    unsigned char ivec[AES_BLOCK_SIZE];
    MakeIvec(ivec);
    AES_cbc_encrypt((unsigned char*)data.c_str(), (unsigned char*)out, length, &deckey_, ivec, AES_DECRYPT);

    string ret = string(out);
    delete[] out;
    return ret;
}

void Aes::MakeIvec(unsigned char* ivec) {
    for(int i = 0; i < AES_BLOCK_SIZE; ++i) {
        ivec[i] = key_.at(AES_BLOCK_SIZE-i-1);
    }
}

Aes::~Aes() {}