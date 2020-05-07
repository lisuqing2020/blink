#ifndef _SHM_H_
#define _SHM_H_

#include <sys/ipc.h>
#include <sys/shm.h>
#include <cstddef>
#include <cstring>

class ShmNode {
public:
    int status_;
    int keyid_;
    char client_[12];
    char server_[12];
    char key_[128];
};

class Shm {
private:
    int shmid_;
    void* shmaddr_;
public:
    Shm(key_t key, size_t size);
    void* Combine();
    void Separate();
    ~Shm();
};

class KeyShm: public Shm {
private:
    int maxnode_;
public:
    KeyShm(key_t key, size_t maxnode);
    bool Write(ShmNode* node);
    bool Read(char* client, char* server, ShmNode* node);
    ~KeyShm();
};

#endif