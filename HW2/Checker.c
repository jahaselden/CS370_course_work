// do this functionality first

/*
Checker: This program requires two arguments to complete its task. The Checker checks whether or not argTwo (the dividend) is divisible
by argOne (the divisor) and prints out the result. Both these arguments are positive integers.

The two arguments that the Checker needs to perform its mathematical operation will be supplied to it by the Coordinator; the Coordinator
is supplied these aforementioned arguments from the command line.

All print statements must indicate the program that is responsible for generating them. To do this, please prefix your print statements
with the program name i.e. Coordinator or Checker. The example section below depicts these sample outputs.
*/

#include <stdio.h>
#include <unistd.h>

int checkDivision(int divisor, int dividend)
{
    int pid = getpid();
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


// int main(){
//     checkDivision(4, 3);
//     return 0;
// }
