// ȫʡ�߿��ɼ������㷨�����ߣ�C���Լ�������www.freecplus.net����ũ�е���
#include <stdio.h>

int main() 
{
  // ģ��ȫʡ�����ĳɼ���
  int score[]={581,575,632,581,750,522,576,581,580,582,630,710,508,749,250};

  int len=sizeof(score)/sizeof(int); // ������������

  int buckets[751]={0};        // ׼��751��Ͱ��

  int ii;    // ѭ���ļ�������

  // ��ÿ��ѧ���ĳɼ�������
  for (ii=0;ii<len;ii++) buckets[score[ii]]++;  

  // �����ÿ��������ȫʡ������
  for (ii=750-1;ii>=0;ii--) buckets[ii]=buckets[ii]+buckets[ii+1];

  int itmp=0;
  printf("�����뿼���ĳɼ���");
  scanf("%d",&itmp);
  printf("�ÿ���ȫʡ�����ǣ�%d\n",buckets[itmp]);

  // system("pause");  // widnows�µ�C���ñ��д��롣

  return 0;
}
