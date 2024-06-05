
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/resource.h>
 
int main(int argc, char *argv[])
{
    int pid;
    int returnCode = -1;
 
    for (int i = 2; i < 6; i++)
    {
 
        pid = fork();
 
        if (pid == -1)
        {
            printf("fork failed");
            return -1;
        }
        if (pid == 0)
        {
            execlp("checker", "checker", argv[1], argv[i], NULL); 
        }
        else
        {
            printf("Coordinator: forked process with ID %d.\n", pid);
            printf("Coordinator: waiting for process [%d].\n", pid);
            int status;
            wait(&status);
            returnCode = WEXITSTATUS(status);
            printf("Coordinator: child process %d returned %d.\n", pid, returnCode);
        }
    }
 
    printf("Coordinator: exiting.\n");
    return 0;
}