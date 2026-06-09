#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct edge
{
	int adjvex;//边的端点信息
	struct edge *next;
} ELink;
typedef struct ver
{
	ELink *link;
} VLink;
VLink G[105];

int n,e,ext;
int count=0,front=0,rear=1004;
int visited[105];
int Q[1005];

ELink *insertEdge(ELink *head,int x)//插入到有序链表
{
	ELink *e,*p,*q;
	e=(ELink*)malloc(sizeof(ELink));
	e->adjvex=x;
	e->next=NULL;
	if(head==NULL)
	{
		head=e;
		return head;
	}
	for(p=head; p!=NULL&&x>p->adjvex; q=p,p=p->next);

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
void createGraph(VLink graph[])
{
	int i,v1,v2;
	for(i=0; i<e; i++)
	{
		scanf("%d %d",&v1,&v2);
		graph[v1].link=insertEdge(graph[v1].link,v2);
		graph[v2].link=insertEdge(graph[v2].link,v1);
	}
}

void DFS(VLink graph[],int v)
{
	ELink *p;
	printf("%d ",v);
	visited[v]=1;
	for(p=graph[v].link; p!=NULL; p=p->next)
	{
		if(visited[p->adjvex]==0)
			DFS(graph,p->adjvex);
	}
}
void travelDFS(VLink graph[])
{
	int i;
	memset(visited,0,sizeof(visited));
	if(ext>=0)
		visited[ext]=1;
	for(i=0; i<n; i++)
	{
		if(visited[i]==0)
			DFS(graph,i);
	}
}

void enQueue(int queue[ ], int item)
{
	rear=(rear+1)%1005;
	queue[rear]=item;
	count++;
}
int deQueue(int queue[ ])
{
	int e;
	e=queue[front];
	count--;
	front=(front+1)%1005;
	return e;
}

void BFS(VLink graph[],int v)
{
	ELink *p;
	visited[v]=1;
	enQueue(Q,v);
	while(count>0)
	{
		v=deQueue(Q);
		printf("%d ",v);
		for(p=graph[v].link; p!=NULL; p=p->next)
		{
			if(visited[p->adjvex]==0)
			{
				visited[p->adjvex]=1;
				enQueue(Q,p->adjvex);
			}
		}
	}
}
void travelBFS(VLink graph[])
{
	int i;
	memset(visited,0,sizeof(visited));
	if(ext>=0)
		visited[ext]=1;
	for(i=0; i<n; i++)
	{
		if(visited[i]==0)
			BFS(graph,i);
	}
}
int main()
{
	int x;
	scanf("%d %d",&n,&e);
	createGraph(G);
	scanf("%d",&x);
	
	ext=-1;
	travelDFS(G);
	printf("\n");
	travelBFS(G);
	printf("\n");
	
	ext=x;	
	travelDFS(G);
	printf("\n");
	travelBFS(G);

	return 0;
}

