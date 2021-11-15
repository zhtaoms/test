/*
 * ��������linklist5.c���˳�����ʾ��ͷ����ѭ���������ʵ�֣�����Ԫ����������
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

// ��������LL��
void DestroyList1(LinkList LL);

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
LNode *LocateNode(LinkList LL, unsigned int ii);

// ����Ԫ��ee������LL�еĽ���ַ�����û�ҵ�����NULL�����򷵻ؽ��ĵ�ַ��
LNode *LocateElem(LinkList LL, ElemType *ee);

// ��ָ�����pp֮�����Ԫ��ee������ֵ��0-ʧ�ܣ�1-�ɹ���
int InsertNextNode(LNode *pp, ElemType *ee);

// ��ָ�����pp֮ǰ����Ԫ��ee������ֵ��0-ʧ�ܣ�1-�ɹ���
int InsertPriorNode(LNode *pp, ElemType *ee);

int main()
{
  LinkList LL=NULL; // ��������ָ�������

  LL=InitList1();     // ��ʼ������

  printf("LL=%p\n",LL);

  ElemType ee;      // ����һ������Ԫ�ء�

  LNode *tmp1;

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

  printf("ɾ�����е�һ����㡣\n");
  PopFront(LL); PrintList(LL);

  printf("ɾ���������һ����㡣\n");
  PopBack(LL); PrintList(LL);

  LNode *tmp;

  if ( (tmp=LocateNode(LL,5)) != NULL)
    printf("��5�����ĵ�ַ��=%p��ee=%d\n",tmp,tmp->data);

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

  DestroyList1(LL); LL=NULL;  // ��������LL��Ϊ�ա�

  printf("LL=%p\n",LL);

  return 0;
}

// ��ʼ������LL������ֵ��ʧ�ܷ���NULL���ɹ�����ͷ���ĵ�ַ��
LNode *InitList1()
{
  LNode *head = (LNode *)malloc(sizeof(LNode));  // ����ͷ��㡣

  if (head == NULL) return NULL;  // �ڴ治�㣬����ʧ�ܡ�

  head->next=head;  // ͷ����nextָ��ָ���Լ��� // xxx

  return head;
}

// ��������LL��
void DestroyList1(LinkList LL)
{
  LNode *head=LL;  // ����ͷ���ĵ�ַ��

  LL=LL->next;  // �����ݽ�㿪ʼ��

  // �ͷ�����ȫ�������ݽ�㡣
  LNode *tmp;

  while(LL!=head)      // xxx
  {
    tmp=LL->next;  // tmp������һ���ĵ�ַ��
    free(LL);      // �ͷŵ�ǰ��㡣
    LL=tmp;        // LLָ���ƶ�����һ��㡣
  }

  free(head);  // ���ͷ�ͷ��㡣// xxx

  return;
}

// �������
void ClearList(LinkList LL)
{
  // �������LL��ָ�ͷ�����ȫ�������ݽ�㣬������ͷ��㡣
  if (LL == NULL) { printf("����LL�����ڡ�\n"); return; } // �ж������Ƿ���ڡ�

  LNode *tmp1;
  LNode *tmp2=LL->next;  // ����ͷ��㣬��ͷ������һ����㿪ʼ�ͷš�

  while(tmp2!=LL) // xxx
  {
    tmp1=tmp2->next;
    free(tmp2);
    tmp2=tmp1;
  }

  LL->next=LL; // ��ͷ����nextָ��ָ���Լ��� // xxx

  return;
}

// ������LL�ĵ�ii��λ�ò���Ԫ��ee������ֵ��0-ʧ�ܣ�1-�ɹ���
int InsertList(LinkList LL, unsigned int ii, ElemType *ee)
{
  if ( (LL == NULL) || (ee == NULL) ) { printf("����LL��Ԫ��ee�����ڡ�\n"); return 0; } // �жϱ��Ԫ���Ƿ���ڡ�

  // �жϲ���λ���Ƿ�Ϸ�
  if (ii < 1) { printf("����λ�ã�%d�����Ϸ���Ӧ���ڴ���0��\n",ii); return 0; }

  // Ҫ��λ��ii�����㣬�����ҵ�ii-1��㡣
  LNode *pp;

  if (ii == 1) 
  {
    pp=LL;  // ���ii==1���������ˣ�ii-1������ͷ��㡣
  }
  else
  {
    pp=LL->next;  // xxx ָ��ppָ��һ�����ݽ�㣬�������ƶ������ΪLL����ʾ����û����ˡ�
    int kk=1;     // kkָ����ǵڼ�����㣬ppÿ����ƶ�һ�Σ�kk�ͼ�1��

    while ( (pp != LL) && (kk < ii-1) )   // xxxx
    {
      pp=pp->next;    kk++;

      // printf("pp=%p,kk=%d\n",pp,kk);
    }

    if ( pp == LL ) { printf("λ�ã�%d�����Ϸ��������˱���\n",ii); return 0; }  // xxx
  }

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

  // Ҫ��λ��iiɾ����㣬�����ҵ�ii-1��㡣
  LNode *pp;

  if (ii == 1)
  {
    pp=LL;  // ���ii==1���������ˣ�ii-1������ͷ��㡣
  }
  else
  {
    pp=LL->next;  // xxx ָ��ppָ��һ�����ݽ�㣬�������ƶ������ΪLL����ʾ����û����ˡ�
    int kk=1;     // kkָ����ǵڼ�����㣬ppÿ����ƶ�һ�Σ�kk�ͼ�1��

    while ( (pp != LL) && (kk < ii-1) )   // xxxx
    {
      pp=pp->next;    kk++;

      // printf("pp=%p,kk=%d\n",pp,kk);
    }
  }

  if ( pp->next == LL ) { printf("λ�ã�%d�����Ϸ��������˱���\n",ii); return 0; }  // xxx

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
  while (pp->next != LL) pp=pp->next;   // xxx
  
  LNode *tmp = (LNode *)malloc(sizeof(LNode));  // ����һ����㡣
  if (tmp == NULL) return 0;  // �ڴ治�㣬����ʧ�ܡ�
  
  // ��������Ԫ��Ϊ�ṹ�����������������memcpy�ķ���������ֱ�Ӹ�ֵ��
  memcpy(&tmp->data,ee,sizeof(ElemType));

  // ����nextָ�롣
  pp->next=tmp;
  tmp->next=LL;   // xxx

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

  // �����������жϣ��ձ�
  if ( LL->next == LL) { printf("����LLΪ�գ�û��β��㡣\n"); return 0; } // �жϱ��Ƿ�Ϊ�ա� // xxx

  // Ҫɾ�����һ����㣬�����ҵ����һ������ǰһ����㡣

  LNode *pp=LL;  // �ӵ�0����㿪ʼ��   // xxx

  // �ҵ������ڶ�����㣨����ͷ��㣩��
  while (pp->next->next != LL) pp=pp->next;
 
  // �ͷ����һ����㡣
  free(pp->next);
  pp->next=LL;   // xxx

  return 1;
}

// ��ӡ������ȫ����Ԫ�ء�
void PrintList(LinkList LL)
{
  if (LL == NULL) { printf("����LL�����ڡ�\n"); return; } // �ж������Ƿ���ڡ�

  LNode *pp=LL->next;  // �ӵ�1����㿪ʼ��

  while (pp != LL)   //  xxxxx
  {
    printf("%-3d", pp->data);  // ���Ԫ��eeΪ�ṹ�壬���д���Ҫ�޸ġ�
    pp=pp->next;
  }

  printf("\n");

  /*
  // ���´���������ʾȫ�����ݽ��ĵ�ַ��Ԫ�ص�ֵ��
  LNode *pp=LL->next;  // �ӵ�1����㿪ʼ��

  printf("%p,%p\n",LL,LL->next);  // ��ʾͷ����ָ��ֵ��

  while (pp != LL)
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

  while (pp != LL) { pp=pp->next; length++; } // xxxxx

  return length;

  // ��ʹ����ʱ��������μ�����������ͷ��㣩�ĳ��ȣ�
  // if (LL==NULL) return 0;
  // return LengthList(LL->next)+1;
}

// �ж������Ƿ�Ϊ�գ�����ֵ��0-�ǿջ�ʧ�ܣ�1-�ա�
int IsEmpty(LinkList LL)
{
  if (LL == NULL) return 0;

  if (LL->next == LL) return 1; // xxxx

  return 0;
}

// ��ȡ�����е�ii����㣬�ɹ����ؽ��ĵ�ַ��ʧ�ܷ��ؿա�
// ע�⣬ii����ȡֵΪ0����ʾͷ��㡣
LNode *LocateNode(LinkList LL, unsigned int ii)
{
  if ( LL == NULL ) { printf("����LL�����ڡ�\n"); return NULL; } // �жϱ��Ԫ���Ƿ���ڡ�

  if (ii == 0) return LL;  // ֱ�ӷ���ͷ��㡣
  
  LNode *pp=LL->next;  // ָ��ppָ���һ�����ݽ�㣬�������ƶ������Ϊ�գ���ʾ����û����ˡ� // xxx
  int kk=1;      // kkָ����ǵڼ�����㣬�����ݽ�㿪ʼ��ppÿ����ƶ�һ�Σ�kk�ͼ�1��

  while ( (pp != LL) && (kk < ii) )
  { 
    pp=pp->next; kk++; 
  }

  if ( pp==LL ) { printf("λ�ã�%d�����Ϸ��������˱���\n",ii); return NULL; }  // xxx

  return pp;
}

// ����Ԫ��ee������LL�еĽ���ַ�����û�ҵ�����NULL�����򷵻ؽ��ĵ�ַ��
LNode *LocateElem(LinkList LL, ElemType *ee)
{
  LNode *pp=LL->next;  // �ӵ�1�����ݽ�㿪ʼ��

  while (pp != LL)  // xxxx
  {
    // �������Ԫ���ǽṹ�壬���´���Ҫ�޸ġ�
    if (pp->data == *ee) return pp;

    pp = pp->next;
  }

  return NULL;
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


