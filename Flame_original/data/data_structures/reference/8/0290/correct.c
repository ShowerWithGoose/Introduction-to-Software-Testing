#include<stdio.h>
#include<stdlib.h>
#define MaxV 105
struct edge
{
	int  adjvex;
	struct edge *next;
};
struct ver
{
	struct edge *link;
} graph[MaxV];
struct edge *insertEdge(struct edge *head, int avex)
{
	struct edge *e,*p,*q;
	e =(struct edge *)malloc(sizeof(struct edge));
	e->adjvex= avex;
	e->next = NULL;
	if(head == NULL)
	{
		head=e;
		return head;
	}
	for(p=head,q=NULL; p != NULL&&p->adjvex<avex; q=p,p=p->next);
	if(q!=NULL)
	{
		q->next=e;
		e->next=p;
	}
	else
	{
		head=e;
		e->next=p;
	}
	return head;
}
void createGraph(struct ver graph[])
{
	int v1,v2;
	scanf("%d %d",&v1,&v2);
	graph[v1].link=insertEdge(graph[v1].link, v2);
	graph[v2].link=insertEdge(graph[v2].link, v1);
}
int  Visited[MaxV]= {0};
void DFS(struct ver graph[], int v)
{
	struct edge *p;
	Visited[v] = 1;
	printf("%d ",v);
	for(p = graph[v].link; p!=NULL;  p=p->next)
	{
		if( !Visited[p->adjvex] )
			DFS(graph, p->adjvex);
		//else break;
	}
}
void travelDFS(struct ver graph[],int n)
{
	int i;
	for(i=0; i<n; i++) Visited[i] = 0 ;
	for(i=0; i<n; i++)
	{
		if( !Visited[i] )
			DFS(graph,i);
	}
}
void travelDFS2(struct ver graph[],int n,int m)
{
	int i;
	for(i=0; i<n; i++)
	{
		if(i==m)
			Visited[i]=1;
		else
			Visited[i] = 0 ;
	}
	for(i=0; i<n; i++)
	{
		if( !Visited[i] )
			DFS(graph,i);
	}
}
int Q[105],front=0,rear=-1;
void enQueue(int Q[],int v)
{
	Q[++rear]=v;
}
int deQueue(int Q[])
{
	return Q[front++];
}
int emptyQ(int Q[])
{
	if(front>rear)
		return 1;
	else
		return 0;
}
void BFS(struct ver G[], int v)
{
	struct edge *p;
	Visited[v] = 1; //标识某顶点已入队
	enQueue(Q, v);
	while( !emptyQ(Q))
	{
		v = deQueue(Q);  //取出队头元素
		printf("%d ",v); //访问当前顶点
		for(p=G[v].link; p!=NULL; p=p->next ) //访问该顶点的每个邻接顶点
			if( !Visited[p->adjvex] )
			{
				Visited[p->adjvex] = 1; //标识某顶点入队
				enQueue(Q, p->adjvex);
			}
	}
}
void  travelBFS(struct ver G[ ], int n)
{
	int i;
	for(i=0; i<n; i++) Visited[i] = 0 ;
	for(i=0; i<n; i++)
		if( !Visited[i] ) BFS(G, i);
}
void  travelBFS2(struct ver G[ ], int n,int m)
{
	int i;
	for(i=0; i<n; i++)
	{
		if(i==m)
			Visited[i]=1;
		else
			Visited[i] = 0 ;
	}
	for(i=0; i<n; i++)
		if( !Visited[i] ) BFS(G, i);
}
int main()
{
	int n,e,m;
	struct edge *p=NULL,*q=NULL;
	scanf("%d %d",&n,&e);
	for(int i=0; i<e; i++)
		createGraph(graph);
	travelDFS(graph,n);
	printf("\n");
	travelBFS(graph,n);
	printf("\n");
	scanf("%d",&m);
	travelDFS2(graph,n,m);
	printf("\n");
	travelBFS2(graph,n,m);
	printf("\n");
	return 0;
}

