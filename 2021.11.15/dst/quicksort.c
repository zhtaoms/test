// �����������ߣ�C���Լ�������www.freecplus.net����ũ�е���
#include <stdlib.h>
#include <stdio.h>

void quicksort(int *arr,unsigned int len)
{
  if (len<2) return;  // �����Ԫ��С��2���Ͳ��������ˡ�

  int itmp=arr[0];  // ѡȡ����ߵ�����Ϊ�����ᡣ
  int ileft=0;      // ���±ꡣ
  int iright=len-1; // ���±ꡣ
  int imoving=2;    // ��ǰӦ���ƶ����±꣬1-���±ꣻ2-���±ꡣ

  while (ileft<iright)
  {
    if (imoving==2) // �ƶ����±�������
    {
      // ������±�λ��Ԫ�ص�ֵ���ڵ��������ᣬ�����ƶ����±ꡣ
      if (arr[iright]>=itmp) { iright--; continue; }
      
      // ������±�λ��Ԫ�ص�ֵС�������ᣬ��������±�Ŀ��С�
      arr[ileft]=arr[iright];
      ileft++;    // ���±������ƶ���
      imoving=1;  // �´�ѭ�����ƶ����±ꡣ
      continue;
    }

    if (imoving==1) // �ƶ����±�������
    {
      // ������±�λ��Ԫ�ص�ֵС���������ᣬ�����ƶ����±ꡣ
      if (arr[ileft]<=itmp) { ileft++; continue; }

      // ������±�λ��Ԫ�ص�ֵ���������ᣬ��������±�Ŀ��С�
      arr[iright]=arr[ileft];
      iright--;   // ���±������ƶ���
      imoving=2;  // �´�ѭ�����ƶ����±ꡣ
      continue;
    }
  }

  // ���ѭ�������������±��غϣ����������ֵ���ȥ��
  arr[ileft]=itmp;

  quicksort(arr,ileft);             // ����������ߵ����н�������
  quicksort(arr+ileft+1,len-ileft-1); // ���������ұߵ����н�������
}

int main(int argc,char *argv[])
{
  int arr[]={44,3,38,5,47,15,36,26,27,2,46,4,19,50,48};
  int len=sizeof(arr)/sizeof(int);

  quicksort(arr,len);   // ���ò�������������������

  // ��ʾ��������
  int yy; for (yy=0;yy<len;yy++) printf("%2d ",arr[yy]); printf("\n");

  // system("pause");  // widnows�µ�C���ñ��д��롣

  return 0;
}
