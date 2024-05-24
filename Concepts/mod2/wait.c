#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h> //needed to use fork function
#include <time.h> 

int main(int argc, char* argv[]){
    int id = fork(); 
    int n;
    if (id == 0){ //we're in the child process
        n = 1;
    } else {
        n = 6;
    }

    if (id != 0){
        wait(NULL);
    }

    for (int i = n; i < n + 5; i++) {
        printf("%d ", i);
        fflush(stdout); //this avoids a print buffer and will show in terminal immediately
    }
    //printf("\n");
    return 0;
}