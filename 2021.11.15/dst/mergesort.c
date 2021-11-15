// ���õݹ�ķ���ʵ�ֹ鲢�������ߣ�C���Լ�������www.freecplus.net����ũ�е���
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// ���õݹ�ķ���ʵ�ֹ鲢��������
// arr-������������׵�ַ��arrtmp-�����������ʱ������׵�ַ
// start-���������һ��Ԫ�ص�λ�ã�end-�����������һ��Ԫ�ص�λ�á�
void _mergesort(int *arr,int *arrtmp,int start,int end) 
{
  // ���start>=end����ʾ�������Ԫ�������������ݹ���ֹ��
  if (start>=end) return; 

  int mid=start+(end-start)/2;  // �������������м��λ�á�

  int istart1=start,iend1=mid;  // �������Ԫ�صĵ�һ�����һ��Ԫ�ص�λ�á�
  int istart2=mid+1,iend2=end;  // �����ұ�Ԫ�صĵ�һ�����һ��Ԫ�ص�λ�á�

  _mergesort(arr,arrtmp,istart1,iend1);   // ���������Ԫ�صݹ�����
  _mergesort(arr,arrtmp,istart2,iend2);   // �������ұ�Ԫ�صݹ�����

  int ii=start; // ����������arrtmp�ļ�������

  // �����������������кϲ�������������arrtmp�С�
  while (istart1<=iend1 && istart2<=iend2)
    arrtmp[ii++]=arr[istart1]<arr[istart2] ? arr[istart1++] : arr[istart2++];

  // ���������������Ԫ��׷�ӵ����������顣
  while (istart1<=iend1) arrtmp[ii++]=arr[istart1++];

  // ���ұ�����������Ԫ��׷�ӵ����������顣
  while (istart2<=iend2) arrtmp[ii++]=arr[istart2++];

  // ������������arrtmp�е�Ԫ�ظ��Ƶ�arr�С�
  memcpy(arr+start,arrtmp+start,(end-start+1)*sizeof(int));
}

// ������������arrΪ�����������ĵ�ַ��lenΪ����ĳ��ȡ�
void mergesort(int *arr,unsigned int len) 
{
  if (len<2) return;  // С������Ԫ�ز���Ҫ����

  int arrtmp[len];  // ����һ���������������ͬ��С�����顣

  _mergesort(arr,arrtmp,0,len-1);  // ���õݹ麯����������
}

int main(int argc,char *argv[])
{
  int arr[]={44,3,38,5,47,15,36,26,27,2,46,4,19,50,48};
  int len=sizeof(arr)/sizeof(int);

  mergesort(arr,len);

  // ��ʾ��������
  int yy; for (yy=0;yy<len;yy++) printf("%2d ",arr[yy]); printf("\n");

  // system("pause");  // widnows�µ�C���ñ��д��롣

  return 0;
}

