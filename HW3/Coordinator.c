
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/resource.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(int argc, char *argv[])
{
    int pid;
    int returnCode = -1;

    for (int i = 2; i < 6; i++)
    {
        // 1. create unique shared memory segments for each Checker instance to store results
        int sharedMemId = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | 0666);

        // 2. create pipe for each Checker instance that provides it with the ID of the shared
        //  memory segment created in step 1 - fd of the pipe is passed as an additional
        //  argument to the checker
        int fd[2];
        pipe(fd);

        pid = fork();

        if (pid == -1)
        {
            printf("fork failed");
            return -1;
        }
        if (pid == 0)
        {
            //create a char array 
            char buffer[8];

            sprintf(buffer, "%d", fd[0]);

            execlp("checker", "checker", argv[1], argv[i], buffer, NULL); //step 4
        }
        else
        {
            printf("Coordinator: forked process with ID %d.\n", pid);

            // close the read end of the pipe
            close(fd[0]);

            // write the shared memory id address to pipe - step 5
            write(fd[1], &sharedMemId, sizeof(sharedMemId));

            // close write end of the pipe
            close(fd[1]);

            printf("Coordinator: wrote shm ID %d to pipe (%lu bytes)\n", sharedMemId, sizeof(sharedMemId));
            printf("Coordinator: waiting for process [%d].\n", pid);
            // int status;
            // wait(&status);
            // returnCode = WEXITSTATUS(status);
            // attach to the shared memory segment
            int *sharedMemPointer = (int *)shmat(sharedMemId, NULL, 0);

            // read from shared memory segment
            read(fd[0], &returnCode, sizeof(returnCode));

            // destroy the shared memory segment
            shmctl(*sharedMemPointer, IPC_RMID, NULL);

            // int status;
            // wait(&status);

            // change this line to match instructions
            if (returnCode == 0)
            {
                printf("Coordinator: result %d (not divisable) read from shared memory.\n", returnCode);
            }
            else if (returnCode == 1)
            {
                printf("Coordinator: result %d (divisable) read from shared memory.\n", returnCode);
            }
        }
    }

    printf("Coordinator: exiting.\n");
    return 0;
}