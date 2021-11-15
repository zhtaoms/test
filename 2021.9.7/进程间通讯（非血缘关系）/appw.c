#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<pthread.h>
#include <sys/mman.h>


struct student
{
    int id;
    char *name;
    char sex;
}STU;
void sys(char*str)
{
    perror(str);
    exit(-1);
}

int main(int argc,char **argv)
{
    int fd;

    struct student s1={1,"liuming",'m'};
    struct student *m;

    if(argc<2)
    {
        printf("./a.out file_shared\n");
        exit(-1);
    }
    
    fd=open(argv[1],O_RDWR|O_CREAT,0644);
    ftruncate(fd,sizeof(s1));

    if(fd<0)
    {
        sys("open error");
    }
    m=(struct student *)mmap(NULL,sizeof(s1),PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
    if(m==MAP_FAILED)
    {
        sys("mmap error");
    }
    close(fd);
    printf("id =%d",m->id);
    while(1)
    {
        memcpy(m,&s1,sizeof(s1));
        s1.id++;
        sleep(1);
    }
    munmap(m,sizeof(s1));

    return 0;
}
