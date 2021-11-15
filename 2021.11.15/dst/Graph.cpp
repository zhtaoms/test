/*
 * ��������Graph.cpp���˳�����ͼ�½ڸ����㷨��α���롣
 * ���ߣ�C���Լ�����(www.freecplus.net) ���ڣ�20200302
*/
//////////////////////////////////////////////////////////////////
// ͼ�Ĺ����������α���뿪ʼ��

bool visited[MAXVERNUM];   // ��Ƕ����Ƿ��ѷ��ʵ����顣

// ͼ�Ĺ����������
void BFST(Graph G,int v)  
{
  // ��ʼ�����ʱ������Ϊfalse��
  for ( i=0; i<MAXVERNUM; i++ ) visited[i]=false;
  
  InitQueue(Q);  // ��ʼ���������С�

  BFS(G,v);      // �Ӷ���v��ʼ��ͼ���й������������

  // ����������ͨ�������й������������
  for (i=1;i<G.vexnum;i++) 
    if ((visited[i]==false) BFS(G,i); 
}

// ͼ�Ĺ������������������
void BFS(Graph G,int v)  // �Ӷ���v��ʼ������ͼG��
{
  visit(v);         // ���ʶ���v��
  visited[v]=true;  // ��Ƕ���vΪ�ѷ��ʡ�
  EnQueue(Q,v);     // ����v��ӡ�

  while (IsEmpty(Q)==false) { // ������в�Ϊ�ա�
    DeQueue(Q,u);        // ��ͷ������ӣ�������u�С�
    // forѭ����ȡ����uȫ���ıߡ�
    for ( w=FirstAdjVex(G,u); w>=0; w=NextAdjVex(G,u,w) ) {
      if (visited[w]==false) {
        visit(w);        // ���ʶ���w��
        visited[w]=true; // ��Ƕ���wΪ�ѷ��ʡ�
        EnQueue(Q,w);    // ����w��ӡ�
      } // if
    } // for
  } // while
}

// ͼ�Ĺ����������α���������
//////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////
// ͼ�������������α���뿪ʼ��

bool visited[MAXVERNUM];   // ��Ƕ����Ƿ��ѷ��ʵ����顣

// ͼ�������������
void DFST(Graph G,int v)  
{
  // ��ʼ�����ʱ������Ϊfalse��
  for ( i=0; i<MAXVERNUM; i++ ) visited[i]=false;
  
  DFS(G,v);   // �Ӷ���v��ʼ��ͼ�����������������

  // ����������ͨ���������������������
  for (i=1;i<G.vexnum;i++) 
    if ((visited[i]==false) DFS(G,i); 
}

// ͼ���������������������
void DFS(Graph G,int v)  // �Ӷ���v��ʼ��
{
  visit(v);         // ���ʶ���v��
  visited[v]=true;  // ��Ƕ���vΪ�ѷ��ʡ�

  // forѭ����ȡ����vȫ���ıߡ�
  for ( w=FirstAdjVex(G,v); w>=0; w=NextAdjVex(G,v,w) ) 
    if (visited[w]==false) 
      DFS(G,w);     // �Զ���w�ݹ���ã�����ߡ�
}

// ͼ�������������α���������
//////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////
// ����ͼ�Ĺ��������������Ȩͼ�����·��α���뿪ʼ��

bool visited[MAXVERNUM];   // ��Ƕ����Ƿ��ѷ��ʵ����顣
bool dist[MAXVERNUM];      // ��������·����-1-��·����
bool path[MAXVERNUM];      // �����ǰ�����㣬-1-��ǰ����

void BFSMinDist(Graph G,int v)  // �Ӷ���v��������������·����
{
  // ��ʼ�����ʱ�ǡ����·����ǰ���������顣
  for ( i=0; i<MAXVERNUM; i++ ) {
    visited[i]=false; dist[i]=-1; path[i]=-1;
  }

  dist[v]=0;        // ����v��·��Ϊ0��
  visited[v]=true;  // ��Ƕ���vΪ�ѷ��ʡ�
  EnQueue(Q,v);     // ����v��ӡ�

  while (IsEmpty(Q)==false) { // ������в�Ϊ�ա�
    DeQueue(Q,u);             // ��ͷ������ӣ�������u�С�
    // forѭ����ȡ����uȫ���ıߡ�
    for ( w=FirstAdjVex(G,u); w>=0; w=NextAdjVex(G,u,w) ) {
      if (visited[w]==false) {
        dist[w]=dist[u]+1;  // ����w��·�����ȼ�1��
        path[w]=u;          // ����w��ǰ������Ϊv��
        visited[w]=true;    // ��Ƕ���wΪ�ѷ��ʡ�
        EnQueue(Q,w);       // ����w��ӡ�
      } // if
    } // for
  } // while
}

// ����ͼ�Ĺ��������������Ȩͼ�����·��α���������
//////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////
// ��������α���뿪ʼ��

// ������������������ͼG�޻���������������result�����У����򷵻�ʧ�ܡ�
bool TopoSort(Graph G)  
{
  int indegree[MAXVERNUM];   // ���ȫ���������ȡ�
  int result[MAXVERNUM];     // �����������Ľ����
  int count=0;               // �����򶥵�ļ�������

  // ��ͼG��ȫ���������ȣ�����������indegree�С�
  FindInDegree(G,indegree);  

  InitStack(S);     // ��ʼ��ջ�����ڱ������Ϊ0�Ķ��㡣

  for ( i=0; i<G.vexnum; i++ ) // ȫ�����Ϊ0�Ķ�����ջ��
    if (indegree[i]==0) Push(S,i);

  while (IsEmpty(S)==false) {  // ���ջ��Ϊ�ա�
    Pop(S,u);                  // ��ջһ��Ԫ�أ�������u�С�
    result[count++]=u;         // �������u��������count��1��
    // forѭ����ȡ����uȫ���ĳ��ߡ�
    for ( w=FirstAdjVex(G,u); w>=0; w=NextAdjVex(G,u,w) ) {
      indegree[w]--;   // ������ָ��Ķ������ȼ�1��
      if (indegree[w]==0) Push(S,w);  // ���Ϊ0�Ķ�����ջ��
    } 
  } 

  if (count<G.vexnum) return false; // ͼ���л�������ʧ�ܡ�
  else return true;                 // ����ɹ���
}

// ��������α���뿪ʼ��
//////////////////////////////////////////////////////////////////
