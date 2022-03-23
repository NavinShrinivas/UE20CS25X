#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
    char x,y;
    scanf("%c %c",&x,&y);
    char* a[] = {&x,&y,NULL};
    execv("./a1.out",a);
}
