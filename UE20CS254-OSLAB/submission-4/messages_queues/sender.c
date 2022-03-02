#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <unistd.h>

struct my_msgbuf {
  long mtype;
  char mtext[200];
};

int main() {
  int msgid = msgget(ftok("haloo", 65), 0777 | IPC_CREAT);
  // ftok gets us a unique ID for our message queues
  // 0777 id the read write permissions for the queue
  struct my_msgbuf msg;
  printf("Enter text to append to queue : ");
  scanf("%[^\n]*c", msg.mtext);
  msg.mtype = 1; // must, can be 0 or greater
  msgsnd(msgid, &msg, sizeof(msg), 0);
  // msgsend ofc sends the message :)
}
