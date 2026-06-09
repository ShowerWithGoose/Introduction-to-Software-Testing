#include <stdio.h>
#include <stdlib.h>
typedef struct edge
{
	int adj;
	int wei;
	struct edge *next;
}Elink;
typedef struct ver
{
	Elink *link;
}Vlink;
Vlink G[114];
Elink *insertedge(Elink *head,int avex)
{
	Elink *e,*p,*q=NULL;;
	e=(Elink *)malloc(sizeof(Elink));
	e->adj=avex; e->wei=1; e->next=NULL;
	if(head==NULL)
	{
		head=e;
		return head;
	}
	for(p=head;p!=NULL&&p->adj<avex;q=p,p=p->next);
	if(p==head)
	{
		e->next=p;
		return e;
	}
	else
	{
		q->next=e;
		e->next=p;
		return head;
	}
}
void creategraph(Vlink G[],int n)
{
	int i=0;
	int v1,v2;
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&v1,&v2);
		G[v1].link=insertedge(G[v1].link,v2);
		G[v2].link=insertedge(G[v2].link,v1);
	}
}
int visited[114]={0};
void DFS(Vlink G[],int v)
{
	Elink *p;
	visited[v]=1;
	printf("%d ",v);
	for(p=G[v].link;p!=NULL;p=p->next)
		if(!visited[p->adj])
			DFS(G,p->adj);
}
void travelDFS(Vlink G[],int n,int delv)
{
	int i;
	for(i=0;i<n;i++)
		visited[i]=0;
	if(delv>=0)
		visited[delv]=1;
	for(i=0;i<n;i++)
		if(!visited[i])
			DFS(G,i);
	printf("\n");
}
int Q[114]={0};
int front=0,cnt=0,rear=113;
int empty(int Q[])
{
	return cnt==0;
}
int isfull(int Q[])
{
	return cnt==114;
}
int deQueue(int Q[])
{
	int e;
	if(empty(Q))
		return 0;
	else
	{
		e=Q[front];
		cnt--;
		front=(front+1)%114;
		return e;
	}
}
void enQueue(int Q[],int num)
{
	if(isfull(Q))
		return;
	else
	{
		rear=(rear+1)%114;
		Q[rear]=num;
		cnt++;
	}
}
void BFS(Vlink G[],int v)
{
	Elink *p;
	visited[v]=1;
	enQueue(Q,v);
	while(!empty(Q))
	{
		v=deQueue(Q);
		printf("%d ",v);
		for(p=G[v].link;p!=NULL;p=p->next)
			if(!visited[p->adj])
			{
				visited[p->adj]=1;
				enQueue(Q,p->adj);
			}
	}
}
void travelBFS(Vlink G[],int n,int delv)
{
	int i;
	for(i=0;i<n;i++)
		visited[i]=0;
	if(delv>=0)
		visited[delv]=1;
	for(i=0;i<n;i++)
		if(!visited[i])
			BFS(G,i);
	printf("\n");
}
int delv;
int main()
{
	int ver,edge;
	scanf("%d%d",&ver,&edge);
	creategraph(G,edge);
	travelDFS(G,ver,-1);
	travelBFS(G,ver,-1);
	scanf("%d",&delv);
	travelDFS(G,ver,delv);
	travelBFS(G,ver,delv);
}

