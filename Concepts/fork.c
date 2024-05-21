#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h> //needed to use fork function

int main(int argc, char* argv[]){
    int id = fork(); 
    //there will be two id's returned here, one from the parent (main), one from the child process
    printf("Hello World from id: %d \n", id); 
    if (id == 0){
        printf("hello from the child process\n");
    } else {
        printf("hello from the main process\n");
    }
    return 0;
}