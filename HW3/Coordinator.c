#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(int argc, char *argv[])
{
    // for printing after executing parallel processes
    int pid[4];
    int sharedMemId[4];

    for (int i = 2; i < 6; i++)
    {
        int index = 0;

        int fd[2];
        pipe(fd); // step 2

        pid[index] = fork();

        if (pid[index] == -1)
        {
            printf("fork failed");
            return -1;
        }
        if (pid[index] == 0)
        {
            // create a char array
            char buffer[8];

            // passing the read end of the pipe into the buffer
            sprintf(buffer, "%d", fd[0]);

            execlp("checker", argv[1], argv[i], buffer, NULL); // step 4
            exit(0);
        }
        else
        {
            int shm_id = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | 0666); // step 5.a.
            sharedMemId[index] = shm_id;

            printf("Coordinator: forked process with ID %d.\n", pid[index]); // step 3

            // close the read end of the pipe
            close(fd[0]);
            // write the shared memory id address to pipe - step 5.b.
            write(fd[1], &sharedMemId[index], sizeof(sharedMemId[index]));
            // close write end of the pipe
            close(fd[1]);

            printf("Coordinator: wrote shm ID %d to pipe (%lu bytes)\n", sharedMemId[index], sizeof(sharedMemId[index]));
        }

        index++;
    }

    for (int index = 0; index < 4; index++)
    {
        printf("Coordinator: waiting on child process ID [%d]...\n", pid[index]);

        // attach to the shared memory segment
        int *sharedMemPointer = (int *)shmat(sharedMemId[index], NULL, 0);

        waitpid(pid[index], NULL, 0);

        // read from shared memory segment
        if (*sharedMemPointer)
        {
            printf("Coordinator: result %d (not divisable) read from shared memory.\n", *sharedMemPointer);
        }
        else
        {
            printf("Coordinator: result %d (divisable) read from shared memory.\n", *sharedMemPointer);
        }

        // destroy the shared memory segment
        shmctl(*sharedMemPointer, IPC_RMID, NULL);
    }

    printf("Coordinator: exiting.\n");
    return 0;
}