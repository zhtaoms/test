#include<stdio.h>
#include <sys/stat.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<pthread.h>
#include <sys/mman.h>

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
    int fd;
    fd=open("temp.txt",O_RDWR|O_CREAT|O_TRUNC,0644);

    if(fd<0)
        sys("open error");
    int ret=ftruncate(fd,4);//指定文件修改大小
    if(ret<0)
        sys("ftruncate error");


    //P指针指向文件内存映射区
    p=(int *)mmap(NULL,4,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
    if(p==MAP_FAILED)
    {
        sys("mmap error");
    }
    close(fd);
    memcpy(p,"abc",3);
    munmap(p,4);

    return 0;
}
