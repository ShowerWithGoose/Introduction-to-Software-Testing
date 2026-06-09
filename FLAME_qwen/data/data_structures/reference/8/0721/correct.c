#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MaxV 100
#define MAXSIZE 1000
typedef struct edge{
	int adj;
	int wei;
	struct edge *next;
}Elink;
typedef struct ver{
	Elink *link;
}Vlink;
Vlink G[MaxV];

void createGraph(Vlink graph[]);
void DFS(Vlink G[], int n, int delV);
void BFS(Vlink G[], int n, int delV);

int V, E;

int main()
{
	scanf("%d %d", &V, &E);
	createGraph(G);
	DFS(G, V, -1);
	BFS(G, V, -1);
	int k;
	scanf("%d", &k);
	DFS(G, V, k);
	BFS(G, V, k);
	return 0;
}

Elink *insertEdge(Elink *head, int avex)
{
	Elink *e, *p, *q = NULL;
	e = (Elink *)malloc(sizeof(Elink));
	e->adj = avex;
	e->next = NULL;
	e->wei = 1;
	if(head == NULL)return e;
	for(p = head; p != NULL && avex > p->adj; q = p, p = p->next);
	if(p == head)
	{
		e->next = p;
		return e;
	}
	else 
	{
		q->next = e;
		e->next = p;
		return head;
	}
}

void createGraph(Vlink graph[])
{
	int i;
	for(i = 0; i < E; i++)
	{
		int v1, v2;
		scanf("%d %d", &v1, &v2);
		graph[v1].link = insertEdge(graph[v1].link, v2);
		graph[v2].link = insertEdge(graph[v2].link, v1);
	}
}

int Visited[MaxV] = {0};

void tDFS(Vlink G[], int v)
{
	Elink *p;
	Visited[v] = 1;
	printf("%d ", v);
	for(p = G[v].link; p != NULL; p = p->next)
	{
		if(!Visited[p->adj])tDFS(G, p->adj);
	}
}

void DFS(Vlink G[], int n, int delV)
{
	int i;
	for(i = 0; i < n; i++) Visited[i] = 0;
	if(delV >= 0)Visited[delV] = 1;
	for(i = 0; i < n; i++)
	{
		if(!Visited[i])tDFS(G, i);
	}
	printf("\n");
}

int Q[MAXSIZE];
int Front, Rear, Count;
void initQueue()
{
	Front = 0;
	Rear = MAXSIZE - 1;
	Count = 0;
}
int isFull()
{
	return Count == MAXSIZE;
}
int isEmpty()
{
	return Count == 0;
}
void enQueue(int queue[], int item)
{
	if(isFull())printf("Full queue!");
	else 
	{
		Rear = (Rear + 1) % MAXSIZE;
		queue[Rear] = item;
		Count++;
	}
}
int deQueue(int queue[])
{
	int e;
	if(isEmpty())printf("empty queue!");
	else
	{
		e = queue[Front];
		Count--;
		Front = (Front + 1) % MAXSIZE;
		return e;
	}
	return 0;
}

void tBFS(Vlink G[], int v)
{
	Elink *p;
	initQueue();
	Visited[v] = 1;
	enQueue(Q, v);
	while(!isEmpty())
	{
		v = deQueue(Q);
		printf("%d ", v);
		for(p = G[v].link; p != NULL; p = p->next)
			if(!Visited[p->adj])
			{
				Visited[p->adj] = 1;
				enQueue(Q, p->adj);
			}
	 } 
}

void BFS(Vlink G[], int n, int delV)
{
	int i;
	for(i = 0; i < n; i++)Visited[i] = 0;
	if(delV >= 0)Visited[delV] = 1;
	for(i = 0; i < n; i++)
	{
		if(!Visited[i])tBFS(G, i);
	}
	printf("\n");
}

