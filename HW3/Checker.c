
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/resource.h>
#include <sys/ipc.h>
#include <sys/shm.h>
 
int checkDivision(int divisor, int dividend, int pid, int fd)
{
    int sharedMemId = -1;
    int returnVal = -1;
 
    // must print current process id, must match the one returned by the fork() command in step 3
    printf("Checker process [%d]: Starting.\n", pid);

    //retrieve shared memory segment ID from pipe - step 6
    read(fd, &sharedMemId, sizeof(sharedMemId));

    //get pointer for shared memory
    int *sharedMemPointer = (int*)shmat(sharedMemId, NULL, 0);

    printf("Checker process [%d]: read %lu bytes containg shm ID %d\n", pid, sizeof(sharedMemId), sharedMemId);
 
    int remainder = dividend % divisor;
 
    if (remainder == 0)
    {
        printf("Checker process [%d]: %d *IS* divisible by %d.\n", pid, dividend, divisor);
        *sharedMemPointer = 0;
        returnVal = 1;
    }
    else if (remainder != 0)
    {
        printf("Checker process [%d]: %d *IS NOT* divisible by %d.\n", pid, dividend, divisor);
        *sharedMemPointer = 1;
        returnVal = 0;
    }
 
    printf("Checker process [%d]: wrote result(%d) to shared memory.\n", pid, returnVal);

    //detach from shared mem segment
    shmdt(sharedMemPointer);

    return returnVal;
}
 
int main(int argc, char **argv)
{
    if (argc != 4)
    {
        printf("incorrect number of args");
        return -1;
    }
 
    pid_t pid = getpid();
    int divisor = atoi(argv[1]);
    int dividend = atoi(argv[2]);
    
    //retrieve shared memory data
    int fd = atoi(argv[3]);
    printf("fd: %d\n", fd);
    
    return checkDivision(divisor, dividend, pid, fd);
}