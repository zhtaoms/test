#pragma once
#include<iostream>
using namespace std;

typedef struct evnode{
    int occurTime;//事件发生时间
    int nType;//事件类型，-1表示到达事件，0-3表示四个窗口的离开事件
    struct evnode *next; //指针域
}evNode;

class EventList{
private:
    evNode *head;
public:
    EventList();
    ~EventList();
    bool isEmpty();
    void addNode(evNode ev);
    bool deleteNode(evNode *firstEv);
    void displayNode();
};

EventList::EventList(){
    head =new evNode;
    head->next=nullptr;
    head->nType=-1;
    head->occurTime=0;
}
EventList::~EventList(){

}

bool EventList::isEmpty(){
    if(head->next=nullptr)
        return true;
    else
        return false;
}
void EventList::addNode(evNode ev){
    evNode *p=new evNode;
    evNode *pn=head->next;
    evNode *last;
    p->nType=ev.nType;
    p->occurTime=ev.occurTime;

    if(isEmpty()){
        head->next=p;
        ev.next=nullptr;
    }
    while(pn->occurTime<p->occurTime){   
        last=pn;
        pn=pn->next;
    }
    last->next=p;
    p->next=pn;
    
}

bool EventList::deleteNode(evNode *firstEv){
    evNode *p=head->next;
    if(p!=nullptr){
        firstEv=head;
    delete head;
    head=p;
    return true;
    }else{
        return false;
    }
    
}

void EventList::displayNode(){
    evNode *p =head->next;
    cout<<"显示事件表：[";
    while(p!=nullptr){
        if(p->next!=nullptr){
            cout<<p->occurTime<<","<<p->nType<<"-"<<"]->";
            p=p->next;
        }else{
            cout<<p->occurTime<<","<<p->nType<<"^"<<"]";
        }
    }
}