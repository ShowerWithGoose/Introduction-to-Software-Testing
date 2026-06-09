#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <math.h>
#define  PR printf
#define MAX 512
typedef long long LL;



//typedef struct _Edge{
//	int vertex;
//	struct _Edge *next;
//}Edge; 
//
//typedef struct _Ver{
//	Edge *link;
//}Ver;
typedef struct _Edge{    		//定义边类型 
	int adjvex;
	int wei;
	struct _Edge *next;
}Edge;

typedef struct _ver{			//定义顶点类型 
	Edge *link;
}Ver;


Ver G[MAX];
int Nov, Noe, dln;
int visited[MAX];
int Q[MAX];					//BFS用顶点队列
int front=0,real=MAX-1,count = 0; 
void creategraph(Ver g[]);
Edge *insertEdge(Edge *head,int ave);
void travelDFS(Ver g[],int N,int op);
void DFS(Ver g[], int v);
void travelBFS(Ver g[],int N,int op);
void BFS(Ver g[],int v);
void Visit(Ver g[],int i);
int emptyQ(int Q[]);
void enQueue(int Q[],int t);
int deQueue(int Q[]);
int isfull(int Q[]);


int main()
{
	scanf("%d%d", &Nov, &Noe);
	
	creategraph(G);
	scanf("%d",&dln);
	
	travelDFS(G,Nov,0);
	printf("\n"); 
	travelBFS(G,Nov,0);
	printf("\n");
	travelDFS(G,Nov,1);
	printf("\n");
	travelBFS(G,Nov,1);
	return 0;

}

void creategraph(Ver g[])
{
	int i, v1,v2;
	for(i=0;i<Noe;i++)
	{
		scanf("%d%d", &v1, &v2); 
		//printf("%d %d\n",v1,v2);
		g[v1].link = insertEdge(g[v1].link,v2);
		g[v2].link = insertEdge(g[v2].link,v1);
	}
}

Edge *insertEdge(Edge *head,int ave)
{
	Edge *r,*p;
	r = (Edge *)malloc(sizeof(Edge));
	r->adjvex = ave;
	r->wei = 1;
	r->next = NULL;
	if(head == NULL)
	{
		head = r;
		return head;
	}
	else{
		if(head->adjvex>ave)
		{
			r->next = head;
			head = r;
		}
		else{
			for(p=head;p->next != NULL&&p->next->adjvex < ave; p = p->next)
			{
				;
			}
			if(p->next ==NULL)
			{
				p->next = r;
			}
			else{												//按从小到大插入边结点 
				r->next = p->next;
				p->next = r;
			}
				}
				return head;
		}
	return head;
}


void travelDFS(Ver g[],int N,int op)
{
	int i;
	for(i=0;i<N;i++)
	{
		visited[i] = 0;
	}
	if(op==1)
	{
		visited[dln]=1;
	}
	for(i=0;i<N;i++)
	{
		if(!visited[i])
		{
			DFS(g,i);
		}
	}
}
void DFS(Ver g[], int v)
{
	Edge *p;
	visited[v] = 1;
	Visit(g,v);
	for(p = g[v].link;p!=NULL;p=p->next)
	{
		
		if(!visited[p->adjvex])
		{
			DFS(g,p->adjvex);
		}
	}
}

void travelBFS(Ver g[],int N,int op)
{
	int i;
	for(i=0;i<N;i++)
	{
		visited[i] = 0;	
	}
	if(op ==1)
	{
		visited[dln]=1;
	}
	for(i=0;i<N;i++)
	{
		if(!visited[i])
		{
			BFS(g,i);
		}
	}
}

void BFS(Ver g[],int v)
{
	Edge *p;
	enQueue(Q,v);
	visited[v] = 1;
	while(!emptyQ(Q))
	{
		v = deQueue(Q);
		Visit(g,v);
		for(p = g[v].link; p!=NULL;p=p->next)
		{
			if(!visited[p->adjvex])
			{
				enQueue(Q,p->adjvex);
				visited[p->adjvex]=1;
			}
		}
	}
}

void Visit(Ver g[],int i)
{
	printf("%d ",i);
 } 

int emptyQ(int Q[])
{
	return count == 0;
}

int isfull(int Q[])
{
	return count == MAX;
}
void enQueue(int Q[],int t)
{
	if(isfull(Q))
	{
		printf("Q is full!\n");
		return;
	}
	else{
		real =( real+1)%MAX;
		Q[real]= t;
		count++;
	}
}
int deQueue(int Q[])
{
	int e;
	if(emptyQ(Q))
	{
		printf("Q is empty!\n");
	}
	else{
		e = Q[front];
		count--;
		front = (front+1)%MAX;
		return e;
		
	}
}

