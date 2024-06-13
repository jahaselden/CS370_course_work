#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
    //create shared memory
    int sharedMemId = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | 0666);

    //call fork, create a child process


    //parent process handling
    {
        //pipe stuff
    }

    //child process handling
    {
        //get the sharedMemId to the child using pipes and execlp
    }

    //wait for the child to finish

    //attach to the shared memory segment
    int *sharedMemPointer = (int*)shmat(sharedMemId, NULL, 0);

    //read from shared memory segment

    //destroy the shared memory segment
    shmctl(*sharedMemPointer, IPC_RMID, NULL);

    return 0;
}