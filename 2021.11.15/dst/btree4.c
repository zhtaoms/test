/*
 * C���԰汾��
 * ��������btree4.c���˳�����ʾ�����������ĸ��ֲ������������롢ɾ�������ҡ�
 * ���ߣ�C���Լ�����(www.freecplus.net) ���ڣ�20200202
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

///////////////////////////////////////////////

typedef int ElemType;     // �Զ�������Ԫ��Ϊ������

// �����������ݽṹ��
typedef struct BSTNode
{
  ElemType   data;           // ��Ž�������Ԫ�ء�
  struct BSTNode *lchild;    // ָ�����ӽ���ַ��ָ�롣
  struct BSTNode *rchild;    // ָ�����ӽ���ַ��ָ�롣
}BSTNode,*BSTree;
///////////////////////////////////////////////

// ����TT�в���ؼ���Ϊee���½�㣨�ݹ�ʵ�֣�������ֵ��0-�����Ѵ��ڹؼ���Ϊee�Ľ�㣻1-�ɹ���
int Insert(BSTree *TT,ElemType *ee);
// ����TT�в���ؼ���Ϊee���½�㣨�ǵݹ�ʵ�֣�������ֵ��0-�����Ѵ��ڹؼ���Ϊee�Ľ�㣻1-�ɹ���
int Insert1(BSTree *TT,ElemType *ee);

// ������arr�е����й�������������TT��
// ��������д�������ԡ�
//void CreateBST(BSTree *TT,int arr[],int len);
void CreateBST(BSTree *TT,int *arr,int len);

// ����TT�в���ֵΪee�Ľ�㣨�ݹ�ʵ�֣����ɹ����ؽ��ĵ�ַ��ʧ�ܷ���NULL��
BSTNode *Find(BSTree TT,ElemType *ee);
// ����TT�в���ֵΪee�Ľ�㣨�ǵݹ�ʵ�֣����ɹ����ؽ��ĵ�ַ��ʧ�ܷ���NULL��
BSTNode *Find1(BSTree TT,ElemType *ee);

// ����TT��ɾ��ֵΪee�Ľ�㣬�ɹ�����0����㲻���ڷ���1��
int Delete(BSTree *TT,ElemType *ee);

// ��������ĸ߶ȡ�
int TreeDepth(BSTree TT);

// ���ʽ��Ԫ�ء�
void visit(BSTNode *pp);

// ���õݹ�ķ����Զ����������������
void PreOrder(BSTree TT);

// ���õݹ�ķ����Զ����������������
void InOrder(BSTree TT);

// ���õݹ�ķ����Զ������ĺ��������
void PostOrder(BSTree TT);

int main()
{
  BSTree TT=0; // ������ָ�������

  ElemType arr[]={50,66,60,26,21,30,70,68}; 

  /*
  // ������arr�е����й�������������TT��
  // �����Ķ��������������£�
              50
           /     \
          26      66
         /  \    /  \
        21  30 60   70
                   /
                  68
  */
  CreateBST(&TT,arr,sizeof(arr)/sizeof(ElemType));

  ElemType ee;

  // ����TT�в���ֵΪee�Ľ�㣬�ɹ����ؽ��ĵ�ַ��ʧ�ܷ���NULL��
  ee=30;
  BSTNode *ss=Find(TT,&ee);
  if (ss!=NULL) printf("���ҳɹ������ĵ�ַ��%p��ֵ��%d��\n",ss,ss->data);
  else printf("����ʧ�ܡ�\n");

  // �����������������
  printf("����������1��"); InOrder(TT); printf("\n");

  // ����TT��ɾ��ֵΪee�Ľ�㣬�ɹ�����0����㲻���ڷ���1��
  ee=50;
  printf("������ɾ��ֵΪee�Ľ�㣬Delete()�ķ���ֵ��%d��\n",Delete(&TT,&ee));

  // �����������������
  printf("����������2��"); InOrder(TT); printf("\n");

  return 0;
}

// �����������������
void PreOrder(BSTree TT)
{
  if (TT == NULL) return;

  visit(TT);               // ��������TT�ĸ���㡣
  PreOrder(TT->lchild);    // ������������
  PreOrder(TT->rchild);    // ������������
}

// �����������������
void InOrder(BSTree TT)
{
  if (TT == NULL) return;

  InOrder(TT->lchild);     // ������������
  visit(TT);               // ��������TT�ĸ���㡣
  InOrder(TT->rchild);     // ������������
}

// �������ĺ��������
void PostOrder(BSTree TT)
{
  if (TT == NULL) return;

  PostOrder(TT->lchild);     // ������������
  PostOrder(TT->rchild);     // ������������
  visit(TT);                 // ��������TT�ĸ���㡣
}

// ��������ĸ߶ȡ�
int TreeDepth(BSTree TT)
{
  if (TT==NULL) return 0;

  int ll=TreeDepth(TT->lchild);  // ���������ĸ߶ȡ�

  int rr=TreeDepth(TT->rchild);  // ���������ĸ߶ȡ�

  return ll>rr ? ll+1: rr+1;     // ȡ���������Ľϴ����ټ��ϸ����ĸ߶ȡ�
}

// ���ʽ��Ԫ�ء�
void visit(BSTNode *pp)
{
  printf("%d ",pp->data);  // ���ʽ��Ԫ�ؾ��ǰ�ֵ���������˼һ�¾����ˡ�
}

// ����TT�в���ؼ���Ϊee���½�㣨�ݹ�ʵ�֣�������ֵ��0-�����Ѵ��ڹؼ���Ϊee�Ľ�㣻1-�ɹ���
int Insert(BSTree *TT,ElemType *ee)
{
  // �����ǰ����Ϊ�գ����������ĸ���㡣
  if ((*TT)==NULL)
  {
    (*TT)=(BSTree)malloc(sizeof(BSTNode));
    memcpy(&(*TT)->data,ee,sizeof(ElemType));  // ��������Ԫ��eeΪ�ṹ������������memcpy������ֱ�Ӹ�ֵ��
    (*TT)->lchild=(*TT)->rchild=NULL;  // ��ǰ���������Һ���ָ���ÿա�
    return 1;  // ���سɹ���
  }

  if (*ee==(*TT)->data) return 0; // ���ee�Ѵ��ڣ�����ʧ�ܡ�

  if (*ee<(*TT)->data) Insert(&(*TT)->lchild,ee);  // �ݹ�������롣
  else Insert(&(*TT)->rchild,ee);  // �ݹ����Ҳ��롣
}

// ����TT�в���ؼ���Ϊee���½�㣨�ǵݹ�ʵ�֣�������ֵ��0-�����Ѵ��ڹؼ���Ϊee�Ľ�㣻1-�ɹ���
int Insert1(BSTree *TT,ElemType *ee)
{
  // �����Ϊ�գ��������ĸ���㡣
  if ((*TT)==NULL)
  {
    (*TT)=(BSTree)malloc(sizeof(BSTNode));
    memcpy(&(*TT)->data,ee,sizeof(ElemType));  // ��������Ԫ��eeΪ�ṹ������������memcpy������ֱ�Ӹ�ֵ��
    (*TT)->lchild=(*TT)->rchild=NULL;  // �������Һ���ָ���ÿա�
    return 1;  // ���سɹ���
  }

  BSTNode *pss=NULL;  // ��¼˫�׽��ĵ�ַ��
  BSTNode *ss=(*TT);  // ���ڲ��ҵ���ʱָ�롣
  int  rl=0;          // ��¼ss��˫�׽���������������������0-��������1-��������

  while (ss!=NULL)
  {
    if (*ee==ss->data) return 0; // ���ee�Ѵ��ڣ�����ʧ�ܡ�

    pss=ss;  // ��¼˫�׽��ĵ�ַ��
    if (*ee<ss->data) { ss=ss->lchild; rl=0; }  // ���������ߡ�
    else { ss=ss->rchild; rl=1; }  // ���������ߡ�
  }

  // �����½�㡣
  ss=(BSTree)malloc(sizeof(BSTNode));
  memcpy(&ss->data,ee,sizeof(ElemType));  // ��������Ԫ��eeΪ�ṹ������������memcpy������ֱ�Ӹ�ֵ��
  ss->lchild=ss->rchild=NULL;  // ��ǰ���������Һ���ָ���ÿա�

  // ��˫�׽��������ָ��ָ���·���Ľ�㡣
  if (rl==0) pss->lchild=ss;
  else pss->rchild=ss;

  return 1;  // ���سɹ���
}

// ������arr�е����й�������������TT��
// ��������д�������ԡ�
//void CreateBST(BSTree *TT,int arr[],int len)
void CreateBST(BSTree *TT,int *arr,int len)
{
  (*TT)=NULL;

  int ii=0;
  for (ii=0;ii<len;ii++)
  {
    Insert(TT,&arr[ii]);  // �������е�Ԫ������������С�
    // Insert1(TT,&arr[ii]);  // �������е�Ԫ������������С�
  }
}

// ����TT�в���ֵΪee�Ľ�㣨�ݹ�ʵ�֣����ɹ����ؽ��ĵ�ַ��ʧ�ܷ���NULL��
BSTNode *Find(BSTree TT,ElemType *ee)  
{
  if (TT==NULL) return NULL;    // ����ʧ�ܡ�

  if (*ee==TT->data) return TT;  // ���ҳɹ��� 

  if (*ee<TT->data) return Find(TT->lchild,ee); // �ݹ�������ҡ�
  else return Find(TT->rchild,ee);             // �ݹ����Ҳ��ҡ�
}

// ����TT�в���ֵΪee�Ľ�㣨�ǵݹ�ʵ�֣����ɹ����ؽ��ĵ�ַ��ʧ�ܷ���NULL��
BSTNode *Find1(BSTree TT,ElemType *ee)  
{
  BSTNode *ss=TT;  // ���ڲ��ҵ���ʱָ�룬Ҳ����ֱ����TT��

  while (ss!=NULL) 
  {
    if (*ee==ss->data) return ss;  // �ɹ��ҵ���

    if (*ee<ss->data) ss=ss->lchild;  // ���������ߡ�
    else ss=ss->rchild;  // ���������ߡ�
  }

  return NULL;

  /*
  // ���´�������򣬿���ȡ�����ϵĴ��롣
  while ( (TT!=NULL) && (*ee!=TT->data) )
  {
    if (*ee<TT->data) TT=TT->lchild;  // ���������ߡ�
    else TT=TT->rchild;  // ���������ߡ�
  }

  return TT;
  */
}

// ����TT��ɾ��ֵΪee�Ľ�㣬�ɹ�����0����㲻���ڷ���1��
int Delete(BSTree *TT,ElemType *ee)  
{
  if ((*TT)==NULL) return 1; // ��Ϊ�գ�����1��

  // 1�������ֻ�и���㣬���Ҵ�ɾ���Ľ����Ǹ���㡣
  if ( ((*TT)->data==*ee) && ((*TT)->lchild==NULL) && ((*TT)->rchild==NULL) )
  {
    free(*TT); (*TT)=0; return 0;
  }

  BSTNode *pss=NULL;  // ��¼˫�׽��ĵ�ַ��
  BSTNode *ss=(*TT);  // ���ڲ��ҵ���ʱָ�롣
  int  rl=0;          // ��¼ss��˫�׽���������������������0-��������1-��������

  // ���Ҵ�ɾ���Ľ�㡣
  while (ss!=NULL) 
  {
    if (*ee==ss->data) break;  // �ɹ��ҵ���

    pss=ss;  // ��¼˫�׽��ĵ�ַ��
    if (*ee<ss->data) { ss=ss->lchild; rl=0; }  // ���������ߡ�
    else { ss=ss->rchild; rl=1; }  // ���������ߡ�
  }

  // ��㲻���ڣ�����1��
  if (ss==NULL) return 1;

  // 2�������ɾ���Ľ��ss��Ҷ��㣬ֱ��ɾ���������ƻ����������������ʡ�
  if ( (ss->lchild==NULL) && (ss->rchild==NULL) )
  {
    free(ss);   // �ͷŽ�㡣

    // �޸�˫�׽��pss�������ָ��ָ��NULL��
    if (rl==0) pss->lchild=NULL;
    else pss->rchild=NULL;

    return 0;  // ���سɹ���
  }
  
  // 3�������ɾ���Ľ��ssֻ�������������������������������Լ���
  if ( (ss->lchild==NULL) || (ss->rchild==NULL) )
  {
    if (ss->lchild!=NULL)  // ����������
    {
      // �޸�˫�׽��pss�������ָ��ָ��ss����������
      if (rl==0) pss->lchild=ss->lchild;
      else pss->rchild=ss->lchild;
    }
    else  // ����������
    {
      // �޸�˫�׽��pss�������ָ��ָ��ss����������
      if (rl==0) pss->lchild=ss->rchild;
      else pss->rchild=ss->rchild;
    }

    return 0;  // ���سɹ���
  }

  // 4�������ɾ���Ľ��ss�����������������������������Ҳ�Ľ������Լ���Ȼ����ɾ�����������Ҳ�Ľ�㡣
  // Ҳ�����������������Ľ������Լ���Ȼ��ɾ�������������Ľ�㡣
  BSTNode *pss1=ss;        // ��¼˫�׽��ĵ�ַ��
  BSTNode *ss1=ss->lchild; // ���ڲ��ҵ���ʱָ�롣
  int  rl1=0;              // ��¼ss1��˫�׽���������������������0-��������1-��������

  // �����������ߵ���ͷ��
  while (ss1->rchild!=NULL)
  {
    rl1=1; pss1=ss1; ss1=ss1->rchild;
  }
  
  // �����������Ҳ�Ľ��ֵ���Ƶ����ss�С�
  memcpy(&ss->data,&ss1->data,sizeof(ElemType));

  // ���������Ҳ�Ľ��ss1�ض�����������
  // �޸�˫�׽��pss1�������ָ��ָ��ss1����������ss1������������Ϊ�ա�
  if (rl1==0) pss1->lchild=ss1->lchild;
  else pss1->rchild=ss1->lchild;

  free(ss1);  // �ͷ�ss1��

  return 0;
}
