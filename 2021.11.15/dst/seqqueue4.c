/*
 * ��������seqqueue4.c���˳�����ʾѭ�����е�����ʵ�֣���βָ��ָ���βԪ�أ�������length�ĸ���������
 * ���ߣ�C���Լ�����(www.freecplus.net) ���ڣ�20201230
*/
#include <stdio.h>
#include <string.h>

#define MAXSIZE 10       // ѭ�����е���󳤶ȣ������Դ��MAXSIZE��Ԫ�ء�

typedef int ElemType;    // �Զ���ѭ�����е�����Ԫ��Ϊ������

typedef struct
{
  ElemType data[MAXSIZE];   // ������洢ѭ�������е�Ԫ�ء�
  int front;                // ���е�ͷָ�롣
  int rear;                 // ���е�βָ�룬ָ���βԪ�ء�
  int length;               // ���е�ʵ�ʳ��ȡ�    // xxx
}SeqQueue,*PSeqQueue;

// ѭ������QQ�ĳ�ʼ��������
void InitQueue(PSeqQueue QQ);                     

// ����ѭ������QQ��
void DestroyQueue(PSeqQueue QQ);

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

// ��ӡѭ��������ȫ����Ԫ�ء�
void PrintQueue(PSeqQueue QQ);                    

// ��ȡ��ͷԪ�أ�����ֵ��0-ʧ�ܣ�1-�ɹ���
// ֻ�鿴��ͷԪ�ص�ֵ��Ԫ�ز����ӡ�
int GetHead(PSeqQueue QQ, ElemType *ee);

int main()
{
  SeqQueue QQ;     // ����ѭ�����С�

  InitQueue(&QQ);  // ��ʼ��ѭ�����С�

  ElemType ee;     // ����һ������Ԫ�ء�

  printf("Ԫ�أ�1��2��3��4��5��6��7��8��9��10��11����ӡ�\n");
  ee=1;  InQueue(&QQ, &ee);
  ee=2;  InQueue(&QQ, &ee);
  ee=3;  InQueue(&QQ, &ee);
  ee=4;  InQueue(&QQ, &ee);
  ee=5;  InQueue(&QQ, &ee);
  ee=6;  InQueue(&QQ, &ee);
  ee=7;  InQueue(&QQ, &ee);
  ee=8;  InQueue(&QQ, &ee);
  ee=9;  InQueue(&QQ, &ee);
  ee=10; InQueue(&QQ, &ee);
  ee=11; InQueue(&QQ, &ee);

  printf("���еĳ�����%d\n",Length(&QQ));
  PrintQueue(&QQ);

  if (OutQueue(&QQ,&ee)==1)  printf("���ӵ�Ԫ��ֵΪ%d\n",ee);
  if (OutQueue(&QQ,&ee)==1)  printf("���ӵ�Ԫ��ֵΪ%d\n",ee);
  if (OutQueue(&QQ,&ee)==1)  printf("���ӵ�Ԫ��ֵΪ%d\n",ee);
  if (OutQueue(&QQ,&ee)==1)  printf("���ӵ�Ԫ��ֵΪ%d\n",ee);
  if (OutQueue(&QQ,&ee)==1)  printf("���ӵ�Ԫ��ֵΪ%d\n",ee);
  if (OutQueue(&QQ,&ee)==1)  printf("���ӵ�Ԫ��ֵΪ%d\n",ee);
  if (OutQueue(&QQ,&ee)==1)  printf("���ӵ�Ԫ��ֵΪ%d\n",ee);

  printf("���еĳ�����%d\n",Length(&QQ));
  PrintQueue(&QQ);

  printf("Ԫ�أ�11��12��13��14��15����ӡ�\n");
  ee=11;  InQueue(&QQ, &ee);
  ee=12;  InQueue(&QQ, &ee);
  ee=13;  InQueue(&QQ, &ee);
  ee=14;  InQueue(&QQ, &ee);
  ee=15;  InQueue(&QQ, &ee);

  printf("���еĳ�����%d\n",Length(&QQ));

  PrintQueue(&QQ);

  // ֻ�鿴��ͷԪ�ص�ֵ��Ԫ�ز����ӡ�
  if (GetHead(&QQ,&ee)==1)  printf("��ͷ��Ԫ��ֵΪ%d\n",ee);

  return 0;
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

  QQ->front=0;
  QQ->rear=MAXSIZE-1;    // xxxx
  QQ->length=0;
  memset(QQ->data,0,sizeof(ElemType)*MAXSIZE);  // ����Ԫ�����㡣
}

// ��ѭ�����еĳ��ȣ�����ֵ��>=0-����QQԪ�صĸ�����
int Length(PSeqQueue QQ)
{
  if (QQ == NULL) return 0;  // ����ָ�롣

  return QQ->length;    // xxx
}

// ����ѭ������QQ��
void DestroyQueue(PSeqQueue QQ)
{
  // ��̬ѭ�����������ͷ��ڴ棬����Ҫ���ٲ�����

  Clear(QQ); // ���ѭ�����С�

  return;
}

// �ж�ѭ�������Ƿ�Ϊ�գ�����ֵ��1-�գ�0-�ǿջ�ʧ�ܡ�
int IsEmpty(PSeqQueue QQ)
{
  if (QQ == NULL) return 0;   // ����ָ�롣

  // if (QQ->front == QQ->rear) return 1;  

  if (QQ->length == 0) return 1;    // xxx

  return 0;
}

// �ж�ѭ�������Ƿ�����������ֵ��1-������0-δ����ʧ�ܡ�
int IsFull(PSeqQueue QQ)
{
  if (QQ == NULL) return 0;   // ����ָ�롣

  // if ( ((QQ->rear+1)%MAXSIZE) == QQ->front) return 1;
  if (QQ->length == MAXSIZE) return 1;    // xxx

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

  // xxxx ���ƶ���βָ�룬Ȼ���ٲ������ݡ�
  QQ->rear=(QQ->rear+1)%MAXSIZE;  // ��βָ����ơ�

  memcpy(&QQ->data[QQ->rear],ee,sizeof(ElemType));  // ��������±���ʡ�
  // memcpy(QQ->data+QQ->rear,ee,sizeof(ElemType));    // ����ָ������Ҳ���ԡ�

  QQ->length++;    // xxx

  return 1;
}

// ��ӡѭ��������ȫ����Ԫ�ء�
void PrintQueue(PSeqQueue QQ)
{
  if (QQ == NULL) return;   // ����ָ�롣

  if (IsEmpty(QQ) == 1) { printf("����Ϊ�ա�\n"); return; }

  int kk,qlen=Length(QQ);
  for (kk = 0; kk < qlen; kk++)
  {
    // ��������±���ʡ�
    printf("data[%d],value=%d\n",(QQ->front+kk)%MAXSIZE,QQ->data[(QQ->front+kk)%MAXSIZE]);     
   
    // ����ָ������Ҳ���ԡ�
    // printf("data[%d],value=%d\n",(QQ->front+kk)%MAXSIZE,*(QQ->data+(QQ->front+kk)%MAXSIZE));
  }
}

// Ԫ�س��ӣ�����ֵ��0-ʧ�ܣ�1-�ɹ���
int OutQueue(PSeqQueue QQ, ElemType *ee)
{
  if ( (QQ == NULL) || (ee == NULL) ) return 0;   // ����ָ�롣

  if (IsEmpty(QQ) == 1) { printf("����Ϊ�ա�\n"); return 0; }

  memcpy(ee,&QQ->data[QQ->front],sizeof(ElemType));  // ��������±���ʡ�
  // memcpy(ee,QQ->data+QQ->front,sizeof(ElemType));    // ����ָ������Ҳ���ԡ�

  QQ->front=(QQ->front+1)%MAXSIZE;  // ����ͷָ����ơ�

  QQ->length--;    // xxx

  return 1;
}

// ��ȡ��ͷԪ�أ�����ֵ��0-ʧ�ܣ�1-�ɹ���
// ֻ�鿴��ͷԪ�ص�ֵ��Ԫ�ز����ӡ�
int GetHead(PSeqQueue QQ, ElemType *ee)
{
  if ( (QQ == NULL) || (ee == NULL) ) return 0;   // ����ָ�롣

  if (IsEmpty(QQ) == 1) { printf("����Ϊ�ա�\n"); return 0; }

  memcpy(ee,&QQ->data[QQ->front],sizeof(ElemType));  // ��������±���ʡ�
  // memcpy(ee,QQ->data+QQ->front,sizeof(ElemType));    // ����ָ������Ҳ���ԡ�

  return 1;
}
