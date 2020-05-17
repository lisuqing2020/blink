#include <iostream>
#include <string>
#include <fstream>
#include <json/json.h>
#include <pthread.h>
#include <map>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "tcp.h"
#include "factory.h"
#include "rsa.h"
#include "hash.h"
#include "shm.h"
#include "db.h"
using namespace std;
using namespace Json;

class Server {
private:
    map<pthread_t, TcpSocket*> sockets_;
    string server_;
    unsigned short port_;
    int key_;
    int maxnode_;
    string db_;
    string dbhost_;
    string user_;
    string pass_;
    KeyShm* shm_;
    MySQL mysql_;
    string RandomString(int length);
public:
    Server(string file);
    void Run();
    string Agree(RequestMessage* reqmes);
    static void* Working(void* arg);
    ~Server();
};

Server::Server(string file) {
    ifstream ifs(file.c_str());
    Reader reader;
    Value root;
    reader.parse(ifs, root);
    server_ = root["server"].asString();
    port_ = root["port"].asUInt();
    key_ = root["key"].asInt();
    maxnode_ = root["maxnode"].asInt();
    db_ = root["db"].asString();
    dbhost_ = root["dbhost"].asString();
    user_ = root["uesr"].asString();
    pass_ = root["pass"].asString();
    shm_ = new KeyShm(key_, maxnode_);

    mysql_.Connect((char*)dbhost_.c_str(), (char*)db_.c_str(), (char*)user_.c_str(), (char*)pass_.c_str());
}

void Server::Run() {
    TcpServer server;
    server.Listen(port_);
    while(1) {
        TcpSocket* socket = server.Accept(10);
        pthread_t tid;
        pthread_create(&tid, NULL, Working, this);
        pthread_detach(tid);
        sockets_.insert(make_pair(tid, socket));
    } 
}

string Server::RandomString(int length) {
    string ret;
    srand(time(0));
    for(int i = 0; i < length; ++i) {
        int flag = rand() % 3;
        if(flag == 0) {
            ret.append(1, '0'+rand()%10);
        } else if(flag == 1) {
            ret.append(1, 'a'+rand()%26);
        } else if(flag == 2) {
            ret.append(1, 'A'+rand()%26);
        }
    }
    return ret;
}

string Server::Agree(RequestMessage* reqmes) {
    /*
     * 1. 校验签名
     * 2. 将得到的公钥写入服务器磁盘
     * 3. 生成随机字符串 -> 16/24/32 -> 对称加密密钥
     * 4. 回复数据 -> 结构体
     * 5. 数据初始化，密钥使用公钥加密
     * 6. 通过工厂函数创建编码对象
     * 7. 得到要回复客户端的数据
     */
    ResponseMessage resmes;

    // 将得到的客户端公钥写入磁盘
    string filename = reqmes->client_() + ".pem";
    ofstream ofs(filename);
    ofs << reqmes->data_();
    ofs.close();    // 数据刷到磁盘

    // 签名校验
    Rsa rsa(filename.c_str(), false);
    Hash hash(HASH_MD5);
    hash.Add(reqmes->data_());
    if(!rsa.Verify(hash.Encrypt(), reqmes->sign_())) {
        // ...fail
        resmes.set_status_(false);
    } else {
        cout << "签名校验成功！" << endl;
        resmes.set_status_(true);
        resmes.set_client_(reqmes->client_());
        resmes.set_server_(server_);
        string key = RandomString(24);
        resmes.set_data_(rsa.PubEncrypt(key));

        ShmNode node;
        strcpy(node.client_, reqmes->client_().c_str());
        strcpy(node.server_, server_.c_str());
        strcpy(node.key_, key.c_str());
        node.status_ = 1;
        node.keyid_ = mysql_.GetKeyID(); // 从数据库读
        bool r = mysql_.InsertKeyInfo(node.client_, node.server_, node.keyid_, node.key_);
        if(r) cout << "写数据库成功\n";
        
        shm_ -> Write(&node);
        cout << "对称加密密钥已写入共享内存\n";
    }

    // 生成序列化对象
    Factory* fac = new ResponseFactory(resmes);
    Codec* cc = fac->CreateCodec();
    string mes = cc->EncodeMessage();
    delete fac;
    delete cc;
    
    return mes;
}

void* Server::Working(void* arg) {
    usleep(100);    // 防止sockets_.insert(make_pair(tid, socket))还未执行
    Server* server = (Server*)arg;
    TcpSocket* socket = server->sockets_[pthread_self()];

    string rec = socket->Recv(10);
    Factory* fac = new RequestFactory(rec);
    Codec* cc = fac->CreateCodec();
    RequestMessage* reqmes = (RequestMessage*)cc->DecodeMessage();

    string data;
    switch(reqmes->type_()) {
        case 1:
        data = server->Agree(reqmes);
    }
    socket->Send(data, 10);
    delete fac;
    delete cc;
    server->sockets_.erase(pthread_self());
    delete socket;
}

Server::~Server() {}

int main(int argc, char* argv[]) {
    Server server("server.json");
    server.Run();
}