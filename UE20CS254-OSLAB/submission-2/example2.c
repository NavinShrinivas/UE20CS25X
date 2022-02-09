// program to demonstrate fork() and wait()

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

/*
 *
 *wait(NULL) will block parent process until any of its children has finished.
 *If child terminates before parent process reaches wait(NULL) then the child
 *process turns to a zombie process until its parent waits on it and its
 *released from memory.
 *
 *If parent process doesn't wait for its child, and parent finishes first,
 *then the child process becomes orphan and is assigned to init as its child.
 *And init will wait and release the process entry in the process table.
 *
 *In other words: parent process will be blocked until child process returns
 *an exit status to the operating system which is then returned to parent
 *process. If child finishes before parent reaches wait(NULL) then it will read
 *the exit status, release the process entry in the process table and continue
 *execution until it finishes as well.
 */

// so what are zombie processes?
/*
 *A zombie process is a process whose execution is completed but it still has an
 *entry in the process table. Zombie processes usually occur for child
 *processes, as the parent process still needs to read its child’s exit status.
 */
// this makes the exist status of child process very important

int main() {
  pid_t p1;
  int y = 0;
  p1 = fork();
  if (p1 > 0) { // parent process
    wait(NULL);
    y = y - 1;
    printf("This is parent. Process Id = %d, y = %d\n", getpid(), y);
  } else if (p1 == 0) { // child process
    y = y + 1;
    printf("This is child. Process Id = %d, Parent Process Id = %d, y = %d\n",
           getpid(), getppid(), y);
    exit(0);
    // parent wait for this exit status when it comes across wait(NULL)
    // if child was done before parent reached wait(NULL) it becomes a zombie
    // process and waits to parent to read it's exit status
  } else { // fork failed
    printf("fork creation failed!!!\n");
  }
}
