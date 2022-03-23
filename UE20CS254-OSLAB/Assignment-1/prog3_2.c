#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    char *x = argv[0];
    char *y = argv[1];
    int sum = atoi(x)+atoi(y);
    printf("From another process!! \n");
    printf("Sum of two number : %d ",sum);

    return 0;
}
