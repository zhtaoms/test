// ���������Ż��棩�����ߣ�C���Լ�������www.freecplus.net����ũ�е���
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ��ȡ�������������С�����Ԫ�ص�ֵ��
void arrminmax(int *arr,unsigned int len,int *min,int *max)
{
  int ii=0;
  *min=*max=arr[0];

  for (ii=0;ii<len;ii++) 
  {
    if (*max<arr[ii]) *max=arr[ii];
    if (*min>arr[ii]) *min=arr[ii];
  }
}

// ����������������arr-����������ĵ�ַ��len-����ĳ��ȡ�
void countsort(int *arr,unsigned int len) 
{
  if (len<2) return;

  // ��ȡ�������������С������Ԫ�ص�ֵ��
  int imin,imax; 
  arrminmax(arr,len,&imin,&imax);  

  int arrtmp[imax-imin+1];          // ��ʱ����Ĵ�СΪimax+1��
  memset(arrtmp,0,sizeof(arrtmp));  // ��ʼ����ʱ���顣

  int ii,jj,kk;
  
  // ��ʱ���������
  for (ii=0;ii<len;ii++) arrtmp[arr[ii]-imin]++;

  // ����ʱ���������������䵽arr�С�
  ii=0;
  for (jj=0;jj<imax-imin+1;jj++)
  {
    for (kk=0;kk<arrtmp[jj];kk++) arr[ii++]=jj+imin;
  }
}

int main() 
{
  //int arr[]={2,3,8,7,1,2,2,2,7,3,9,8,2,1,4,2,4,6,9,2};
  int arr[]={102,103,108,107,101,102,102,102,107,103,109,108,102,101,104,102,104,106,109,102};

  int len=sizeof(arr)/sizeof(int);

  int xx; for (xx=0;xx<len;xx++) printf("%2d ",arr[xx]); printf("\n");

  countsort(arr,len);

  // ��ʾ��������
  int yy; for (yy=0;yy<len;yy++) printf("%2d ",arr[yy]); printf("\n");

  // system("pause");  // widnows�µ�C���ñ��д��롣

  return 0;
}
