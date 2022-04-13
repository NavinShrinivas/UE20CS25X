//Demo for LRU Page reaplcement


#include<stdio.h> 

int main(){
    int ref[100];
    printf("Enter length of refrence string : ");
    int n;
    scanf("%d",n);
    printf("Enter the refrence string : \n ");
    for(int i=0i<n;i++)
        scanf("%d",ref[i]);
    printf("Enter number of frame : ");
    int f;
    scanf("%d",&f);
    //keep all frame free initially thus -1 

    int recently_used[f];
    int frames[f];
    for(int i=0;i<f;i++){
        frames[i] = -1;
        recently_used[i] = -1;
    }
    for(int i=0;i<n;i++){
        //check is needed frame already there : 
        //if so update the recently used thing
        int needed_frame = ref[i];
        for(int j=0;j<f;j++){
            if(needed_frame == frames[j]){
                break;
            }
        }
        //If not, check which one to replace
    }
}
