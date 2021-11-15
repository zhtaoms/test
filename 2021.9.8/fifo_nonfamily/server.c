#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>

//服务器端 父进程发送 子进程接受
int main()
{
    pid_t fpid;
    int fd,fd1;
    char buf[20],buf1[20];
    int bitread,bitread1;
    int bitwrite,bitwrite1;

    if((mkfifo("public",0666))<0)//创建公共管道
    {
        printf("creat public pipe error!\n");
        exit(1);
    }
    
    if((mkfifo("user",0666))<0)//创建公共管道
    {
        printf("creat user pipe error!\n");
        exit(2);
    }
//  if((mkfifo("public",0666))<0)
//         {
//             printf("creat pipe error!!\n");
//             exit(1);
//         }
//         if((mkfifo("client",0666))<0)
//         {
//             printf("2___creat pipe error!!\n");
//             exit(2);
//         }


    fpid=fork();
    if(fpid<0)
    {
        printf("fork error\n");
        exit(0);
    }
    if(fpid==0)//子进程接收
    {
        while(1)
        {
            if((fd=open("public",O_RDWR))<0)
            {
                printf("open public error!\n");
                exit(10);
            }
            if((bitread=read(fd,buf,sizeof(buf)))<0)
            {
                printf("public read error!\n");
                exit(11);
            }
            buf[bitread]='\0';
            printf("%s\n",buf);
            close(fd);
        }
    }
    if(fpid>0)//父进程 发送
    {
        while(1)
        {
            if((fd1=open("user",O_RDWR))<0)
            {
                printf("open client error!\n");
                exit(2);
            }
            
            scanf("%s",buf1);
            if(strcmp(buf1,"q")==0)
            {
                exit(0);
            }

            if((bitwrite=write(fd1,buf1,sizeof(buf1))<0))
            {
                printf("client write error!\n");
                exit(3);
            }
            close(fd1);


        }
    }
    return 0;
}
