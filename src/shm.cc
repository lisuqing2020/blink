#include "shm.h"

Shm::Shm(key_t key, size_t size) {
    if(size == 0) {
        shmid_ = shmget(key, 0, 0); // 打开共享内存
    } else {
        shmid_ = shmget(key, size, IPC_CREAT|0644); // 创建共享内存
    }
}

void* Shm::Combine() {
    shmaddr_ = shmat(shmid_, NULL, 0);
    return shmaddr_;
}

void Shm::Separate() {
    shmdt(shmaddr_);
}

Shm::~Shm() {
    shmctl(shmid_, IPC_RMID, NULL);
}