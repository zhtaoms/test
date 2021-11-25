#include"queue.h"


CirQueue::CirQueue(){
    this->data=new int [QUEUESIZE];
    this->front=-1;
    this->rear=-1;
    this->count=0;
    mSize=QUEUESIZE;
}

CirQueue::CirQueue(int size){
    this->mSize=size;
    this->data=new int [mSize];
    this->front=-1;
    this->rear=-1;
    this->count-0;
}
CirQueue:: ~CirQueue(){
    delete this->data;
    this->data=NULL;
 }
bool CirQueue::isFull(){
    if(this->count==mSize)
        return 1;
    else
        return 0;
}
bool CirQueue::isEmpty(){
    if(this->count==0)
        return 1;
    else
        return 0;
}

bool CirQueue::enQueue(int item){
    if(isFull()){
        cout<<"Full"<<endl;
        return 0;
    }else{
        this->rear=(this->rear+1)%mSize;
        this->data[this->rear]=item;
        this->count++;
        return 1;
    }
}
bool CirQueue::dnQueue(int *item){
    if(isEmpty()){
        cout<<"Empty"<<endl;
        return 0;
    }else{
        this->front=(this->front+1)%mSize;
        (*item)=this->data[front];
        this->front=(this->front+1)%mSize;
        this->count--;
        return 1;
    }
}
bool CirQueue::getFront(int *item){
    if(isEmpty()){
        cout<<"Empty"<<endl;
        return 0;
    }else{
        this->front=(this->front+1)%mSize;
        (*item)=this->data[this->front];
        return 1;
       
    }
}   
void CirQueue::clearQueue(){
    this->front=-1;
    this->rear=-1;
    this->count=0;
}
void CirQueue::displayQueue(){
    int x=this->front+1;
    if(isEmpty()){
        cout<<"Empty"<<endl;
    }else{
        for(int i=0;i<this->count;i++){
        cout<<this->data[x]<<"<-";
        x=(x+1)%mSize;
    }
       
    }
    
}
int CirQueue::queueLength(){
    return count;
}