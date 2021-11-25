# ifndef STACK_H
# define STACK_H
//方向
typedef struct 
{
    int incX,incY;
}Direction;

struct Box	//将每个迷宫格子看成是一个结构体
{
    int x, y, di;
    //x和y分别代表迷宫格子的横纵坐标，di为当前的方向
};

typedef struct Node		//这是栈节点
{
    Box data;
    struct Node* pNext;
}Node, *PNODE;

class Stack
{
    private:
    PNODE pTop;
    PNODE pBottom;

    public:
        Stack();
        void initStack(Stack*);
        void pushStack(Stack*, Box); 
        
        //将栈中的栈底元素返回并移除，用递归来实现栈逆序遍历的
        Box getElement(Stack&, Box&);
        void reverse(Stack&, Box&); 
        
        void traverse(Stack*);
        void pop(Stack*, Box&);
        bool isEmpty(Stack*);
};


# endif