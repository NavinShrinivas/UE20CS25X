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
  int msgid = msgget((key_t)1200, 0777 | IPC_CREAT);
  struct my_msgbuf msg;
  printf("Enter text to append to queue : ");
  scanf("%[^\n]*c", msg.mtext);

  printf("%d", msgid);
  fflush(stdout);
  msgsnd(msgid, &msg, sizeof(msg.mtext), 0);
}
