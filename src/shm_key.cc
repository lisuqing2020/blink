#include "shm.h"
#include <iostream>
using namespace std;

KeyShm::KeyShm(key_t key, size_t maxnode):Shm(key, maxnode*sizeof(ShmNode)) {
    maxnode_ = maxnode;
}

bool KeyShm::Write(ShmNode* node) {
    ShmNode* p = (ShmNode*)Combine();

    for(int i = 0; i < maxnode_; ++i) {
        ShmNode* it = p + i;
        if(!strcmp(it->client_, node->client_) && !strcmp(it->server_, node->server_)) {
            cout << "共享内存中有该网点密钥信息，更新\n";
            // 共享内存中有该网点密钥信息，更新
            memcpy(it, node, sizeof(ShmNode));
            Separate();
            return true;
        }
    }

    ShmNode tmp;
    memset(&tmp, 0, sizeof(ShmNode));
    for(int i = 0; i < maxnode_; ++i) {
        ShmNode* it = p + i;
        if(!memcmp(&tmp, it, sizeof(ShmNode))) {
            cout << "找到一个空节点，写入\n";
            // 找到一个空节点，写入
            memcpy(p, node, sizeof(ShmNode));
            Separate();
            return true;
        }
    }

    Separate();
    return false;
}

bool KeyShm::Read(char* client, char* server, ShmNode* node) {
    ShmNode* p = (ShmNode*)Combine();
    for(int i = 0; i < maxnode_; ++i) {
        ShmNode* it = p + i;
        if(!strcmp(it->client_, client) && !strcmp(it->server_, server)) {
            // 找到了该网点密钥信息，写到传出参数
            memcpy(node, it, sizeof(ShmNode));
            Separate();
            return true;
        }
    }

    Separate();
    return false;
}

KeyShm::~KeyShm() {}