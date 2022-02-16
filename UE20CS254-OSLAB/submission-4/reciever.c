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
  struct my_msgbuf msg;
  int msgid = msgget((key_t)1200, 0777);
  char output[1000];
  msgrcv(msgid, &msg, sizeof(msg.mtext), 0, 0);
  printf("%s", msg.mtext);
}
