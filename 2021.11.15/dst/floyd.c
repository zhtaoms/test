/*
 * ��������floyd.c���˳�����ʾ���������㷨��floyd����
 * ���ߣ�C���Լ�����(www.freecplus.net) ���ڣ�20200202
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define VEXNUM   5      // ͼ�Ķ�������

void print(int AA[][VEXNUM]) // ��ʾ����
{
  int ii,jj;
  for (ii=0;ii<VEXNUM;ii++)
  {
    for (jj=0;jj<VEXNUM;jj++)
      printf("%5d",AA[ii][jj]);

    printf("\n");
  }
}

int main()
{
  // ��ʼ������
  int AA[VEXNUM][VEXNUM]={\
        0  ,999,  1,999, 10,\
        999,  0,999,  1,  5,\
        999,  1,  0,999,  7,\
        999,999,999,  0,  1,\
        999,999,999,999,  0 };

  int path[VEXNUM][VEXNUM]={\
        -1,-1,-1,-1,-1,\
        -1,-1,-1,-1,-1,\
        -1,-1,-1,-1,-1,\
        -1,-1,-1,-1,-1,\
        -1,-1,-1,-1,-1};

  printf("init\n"); print(AA); print(path);  printf("\n");

  int kk,ii,jj;

  for (kk=0; kk<VEXNUM; kk++) {   // ����ȫ���Ķ��㡣
    printf("kk=%d\n",kk); 

    // ������������ii���У�jj���С�
    for (ii=0; ii<VEXNUM; ii++) {
      for (jj=0; jj<VEXNUM; jj++) {
        // �������kk��ת��·�����̣�����¾���
        if ( AA[ii][kk] + AA[kk][jj] < AA[ii][jj]) {
          // �������·����������ת���㡣
          AA[ii][jj] = AA[ii][kk] + AA[kk][jj]; 
          path[ii][jj] = kk;  
          printf("AA[%d][%d] updated.\n",ii,jj);
        }
      }
    }

    print(AA); print(path);  printf("\n");
  }
  
  // print(AA); print(path);

  return 0;
}

