// ����ѭ���ķ���ʵ�ֹ鲢�������������ߣ�C���Լ�������www.freecplus.net����ũ�е���
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int min(int x,int y) { return x<y ? x : y; }  // ȡx��y�еĽ�С�ߵ�ֵ��

// ����ѭ��ʵ�ֹ鲢����arr-������������׵�ַ��len--����������ĳ��ȡ�
void mergesort(int *arr,unsigned int len) 
{
  if (len<2) return;  // С������Ԫ�ز���Ҫ����

  int *aa=arr;     // aaָ�����������顣
  int *bb=(int *)malloc(len*sizeof(int)); // bbָ������������顣

  int iseg;    // ����ֶεļ�������1,2,4,8,16,...
  int istart;  // ������ʼλ�õļ�������

  // �����������ѭ����
  for (iseg=1;iseg<len;iseg=iseg*2) 
  {
    // ÿ������ѡȡ�����ѭ����
    for (istart=0;istart<len;istart=istart+iseg*2) 
    {
      // ��ÿ������ֳ������֣�ilow����ʼλ�ã�imid���м�λ�ã�imax�ǽ���λ�á�
      int ilow=istart;
      int imid=min(istart+iseg,len);     // ���Ƿֶβ����������imid���ܳ���len��
      int imax=min(istart+iseg*2,len);   // ���Ƿֶβ����������imaxҲ���ܳ���len��

      int ii=ilow; // ����������ļ�������
      int istart1=ilow,iend1=imid;  // ������������е���ʼ�ͽ���λ�á�
      int istart2=imid,iend2=imax;  // �������ұ����е���ʼ�ͽ���λ�á�

      // �Ѵ����������������кϲ������������顣
      while ((istart1<iend1) && (istart2<iend2))
        bb[ii++]=aa[istart1]<aa[istart2] ? aa[istart1++] : aa[istart2++];

      // ���������������Ԫ��׷�ӵ����������顣
      while (istart1<iend1) bb[ii++]=aa[istart1++];

      // ���ұ�����������Ԫ��׷�ӵ����������顣
      while (istart2<iend2) bb[ii++]=aa[istart2++];
    }

    // ����һ�����������ָ�룬׼����һ�˵�����
    int *ptmp=aa; aa=bb; bb=ptmp;
  }

  // ���aaָ��Ĳ���ԭʼ�����ָ�룬��aa�е����ݸ��Ƶ�arr�С�
  if (aa != arr) 
  {
    memcpy(arr,aa,len*sizeof(int));

    bb = aa;
  }

  free(bb);
}

int main(int argc,char *argv[])
{
  int arr[]={44,3,38,5,47,15,36,26,27,2,46,4,19,50,48,10};
  int len=sizeof(arr)/sizeof(int);

  mergesort(arr,len);

  // ��ʾ��������
  int yy; for (yy=0;yy<len;yy++) printf("%2d ",arr[yy]); printf("\n");

  // system("pause");  // widnows�µ�C���ñ��д��롣

  return 0;
}

