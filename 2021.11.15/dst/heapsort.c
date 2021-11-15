// ���������ߣ�C���Լ�������www.freecplus.net����ũ�е���
#include <stdio.h>
#include <stdlib.h>

// ��������Ԫ�ص�ֵ��
void swap(int *a,int *b) { int temp=*b; *b=*a; *a=temp; }

// ����ѭ��ʵ��heapify��Ԫ���³�����
// arr-����������ĵ�ַ��start-��heapify�ڵ���±꣬end-�������������һ��Ԫ�ص��±ꡣ
void heapify(int *arr,int start,int end) 
{
  // ȷ�����ڵ�����ӽڵ�������±ꡣ
  int dad=start;
  int son=dad*2+1;

  // ����ӽڵ���±�û�г�����Χ��ѭ��������
  while (son<=end) 
  { 
    // �ȱȽ������ӽڵ��С��ѡ�����ġ�
    if ((son+1<=end) && (arr[son]<arr[son+1])) son++;

    // ������ڵ�����ӽڵ���������ϣ�ֱ������������
    if (arr[dad]>arr[son]) return;

    // ���򽻻����Ӄ����ټ����ӽڵ����ڵ�Ƚϡ�
    swap(&arr[dad],&arr[son]);
    dad=son;
    son=dad*2+1;
  }
}

// ���õݹ�ʵ��heapify��
void heapify1(int *arr,int start,int end) 
{
  // ȷ�����ڵ�����ӽڵ�������±ꡣ
  int dad=start;
  int son=dad*2+1;

  // ����ӽڵ���±�û�г�����Χ��ѭ��������
  if (son>end ) return;

  // �ȱȽ������ӽڵ��С��ѡ�����ġ�
  if ((son+1<=end) && (arr[son]<arr[son+1])) son++;

  // ������ڵ�����ӽڵ���������ϣ�ֱ������������
  if (arr[dad]>arr[son]) return;

  // ���򽻻����Ӄ����ټ����ӽڵ����ڵ�Ƚϡ�
  swap(&arr[dad],&arr[son]);

  heapify(arr,son,end);
}

void heapsort(int *arr, int len) 
{
  int ii;

  // ��ʼ���ѣ������һ�����ڵ㿪ʼ������
  for (ii=(len-1)/2;ii>=0;ii--) heapify(arr,ii,len-1);

  // �ѵ�һ��Ԫ�غͶ����һ��Ԫ�ؽ�����Ȼ�����µ�����ֱ��������ϡ�
  for (ii=len-1;ii>0;ii--) 
  {
    swap(&arr[0],&arr[ii]);
    heapify(arr,0,ii-1);
  }
}

int main() 
{
  int arr[]={44,3,38,5,47,15,36,26,27,2,46,4,19,50,48};

  int len=sizeof(arr)/sizeof(int);

  heapsort(arr,len);

  // ��ʾ��������
  int yy; for (yy=0;yy<len;yy++) printf("%2d ",arr[yy]); printf("\n");

  // system("pause");  // widnows�µ�C���ñ��д��롣

  return 0;
}
