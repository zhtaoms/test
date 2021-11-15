/*
 * ��������hash.c���˳�����ʾ��ϣ���ʵ�֣�����Ԫ�ص������ͷ��㡣
 * ���ߣ�C���Լ�����(www.freecplus.net) ���ڣ�20210401
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ��ϣ��������Ԫ�صĽṹ�塣
typedef struct Element
{
  unsigned int key; // �ؼ��֡�
  int value;        // ����Ԫ����������������������������͡�
  // char value[1001];        // ����Ԫ����������������������������͡�
}Element;

// ����Ԫ�ص�����
typedef struct Node
{
  Element elem;      // ����Ԫ�ء�
  struct Node *next; // nextָ�롣
}Node;

// ��ϣ��
typedef struct HashTable
{
  struct Node *head;  // ����Ԫ�ش洢��ַ����̬�������顣
  int tablesize;      // ��ϣ��ǰ��С��������
  int count;          // ��ϣ��������Ԫ�صĸ�����
}HashTable;

// ��ʼ����ϣ��tablesizeΪ��ϣ��ı������ع�ϣ��ĵ�ַ��
HashTable *InitHashTable(const unsigned int tablesize)
{
  // �����ϣ��
  HashTable *hh=(HashTable *)malloc(sizeof(HashTable));

  hh->tablesize=tablesize;  // ��ϣ����

  // ����ͳ�ʼ������Ԫ�ص������ͷ��㡣
  hh->head=(Node *)malloc((hh->tablesize)*sizeof(Node));
  memset(hh->head,0,(hh->tablesize)*sizeof(Node));

  hh->count=0;  // ��ϣ��������Ԫ�ظ�����Ϊ0��

  return hh;
}

// ��ϣ������
unsigned int Hash(HashTable *hh,unsigned int key)
{
  return key%hh->tablesize;  // �Ա�ȡ�ࡣ
}

// �ڹ�ϣ���в��ҹؼ��֣��ɹ����ص�������ĵ�ַ��ʧ�ܷ��ؿա�
Node *LookUp(HashTable *hh,unsigned int key)
{
  int ii;

  ii=Hash(hh,key);  // ��ȡ�ؼ�key�Ĺ�ϣ��ַ��

  Node *pp=hh->head[ii].next;

  // ����������
  while( (pp!=NULL) && (pp->elem.key!=key) )
  {
    pp=pp->next;
  }

  return pp;
}

// �ӹ�ϣ����ɾ���ؼ��������ݣ��ɹ�����1������ؼ��ֲ����ڷ���0��
int Delete(HashTable *hh,unsigned int key)
{
  int ii;

  ii=Hash(hh,key);  // ��ȡ�ؼ�key�Ĺ�ϣ��ַ��

  Node *pp=&hh->head[ii];

  // ����������ppָ��ͣ���ڴ�ɾ���ؼ�key��ǰһ��㡣
  while( (pp->next!=NULL) && (pp->next->elem.key!=key) )
  {
    pp=pp->next;
  }

  if (pp->next==NULL) return 0;  // ����ʧ�ܡ�

  Node *tmp=pp->next;        // tmpΪ��Ҫɾ���Ľ�㡣
  pp->next=pp->next->next;   // д��p->next=tmp->next����ࡣ

  free(tmp);     // �ͷŽ�㡣

  hh->count--;   // ����Ԫ�ظ�����1��

  return 1;
}

// ���ϣ���в�������Ԫ�أ��ɹ�����1���������Ԫ�عؼ����Ѵ��ڣ�����0��
int Insert(HashTable *hh,Element *ee)
{
  // ���ҹؼ����Ƿ��Ѵ��ڣ�������ڣ�����ʧ�ܡ�
  Node *pp=LookUp(hh,ee->key);

  if (pp!=NULL) { printf("�ؼ���%d�Ѵ��ڡ�\n",ee->key); return 0; }
  
  Node *qq=(Node *)malloc(sizeof(Node));

  memcpy(&qq->elem,ee,sizeof(Element));

  // ��ͷ�巨����������Ԫ�ء�
  int ii=Hash(hh,ee->key);
  qq->next=hh->head[ii].next;
  hh->head[ii].next=qq;
  
  hh->count++;   // ����Ԫ�ظ�����1��

  return 1;
}

// ���ٹ�ϣ��
void FreeHashTable(HashTable *hh)
{
  int ii;

  Node *pp,*qq;

  // �ͷ�ȫ���ĵ�����
  for(ii=0;ii<hh->tablesize;ii++)
  {
    pp=hh->head[ii].next;
    while(pp)
    {
      qq=pp->next;
      free(pp);
      pp=qq;
    }
  }

  // �ͷ�ȫ���������ͷ������顣
  free(hh->head);

  free(hh);  // �ͷŹ�ϣ��
}

// ��ӡ��ϣ��
void PrintTable(HashTable *hh)
{
  int ii; 

  for (ii=0;ii<hh->tablesize;ii++)
  {
    Node *pp=hh->head[ii].next;
    while (pp)
    {
      printf("[%d-%d] ",pp->elem.key,pp->elem.value);
      // printf("[%d-%s] ",pp->elem.key,pp->elem.value);
      pp=pp->next;
    }

    printf("^\n");
  }

  printf("\n");
}

int main()
{
  // ��ʼ����ϣ��
  HashTable *hh=InitHashTable(10);

  Element ee;

  // ��������Ԫ�أ��ؼ��ִ�10��20��
  ee.key=10; ee.value=110; Insert(hh,&ee);
  ee.key=11; ee.value=111; Insert(hh,&ee);
  ee.key=12; ee.value=112; Insert(hh,&ee);
  ee.key=13; ee.value=113; Insert(hh,&ee);
  ee.key=14; ee.value=114; Insert(hh,&ee);
  ee.key=15; ee.value=115; Insert(hh,&ee);
  ee.key=16; ee.value=116; Insert(hh,&ee);
  ee.key=17; ee.value=117; Insert(hh,&ee);
  ee.key=18; ee.value=118; Insert(hh,&ee);
  ee.key=19; ee.value=119; Insert(hh,&ee);

  // ��������Ԫ�أ��ؼ��ִ�20��30��
  ee.key=20; ee.value=120; Insert(hh,&ee);
  ee.key=21; ee.value=121; Insert(hh,&ee);
  ee.key=22; ee.value=122; Insert(hh,&ee);
  ee.key=23; ee.value=123; Insert(hh,&ee);
  ee.key=24; ee.value=124; Insert(hh,&ee);
  ee.key=25; ee.value=125; Insert(hh,&ee);
  ee.key=26; ee.value=126; Insert(hh,&ee);
  ee.key=27; ee.value=127; Insert(hh,&ee);
  ee.key=28; ee.value=128; Insert(hh,&ee);
  ee.key=29; ee.value=129; Insert(hh,&ee);

  // ��������Ԫ�أ��ؼ��ִ�30��32��
  ee.key=30; ee.value=130; Insert(hh,&ee);
  ee.key=31; ee.value=131; Insert(hh,&ee);
  ee.key=32; ee.value=132; Insert(hh,&ee);

  printf("count=%d\n",hh->count);
  PrintTable(hh);    // ��ӡ��ϣ�� 

  Delete(hh,12);     // ɾ����ϣ���йؼ���Ϊ12������Ԫ�ء�

  printf("count=%d\n",hh->count);
  PrintTable(hh);    // ��ӡ��ϣ�� 

  // �ڹ�ϣ���в��ҹؼ���18��
  Node *pp=LookUp(hh,18);
  if (pp==0) printf("LookUp(18) failed.\n");
  else printf("key=18,value=%d.\n",pp->elem.value);  

  // ee.key=10; strcpy(ee.value,"<no>00010<no/><name>��ʩ</name><yz>��������</yz>"); Insert(hh,&ee);
  // PrintTable(hh);    // ��ӡ��ϣ�� 

  FreeHashTable(hh);  // ���ٹ�ϣ�� 

  return 0;
}


