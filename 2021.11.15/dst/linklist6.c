/*
 * ��������linklist6.c���˳�����ʾ����ĳ��ÿ��⣬��linklist1.c�������˳��ÿ���Ľ��
 * ���ߣ�C���Լ�����(www.freecplus.net) ���ڣ�20201230
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int ElemType;     // �Զ������������Ԫ��Ϊ������

typedef struct LNode
{
  ElemType data;       // ��Ž�������Ԫ�ء�
  struct LNode *next;  // ָ����һ������ָ�롣
}LNode,*LinkList;

// ��ʼ������LL������ֵ��ʧ�ܷ���NULL���ɹ�����ͷ���ĵ�ַ��
LNode *InitList1();

// ����ָ������ĵ�ַ�ķ�����
// ��ʼ����������ֵ��0-ʧ�ܣ�1-�ɹ���
int InitList2(LinkList *LL);

// C++���õķ�������Linux�£���Ҫ��g++���롣
// ��ʼ����������ֵ��0-ʧ�ܣ�1-�ɹ���
// int InitList3(LinkList &LL);

// �����������תָ��LL��ֵ��LL��ֵֻ�ܴ���ȥ���޷����أ����ַ����ǲ��еġ�
int InitList4(LinkList LL);

// ��������LL��
void DestroyList1(LinkList LL);

// ��������LL��
// ����ָ��ĵ�ַ�ķ�����
void DestroyList2(LinkList *LL);

// C++���õķ�������Linux�£���Ҫ��g++���롣
// ����ָ��ĵ�ַ�ķ�����
// void DestroyList3(LinkList &LL);

// �������
void ClearList(LinkList LL);                    

// ������LL�ĵ�ii��λ�ò���Ԫ��ee������ֵ��0-ʧ�ܣ�1-�ɹ���
int  InsertList(LinkList LL, unsigned int ii, ElemType *ee);   

// ��ӡ������ȫ����Ԫ�ء�
void PrintList(LinkList LL);                    

// �����ӡ������ȫ����Ԫ�ء�
void PrintList1(LNode *pp);

// ������LL��ͷ������Ԫ��ee������ֵ��0-ʧ�ܣ�1-�ɹ���
int  PushFront(LinkList LL, ElemType *ee);

// ������LL��β������Ԫ��ee������ֵ��0-ʧ�ܣ�1-�ɹ���
int  PushBack(LinkList LL, ElemType *ee);

// ɾ������LL�еĵ�ii����㣬����ֵ��0-λ��ii���Ϸ���1-�ɹ���
int  DeleteNode(LinkList LL, unsigned int ii);  

// ɾ������LL�е�һ����㣬����ֵ��0-λ�ò��Ϸ���1-�ɹ���
int PopFront(LinkList LL);

// ɾ������LL�����һ����㣬����ֵ��0-λ�ò��Ϸ���1-�ɹ���
int PopBack(LinkList LL);

// ������ĳ��ȣ�����ֵ��>=0-��LL���ĸ�����
int  LengthList(LinkList LL);                   

// �ж������Ƿ�Ϊ�գ�����ֵ��0-�ǿջ�ʧ�ܣ�1-�ա�
int IsEmpty(LinkList LL);

// ��ȡ�����е�ii����㣬�ɹ����ؽ��ĵ�ַ��ʧ�ܷ��ؿա�
// ע�⣬ii����ȡֵΪ0����ʾͷ��㡣
LNode *LocateNode(LinkList LL, unsigned int ii);

// ����Ԫ��ee������LL�еĽ���ַ�����û�ҵ�����NULL�����򷵻ؽ��ĵ�ַ��
LNode *LocateElem(LinkList LL, ElemType *ee);

// ��ָ�����pp֮�����Ԫ��ee������ֵ��0-ʧ�ܣ�1-�ɹ���
int InsertNextNode(LNode *pp, ElemType *ee);

// ��ָ�����pp֮ǰ����Ԫ��ee������ֵ��0-ʧ�ܣ�1-�ɹ���
int InsertPriorNode(LNode *pp, ElemType *ee);

// ɾ��ָ����㡣
int DeleteNode1(LNode *pp);

// ���ù鲢�ķ��������������������La��Lb���ϲ���һ�����������Lc��
int MergeList(LinkList La,LinkList Lb,LinkList Lc);

// ������pp���֮��Ľ��ԭ�����ã���ת��������ֵ��0-ʧ�ܣ�1-�ɹ���
void ReverseList(LNode *pp);

// �ҳ���ͷ���ĵ���������k(k>0)����㡣
LNode *FindKNode(LinkList LL,unsigned int kk);

// �жϵ������Ƿ��л������ҵ�������ڡ�
LNode *FindLoop(LinkList LL);

// �ҳ�������۵�����Ĺ�����㣬���û�л�ۣ����ؿգ�����У����ػ�۵ĵ�һ����㡣
LNode *FindJoin(LinkList La,LinkList Lb);

// �������Ա�L=(a1,a2,a3,...,an-2,an-1,an)���ô�ͷ���ĵ������棬���ݽ��ĸ���Ϊż����
// �����һ���ռ临�Ӷ�ΪO(1)��ʱ���Ͼ����ܸ�Ч���㷨����������L�еĸ���㡣
// ���õ����Ա�L=(a1,an,a2,an-1,a3,an-2,...)��
void ReplaceList(LinkList LL);

int main()
{
  LinkList LL=NULL; // ��������ָ�������

  LL=InitList1();     // ��ʼ������

  printf("LL=%p\n",LL);

  ElemType ee;      // ����һ������Ԫ�ء�

  printf("�ڱ��в���Ԫ�أ�1��2��3��4��5��6��7��8��9��10����\n");
  ee=1;  PushBack(LL, &ee);
  ee=2;  PushBack(LL, &ee);
  ee=3;  PushBack(LL, &ee);
  ee=4;  PushBack(LL, &ee);
  ee=5;  PushBack(LL, &ee);
  ee=6;  PushBack(LL, &ee);
  ee=7;  PushBack(LL, &ee);
  ee=8;  PushBack(LL, &ee);
  ee=9;  PushBack(LL, &ee);
  ee=10; PushBack(LL, &ee);

  // ������˳����ʾȫ������ֵ��
  PrintList(LL);

  // ��1�⡣
  /*
  // ������ʾȫ������ֵ��
  PrintList1(LL->next); printf("\n");
  */

  // ��2�⡣
  /*
  // �ҳ���ͷ���ĵ���������k(k>0)����㡣
  LNode *tmp=FindKNode(LL,6);
  if (tmp == NULL) 
    printf("������6�����û���š�\n");
  else
    printf("������6������ֵ��%d��\n",tmp->data);
  */

  // ��3�⡣
  /*
  // �жϵ������Ƿ��л������ҵ�������ڡ�
  // �ֹ����������ó��л���
  LNode *tmp1=LocateNode(LL,4);
  LNode *tmp2=LocateNode(LL,10);
  tmp2->next=tmp1;
  printf("����������ڵĵ�ַ��%p������ֵ��%d��\n",tmp1,tmp1->data);

  // �жϵ������Ƿ��л������ҵ�������ڡ�
  LNode *tmp=FindLoop(LL);
  if (tmp == NULL) 
    printf("����û����\n");
  else
    printf("������ڵĵ�ַ��%p������ֵ��%d��\n",tmp,tmp->data);
  */

  // ��4�⡣
  /*
  LinkList La=LL;   // ֱ����LL��

  // ��������Lb��
  LinkList Lb=InitList1();     // ��ʼ������
  printf("�ڱ�Lb�в���Ԫ�أ�11��12��33����\n");
  ee=11;  PushBack(Lb, &ee);
  ee=12;  PushBack(Lb, &ee);
  ee=13;  PushBack(Lb, &ee);

  // ��Lb���һ���ڵ��nextָ��ָ��La�ĵ�7����㡣
  LNode *tmp1=LocateNode(La,7); 
  LNode *tmp2=LocateNode(Lb,3); 
  tmp2->next=tmp1;

  PrintList(La);
  PrintList(Lb);

  // �ҳ�������۵�����Ĺ�����㣬���û�л�ۣ����ؿգ�����У����ػ�۵ĵ�һ����㡣
  LNode *tmp=FindJoin(La,Lb);
  if (tmp == NULL)
    printf("����û�л�ۡ�\n");
  else
    printf("�����۵���ʼ��ַ��%p������ֵ��%d��\n",tmp,tmp->data);
  */

  // ��5�⡣
  /*
  // �������Ա�L=(a1,a2,a3,...,an-2,an-1,an)���ô�ͷ���ĵ������棬���ݽ��ĸ���Ϊż����
  // �����һ���ռ临�Ӷ�ΪO(1)��ʱ���Ͼ����ܸ�Ч���㷨����������L�еĸ���㡣
  // ���õ����Ա�L=(a1,an,a2,an-1,a3,an-2,...)��
  ReplaceList(LL);
  PrintList(LL);
  */

  // �ڲ���FindLoop������ʱ�򣬲����������´��롣
  // DestroyList1(LL); LL=NULL;  // ��������LL��Ϊ�ա�

  return 0;
}

// �����������תָ��LL��ֵ��LL��ֵֻ�ܴ���ȥ���޷����أ����ַ����ǲ��еġ�
int InitList4(LinkList LL)
{
  LNode *head = (LNode *)malloc(sizeof(LNode));  // ����ͷ��㡣

  if (head == NULL) return 0;  // �ڴ治�㣬����ʧ�ܡ�

  head->next=NULL;  // ͷ������һ�����ʱ�����ڣ��ÿա�

  LL=head;

  printf("LL1=%p\n",LL);

  return 1;
}

// ��ʼ������LL������ֵ��ʧ�ܷ���NULL���ɹ�����ͷ���ĵ�ַ��
LNode *InitList1()
{
  LNode *head = (LNode *)malloc(sizeof(LNode));  // ����ͷ��㡣

  if (head == NULL) return NULL;  // �ڴ治�㣬����ʧ�ܡ�

  head->next=NULL;  // ͷ������һ�����ʱ�����ڣ��ÿա�

  return head;
}

// ����ָ������ĵ�ַ�ķ�����
// ��ʼ����������ֵ��0-ʧ�ܣ�1-�ɹ���
int InitList2(LinkList *LL)
{
  // �ڱ������У�LL��ָ���ָ�룬���ڴ��ָ��ĵ�ַ��

  if ( *LL != NULL ) { printf("����LL�Ѵ��ڣ��ڳ�ʼ��֮ǰ�����ͷ�����\n"); return 0; }

  LNode *head = (LNode *)malloc(sizeof(LNode));  // ����ͷ��㡣

  if (head == NULL) return 0;  // �ڴ治�㣬����ʧ�ܡ�

  head->next=NULL;  // ͷ������һ�����ʱ�����ڣ��ÿա�

  *LL=head;

  return 1;
}

/*
// C++���õķ�����
// ��ʼ����������ֵ��0-ʧ�ܣ�1-�ɹ���
int InitList3(LinkList &LL)
{
  if ( LL != NULL ) { printf("����L�Ѵ��ڣ��ڳ�ʼ��֮ǰ�����ͷ�����\n"); return 0; }

  LNode *head = (LNode *)malloc(sizeof(LNode));  // ����ͷ��㡣

  if (head == NULL) return 0;  // �ڴ治�㣬����ʧ�ܡ�

  head->next=NULL;  // ͷ������һ�����ʱ�����ڣ��ÿա�

  LL=head;

  return 1;
}
*/

// ��������LL��
void DestroyList1(LinkList LL)
{
  // ��������LL��ָ�ͷ�����ȫ���Ľ�㣬����ͷ��㡣
  LNode *tmp;

  while(LL!=NULL)
  {
    tmp=LL->next;  // tmp������һ���ĵ�ַ��
    free(LL);      // �ͷŵ�ǰ��㡣
    LL=tmp;        // LLָ���ƶ�����һ��㡣
  }

  // LL=NULL;   // LL�ڱ��������൱�ھֲ������������ÿ���Ҳ����Ӱ������ߴ��ݵ�LL������LL=NULLû�����塣

  return;
}

// ��������LL��
void DestroyList2(LinkList *LL)
{  
  // ��������Ĳ�����ָ���ָ�룬�����������´��롣
  LNode *tmp1,*tmp2;

  tmp1=*LL;

  while(tmp1!=NULL)
  {
    tmp2=tmp1->next; // tmp������һ���ĵ�ַ��
    free(tmp1);      // �ͷŵ�ǰ��㡣
    tmp1=tmp2;       // LLָ���ƶ�����һ��㡣
  }

  *LL=NULL;  // �������ָ����Ϊ�գ���ʾ���������ˡ�

  return;
}

/*
// C++���õķ�����
// ����ָ��ĵ�ַ�ķ�����
void DestroyList3(LinkList &LL)
{
  // ��������LL��ָ�ͷ�����ȫ���Ľ�㣬����ͷ��㡣
  LNode *tmp;

  while(LL!=NULL)
  {
    tmp=LL->next;   // tmp������һ���ĵ�ַ��
    free(LL);       // �ͷŵ�ǰ��㡣
    LL=tmp;         // LLָ���ƶ�����һ��㡣
  }

  LL=NULL;  // �������ָ����Ϊ�գ���ʾ���������ˡ�

  return;
}
*/

// �������
void ClearList(LinkList LL)
{
  // �������LL��ָ�ͷ�����ȫ���Ľ�㣬��������ͷ��㡣
  if (LL == NULL) { printf("����LL�����ڡ�\n"); return; } // �ж������Ƿ���ڡ�

  LNode *tmp1;
  LNode *tmp2=LL->next;  // ����ͷ��㣬��ͷ������һ����㿪ʼ�ͷš�

  while(tmp2!=NULL)
  {
    tmp1=tmp2->next;
    free(tmp2);
    tmp2=tmp1;
  }

  LL->next=NULL; // ���д���һ�������٣����������Ұָ�롣

  return;
}

// ������LL�ĵ�ii��λ�ò���Ԫ��ee������ֵ��0-ʧ�ܣ�1-�ɹ���
int InsertList(LinkList LL, unsigned int ii, ElemType *ee)
{
  if ( (LL == NULL) || (ee == NULL) ) { printf("����LL��Ԫ��ee�����ڡ�\n"); return 0; } // �жϱ��Ԫ���Ƿ���ڡ�

  // �жϲ���λ���Ƿ�Ϸ�
  if (ii < 1) { printf("����λ�ã�%d�����Ϸ���Ӧ���ڴ���0��\n",ii); return 0; }

  // Ҫ��λ��ii�����㣬�����ҵ�ii-1��㡣
  LNode *pp=LL;  // ָ��ppָ��ͷ��㣬�������ƶ������Ϊ�գ���ʾ����û����ˡ�
  int kk=0;      // kkָ����ǵڼ�����㣬��ͷ���0��ʼ��ppÿ����ƶ�һ�Σ�kk�ͼ�1��

  while ( (pp != NULL) && (kk < ii-1) )
  {
    pp=pp->next; kk++;

    // printf("pp=%p,kk=%d\n",pp,kk);
  }

  if ( pp==NULL ) { printf("λ�ã�%d�����Ϸ��������˱���\n",ii); return 0; }

  LNode *tmp = (LNode *)malloc(sizeof(LNode));  // ����һ����㡣
  if (tmp == NULL) return 0;  // �ڴ治�㣬����ʧ�ܡ�
  
  // ��������Ԫ��Ϊ�ṹ�����������������memcpy�ķ���������ֱ�Ӹ�ֵ��
  memcpy(&tmp->data,ee,sizeof(ElemType));

  // ����nextָ�롣
  tmp->next=pp->next;
  pp->next=tmp;

  return 1;

  ///////////////////////////////////////
  // ���ϴ�����������´�����档
  // LNode *pp=LocateNode(LL,ii-1);  
  // return InsertNextNode(pp,ee);
  ///////////////////////////////////////
}

// ɾ������LL�еĵ�ii����㣬����ֵ��0-λ��ii���Ϸ���1-�ɹ���
int  DeleteNode(LinkList LL, unsigned int ii)  
{
  if (LL == NULL) { printf("����L�����ڡ�\n"); return 0; } // �ж������Ƿ���ڡ�

  // �ж�ɾ��λ���Ƿ�Ϸ�
  if (ii < 1) { printf("ɾ��λ�ã�%d�����Ϸ���Ӧ���ڴ���0��\n",ii); return 0; }

  // Ҫɾ��λ��ii��㣬�����ҵ�ii-1��㡣
  LNode *pp=LL;  // ָ��ppָ��ͷ��㣬�������ƶ������Ϊ�գ���ʾ����û����ˡ�
  int kk=0;      // kkָ����ǵڼ�����㣬��ͷ���0��ʼ��ppÿ����ƶ�һ�Σ�kk�ͼ�1��

  while ( (pp != NULL) && (kk < ii-1) )
  {
    pp=pp->next; kk++;
  }

  // ע�⣬�����еĴ�������Ƶ�еĲ�һ������Ƶ�е��� if ( pp==NULL )����bug��
  if ( pp->next==NULL ) { printf("λ�ã�%d�����Ϸ��������˱���\n",ii); return 0; }

  LNode *tmp=pp->next;  // tmpΪ��Ҫɾ���Ľ�㡣
  pp->next=pp->next->next;   // д��p->next=tmp->next����ࡣ

  free(tmp);

  return 1;
}

// ������LL��ͷ������Ԫ��ee������ֵ��0-ʧ�ܣ�1-�ɹ���
int  PushFront(LinkList LL, ElemType *ee)
{
  return InsertList(LL,1,ee);
}

// ������LL��β������Ԫ��ee������ֵ��0-ʧ�ܣ�1-�ɹ���
int PushBack(LinkList LL, ElemType *ee)
{
  if ( (LL == NULL) || (ee == NULL) ) { printf("����LL��Ԫ��ee�����ڡ�\n"); return 0; } // �жϱ��Ԫ���Ƿ���ڡ�

  LNode *pp=LL;  // ��ͷ��㿪ʼ��

  // �ҵ����һ����㡣
  while (pp->next != NULL) pp=pp->next;
  
  LNode *tmp = (LNode *)malloc(sizeof(LNode));  // ����һ����㡣
  if (tmp == NULL) return 0;  // �ڴ治�㣬����ʧ�ܡ�
  
  // ��������Ԫ��Ϊ�ṹ�����������������memcpy�ķ���������ֱ�Ӹ�ֵ��
  memcpy(&tmp->data,ee,sizeof(ElemType));

  // ����nextָ�롣
  tmp->next=NULL;
  pp->next=tmp;

  return 1;
}

// ɾ������LL�е�һ����㣬����ֵ��0-λ�ò��Ϸ���1-�ɹ���
int PopFront(LinkList LL)
{
  return DeleteNode(LL, 1);
}

// ɾ������LL�����һ����㣬����ֵ��0-λ�ò��Ϸ���1-�ɹ���
int PopBack(LinkList LL)
{
  if ( LL == NULL ) { printf("����LL�����ڡ�\n"); return 0; } // �жϱ��Ԫ���Ƿ���ڡ�

  // �����������жϣ����������ѭ��pp->next->next��������
  if ( LL->next == NULL) { printf("����LLΪ�գ�û��β��㡣\n"); return 0; } // �жϱ��Ƿ�Ϊ�ա�

  // Ҫɾ�����һ����㣬�����ҵ����һ������ǰһ����㡣

  LNode *pp=LL;  // �ӵ�0����㿪ʼ��

  // �ҵ������ڶ�����㣨����ͷ��㣩��
  while (pp->next->next != NULL) pp=pp->next;
 
  // �ͷ����һ����㡣
  free(pp->next);
  pp->next=NULL;

  return 1;
}

// ��ӡ������ȫ����Ԫ�ء�
void PrintList(LinkList LL)
{
  if (LL == NULL) { printf("����LL�����ڡ�\n"); return; } // �ж������Ƿ���ڡ�

  LNode *pp=LL->next;  // �ӵ�1����㿪ʼ��

  while (pp != NULL)
  {
    printf("%-3d", pp->data);  // ���Ԫ��eeΪ�ṹ�壬���д���Ҫ�޸ġ�
    pp=pp->next;
  }

  printf("\n");

  /*
  // ���´���������ʾȫ�����ĵ�ַ��Ԫ�ص�ֵ��
  LNode *pp=LL;  // �ӵ�0����㿪ʼ��

  while (pp != NULL)
  {
    printf("%p,%p,%-3d\n",pp,pp->next,pp->data);  // ���Ԫ��eeΪ�ṹ�壬���д���Ҫ�޸ġ�
    pp=pp->next;
  }
  */
}

// ������ĳ��ȣ�����ֵ��>=0-��LL���ĸ�����
int  LengthList(LinkList LL)
{
  if (LL == NULL) { printf("����LL�����ڡ�\n"); return 0; } // �ж������Ƿ���ڡ�

  LNode *pp=LL->next;  // ͷ��㲻�㣬�ӵ�1����㿪ʼ��

  int length=0;

  while (pp != NULL) { pp=pp->next; length++; }

  return length;

  // ��ʹ����ʱ��������μ�����������ͷ��㣩�ĳ��ȣ�
  // if (LL==NULL) return 0;
  // return LengthList(LL->next)+1;
}

// �ж������Ƿ�Ϊ�գ�����ֵ��0-�ǿգ�1-�ա�
int IsEmpty(LinkList LL)
{
  if (LL == NULL) return 0;

  if (LL->next == NULL) return 1;

  return 0;
}

// ��ȡ�����е�ii����㣬�ɹ����ؽ��ĵ�ַ��ʧ�ܷ��ؿա�
// ע�⣬ii����ȡֵΪ0����ʾͷ��㡣
LNode *LocateNode(LinkList LL, unsigned int ii)
{
  if ( LL == NULL ) { printf("����LL�����ڡ�\n"); return NULL; } // �жϱ��Ԫ���Ƿ���ڡ�
  
  LNode *pp=LL;  // ָ��ppָ��ͷ��㣬�������ƶ������Ϊ�գ���ʾ����û����ˡ�
  int kk=0;      // kkָ����ǵڼ�����㣬��ͷ���0��ʼ��ppÿ����ƶ�һ�Σ�kk�ͼ�1��

  while ( (pp != NULL) && (kk < ii) )
  { 
    pp=pp->next; kk++; 
  }

  if ( pp==NULL ) { printf("λ�ã�%d�����Ϸ��������˱���\n",ii); return NULL; }

  return pp;
}

// ����Ԫ��ee������LL�еĽ���ַ�����û�ҵ�����NULL�����򷵻ؽ��ĵ�ַ��
LNode *LocateElem(LinkList LL, ElemType *ee)
{
  LNode *pp=LL->next;  // �ӵ�1�����ݽ�㿪ʼ��

  while (pp != NULL)
  {
    // �������Ԫ���ǽṹ�壬���´���Ҫ�޸ġ�
    if (pp->data == *ee) return pp;

    pp = pp->next;
  }

  return NULL;
}

// ���ù鲢�ķ��������������������La��Lb���ϲ���һ�����������Lc��
int MergeList(LinkList La,LinkList Lb,LinkList Lc)
{
  if ( (La == NULL) || (Lb == NULL) || (Lc == NULL) ) { printf("��La��Lb��Lc������һ�������ڡ�\n"); return 0; }

  La=La->next;
  Lb=Lb->next;

  LNode *pp;

  // ��La��Lb�ϲ���Lc�С�
  while ( (La != NULL) && (Lb != NULL) )
  {
    // ȡLa��Lb�Ľ�С�ߡ�
    if (La->data <= Lb->data)
    {
      pp=La; La=La->next;
    }
    else
    {
      pp=Lb; Lb=Lb->next;
    }

    // �ѽ�С��׷�ӵ�Lc�С�
    Lc->next=(LNode *)malloc(sizeof(LNode));  // ����һ���½�㡣
    Lc=Lc->next;
    memcpy(&Lc->data,&pp->data,sizeof(ElemType));
    Lc->next=NULL;
  }

  // ������La������Ԫ��׷�ӵ�Lc�С�
  while (La != NULL)
  {
    Lc->next=(LNode *)malloc(sizeof(LNode));  // ����һ���½�㡣
    Lc=Lc->next;
    memcpy(&Lc->data,&La->data,sizeof(ElemType));
    Lc->next=NULL;
    La=La->next;
  }
    
  // ������Lb������Ԫ��׷�ӵ�Lc�С�
  while (Lb != NULL)
  {
    Lc->next=(LNode *)malloc(sizeof(LNode));  // ����һ���½�㡣
    Lc=Lc->next;
    memcpy(&Lc->data,&Lb->data,sizeof(ElemType));
    Lc->next=NULL;
    Lb=Lb->next;
  }

  return 1;
}

// ��ָ�����pp֮�����Ԫ��ee������ֵ��0-ʧ�ܣ�1-�ɹ���
int InsertNextNode(LNode *pp, ElemType *ee)
{
  if (pp == NULL) { printf("���pp�����ڡ�\n"); return 0; }

  LNode *tmp = (LNode *)malloc(sizeof(LNode));
  if (tmp == NULL) return 0;

  memcpy(&tmp->data,ee,sizeof(ElemType));
  tmp->next=pp->next;
  pp->next=tmp;

  return 1;
}

// ��ָ�����pp֮ǰ����Ԫ��ee������ֵ��0-ʧ�ܣ�1-�ɹ���
int InsertPriorNode(LNode *pp, ElemType *ee)
{
  if (pp == NULL) { printf("���pp�����ڡ�\n"); return 0; }

  // ��ָ�����pp֮ǰ�������͵�������ķ�����
  // 1������һ���µĽ�㣻
  // 2����pp�������ݺ�ָ�븴�Ƶ��½���С�
  // 3���Ѵ�����Ԫ�ص����ݴ���pp����С�

  LNode *tmp = (LNode *)malloc(sizeof(LNode));
  if (tmp == NULL) return 0;

  // ��pp�������ݺ�ָ�븴�Ƶ�tmp�С�
  memcpy(&tmp->data,&pp->data,sizeof(ElemType));
  tmp->next=pp->next;

  // �Ѵ������Ԫ�ش���pp�С�
  memcpy(&pp->data,ee,sizeof(ElemType));
  pp->next=tmp;
  
  return 1;
}

// ɾ��ָ����㡣
int DeleteNode1(LNode *pp)
{
  if (pp == NULL) { printf("���pp�����ڡ�\n"); return 0; }

  // ɾ��ָ������˼���ǣ�1����pp��̽������ݺ�nextָ�븴�Ƶ�pp��㣻2��ɾ��pp���ĺ�̽�㡣
  LNode *tmp=pp->next;  // tmpָ��pp�ĺ�̽�㡣
  memcpy(&pp->data,&tmp->data,sizeof(ElemType)); // �Ѻ�̽������ݸ��Ƶ�pp����С�
  pp->next=tmp->next;   // ��pp��nextָ���̽���next��
  free(tmp);  // �ͷź�̽�㡣

  // д���������Ŀ���Ǹ��ߴ�����ַ�����������ġ�
  // ���⣺�����ǰ��pp�������������һ����㣬��ô���ĺ�̽����������ڡ�
  // ���ۣ��˷���ͨ�����ǹԹԵĴ�����ͷ����ʼɨ�衣

  return 1;
}

// ������pp���֮��Ľ��ԭ�����ã���ת��������ֵ��0-ʧ�ܣ�1-�ɹ���
void ReverseList(LNode *pp)
{
  LNode *ss;      // ��ǰ��㡣
  LNode *ssnext;  // ��ǰ������һ��㡣

  ss=pp->next;    // ��pp���֮��Ľ�㿪ʼ��ת��

  pp->next=NULL;  // pp->nextָ��ա�

  while (ss != NULL)
  {
    ssnext=ss->next;  // ����ss��һ���ĵ�ַ��

    // ���������൱����pp֮�����ss��㡣
    ss->next=pp->next;  
    pp->next=ss;

    ss=ssnext;  // ss�����ơ�
  }
}

// �����ӡ������ȫ����Ԫ�ء�
void PrintList1(LNode *pp)
{
  if (pp == NULL) return;

  PrintList1(pp->next);

  printf("%-3d", pp->data);  

  return;
}

// �ҳ���ͷ���ĵ���������k(k>0)����㡣
LNode *FindKNode(LinkList LL,unsigned int kk)
{
  LNode *pp1=LL->next;
  LNode *pp2=LL->next;

  int ii=1;

  // ��pp1����kk���ڵ㡣
  while ( (pp1!=NULL) && (ii<kk) )
  {
    pp1=pp1->next; ii++;
  }
    
  if (pp1 == NULL) return NULL;

  // Ȼ��pp1�����ܵ�β��pp2Ҳ��ʼ�ܡ�
  while (1)
  {
    pp1=pp1->next; 
    if (pp1 == NULL) break;
    pp2=pp2->next;
  }
  
  return pp2;
}

// �жϵ������Ƿ��л������ҵ�������ڡ�
LNode *FindLoop(LinkList LL)
{
  LNode *fast=LL,*slow=LL;  // ���ÿ���ָ�롣

  while ( (fast != NULL) && (fast->next != NULL) ) // ��ֹ����û��������ָ��������
  {
    // ��ָ����һ������ָ����������
    slow=slow->next;
    fast=fast->next->next;

    if (slow == fast) break;
  }

  // �����ָ�����ܵ�ͷ����ʾû����
  if ( (fast==NULL) || (fast->next==NULL) ) return NULL;

  // �ҵ�������ڡ�
  LNode *p1=LL,*p2=slow;
  while (p1 != p2)
  {
    p1=p1->next; p2=p2->next;
  }

  return p1;
}

// �ҳ�������۵�����Ĺ�����㣬���û�л�ۣ����ؿգ�����У����ػ�۵ĵ�һ����㡣
LNode *FindJoin(LinkList La,LinkList Lb)
{
  int lalen=LengthList(La); // �õ�La�ĳ��ȡ�
  int lblen=LengthList(Lb); // �õ�Lb�ĳ��ȡ�

  LNode *pa,*pb;
  
  // ���La������La����lalen-lblen����
  for (pa=La;lblen<lalen;lalen--)
    pa=pa->next;

  // ���Lb������Lb����lblen-lalen����
  for (pb=Lb;lalen<lblen;lblen--)
    pb=pb->next;

  // Ȼ��La��Lbһ���ߣ�����ַ��ͬ���ǻ�۵㡣
  while (1)
  {
    if (pa == pb) break;

    pa=pa->next; pb=pb->next;

    if (pa == NULL) return NULL;   // �ܵ�ͷ�˻�û����ͬ�ĵ�ַ����ʾû�л�ۡ�
  }
  
  return pa;  // ���ػ�۵ĵ�һ�����ĵ�ַ��
}

// �������Ա�L=(a1,a2,a3,...,an-2,an-1,an)���ô�ͷ���ĵ������棬���ݽ��ĸ���Ϊż����
// �����һ���ռ临�Ӷ�ΪO(1)��ʱ���Ͼ����ܸ�Ч���㷨����������L�еĸ���㡣
// ���õ����Ա�L=(a1,an,a2,an-1,a3,an-2,...)��
void ReplaceList(LinkList LL)
{
  // ��1�����ҵ�������м��㡣
  LNode *fast=LL,*slow=LL;  // ���ÿ���ָ�롣

  while (fast->next != NULL) 
  {
    // ��ָ����һ������ָ����������
    slow=slow->next;
    fast=fast->next->next;  // ��Ϊ���ݽ��ĸ���Ϊż�����������ﲻ����ֲ�����ָ��������
    // printf("slow=%p,data=%d\n",slow,slow->data);
    // printf("fast=%p,data=%d\n",fast,fast->data);
  }

  // slowָ������ǰ������һ����㡣
  // printf("slow=%p,data=%d\n",slow,slow->data);

  // ��2����������ĺ���ԭ�����á�
  ReverseList(slow);

  // PrintList(LL);

  // ��3����������ĺ��β��뵽ǰ����С�
  LNode *n1=LL->next;    // n1Ϊǰ��ε�һ�����ݽ�㡣
  LNode *n2=slow->next;  // n2Ϊ���ε�һ�����ݽ�㡣

  slow->next=NULL;  // ���������־��
 
  LNode *tmp;

  while (n2 != NULL)
  {
    tmp=n2->next;      // ������һ���ĵ�ַ��
    n2->next=n1->next;
    n1->next=n2;
    n2=tmp;
    n1=n1->next->next; // n1������һ������λ�á�
  }
}

