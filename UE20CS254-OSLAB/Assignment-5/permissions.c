#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include<dirent.h>
#include<string.h>

int main (int argc, char **argv)
{
    if(argc != 5){
        printf("Format Error! \n ");
        printf("Follow the following format : ./executable.out /full/absolute/path/ DD MM YYYY \n");
        printf("Note that the / after full path is ver important");
        return 0;
    }
    int day = atoi(argv[2]);
    int mon = atoi(argv[3]);
    int yer = atoi(argv[4]);
    struct stat attrib;
    DIR* d = opendir(argv[1]);
    struct dirent* filefo_path;
    while((filefo_path = readdir(d))!=NULL){
        char temp[1000];
        strcpy(temp,argv[1]);
        strcat(temp,filefo_path->d_name);
        stat(temp,&attrib);
        struct tm* time_struct = gmtime(&attrib.st_mtime);
            /*printf("%s %d %d %d \n",temp,time_struct->tm_mday,time_struct->tm_mon+1,time_struct->tm_year+1900);*/
        if(time_struct->tm_year + 1900 >= yer && time_struct->tm_mday >= day && time_struct->tm_mon+1 >= mon){

            printf("%s %d %d %d  previous size : %d\n",temp,time_struct->tm_mday,time_struct->tm_mon+1,time_struct->tm_year+1900,(int)attrib.st_size);
            truncate(temp,(int)attrib.st_size/2);
            struct stat attrib1;
            stat(temp,&attrib1);
            printf("mod size : %d\n",(int)attrib1.st_size);
        }
    }
}
