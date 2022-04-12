
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include<stdlib.h>
#include <sys/wait.h>
int main() {
    int fd;
    char *file = "/home/navin/hello";
    mkfifo(file, 0777);
    FILE* input_fd = fopen("./input.txt","r");

    char content[2000];
    fscanf(input_fd,"%[^\n]c",content);

    fd = open(file, O_RDWR);

    write(fd, content, strlen(content) + 1);
    pid_t p1;
    p1 = fork();
    if (p1 > 0){//parent proc
        wait(NULL); //wait for child proc to exit(0)
    }
    if(p1 == 0)
    {

        char output[80];
        read(fd, output, sizeof(output));
        printf("%s",output);
        FILE* output_fd = fopen("./output.txt","w+");
        fprintf(output_fd,"%s",output); 
        int wc = 0;
        int i=0;
        while(output[i]!='\0'){
            if(output[i] == ' ')
                wc++;
            i++;
        }
        wc++;//for last word
        printf("\n Word count : %d",wc);
        exit(0);
    }
}
