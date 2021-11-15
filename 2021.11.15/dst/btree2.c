/*
 * ��������btree2.c���˳�����ʾ��������ǰ���������������ͺ�������������ݹ�ͷǵݹ����ַ�����
 * ���ߣ�C���Լ�����(www.freecplus.net) ���ڣ�20200202
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

///////////////////////////////////////////////
// �����������ݽṹ��
typedef struct BiTNode
{
  char   data;               // ��Ž�������Ԫ�ء�
  struct BiTNode *lchild;    // ָ�����ӽ���ַ��ָ�롣
  struct BiTNode *rchild;    // ָ�����ӽ���ַ��ָ�롣
}BiTNode,*BiTree;
///////////////////////////////////////////////


////////////////////////////////////////////////////////////////
// ջ�����ݽṹ��
#define MAXSIZE 30       // ˳��ջ����󳤶ȡ�

typedef BiTree ElemType;     // �Զ���ջ������Ԫ��Ϊ��������

typedef struct
{
  ElemType data[MAXSIZE];   // ������洢˳��ջ�е�Ԫ�ء�
  int top;                  // ջ��ָ�룬��0��MAXSIZE-1��-1��ʾ��ջ��
                            // Ҳ���Դ�1��MAXSIZE��0��ʾ��ջ��
}SeqStack,*PSeqStack;
////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////
// ˳��ջSS�ĳ�ʼ��������
void InitStack(PSeqStack SS);                     

// Ԫ����ջ������ֵ��0-ʧ�ܣ�1-�ɹ���
int Push(PSeqStack SS, ElemType *ee);

// Ԫ�س�ջ������ֵ��0-ʧ�ܣ�1-�ɹ���
int Pop(PSeqStack SS, ElemType *ee);

// ��˳��ջ�ĳ��ȣ�����ֵ��ջSS��Ԫ�صĸ�����
int Length(PSeqStack SS);                   

// ���˳��ջ��
void Clear(PSeqStack SS);                    

// �ж�˳��ջ�Ƿ�Ϊ�գ�����ֵ��1-�գ�0-�ǿջ�ʧ�ܡ�
int IsEmpty(PSeqStack SS);                    

// �ж�˳��ջ�Ƿ�����������ֵ��1-������0-δ����ʧ�ܡ�
int IsFull(PSeqStack SS);

// ��ӡ˳��ջ��ȫ����Ԫ�ء�
void PrintStack(PSeqStack SS);                    

// ��ȡջ��Ԫ�أ�����ֵ��0-ʧ�ܣ�1-�ɹ���
// ֻ�鿴ջ��Ԫ�ص�ֵ��Ԫ�ز���ջ��
int GetTop(PSeqStack SS, ElemType *ee);
////////////////////////////////////////////////////////////////

// ��������ĸ߶ȡ�
int TreeDepth(BiTree TT);

// ���ʽ��Ԫ�ء�
void visit(BiTNode *pp);

// ���õݹ�ķ����Զ����������������
void PreOrder(BiTree TT);
// �����õݹ�ķ����Զ����������������
void PreOrder1(BiTree TT);

// ���õݹ�ķ����Զ����������������
void InOrder(BiTree TT);
// �����õݹ�ķ����Զ����������������
void InOrder1(BiTree TT);

// ���õݹ�ķ����Զ������ĺ��������
void PostOrder(BiTree TT);
// �����õݹ�ķ����Զ������ĺ��������
void PostOrder1(BiTree TT);

int main()
{
  BiTree TT=0; // ������ָ�������

  /*
  // �ֹ�����һ�����½ṹ�Ķ�������
             1
          /     \
         2       3
        / \     /
       4   5   6
      / \ / \
     7  8 9  0
  */

  // ������ڵ㡣
  TT=(BiTNode *)malloc(sizeof(BiTNode));
  TT->data='1';
  TT->lchild=TT->rchild=0;

  // �ڶ����һ���ڵ㡣
  TT->lchild=(BiTNode *)malloc(sizeof(BiTNode));
  TT->lchild->data='2'; TT->lchild->lchild=TT->lchild->rchild=0;

  // �ڶ���ڶ����ڵ㡣
  TT->rchild=(BiTNode *)malloc(sizeof(BiTNode));
  TT->rchild->data='3'; TT->rchild->lchild=TT->rchild->rchild=0;

  // �������һ���ڵ㡣
  TT->lchild->lchild=(BiTNode *)malloc(sizeof(BiTNode));
  TT->lchild->lchild->data='4'; TT->lchild->lchild->lchild=TT->lchild->lchild->rchild=0;

  // ������ڶ����ڵ㡣
  TT->lchild->rchild=(BiTNode *)malloc(sizeof(BiTNode));
  TT->lchild->rchild->data='5'; TT->lchild->rchild->lchild=TT->lchild->rchild->rchild=0;

  // ������������ڵ㡣
  TT->rchild->lchild=(BiTNode *)malloc(sizeof(BiTNode));
  TT->rchild->lchild->data='6'; TT->rchild->lchild->lchild=TT->rchild->lchild->rchild=0;

  // ���Ĳ��һ���ڵ㡣
  TT->lchild->lchild->lchild=(BiTNode *)malloc(sizeof(BiTNode));
  TT->lchild->lchild->lchild->data='7'; TT->lchild->lchild->lchild->lchild=TT->lchild->lchild->lchild->rchild=0;

  // ���Ĳ�ڶ����ڵ㡣
  TT->lchild->lchild->rchild=(BiTNode *)malloc(sizeof(BiTNode));
  TT->lchild->lchild->rchild->data='8'; TT->lchild->lchild->rchild->lchild=TT->lchild->lchild->rchild->rchild=0;

  // ���Ĳ�������ڵ㡣
  TT->lchild->rchild->lchild=(BiTNode *)malloc(sizeof(BiTNode));
  TT->lchild->rchild->lchild->data='9'; TT->lchild->rchild->lchild->lchild=TT->lchild->rchild->lchild->rchild=0;

  // ���Ĳ���ĸ��ڵ㡣
  TT->lchild->rchild->rchild=(BiTNode *)malloc(sizeof(BiTNode));
  TT->lchild->rchild->rchild->data='0'; TT->lchild->rchild->rchild->lchild=TT->lchild->rchild->rchild->rchild=0;

  // �����������������
  printf("����������1��"); PreOrder(TT); printf("\n");
  printf("����������2��"); PreOrder1(TT); printf("\n");

  // �����������������
  printf("����������1��"); InOrder(TT); printf("\n");
  printf("����������2��"); InOrder1(TT); printf("\n");

  // �������ĺ��������
  printf("����������1��"); PostOrder(TT); printf("\n");
  printf("����������2��"); PostOrder1(TT); printf("\n");


  // ��������ĸ߶ȡ�
  printf("���ĸ߶��ǣ�%d\n",TreeDepth(TT));

  return 0;
}

// ��ʼ��˳��ջ
void InitStack(PSeqStack SS)
{
  Clear(SS); // ���˳��ջ��
}

// ���˳��ջ��
void Clear(PSeqStack SS)
{
  if (SS == NULL) return; // ����ָ�롣

  SS->top=-1;  // ջ��ָ����Ϊ-1��
  memset(SS->data,0,sizeof(ElemType)*MAXSIZE);  // ����Ԫ�����㡣
}

// ��˳��ջ�ĳ��ȣ�����ֵ��ջSS��Ԫ�صĸ�����
int Length(PSeqStack SS)
{
  if (SS == NULL) return 0; // ����ָ�롣

  return SS->top+1;
}


// �ж�˳��ջ�Ƿ�Ϊ�գ�����ֵ��1-�գ�0-�ǿջ�ʧ�ܡ�
int IsEmpty(PSeqStack SS)
{
  if (SS == NULL) return 0;  // ����ָ�롣

  if (SS->top == -1) return 1;

  return 0;
}

// �ж�˳��ջ�Ƿ�����������ֵ��1-������0-δ����ʧ�ܡ�
int IsFull(PSeqStack SS)
{
  if (SS == NULL) return 0;  // ����ָ�롣

  if (SS->top >= MAXSIZE-1) return 1;

  return 0;
}

// Ԫ����ջ������ֵ��0-ʧ�ܣ�1-�ɹ���
int Push(PSeqStack SS, ElemType *ee)
{
  if ( (SS == NULL) || (ee == NULL) ) return 0;  // ����ָ�롣

  if (IsFull(SS) == 1)
  {
    printf("˳��ջ���������ܲ��롣\n"); return 0;
  }

  SS->top++;  // ջָ���ȼ�1��

  memcpy(&SS->data[SS->top],ee,sizeof(ElemType));  // ��������±���ʡ�
  // memcpy(SS->data+SS->top,ee,sizeof(ElemType));    // ����ָ������Ҳ���ԡ�

  return 1;
}

// ��ӡ˳��ջ��ȫ����Ԫ�ء�
void PrintStack(PSeqStack SS)
{
  if (SS == NULL) return;  // ����ָ�롣

  if (SS->top == -1) { printf("ջΪ�ա�\n"); return; }

  int kk;
  for (kk = 0; kk <= SS->top; kk++)
  {
    printf("SS[%d],value=%d\n",kk,SS->data[kk]);     // ��������±���ʡ�
    // printf("SS[%d],value=%d\n",kk,*(SS->data+kk));   // ����ָ������Ҳ���ԡ�
  }
}

// Ԫ�س�ջ������ֵ��0-ʧ�ܣ�1-�ɹ���
int Pop(PSeqStack SS, ElemType *ee)
{
  if ( (SS == NULL) || (ee == NULL) ) return 0;  // ����ָ�롣

  if (SS->top == -1) { printf("ջΪ�ա�\n"); return 0; }

  memcpy(ee,&SS->data[SS->top],sizeof(ElemType));  // ��������±���ʡ�
  // memcpy(ee,SS->data+SS->top,sizeof(ElemType));    // ����ָ������Ҳ���ԡ�

  SS->top--;  // ջָ���1��

  return 1;
}

// ��ȡջ��Ԫ�أ�����ֵ��0-ʧ�ܣ�1-�ɹ���
// ֻ�鿴ջ��Ԫ�ص�ֵ��Ԫ�ز���ջ��
int GetTop(PSeqStack SS, ElemType *ee)
{
  if ( (SS == NULL) || (ee == NULL) ) return 0;  // ����ָ�롣

  if (IsEmpty(SS) == 1) { printf("ջΪ�ա�\n"); return 0; }

  memcpy(ee,&SS->data[SS->top],sizeof(ElemType));  // ��������±���ʡ�
  // memcpy(ee,SS->data+SS->top,sizeof(ElemType));    // ����ָ������Ҳ���ԡ�

  return 1;
}

// ���ʽ��Ԫ�ء�
void visit(BiTNode *pp)
{
  printf("%c ",pp->data);  // ���ʽ��Ԫ�ؾ��ǰ�ֵ���������˼һ�¾����ˡ�
}

// �����������������
void PreOrder(BiTree TT)
{
  if (TT == NULL) return;

  visit(TT);               // ��������TT�ĸ���㡣
  PreOrder(TT->lchild);    // ������������
  PreOrder(TT->rchild);    // ������������
}

// �����������������
void InOrder(BiTree TT)
{
  if (TT == NULL) return;

  InOrder(TT->lchild);     // ������������
  visit(TT);               // ��������TT�ĸ���㡣
  InOrder(TT->rchild);     // ������������
}

// �������ĺ��������
void PostOrder(BiTree TT)
{
  if (TT == NULL) return;

  PostOrder(TT->lchild);     // ������������
  PostOrder(TT->rchild);     // ������������
  visit(TT);                 // ��������TT�ĸ���㡣
}

// �����õݹ�ķ����Զ����������������
void PreOrder1(BiTree TT)
{
  SeqStack SS;     // ����˳��ջ��

  InitStack(&SS);  // ��ʼ��˳��ջ��

  ElemType ee=TT;  // ���е�Ԫ���Ƕ�������

  while ( (ee!=NULL) || (IsEmpty(&SS)!=1) )
  {
    if (ee!=NULL)
    {
      visit(ee);               // ��ջǰ���ʡ�
      Push(&SS,&ee);           // ��ջ��
      ee=ee->lchild;           // ����������������
    }
    else
    {
      Pop(&SS,&ee);            // ��ջ��
      ee=ee->rchild;           // ������������ 
    }
  }
}

// �����õݹ�ķ����Զ����������������
void InOrder1(BiTree TT)
{
  SeqStack SS;     // ����˳��ջ��

  InitStack(&SS);  // ��ʼ��˳��ջ��

  ElemType ee=TT;  // ���е�Ԫ���Ƕ�������

  while ( (ee!=NULL) || (IsEmpty(&SS)!=1) )
  {
    if (ee!=NULL)
    {
      Push(&SS,&ee);        // ��ջ��
      ee=ee->lchild;        // ����������������
    }
    else
    {
      Pop(&SS,&ee);        // ��ջ��
      visit(ee);           // ���ʳ�ջԪ�ء�
      ee=ee->rchild;       // ������������
    }
  }
}

// �����õݹ�ķ����Զ������ĺ��������
void PostOrder1(BiTree TT)
{
  SeqStack SS;      // ����˳��ջ��

  InitStack(&SS);   // ��ʼ��˳��ջ��

  ElemType ee=TT;   // ���е�Ԫ���Ƕ�������
  
  ElemType pp=NULL; // ������ʹ��Ľ�㡣

  while ( (ee!=NULL) || (IsEmpty(&SS)!=1) )
  {
    if (ee!=NULL)    // �Ӹ���㿪ʼ�����������㣬������ջ��ֱ������Ϊ�ա�
    {
      Push(&SS,&ee);
      ee=ee->lchild;
    }
    else   // ת���ҡ�
    {
      // ��ȡջ��Ԫ�أ�����ջ��
      GetTop(&SS,&ee);       

      // ������������ڲ���û�б����ʹ���
      if ( (ee->rchild!=NULL) && (ee->rchild!=pp) )
      {
        ee=ee->rchild;  // ת���ҡ�
        Push(&SS,&ee);  // �������ĸ������ջ��
        ee=ee->lchild;  // ��ת�������������㡣
      }
      else  
      {
        Pop(&SS,&ee);  // ����㵯����
        visit(ee);     // ���ʽ�㡣
        pp=ee;         // ����������ʹ��Ľ�㡣
        ee=NULL;       // �������������eeΪ�գ�������ȡջ��Ԫ�ء�
      }
    }
  }
}

// ��������ĸ߶ȡ�
int TreeDepth(BiTree TT)
{
  if (TT==NULL) return 0;

  int ll=TreeDepth(TT->lchild);  // ���������ĸ߶ȡ�

  int rr=TreeDepth(TT->rchild);  // ���������ĸ߶ȡ�

  return ll>rr ? ll+1: rr+1;  // ȡ���������Ľϴ����ټ��ϸ����ĸ߶ȡ�
}
