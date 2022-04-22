#include<stdio.h> 
#include <stdlib.h> 


//GLOBAL VARS
int no_frames;

void insert_to_mem(int proc_size,int page_size,int* memory){
    //We also make page table entries in the same function
    int no_pages = proc_size/page_size;
    int j=0;
    while(j<no_pages){
        //paging give preference to contiguous storage and hence need to search for 
        //largest contiguous block available
        int starting = 0; //init starting address of contiguos block
        int ending = 0; //init ending address of contiguos block 
        int temp_starting = 0;
        int temp_ending = 0;
        int largest_size = 0;
        int temp_largest = 0;
        for(int i=0;i<no_frames;i++){
            if(memory[i] == 0){
                temp_largest+=1;
                temp_ending = i;
            }else{
                printf("Hello");
                fflush(stdout);
                if(temp_largest > largest_size){
                    largest_size = temp_largest ;
                    starting = temp_starting;
                    ending = temp_ending;
                }
                temp_largest = 0; 
                temp_starting = i+1;
                temp_ending = i+1;
            }
        }
        if(largest_size >= no_pages){//we have large enuf blocs 
            printf("Hello");
            fflush(stdout);
            for(int k=0;k<no_pages;k++){
                memory[starting]=1;
                starting++;
                j++;
            }
        }else{
            for(int k=0;k<largest_size;k++){
                memory[starting]=1;
                starting++;
                j++;
            }
        }
    }
}


//Often times the programs online for paging is using a memory that stores the proc_number and its pages
//Instead here I have used a page table, where instead of maintaning PTBR for each process, I pseudo create one page table for each process.
int main(){
    int mem_size,page_size;
    printf("Enter memory size and page size (following same units) : ");
    scanf("%d %d",&mem_size,&page_size);
    no_frames = mem_size / page_size;
    int memory[no_frames];
    for(int i=0;i<no_frames;i++){
        memory[i] = 0;
    }

    printf("Page size(logical/process) is same as frame size, following so, total number of frames in memory : %d",no_frames);
    printf("Enter number of processes to store in main memory : ");
    int no_proc;
    scanf("%d",&no_proc);
    int tlb[no_proc][no_frames];
    //any given process can not take more than max number of frams (no_frames), that also means we dont need to keep page table entires of more than max frames for each proc.

    printf("Enter size of processes (Same units as before) : \n");
    for(int i=0;i<no_proc;i++){
        int proc_size;
        printf("Size of p%d : ",i+1);
        scanf("%d",&proc_size); 
        insert_to_mem(proc_size,page_size,memory);
    }

}
