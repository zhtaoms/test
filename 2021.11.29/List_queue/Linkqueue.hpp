#pragma once

# include <iostream>
using namespace std;


template <class TypeDate>
class LinkQueue
{
    private:
        typedef struct Node{
            TypeDate date;      //数据域
            struct Node *next; //指针域
        }node,*Link;            //链表结构体
        Link Front,Rear; //头指针 和 尾部指针
        int length;     //队列元素个数
    public:
        LinkQueue();               //构造函数
        virtual ~LinkQueue();     //析构函数
        void enQueue(TypeDate x); //入队
        bool deQueue(TypeDate &item); //出队
        bool getFront(TypeDate &item); //获得队头元素
        bool isEmpty();           //判断是否为空
        void clearQueue();        //清空队列
        bool displayQueue();      //显示队列内容
        int  queueLength();       //获得队列元素个数

};

template <class TypeDate>
LinkQueue<TypeDate>::LinkQueue()
{
    Front = new  node;  //分配内存 创建节点
    Front->next = nullptr;
    Rear = Front; //尾部指针  = 头部指针
    length = 0;   //长度 初始化为 0   有头节点的 链队
}

template <class TypeDate>
LinkQueue<TypeDate>::~LinkQueue()
{
    
    //clearQueue(); //删除数据节点
    //delete Front;//删除头节点
    //Front=Rear=NULL;
    //delete Rear; //删除尾节点

}

template <class TypeDate>
void LinkQueue<TypeDate>::enQueue(TypeDate x)
{
    Link p;//新建node指针
    p = new node;//分配内存 创建节点
    p->date = x;  //数据装载
    p->next = nullptr; //空指针
    Rear->next = p;//当前末尾元素 next 指向 新加入的节点P
    Rear = p;      //Rear  指向 末尾节点
    length++;      //长度+1

}

template <class TypeDate>
bool LinkQueue<TypeDate>::deQueue(TypeDate &item)
{
    Link p;
    p = Front->next;  //指向头节点后一个

    if(isEmpty())   //判断是否为空队列
        return false;
    else
    {
        item = p->date;   //采用 引用的方式输出
        Front->next = p->next; // Front next域  指 p  的 next域的内容
        if(p->next == nullptr)// 节点关系Front  p(Front->next)  p->next
            Rear = Front; // Rear 指向 Front  当只有一个节点数据域
        delete p;  //删除p 节点
        length--;   //长度减少
        return true;
    }

}

template <class TypeDate>
bool LinkQueue<TypeDate>::getFront(TypeDate &item)
{
    Link p;
    p = Front->next;  //指向头节点后一个

    if(isEmpty())   //判断是否为空队列
        return false;
    else
    {
        item = p->date;   //指针方式输出  也可以采用 引用的方式输出  &item  item = p->date;
    }

}

template <class TypeDate>
bool LinkQueue<TypeDate>::isEmpty()
{
    return  (Front == Rear)&&(length ==0);

}

template <class TypeDate>
void LinkQueue<TypeDate>::clearQueue()
{
    Link p;
    p = Front->next;
    while( p != NULL) //判断 Front->next 是否为空指针
    {
        
        Front->next= p->next;// Front next域  指 p  的 next域的内容
        delete p; //删除节点
        length--; //长度减1
        p= Front->next;
    }
    Rear = Front;  //结尾指针指向头部


}
template <class TypeDate>
bool LinkQueue<TypeDate>::displayQueue()
{
    Link p;
    p = Front->next;
    if(p == nullptr)
        return false;

    while( p != nullptr)
    {
        printf("%lf\n",p->date);// 测用的情况<double> date的情况  实际使用需要修改
        p = p->next;

    }
    return true;
}
template <class TypeDate>
int LinkQueue<TypeDate>::queueLength()
{
    return length;  //返回长度
}


