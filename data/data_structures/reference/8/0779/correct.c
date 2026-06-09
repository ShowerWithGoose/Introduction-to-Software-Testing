#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Max 100

typedef struct edge {
	int  adjvex;
	struct edge* next;
}ELink;

typedef struct ver {
	ELink* link;
}VLink;

VLink Graph[Max];
int v_del;
int  Visited[Max] = { 0 };
int op = 0;

ELink* insertEdge(ELink* head, int avex)
{
	ELink* e, * p;
	e = (ELink*)malloc(sizeof(ELink));
	e->adjvex = avex;
	e->next = NULL;
	if (head == NULL) {
		head = e; 
		return head; 
	}
	if (head->adjvex > avex) {
		e->next = head;
		return e;
	}
	for (p = head; p->next != NULL; p = p->next) {
		if (p->next->adjvex > avex) {
			e->next = p->next;
			p->next = e;
			return head;
		}
	}
	p->next = e;
	return head;
}


void DFS(VLink  G[], int v)
{
	ELink* p;
	Visited[v] = 1;
	if (op==0||v != v_del)
		printf("%d ", v);
	for (p = G[v].link; p != NULL; p = p->next)
		if (!Visited[p->adjvex])
			DFS(G, p->adjvex);
}

void  travelDFS(VLink  G[], int n)
{
	int i;
	for (i = 0; i < n; i++) Visited[i] = 0;
	for (i = 0; i < n; i++)
		if (!Visited[i]) DFS(G, i);
}



void del_v(int v);
int num_v, num_e;

int Queue[10000], front = 0, rear = -1;
void enQueue(int Queue[], int v) {
	Queue[++rear] = v;
}

int deQueue(int Queue[]) {
	return Queue[front++];
}

int empty(int Queue[]) {
	if (rear < front)
		return 1;
	else
		return 0;
}

void BFS(VLink  G[], int v)
{
	ELink* p;
	Visited[v] = 1; //标识某顶点已入队
	enQueue(Queue, v);
	while (!empty(Queue)) {
		v = deQueue(Queue);  //取出队头元素
		if (op==0||v != v_del)
			printf("%d ", v); //访问当前顶点
		for (p = G[v].link; p != NULL; p = p->next) //访问该顶点的每个邻接顶点
			if (!Visited[p->adjvex]) {
				Visited[p->adjvex] = 1; //标识某顶点入队
				enQueue(Queue, p->adjvex);
			}
	}
}

void  travelBFS(VLink  G[], int n)
{
	int i;
	for (i = 0; i < n; i++) Visited[i] = 0;
	for (i = 0; i < n; i++)
		if (!Visited[i]) BFS(G, i);
}


int main() {
	int v1, v2;
	scanf("%d%d", &num_v, &num_e);
	for (int i = 0; i < num_e; i++) {
		scanf("%d %d", &v1, &v2);
		Graph[v1].link = insertEdge(Graph[v1].link, v2);
		Graph[v2].link = insertEdge(Graph[v2].link, v1);
	}
	scanf("%d", &v_del);
	travelDFS(Graph, num_v);
	puts("");
	memset(Visited, 0, sizeof(Visited));
	travelBFS(Graph, num_v);
	puts("");
	memset(Visited, 0, sizeof(Visited));
	del_v(v_del);
	op = 1;
	travelDFS(Graph, num_v);
	puts("");
	memset(Visited, 0, sizeof(Visited));
	travelBFS(Graph, num_v);
	puts("");
	return 0;
}

void del_v(int v) {
	for (int i = 0; i < num_v; i++) {
		if (Graph[i].link->adjvex == v) {
			ELink* p = Graph[i].link;
			Graph[i].link = p->next;
			free(p);
		}
		for (ELink* p = Graph[i].link; p != NULL && p->next != NULL; p = p->next) {
			if (p->next->adjvex == v) {
				ELink* q = p->next;
				p->next = p->next->next;
				free(q);
			}
		}
	}
}
