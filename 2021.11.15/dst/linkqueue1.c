/*
 * ��������linkqueue1.c���˳�����ʾ���е�����ʵ�֣���ͷ��㣩��
 * ���ߣ�C���Լ�����(www.freecplus.net) ���ڣ�20201230
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int ElemType;    // �Զ�����е�����Ԫ��Ϊ������

typedef struct LNode
{
  ElemType data;         // �洢�����е�Ԫ�ء�
  struct LNode *next;    // nextָ�롣
}LNode;

typedef struct
{
  LNode *front,*rear;     // ���е�ͷָ���βָ�롣
}LinkQueue,*PLinkQueue;

// ����QQ�ĳ�ʼ��������
int InitQueue(PLinkQueue QQ);                     

// ���ٶ���QQ��
void DestroyQueue(PLinkQueue QQ);

// ��ն��С�
void Clear(PLinkQueue QQ);                    

// Ԫ����ӣ�����ֵ��0-ʧ�ܣ�1-�ɹ���
int InQueue(PLinkQueue QQ, ElemType *ee);

// ��ӡ������ȫ����Ԫ�ء�
void PrintQueue(PLinkQueue QQ);                    

// ����еĳ��ȣ�����ֵ��>=0-����QQԪ�صĸ�����
int  Length(PLinkQueue QQ);                   

// �ж϶����Ƿ���������ʽ���в����ڶ�����˵����
int IsFull(PLinkQueue QQ);

// �ж϶����Ƿ�Ϊ�գ�����ֵ��1-�գ�0-�ǿջ�ʧ�ܡ�
int  IsEmpty(PLinkQueue QQ);                    

// Ԫ�س��ӣ�����ֵ��0-ʧ�ܣ�1-�ɹ���
int OutQueue(PLinkQueue QQ, ElemType *ee);

// ��ȡ��ͷԪ�أ�����ֵ��0-ʧ�ܣ�1-�ɹ���
// ֻ�鿴��ͷԪ�ص�ֵ��Ԫ�ز����ӡ�
int GetHead(PLinkQueue QQ, ElemType *ee);

int main()
{
  LinkQueue QQ;     // �������С�

  memset(&QQ,0,sizeof(LinkQueue));

  InitQueue(&QQ);  // ��ʼ�����С�

  ElemType ee;     // ����һ������Ԫ�ء�

  printf("Ԫ�أ�1��2��3��4��5��6��7��8��9��10����ӡ�\n");
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

  DestroyQueue(&QQ); // ���ٶ���QQ��

  return 0;
}

// ��ʼ�����У�����ֵ��0-ʧ�ܣ�1-�ɹ���
int InitQueue(PLinkQueue QQ)
{
  LNode *head = (LNode *)malloc(sizeof(LNode));  // ����ͷ��㡣

  if (head == NULL) return 0;  // �ڴ治�㣬����ʧ�ܡ�

  head->next=NULL;  // ͷ������һ�����ʱ�����ڣ��ÿա�

  QQ->front=QQ->rear=head;

  return 1;
}

// ��ն��С�
void Clear(PLinkQueue QQ)
{
  if (QQ == NULL) return; // �ж϶����Ƿ���ڡ�

  if (QQ->front == NULL) { printf("����QQδ��ʼ����\n"); return; } // ����δ��ʼ����

  // ��ն���QQ��ָ�ͷ�����ȫ�������ݽ�㣬������ͷ��㡣
  LNode *tmp=QQ->front->next,*tmpnext;

  while(tmp!=NULL)
  {
    tmpnext=tmp->next;  // tmpnext������һ���ĵ�ַ��
    free(tmp);          // �ͷŵ�ǰ��㡣
    tmp=tmpnext;        // tmpָ���ƶ�����һ��㡣
  }

  QQ->rear=QQ->front;   // βָ��ָ��ͷ��㡣

  QQ->front->next=NULL;
}

// ����еĳ��ȣ�����ֵ��>=0-����QQԪ�صĸ�����
int Length(PLinkQueue QQ)
{
  if (QQ == NULL) return 0;  // ����ָ�롣

  if (QQ->front == NULL) { printf("����QQδ��ʼ����\n"); return 0; } // ����δ��ʼ����

  LNode *pp=QQ->front->next;  // ͷ��㲻�㣬�ӵ�1����㿪ʼ��

  int length=0;

  while (pp != NULL) { pp=pp->next; length++; }

  return length;

}

// ���ٶ���QQ��
void DestroyQueue(PLinkQueue QQ)
{
  if (QQ == NULL) return;    // ����ָ�롣

  // ���ٶ���QQ��ָ�ͷ�����ȫ���Ľ�㣬����ͷ��㡣
  LNode *tmp=QQ->front,*tmpnext;

  while(tmp!=NULL)
  {
    tmpnext=tmp->next;  // tmpnext������һ���ĵ�ַ��
    free(tmp);          // �ͷŵ�ǰ��㡣
    tmp=tmpnext;        // tmpָ���ƶ�����һ��㡣
  }

  QQ->front=QQ->rear=NULL;  // ��ֹҰָ�롣

  return;
}

// �ж϶����Ƿ�Ϊ�գ�����ֵ��1-�գ�0-�ǿջ�ʧ�ܡ�
int IsEmpty(PLinkQueue QQ)
{
  if (QQ == NULL) return 0;  // ����ָ�롣

  if (QQ->front == NULL) { printf("����QQδ��ʼ����\n"); return 0; } // ����δ��ʼ����

  if (QQ->front->next == NULL) return 1;

  return 0;
}

// �ж϶����Ƿ���������ʽ���в����ڶ�����˵����
int IsFull(PLinkQueue QQ)
{
  if (QQ == NULL) return 0;   // ����ָ�롣

  return 1;
}

// Ԫ����ӣ�����ֵ��0-ʧ�ܣ�1-�ɹ���
int InQueue(PLinkQueue QQ, ElemType *ee)
{
  if ( (QQ == NULL) || (ee == NULL) ) return 0;   // ����ָ�롣

  if (QQ->front == NULL) { printf("����QQδ��ʼ����\n"); return 0; } // ����δ��ʼ����

  LNode *tmp = (LNode *)malloc(sizeof(LNode));  // ����һ����㡣
  if (tmp == NULL) return 0;  // �ڴ治�㣬����ʧ�ܡ�

  // ��������Ԫ��Ϊ�ṹ�����������������memcpy�ķ���������ֱ�Ӹ�ֵ��
  memcpy(&tmp->data,ee,sizeof(ElemType));
  tmp->next=NULL;

  // ��tmp׷�ӵ�QQ->rear֮��
  QQ->rear->next=tmp;
  QQ->rear=tmp;

  return 1;
}

// ��ӡ������ȫ����Ԫ�ء�
void PrintQueue(PLinkQueue QQ)
{
  if (QQ == NULL) return;   // ����ָ�롣

  if (QQ->front == NULL) { printf("����QQδ��ʼ����\n"); return; } // ����δ��ʼ����

  LNode *pp=QQ->front->next;  // �ӵ�1�����ݽ�㿪ʼ��

  while (pp != NULL)
  {
    printf("%-3d", pp->data);  // ���Ԫ��eeΪ�ṹ�壬���д���Ҫ�޸ġ�
    pp=pp->next;
  }

  printf("\n");
}

// Ԫ�س��ӣ�����ֵ��0-ʧ�ܣ�1-�ɹ���
int OutQueue(PLinkQueue QQ, ElemType *ee)
{
  if ( (QQ == NULL) || (ee == NULL) ) return 0;   // ����ָ�롣

  if (QQ->front == NULL) { printf("����QQδ��ʼ����\n"); return 0; } // ����δ��ʼ����

  if (IsEmpty(QQ) == 1) { printf("����Ϊ�ա�\n"); return 0; }

  LNode *tmp=QQ->front->next;

  memcpy(ee,&tmp->data,sizeof(ElemType));  
  QQ->front->next=tmp->next;

  // ������ӵ������һ����㡣
  if (QQ->rear==tmp) QQ->rear=QQ->front;
  
  free(tmp);

  return 1;
}

// ��ȡ��ͷԪ�أ�����ֵ��0-ʧ�ܣ�1-�ɹ���
// ֻ�鿴��ͷԪ�ص�ֵ��Ԫ�ز����ӡ�
int GetHead(PLinkQueue QQ, ElemType *ee)
{
  if ( (QQ == NULL) || (ee == NULL) ) return 0;   // ����ָ�롣

  if (QQ->front == NULL) { printf("����QQδ��ʼ����\n"); return 0; } // ����δ��ʼ����

  if (IsEmpty(QQ) == 1) { printf("����Ϊ�ա�\n"); return 0; }

  memcpy(ee,&QQ->front->next->data,sizeof(ElemType));  

  return 1;
}
