#include "tcp.h"

TcpSocket::TcpSocket() {
    socket_ = socket(AF_INET, SOCK_STREAM, 0);
}

TcpSocket::TcpSocket(int socket) {
    socket_ = socket;
}

void TcpSocket::Connect(string ip, unsigned short port, int timeout) {
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    inet_pton(AF_INET, ip.c_str(), &addr.sin_addr.s_addr);
    connect(socket_, (struct sockaddr*)&addr, sizeof(addr));
}

void TcpSocket::Send(string data, int timeout) {
    write(socket_, data.c_str(), data.size()+1);
}

string TcpSocket::Recv(int timeout) {
    char buf[2048];
    read(socket_, buf, sizeof(buf));
    return string(buf);
}

TcpSocket::~TcpSocket() {
    close(socket_);
}