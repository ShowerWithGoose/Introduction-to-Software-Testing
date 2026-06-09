#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#define llo long long
#define max(A,B) A>B?A:B
#define maxV 200
#define maxE 20000
#define vertype int   
#define testdata1 8 
#define testdata2 16
#define testdata 22
int n,m;
typedef struct edge{
	int adjvex;
	int weight;
	struct edge *next;
}Elink;
typedef struct ver{
	vertype vertex;
	int valid;
	Elink *link;
}Vlink;
Vlink G[maxV];
typedef struct EDGE{
	int weight;
	vertype v1,v2;
}Edge;
int Visited[maxV];
vertype Vertex[maxV];
Edge GV[maxV][maxV];
Edge GE[maxE];
Elink *insertEdge(Elink *head,int avex)
{
	Elink *e,*p;
	e=(Elink *)malloc(sizeof(Elink*));
	e->adjvex =avex;
	e->weight=1;
	e->next =NULL;
	if(head==NULL)
	{
		head=e;
		return head;
	}
	for(p=head;p->next!=NULL;p=p->next);
	
		p->next=e;
	
	return head;
}
void creategraph(Vlink graph[])
{
	int i,v1,v2;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&v1,&v2);
		graph[v1].link=insertEdge(graph[v1].link,v2);
		graph[v2].link=insertEdge(graph[v2].link,v1);
		
	}
}
int cmp(const void *p,const void *q)
{
	Edge *a=(Edge*)p;
	Edge *b=(Edge*)q;
	return a->v1!=b->v1?a->v1-b->v1:a->v2-b->v2;
}
void createfromlessgraph(Vlink graph[])
{
	int i;
	Edge minedge[maxE];
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&minedge[i].v1,&minedge[i].v2);
		if(minedge[i].v1>minedge[i].v2)
		{
			vertype tmp=minedge[i].v2;
			minedge[i].v2=minedge[i].v1;
			minedge[i].v1=tmp;
		}
		
		
	}
	qsort(minedge,m,sizeof(Edge),cmp);
	for(i=0;i<m;i++)
	{
		graph[minedge[i].v1].valid=1;
		graph[minedge[i].v2].valid=1;
		graph[minedge[i].v1].link=insertEdge(graph[minedge[i].v1].link,minedge[i].v2);
		graph[minedge[i].v2].link=insertEdge(graph[minedge[i].v2].link,minedge[i].v1);
	}
}
void VISIT(Vlink G[],int v)
{
	
	 if(G[v].valid==1)
	printf("%d ",G[v].vertex);
	
	
}
void DFS(Vlink G[],int v)
{
	Elink *p;
	Visited[v]=1;
	VISIT(G,v);
	for(p=G[v].link;p!=NULL;p=p->next)
	if(!Visited[p->adjvex]&&G[p->adjvex].valid==1)
	DFS(G,p->adjvex);
}
void travelDFS(Vlink G[])
{
	int i;
	for(i=0;i<n;i++)
	{
		Visited[i]=0;
	}
	for(i=0;i<n;i++)
	{
		if(!Visited[i])
		DFS(G,i);
	}
}
void initgraph(Vlink graph[])
{
	int i;
	for(i=0;i<maxV;i++)
	{
		graph[i].link=NULL;
		graph[i].vertex=i;
	}
}
int Vrear=-1;
int Vhead=0;
int isempty()
{
	return Vrear==Vhead-1;
}
void enquene(vertype Vquene[],vertype v)
{
	Vquene[++Vrear]=v;
}
vertype dequene(vertype Vquene[])
{
	
	return Vquene[Vhead++];
}
void BFS(Vlink G[],int v)
{
	Elink *p;
	vertype Vquene[maxV];
	VISIT(G,v);
	Visited[v]=1;
	enquene(Vquene,v);
	while(!isempty())
	{
		v=dequene(Vquene);
		p=G[v].link;
		for(;p!=NULL;p=p->next)
		if(!Visited[p->adjvex])
		{
			VISIT(G,p->adjvex);
			Visited[p->adjvex]=1;
			enquene(Vquene,p->adjvex);
		}
		
	}
}
void travelBFS(Vlink G[])
{
	int i;
	for(i=0;i<n;i++)
	{
		Visited[i]=0;
	}
	for(i=0;i<n;i++)
	{
		if(!Visited[i])
		BFS(G,i);
	}
}
void deleteDFS(Vlink G[],int v,int delv)
{
	Elink *p,*q,*r;
	if(G[v].link->adjvex==delv)
	{
		
		q=G[v].link;
		G[v].link=q->next;
		
		return;
	}
	else
	{
		for(p=G[v].link;p!=NULL;p=p->next)
		{
			
			if(p->adjvex==delv)
			{
				
				r=p;
				q->next=p->next;
				free(r);
				return;
			}
			q=p;
		
		}
		
	}
	
	
}

void traveldeleteDFS(Vlink G[],vertype delv)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(i!=delv)
		deleteDFS(G,i,delv);
	}
}
void deletegraph(Vlink G[],vertype delv)
{
	G[delv].link=NULL;
	G[delv].valid=0;
	traveldeleteDFS(G,delv);
}
int main()
{

	Vlink graph[maxV];
	initgraph(graph);
	createfromlessgraph(graph);
	travelDFS(graph);
	putchar(10);
	travelBFS(graph);
	putchar(10);
	int delv;
	scanf("%d",&delv);
	deletegraph(graph,delv);
	travelDFS(graph);
	putchar(10);
	travelBFS(graph);
	putchar(10);
	return 0;
	
}


