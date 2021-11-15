#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// ��ȡ����arr�����ֵ��arr-����������飬len-����arr�ĳ��ȡ�
int arrmax(int *arr,unsigned int len)
{
  int ii,imax;

  imax=arr[0];

  for (ii=1;ii<len;ii++)
    if (arr[ii]>imax) imax=arr[ii];

  return imax;
}

// ������arr��ָ��λ��������
// arr-����������飬len-����arr�ĳ��ȡ�
// exp-����ָ����exp=1������λ����exp=10����ʮλ����......
void _radixsort(int *arr,unsigned int len,unsigned int exp)
{
  int ii;
  int result[len];       // ��Ŵ�Ͱ���ռ������ݵ���ʱ���顣
  int buckets[10]={0};   // ��ʼ��10��Ͱ��

  // ����arr�������ݳ��ֵĴ����洢��buckets�С�
  for (ii=0;ii<len;ii++)
    buckets[(arr[ii]/exp)%10]++;

  // ����buckets��Ԫ�ص�ֵ���������ֵ����arr��Ԫ����result�е�λ�á�
  for (ii=1;ii<10;ii++)
    buckets[ii]=buckets[ii]+buckets[ii-1];

  // ��arr�е�Ԫ����䵽result�С�
  for (ii=len-1;ii>=0;ii--)
  {
    int iexp=(arr[ii]/exp)%10;
    result[buckets[iexp]-1]=arr[ii];
    buckets[iexp]--;
  }
  
  // ������õ�����result���Ƶ�����arr�С�
  memcpy(arr,result,len*sizeof(int));
}

// ����������������arr-����������飬len-����arr�ĳ��ȡ�
void radixsort(int *arr,unsigned int len)
{
  int imax=arrmax(arr,len);    // ��ȡ����arr�е����ֵ��

  int iexp;    // ����ָ����iexp=1������λ����iexp=10����ʮλ����......

  // �Ӹ�λ��ʼ��������arr��ָ��λ��������
  for (iexp=1;imax/iexp>0;iexp=iexp*10)
  {
    _radixsort(arr,len,iexp);
    int yy; printf("exp=%-5d  ",iexp); for (yy=0;yy<len;yy++) printf("%2d ",arr[yy]); printf("\n");
  }
}

int main(int argc,char *argv[])
{
  int arr[]={144,203,738,905,347,215,836,26,527,602,946,504,219,750,848};
  int len=sizeof(arr)/sizeof(int);

  radixsort(arr,len);  // ��������

  // ��ʾ��������
  int yy; for (yy=0;yy<len;yy++) printf("%2d ",arr[yy]); printf("\n");

  // system("pause");  // widnows�µ�C���ñ��д��롣

  return 0;
}
