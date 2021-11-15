/*
 * ��������seqstack3.c���˳�����ʾ��˳��ջʵ����׺���ʽת��׺���ʽ��
 * ���ߣ�C���Լ�����(www.freecplus.net) ���ڣ�20201230
*/
#include <stdio.h>
#include <string.h>

#define MAXSIZE 100      // ˳��ջ����󳤶ȡ�   // xxxxx

typedef char ElemType;    // �Զ���˳��ջ������Ԫ��Ϊ�ַ��� // xxxx

typedef struct
{
  ElemType data[MAXSIZE];   // ������洢˳��ջ�е�Ԫ�ء�
  int top;                  // ջ��ָ�룬��0��MAXSIZE-1��-1��ʾ��ջ��
                            // Ҳ���Դ�1��MAXSIZE��0��ʾ��ջ��
}SeqStack,*PSeqStack;

// ˳��ջSS�ĳ�ʼ��������
void InitStack(PSeqStack SS);                     

// ����˳��ջSS��
void DestroyStack(PSeqStack SS);

// Ԫ����ջ������ֵ��0-ʧ�ܣ�1-�ɹ���
int Push(PSeqStack SS, ElemType *ee);

// Ԫ�س�ջ������ֵ��0-ʧ�ܣ�1-�ɹ���
int Pop(PSeqStack SS, ElemType *ee);

// ��˳��ջ�ĳ��ȣ�����ֵ��ջSS��Ԫ�صĸ�����
int Length(PSeqStack SS);                   

// ���˳��ջ��
void Clear(PSeqStack SS);                    

// �ж�˳��ջ�Ƿ�Ϊ�գ�����ֵ��1-�գ�0-�ǿջ�ʧ�ܡ�
int IsEmpty(PSeqStack SS);                    

// �ж�˳��ջ�Ƿ�����������ֵ��1-������0-δ����ʧ�ܡ�
int IsFull(PSeqStack SS);

// ��ӡ˳��ջ��ȫ����Ԫ�ء�
void PrintStack(PSeqStack SS);                    

// ��ȡջ��Ԫ�أ�����ֵ��0-ʧ�ܣ�1-�ɹ���
// ֻ�鿴ջ��Ԫ�ص�ֵ��Ԫ�ز���ջ��
int GetTop(PSeqStack SS, ElemType *ee);

// ����׺���ʽstr1ת��Ϊ��׺���ʽstr2��
int torpolish(char *str1,char *str2);

int main(int argc,char *argv[])
{
  char str1[101],str2[101];  
  memset(str1,0,sizeof(str1));
  memset(str2,0,sizeof(str2));

  printf("�������ת���ı��ʽ��");
  fgets(str1,100,stdin);     // ��������gets������gets��������ʱ���ܻ���־��š�
  str1[strlen(str1)-1]=0;    // ɾ��str1���Ļ��С�
  printf("����ת���ı��ʽ=%s=\n",str1);

  // ����׺���ʽstr1ת��Ϊ��׺���ʽstr2��
  if (torpolish(str1,str2) == 0) { printf("ת��ʧ�ܡ�\n"); return -1; }

  printf("ת���ɹ�=%s=��\n",str2);

  return 1;
}

// ����׺���ʽstr1ת��Ϊ��׺���ʽstr2��
int torpolish(char *str1,char *str2)
{
  SeqStack SS;     // ����˳��ջ��
  InitStack(&SS);  // ��ʼ��˳��ջ��

  ElemType ee;     // ����һ������Ԫ�ء�

  int ipos1=0,len=strlen(str1),ipos2=0;

  // ������ɨ����׺���ʽ��
  for (ipos1=0;ipos1<len;ipos1++)
  {
    // ���ֺ���ĸֱ��׷�ӵ���׺���ʽ���档
    if ( ( (str1[ipos1]>='0') && (str1[ipos1]<='9') ) ||
         ( (str1[ipos1]>='a') && (str1[ipos1]<='z') ) ||
         ( (str1[ipos1]>='A') && (str1[ipos1]<='Z') ) )
    {
      str2[ipos2]=str1[ipos1]; ipos2++; continue;
    }

    // ������'('ֱ����ջ��
    if (str1[ipos1]=='(')  { Push(&SS,&str1[ipos1]); continue; }

    // �����������')'�����ε���ջ�е��������׷�ӵ���׺���ʽ�У�ֱ������������'('��
    if (str1[ipos1]==')')  
    {
      while (1)
      {
        // һ��Ҫ�жϳ�ջ��������ջ��û��Ԫ�أ�ת��ʧ�ܣ���Ϊû�ҵ�������'('����
        if ( Pop(&SS,&ee) != 1) return 0;  
        if ( ee == '(') break;
        str2[ipos2]=ee; ipos2++;
      }

      continue;
    }

    // ��������������'+'��'-'��'*'��'/'��
    if ( (str1[ipos1]=='+') || (str1[ipos1]=='-') || (str1[ipos1]=='*') || (str1[ipos1]=='/') )
    {
      while (1)
      {
        // ��ȡջ������������ջΪ�գ���ǰ�����ֱ����ջ��
        if (GetTop(&SS,&ee) != 1) break;

        if ( ee=='(' ) break;  // ������������ţ�ֹͣ�жϣ���ǰ���������ջ��

        int pri1;   // ��ǰ����������ȼ���
        int pri2;   // ջ������������ȼ���

        if ( (str1[ipos1]=='+') || (str1[ipos1]=='-') ) pri1=1;
        if ( (str1[ipos1]=='*') || (str1[ipos1]=='/') ) pri1=2;
        if ( (ee=='+') || (ee=='-') ) pri2=1;
        if ( (ee=='*') || (ee=='/') ) pri2=2;

        // �����ǰ����������ȼ� ���� ջ������������ȼ���ֹͣ�жϣ���ǰ���������ջ��
        if (pri1>pri2) break;  
        
        // ��ջ�����ȼ� ���ڵ��� ��ǰ�������Ԫ�����ε�����׷�ӵ���׺���ʽ���档
        Pop(&SS,&ee); str2[ipos2]=ee; ipos2++; continue;
      }

      // ��ǰ�������ջ��
      Push(&SS,&str1[ipos1]); 

      continue;
    }
  }

  // ����ջ���������������׷�ӵ���׺���ʽ���档
  while (1)
  {
    if (Pop(&SS,&ee)!=1) break;

    str2[ipos2]=ee; ipos2++;
  }

  return 1;
}

// ��ʼ��˳��ջ
void InitStack(PSeqStack SS)
{
  Clear(SS); // ���˳��ջ��
}

// ���˳��ջ��
void Clear(PSeqStack SS)
{
  if (SS == NULL) return; // ����ָ�롣

  SS->top=-1;  // ջ��ָ����Ϊ-1��
  memset(SS->data,0,sizeof(ElemType)*MAXSIZE);  // ����Ԫ�����㡣
}

// ��˳��ջ�ĳ��ȣ�����ֵ��ջSS��Ԫ�صĸ�����
int Length(PSeqStack SS)
{
  if (SS == NULL) return 0; // ����ָ�롣

  return SS->top+1;
}

// ����˳��ջSS��
void DestroyStack(PSeqStack SS)
{
  // ��̬˳��ջ�����ͷ��ڴ棬����Ҫ���ٲ�����

  Clear(SS); // ���˳��ջ��

  return;
}

// �ж�˳��ջ�Ƿ�Ϊ�գ�����ֵ��1-�գ�0-�ǿջ�ʧ�ܡ�
int IsEmpty(PSeqStack SS)
{
  if (SS == NULL) return 0;  // ����ָ�롣

  if (SS->top == -1) return 1;

  return 0;
}

// �ж�˳��ջ�Ƿ�����������ֵ��1-������0-δ����ʧ�ܡ�
int IsFull(PSeqStack SS)
{
  if (SS == NULL) return 0;  // ����ָ�롣

  if (SS->top >= MAXSIZE-1) return 1;

  return 0;
}

// Ԫ����ջ������ֵ��0-ʧ�ܣ�1-�ɹ���
int Push(PSeqStack SS, ElemType *ee)
{
  if ( (SS == NULL) || (ee == NULL) ) return 0;  // ����ָ�롣

  if (IsFull(SS) == 1)
  {
    printf("˳��ջ���������ܲ��롣\n"); return 0;
  }

  SS->top++;  // ջָ���ȼ�1��

  memcpy(&SS->data[SS->top],ee,sizeof(ElemType));  // ��������±���ʡ�
  // memcpy(SS->data+SS->top,ee,sizeof(ElemType));    // ����ָ������Ҳ���ԡ�

  return 1;
}

// ��ӡ˳��ջ��ȫ����Ԫ�ء�
void PrintStack(PSeqStack SS)
{
  if (SS == NULL) return;  // ����ָ�롣

  if (SS->top == -1) { printf("ջΪ�ա�\n"); return; }

  int kk;
  for (kk = 0; kk <= SS->top; kk++)
  {
    printf("SS[%d],value=%c\n",kk,SS->data[kk]);     // ��������±���ʡ� xxx
    // printf("SS[%d],value=%d\n",kk,*(SS->data+kk));   // ����ָ������Ҳ���ԡ�
  }
}

// Ԫ�س�ջ������ֵ��0-ʧ�ܣ�1-�ɹ���
int Pop(PSeqStack SS, ElemType *ee)
{
  if ( (SS == NULL) || (ee == NULL) ) return 0;  // ����ָ�롣

  if (SS->top == -1) { printf("ջΪ�ա�\n"); return 0; }

  memcpy(ee,&SS->data[SS->top],sizeof(ElemType));  // ��������±���ʡ�
  // memcpy(ee,SS->data+SS->top,sizeof(ElemType));    // ����ָ������Ҳ���ԡ�

  SS->top--;  // ջָ���1��

  return 1;
}

// ��ȡջ��Ԫ�أ�����ֵ��0-ʧ�ܣ�1-�ɹ���
// ֻ�鿴ջ��Ԫ�ص�ֵ��Ԫ�ز���ջ��
int GetTop(PSeqStack SS, ElemType *ee)
{
  if ( (SS == NULL) || (ee == NULL) ) return 0;  // ����ָ�롣

  if (IsEmpty(SS) == 1) { printf("ջΪ�ա�\n"); return 0; }

  memcpy(ee,&SS->data[SS->top],sizeof(ElemType));  // ��������±���ʡ�
  // memcpy(ee,SS->data+SS->top,sizeof(ElemType));    // ����ָ������Ҳ���ԡ�

  return 1;
}
