#include <stdio.h>
#include <stdlib.h>

typedef struct edge {
	int adjvex;
	struct edge *next;
} Edge;

typedef struct vertex {
	Edge *link;
} Ver;

Edge *insert(Edge *, int);
void travelDFS(Ver[], int);
void travelBFS(Ver[], int);
void DFS(Ver[], int);
void BFS(Ver[], int);

Ver	graph[105];	//无向图的顶点个数n大于等于3，小于等于100
int visited[105];
int nVer, nEdge;
int queue[105];
int front, rear;
int flag, del[105];

int main(void) {


	scanf("%d%d", &nVer, &nEdge);

	for (int i = 0; i < nEdge; i++) {
		int from, to;
		scanf("%d%d", &from, &to);
		graph[from].link = insert(graph[from].link, to);
		graph[to].link = insert(graph[to].link, from);
	}

	travelDFS(graph, nVer);
	printf("\n");
	travelBFS(graph, nVer);
	printf("\n");

	int i = 0;
	while (	scanf("%d", &del[i++]) != EOF);
	del[i - 1] = -1;
	flag = 1;

	travelDFS(graph, nVer);
	printf("\n");
	travelBFS(graph, nVer);
	printf("\n");

	return 0;
}

Edge *insert(Edge *head, int to) {
	Edge *r = malloc(sizeof(Edge));
	r->adjvex = to;
	r->next = 0;
	if (head == 0)
		return r;
	else {
		Edge *p, *q = 0;
		for (p = head; p != 0 && to > p->adjvex ; q = p, p = p->next);
		if (p == head) {
			r->next = head;
			return r;
		} else {
			q->next = r;
			r->next = p;
			return head;
		}
	}
}

void travelDFS(Ver g[], int n) {

	for (int i = 0; i < n; i++)
		visited[i] = 0;
	if (flag) {
		for (int i = 0; del[i] != -1; i++)
			visited[del[i]] = 1;
	}

	for (int i = 0; i < n; i++) {
		if (visited[i] == 0)
			DFS(g, i);
	}
}

void DFS(Ver g[], int v) {
	printf("%d ", v);
	visited[v] = 1;
	for (Edge *p = g[v].link; p != 0; p = p->next) {
		if (visited[p->adjvex] == 0)
			DFS(g, p->adjvex);
	}

}


void travelBFS(Ver g[], int n) {
	rear = -1, front = 0;

	for (int i = 0; i < n; i++)
		visited[i] = 0;

	if (flag) {
		for (int i = 0; del[i] != -1; i++)
			visited[del[i]] = 1;
	}

	for (int i = 0; i < n; i++) {
		if (visited[i] == 0)
			BFS(g, i);
	}
}

void BFS(Ver g[], int v) {
	printf("%d ", v);
	visited[v] = 1;
	queue[++rear] = v;
	while (rear - front >= 0) {
		v = queue[front++];
		for (Edge *p = g[v].link; p != 0; p = p->next) {
			if (visited[p->adjvex] == 0) {
				printf("%d ", p->adjvex);
				visited[p->adjvex] = 1;
				queue[++rear] = p->adjvex;
			}
		}
	}
}



