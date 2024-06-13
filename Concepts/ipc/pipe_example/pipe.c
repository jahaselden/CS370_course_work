#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/resource.h>

int main() {
    printf("test");
    //declaring an integer array of size 2
    int fd[2];
    //passing array as an argument
    pipe(fd);

    //fork a child process
    int pid = fork();

    //check where we are
    if (pid < 0) {
        printf("fork failed\n");
    }
    else if (pid > 0) {
        //close the read end of the pipe, parent only writes to the pipe
        close(fd[0]);
        //pass this into the pipe for the child process to read
        int fav_num = 27;
        //file descriptor at location 1, memory address of the int created, and size of same variable
        //write the address of my int to the write end of the pipe and write exactly fav_num number of bytes
        write(fd[1], &fav_num, sizeof(fav_num));
        //close write end of the pipe bc we are done writing to it
        close(fd[1]);
    }
    else {
        //create a char array 
        char buffer[8];
        //instead of printing on the console, it stores output on char buffer (array) 
        //pass it buffer (the write to), specify integer as the type, and read end of pipe into buffer 
        sprintf(buffer, "%d", fd[0]);
        execlp("child", buffer, NULL);
    }

    return 0;
}