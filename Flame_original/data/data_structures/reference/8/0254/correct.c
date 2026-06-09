#include<stdio.h>  
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int A[100][100];//数组储存边关系 
typedef struct edge  
{
	int adjvex;
	struct edge *next;
}Elink,*PElink;//边结点类型
typedef struct ver 
 { 
	int vertex;
	Elink *link;
}Vlink,*PVlink; //顶点结点类型 
Vlink G[100],T[100];
int visited[100];//判断结点是否访问过 
int Q[100];
int del, jud=0;//del要删除结点，jud区分删除结点前后 
void travel_DFS(Vlink G[], int n);
void travel_BFS(Vlink G[], int n);
void DFS(Vlink G[], int v);
void BFS(Vlink G[], int v);
int num_edge,num_ver,i,j,k; 


int main()
{ 
scanf("%d %d",&num_ver,&num_edge);
for(i=0;i<num_ver;i++)
{
	G[i].vertex=T[i].vertex=i;
	G[i].link=T[i].link=NULL; 
}//初始化

 int a,b;
 for(i=0;i<num_edge;i++)
   {
 	scanf("%d %d",&a,&b);
	 A[a][b]=A[b][a]=1;//数组记录边关系  
	} 
	scanf("%d",&del);
	PElink p,q;
	for(i=0;i<num_ver;i++)//领接表T 
	{
		for(j=0;j<num_ver;j++)
		{
			if(A[i][j]==1)
			{
				p=(PElink)malloc(sizeof(Elink));
				p->adjvex = j;
				p->next = NULL;
				if(T[i].link==NULL)
				T[i].link=p;
				else 
				{
					for(q=T[i].link;q->next!=NULL;q=q->next);
					q->next=p;
				}
			}
		}
	}
	travel_DFS(T, num_ver);
	printf("\n");
	travel_BFS(T, num_ver);
	printf("\n");//输出删除前的遍历结果 
	for (i = 0; i < num_ver; i++)
	{
		if (A[del][i] == 1)
		A[del][i] = A[i][del] = 0;//删除该节点	
	}
	for(i=0;i<num_ver;i++)//删除结点后的领接表 G
	{
		for(j=0;j<num_ver;j++)
		{
			if(A[i][j]==1)
			{
				p=(PElink)malloc(sizeof(Elink));
				p->adjvex = j;
				p->next = NULL;
				if(G[i].link==NULL)
			    G[i].link=p;
				else 
				{
					for(q=G[i].link;q->next!=NULL;q=q->next);
					q->next=p;
				}
			}
		}
	}
    jud = 1;//标记 
	travel_DFS(G, num_ver);
	printf("\n");
	travel_BFS(G, num_ver);
	printf("\n");
	return 0;

  

return 0;
}
void travel_DFS(Vlink G[], int n) {
	int i;
	for (i = 0; i < n; i++)
		visited[i] = 0;
	if (jud)//jud为1则删除 
		visited[del] = 1;
	for (i = 0; i < n; i++)
		if (!visited[i])
			DFS(G, i);
}
void travel_BFS(Vlink G[], int n) {
	int i;
	for (i = 0; i < n; i++)
		visited[i] = 0;
	if (jud)
		visited[del] = 1;
	for (i = 0; i < n; i++)
		if (!visited[i])
			BFS(G, i);
}
void DFS(Vlink G[], int v) {
	Elink *p;
	printf("%d ", v);
	visited[v] = 1;
	for (p = G[v].link; p != NULL; p = p->next) {
		if (!visited[p->adjvex])
			DFS(G, p->adjvex);
	}
}
void BFS(Vlink G[], int v) {
	Elink *p;
	visited[v] = 1;
	int head = 0, tail = 0;
	Q[tail++] = v;//进队 
	
	while (head < tail) //队不为空时 
	{
		v = Q[head];//取出队首 
		printf("%d ", v);
		head++;
		p = G[v].link;//获取该结点第一个邻接结点 
		for( ;p!=NULL;p=p->next)
		{
			if(!visited[p->adjvex])
			{
				visited[p->adjvex] = 1;
				Q[tail++] = p->adjvex;//进队 
				
			}
		 } 
	}
}



