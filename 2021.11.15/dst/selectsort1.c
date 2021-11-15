// �Ż����ѡ���������ߣ�C���Լ�������www.freecplus.net����ũ�е���
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

  int ileft,iright;   // ÿ���������������ҵ�λ�á�
  int ii;             // ÿ�������Ԫ��λ�ü�������
  int iminpos;        // ÿ��ѭ��ѡ������Сֵ��λ�ã�������±꣩��
  int imaxpos;        // ÿ��ѭ��ѡ�������ֵ��λ�ã�������±꣩��

  ileft=0; iright=len-1;  // ileft��0��ʼ��iright��len-1��ʼ��

  while (ileft<iright)
  {
    iminpos=imaxpos=ileft;

    for (ii=ileft;ii<=iright;ii++)  // ÿ��ѭ����ileft��iright֮��ѡȡԪ�ء�
    {
      // �ҳ�ֵ��С��Ԫ�أ���������λ�á�
      if (arr[ii]<arr[iminpos])  iminpos=ii;

      // �ҳ�ֵ�����Ԫ�أ���������λ�á�
      if (arr[ii]>arr[imaxpos])  imaxpos=ii;
    }

    // �������ѭ������С��Ԫ�ز�������ߵ�Ԫ�أ��򽻻����ǵ�λ�á�
    if (iminpos!=ileft) swap(&arr[ileft],&arr[iminpos]);

    // ���imaxpos��λ����ileft��������Ĵ�����ileft�ѱ���������iminpos��λ�á�
    // ����imaxpos��ֵҪ�޸�Ϊiminpos��
    if (imaxpos==ileft) imaxpos=iminpos;

    // �������ѭ��������Ԫ�ز������ұߵ�Ԫ�أ��򽻻����ǵ�λ�á�
    if (imaxpos!=iright) swap(&arr[iright],&arr[imaxpos]);

    ileft++;
    iright--;
  }
}



// ���õݹ�ʵ�ֵķ�����
// ����arr�Ǵ�����������׵�ַ��len������Ԫ�صĸ�����
void selectsort2(int *arr,unsigned int len)
{
  if (len<2) return;

  int ii;             // ÿ�������Ԫ��λ�ü�������
  int iminpos=0;      // ÿ��ѭ��ѡ������Сֵ��λ�ã�������±꣩��
  int imaxpos=0;      // ÿ��ѭ��ѡ�������ֵ��λ�ã�������±꣩��
  int ileft=0;
  int iright=len-1;

  for (ii=ileft;ii<=iright;ii++)  // ѭ����ileft��iright֮��ѡȡԪ�ء�
  {
    // �ҳ�ֵ��С��Ԫ�أ���������λ�á�
    if (arr[ii]<arr[iminpos])  iminpos=ii;

    // �ҳ�ֵ�����Ԫ�أ���������λ�á�
    if (arr[ii]>arr[imaxpos])  imaxpos=ii;
  }

  // �������ѭ������С��Ԫ�ز�������ߵ�Ԫ�أ��򽻻����ǵ�λ�á�
  if (iminpos!=ileft) swap(&arr[ileft],&arr[iminpos]);

  // ���imaxpos��λ����ileft��������Ĵ�����ileft�ѱ���������iminpos��λ�á�
  // ����imaxpos��ֵҪ�޸�Ϊiminpos��
  if (imaxpos==ileft) imaxpos=iminpos;

  // �������ѭ��������Ԫ�ز������ұߵ�Ԫ�أ��򽻻����ǵ�λ�á�
  if (imaxpos!=iright) swap(&arr[iright],&arr[imaxpos]);

  len=len-2;

  selectsort2(++arr,len);
}

int main(int argc,char *argv[])
{
  int arr[]={44,3,38,5,47,15,36,26,27,2,46,4,19,50,48};
  int len=sizeof(arr)/sizeof(int);

  // selectsort1(arr,len);  // ��������ѭ������ķ�����
  selectsort2(arr,len);  // ���õݹ�����ķ�����

  // ��ʾ��������
  int jj; for (jj=0;jj<len;jj++) printf("%2d ",arr[jj]); printf("\n");

  // system("pause");  // widnows�µ�C���ñ��д��롣

  return 0;
}
