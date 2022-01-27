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
  pid_t p1, p2;
  int y = 0;
  p1 = fork();
  if (p1 > 0) { // parent process
    wait(NULL);
    y = y - 1;
    printf("This is parent. Process Id = %d, y = %d\n", getpid(), y);
    execl("/bin/ls", "/home/nivedita/osprograms", NULL);
  } else if (p1 == 0) // child process
  {
    p2 = fork();

    if (p2 > 0) {
      wait(NULL);
    } else if (p2 == 0) {
      y = y + 5;

      printf("This is grandchild. Process Id = %d, Parent Process Id = %d, y = "
             "%d\n",
             getpid(), getppid(), y);
      execl("/bin/ls", "~/", "-r", NULL);
      // the -r flag is for reverse order when sorting
      // execl("path/command","file assosiated","flag1",...,)
      // from man pages :
      /*
       *The const char *arg and subsequent ellipses in the execl(),
       *execlp(), and execle() functions can be thought of as arg0,
       *arg1, ..., argn. [....]
       *The list of arguments must be terminated by a NULL pointer,
       *and, since these are variadic functions, this pointer must be cast (char
       **) NULL.
       */
      // execl should know wen the argument list ends, hence the NULL
      // this will make a lot more sense if you remember variarble length
      // paramets from sem
      exit(0);
    }
    y = y + 1;
    printf("This is child. Process Id = %d, Parent Process Id = %d, y = %d\n",
           getpid(), getppid(), y);
    char *a[] = {NULL};
    execv(
        "/home/navin/github/LearnThings/Rust-02/module09/target/debug/module09",
        a);
    // v in execv stands for vector, and just like execl the vector must be
    // terminated with NULL
    exit(0);
  } else // fork failed
  {
    printf("fork creation failed!!!\n");
  }
}

// man pages are the best to learn about posix functions like execv and execl
// man pages :
/*
 *l - execl(), execlp(), execle()
 *       The  const  char *arg and subsequent ellipses can be thought of as
 *arg0, arg1, ..., argn.  Together they describe a list of one or more pointers
 *to null-terminated strings that represent the argument list available to the
 *executed program.   The first argument, by convention, should point to the
 *filename associated with the file being executed. The list of arguments must
 *be terminated by a null pointer, and, since these are variadic functions, this
 *pointer must be cast (char *) NULL.
 *
 *       By  contrast  with  the 'l' functions, the 'v' functions (below)
 *specify the command-line arguments of the executed program as a vector.
 *
 *   v - execv(), execvp(), execvpe()
 *       The char *const argv[] argument is an array of pointers to
 *null-terminated strings that represent the argument list available  to the new
 *program.  The first argument, by convention, should point to the filename
 *associated with the file being executed.  The array of pointers must be
 *terminated by a null pointer.
 */
