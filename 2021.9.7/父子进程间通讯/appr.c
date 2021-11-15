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

    int fd;
    fd=open("temp",O_RDWR|O_CREAT|O_TRUNC,0644);
    if(fd<0)
        sys("open error");
    
    unlink("temp");//删除临时文件的目录项（相当于硬连接），使之具有被释放的条件 所有使用其的进程关系后被释放
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
    pid=fork();
    if(pid==0)
    {
        *p=2000;
        var=1000;
        printf("child, *p=%d,var =%d",*p,var);
    }else{
        sleep(1);
        printf("parent ,*p=%d ,var=%d",*p,var);
    }
    wait(NULL);
    munmap(p,4);

    return 0;
}
