// Ͱ�������ߣ�C���Լ�������www.freecplus.net����ũ�е���
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// ��������ѭ��ʵ��ð������ķ�����
// ����arr�Ǵ�����������׵�ַ��len������Ԫ�صĸ�����
void bubblesort(int *arr,unsigned int len)
{
  if (len<2) return; // ����С��2��Ԫ�ز���Ҫ����

  int ii;    // ����������ļ�������
  int jj;    // ÿ�������Ԫ��λ�ü�������
  int itmp;  // �Ƚ�����Ԫ�ش�Сʱ����λ���õ�����ʱ������

  // 44,3,38,5,47,15,36,26,27,2,46,4,19,50,48  
  for (ii=len-1;ii>0;ii--)  // һ������len-1�˱Ƚϡ�
  {
    for (jj=0;jj<ii;jj++)  // ÿ��ֻ��Ҫ�Ƚ�0......ii֮���Ԫ�أ�ii֮���Ԫ�����Ѿ�����õġ�
    {
      if (arr[jj]>arr[jj+1])  // ���ǰ���Ԫ�ش��ں����Ԫ�أ��򽻻���λ��λ�á�
      {
        itmp=arr[jj+1];
        arr[jj+1]=arr[jj];
        arr[jj]=itmp;
      }
    }
  }
}

// Ͱ����������������arr�Ǵ�����������׵�ַ��len������Ԫ�صĸ�����
void bucketsort(int *arr,unsigned int len)
{
  int buckets[5][5];   // �������Ͱ��
  int bucketssize[5];  // ÿ��Ͱ��Ԫ�ظ����ļ�������

  // ��ʼ��Ͱ��Ͱ��������
  memset(buckets,0,sizeof(buckets));
  memset(bucketssize,0,sizeof(bucketssize));

  // ������arr�����ݷ���Ͱ�С�
  int ii=0;
  for (ii=0;ii<len;ii++)
  {
    buckets[arr[ii]/10][bucketssize[arr[ii]/10]++]=arr[ii];
  }

  // ��ÿ��Ͱ����ð������
  for (ii=0;ii<5;ii++)
  {
    bubblesort(buckets[ii],bucketssize[ii]);
  }

  // ��ÿ��Ͱ�е�������䵽����arr�С�
  int jj=0,kk=0;
  for (ii=0;ii<5;ii++)
  {
    for (jj=0;jj<bucketssize[ii];jj++)
      arr[kk++]=buckets[ii][jj];
  }
}

int main(int argc,char *argv[])
{
  int arr[]={21,3,30,44,15,36,6,10,9,19,25,48,5,23,47};
  int len=sizeof(arr)/sizeof(int);

  int xx; for (xx=0;xx<len;xx++) printf("%2d ",arr[xx]); printf("\n");

  bucketsort(arr,len);

  // ��ʾ��������
  int ii; for (ii=0;ii<len;ii++) printf("%2d ",arr[ii]); printf("\n");

  // system("pause");  // widnows�µ�C���ñ��д��롣

  return 0;
}
