// ϣ���������ߣ�C���Լ�������www.freecplus.net����ũ�е���
#include <stdlib.h>
#include <stdio.h>

// ��ϣ�������еĵ������������
// arr-����������飬len-�����ܵĳ��ȣ�ipos-�������ʼλ�ã�istep-����Ĳ�������������
void groupsort(int *arr, int len, int ipos,int istep)
{
  int itmp;  // ��ǰ��Ҫ�����Ԫ�ص�ֵ��
  int ii;    // ��Ҫ����Ԫ�صļ�������
  int jj;    // ��������ʱ����Ҫ����Ԫ�صļ�������

  for (ii=ipos+istep;ii<len;ii=ii+istep) 
  {
    itmp=arr[ii];    // ������Ԫ��
      
    // ������������ұ߿�ʼ���Ѵ��ڵ�ǰ�����Ԫ�غ��ơ�
    // for (jj=ii-istep;(jj>=0&&arr[jj]>itmp);jj=jj-istep)
    for (jj=ii-istep;jj>=0;jj=jj-istep)
    {
      if (arr[jj]<=itmp) break;  

      arr[jj+istep]=arr[jj];  // ���Ԫ�غ��ơ�
    }

    arr[jj+istep]=itmp; // ���뵱ǰ����Ԫ�ء�
  }
}

// ϣ������arr�Ǵ�����������׵�ַ��len������Ĵ�С��
void shellsort(int *arr,unsigned int len)
{
  int ii,istep;

  // istepΪ������ÿ�μ�Ϊԭ����һ��ȡ���������һ�αض�Ϊ1��
  for (istep=len/2;istep>0;istep=istep/2)
  {
    // ��istep���飬��ÿһ�鶼ִ�в�������
    for (ii=0;ii<istep;ii++)
    {
      groupsort(arr,len,ii,istep);
    }
  }
}

int main(int argc,char *argv[])
{
  int arr[]={44,3,38,5,47,15,36,26,27,2,46,4,19,50,48};
  int len=sizeof(arr)/sizeof(int);

  shellsort(arr,len);   // ���ò�������������������

  // ��ʾ��������
  int yy; for (yy=0;yy<len;yy++) printf("%2d ",arr[yy]); printf("\n");

  // system("pause");  // widnows�µ�C���ñ��д��롣

  return 0;
}
