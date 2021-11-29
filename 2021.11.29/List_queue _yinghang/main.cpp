# include <iostream>
#include <cstdlib>
#include <ctime>
#include"Linkqueue.hpp"
#include"EventList.hpp"
using namespace std;

const int CLOSE_TIME = 40;
const int MAX_DURATION = 30;
const int MAX_INTERTIME = 10;

//定义银行客户，Client作为队列的data域
typedef struct client{

    int arrivalTime;// 客户到达银行的时间
    int duration;// 办理业务所需时间

}Client;

//定义队列结点类型
struct Node{
    Client data;
    struct Node *next;
};
double simulation();
int findMin(LinkQueue<Client> *queue,int num);

int main()
{
    // LinkQueue<Client> queue[4];//四个柜台
    srand((int)time(0));
    cout<<"每个用户用时："<<simulation()<<endl;


   
    return 0;
}

double simulation(){
    int totalTime = 0;//为客户服务的总时长
    int customerNum= 0;//客户人数
    evNode evTemp;

    //定义队列数组queue，下标0至3分别代表4个排队窗口队列

    LinkQueue<Client> queue[4];

    //建立事件链表对象，设定第一个客户到达的事件

    EventList evList;

    //初始化事件列表，加入第一个结点，起始时间为0，第一个事件为-1（新客户到达事件）

    //设置evItem值为[0,-1,NULL];
    evNode evItem;
    evItem.occurTime=0;
    evItem.nType=-1;
    evItem.next=nullptr;

    evList.addNode(evItem);

//扫描并处理事件列表

while(!evList.isEmpty()){

//删除事件链表中第一个结点存入evItem

evList.deleteNode(&evItem);

if(evItem.nType == -1){
/* --是新客户到达事件--  */
// 客户人数加1
    customerNum++;
// 输入随机数durTime 和interTime，（durTime代表当前客户服务时间,
    int interTime=rand()%10;
    int durTime =rand()%20;
// interTimed代表下一个客户到来的间隔时间）

    if (evItem.occurTime+interTime < CLOSE_TIME) {//在银行关门之前

    //设定下一位客户到达的事件插入事件表

    evTemp.occurTime = evItem.occurTime + interTime;
    evTemp.nType = -1;
    evTemp.next = NULL;
    evList.addNode(evTemp);
}
    //为当前客户找到排队人数最少的队列下标

    int min = findMin(queue,4);

    //当前客户进入人数最少的队列
    Client cli;
    cli.arrivalTime=evItem.occurTime;
    cli.duration = durTime;
    queue[min].enQueue(cli);//入队
    //如果当前客户到达的窗口没有人在排队(他是第一个客户)
    if(queue[min].queueLength()==1) {
    //设定第一个客户离开银行的事件，插入事件表
    evTemp.occurTime = evItem.occurTime + durTime;
    evTemp.nType = min;
    evList.addNode(evTemp);
}

}
else{
    /* --是客户离开事件-- */
    //获得客户所在的窗口号(队列号)
    int win= evItem.nType;
    client cli;
    //将当前要离开的客户从队列中删除，并将当前客户信息存入client
    queue[win].deQueue(cli);//出队
    //计算客户在银行逗留时间，把当前客户的服务时间累加到totalTime中
    totalTime = totalTime + cli.duration;
    //如果还有人在排队，则把队头客户的离开事件插入事件表
    if (queue[win].queueLength()!=0){
    //获取队头结点数据
    queue[win].getFront(cli);
    //把队头结点的离开事件插入到事件表中
    evTemp.occurTime = evItem.occurTime+cli.duration;
    evTemp.nType = win;
    evList.addNode(evTemp);
}
}
}

//计算客户平均处理时间

return totalTime*1.0/customerNum; //返回客户平均处理时间

}


int findMin(LinkQueue<Client> *queue,int num){
    int min=queue[0].queueLength();
    for(int i=1;i<num;i++){
        
        if(min<queue[i].queueLength())
            min = min;
        else 
            min = queue[i].queueLength();
        
    }
    return min;

}