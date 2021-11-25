#include "stack.h"
#include <iostream>
#include <stdlib.h>		//exit函数要用到
using namespace std;

Stack::Stack()
{
    //ctor
}

void Stack::initStack(Stack* pS)
{
    pS->pTop = new Node;
    if(nullptr == pS->pTop){
        cout << "动态内存分配失败！" << endl;
        exit(-1);
    }
    else{
        pS->pBottom = pS->pTop;
        pS->pTop->pNext = nullptr;
    }
    return;
}

void Stack::pushStack(Stack* pS, Box temp) //temp是将一个结构体整体入栈
{
    PNODE pNew = new Node;
    pNew->data = temp;
    pNew->pNext = pS->pTop;
    pS->pTop = pNew;
}
/** 这里开始是逆序遍历栈的关键代码，等会详细讲解 */
Box Stack::getElement(Stack& s, Box& temp)
{
    s.pop(&s, temp);
    Box res = temp;
    if(s.isEmpty(&s)) return res;
    else{
        Box last = getElement(s, temp);
        s.pushStack(&s, res);
        return last;
    }
}

void Stack::reverse(Stack& s, Box& temp)
{
    if(s.isEmpty(&s)) return;
    Box i  = getElement(s, temp);
    s.reverse(s, temp);
    s.pushStack(&s, i);
}
/****************************************/
void Stack::traverse(Stack* pS)
{
    PNODE p = pS->pTop;		//p是移动指针，在栈顶和栈底间上下移动的
    while(p != pS->pBottom)
    {
        cout << "(" << p->data.x << ", " << p->data.y << ")" << endl;
        p = p->pNext;
    }
    cout << endl;
    return;
}

void Stack::pop(Stack* pS, Box& temp)	//这里的temp一定要 采用引用
{
    if(isEmpty(pS)) return;
    else{
        PNODE r = pS->pTop;
        temp = r->data;
        pS->pTop = r->pNext;
        free(r);
        r = NULL;
        return;
    }
}

bool Stack::isEmpty(Stack* pS)
{
    if(pS->pTop == pS->pBottom)
        return true;
    else
        return false;
}
