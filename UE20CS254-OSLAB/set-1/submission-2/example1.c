// program to demonstrate fork()

#include <stdio.h>
#include <unistd.h>

/*
Data Type: pid_t
The pid_t data type is a signed integer type which is capable of
representing a process ID. In the GNU library, this is an int.

Function: pid_t getpid (void)
The getpid function returns the process ID of the current process.

Function: pid_t getppid (void)
The getppid function returns the process ID of the parent of the current
process.

*/

/*
 *increadeible link to learn about this program :
 *https://www.geeksforgeeks.org/fork-system-call/#:~:text=Fork%20system%20call%20is%20used,the%20fork()%20system%20call.
 *fork literally forks the the program and causes the parent and the child to
 *run concurrently, they both use the the same memory space. Except the values
 *of fork(), parent and child should have same space [Space before forking].
 *and right after forking value returned by fork() to parent is some positive
 *value and child is 0 if success else -ve if u did not get the previous line,
 *execute and see values of p1 and y
 */

int main() {
  pid_t p1;
  int y = 0;
  p1 = fork();
  /*
   *Negative Value: creation of a child process was unsuccessful.
   *Zero: Returned to the newly created child process.
   *Positive value: Returned to parent or caller. The value contains process ID
   *of newly created child process.
   */
  /*
   *Important: Parent process and child process are running the same program,
   *but it does not mean they are identical. OS allocate different data and
   *states for these two processes, and the control flow of these processes can
   *be different. See next example  :
   */
  if (p1 > 0) { // parent process
    y = y - 1;
    printf("This is parent. Process Id = %d, y = %d\n", getpid(), y);
  } else if (p1 == 0) { // child process
    y = y + 1;
    printf("This is child. Process Id = %d, Parent Process Id = %d, y = %d\n",
           getpid(), getppid(), y);
  } else { // fork failed
    printf("fork creation failed!!!\n");
  }
}
