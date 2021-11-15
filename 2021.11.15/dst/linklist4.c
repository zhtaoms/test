/*
 * ��������linklist4.c���˳�����ʾ��ͷ����˫�����ʵ�֣�����Ԫ����������
 * ���ߣ�C���Լ�����(www.freecplus.net) ���ڣ�20201230
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int ElemType;     // �Զ������������Ԫ��Ϊ������

typedef struct DNode
{
  ElemType data;          // ��Ž�������Ԫ�ء�
  struct DNode *prior,*next;  // ǰ���ͺ�̽���ָ�롣
}DNode,*LinkList;

// ��ʼ������LL������ֵ��ʧ�ܷ���NULL���ɹ�����ͷ���ĵ�ַ��
DNode *InitList1();

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
DNode *LocateNode(LinkList LL, unsigned int ii);

// ����Ԫ��ee������LL�еĽ���ַ�����û�ҵ�����NULL�����򷵻ؽ��ĵ�ַ��
DNode *LocateElem(LinkList LL, ElemType *ee);

// ��ָ�����pp֮�����Ԫ��ee������ֵ��0-ʧ�ܣ�1-�ɹ���
int InsertNextNode(DNode *pp, ElemType *ee);

// ��ָ�����pp֮ǰ����Ԫ��ee������ֵ��0-ʧ�ܣ�1-�ɹ���
int InsertPriorNode(DNode *pp, ElemType *ee);

// ɾ��ָ����㡣
int DeleteNode1(DNode *pp);

int main()
{
  LinkList LL=NULL; // ��������ָ�������

  LL=InitList1();     // ��ʼ������

  // ���Ҫ�ں����жԱ������и�ֵ������ѱ����ĵ�ַ���뺯����
  // ָ��������ָ�룬���Ҫ�ں����ж�ָ�������ֵ��Ҳ�����ָ��ĵ�ַ���뺯����
  // LL��ָ�룬��InitList2�����У���Ҫ��ͷ���ĵ�ַ��ֵ��LL������Ҫ����LL�ĵ�ַ��
  // ָ���Ǳ��������ڴ�ű����ĵ�ַ��ָ�벻�ǵ�ַ��ָ�����ŵ����ݲ��ǵ�ַ��
  // ���ԣ�����Ҫ��ָ�����LL�ĵ�ַ����InitList2()������
  // ��λ�˼�����������
  // InitList2(&LL);     // ��ʼ����������ָ�����LL�ĵ�ַ��

  // InitList3(LL);      // ��ʼ������C++�����á�

  // �����������תָ��LL��ֵ��LL��ֵֻ�ܴ���ȥ���޷����أ����ַ����ǲ��еġ�
  // InitList4(LL);

  printf("LL=%p\n",LL);

  ElemType ee;      // ����һ������Ԫ�ء�

  printf("�ڱ��в���Ԫ�أ�1��2��3��4��5��6��7��8��9��10����\n");
  ee=1;  InsertList(LL, 1, &ee);
  ee=2;  InsertList(LL, 1, &ee);
  ee=3;  InsertList(LL, 1, &ee);
  ee=4;  InsertList(LL, 1, &ee);
  ee=5;  InsertList(LL, 1, &ee);
  ee=6;  InsertList(LL, 1, &ee);
  ee=7;  InsertList(LL, 1, &ee);
  ee=8;  InsertList(LL, 1, &ee);
  ee=9;  InsertList(LL, 1, &ee);
  ee=10; InsertList(LL, 1, &ee);

  printf("length=%d\n",LengthList(LL));

  PrintList(LL);

  printf("�ڵ�5��λ�ò���Ԫ�أ�13����\n");
  ee=13; InsertList(LL, 5, &ee);  

  PrintList(LL);

  printf("�ڱ�ͷ����Ԫ�أ�11������β����Ԫ�أ�12����\n");
  ee=11; PushFront(LL, &ee);
  ee=12; PushBack(LL, &ee);

  PrintList(LL);
  
  printf("ɾ�����е�7����㡣\n");
  DeleteNode(LL,7); PrintList(LL);

  printf("ɾ�����е�һ����㡣\n");
  PopFront(LL); PrintList(LL);

  DNode *tmp;

  if ( (tmp=LocateNode(LL,3)) != NULL)
    printf("��3�����ĵ�ַ��=%p��ee=%d\n",tmp,tmp->data);

  ee=8;
  if ( (tmp=LocateElem(LL,&ee)) != NULL)
    printf("Ԫ��ֵΪ8�Ľ��ĵ�ַ��=%p\n",tmp);
  else
    printf("Ԫ��ֵΪ8�Ľ��ĵ�ַ��NULL��û���š�\n");

  printf("�ڽ��%p֮�����66\n",tmp);
  ee=66;
  InsertNextNode(tmp,&ee);  PrintList(LL);

  printf("�ڽ��%p֮ǰ����55\n",tmp);
  ee=55;
  InsertPriorNode(tmp,&ee);  PrintList(LL);

  // �ҵ���10���ڵ㲢ɾ������
  if ( (tmp=LocateNode(LL,10)) != NULL)
    printf("��10�����ĵ�ַ��=%p��ee=%d\n",tmp,tmp->data);

  printf("ɾ�����%p\n",tmp);
  DeleteNode1(tmp);  PrintList(LL);

  DestroyList1(LL); LL=NULL;  // ��������LL��Ϊ�ա�
  // DestroyList2(&LL);       // ������������ָ��ĵ�ַ��LL�ں����л���Ϊ�ա�
  // DestroyList3(LL);       // ��������C++�����ã�LL�ں����л���Ϊ�ա�

  printf("LL=%p\n",LL);

  return 0;
}

// �����������תָ��LL��ֵ��LL��ֵֻ�ܴ���ȥ���޷����أ����ַ����ǲ��еġ�
int InitList4(LinkList LL)
{
  DNode *head = (DNode *)malloc(sizeof(DNode));  // ����ͷ��㡣

  if (head == NULL) return 0;  // �ڴ治�㣬����ʧ�ܡ�

  head->next=NULL;  // ͷ������һ�����ʱ�����ڣ��ÿա�

  LL=head;

  printf("LL1=%p\n",LL);

  return 1;
}

// ��ʼ������LL������ֵ��ʧ�ܷ���NULL���ɹ�����ͷ���ĵ�ַ��
DNode *InitList1()
{
  DNode *head = (DNode *)malloc(sizeof(DNode));  // ����ͷ��㡣

  if (head == NULL) return NULL;  // �ڴ治�㣬����ʧ�ܡ�

  head->prior=head->next=NULL;    // ǰ����̽�㶼��Ϊ�ա�

  return head;
}

// ����ָ������ĵ�ַ�ķ�����
// ��ʼ����������ֵ��0-ʧ�ܣ�1-�ɹ���
int InitList2(LinkList *LL)
{
  // �ڱ������У�LL��ָ���ָ�룬���ڴ��ָ��ĵ�ַ��

  if ( *LL != NULL ) { printf("����LL�Ѵ��ڣ��ڳ�ʼ��֮ǰ�����ͷ�����\n"); return 0; }

  DNode *head = (DNode *)malloc(sizeof(DNode));  // ����ͷ��㡣

  if (head == NULL) return 0;  // �ڴ治�㣬����ʧ�ܡ�

  head->prior=head->next=NULL;    // ǰ����̽�㶼��Ϊ�ա�

  *LL=head;

  return 1;
}

/*
// C++���õķ�����
// ��ʼ����������ֵ��0-ʧ�ܣ�1-�ɹ���
int InitList3(LinkList &LL)
{
  if ( LL != NULL ) { printf("����L�Ѵ��ڣ��ڳ�ʼ��֮ǰ�����ͷ�����\n"); return 0; }

  DNode *head = (DNode *)malloc(sizeof(DNode));  // ����ͷ��㡣

  if (head == NULL) return 0;  // �ڴ治�㣬����ʧ�ܡ�

  head->prior=head->next=NULL;    // ǰ����̽�㶼��Ϊ�ա�

  LL=head;

  return 1;
}
*/

// ��������LL��
void DestroyList1(LinkList LL)
{
  // ��������LL��ָ�ͷ�����ȫ���Ľ�㣬����ͷ��㡣
  DNode *tmp;

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
  DNode *tmp1,*tmp2;

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
  DNode *tmp;

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

  DNode *tmp1;
  DNode *tmp2=LL->next;  // ����ͷ��㣬��ͷ������һ����㿪ʼ�ͷš�

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
  DNode *pp=LL;  // ָ��ppָ��ͷ��㣬�������ƶ������Ϊ�գ���ʾ����û����ˡ�
  int kk=0;      // kkָ����ǵڼ�����㣬��ͷ���0��ʼ��ppÿ����ƶ�һ�Σ�kk�ͼ�1��

  while ( (pp != NULL) && (kk < ii-1) )
  {
    pp=pp->next; kk++;

    // printf("pp=%p,kk=%d\n",pp,kk);
  }

  if ( pp==NULL ) { printf("λ�ã�%d�����Ϸ��������˱���\n",ii); return 0; }

  DNode *tmp = (DNode *)malloc(sizeof(DNode));  // ����һ����㡣
  if (tmp == NULL) return 0;  // �ڴ治�㣬����ʧ�ܡ�
  
  // ��������Ԫ��Ϊ�ṹ�����������������memcpy�ķ���������ֱ�Ӹ�ֵ��
  memcpy(&tmp->data,ee,sizeof(ElemType));

  // ����ǰ����������ָ�롣
  tmp->next=pp->next;
  tmp->prior=pp;
  if (tmp->next != NULL) tmp->next->prior=tmp;  // ���⴦���������β�����룬tmp->next���������ڡ�
  pp->next=tmp;

  return 1;

  ///////////////////////////////////////
  // ���ϴ�����������´�����档
  // DNode *pp=LocateNode(LL,ii-1);  
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
  DNode *pp=LL;  // ָ��ppָ��ͷ��㣬�������ƶ������Ϊ�գ���ʾ����û����ˡ�
  int kk=0;      // kkָ����ǵڼ�����㣬��ͷ���0��ʼ��ppÿ����ƶ�һ�Σ�kk�ͼ�1��

  while ( (pp != NULL) && (kk < ii-1) )
  {
    pp=pp->next; kk++;
  }

  // ע�⣬�����еĴ�������Ƶ�еĲ�һ������Ƶ�е��� if ( pp==NULL )����bug��
  if ( pp->next==NULL ) { printf("λ�ã�%d�����Ϸ��������˱���\n",ii); return 0; }

  DNode *tmp=pp->next;  // tmpΪ��Ҫɾ���Ľ�㡣

  // ����ǰ����������ָ�롣
  pp->next=tmp->next;
  if (tmp->next != NULL) tmp->next->prior=pp; // ���⴦�����tmp��β��㣬tmp->next���������ڡ�

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

  DNode *pp=LL;  // ��ͷ��㿪ʼ��

  // �ҵ����һ����㡣
  while (pp->next != NULL) pp=pp->next;
  
  DNode *tmp = (DNode *)malloc(sizeof(DNode));  // ����һ����㡣
  if (tmp == NULL) return 0;  // �ڴ治�㣬����ʧ�ܡ�
  
  // ��������Ԫ��Ϊ�ṹ�����������������memcpy�ķ���������ֱ�Ӹ�ֵ��
  memcpy(&tmp->data,ee,sizeof(ElemType));

  // ����ǰ����������ָ�롣
  tmp->next=pp->next;
  tmp->prior=pp;
  if (tmp->next != NULL) tmp->next->prior=tmp;  // ���⴦���������β�����룬tmp->next���������ڡ�
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

  // �����������жϣ���Ҫ��ɾ��ͷ��㡣
  if ( LL->next == NULL) { printf("����LLΪ�գ�û��β��㡣\n"); return 0; } // �жϱ��Ƿ�Ϊ�ա�

  // ����ǵ�����Ҫɾ�����һ����㣬�����ҵ����һ������ǰһ����㡣
  // �����˫����Ҫɾ�����һ����㣬�ҵ����һ���������һ������ǰһ����㶼���ԣ�������ʵ�����в�ͬ��

  DNode *pp=LL;  // �ӵ�0����㿪ʼ��

  // �ҵ����һ����㡣
  while (pp->next != NULL) pp=pp->next;
 
  pp->prior->next=NULL;  // �����һ���ڵ��ǰһ����nextָ����Ϊ�ա�

  // �ͷ����һ����㡣
  free(pp);

  return 1;
}

// ��ӡ������ȫ����Ԫ�ء�
void PrintList(LinkList LL)
{
  if (LL == NULL) { printf("����LL�����ڡ�\n"); return; } // �ж������Ƿ���ڡ�

  DNode *pp=LL->next;  // �ӵ�1����㿪ʼ��

  while (pp != NULL)
  {
    printf("%-3d", pp->data);  // ���Ԫ��eeΪ�ṹ�壬���д���Ҫ�޸ġ�
    pp=pp->next;
  }

  printf("\n");

/*
  // ���´���������ʾȫ�����ĵ�ַ��Ԫ�ص�ֵ��
  DNode *pp=LL;  // �ӵ�0����㿪ʼ��

  while (pp != NULL)
  {
    printf("pp=%p,prior=%p,next=%p,data=%-3d\n",pp,pp->prior,pp->next,pp->data);  
    pp=pp->next;
  }
*/
}

// ������ĳ��ȣ�����ֵ��>=0-��LL���ĸ�����
int  LengthList(LinkList LL)
{
  if (LL == NULL) { printf("����LL�����ڡ�\n"); return 0; } // �ж������Ƿ���ڡ�

  DNode *pp=LL->next;  // ͷ��㲻�㣬�ӵ�1����㿪ʼ��

  int length=0;

  while (pp != NULL) { pp=pp->next; length++; }

  return length;

  // ��ʹ����ʱ��������μ�����������ͷ��㣩�ĳ��ȣ�
  // if (LL==NULL) return 0;
  // return LengthList(LL->next)+1;
}

// �ж������Ƿ�Ϊ�գ�����ֵ��0-�ǿջ�ʧ�ܣ�1-�ա�
int IsEmpty(LinkList LL)
{
  if (LL == NULL) return 0;

  if (LL->next == NULL) return 1;

  return 0;
}

// ��ȡ�����е�ii����㣬�ɹ����ؽ��ĵ�ַ��ʧ�ܷ��ؿա�
// ע�⣬ii����ȡֵΪ0����ʾͷ��㡣
DNode *LocateNode(LinkList LL, unsigned int ii)
{
  if ( LL == NULL ) { printf("����LL�����ڡ�\n"); return NULL; } // �жϱ��Ԫ���Ƿ���ڡ�
  
  DNode *pp=LL;  // ָ��ppָ��ͷ��㣬�������ƶ������Ϊ�գ���ʾ����û����ˡ�
  int kk=0;      // kkָ����ǵڼ�����㣬��ͷ���0��ʼ��ppÿ����ƶ�һ�Σ�kk�ͼ�1��

  while ( (pp != NULL) && (kk < ii) )
  { 
    pp=pp->next; kk++; 
  }

  if ( pp==NULL ) { printf("λ�ã�%d�����Ϸ��������˱���\n",ii); return NULL; }

  return pp;
}

// ����Ԫ��ee������LL�еĽ���ַ�����û�ҵ�����NULL�����򷵻ؽ��ĵ�ַ��
DNode *LocateElem(LinkList LL, ElemType *ee)
{
  DNode *pp=LL->next;  // �ӵ�1�����ݽ�㿪ʼ��

  while (pp != NULL)
  {
    // �������Ԫ���ǽṹ�壬���´���Ҫ�޸ġ�
    if (pp->data == *ee) return pp;

    pp = pp->next;
  }

  return NULL;
}

// ��ָ�����pp֮�����Ԫ��ee������ֵ��0-ʧ�ܣ�1-�ɹ���
int InsertNextNode(DNode *pp, ElemType *ee)
{
  if (pp == NULL) { printf("���pp�����ڡ�\n"); return 0; }

  DNode *tmp = (DNode *)malloc(sizeof(DNode));
  if (tmp == NULL) return 0;

  memcpy(&tmp->data,ee,sizeof(ElemType));

  // ����ǰ����������ָ�롣
  tmp->next=pp->next;
  tmp->prior=pp;
  if (tmp->next != NULL) tmp->next->prior=tmp;  // ���⴦���������β�����룬tmp->next���������ڡ�
  pp->next=tmp;

  return 1;
}

// ��ָ�����pp֮ǰ����Ԫ��ee������ֵ��0-ʧ�ܣ�1-�ɹ���
int InsertPriorNode(DNode *pp, ElemType *ee)
{
  if (pp == NULL) { printf("���pp�����ڡ�\n"); return 0; }

  // �ڵ������У����Ҫ��ָ�����pp֮ǰ����Ԫ�أ����õ���͵�������ķ�����
  // ��˫�����У�͵��͵���У���Ϊpp->prior��ǰ�����ĵ�ַ��

  DNode *tmp = (DNode *)malloc(sizeof(DNode));
  if (tmp == NULL) return 0;

  // �Ѵ������Ԫ�ش���tmp�С�
  memcpy(&tmp->data,ee,sizeof(ElemType));

  // ����ǰ�����ָ�롣
  tmp->prior=pp->prior;
  pp->prior->next=tmp;

  tmp->next=pp;
  pp->prior=tmp;

  return 1;
}

// ɾ��ָ����㡣
int DeleteNode1(DNode *pp)
{
  if (pp == NULL) { printf("���pp�����ڡ�\n"); return 0; }

  // �ڵ������У�ɾ��ָ�������������У�Ҳ���ܲ���͵�������ķ�����
  // ���ǣ���˫�����У�ɾ��ָ������ǿ��еġ�
  
  pp->prior->next=pp->next;
  if (pp->next != NULL) pp->next->prior=pp->prior;  // ���⴦�����pp��β��㣬pp->next->prior���������ڡ�

  free(pp);

  return 1;
}

