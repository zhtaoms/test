/*
 * ��������linklist3.c����ʾ����ͷ���ĵ������ʵ�֣�ֻʵ���˲��ֹ��ܡ�
 * ���ߣ�C���Լ�����(www.freecplus.net) ���ڣ�20201230
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int ElemType;        

typedef struct LNode
{
  ElemType data;       // ��Ž�������Ԫ�ء�
  struct LNode *next;  // ָ����һ������ָ�롣
}LNode,*LinkList;

// ��������LL��
void DestroyList(LinkList &LL);

// �������
void ClearList(LinkList &LL);                    

// ������LL�ĵ�ii��λ�ò���Ԫ��ee������ֵ��0-ʧ�ܣ�1-�ɹ���
int  InsertList(LinkList &LL, unsigned int ii, ElemType *ee);   

// ��ӡ������ȫ����Ԫ�ء�
void PrintList(LinkList LL);                    

// ������LL��ͷ������Ԫ��ee������ֵ��0-ʧ�ܣ�1-�ɹ���
int  PushFront(LinkList &LL, ElemType *ee);

// ������LL��β������Ԫ��ee������ֵ��0-ʧ�ܣ�1-�ɹ���
int  PushBack(LinkList &LL, ElemType *ee);

// ɾ������LL�еĵ�ii����㣬����ֵ��0-λ��ii���Ϸ���1-�ɹ���
int  DeleteNode(LinkList LL, unsigned int ii);  

// ɾ������LL�е�һ����㣬����ֵ��0-λ�ò��Ϸ���1-�ɹ���
int PopFront(LinkList LL);

// ɾ������LL�����һ����㣬����ֵ��0-λ�ò��Ϸ���1-�ɹ���
int PopBack(LinkList &LL);

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

int main()
{
  // ����ͷ��������ֱ�Ӹ��վͿ����ˡ�
  LinkList LL=NULL; // ��������ָ�������

  ElemType ee;      // ����һ������Ԫ�ء�

  printf("�ڱ��в���Ԫ�أ�1��2��3��4��5��6��7��8��9��10����\n");
  ee=1;   InsertList(LL, 1, &ee);
  ee=2;   InsertList(LL, 1, &ee);
  ee=3;   InsertList(LL, 1, &ee);
  ee=4;   InsertList(LL, 1, &ee);
  ee=5;   InsertList(LL, 1, &ee);
  ee=6;   InsertList(LL, 1, &ee);
  ee=7;   InsertList(LL, 1, &ee);
  ee=8;   InsertList(LL, 1, &ee);
  ee=9;   InsertList(LL, 1, &ee);
  ee=10;  InsertList(LL, 1, &ee);

  printf("length=%d\n",LengthList(LL));

  PrintList(LL);

  printf("�ڵ�5��λ�ò���Ԫ�أ�13����\n");
  memset(&ee,0,sizeof(ElemType)); ee=13; InsertList(LL, 5, &ee);  

  PrintList(LL);

  printf("�ڱ�ͷ����Ԫ�أ�11������β����Ԫ�أ�12����\n");
  memset(&ee,0,sizeof(ElemType)); ee=11; PushFront(LL, &ee);
  memset(&ee,0,sizeof(ElemType)); ee=12; PushBack(LL, &ee);

  PrintList(LL);

  // ����Ĵ��벻Ҫ���ã���û�и��ꡣ
  /*
  printf("ɾ�����е�7����㡣\n");
  DeleteNode(LL,7); PrintList(LL);

  printf("ɾ�����е�һ����㡣\n");
  PopFront(LL); PrintList(LL);

  printf("ɾ���������һ����㡣\n");
  PopBack(LL); PrintList(LL);

  LNode *tmp;

  if ( (tmp=LocateNode(LL,3)) != NULL)
    printf("��3�����ĵ�ַ��=%p��ee.no=%d\n",tmp,tmp->data.no);

  memset(&ee,0,sizeof(ElemType)); ee.no=8;
  if ( (tmp=LocateElem(LL,&ee)) != NULL)
    printf("Ԫ��ֵΪ8�Ľ��ĵ�ַ��=%p\n",tmp);
  else
    printf("Ԫ��ֵΪ8�Ľ��ĵ�ַ��NULL��û���š�\n");

  printf("�ڽ��%p֮�����66\n",tmp);
  memset(&ee,0,sizeof(ElemType)); ee.no=66;
  InsertNextNode(tmp,&ee);  PrintList(LL);

  printf("�ڽ��%p֮ǰ����55\n",tmp);
  memset(&ee,0,sizeof(ElemType)); ee.no=55;
  InsertPriorNode(tmp,&ee);  PrintList(LL);
  */

  DestroyList(LL); // ��������

  return 0;
}

// ��������LL��
void DestroyList(LinkList &LL)
{
  // ��������LL��ָ�ͷ�����ȫ���Ľ�㡣
  LNode *tmp;

  while(LL!=NULL)
  {
    tmp=LL->next;  // tmp������һ���ĵ�ַ��
    free(LL);      // �ͷŵ�ǰ��㡣
    LL=tmp;        // LLָ���ƶ�����һ��㡣
  }

  LL=NULL; 

  return;
}

// �������
void ClearList(LinkList &LL)
{
  // �������LL��ָ�ͷ�����ȫ���Ľ�㣬��������һ���ġ�
  return DestroyList(LL);
}

// ������LL�ĵ�ii��λ�ò���Ԫ��ee������ֵ��0-ʧ�ܣ�1-�ɹ���
int InsertList(LinkList &LL, unsigned int ii, ElemType *ee)
{
  if (ee == NULL) { printf("Ԫ��ee�����ڡ�\n"); return 0; } // �жϱ��Ԫ���Ƿ���ڡ�

  // �жϲ���λ���Ƿ�Ϸ�
  if (ii < 1) { printf("����λ�ã�%d�����Ϸ���Ӧ���ڴ���0��\n",ii); return 0; }

  // �������Ϊ�գ�������һ����㡣
  if (LL == NULL)
  {
    LL = (LNode *)malloc(sizeof(LNode));

    memcpy(&LL->data,ee,sizeof(ElemType));  // �������ݵ�����С�
    LL->next=NULL; // ����nextָ�롣

    return 1;
  }

  // ��������λ����1������������ͷ�����룬ÿ����һ�Σ�����LLָ��ĵ�ַҲҪ�ı䡣
  if (ii == 1)
  {
    LNode *tmp = (LNode *)malloc(sizeof(LNode));  // ����һ����㡣
  
    memcpy(&tmp->data,ee,sizeof(ElemType));
    tmp->next=LL;
  
    LL=tmp;

    return 1;
  }

  // Ҫ��λ��ii�����㣬�����ҵ�ii-1��㡣
  LNode *pp=LL;
  int kk=1;

  while ( (pp != NULL) && (kk < ii-1) )
  {
    pp=pp->next; kk++;
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
}

// ɾ������LL�еĵ�ii����㣬����ֵ��0-λ��ii���Ϸ���1-�ɹ���
int  DeleteNode(LinkList LL, unsigned int ii)  
{
  if (LL == NULL) { printf("����L�����ڡ�\n"); return 0; } // �ж������Ƿ���ڡ�

  // �жϲ���λ���Ƿ�Ϸ�
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
int  PushFront(LinkList &LL, ElemType *ee)
{
  return InsertList(LL,1,ee);
}

// ������LL��β������Ԫ��ee������ֵ��0-ʧ�ܣ�1-�ɹ���
int PushBack(LinkList &LL, ElemType *ee)
{
  if (ee == NULL) { printf("Ԫ��ee�����ڡ�\n"); return 0; } // �жϱ��Ԫ���Ƿ���ڡ�

  if (LL == NULL) { InsertList(LL,1,ee);  return 1; }

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

  LNode *pp=LL;  // �ӵ�1����㿪ʼ��

  printf("LL=%p ",LL);

  while (pp != NULL)
  {
    printf("%-3d", pp->data);  
    pp=pp->next;
  }

  printf("\n");
}

// ������ĳ��ȣ�����ֵ��>=0-��LL���ĸ�����
int  LengthList(LinkList LL)
{
  if (LL == NULL) { printf("����LL�����ڡ�\n"); return 0; } // �ж������Ƿ���ڡ�

  LNode *pp=LL;  

  int length=0;

  while (pp != NULL) { pp=pp->next; length++; }

  return length;
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

