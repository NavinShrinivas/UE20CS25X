// program to demonstrate fork()

#include <stdio.h>
#include <unistd.h>
/*
Fork system call is used for creating a new process, which is called
 child process, which runs concurrently with the process that makes
 the fork() call (parent process). After a new child process is created,
 both processes will execute the next instruction following the fork()
 system call. A child process uses the same pc(program counter),
 same CPU registers, same open files which use in the parent process.

It takes no parameters and returns an integer value.
Below are different values returned by fork().

Negative Value: creation of a child process was unsuccessful.
Zero: Returned to the newly created child process.
Positive value: Returned to parent or caller.
The value contains process ID of newly created child process.


*/
int main() {
  pid_t p1;
  int i = 0, y = 0;
  p1 = fork();
  /*
   *Important: Parent process and child process are running the same program,
   *but it does not mean they are identical. OS allocate different data and
   *states for these two      *processes, and the control flow of these
   *processes can be different. See next example  :
   */
  if (p1 > 0) { // parent process
    for (i = 0; i < 5; i++) {
      sleep(i);
      y = y - 1;
      printf("This is parent. Process Id = %d, y = %d\n", getpid(), y);
    }
  } else if (p1 == 0) { // child process
    for (i = 0; i < 5; i++) {
      sleep(i);
      y = y + 1;
      printf("This is child. Process Id = %d, Parent Process Id = %d, y = %d\n",
             getpid(), getppid(), y);
    }
  } else { // forking failed
    printf("fork creation failed!!!\n");
  }
}
