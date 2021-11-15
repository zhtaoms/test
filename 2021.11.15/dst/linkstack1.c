/*
 * ��������linkstack1.c���˳�����ʾ��ջ��ʵ�֣�����Ԫ����������
 * ���ߣ�C���Լ�����(www.freecplus.net) ���ڣ�20201230
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int ElemType;    // �Զ�����ջ������Ԫ��Ϊ������

typedef struct SNode
{
  ElemType data;       // ��ջ�е�Ԫ�ء�
  struct SNode *next;  // ָ����һ������ָ�롣
}SNode,*LinkStack;

// ��ջSS�ĳ�ʼ������������ͷ��㣬����ͷ���ĵ�ַ��
SNode *InitStack();

// ������ջSS��
void DestroyStack(LinkStack SS);

// Ԫ����ջ������ֵ��0-ʧ�ܣ�1-�ɹ���
int Push(LinkStack SS, ElemType *ee);

// Ԫ�س�ջ������ֵ��0-ʧ�ܣ�1-�ɹ���
int Pop(LinkStack SS, ElemType *ee);

// ����ջ�ĳ��ȣ�����ֵ��ջSS��Ԫ�صĸ�����
int  Length(LinkStack SS);                   

// �����ջ��
void Clear(LinkStack SS);                    

// �ж���ջ�Ƿ�Ϊ�գ�����ֵ��1-�գ�0-�ǿջ�ʧ�ܡ�
int  IsEmpty(LinkStack SS);                    

// ��ӡ��ջ��ȫ����Ԫ�ء�
void PrintStack(LinkStack SS);                    

// ��ȡջ��Ԫ�أ�����ֵ��0-ʧ�ܣ�1-�ɹ���
// ֻ�鿴ջ��Ԫ�ص�ֵ��Ԫ�ز���ջ��
int GetTop(LinkStack SS, ElemType *ee);

int main()
{
  LinkStack SS;     // ������ջ��

  SS=InitStack();  // ��ʼ����ջ��

  printf("ջ�ĳ�����%d\n",Length(SS));

  ElemType ee;     // ����һ������Ԫ�ء�

  printf("Ԫ�أ�1��2��3��4��5��6��7��8��9��10����ջ��\n");
  ee=1;  Push(SS, &ee);
  ee=2;  Push(SS, &ee);
  ee=3;  Push(SS, &ee);
  ee=4;  Push(SS, &ee);
  ee=5;  Push(SS, &ee);
  ee=6;  Push(SS, &ee);
  ee=7;  Push(SS, &ee);
  ee=8;  Push(SS, &ee);
  ee=9;  Push(SS, &ee);
  ee=10; Push(SS, &ee);

  printf("ջ�ĳ�����%d\n",Length(SS));

  if (GetTop(SS,&ee)==1)  printf("ջ����Ԫ��ֵΪ%d\n",ee);

  PrintStack(SS);

  if (Pop(SS,&ee)==1)  printf("��ջ��Ԫ��ֵΪ%d\n",ee);
  if (Pop(SS,&ee)==1)  printf("��ջ��Ԫ��ֵΪ%d\n",ee);
  if (Pop(SS,&ee)==1)  printf("��ջ��Ԫ��ֵΪ%d\n",ee);
  if (Pop(SS,&ee)==1)  printf("��ջ��Ԫ��ֵΪ%d\n",ee);
  if (Pop(SS,&ee)==1)  printf("��ջ��Ԫ��ֵΪ%d\n",ee);
  if (Pop(SS,&ee)==1)  printf("��ջ��Ԫ��ֵΪ%d\n",ee);
  if (Pop(SS,&ee)==1)  printf("��ջ��Ԫ��ֵΪ%d\n",ee);
  if (Pop(SS,&ee)==1)  printf("��ջ��Ԫ��ֵΪ%d\n",ee);
  if (Pop(SS,&ee)==1)  printf("��ջ��Ԫ��ֵΪ%d\n",ee);
  if (Pop(SS,&ee)==1)  printf("��ջ��Ԫ��ֵΪ%d\n",ee);
  if (Pop(SS,&ee)==1)  printf("��ջ��Ԫ��ֵΪ%d\n",ee);
  if (Pop(SS,&ee)==1)  printf("��ջ��Ԫ��ֵΪ%d\n",ee);

  // ������ջSS��
  DestroyStack(SS); SS=0;  // ������ջ���SS��Ϊ�գ���ֹҰָ�롣

  return 0;
}

// ��ջSS�ĳ�ʼ������������ͷ��㣬����ͷ���ĵ�ַ��
SNode *InitStack()
{
  SNode *head = (SNode *)malloc(sizeof(SNode));  // ����ͷ��㡣

  if (head == NULL) return NULL;  // �ڴ治�㣬����ʧ�ܡ�

  head->next=NULL;  // ͷ������һ�����ʱ�����ڣ��ÿա�

  return head;
}


// �����ջ��
void Clear(LinkStack SS)
{
  // �����ջSS��ָ�ͷ���ջȫ���Ľ�㣬��������ͷ��㡣
  if (SS == NULL) return;  // ����ָ�롣

  SNode *tmp1;
  SNode *tmp2=SS->next;  // ����ͷ��㣬��ͷ������һ����㿪ʼ�ͷš�

  while(tmp2!=NULL)
  {
    tmp1=tmp2->next;
    free(tmp2);
    tmp2=tmp1;
  }

  SS->next=NULL; // ���д���һ�������٣����������Ұָ�롣

  return;
}

// ����ջ�ĳ��ȣ�����ֵ��ջSS��Ԫ�صĸ�����
int  Length(LinkStack SS)
{
  if (SS == NULL) return 0; // ����ָ�롣

  SNode *pp=SS->next;  // ͷ��㲻�㣬�ӵ�1����㿪ʼ��

  int length=0;

  while (pp != NULL) { pp=pp->next; length++; }

  return length;
}

// ������ջSS��
void DestroyStack(LinkStack SS)
{
  // ������ջSS��ָ�ͷ���ջȫ���Ľ�㣬����ͷ��㡣
  SNode *tmp;

  while(SS!=NULL)
  {
    tmp=SS->next;  // tmp������һ���ĵ�ַ��
    free(SS);      // �ͷŵ�ǰ��㡣
    SS=tmp;        // SSָ���ƶ�����һ��㡣
  }

  // SS=NULL;   // SS�ڱ��������൱�ھֲ������������ÿ���Ҳ����Ӱ������ߴ��ݵ�SS������SS=NULLû�����塣

  return;
}

// �ж���ջ�Ƿ�Ϊ�գ�����ֵ��1-�գ�0-�ǿջ�ʧ�ܡ�
int IsEmpty(LinkStack SS)
{
  if (SS == NULL) return 0;   // ����ָ�롣

  if (SS->next == NULL) return 1;

  return 0;
}

// ��ӡ��ջ��ȫ����Ԫ�ء�
void PrintStack(LinkStack SS)
{
  if (SS == NULL) return; // ����ָ�롣

  if (SS->next == NULL) { printf("ջΪ�ա�\n"); return; }

  int kk=0;
  SNode *pp=SS->next;  // �ӵ�1����㿪ʼ��

  while (pp != NULL)
  {
    printf("SS[%d],value=%d\n",kk++,pp->data);     
    pp=pp->next;
  }
}

// Ԫ�س�ջ������ֵ��0-ʧ�ܣ�1-�ɹ���
int Pop(LinkStack SS, ElemType *ee)
{
  if ( (SS == NULL) || (ee == NULL) ) return 0;  // ����ָ�롣

  if (SS->next == NULL) { printf("ջΪ�ա�\n"); return 0; }

  SNode *tmp=SS->next;

  memcpy(ee,&tmp->data,sizeof(ElemType));  

  SS->next=tmp->next;

  free(tmp);

  return 1;
}

// ��ȡջ��Ԫ�أ�����ֵ��0-ʧ�ܣ�1-�ɹ���
// ֻ�鿴ջ��Ԫ�ص�ֵ��Ԫ�ز���ջ��
int GetTop(LinkStack SS, ElemType *ee)
{
  if ( (SS == NULL) || (ee == NULL) ) return 0;  // ����ָ�롣

  if (SS->next == NULL) { printf("ջΪ�ա�\n"); return 0; }

  memcpy(ee,&SS->next->data,sizeof(ElemType));  

  return 1;
}

// Ԫ����ջ������ֵ��0-ʧ�ܣ�1-�ɹ���
int Push(LinkStack SS, ElemType *ee)
{
  if ( (SS == NULL) || (ee == NULL) ) return 0;  // ����ָ�롣

  SNode *tmp = (SNode *)malloc(sizeof(SNode));  // ����һ����㡣
  if (tmp == NULL) return 0;  // �ڴ治�㣬����ʧ�ܡ�

  // ��������Ԫ��Ϊ�ṹ�����������������memcpy�ķ���������ֱ�Ӹ�ֵ��
  memcpy(&tmp->data,ee,sizeof(ElemType));

  // ����nextָ�롣
  tmp->next=SS->next;
  SS->next=tmp;
  
  return 1;
}
