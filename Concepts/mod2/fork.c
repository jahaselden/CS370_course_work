#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h> //needed to use fork function

int main(int argc, char *argv[])
{
    // youtube examplt
    //  int id = fork();
    //  //there will be two id's returned here, one from the parent (main), one from the child process
    //  printf("Hello World from id: %d \n", id);
    //  if (id == 0){
    //      printf("hello from the child process\n");
    //  } else {
    //      printf("hello from the main process\n");
    //  }

    // infospaces example

    pid_t pid = fork();

    if (pid == -1)
    {
        printf("fork failed\n");
    }

    if (pid == 0)
    {
        printf("child process beginning.. \n");
        execlp("childtask", NULL);
        printf("child process complete \n");
    }
    else
    {
        printf("parent process beginning.. \n");
        int status;
        // using & returns the address of a variable
        wait(&status);
        int result = WEXITSTATUS(status);
        printf("child returned: %d\n", result);
        printf("parent process complete \n");
    }

    return 0;
}