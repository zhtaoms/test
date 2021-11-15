/*
 * ��������btree1.c���˳�����ʾ�������Ĳ�α�����
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


///////////////////////////////////////////////
// ���е����ݽṹ��
#define MAXSIZE 30       // ѭ�����е���󳤶ȣ������Դ��MAXSIZE-1��Ԫ�ء�

typedef BiTree ElemType;     // �Զ�����е�����Ԫ��Ϊ��������

typedef struct
{
  ElemType data[MAXSIZE];   // ������洢ѭ�������е�Ԫ�ء�
  int front;                // ���е�ͷָ�롣
  int rear;                 // ���е�βָ�룬ָ���β����һ��Ԫ�ء�
}SeqQueue,*PSeqQueue;
///////////////////////////////////////////////

///////////////////////////////////////////////
// ���в����ĺ�����

// ѭ������QQ�ĳ�ʼ��������
void InitQueue(PSeqQueue QQ);

// Ԫ����ӣ�����ֵ��0-ʧ�ܣ�1-�ɹ���
int InQueue(PSeqQueue QQ, ElemType *ee);

// Ԫ�س��ӣ�����ֵ��0-ʧ�ܣ�1-�ɹ���
int OutQueue(PSeqQueue QQ, ElemType *ee);

// ��ѭ�����еĳ��ȣ�����ֵ��>=0-����QQԪ�صĸ�����
int  Length(PSeqQueue QQ);

// ���ѭ�����С�
void Clear(PSeqQueue QQ);

// �ж�ѭ�������Ƿ�Ϊ�գ�����ֵ��1-�գ�0-�ǿջ�ʧ�ܡ�
int  IsEmpty(PSeqQueue QQ);

// �ж�ѭ�������Ƿ�����������ֵ��1-������0-δ����ʧ�ܡ�
int IsFull(PSeqQueue QQ);
///////////////////////////////////////////////


// �������Ĳ�α�����
void LevelOrder(BiTree TT);

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

  // ��������α�����
  printf("��α��������"); LevelOrder(TT); printf("\n");

  return 0;
}

// ���ʳ���Ԫ�ء�
void visit(BiTNode *pp)
{
  printf("%c ",pp->data);  // ���ʳ���Ԫ�ؾ��ǰ�ֵ���������˼һ�¾����ˡ�
}

// ��������α�����
void LevelOrder(BiTree TT)
{
  SeqQueue QQ;     // ����ѭ�����С�

  InitQueue(&QQ);  // ��ʼ��ѭ�����С�

  ElemType ee=TT;  // ���е�Ԫ���Ƕ�������
  
  InQueue(&QQ,&ee);  // �Ѹ���㵱�ɶ��е�Ԫ����ӡ�
  
  while (IsEmpty(&QQ)!=1)  // ���в�Ϊ�ա�
  {
    OutQueue(&QQ,&ee);  // ��ͷԪ�س��ӡ�

    visit(ee);  // ���ʳ���Ԫ�ء�

    if (ee->lchild != NULL) InQueue(&QQ,&ee->lchild);  // �������Ԫ�������㣬������ӡ�

    if (ee->rchild != NULL) InQueue(&QQ,&ee->rchild);  // �������Ԫ�����ҽ�㣬�ҽ����ӡ�
  }
}

// ��ʼ��ѭ������
void InitQueue(PSeqQueue QQ)
{
  Clear(QQ); // ���ѭ�����С�
}

// ���ѭ�����С�
void Clear(PSeqQueue QQ)
{
  if (QQ == NULL) return;  // ����ָ�롣

  QQ->front=QQ->rear=0;
  memset(QQ->data,0,sizeof(ElemType)*MAXSIZE);  // ����Ԫ�����㡣
}

// ��ѭ�����еĳ��ȣ�����ֵ��>=0-����QQԪ�صĸ�����
int Length(PSeqQueue QQ)
{
  if (QQ == NULL) return 0;  // ����ָ�롣

  return (QQ->rear-QQ->front+MAXSIZE)%MAXSIZE;
}

// �ж�ѭ�������Ƿ�Ϊ�գ�����ֵ��1-�գ�0-�ǿջ�ʧ�ܡ�
int IsEmpty(PSeqQueue QQ)
{
  if (QQ == NULL) return 0;    // ����ָ�롣

  if (QQ->front == QQ->rear) return 1;

  return 0;
}

// �ж�ѭ�������Ƿ�����������ֵ��1-������0-δ����ʧ�ܡ�
int IsFull(PSeqQueue QQ)
{
  if (QQ == NULL) return 0;   // ����ָ�롣

  if ( ((QQ->rear+1)%MAXSIZE) == QQ->front) return 1;

  return 0;
}

// Ԫ����ӣ�����ֵ��0-ʧ�ܣ�1-�ɹ���
int InQueue(PSeqQueue QQ, ElemType *ee)
{
  if ( (QQ == NULL) || (ee == NULL) ) return 0;   // ����ָ�롣

  if (IsFull(QQ) == 1)
  {
    printf("ѭ���������������ܲ��롣\n"); return 0;
  }

  memcpy(&QQ->data[QQ->rear],ee,sizeof(ElemType));  // ��������±���ʡ�
  // memcpy(QQ->data+QQ->rear,ee,sizeof(ElemType));    // ����ָ������Ҳ���ԡ�

  QQ->rear=(QQ->rear+1)%MAXSIZE;  // ��βָ����ơ�

  return 1;
}

// Ԫ�س��ӣ�����ֵ��0-ʧ�ܣ�1-�ɹ���
int OutQueue(PSeqQueue QQ, ElemType *ee)
{
  if ( (QQ == NULL) || (ee == NULL) ) return 0;   // ����ָ�롣

  if (IsEmpty(QQ) == 1) { printf("����Ϊ�ա�\n"); return 0; }

  memcpy(ee,&QQ->data[QQ->front],sizeof(ElemType));  // ��������±���ʡ�
  // memcpy(ee,QQ->data+QQ->front,sizeof(ElemType));    // ����ָ������Ҳ���ԡ�

  QQ->front=(QQ->front+1)%MAXSIZE;  // ����ͷָ����ơ�

  return 1;
}

