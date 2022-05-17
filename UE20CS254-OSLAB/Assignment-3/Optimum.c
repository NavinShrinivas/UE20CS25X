#include<stdio.h> 

int page_fault = 0;


void enter_page(int* ref,int page_number,int i,int n,int* frames,int f){
    //Before anything, have to check if page already in fram list 
    for(int j=0;j<f;j++){
        if(frames[j] == page_number)
            return;
    }
    
    page_fault++;
    //First check for a free place in the frames 
    for(int i=0;i<f;i++){
        if(frames[i] == -1){
            frames[i] = page_number;
            return;
        }
    }
    //If no free frames, need to find what to replace
    //Starting from current frame, see all the near by frames
    int non_replace_arr[f];
    for(int j=0;j<f;j++){
        non_replace_arr[j] = 0;
    }
    int left_replace=f;
    for(int j=i;j<n;j++){
        if(left_replace == 1){
            break;
        }
        for(int k=0;k<f;k++){
            if(frames[k] == ref[j]){
                non_replace_arr[k] = 1;
                if(left_replace == 1)
                    break;
                left_replace--;
            }
        }
    }
    printf("%d",left_replace);
    fflush(stdout);
    for(int j=0;j<f;j++){
        if(non_replace_arr[j]!=1){
            frames[j] = page_number ;
            break;
        }
    }
}

int main(){
    int ref[100];
    printf("Enter length of refrence string : ");
    int n;
    scanf("%d",&n);
    printf("Enter the refrence string : \n ");
    for(int i=0;i<n;i++)
        scanf("%d",&ref[i]);
    printf("Enter number of frame : ");
    int f;
    scanf("%d",&f);
    //keep all frame free initially thus -1 
    int frames[f];
    for(int i=0;i<f;i++){
        frames[i] = -1;
    }
    for(int i=0;i<n;i++){
        enter_page(ref,ref[i],i,n,frames,f);
        printf("Current fram state : \n");
        for(int j=0;j<f;j++){
            printf("%d ",frames[j]);
        }
        printf("\n");
    }

    printf("Total number of page faults : %d \n ",page_fault);
}
