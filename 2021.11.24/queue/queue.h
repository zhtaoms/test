#pragma once

# include <iostream>
using namespace std;


const int QUEUESIZE =100;

class CirQueue{

private:
    int *data;//数据
    int front;
    int rear;
    int mSize;//数组大小
    int count;
public:
    CirQueue();//建立规定长度数组
    CirQueue(int size);
    ~CirQueue();
    bool enQueue(int item);//入队
    bool dnQueue(int *item);//出对
    bool getFront(int *item);
    bool isEmpty();
    bool isFull();
    void clearQueue();
    void displayQueue();
    int queueLength();
};


