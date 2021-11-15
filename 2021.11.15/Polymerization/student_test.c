//============================================================================
// Name        : LinkBlank.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>
#include<string.h>
#include<malloc.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct polynomial
{
    int coefficient;//系数
    int exp;//指数
    struct polynomial *next;
}*Link,Node;

void inputPoly(Link head);//用于从控制台读入链表的函数
void print(Link head);//打印链表用的函数
bool insert(Link head,int coefficient,int exp);//向链表插入一个元素的函数
void combin2List(Link heada,Link headb,Link headab);//合并两个链表

int main()
{
    Link headA,headB;//两个多项式的头指针
    Link headAB;//合并后的多项式的头指针

    /*链表的初始化*/
    headA=(Link)malloc(sizeof(Node));
    headA->next=NULL;
    headB=(Link)malloc(sizeof(Node));
    headB->next=NULL;
    headAB=(Link)malloc(sizeof(Node));
    headAB->next=NULL;

    printf("请输入第一个多项式的系数和指数，以(0 0)结束：\n");
    inputPoly(headA);
    printf("第一个");
    print(headA);
    printf("请输入第二个多项式的系数和指数，以(0 0)结束：\n");
    inputPoly(headB);
    printf("第二个");
    print(headB);

    combin2List(headA,headB,headAB);
    printf("合并后");
    print(headAB);
    free(headA);
    free(headB);
    return 0;
}

/**输入二项式数据的函数*/
/*这个函数用来输入二项式，给用户合适的提示，读入用户输入的系数和指数。
调用函数insert，将用户输入的二项式的一项插入到链表中去。*/
void inputPoly(Link head)
{
    int coefficient,exp;//系数和指数
    printf("请输入系数和指数(如：\"2 3\"表示2x^3)：");
    scanf("%d %d",&coefficient,&exp);
    while(coefficient!=0||exp!=0)//连续输入多个系数和指数
    {
        insert(head,coefficient,exp);//调函数输入多项式
        printf("请输入系数和指数：");
        scanf("%d %d",&coefficient,&exp);
    }
}

/**向多项式链表中插入元素的函数
int coefficient 一个多项式项的系数
int exp 一个多项式项的幂
*/
bool insert(Link head,int coefficient,int exp)
{
    Link node;  //node指针指向新创建的节点
    Link q,p;   //q,p两个节点一前一后
	q=head;
	p=head->next;

    //创建一个新结点
	node=(Link)malloc(sizeof(Node));
    node->next=NULL;
	node->coefficient=coefficient;
	node->exp=exp;

    if(head->next==NULL)//空表,插第1个
    {
          head->next=node;
    }
    else
    {
        while(p != NULL){ //循环访问链表中的所有节点

            //如果node节点的指数比p节点的指数大，则插在p的前面，完成插入后，提前退出
			//如果node节点的指数和p节点的指数相等，则合并这个多项式节点，提前退出
            //如果node节点的指数比p节点的指数小，继续向后移动指针（依然保持p，q一前一后）
			if(node->exp>p->exp){
				q->next=node;
				node->next=p;
				return true;
			}else if(node->exp==p->exp){
				p->coefficient=p->coefficient+node->coefficient;
				return true;
			}else{
				q=p;
				p=p->next;
			}
            

	}
	//如果退出循环是当前指针p移动到链表结尾，则说明之前没有插入，那么当前node节点的指数值是最大值，此时插在链表的最后面
	q->next=node;
    }
    return true;
}

/**
打印多项式链表的函数
*/
/*
①　通过指针访问链表
②　多重条件语句嵌套
③　数字转换为字符串函数itoa
④　标志是否为第一个节点的flag的设置
⑤　字符串连接函数strcat
⑥　字符串清空函数memset。memset(item,0,20);清空长20的字符串item
请补充代码实现。
*/
void print(Link head)
{
    Link p; //指向链表要输出的结点
    printf("多项式如下：\n");
    p=head->next;

    if (p == NULL)
    {
        printf("多项式为空\n");
        return;
    }
    // 不是空表
    char item[20]="";//要打印的当前多项式的一项
    char number[7]="";//暂时存放系数转换成的字符串
    
    bool isFirstItem=true;//标志是否为第一个节点的flag
    //打印节点
    do {
            memset(item,0,20);//清空字符串item
            //如果是第一项，不要打+号
			//如果不是第一项，且系数为正数，要打加号
			if(isFirstItem==true){
				if(p->coefficient==1){
                    strcat(item,"X^");
                    sprintf(number,"%d",p->exp);
                    strcat(item,number);
                }else if((p->coefficient!=0)&&(p->coefficient!=-1)){
                    
                    sprintf(number,"%d",p->coefficient);
                    strcat(item,number);
                    sprintf(number,"%d",p->exp);
                    
                
                    strcat(item,"X^");
                    strcat(item,number);
                }else{
                    strcat(item,"-X^");
                    sprintf(number,"%d",p->exp);
                    strcat(item,number);
                }
			}else{
                if(p->exp!=0){
                    if(p->coefficient==1){
                    strcat(item,"+X^");
                    sprintf(number,"%d",p->exp);
                    strcat(item,number);
                }else if((p->coefficient!=0)&&(p->coefficient!=-1)){
                    sprintf(number,"%d",p->coefficient);
                    strcat(item,"+");
                    strcat(item,number);
                    sprintf(number,"%d",p->exp);
                    
                    strcat(item,"X^");
                    strcat(item,number);
                }else{
                    strcat(item,"-X^");
                    sprintf(number,"%d",p->exp);
                    strcat(item,number);
                }
                }else{
                    sprintf(number,"%d",p->coefficient);
                    strcat(item,"+");
                    strcat(item,number);
                }
                
			}
            

            //如果系数为负数，系数自身带有符号

            //如果系数为1，不用打系数
            //系数为-1打印负号

            //如果系数不为1或-1，打印系数


            //如果指数为0，直接打系数不用打x^和指数
            //如果系数是-1或1，需要打1出来，不能只打符号

            //指数不为0
            //打印x
            //如果指数为1，不打指数，否则打指数

            printf("%s",item);//打印当前节点代表的项
            p = p->next;//指向下个结点
            isFirstItem=false;//flag标志不是第一项了
        }while(p != NULL);
    printf("\n");
    return;
}

/**
合并两个有序链表a，b到链表ab
heada.headb,headab分别为链表a,b,ab的头指针
*/
void combin2List(Link heada,Link headb,Link headab)
{
    Link pa,pb,p,temp,temp2;//指向a，b链表和ab的指针
    pa=heada->next;
    pb=headb->next;
    p=headab;
    while(pa!=NULL&&pb!=NULL)//a,b链表都没有没有访问完毕
    {
        //如果指数a>指数b，a节点插入ab链表，a指针后移
        //如果指数a<指数b，b节点插入ab链表，b指针后移
        //如果指数a==指数b，a、b系数相加，插入ab链表，a、b指针后移
        if(pa->exp>pb->exp){
            p->next=pa;
            temp=pa->next;
            pa->next=NULL;
            
            pa=temp;
            p=p->next;
        }else if(pa->exp<pb->exp){
            p->next=pb;
            temp=pb->next;
            pb->next=NULL;
            
            pb=temp;
            p=p->next;
        }else{
            
            pa->coefficient=pa->coefficient+pb->coefficient;
            temp2=pb->next;
            free(pb);
            pb=temp2;
            p->next=pa;
            temp=pa->next;
            pa->next=NULL;
            pa=temp;
            p=p->next;
        }

    }
     //如果a、b链表还有尾巴，将它加到ab链表后面
    while(pa!=NULL)
    {
        p->next=pa;
    }
    while(pb!=NULL)
    {
        p->next=pb;
    }
    
    return;

}