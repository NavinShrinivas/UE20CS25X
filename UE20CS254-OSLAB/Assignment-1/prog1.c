// program to demonstrate creation of child processes and
// executing commands using fork(), execl() and wait()

/*
C System Functions in Exec Family:
The exec function families are defined in the header unistd.h.
So, you must use this header on the
C program where you want to use these functions.

execl() System Function:
In execl() system function takes the path of the
executable binary file (i.e. /bin/ls) as the first
and second argument. Then, the arguments (i.e. -lh, /home) that
you want to pass to the executable followed by NULL.
Then execl() system function runs the command and prints the output.
 If any error occurs, then execl() returns -1. Otherwise, it returns nothing.

Syntax:
int execl(const char *path, const char *arg, ..., NULL);
An example of the execl() system function is given below:

*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
      pid_t p1;
      p1 = fork();
      if (p1 > 0){//parent proc
          wait(NULL); //wait for child proc to exit(0)
      }
      if(p1 == 0)
     {
      execl("/bin/ls", "./", "-l", NULL);
      exit(0);
     }
}

