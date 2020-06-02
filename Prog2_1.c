#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <signal.h>
#include <stdlib.h>
#define SIZE 1024 
void signalHandler(int signo);
int shmid;

int main() {
    void *shmaddr;
    void *sh;

    if((shmid=shmget((key_t)1234, SIZE, IPC_CREAT|0666))==-1) {
        perror("shmid failed");
        exit(1);
    }

    if((shmaddr=shmat(shmid, (void *)0, 0))==(void *)-1) {
        perror("shmat failed");
        exit(1);
    }


    for(int i=0; i<10; i++) {
        strcpy((char *)shmaddr, "System");
	sleep(1);
        printf("A: %s\n", (char *)shmaddr);
    }

    if(shmdt(shmaddr)==-1) {
        perror("shmdt failed");
        exit(1);
    }

    return 0;
}

