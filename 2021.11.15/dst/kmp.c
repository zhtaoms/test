/*
 * ��������kmp.c���˳�����ʾ���ַ�����ƥ��ģʽ�㷨��������
 * 1����ͨ��ģʽƥ���㷨����BF�㷨��
 * 2��KMP�㷨����next���飻
 * 3��KMP�㷨����nextval���飻
 * 4��KMP�㷨��ʵ�֡�
 * ���ߣ�C���Լ�����(www.freecplus.net) ���ڣ�20210125
*/
#include <stdio.h>
#include <string.h>

// ����BF�㷨��������Ŀ�괮sstr��ģʽ��tstr���ֵ�λ�ã��ַ�������ʼλ�ô�0��ʼ��
// ֻҪ��Ŀ�괮sstr���ҵ��˵�һ��ģʽ��tstr�������ͷ��ء�
// �ɹ�����ģʽ��tstr��Ŀ�괮sstr�е�һ�γ��ֵ������±꣬ʧ�ܷ���-1��
int index_bf(char sstr[],char tstr[])
// int index_bf(char *sstr,char *tstr)
{
  if ( (sstr==0) || (tstr==0) ) return -1;  // �жϿ�ָ�롣

  // Ŀ�괮sstr��ģʽ��tstr���������±�0��ʼ��
  int ii=0,jj=0;  // ѭ����0��ʼ��
  int slen=strlen(sstr),tlen=strlen(tstr);
  
  while ( (ii<slen) && (jj<tlen) )
  {
    if (sstr[ii] == tstr[jj]) 
    {
      ii++; jj++;  // �����ȽϺ�����ַ���
    }
    else
    {
      ii=ii-jj+1; jj=0; // Ŀ�괮��ģʽ����ָ�붼���ݡ�
    }
  }

  // ƥ��ɹ���
  if (jj==tlen) return ii-tlen;

  return -1;
}

// ����ģʽ��tstr������next���飬�ַ�������ʼλ�ô�0��ʼ��
// void getnext(char *tstr,int *next)
void getnext(char tstr[],int next[])
{
  if ( (tstr==0) || (next==0) ) return;  // �жϿ�ָ�롣

  int tlen=strlen(tstr);  // ģʽ���ĳ��ȡ�

  // ���ģʽ���ĳ���С��3���������next���飬ֱ�ӷ��ء�
  if (tlen==0) return;
  if (tlen==1) { next[0]=-1; return; }
  if (tlen==2) { next[0]=-1; next[1]=0; return; }

  next[0]=-1;  // λ��0ֱ������-1��
  next[1]=0;   // λ��1ֱ������0��

  // �������Ա��������ſ�// xxx�Ϳ����ˡ�

  int ii;

  // ѭ����2��ʼ��λ��0��1���ؼ��㡣
  for (ii=2;ii<tlen;ii++)
  {
    // ��ʾ�Ӵ���
    // xxx char p0[tlen]; 
    // xxx memset(p0,0,sizeof(p0));
    // xxx strncpy(p0,tstr,ii); 
    // xxx printf("p0=%s  ",p0);

    int maxlen=0;  // �����ǰ��׺�ĳ��ȡ�

    // ��һ��ѭ�����õ�ȫ����ǰ׺�ͺ�׺�����ж������ǰ��׺��
    int jj=1;
    for (jj=1;jj<ii;jj++)
    { 
      char p1[tlen],p2[tlen]; 
      memset(p1,0,sizeof(p1));
      memset(p2,0,sizeof(p2));

      strncpy(p1,tstr,jj);       // ȡǰ׺��
      strncpy(p2,tstr+ii-jj,jj); // ȡ��׺��

      // xxx printf("%s %s    ",p1,p2);

      // �ж�ǰ��׺�Ƿ���ͬ����ͬ�ͼ���jj��ֵ��
      if (strcmp(p1,p2)==0) maxlen=jj;
    }

    // xxx printf(" maxlen=%d\n",maxlen);  
    next[ii]=maxlen;
  }

  // xxx printf("next "); int kk;for (kk=0;kk<strlen(tstr);kk++) printf("%d ",next[kk]); printf("\n");

  return ;
}

// ����ģʽ��tstr��next�������nextval���飬�ַ�������ʼλ�ô�0��ʼ��
// void getnextval(char *tstr,int *next,int *nextval)
void getnextval(char tstr[],int next[],int nextval[])
{
  if ( (tstr==0) || (next==0) || (nextval==0) ) return;  // �жϿ�ָ�롣

  int tlen=strlen(tstr);  // ģʽ���ĳ��ȡ�
  
  nextval[0]=-1;   // λ��0ֱ������-1��

  int ii;

  // �ӵ�1��λ�ÿ�ʼɨ�衣
  for (ii=1;ii<tlen;ii++)
  {
    if (tstr[ii]==tstr[next[ii]]) 
      nextval[ii]=nextval[next[ii]];
    else
      nextval[ii]=next[ii];
  }
}

// ����kmp�㷨��������Ŀ�괮sstr��ģʽ��tstr���ֵ�λ�ã��ַ�������ʼλ�ô�0��ʼ��
// ֻҪ��Ŀ�괮sstr���ҵ��˵�һ��ģʽ��tstr�������ͷ��ء�
// �ɹ�����ģʽ��tstr��Ŀ�괮sstr�е�һ�γ��ֵ������±꣬ʧ�ܷ���-1��
// int index_kmp(char *sstr,char *tstr)
int index_kmp(char sstr[],char tstr[])
{
  if ( (sstr==0) || (tstr==0) ) return -1;  // �жϿ�ָ�롣

  // Ŀ�괮sstr��ģʽ��tstr���������±�0��ʼ��
  int ii=0,jj=0;  
  int slen=strlen(sstr),tlen=strlen(tstr);
  
  // ��ȡnext���顣
  int next[tlen]; 
  getnext(tstr,next);

  // ����ģʽ��tstr��next�������nextval���飬�ַ�������ʼλ�ô�0��ʼ��
  int nextval[tlen]; 
  getnextval(tstr,next,nextval);

  while ( (ii<slen) && (jj<tlen) )
  {
    if ( (jj==-1) || (sstr[ii] == tstr[jj]) )
    {
      ii++; jj++;  // �����ȽϺ�����ַ���
    }
    else
    {
      // jj=next[jj]; // ����next����ģʽ��ָ����ݡ�
      jj=nextval[jj]; // ����nextval����ģʽ��ָ����ݡ�
    }
  }

  // ƥ��ɹ���
  if (jj==tlen) return ii-tlen;

  return -1;
}

int main()
{
  //////////////////////////////////
  // ��ȡģʽ����next���飬�ַ�����λ�ô�0��ʼ��
  char tmp[100];
  memset(tmp,0,sizeof(tmp));
  strcpy(tmp,"baabaa");
  int next[100];
  getnext(tmp,next);
  printf("next    "); int kk;for (kk=0;kk<strlen(tmp);kk++) printf("%d ",next[kk]); printf("\n");
  //////////////////////////////////

  //////////////////////////////////
  // ����ģʽ��tstr��next�������nextval���飬�ַ�������ʼλ�ô�0��ʼ��
  int nextval[100];
  getnextval(tmp,next,nextval);
  printf("nextval "); int ll;for (ll=0;ll<strlen(tmp);ll++) printf("%d ",nextval[ll]); printf("\n");
  //////////////////////////////////

  //////////////////////////////////
  // �ж�ģʽ����Ŀ�괮�Ƿ�ƥ�䡣
  char sstr[100]; memset(sstr,0,sizeof(sstr));
  char tstr[100]; memset(tstr,0,sizeof(tstr));
  strcpy(sstr,"aabaabcbcabaabc"); 
  strcpy(tstr,"abaabc");
  printf("index_bf =%d\n", index_bf(sstr,tstr));
  printf("index_kmp=%d\n",index_kmp(sstr,tstr));
  //////////////////////////////////
}
