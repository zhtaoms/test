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

#define NO_LENGTH  20
#define NAME_LENGTH 11

/* 定义学生结构体的数据结构 */
typedef struct Student{
	char studentNo[NO_LENGTH];
	char studentName[NAME_LENGTH];
}st;

/* 定义每条记录或节点的数据结构 */
typedef struct node
{
	struct Student data; //数据域
	struct node *next; //指针域
}Node,*Link;  //Node为node类型的别名,Link为node类型的指针别名

//定义提示菜单
void myMenu(){
	printf(" * * * * * * * * * 菜     单 * * * * * * * * * *\n");
	printf("     1 增加学生记录            2 删除学生记录                     \n");
	printf("     3 查找学生记录            4 修改学生记录                     \n");
	printf("     5 统计学生人数            6 显示学生记录                     \n");
	printf("     7 退出系统                                     \n");
	printf(" * * * * * * * * * * * * * * * * * * * * * * * *\n");
}

void inputStudent(Link l){
	 printf("请输入学生学号:");
	 scanf("%s",l->data.studentNo);
	 printf("请输入学生的姓名:");
	 scanf("%s",l->data.studentName);

	 //每个新创建的节点的next域都初始化为NULL
	 l->next = NULL;
}

void inputStudentNo(char s[],char no[]){
	printf("请输入要%s的学生学号:",s);
	scanf("%s",no);
}
void isexist(Link head)
{
	 if(head==NULL||head->next==NULL)
   {
       printf("There is no student!\n");
       printf("请添加学生!\n");
	   return ;
   }
}
void displayNode(Link head){
   // 填写代码，根据传入的链表head头指针，扫描链表显示所有节点的信息
   if(head==NULL||head->next==NULL)
   {
       printf("There is no student!\n");
       printf("请添加学生!\n");
   }
   Link p=head->next;
   while(p!=NULL)
   {
       printf("学号：%s  姓名：%s\n",p->data.studentNo,p->data.studentName);
       p=p->next;
   }
   
}

/* 增加学生记录 */
bool addNode(Link head){
	 Link p,q;   //p,q两个节点一前一后
	 Link node;  //node指针指向新创建的节点
	 node=(Link)malloc(sizeof(Node));
	 inputStudent(node);

	 q = head;
	 p = head->next;  //q指向head后面的第一个有效节点
	 if(head->next==NULL)
		 //链表为空时
		head->next = node;
	 else {
		 //循环访问链表中的所有节点
		while(p != NULL){
			if (node->data.studentNo < p->data.studentNo){
				//如果node节点的学号比p节点的学号小，则插在p的前面，完成插入后，提前退出子程序
				q->next = node;
				node->next = p;
				return true;
			}
			else{
				//如果node节点的学号比p节点的学号大，继续向后移动指针（依然保持pq一前一后）
				q = p;
				p = p->next;

			}
		}
		//如果没能提前退出循环，则说明之前没有插入，那么当前node节点的学号是最大值，此时插在链表的最后面
		q->next = node;

	}
	 return true;
}

bool deleteNode(Link head){
    // 按照给定的学号删除学生记录，如果删除成功返回true，如果没找到学号返回false

    //输入要处理的学号
    char no[NO_LENGTH];
	inputStudentNo("删除",no);
	Link q ,p;
	q=head;
	p=head->next;
	while(p!=NULL)
	{
		if(strcmp(p->data.studentNo,no)==0)//这里定义了char类型的数组 建议改称int 类型比较方便
		{
			q->next=p->next;
			free(p);
			return true;
		}else{
			q=p;
			p=p->next;
		}
		
	}
	return false;
}

bool queryNode(Link head){
    // 按照给定的学号查询学生记录，如果删除成功返回true，如果没找到学号返回false

    //输入要处理的学号
	char no[NO_LENGTH];
	inputStudentNo("查询",no);
	
	Link q ,p;
	q=head;
	p=head->next;
	isexist(head);
	while(p!=NULL)
	{
		if(strcmp(p->data.studentNo,no)==0)//这里定义了char类型的数组 建议改称int 类型比较方便
		{
			printf("找到了！\n");
			return true;
		}else{
			q=p;
			p=p->next;
		}
		
	}
	return false;
}

bool modifyNode(Link head){
    // 按照给定的学号找到学生记录节点，如果修改成功返回true，如果没找到学号返回false

    //输入要处理的学号
	char no[NO_LENGTH];
	inputStudentNo("修改",no);

	char newno[NO_LENGTH];
	char newname[NAME_LENGTH];

	Link q ,p;
	q=head;
	p=head->next;
	isexist(head);
	

	while(p!=NULL)
	{
		if(strcmp(p->data.studentNo,no)==0)//这里定义了char类型的数组 建议改称int 类型比较方便
		{
			printf("找到了！\n");
			printf("请输入新的学号：\n");
			scanf("%s",newno);
			printf("请输入新的姓名：\n");
			scanf("%s",newname);
			memset(p->data.studentNo,0,sizeof(p->data.studentNo));
			memset(p->data.studentName,0,sizeof(p->data.studentName));
			strcpy(p->data.studentNo,newno);
			strcpy(p->data.studentName,newname);
			printf("i修改成功！\n");
			return true;
		}else{
			q=p;
			p=p->next;
		}
		
	}
	return false;
}

int countNode(Link head){
	//统计学生人数，扫描链表统计节点个数，返回节点数
	Link p;
	int count = 0;
	p = head->next;
	while (p!=NULL)
	{/* code */
		count++;
		p=p->next;
		
	}
	if(count>0)
		return count;
	else
	//填充代码
		return false;
}

void clearLink(Link head){
	Link q,p;
        //遍历链表，用free语句删除链表中用malloc建立起的所有的节点
	q=head;
	p=head->next;
	if(p==NULL)
	{
		free(q);
		q->next=NULL;
		printf("OK\n");
		return ;
	}

	while (p!=NULL)
	{
		q=p->next;
		
		free(p);
		p=q;
		
	}
	p->next=NULL;
	
}

int main() {
	int select;
    	int count;
	Link head;  // 定义链表

	//建立head头结点，在这个程序中head指向头结点，头结点data部分没有内容，其后续节点才有真正的数据
	head = (Link)malloc(sizeof(Node));
	head->next = NULL;

	while(1)
	{
		myMenu();
		printf("\n请输入你的选择(0-7):");  //显示提示信息
		scanf("%d",&select);
		switch(select)
		{
		case 1:
			//增加学生记录
			if(addNode(head))
				printf("成功插入一个学生记录。\n\n");
			break;
		case 2:
			//删除学生记录
			if(deleteNode(head))
				printf("成功删除一个学生记录。\n\n");
			else
				printf("没有找到要删除的学生节点。\n\n");
			break;
		case 3:
			//查询学生记录
			if(queryNode(head))
				printf("成功找到学生记录。\n\n");
			else
				printf("没有找到要查询的学生节点。\n\n");
			break;
		case 4:
			//修改学生记录
			if(modifyNode(head))
				printf("成功修改一个学生记录。\n\n");
			else
				printf("没有找到要修改的学生节点。\n\n");
			break;
		case 5:
			//统计学生人数
			count = countNode(head);
			printf("学生人数为：%d\n\n",count);
			break;
		case 6:
			//显示学生记录
			displayNode(head);
			break;
		case 7:
			//退出前清除链表中的所有结点
            clearLink(head);
			return 0;
		default:
			printf("输入不正确，应该输入0-7之间的数。\n\n");
			break;
		}
	}
	return 0;
}