#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define NHASH  3001
#define MULT  37
typedef struct edge{ 
	int adjvex; //所指顶点下标 
	int weight; //权值  
	struct edge *next; 
}ELink;//定义边结点类型 
typedef struct ver{ 
	int vertex; //存储的信息 
	ELink *link; 
}VLink;//定义顶点结点类型 
VLink G[120];//顶点数组 
void insert(int a,int b)
{
	ELink *p,*q;
	p=(ELink *)malloc(sizeof(ELink));
	p->adjvex=b,p->next=NULL,p->weight=1;
	if(G[a].link==NULL)
	{
		G[a].link=p;
	}
	else
	{
		if(G[a].link->adjvex>b)
		{
			p->next=G[a].link;
			G[a].link=p;
			return;
		}
		for(q=G[a].link;;q=q->next)
		{
			if(q->next==NULL)
			{
				q->next=p;
				break;
			}
			else if(q->next->adjvex>p->adjvex)
			{
				p->next=q->next;
				q->next=p;
				break;
			}
		}
	}
}
int visited[120]={0};//顶点是否被访问过，N为顶点数 
void DFS(VLink G[],int v)
{
	ELink *p;
	visited[v]=1;
	printf("%d ",G[v].vertex);
	for(p=G[v].link;p!=NULL;p=p->next)
	{
		if(visited[p->adjvex]==0)//若p所指结点未访问 
			DFS(G,p->adjvex);//则递归 
	}
}
int Q[120],head=0,tail=-1;
void BFS(VLink G[],int v)
{
	ELink *p;
	visited[v]=1;//标志顶点已进队 
	Q[++tail]=v;
	while(head<=tail)
	{
		v=Q[head++];
		printf("%d ",G[v].vertex);
		for(p=G[v].link;p!=NULL;p=p->next)
		{
			if(!visited[p->adjvex])
			{
				visited[p->adjvex]=1;
				Q[++tail]=p->adjvex;
			}
		}
	}
}
int main()
{
	int n,e,i,a,b;
	scanf("%d%d",&n,&e);
	for(i=0;i<n;i++)
	{
		G[i].link=NULL;
		G[i].vertex=i;
	}
	for(i=0;i<e;i++)
	{
		scanf("%d%d",&a,&b);
		insert(a,b);
		insert(b,a);
	}
	for(i=0;i<n;i++)visited[i]=0;
	for(i=0;i<n;i++)if(!visited[i])DFS(G,i);
	printf("\n");
	for(i=0;i<n;i++)visited[i]=0;
	for(i=0;i<n;i++)if(!visited[i])BFS(G,i);
	printf("\n");
	int del;
	scanf("%d",&del);
	for(i=0;i<n;i++)visited[i]=0;
	visited[del]=1;
	for(i=0;i<n;i++)if(!visited[i])DFS(G,i);
	printf("\n");
	for(i=0;i<n;i++)visited[i]=0;
	visited[del]=1;
	for(i=0;i<n;i++)if(!visited[i])BFS(G,i);
	printf("\n");
    return 0;
}


