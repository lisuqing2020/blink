#include <json/json.h>
#include <fstream>
#include <iostream>
#include "aes.h"
#include "shm.h"
#include "tcp.h"
using namespace Json;
using namespace std;

class Blink {
private:
    string aeskey_;
public:
    Blink(string file);
    string Encrypt(string data);
    string Decrypt(string data);
    ~Blink();
};

Blink::Blink(string file) {
    ifstream ifs(file);
    Reader reader;
    Value root;
    reader.parse(ifs, root);
    int shmkey = root["key"].asInt();
    string client = root["client"].asString();
    string server = root["server"].asString();
    int maxnode = root["maxnode"].asInt();
    KeyShm shm(shmkey, maxnode);
    ShmNode node;
    bool r = shm.Read((char*)client.c_str(), (char*)server.c_str(), &node);
    if(r) {
        cout << "共享内存读取成功!\n";
        aeskey_ = string(node.key_);
        cout << "对称加密密钥: " << aeskey_ << endl;
    }
}

string Blink::Encrypt(string data) {
    Aes aes(aeskey_);
    return aes.Encrypt(data);
}

string Blink::Decrypt(string data) {
    Aes aes(aeskey_);
    return aes.Decrypt(data);
}

Blink::~Blink() {}

int main() {
    Blink blink("server.json");
    TcpServer server;
    server.Listen(8989);
    TcpSocket* sock = server.Accept(10000);
    while(1) {
        string rec = sock->Recv(1);
        rec = blink.Decrypt(rec);
        cout << "server recv: " << rec << endl;
        string sen = "hello client!";
        cout << "server send: " << sen << endl;
        sock->Send(sen,1);
        sen = blink.Encrypt(sen);
    }
}