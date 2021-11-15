// ѡ���������ߣ�C���Լ�������www.freecplus.net����ũ�е���
#include <stdlib.h>
#include <stdio.h>

// ��������������ֵ��
void swap(int *x,int *y)
{
  int itmp=*x;
  *x=*y;
  *y=itmp;
}

// ��������ѭ��ʵ�ֵķ�����
// ����arr�Ǵ�����������׵�ַ��len������Ԫ�صĸ�����
void selectsort1(int *arr,unsigned int len)
{
  if (len<2) return; // ����С��2��Ԫ�ز���Ҫ����

  int ii;      // ����������ļ�������
  int jj;      // ÿ�������Ԫ��λ�ü�������
  int iminpos; // ÿ��ѭ��ѡ������Сֵ��λ�ã�������±꣩��

  // 44,3,38,5,47,15,36,26,27,2,46,4,19,50,48  
  for (ii=0;ii<len-1;ii++)  // һ������len-1�˱Ƚϡ�
  {
    iminpos=ii;

    for (jj=ii+1;jj<len;jj++)  // ÿ��ֻ��Ҫ�Ƚ�ii+1......len-1֮���Ԫ�أ�ii֮ǰ��Ԫ�����Ѿ�����õġ�
    {
      // �ҳ�ֵ��С��Ԫ�أ���������λ�á�
      if (arr[jj]<arr[iminpos])  iminpos=jj;
    }

    // �������ѭ������С��Ԫ�ز�����ʼλ�õ�Ԫ�أ��򽻻����ǵ�λ�á�
    if (iminpos!=ii) swap(&arr[ii],&arr[iminpos]);
  }
}

// ���õݹ�ʵ�ֵķ�����
// ����arr�Ǵ�����������׵�ַ��len������Ԫ�صĸ�����
void selectsort2(int *arr,unsigned int len)
{
  if (len<2) return; // ����С��2��Ԫ�ز���Ҫ����

  int ii;        // ����������ļ�������
  int iminpos=0; // ÿ��ѭ��ѡ������Сֵ��λ�ã�������±꣩��

  for (ii=1;ii<len;ii++)  
  {
    // �ҳ�ֵ��С��Ԫ�أ���������λ�á�
    if (arr[ii]<arr[iminpos])  iminpos=ii;
  }

  // �������ѭ������С��Ԫ�ز�����ʼλ�õ�Ԫ�أ��򽻻����ǵ�λ�á�
  if (iminpos!=0) swap(&arr[0],&arr[iminpos]);

  selectsort2(arr+1,--len);
}

int main(int argc,char *argv[])
{
  int arr[]={44,3,38,5,47,15,36,26,27,2,46,4,19,50,48};
  //int arr[]={3,4,5,1};
  int len=sizeof(arr)/sizeof(int);

  // selectsort1(arr,len);  // ��������ѭ������ķ�����
  selectsort2(arr,len);  // ���õݹ�����ķ�����

  // ��ʾ��������
  int ii; for (ii=0;ii<len;ii++) printf("%2d ",arr[ii]);

  printf("\n");

  // system("pause");  // widnows�µ�C���ñ��д��롣

  return 0;
}
