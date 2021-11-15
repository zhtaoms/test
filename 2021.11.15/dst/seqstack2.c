/*
 * ��������seqstack2.c���˳�����ʾ��˳��ջ��������Ƿ�ƥ�䣬֧��()[]{}�������š�
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

// �����ʽ�����Ƿ�ƥ�䣬����ֵ��0-��ƥ�䣬1-ƥ�䡣
int checkbrackets(char *str);

int main()
{
  char str[101];  
  memset(str,0,sizeof(str));

  printf("������������ַ�����");
  fgets(str,100,stdin);    // ��������gets������gets��������ʱ���ܻ���־��š�
  str[strlen(str)-1]=0;    // ɾ��str���Ļ��С�
  printf("������ַ�����=%s=\n",str);

  if (checkbrackets(str) == 0) { printf("ƥ��ʧ�ܡ�\n"); return -1; }

  printf("ƥ��ɹ���\n");

  return 1;
}

// �����ʽ�����Ƿ�ƥ�䣬����ֵ��0-��ƥ�䣬1-ƥ�䡣
int checkbrackets(char *str)
{
  SeqStack SS;     // ����˳��ջ��
  InitStack(&SS);  // ��ʼ��˳��ջ��

  ElemType ee;     // ����һ������Ԫ�ء�

  int ipos=0,len=strlen(str);

  for (ipos=0;ipos<len;ipos++)
  {
    // ����������ţ���ջ��
    if ( (str[ipos]=='(') || (str[ipos]=='[') || (str[ipos]=='{') ) Push(&SS,&str[ipos]);
    //if ( (str[ipos]=='(') || (str[ipos]=='[') || (str[ipos]=='{') ) Push(&SS,str+ipos); // ��ָ������Ҳ���ԡ�

    // ����������ţ���ջ�����ж��Ƿ�ƥ�䡣
    if ( (str[ipos]==')') || (str[ipos]==']') || (str[ipos]=='}') ) 
    {
      // һ��Ҫ�жϳ�ջ��������ջ��û��Ԫ�أ�ƥ��ʧ�ܡ�
      if (Pop(&SS,&ee) != 1) return 0; 

      // ֻҪ�����˲�ƥ���������������ء�
      if ( (str[ipos]==')') && (ee!='(') ) return 0; 
      if ( (str[ipos]==']') && (ee!='[') ) return 0; 
      if ( (str[ipos]=='}') && (ee!='{') ) return 0; 
    }
  }

  // ���ȫ�������Ŷ�ƥ�䣬ջһ���ǿյġ�
  return IsEmpty(&SS);
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
    printf("SS[%d],value=%c\n",kk,SS->data[kk]);     // ��������±���ʡ�  // xxx
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
