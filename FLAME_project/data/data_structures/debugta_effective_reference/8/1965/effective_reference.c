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

VLink G[Max];
int deleteVno;
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
	if (op==0||v != deleteVno)
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
int vno, eno;

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
		if (op==0||v != deleteVno)
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
	scanf("%d%d", &vno, &eno);
	for (int i = 0; i < eno; i++) {
		scanf("%d %d", &v1, &v2);
		G[v1].link = insertEdge(G[v1].link, v2);
		G[v2].link = insertEdge(G[v2].link, v1);
	}
	scanf("%d", &deleteVno);
	travelDFS(G, vno);
	puts("");
	memset(Visited, 0, sizeof(Visited));
	travelBFS(G, vno);
	puts("");
	memset(Visited, 0, sizeof(Visited));
	del_v(deleteVno);
	op = 1;
	travelDFS(G, vno);
	puts("");
	memset(Visited, 0, sizeof(Visited));
	travelBFS(G, vno);
	puts("");
	return 0;
}

void del_v(int v) {
	for (int i = 0; i < vno; i++) {
		if (G[i].link->adjvex == v) {
			ELink* p = G[i].link;
			G[i].link = p->next;
			free(p);
		}
		for (ELink* p = G[i].link; p != NULL && p->next != NULL; p = p->next) {
			if (p->next->adjvex == v) {
				ELink* q = p->next;
				p->next = p->next->next;
				free(q);
			}
		}
	}
}
