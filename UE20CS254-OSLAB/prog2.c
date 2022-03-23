#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>



void swap(int* a,int* b){
    int t= *a;
    *a=*b;
    *b = t;
}

int a[] = { 1,6,2,4,5,8,9,0 };

int main(){
    pid_t p1;
    p1 = fork();
    if(p1 > 0){//parent
        wait(NULL);
        for(int i=0;i<8;i++){
            printf("%d ",a[i]);
        }
    }else{
        //bubble sort 
        int i, j;
        for (i = 0; i < 8-1; i++)   {
            for (j = 0; j < 8-i-1; j++)
                if (a[j] > a[j+1])
                    swap(&a[j], &a[j+1]);
        }
    }
}
