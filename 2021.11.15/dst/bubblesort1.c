// �Ż����ð���������ߣ�C���Լ�������www.freecplus.net����ũ�е���
#include <stdlib.h>
#include <stdio.h>

// ��������ѭ��ʵ�ֵķ�����
// ����arr�Ǵ�����������׵�ַ��len������Ԫ�صĸ�����
void bubblesort1(int *arr,unsigned int len)
{
  if (len<2) return; // ����С��2��Ԫ�ز���Ҫ����

  int ii;     // ����������ļ�������
  int jj;     // ÿ�������Ԫ��λ�ü�������
  int itmp;   // �Ƚ�����Ԫ�ش�Сʱ����λ���õ�����ʱ������
  int ifswap; // ÿ������������Ƿ񽻻���Ԫ�أ�0-δ������1-�н�����

  // 44,3,38,5,47,15,36,26,27,2,46,4,19,50,48  
  for (ii=len-1;ii>0;ii--)  // һ������len-1�˱Ƚϡ�
  {
printf("ii=%d\n",ii);
    ifswap=0; // ��ʼ��������־��
    for (jj=0;jj<ii;jj++)  // ÿ��ֻ��Ҫ�Ƚ�0......ii֮���Ԫ�أ�ii֮���Ԫ�����Ѿ�����õġ�
    {
      if (arr[jj]>arr[jj+1])  // ���ǰ���Ԫ�ش��ں����Ԫ�أ��򽻻���λ��λ�á�
      {
        itmp=arr[jj+1];
        arr[jj+1]=arr[jj];
        arr[jj]=itmp;
        ifswap=1; // ���ý�����־��
      }
    }

    if (ifswap==0) return;
  }
}

// ���õݹ�ʵ�ֵķ�����
// ����arr�Ǵ�����������׵�ַ��len������Ԫ�صĸ�����
void bubblesort2(int *arr,unsigned int len)
{
  if (len<2) return; // ����С��2��Ԫ�ز���Ҫ����

printf("len=%d\n",len);

  int ii;       // �����Ԫ��λ�ü�������
  int itmp;     // �Ƚ�����Ԫ�ش�Сʱ����λ���õ�����ʱ������
  int ifswap=0; // ����������Ƿ񽻻���Ԫ�أ�0-δ������1-�н�����

  for (ii=0;ii<len-1;ii++)  // ÿ��ֻ��Ҫ�Ƚ�0......len-1֮���Ԫ�أ�len-1֮���Ԫ�����Ѿ�����õġ�
  {
    if (arr[ii]>arr[ii+1])  // ���ǰ���Ԫ�ش��ں����Ԫ�أ��򽻻���λ��λ�á�
    {
      itmp=arr[ii+1];
      arr[ii+1]=arr[ii];
      arr[ii]=itmp;
      ifswap=1; // ���ý�����־��
    }
  }

  if (ifswap==0) return;

  bubblesort2(arr,--len);
}

int main(int argc,char *argv[])
{
  int arr[]={44,3,38,5,47,15,36,26,27,2,46,4,19,50,48};
  int len=sizeof(arr)/sizeof(int);

  bubblesort2(arr,len);

  // ��ʾ��������
  int ii;
  for (ii=0;ii<len;ii++) printf("%2d ",arr[ii]);

  printf("\n");

  // system("pause");  // widnows�µ�C���ñ��д��롣

  return 0;
}
