#include <iostream>
#include <string>
#include <fstream>
#include <json/json.h>
#include <sstream>
#include "message.pb.h"
#include "rsa.h"
#include "factory.h"
#include "tcp.h"

using namespace std;
using namespace Json;

class Client {
private:
    string server_;
    string client_;
    string host_;
    unsigned int port_;
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
    server_ = root["server"].asString();
    client_ = root["client"].asString();
    host_ = root["host"].asString();
    port_ = root["port"].asUInt();
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
    reqmes.set_data_(ss.str());
    reqmes.set_sign_(rsa.Sign(ss.str()));
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
    cout << "response status: " << resmes->status_() << endl;
    return true;
}

Client::~Client() {}

int main(int argc, char* argv[]) {
    Client cli("client.json");
}