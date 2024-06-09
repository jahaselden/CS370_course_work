#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(int argc, char** argv){
    //pipe stuff to retrieve sharedMemId (the read end retrieval)
    int sharedMemoryIdDummy = 42; //placeholder for actually retrieving id

    //get a pointer to shared memory
    int *sharedMemPointer = (int*)shmat(sharedMemoryIdDummy, NULL, 0);

    //write to shared memory - store value 1 for example
    //hw3 will write a one or a zero based on the divisor / %
    *sharedMemPointer = 1;

    //detach from shared mem segment
    shmdt(sharedMemPointer);

    return 0;
}