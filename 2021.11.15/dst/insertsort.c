// �����������ߣ�C���Լ�������www.freecplus.net����ũ�е���
#include <stdlib.h>
#include <stdio.h>

// ����arr�Ǵ�����������׵�ַ��len������Ԫ�صĸ�����
void insertsort(int *arr,unsigned int len)
{
  if (len<2) return; // ����С��2��Ԫ�ز���Ҫ����

  int itmp;  // ��ǰ��Ҫ�����Ԫ�ص�ֵ��
  int ii;    // ��Ҫ����Ԫ�صļ�������
  int jj;    // ��������ʱ����Ҫ����Ԫ�صļ�������

  for (ii=1;ii<len;ii++)
  {
    itmp=arr[ii];    // ������Ԫ��

    // ������������ұ߿�ʼ���Ѵ��ڵ�ǰ�����Ԫ�غ��ơ�
    // for (jj=ii-1;(jj>=0&&arr[jj]>itmp);jj--)
    for (jj=ii-1;jj>=0;jj--)
    {
      if (arr[jj]<=itmp) break;

      arr[jj+1]=arr[jj]; // ���Ԫ�غ��ơ�
    }

    arr[jj+1]=itmp; // ���뵱ǰ����Ԫ�ء�
  }
}


int main(int argc,char *argv[])
{
  int arr[]={44,3,38,5,47,15,36,26,27,2,46,4,19,50,48};
  int len=sizeof(arr)/sizeof(int);

  insertsort(arr,len);   // ���ò�������������������

  // ��ʾ��������
  int yy; for (yy=0;yy<len;yy++) printf("%2d ",arr[yy]); printf("\n");

  // system("pause");  // widnows�µ�C���ñ��д��롣

  return 0;
}
