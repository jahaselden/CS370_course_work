
#include <libgen.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
 
int checkDivision(int divisor, int dividend)
{
    pid_t pid = getpid();
    int returnVal = -1;
 
    // must print current process id, must match the one returned by the fork() command in step 3
    printf("Checker process [%d]: Starting.\n", pid);
 
    int remainder = dividend % divisor;
 
    if (remainder == 0)
    {
        printf("Checker process [%d]: %d *IS* divisible by %d.\n", pid, dividend, divisor);
        returnVal = 1;
    }
    else if (remainder != 0)
    {
        printf("Checker process [%d]: %d *IS NOT* divisible by %d.\n", pid, dividend, divisor);
        returnVal = 0;
    }
 
    printf("Checker process [%d]: Returning %d.\n", pid, returnVal);
    return returnVal;
}
 
 
int main(int argc, char *argv[]){
    int divisor = atoi(argv[1]);
    int dividend = atoi(argv[2]);
    return checkDivision(divisor, dividend);
}