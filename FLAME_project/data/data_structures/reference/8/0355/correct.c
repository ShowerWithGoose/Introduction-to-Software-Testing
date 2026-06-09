#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
struct edge
{
	int adj;
	struct edge *elink;
};
struct ver
{
	int id;
	struct edge *link;
} graph[1000];
struct edge* insertedge(struct edge *head,int avex)
{
	struct edge *e,*p,*q=NULL;
	e=(struct edge *)malloc(sizeof(struct edge));
	e->adj=avex;
	e->elink=NULL;
	if(head==NULL)
	{
		head=e;
		return head;
	}
	for(p=head; p!=NULL&&graph[p->adj].id<=graph[e->adj].id; q=p,p=p->elink);
	if(p==head)
	{
		head=e;
		e->elink=p;
		return head;
	}
	q->elink=e;
	e->elink=p;
	return head;

}
int visit[1000],q[1000],rear=-1,front=0;
void DFS(int v,int id)
{
	struct edge *p;
	visit[v]=1;
	printf("%d ",id);
	for(p=graph[v].link; p!=NULL; p=p->elink)
		if(!visit[p->adj])
			DFS(p->adj,graph[p->adj].id);
}
void travelDFS(int n)
{
	int i;
	for(i=0; i<n; i++)
		visit[i]=0;
	for(i=0; i<n; i++)
		if(graph[i].link!=NULL)
			if(!visit[i])
				DFS(i,graph[i].id);
}
void BFS(int v)
{
	visit[v]=1;
	struct edge *p;
	q[++rear]=v;
	while(front<=rear)
	{
		v=q[front++];
		printf("%d ",graph[v].id);
		for(p=graph[v].link; p!=NULL; p=p->elink)
		{
			if(!visit[p->adj])
			{
				visit[p->adj]=1;
				q[++rear]=p->adj;
			}
		}

	}
}
void travelBFS(int n)
{
	int i;
	rear=-1;
	front=0;
	for(i=0; i<n; i++)
		visit[i]=0;
	for(i=0; i<n; i++)
		if(graph[i].link!=NULL)
			if(!visit[i])
				BFS(i);
}
void delgraphv(int v)
{
	struct edge *p;
	for(p=graph[v].link; p!=NULL; p=p->elink)
	{
		struct edge *q,*a=NULL;
		for(q=graph[p->adj].link; q!=NULL; a=q,q=q->elink)
		{
			if(q->adj==v)
			{
				if(q==graph[p->adj].link)
				{
					graph[p->adj].link=q->elink;
					free(q);
				}
				else
				{
					a->elink=q->elink;
					free(q);
				}
				break;
			}
		}
	}
	graph[v].link=NULL;
}
int main()
{
	int n,e,i;
	scanf("%d%d",&n,&e);
	for(i=0; i<e; i++)
	{
		int vi,vj;
		scanf("%d%d",&vi,&vj);
		graph[vi].id=vi;
		graph[vj].id=vj;
		graph[vi].link=insertedge(graph[vi].link,vj);
		graph[vj].link=insertedge(graph[vj].link,vi);
	}
	int vo;
	scanf("%d",&vo);
	travelDFS(n);
	printf("\n");
	travelBFS(n);
	printf("\n");
	delgraphv(vo);
//	for(i=0; i<n; i++)
//	{
//		struct edge *p;
//		printf("%d:",graph[i].id);
//		for(p=graph[i].link; p!=NULL; p=p->elink)
//			printf("%d ",graph[p->adj].id);
//		printf("\n");
//	}
	travelDFS(n);
	printf("\n");
	travelBFS(n);
	printf("\n");
	return 0;
}


