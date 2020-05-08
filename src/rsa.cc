#include "rsa.h"
#include <iostream>
#include <cstdio>
using namespace std;

Rsa::Rsa(int bits) {
    RSA* rsa = RSA_new();
    pub_ = RSA_new();
    pri_ = RSA_new();
    BIGNUM* bn = BN_new();
    BN_set_word(bn, 9527);
    RSA_generate_key_ex(rsa, bits, bn, NULL);
    pub_ = RSAPublicKey_dup(rsa);
    pri_ = RSAPrivateKey_dup(rsa);

    BIO* bio = BIO_new_file("pub.pem", "w");
    PEM_write_bio_RSAPublicKey(bio, rsa);
    BIO_flush(bio);
    
    bio = BIO_new_file("pri.pem", "w");
    PEM_write_bio_RSAPrivateKey(bio, rsa, NULL, NULL, 0, NULL, NULL);
    BIO_flush(bio);
    BIO_free(bio);

    RSA_free(rsa);
    BN_free(bn);
}

string Rsa::PubEncrypt(string data) {
    char* ret = new char[RSA_size(pub_)+1];
    int n = RSA_public_encrypt(data.size(), (unsigned char*)data.data(), (unsigned char*)ret, pub_, RSA_PKCS1_PADDING);
    string str = string(ret,n);
    delete[] ret;
    return str;
} 

string Rsa::PriDecrypt(string data) {
    char* ret = new char[RSA_size(pri_)+1];
    int n = RSA_private_decrypt(data.size(), (unsigned char*)data.data(), (unsigned char*)ret, pri_, RSA_PKCS1_PADDING);
    string str = string(ret,n);
    delete[] ret;
    return str;
}

string Rsa::PriEncrypt(string data) {
    char* ret = new char[RSA_size(pri_)+1];
    int n = RSA_private_encrypt(data.size(), (unsigned char*)data.data(), (unsigned char*)ret, pri_, RSA_PKCS1_PADDING);
    string str = string(ret,n);
    delete[] ret;
    return str;
}

string Rsa::PubDecrypt(string data) {
    char* ret = new char[RSA_size(pub_)+1];
    int n = RSA_public_decrypt(data.size(), (unsigned char*)data.data(), (unsigned char*)ret, pub_, RSA_PKCS1_PADDING);
    string str = string(ret,n);
    delete[] ret;
    return str;
}

string Rsa::Sign(string data, Level level) {
    char* buf = new char[RSA_size(pri_)+1];
    unsigned int len;
    RSA_sign(level, (unsigned char*)data.c_str(), data.size(), (unsigned char*)buf, &len, pri_);
    string ret = string(buf, len);
    delete[] buf;
    return ret;
}

bool Rsa::Verify(string data, string sign, Level level) {
    int ret = RSA_verify(level, (unsigned char*)data.c_str(), data.size(), (unsigned char*)sign.c_str(), sign.size(), pub_);
    return ret == 1 ? true : false;
}

Rsa::~Rsa() {
    RSA_free(pub_);
    RSA_free(pri_);
}