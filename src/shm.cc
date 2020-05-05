#include "shm.h"

Shm::Shm(key_t key, size_t size) {
    shmid_ = shmget(key, size, IPC_CREAT|0644);
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