#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define MAX 100
typedef struct edge{
	int adjvex;		//该边的终止顶点位置 / 编号 
	//int weight;
	struct edge *next;	//指向下一个边结点 
}ELink;

typedef struct ver{
	int vertex;		//顶点编号 
	ELink *link;	//指向第一条边 
}VLink;

int visited[MAX];

ELink *insert_G(ELink *head, int v)
{
	ELink *p, *q = NULL, *r;
	r = (ELink*)malloc(sizeof(ELink));
	r->adjvex = v;
	r->next = NULL;
	if(head == NULL)
		return r;
	else
	{
		for(p = head; p && p->adjvex < v; q = p, p = p->next);	//最后在q,p之间插入 
		if(p == head)
		{
			r->next = p;
			return r;
		} 
		else
		{
			q->next = r;
			r->next = p;
			return head;
		}
	}
} 

void ADJLIST(VLink G[] , int n, int e)
{
	int k, vi, vj;
	for(k = 0; k < n; k++)	//初始化 ，建立n个顶点结点 
	{
		G[k].vertex = k;
		G[k].link = NULL;
	}
	for(k = 0; k < e; k++)
	{
		scanf("%d %d", &vi, &vj);	//输入顶点偶对（以及权值） 
		//无向图邻接表建立 + 排序 
		G[vi].link = insert_G(G[vi].link, vj);
		G[vj].link = insert_G(G[vj].link, vi);
	} 
}

void DFS(VLink G[], int v)	//删去（忽略）编号为del的顶点 
{
	ELink *p;
	visited[v] = 1;
	printf("%d ", v);
	//w = FIRSTADJ(G, v);
	for(p = G[v].link; p != NULL; p = p->next)
		if(!visited[p->adjvex])
			DFS(G, p->adjvex);
}

void TRAVEL_DFS(VLink G[], int n, int del)
{
	int i;
	for(i = 0; i < n; i++)
		visited[i] = 0;
	if(del >= 0)
		visited[del] = 1;
	for(i = 0; i < n; i++)
		if(visited[i] == 0)
			DFS(G, i);
	printf("\n");
}

int Q[MAX];
int front, rear, cnt;

void init_Q()
{
	front = 0;
	rear = MAX - 1;
	cnt = 0;
}

void enQueue(int queue[], int elem)
{
	if(cnt == MAX)
		printf("Queue is full.");
	else
	{
		rear = (rear + 1) % MAX;
		queue[rear] = elem;
		cnt++;
	}
}

int deQueue(int queue[])
{
	int elem;
	if(cnt == 0)
		printf("Queue is empty.");
	else
	{
		elem = queue[front];
		cnt--;
		front = (front + 1) % MAX;
		return elem;
	}
	return 0;
}

void BFS(VLink G[], int v)
{
	ELink *p;
	//printf("%d ", G[v].vertex);
	init_Q();
	visited[v] = 1;
	enQueue(Q, v);
	while(cnt != 0)
	{
		v = deQueue(Q);
		printf("%d ", v);
		for(p = G[v].link; p != NULL; p = p->next)
		{
			if(!visited[p->adjvex])
			{
				visited[p->adjvex] = 1;
				enQueue(Q, p->adjvex);
			}
		}
	}
}

void TRAVEL_BFS(VLink G[], int n, int del)
{
	int i;
	for(i = 0; i < n; i++)
		visited[i] = 0;
	visited[del] = 1;
	for(i = 0; i < n; i++)
		if(visited[i] == 0)
			BFS(G, i);
	printf("\n");
}

int main()
{
	int n, e, del;
	scanf("%d %d", &n, &e);
	VLink G[MAX];
	memset(G, 0, MAX*sizeof(VLink));
	ADJLIST(G, n, e);
	TRAVEL_DFS(G, n, -1);
	TRAVEL_BFS(G, n, -1);
	scanf("%d", &del);
	TRAVEL_DFS(G, n, del);
	TRAVEL_BFS(G, n, del);
	return 0;
}


