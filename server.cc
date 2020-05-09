#include <iostream>
#include <string>
#include <fstream>
#include <json/json.h>
#include <pthread.h>
#include <map>
#include "tcp.h"
#include "factory.h"
#include "rsa.h"
using namespace std;
using namespace Json;

class Server {
private:
    map<pthread_t, TcpSocket*> sockets_;
    string server_;
    unsigned short port_;
public:
    Server(string file);
    void Run();
    bool Agree(RequestMessage* reqmes);
    static void* Working(void* arg);
    ~Server();
};

Server::Server(string file) {
    ifstream ifs(file.c_str());
    Reader reader;
    Value root;
    server_ = root["server"].asString();
    port_ = root["port"].asUInt();
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

bool Server::Agree(RequestMessage* reqmes) {

}

void* Server::Working(void* arg) {
    Server* server = (Server*)arg;
    TcpSocket* socket = server->sockets_[pthread_self()];

    string rec = socket->Recv(10);
    Factory* fac = new RequestFactory(rec);
    Codec* cc = fac->CreateCodec();
    RequestMessage* reqmes = (RequestMessage*)cc->DecodeMessage();

    switch(reqmes->type_()) {
        case 1:
        server->Agree(reqmes);
    }
}

int main(int argc, char* argv[]) {
    Server server("server.json");
    server.Run();
}