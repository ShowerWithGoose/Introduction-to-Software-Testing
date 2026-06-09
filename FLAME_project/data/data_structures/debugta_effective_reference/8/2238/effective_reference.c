#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#define maxv 200

typedef struct edge{
	int adjvex;
	struct edge *next;
}Elink;

typedef struct ver{
	int vertex;
	Elink *link;
}Vlink;

Vlink g[maxv];

Elink *insertEdge(Elink *head,int item)
{
	Elink *p,*q;
	p=(Elink *)malloc(sizeof(Elink));
	p->adjvex=item;
	p->next=NULL;
	if(head==NULL)
	{
		head=p;
		return head;
	}
	for(q=head;q->next!=NULL&&q->next->adjvex<item;q=q->next){}
	if(q==head&&q->adjvex>item)
	{
		p->next=head;
		head=p;
	}
	else
	{
		if(q->next!=NULL)
		p->next=q->next;
	    q->next=p;
	}
	return head;
}

int visited[maxv]={0};

void visit(Vlink g[],int v)
{
	if(g[v].vertex>=0)
	printf("%d ",g[v].vertex);
}

void DFS(Vlink g[],int v)
{
	Elink *p;
	visited[v]=1;
	visit(g,v);
	for(p=g[v].link;p!=NULL;p=p->next)
	{
		if(!visited[p->adjvex])
		DFS(g,p->adjvex);
	}
}

int queue[maxv];
int front=0,rear=-1;

void enQueue(int v)
{
	queue[++rear]=v;
}

int deQueue()
{
	return queue[front++];
}

int emptyQ()
{
	if(front>rear)
	return 1;
	return 0;
}

void BFS(Vlink g[],int v)
{
	Elink *p;
	visited[v]=1;
	visit(g,v);
	enQueue(v);
	while(!emptyQ())
	{
		v=deQueue();
		for(p=g[v].link;p!=NULL;p=p->next)
		{
			if(!visited[p->adjvex])
			{
				visit(g,p->adjvex);
				visited[p->adjvex]=1;
				enQueue(p->adjvex);
			}
		}
	}
}

void travelDFS(Vlink g[],int n)
{
	int i;
	for(i=0;i<n;i++)
	visited[i]=0;
	for(i=0;i<n;i++)
	{
		if(!visited[i])
		DFS(g,i);
	}
	printf("\n");
}

void travelBFS(Vlink g[],int n)
{
	front=0,rear=-1;
	int i;
	for(i=0;i<n;i++)
	visited[i]=0;
	for(i=0;i<n;i++)
	{
		if(!visited[i])
		BFS(g,i);
	}
	printf("\n");
}

void deleteG(int v,int n)
{
	int i;
	Elink *p,*q;
	g[v].link=NULL;
	g[v].vertex=-1;
	for(i=0;i<n;i++)
	{
		if(i==v)
		continue;
		q=g[i].link;
		for(p=g[i].link;p!=NULL;q=p,p=p->next)
		{
			if(p->adjvex==v)
			{
				if(p==g[i].link)
				{
					g[i].link=p->next;
				}
				else
				{
					q->next=p->next;
				}
			}
			break;
		}
	}
}

int main()
{
	int n,m,i,a,b;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
	{
		g[i].vertex=i;
	}
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&a,&b);
		g[a].link=insertEdge(g[a].link,b);
		g[b].link=insertEdge(g[b].link,a);
	}
	
	travelDFS(g,n);
	travelBFS(g,n);
	
	scanf("%d",&a);
	deleteG(a,n);
	
	travelDFS(g,n);
	travelBFS(g,n);
	/*for(i=0;i<n;i++)
	{
		printf("%d ",i);
		Elink *p;
		for(p=g[i].link;p!=NULL;p=p->next)
		printf("%d ",p->adjvex);
		printf("\n");
	}*/
	
	return 0;
}

