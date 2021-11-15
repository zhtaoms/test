#include<stdio.h>
#include <sys/stat.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<pthread.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/wait.h>

int var =100;
void sys(char*str)
{
    perror(str);
    exit(-1);
}

int main(int argc,char **argv)
{
    int *p;
    pid_t pid;


    //P指针指向文件内存映射区
    p=(int *)mmap(NULL,4,PROT_READ|PROT_WRITE,MAP_SHARED|MAP_ANONYMOUS,-1,0);
    if(p==MAP_FAILED)
    {
        sys("mmap error");
    }
    
    pid=fork();
    if(pid==0)
    {
        *p=2000;
        var=1000;
        printf("child, *p=%d,var =%d",*p,var);
    }else{
        var=500;
        sleep(1);
        printf("parent ,*p=%d ,var=%d",*p,var);
    }
    wait(NULL);
    munmap(p,4);

    return 0;
}
