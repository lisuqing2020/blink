#ifndef _SHM_H_
#define _SHM_H_

#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>

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

#endif