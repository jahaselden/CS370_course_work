#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    pid_t pid;
    int divisor = argv[1];
    // testing
    printf("divisor: %d", divisor);

    for (int i = 2; i < 5; i++)
    {
        pid = fork();
        printf("Coordinator: forked process with ID %d.", pid);
    }

    return 0;
}