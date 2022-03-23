#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
    char x[100],y[100];
    printf("Enter number 1 : ");
    fgets(x,99,stdin);
    printf("Enter number 2 : ");
    fgets(y,99,stdin);
    char* a[] = {x,y,NULL};
    execv("./a1.out",a);
}
