#include <stdio.h>
    #include <unistd.h>
    #include <sys/types.h>
    #include <stdlib.h>
    #include <sys/stat.h>
    #include <string.h>
    #include <fcntl.h>
 
    int main(int argc,char *argv[])
    {
        int fd,fd1;
        pid_t fpid;
        char buf[20],buf1[20];
        int bytes_read,bytes_write;
        int bytes_read1,bytes_write1;
 
        if((mkfifo("myfifo",0666))<0)
        {
            printf("creat pipe error!!\n");
            exit(1);
        }
        if((mkfifo("yourfifo",0666))<0)
        {
            printf("2___creat pipe error!!\n");
            exit(2);
        }
        
        fpid=fork();
 
        /*子进程，用来接收客户端进程发送来的信息*/
        if(fpid==0)
        {
            while(1)
            {
                printf(">");
                if((fd1=open("yourfifo",O_RDWR))<0)
                {
                    printf("open yourfifo error!\n");
                    exit(10);
                }
                if((bytes_read=read(fd1,buf1,sizeof(buf1)))<0)
                {
                    printf("read yourfifo error!\n");
                    exit(11);
                }
                buf1[bytes_read]='\0';
                printf("%s\n",buf1);
                close(fd1);
            }
        }
        /*父进程，用于给客户端发送信息*/
        if(fpid>0)
        {
            while(1)
            {
                if((fd=open("myfifo",O_RDWR))<0)
                {
                    printf("open pipe error!\n");
                    exit(2);
                }
                printf(">");
                scanf("%s",buf);
                if((strcmp(buf,"quit"))==0)
                {
                    exit(0);
                }
 
                if((bytes_write=write(fd,buf,sizeof(buf)))<0)
                {
                    printf("write pipe error!!\n");
                    exit(3);
                }
                close(fd);
            }
    //  close(fd);  
              }
                      return 0;
                      }
