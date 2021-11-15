#include <stdio.h>
    #include <unistd.h>
    #include <sys/types.h>
    #include <stdlib.h>
    #include <sys/stat.h>
    #include <string.h>
    #include <fcntl.h>
 
    int main(int argc,char *argv[])
    {
        int fd;
        int fd1,fpid;
        char buf[20],buf1[20];
        int bytes_read,bytes_write;
        int bytes_read1,bytes_write1;
 
        fpid=fork();
        /*子进程，发送信息给服务器端*/
        if(fpid==0)
        {
            while(1)
            {
                printf(">");
                scanf("%s",buf1);
                if((strcmp(buf1,"quit"))==0)
                {
                    exit(0);
                }
                if((fd1=open("yourfifo",O_RDWR))<0)
                {
                    printf("open yourfifo error!\n");
                    exit(10);
                }
                if((bytes_write1=write(fd1,buf1,sizeof(buf1)))<0)
                {
                    printf("write yourfifo error!\n");
                    exit(11);
                }
                close(fd1);
            }
        }
        /*父进程，接收从服务器端发送来的信息*/
        if(fpid>0)
        {
            while(1)
            {
 
                if((fd=open("myfifo",O_RDWR))<0)
                {
                    printf("open pipe error!\n");
                    exit(2);
                }
 
                if((bytes_read=read(fd,buf,sizeof(buf)))<0)
                {
                    printf("read fifo error!!\n");
                    exit(2);
                }
                buf[bytes_read]='\0';
                printf("%s\n",buf);
                close(fd);
 
            }
 
    //  close(fd);  
            }
                    return 0;
    
      }
