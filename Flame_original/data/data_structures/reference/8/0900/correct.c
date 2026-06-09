#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MaxV 256
typedef struct edge{
	int adjvex;
	int weight;
	struct edge *next;
} ELink;
typedef struct ver{
	int vertex;
	ELink *link;
} VLink;
VLink G[MaxV]; //邻接表

int a, b;

void createGraph(VLink graph[]);

void travelDFS(VLink G[], int n, int judge);
void travelBFS(VLink G[], int n, int judge);
int main()
{
	scanf("%d %d", &a, &b);//输入顶点和边的个数
	createGraph(G);
	travelDFS(G, a, -1);
	travelBFS(G, a, -1);
	int Del_Dot;
	scanf("%d", &Del_Dot);
	travelDFS(G, a, Del_Dot);
	travelBFS(G, a, Del_Dot);
	return 0;
	 
}
int Visited[MaxV] = {0};
ELink *insertEdge(ELink *head, int avex)
{	
//	printf("insertEdge ok\n");
	ELink *a1, *a2, *a3 = NULL;
	a1 = (ELink*)malloc(sizeof(ELink));
	a1->adjvex = avex; a1->weight = 1; a1->next = NULL;
	if(head == NULL)//空表
		return a1;
	for(a2 = head; a2 != NULL && avex > a2->adjvex; a3 = a2, a2 = a2->next)//找到插入的位置
		;
	if(a2 == head)//在头节点
	{
		a1->next = a2;
		return a1;
	 } else{
	 	a3->next = a1;
	 	a1->next = a2;
	 	return head;
	 }
}
void createGraph(VLink graph[])
{	
//	printf("createGraph ok\n");
	int i;
	for(i = 0; i < b; i++)
	{
		int v1, v2;
		scanf("%d %d", &v1, &v2);
		graph[v1].link = insertEdge(graph[v1].link, v2);
		graph[v2].link = insertEdge(graph[v2].link, v1);
	}
}
/*深度优点*/ 
void DFS(VLink G[], int v)
{	
	ELink *p;
	Visited[v] = 1;
	printf("%d ", v);
	for(p = G[v].link; p!=NULL; p = p->next)
		if(!Visited[p->adjvex])
			DFS(G, p->adjvex);
}
void travelDFS(VLink G[], int n, int judge)
{	
	int i;
	for(i = 0; i < n; i++)Visited[i] = 0;
	if(judge >= 0)
		Visited[judge] = 1;
	for(i = 0; i < n; i++)
		if(!Visited[i])DFS(G, i);
	printf("\n");
}
/*广度优先*/
#define MAXSIZE 1000
int Q[MAXSIZE];
int Front, Rear, Count;
void initQueue()
{
	Front = 0;
	Rear = MAXSIZE-1;
	Count = 0;
} 
int isEmpty()
{
	return Count == 0;
}
int isFull()
{
	return Count == MAXSIZE;
}
void enQueue(int queue[], int item)
{
	if(isFull())
		printf("Full queue!");
	else{
		Rear = (Rear+1) % MAXSIZE;
		queue[Rear] = item;
		Count++;
	}
}
int deQueue(int queue[])
{
	int e;
	if(isEmpty())
		printf("Empty queue!");
	else{
		e = queue[Front];
		Count--;
		Front = (Front+1) % MAXSIZE;
		return e;
	}
	return 0;
}
void BFS(VLink G[], int v)
{
	ELink *p;
	initQueue();
	Visited[v] = 1;
	enQueue(Q, v);
	while(!isEmpty(Q)){
		v = deQueue(Q);//去除队头元素
		printf("%d ", v);
		//获取该顶点第一个邻接顶点
		for(p = G[v].link; p!= NULL; p = p->next) 
		 if(!Visited[p->adjvex]){
		 	Visited[p->adjvex] = 1;
		 	enQueue(Q, p->adjvex);
		 	}
	}
}
void travelBFS(VLink G[], int n, int judge)
{
	int i;
	for(i = 0; i < n; i++)Visited[i] = 0;
	if(judge >= 0)
		Visited[judge] = 1;
	for(i = 0; i < n; i++)
		if(!Visited[i])BFS(G, i);
	printf("\n");
}

