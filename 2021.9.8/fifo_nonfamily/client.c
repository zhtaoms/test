#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>

//客户端 父进程接受 子进程发送
int main()
{
    pid_t fpid;
    int fd,fd1;
    char buf[20],buf1[20];
    int bitread,bitread1;
    int bitwrite,bitwrite1;

    

    fpid=fork();
    if(fpid>0)//父进程 接受
    {
        while(1)
        {
            if((fd=open("user",O_RDWR))<0)
            {
                printf("open client error!\n");
                exit(2);
            }
            if((bitread=read(fd,buf,sizeof(buf))<0))
            {
                printf("client read error!\n");
                exit(2);
            }
            buf[bitread]='\0';
            printf("%s\n",buf);
            close(fd);
        }
    }
    if(fpid==0)//子进程fasong
    {
        while(1)
        {
            if((fd1=open("public",O_RDWR))<0)
            {
                printf("open public error!\n");
                exit(10);
            }
            scanf("%s",buf1);
            if(strcmp(buf1,"q")==0)
            {
                exit(0);
            }

            if((bitwrite=write(fd1,buf1,sizeof(buf1))<0))
            {
                printf("user write error!\n");
                exit(11);
            }
            close(fd1);


        }
    }
    return 0;
}