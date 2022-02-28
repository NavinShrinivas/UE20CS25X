// This is a 2 pipe, only rcv from one side and send from both sides
// send side
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
int main() {
  int fd;
  char *file = "/home/navin/hello";
  mkfifo(file, 0777);
  while (true) {
    fd = open(file, O_WRONLY);
    char input[80];
    printf("Enter message : ");
    fflush(stdout);
    scanf("\t%[^\n]c", input);
    write(fd, input, strlen(input) + 1);
    close(fd);

    fd = open("/home/navin/hello", O_RDONLY);
    char output[80];
    read(fd, output, sizeof(output));
    printf("got back : %s \n", output);
    close(fd);
  }
}
