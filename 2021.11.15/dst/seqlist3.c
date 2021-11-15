/*
 * ��������seqlist3.c���˳�����ʾ˳���Ķ�̬ʵ�֣�����Ԫ����������
 * ���ߣ�C���Լ�����(www.freecplus.net) ���ڣ�20201230
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INITSIZE 10        // ˳���ĳ�ʼ���ȡ�
#define EXTSIZE   5        // ÿ����չԪ�صĸ�����

typedef int ElemType;      // �Զ���˳��������Ԫ��Ϊ������

typedef struct
{
  ElemType *data;           // �洢˳�����Ԫ�ص��׵�ַ��
  unsigned int maxsize;     // ˳���Ԫ�ص���󳤶ȡ�
  unsigned int length;      // ˳�����Ԫ�صĸ�����
}SeqList,*PSeqList;

// ˳���LL�ĳ�ʼ��������
void InitList(PSeqList LL);                     

// ����˳���LL��
void DestroyList(PSeqList LL);

// ��չ˳�����ڴ�ռ䣬����ֵ��0-ʧ�ܣ�1-�ɹ���
int ExtList(PSeqList LL);

// ��˳���LL�ĵ�ii��λ�ò���Ԫ��ee������ֵ��0-ʧ�ܣ�1-�ɹ���
int  InsertList(PSeqList LL, unsigned int ii, ElemType *ee);   

// ��˳���LL��ͷ������Ԫ��ee������ֵ��0-ʧ�ܣ�1-�ɹ���
int  PushFront(PSeqList LL, ElemType *ee);

// ��˳���LL��β������Ԫ��ee������ֵ��0-ʧ�ܣ�1-�ɹ���
int  PushBack(PSeqList LL, ElemType *ee);

// ��˳���ĳ��ȣ�����ֵ��>=0-��LLԪ�صĸ�����
int  LengthList(PSeqList LL);                   

// ��ȡ˳����е�ii��Ԫ�ص�ֵ�������ee�У�����ֵ��0-ʧ�ܣ�1-�ɹ���
int  GetElem(PSeqList LL, unsigned int ii, ElemType* ee);  

// ���˳���
void ClearList(PSeqList LL);                    

// �ж�˳����Ƿ�Ϊ�գ�����ֵ��1-�գ�0-�ǿջ�ʧ�ܡ�
int  IsEmpty(PSeqList LL);                    

// ��ӡ˳�����ȫ����Ԫ�ء�
void PrintList(PSeqList LL);                    

// ����ee��˳���LL�е�λ�ã�����ֵ��0-Ԫ��ee�ڱ�LL�в����ڣ�>0Ԫ��ee�ڱ�LL�е�λ�á�
int  LocateElem(PSeqList LL, ElemType *ee);

// ɾ��˳���LL�еĵ�ii��Ԫ�أ�����ֵ��0-λ��ii���Ϸ���1-�ɹ���
int  DeleteElem(PSeqList LL, unsigned int ii);  

// ɾ��˳���LL��ͷԪ�أ�����ֵ��0-λ��ii���Ϸ���1-�ɹ���
int PopFront(PSeqList LL);

// ɾ��˳���LL��βԪ�أ�����ֵ��0-λ��ii���Ϸ���1-�ɹ���
int PopBack(PSeqList LL);

int main()
{
  SeqList LL;     // ����˳���

  ElemType ee;    // ����һ������Ԫ�ء�

  InitList(&LL);  // ��ʼ��˳���

  printf("�ڱ��в���Ԫ�أ�1��2��3��4��5��6��7��8��9��10����\n");
  ee=1;  InsertList(&LL, 1, &ee);
  ee=2;  InsertList(&LL, 1, &ee);
  ee=3;  InsertList(&LL, 1, &ee);
  ee=4;  InsertList(&LL, 1, &ee);
  ee=5;  InsertList(&LL, 1, &ee);
  ee=6;  InsertList(&LL, 1, &ee);
  ee=7;  InsertList(&LL, 1, &ee);
  ee=8;  InsertList(&LL, 1, &ee);
  ee=9;  InsertList(&LL, 1, &ee);
  ee=10; InsertList(&LL, 1, &ee);

  PrintList(&LL);

  printf("�ڱ�ͷ����Ԫ�أ�11������β����Ԫ�أ�12����\n");
  ee=11; PushFront(&LL, &ee);
  ee=12; PushBack(&LL, &ee);

  PrintList(&LL);

  printf("�ڵ�5��λ�ò���Ԫ�أ�13����\n");
  ee=13; InsertList(&LL, 5, &ee);  

  PrintList(&LL);

  printf("ɾ�����е�7��Ԫ�ء�\n");
  DeleteElem(&LL,7); PrintList(&LL);

  printf("ɾ����ͷԪ�ء�\n");
  PopFront(&LL); PrintList(&LL);

  printf("ɾ����βԪ�ء�\n");
  PopBack(&LL); PrintList(&LL);

  GetElem(&LL,3,&ee);
  printf("��3��Ԫ�ص�ֵ��%d��\n",ee);

  ee=8;
  printf("Ԫ��ֵΪ8��λ����=%d\n",LocateElem(&LL,&ee));

  DestroyList(&LL);  // ����˳���LL��

  return 0;
}

// ��ʼ��˳���
void InitList(PSeqList LL)
{
  LL->data=(ElemType *)malloc(sizeof(ElemType)*INITSIZE);
  LL->maxsize=INITSIZE;

  ClearList(LL); // ���˳���
}

// ���˳���
void ClearList(PSeqList LL)
{
  if (LL == NULL) return;  // ����ָ�롣

  LL->length=0;
  memset(LL->data,0,sizeof(ElemType)*LL->maxsize);
}

// ����˳���LL��
void DestroyList(PSeqList LL)
{
  free(LL->data);

  LL->maxsize=0;
  LL->length=0;
}

// ��˳���ĳ��ȣ�����ֵ��>=0-��LLԪ�صĸ�����
int LengthList(PSeqList LL)
{
  if (LL == NULL) return 0;  // ����ָ�롣

  return LL->length;
}

// ��ȡ˳����е�ii��Ԫ�ص�ֵ�������ee�У�����ֵ��0-ʧ�ܣ�1-�ɹ���
int  GetElem(PSeqList LL, unsigned int ii, ElemType* ee)
{
  if ( (LL == NULL) || (ee == NULL) ) return 0;   // ����ָ�롣
  
  // �ж�λ��ii�Ƿ�Ϸ�
  if ( (ii < 1) || (ii > LL->length) ) return 0;

  memcpy(ee,LL->data+ii-1,sizeof(ElemType));  // ����memcpy��Ϊ��֧��eeΪ�ṹ��������

  return ;
}

// ��չ˳�����ڴ�ռ䣬����ֵ��0-ʧ�ܣ�1-�ɹ���
int ExtList(PSeqList LL)
{
  // �����µ��ڴ�ռ䡣
  ElemType *newdata=(ElemType *)malloc(sizeof(ElemType)*(LL->maxsize+EXTSIZE));

  // �������ʧ�ܣ�����0��
  if (newdata == NULL) return 0;

  memset(newdata,0,sizeof(ElemType)*(LL->maxsize+EXTSIZE));

  // ��˳�����ԭ�������ݸ��Ƶ��·�����ڴ�ռ��С�
  memcpy(newdata,LL->data,sizeof(ElemType)*LL->maxsize);

  // �ͷ�ԭ�����ڴ�ռ䡣
  free(LL->data);

  // ��˳�������Ԫ�ص�ָ��ָ���·�����ڴ�ռ�ĵ�ַ��
  LL->data=newdata;

  // ����˳����maxsize������
  LL->maxsize=LL->maxsize+EXTSIZE;

  return 1;
}

// ��˳���LL�ĵ�ii��λ�ò���Ԫ��ee������ֵ��0-ʧ�ܣ�1-�ɹ���
int InsertList(PSeqList LL, unsigned int ii, ElemType *ee)
{
  if ( (LL == NULL) || (ee == NULL) ) return 0;   // ����ָ�롣

  if (LL->length >= LL->maxsize)
  {
    if (ExtList(LL) == 0) { printf("��չ˳���ʧ�ܡ�\n"); return 0; }
  }

  // �жϲ���λ���Ƿ�Ϸ�
  if ( (ii < 1) || (ii > LL->length+1) )
  {
    printf("����λ�ã�%d�����Ϸ���Ӧ���ڣ�%d-%d��֮�䡣\n",ii,1,LL->length+1); return 0;
  }

  // ע�⣬Ԫ�غ���ֻ����ѭ��������������ע�͵��ķ�������Ԫ���ǽṹ��ʱ�����·������ȶ���
  // if ( ii < LL->length+1)
  //   memcpy(LL->data+ii,LL->data+ii-1,(LL->length-ii+1)*sizeof(ElemType));

  // ��ii��ii֮���Ԫ�غ��ơ�
  int kk;
  for (kk=LL->length;kk>=ii;kk--)
  {
    memcpy(LL->data+kk,LL->data+kk-1,sizeof(ElemType));  // ����memcpy��Ϊ��֧��eeΪ�ṹ��������
    // memcpy(&LL->data[kk],&LL->data[kk-1],sizeof(ElemType));  // Ҳ���Բ����������ʽ��
  }

  memcpy(LL->data+ii-1,ee,sizeof(ElemType));  // ����memcpy��Ϊ��֧��eeΪ�ṹ��������
  LL->length++;       // ��ĳ��ȼ�1��

  return 1;
}

// ��˳���LL��ͷ������Ԫ��ee������ֵ��0-ʧ�ܣ�1-�ɹ���
int  PushFront(PSeqList LL, ElemType *ee)
{
  return InsertList(LL,1,ee);
}

// ��˳���LL��β������Ԫ��ee������ֵ��0-ʧ�ܣ�1-�ɹ���
int PushBack(PSeqList LL, ElemType *ee)
{
  return InsertList(LL,LL->length+1,ee);
}

// ɾ��˳���LL�еĵ�ii��Ԫ�أ�����ֵ��0-λ��ii���Ϸ���1-�ɹ���
int DeleteElem(PSeqList LL, unsigned int ii)
{
  if (LL == NULL) return 0;   // ����ָ�롣

  // �ж�ɾ��λ��ii�Ƿ�Ϸ�
  if ( (ii < 1) || (ii > LL->length) )
  {
    printf("ɾ��λ�ã�%d�����Ϸ���Ӧ���ڣ�%d-%d��֮��\n",ii,1,LL->length); return 0;
  }

  // ��ii֮���Ԫ��ǰ�ơ�
  int kk;
  for (kk=ii;kk<=LL->length;kk++)
  {
    memcpy(LL->data+kk-1,LL->data+kk,sizeof(ElemType));  // ����memcpy��Ϊ��֧��eeΪ�ṹ��������
  }

  LL->length--;       // ��ĳ��ȼ�1��

  return 1;
}

// ����ee��˳���LL�е�λ�ã�����ֵ��0-Ԫ��ee�ڱ�LL�в����ڣ�>0Ԫ��ee�ڱ�LL�е�λ�á�
int LocateElem(PSeqList LL, ElemType *ee)
{
  if (LL == NULL) return 0;   // ����ָ�롣

  int kk;

  for (kk = 0; kk < LL->length; kk++)
  {
    // ���Ԫ��eeΪ�ṹ�壬���д���Ҫ�޸ġ�
    if (*(LL->data+kk) == *ee) return kk+1; // �ڱ��ж�Ӧ���ӦΪkk+1��
  }
    
  return 0;
}

// ɾ��˳���LL��ͷԪ�أ�����ֵ��0-λ��ii���Ϸ���1-�ɹ���
int PopFront(PSeqList LL)
{
  return DeleteElem(LL, 1);
}

// ɾ��˳���LL��βԪ�أ�����ֵ��0-λ��ii���Ϸ���1-�ɹ���
int PopBack(PSeqList LL)
{
  return DeleteElem(LL, LL->length);
}

// �ж�˳����Ƿ�Ϊ�գ�����ֵ��1-�գ�0-�ǿջ�ʧ�ܡ�
int IsEmpty(PSeqList LL)
{
  if (LL == NULL) return 0;   // ����ָ�롣

  if (LL->length == 0) return 1;

  return 0;
}

// ��ӡ˳�����ȫ����Ԫ�ء�
void PrintList(PSeqList LL)
{
  if (LL == NULL) return;   // ����ָ�롣

  if (LL->length == 0) { printf("��Ϊ�ա�\n"); return; }

  int kk;
  for (kk = 0; kk < LL->length; kk++)
  {
    printf("%-3d", *(LL->data+kk));  // ���Ԫ��eeΪ�ṹ�壬���д���Ҫ�޸ġ�
  }

  printf("\n");
}


