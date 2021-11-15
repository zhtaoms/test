#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include <arpa/inet.h>
#include <sys/epoll.h>
#include <errno.h>
#include <ctype.h>
#include "wrap.h"

#define MAXLINE 8192
#define SERV_PORT 8000
#define OPEN_MAX 5000

int main()
{
    int i,listenfd,connfd,sockfd;
    int n ,num=0;
    ssize_t nready,efd,res;
    char buf[MAXLINE], str[INET_ADDRSTRLEN];
    socklen_t clilen;

    struct sockaddr_in cliaddr, servaddr;
    struct epoll_event tep, ep[OPEN_MAX];       //tep: epoll_ctl参数  ep[] : epoll_wait参数

    listenfd=Socket(AF_INET,SOCK_STREAM,0);     //设置套接字

    /*端口复用 主要解决服务器关闭msl等待时间 ---》无需等待*/
    int opt=1;
    setsockopt(listenfd,)
    bzero(&servaddr,sizeof(servaddr));//清空
    servaddr.sin_addr.s_addr=htonl(INADDR_ANY);//初始化 将主机的无符号长整形数转换成网络字节顺序
    servaddr.sin_family=AF_INET;
    servaddr.sin_port=htons(SERV_PORT);//将一个无符号短整型数值转换为网络字节序
    Bind(listenfd,(struct sockaddr *)&servaddr,sizeof(servaddr));

    Listen(listenfd,20);//监听套接字lfd 并且设置数量

    /*创建epoll模型*/
    efd=epoll_create(OPEN_MAX);//创建了树根 设置最大节点数
    if(efd==-1)
    {
        perr_exit("epoll creat error\n");
    }
    tep.events=EPOLLIN;tep.data.fd=listenfd;//将“临时”监听节点加入树中
    res=epoll_ctl(efd,EPOLL_CTL_ADD,listenfd,&tep);
    if(res==-1)
    {
        perr_exit("epoll ctl error\n");
    }
    while(1)
    {
        nready=epoll_wait(efd,ep,OPEN_MAX,-1);//返回监听数量
        if(nready==-1)
        {
            perr_exit("epoll wait error\n");
        }
        for(i=0;i<nready;i++)
        {
            if(!(ep[i].events&EPOLLIN))
            {
                continue;
            }
            if(ep[i].data.fd==listenfd)
            {
                clilen=sizeof(cliaddr);
                connfd=Accept(listenfd,(struct sockaddr *)&cliaddr,&clilen);//传入传出参数struct sockaddr

                printf("received from %s at port %d\n",
                    inet_ntop(AF_INET,&cliaddr.sin_addr,str,sizeof(str)),
                    ntohs(cliaddr.sin_port));
                printf("cfd %d ---client %d\n",connfd,++num);
                /*连接成功 加入监测树*/
                tep.events=EPOLLIN;tep.data.fd=connfd;//将监听节点加入树中
                res=epoll_ctl(efd,EPOLL_CTL_ADD,connfd,&tep);
                if(res==-1)
                {
                    perr_exit("epoll ctl error\n");
                }
            }else{//不是连接请求 进行其他操作
                sockfd=ep[i].data.fd;
                n=Read(sockfd,buf,sizeof(buf));
                if(n==0){//读不到数据 将节点删除
                    res=epoll_ctl(efd,EPOLL_CTL_DEL,sockfd,NULL);
                    if(res==-1)
                    {
                        perr_exit("epoll ctl error\n");
                    }
                }else if(n>0)
                {
                    for (i = 0; i < n; i++)
                        buf[i] = toupper(buf[i]);   //转大写,写回给客户端
                    
                    Writen(sockfd,buf,n);
                    Write(STDOUT_FILENO,buf,n);
                }
            }
        }
    }
    close(listenfd);
    Close(efd);

    return 0;
}
