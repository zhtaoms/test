#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>



int main()
{
    int fd[2];
    pid_t pid;

    int ret=pipe(fd);//创建管道
    if(ret<0)
    {
        perror("pipe error:");
        exit(-1);
    }

    pid =fork();
    if(pid<0)
    {
        perror("pipe error:");
        exit(-1);
    }else if(pid==0){//紫荆城 读 父进程写
        close(fd[1]);
        char buf[1024];
        ret=read(fd[0],buf,sizeof(buf));
        if(ret==0)
        {
            printf("-----------\n");
        }   
        write(STDOUT_FILENO,buf,ret);

    }else{
        close(fd[0]);
        char* str="hello world";
        write(fd[1],"hello world\n",strlen("hello world\n"));

    }

    return 0;
}