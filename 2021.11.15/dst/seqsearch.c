/*
 * ��������seqsearch.c���˳�����ʾ˳����ҡ�
 * ���ߣ�C���Լ�����(www.freecplus.net) ���ڣ�20210325
*/
#include <stdio.h>
#include <string.h>

// ������Ĳ��ұ����˳����ҡ�
// ��sstable�в���key��ʧ�ܷ���-1���ɹ�����key��sstable�е������±ꡣ
int Seq_Search1(int *sstable,unsigned int len,int key)
{
  int ii;

  for (ii=0;ii<len;ii++)  // ��ǰ�����Ӻ���ǰ�Ҷ��С�
    if (sstable[ii]==key) break;  // �ҵ��˾�break

  if (ii==len) return -1;  // ����ʧ��ʱ��ii==len

  return ii;
}

/*
// ������Ĳ��ұ����˳����Ҹ������д����
// ��sstable�в���key��ʧ�ܷ���-1���ɹ�����key��sstable�е������±ꡣ
int Seq_Search1(int *sstable,unsigned int len,int key)
{
  int ii;

  for (ii=0;ii<len&&sstable[ii]!=key;ii++)  // ��ǰ�����Ӻ���ǰ�Ҷ��С�
    ;

  return ii==len?-1:ii; 
}
*/

// �����ڱ�������Ĳ��ұ����˳����ҡ�
// ��sstable�в���key��ʧ�ܷ���0���ɹ�����key��sstable�е������±ꡣ
int Seq_Search2(int *sstable,unsigned int len,int key)
{
  int ii;

  sstable[0]=key;  // �ڱ���

  for (ii=len-1;sstable[ii]!=key;ii--)  // �Ӻ���ǰ�ҡ�
    ;                                   // ע���������䡣

  return ii;  // �Ҳ���ʱ��iiΪ0
}

// ������Ĳ��ұ����˳����ҡ�
// ��sstable�в���key��ʧ�ܷ���-1���ɹ�����key��sstable�е������±ꡣ
int Seq_Search3(int *sstable,unsigned int len,int key)
{
  int ii;

  for (ii=0;ii<len;ii++)  // ��ǰ�����Ӻ���ǰ�Ҷ��С�
  {
    if (sstable[ii]==key) break;  // �ҵ��˾�break
    if (sstable[ii] >key) return -1; // ���������ˣ�����-1
  }

  if (ii==len) return -1;  // ����ʧ��ʱ��ii==len

  return ii;
}

// ������Ծ�ķ���������Ĳ��ұ����˳����ҡ�
// ��sstable�в���key��ʧ�ܷ���-1���ɹ�����key��sstable�е������±ꡣ
int Seq_Search4(int *sstable,unsigned int len,int key)
{
  int ii=0;

  while (ii<len && sstable[ii]<key) ii=ii+3;  // ÿ����Ծ����Ԫ�ء�

  if (ii<len && sstable[ii]==key) return ii;  // ���ҳɹ��� 
  else if (ii-1<len && sstable[ii-1]==key) return ii-1;  // ���ҳɹ���
  else if (ii-2<len && sstable[ii-2]==key) return ii-2;  // ���ҳɹ���

  return -1;  // ����ʧ�ܡ�
}

int main()
{
  // ������Ĳ��ұ����˳����ҡ�
  int sstable1[]={2,5,6,3,1,7,4,8,9};
  int len=sizeof(sstable1)/sizeof(int);

  printf("result1=%d\n",Seq_Search1(sstable1,len,7));
  printf("result1=%d\n",Seq_Search1(sstable1,len,15));
  printf("result1=%d\n",Seq_Search1(sstable1,len,2));
  printf("result1=%d\n",Seq_Search1(sstable1,len,9));
  printf("\n");

  // �����ڱ�������Ĳ��ұ����˳����ҡ�
  int sstable2[]={0,2,5,6,3,1,7,4,8,9};
  len=sizeof(sstable2)/sizeof(int);

  printf("result2=%d\n",Seq_Search2(sstable2,len,7));
  printf("result2=%d\n",Seq_Search2(sstable2,len,15));
  printf("result2=%d\n",Seq_Search2(sstable2,len,2));
  printf("result2=%d\n",Seq_Search2(sstable2,len,9));
  printf("\n");

  // ������Ĳ��ұ����˳����ҡ�
  int sstable3[]={1,2,3,4,5,6,7,8,9};
  len=sizeof(sstable3)/sizeof(int);

  printf("result3=%d\n",Seq_Search3(sstable3,len,7));
  printf("result3=%d\n",Seq_Search3(sstable3,len,15));
  printf("result3=%d\n",Seq_Search3(sstable3,len,1));
  printf("result3=%d\n",Seq_Search3(sstable3,len,9));
  printf("\n");

  // ������Ծ�ķ���������Ĳ��ұ����˳����ҡ�
  int sstable4[]={1,2,3,4,5,6,7,8,9};
  len=sizeof(sstable4)/sizeof(int);

  printf("result4=%d\n",Seq_Search4(sstable4,len,0));
  printf("result4=%d\n",Seq_Search4(sstable4,len,7));
  printf("result4=%d\n",Seq_Search4(sstable4,len,15));
  printf("result4=%d\n",Seq_Search4(sstable4,len,1));
  printf("result4=%d\n",Seq_Search4(sstable4,len,9));
  printf("\n");

  return 0;
}
