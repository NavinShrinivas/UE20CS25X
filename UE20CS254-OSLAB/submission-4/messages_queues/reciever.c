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
  int msgid = msgget(ftok("haloo", 65), 0777);
  char output[1000];
  msgrcv(msgid, &msg, sizeof(msg), 1, 0);
  // message rcv revices all the messages of type 1
  printf("%s", msg.mtext);
}
