// ð���������ߣ�C���Լ�������www.freecplus.net����ũ�е���
#include <stdlib.h>
#include <stdio.h>

// ��������ѭ��ʵ�ֵķ�����
// ����arr�Ǵ�����������׵�ַ��len������Ԫ�صĸ�����
void bubblesort1(int *arr,unsigned int len)
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

// ���õݹ�ʵ�ֵķ�����
// ����arr�Ǵ�����������׵�ַ��len������Ԫ�صĸ�����
void bubblesort2(int *arr,unsigned int len)
{
  if (len<2) return; // ����С��2��Ԫ�ز���Ҫ����

  int ii;    // �����Ԫ��λ�ü�������
  int itmp;  // �Ƚ�����Ԫ�ش�Сʱ����λ���õ�����ʱ������

  for (ii=0;ii<len-1;ii++)  // ÿ��ֻ��Ҫ�Ƚ�0......len-1֮���Ԫ�أ�len-1֮���Ԫ�����Ѿ�����õġ�
  {
    if (arr[ii]>arr[ii+1])  // ���ǰ���Ԫ�ش��ں����Ԫ�أ��򽻻���λ��λ�á�
    {
      itmp=arr[ii+1];
      arr[ii+1]=arr[ii];
      arr[ii]=itmp;
    }
  }

  bubblesort2(arr,--len);
}

int main(int argc,char *argv[])
{
  int arr[]={44,3,38,5,47,15,36,26,27,2,46,4,19,50,48};
  int len=sizeof(arr)/sizeof(int);

  bubblesort1(arr,len);

  // ��ʾ��������
  int ii;
  for (ii=0;ii<len;ii++) printf("%2d ",arr[ii]);

  printf("\n");

  // system("pause");  // widnows�µ�C���ñ��д��롣

  return 0;
}
