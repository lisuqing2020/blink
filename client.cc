#include <iostream>
#include <string>
#include <fstream>
#include <json/json.h>
#include <sstream>
#include "message.pb.h"
#include "rsa.h"
#include "factory.h"
#include "tcp.h"
#include "hash.h"
#include "shm.h"

using namespace std;
using namespace Json;

class Client {
private:
    string server_;
    string client_;
    string host_;
    unsigned int port_;
    int key_;
    int maxnode_;
    KeyShm* shm_;
public:
    Client(string file);
    bool Agree();
    bool Check();
    bool Cancel();
    ~Client();
};

Client::Client(string file) {
    ifstream ifs(file.c_str());
    Reader reader;
    Value root;
    reader.parse(ifs, root);
    server_ = root["server"].asString();
    client_ = root["client"].asString();
    host_ = root["host"].asString();
    port_ = root["port"].asUInt();
    key_ = root["key"].asInt();
    maxnode_ = root["maxnode"].asInt();

    shm_ = new KeyShm(key_, maxnode_);
}

bool Client::Agree() {
    // 1. 准备数据
    RequestMessage reqmes;
    reqmes.set_type_(1);
    reqmes.set_client_(client_);
    reqmes.set_server_(server_);

    Rsa rsa(2048);
    ifstream ifs("pub.pem");
    stringstream ss;
    ss << ifs.rdbuf();

    // 签名数据长度，bits/8 - 11， 但是公钥很长，这里签hash值就可以
    Hash hash(HASH_MD5);
    hash.Add(ss.str());
    string hashval = hash.Encrypt();

    reqmes.set_data_(ss.str());
    reqmes.set_sign_(rsa.Sign(hashval));
    cout << "1. 数据准备完成...\n";

    // 2. 序列化
    Factory* fac1 = new RequestFactory(reqmes);
    Codec* cc1 = fac1->CreateCodec();
    string mes = cc1->EncodeMessage();
    cout << "2. 序列化完成...\n";
    free(fac1);
    free(cc1);

    // 3. 发送数据
    TcpSocket socket;
    socket.Connect(host_, port_, 10);
    socket.Send(mes, 10);
    cout << "3. 发送数据完成...\n";

    // 4. 接收数据
    string rec = socket.Recv(100);
    cout << "4. 接收数据完成...\n";

    // 5. 反序列化
    Factory* fac2 = new ResponseFactory(rec);
    Codec* cc2 = fac2->CreateCodec();
    ResponseMessage* resmes = (ResponseMessage*)cc2->DecodeMessage();
    cout << "5. 反序列化完成...\n";
    free(fac2);
    free(cc2);

    // 6. 判断响应状态
    bool ret = true;
    if(!resmes->status_()) {
        cout << "fail..." << endl;
        ret = false;
    } else {
        string key = rsa.PriDecrypt(resmes->data_());
        cout << "对称加密密钥: " << key << endl;
        ShmNode node;
        strcpy(node.client_, client_.c_str());
        strcpy(node.server_, server_.c_str());
        strcpy(node.key_, key.c_str());
        node.status_ = 0;
        node.keyid_ = resmes->key_();
        shm_ -> Write(&node);
        cout << "对称加密密钥已写入共享内存\n";
    }

    return ret;
}

Client::~Client() {
    delete shm_;
}

int main(int argc, char* argv[]) {
    Client cli("client.json");
    cli.Agree();
}