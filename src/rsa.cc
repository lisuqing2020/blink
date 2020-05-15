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

Rsa::Rsa(string file, bool isprivate) {
    pub_ = RSA_new();
    pri_ = RSA_new();

    BIO* bio = BIO_new_file(file.c_str(), "r");
    if(isprivate) {
        PEM_read_bio_RSAPrivateKey(bio, &pri_, NULL, NULL);
    } else {
        PEM_read_bio_RSAPublicKey(bio, &pub_, NULL, NULL);
    }
    BIO_free(bio);
}

string Rsa::PubEncrypt(string data) {
    char* ret = new char[RSA_size(pub_)+1];
    int n = RSA_public_encrypt(data.size(), (unsigned char*)data.data(), (unsigned char*)ret, pub_, RSA_PKCS1_PADDING);
    string str = ToBase64(ret,n);
    delete[] ret;
    return str;
} 

string Rsa::PriDecrypt(string data) {
    char* tmp = FromBase64(data);
    char* ret = new char[RSA_size(pri_)+1];
    int n = RSA_private_decrypt(RSA_size(pri_), (unsigned char*)tmp, (unsigned char*)ret, pri_, RSA_PKCS1_PADDING);
    string str = string(ret,n);
    delete[] tmp;
    delete[] ret;
    return str;
}

string Rsa::PriEncrypt(string data) {
    char* ret = new char[RSA_size(pri_)+1];
    int n = RSA_private_encrypt(data.size(), (unsigned char*)data.data(), (unsigned char*)ret, pri_, RSA_PKCS1_PADDING);
    string str = ToBase64(ret,n);
    delete[] ret;
    return str;
}

string Rsa::PubDecrypt(string data) {
    char* tmp = FromBase64(data);
    char* ret = new char[RSA_size(pub_)+1];
    int n = RSA_public_decrypt(RSA_size(pub_), (unsigned char*)tmp, (unsigned char*)ret, pub_, RSA_PKCS1_PADDING);
    string str = string(ret,n);
    delete[] tmp;
    delete[] ret;
    return str;
}

string Rsa::Sign(string data, Level level) {
    char* buf = new char[RSA_size(pri_)+1];
    unsigned int len;
    RSA_sign(level, (unsigned char*)data.c_str(), data.size(), (unsigned char*)buf, &len, pri_);
    string ret = ToBase64(buf, len);
    delete[] buf;
    return ret;
}

bool Rsa::Verify(string data, string sign, Level level) {
    char* tmp = FromBase64(sign);
    int ret = RSA_verify(level, (unsigned char*)data.c_str(), data.size(), (unsigned char*)tmp, RSA_size(pub_), pub_);
    delete[] tmp;
    return ret == 1 ? true : false;
}

string Rsa::ToBase64(char* data, int len) {
    // 准备一个base64BIO对象
    BIO* b64  = BIO_new(BIO_f_base64());
    // 准备一个内存的BIO对象
    BIO* mem  = BIO_new(BIO_s_mem());
    // 将base64和内存bio对象 -> bio链
    BIO_push(b64, mem);	// 逻辑关系: b64->mem
    // 数据通过base64进行编码之后 -> 存储到内存
    // 往bio链中写数据
    // 调用bio_write, base64对象默认做编码操作
    BIO_write(b64, data, len);
    // 将编码数据从bio内存对象中读出
    BUF_MEM* ptrmem;
    BIO_get_mem_ptr(b64, &ptrmem);

    return string(ptrmem->data, ptrmem->length);
}

char* FromBase64(string data) {
    BIO* b64  = BIO_new(BIO_f_base64());
    // 准备一个内存的BIO对象
    BIO* mem = BIO_new_mem_buf(data.c_str(), data.size());
    // 组织bio链
    BIO_push(b64, mem);	// 逻辑关系: b64->mem
    // 解码
    char* buf = new char[data.size()];
    BIO_read(b64, buf, sizeof(buf));
    return buf;
}

Rsa::~Rsa() {
    RSA_free(pub_);
    RSA_free(pri_);
}