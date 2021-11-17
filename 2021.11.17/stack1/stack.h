# ifndef STACK_H
# define STACK_H

const int MAX_SIZE = 100;

class Stack
{
    private:
    char * data;//指向数组的指针
    int size;//数组的大小
    int top;//栈顶
    
    public:
    Stack();
    Stack(int set);
    ~Stack();
    
    void push(char );//压栈
    char pop();//出栈并返回出栈元素
    char getTop();//获取栈顶元素
    bool isEmpty();//判断栈是否为空
    bool isFull();//判断栈是否为满
    void setNull();//将栈设置为空
    //定义错误内部类
    class Full{};
    class Empty{};
};

# endif