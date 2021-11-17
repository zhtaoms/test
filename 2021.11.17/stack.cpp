#include"stack.h"

Stack::Stack()
{
    this->size=MAX_SIZE;
    this->top=-1;
    this->data=new char[size];
}
Stack::Stack(int set)
{
    if(set>=MAX_SIZE)
    {
        this->data=new char[set];
        this->size=set;
        this->top=-1;
    }else{
        this->size=set;
        this->top=-1;
        this->data=new char[size];
    }
    
}
Stack::~Stack()
{
    delete[] data;
}
void  Stack::push(char ch)//压栈
{
    if(!isFull()){
        top++;
        this->data[top]=ch;
    }else{
        cout<<"已经满了，无法继续压栈"<<endl;
    }
}
char  Stack::pop()//出栈并返回出栈元素
{
    char temp;
    if(!isEmpty()){
        temp=this->data[top];  
        top--;
        return temp;
    }else{
        cout<<"栈内无数据！"<<endl;
        return 0;
    }
}
char  Stack::getTop()//获取栈顶元素
{
    if(!isEmpty()){
        char t=this->data[top];
        
        return t;
    }else{
        cout<<"栈内无数据！"<<endl;
        return 0;
    }
}
bool  Stack::isEmpty()//判断栈是否为空
{
    if (top ==-1)
            return true;
        else
            return false;
}
bool  Stack::isFull()//判断栈是否为满
{
    if (top >= this->size-1)
        return true;
    else
        return false;
}
void  Stack::setNull()//将栈设置为空
{
    this->top=-1;
}