/*
 * ��������binsearch.c���˳�����ʾ�۰���ҡ�
 * ���ߣ�C���Լ�����(www.freecplus.net) ���ڣ�20210325
*/
#include <stdio.h>
#include <string.h>

// ����ʵ�֡�
// ��sstable�в���key��ʧ�ܷ���-1���ɹ�����key��sstable�е������±ꡣ
int Bin_Search1(int *sstable,unsigned int len,int key)
{
  int low,high,mid;
  low=0; high=len-1;    // ��ʼ��low��high��ֵ�����ó�ʼ���䡣

  while (low<=high)
  {
    mid=(low+high)/2;   // ����mid��ֵ��ȡ�м�λ�á�

    if (sstable[mid]==key) return mid;     // �ҵ��˴����ҵ�Ԫ�ء�
    else if (sstable[mid]>key) high=mid-1; // ������ǰ��������в��ҡ�
    else low=mid+1;                        // �����ں��������в��ҡ�
  }

  return -1;
}

// �ݹ�ʵ�֡�
// ��sstable�в���key��ʧ�ܷ���-1���ɹ�����key��sstable�е������±ꡣ
int Bin_Search2(int *sstable,int key,int low,int high)
{
  if (low>high) return -1;  

  int mid=(low+high)/2;   // ����mid��ֵ��ȡ�м�λ�á�

  if (sstable[mid]==key) return mid;         // �ҵ��˴����ҵ�Ԫ�ء�
  else if (sstable[mid]>key) Bin_Search2(sstable,key,low,mid-1); // ������ǰ��������в��ҡ�
  else Bin_Search2(sstable,key,mid+1,high);  // �����ں��������в��ҡ�
}

int main()
{
  // �����˳���
  int sstable1[]={1,2,3,4,5,6,7,8,9,12};
  int len=sizeof(sstable1)/sizeof(int);

  // ����
  printf("result1=%d\n",Bin_Search1(sstable1,len,0));
  printf("result1=%d\n",Bin_Search1(sstable1,len,1));
  printf("result1=%d\n",Bin_Search1(sstable1,len,7));
  printf("result1=%d\n",Bin_Search1(sstable1,len,10));
  printf("result1=%d\n",Bin_Search1(sstable1,len,12));
  printf("result1=%d\n",Bin_Search1(sstable1,len,15));
  printf("\n");

  // �ݹ�
  printf("result2=%d\n",Bin_Search2(sstable1, 0,0,len-1));
  printf("result2=%d\n",Bin_Search2(sstable1, 1,0,len-1));
  printf("result2=%d\n",Bin_Search2(sstable1, 7,0,len-1));
  printf("result2=%d\n",Bin_Search2(sstable1,10,0,len-1));
  printf("result2=%d\n",Bin_Search2(sstable1,12,0,len-1));
  printf("result2=%d\n",Bin_Search2(sstable1,15,0,len-1));

  return 0;
}
