#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MaxV 100
typedef struct ver{
	int vertex;
	struct ver *next;
}Vlink;
Vlink *G[MaxV];
int visited[MaxV];
Vlink *insert(int v1,int v2);
int main()
{
	int i,b,n,v1,v2,v;
	scanf("%d %d",&n,&b);
	for(i=0;i<b;i++)
	{
		scanf("%d %d",&v1,&v2);
		G[v1]=insert(v1,v2);
		G[v2]=insert(v2,v1);
	}
	scanf("%d",&v);
	travelDFS(0);
	printf("\n");
	travelBFS(0);
	printf("\n");
	delet(v);
	n--;
	travelDFS(0);
	printf("\n");
	travelBFS(0);
	printf("\n");
	return 0;
} 
Vlink *insert(int v1,int v2)
{
	Vlink *e,*p,*q;
	if(G[v1]==NULL)
	{
		G[v1]=(Vlink *)malloc(sizeof(Vlink));
		G[v1]->vertex=v1;
		G[v1]->next=NULL;
	}
	e=(Vlink *)malloc(sizeof(Vlink));
	e->vertex=v2;
	e->next=NULL;
	q=G[v1];
	for(p=G[v1]->next;p!=NULL&&p->vertex<v2;q=p,p=p->next)
	 ;
	e->next=p;
	q->next=e;
	return G[v1];
}
void setzero()
{
	int i;
	for(i=0;i<MaxV;i++)
	{
		visited[i]=0;
	}
}
void travelBFS(int v)
{
	int i;
	setzero();
	BFS(v);
}
void BFS(int v)
{
	Vlink *p,*q;
	Vlink *queue[MaxV];
	int front=0,rear=MaxV-1,count=0;
	visited[v]=1;
	rear=(rear+1)%MaxV;	
	queue[rear]=G[v];
	count++;
	while(count!=0)
	{
		p=queue[front];
		front=(front+1)%MaxV;
		count--;
		printf("%d ",p->vertex);
		for(q=G[p->vertex]->next;q!=NULL;q=q->next)
		{
			if(visited[q->vertex]==0)
			{
				visited[q->vertex]=1;
				rear=(rear+1)%MaxV;
				queue[rear]=q;
				count++;
			}
		}
	}
} 
void DFS(int v)
{
	Vlink *p;
	for(p=G[v];p!=NULL;p=p->next)
	{
		if(visited[p->vertex]==0)
		{
			visited[p->vertex]=1;
			printf("%d ",p->vertex);
			DFS(p->vertex);
		}
	}
}
void travelDFS(int v)
{
	setzero();
	DFS(v);
	return ;
}
void delet(int v)
{
	Vlink *p,*q,*r;
	for(p=G[v]->next;p!=NULL;p=p->next)
	{
		for(r=q=G[p->vertex];q!=NULL&&q->vertex!=v;r=q,q=q->next)
		;
		r->next=q->next;
		free(q);
	}
	for(p=G[v];p!=NULL;)
	{
		r=p->next;
		free(p);
		p=r;
	}
	return ;
}

