#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <time.h>
 
const int BUF_SIZE = 32;
 
int main()
{
    int shmid;
    key_t key = 1234;
    char *shm, *buf;
    srand(time(NULL));
 
    if ((shmid = shmget(key, BUF_SIZE, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }
 
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }
 
    buf = shm;
    for (int i = 0; i < BUF_SIZE - 1; i++) {
        *buf++ = '0' + rand() % 10;
    }

    if (shmdt(shm) == -1) {
        perror("shmdt");
        exit(1);
    }
 
    return 0;
}
