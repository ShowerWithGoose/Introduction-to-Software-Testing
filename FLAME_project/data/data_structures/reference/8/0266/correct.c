#include<stdio.h>
#include<stdlib.h>
#define MaxV 105
typedef struct edge{
	int adj,wei;
	struct edge *next;
}Elink;
typedef struct ver{
	Elink *link;
}Vlink;
Vlink G[MaxV];
int visited[MaxV],queue[MaxV],front=0,rear=0;
Elink* insertEdge(Elink *p1,int v)
{
	Elink *p2,*p;
	p = p1;
	if(p1==NULL)
	{
	    p1 = (Elink*)malloc(sizeof(Elink));
	    p1->next=NULL;
	    p1->adj=v;
	    return p1;
    }
	while(p->next!=NULL&&p->next->adj<v)
	p = p->next;
	p2 = (Elink*)malloc(sizeof(Elink));
	p2->next=p->next;
	p2->adj=v;
	p->next=p2;
	return p1;
}
void createGraph(Vlink g[],int verNum)
{
	int edgeNum,v1,v2,i;
	Elink *p2;
	scanf("%d",&edgeNum);
	for(i=0;i<edgeNum;i++)
	{
		scanf("%d%d",&v1,&v2);
		if(g[v1].link==NULL||g[v1].link->adj<v2)
		g[v1].link=insertEdge(g[v1].link,v2);
		else
		{
			p2 = (Elink*)malloc(sizeof(Elink));
			p2->adj=v2;
			p2->next=g[v1].link;
			g[v1].link=p2;
		}
		if(g[v2].link==NULL||g[v2].link->adj<v1)
		g[v2].link=insertEdge(g[v2].link,v1);
		else
		{
			p2 = (Elink*)malloc(sizeof(Elink));
			p2->adj=v1;
			p2->next=g[v2].link;
			g[v2].link=p2;
		}
	}
	return; 
} 
void DFS(Vlink G[],int v)
{
	Elink *p;
	visited[v]=1;
	printf("%d ",v);
	for(p=G[v].link;p!=NULL;p=p->next)
	if(!visited[p->adj])
	DFS(G,p->adj);
}
void travalDFS(Vlink G[],int n,int ex)
{
	int i;
	for(i=0;i<n;i++)
	visited[i]=0;
	visited[ex]=1;
	for(i=0;i<n;i++)
	if(!visited[i])
	DFS(G,i);
	printf("\n");
}
void BFS(Vlink G[],int v)
{
	Elink *p;
	printf("%d ",v);
	visited[v]=1;
	queue[rear++]=v;
	while(front!=rear)
	{
		v = queue[front++];
		p = G[v].link;
		for(;p!=NULL;p=p->next)
		{
			if(!visited[p->adj]){
			printf("%d ",p->adj);
			visited[p->adj]=1;
			queue[rear++]=p->adj;
		}
		}
	}
}
void travalBFS(Vlink G[],int n,int ex)
{
	int i;
	for(i=0;i<n;i++)
	visited[i]=0;
	visited[ex]=1;
	for(i=0;i<n;i++)
	if(!visited[i])
	BFS(G,i);
	printf("\n");
}
int main()
{
	int verNum,ex;
	scanf("%d",&verNum);
	createGraph(G,verNum);
	travalDFS(G,verNum,104);
	travalBFS(G,verNum,104);
	scanf("%d",&ex);
	Elink *p,*q;
	int i;
	G[ex].link=NULL;
	for(i=0;i<verNum;i++)
	{
		if(i==ex)
		continue;
		p = G[i].link;
		if(p->adj==ex)
		G[i].link=p->next;
		else
		{
			q = p;
			p = p->next;
			while(p!=NULL&&p->adj!=ex)
			{
				q = q->next;
				p = p->next;
			}
			if(p!=NULL)
			{
				q->next=p->next;
			}
		}
	}
	travalDFS(G,verNum,ex);
	travalBFS(G,verNum,ex);
	return 0;
}

