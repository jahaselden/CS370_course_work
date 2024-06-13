#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/resource.h>

//we're passing arguments to this so we need parameters for main
int main(int argc, char** argv){
    //extract arguments
    int fd = atoi(argv[0]);
    int fav_number = atoi(argv[0]);

    //reading whatever is in the file descriptor into fav_number - reading exact num of bytes for that var
    read(fd, &fav_number, sizeof(fav_number));
    printf("Input from pipe: %d\n", fav_number);

    return 0;
}