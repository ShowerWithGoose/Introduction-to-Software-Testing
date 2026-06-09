#include <stdio.h>
#include <stdlib.h>
#define MAX 500
int *visited, N;

struct node {
	struct edge *elist;
};

struct edge {
	int last;
	int next;
	struct edge *link;
};
void insertedge(struct node *, int, int);
void travelDFS(struct node *, int);
void travelBFS(struct node *, int);

int queue[MAX] = {};
int front = 0, rear = MAX - 1;
int count = 0;
int del = -1;

int main() {
	int edgenum, last, next;
	scanf("%d %d", &N, &edgenum);
	struct node graph[N];
	for (int k = 0; k < N; k++)
		graph[k].elist = NULL;
	for (int i = 0; i < edgenum; i++) {
		scanf("%d %d", &last, &next);
		insertedge(graph, last, next);
		insertedge(graph, next, last);
	}
	visited = (int *)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++)
		visited[i] = 0;
	travelDFS(graph, 0);
	printf("\n");
	for (int i = 0; i < N; i++)
		visited[i] = 0;
	travelBFS(graph, 0);
	printf("\n");
	scanf("%d", &del);
	visited = (int *)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++)
		visited[i] = 0;
	travelDFS(graph, 0);
	printf("\n");
	for (int i = 0; i < N; i++)
		visited[i] = 0;
	travelBFS(graph, 0);
	printf("\n");
	return 0;
}

void insertedge(struct node *graph, int a, int b) {
	struct edge *p = NULL;
	p = (struct edge *)malloc(sizeof(struct edge));
	p->last = a;
	p->next = b;
	p->link = NULL;
	if (graph[a].elist == NULL) {
		graph[a].elist = p;
	} else {
		struct edge *q = graph[a].elist, *m;
		m = q;
		for (; q != NULL; q = q->link) {
			if (b < q->next) {
				if (q != graph[a].elist) {
					p->link = q;
					m->link = p;
				} else {
					p->link = graph[a].elist;
					graph[a].elist = p;
				}
				break;
			}
			m = q;
		}
		if (q == NULL) {
			m->link = p;
		}
	}
}

void travelDFS(struct node *graph, int i) {
	if (visited[i] == 0)
		printf("%d ", i);
	visited[i] = 1;
	struct edge *p;
	if (graph[i].elist != NULL) {
		for (p = graph[i].elist; p != NULL; p = p->link) {
			if (p->next != del && visited[p->next] == 0)
				travelDFS(graph, p->next);
		}

	}
}

void travelBFS(struct node *graph, int i) {
	queue[0] = 0;
	rear = (rear + 1) % MAX;
	count++;
	while (count > 0) {
		if (visited[queue[front]] == 0) {
			printf("%d ", queue[front]);
			visited[queue[front]] = 1;
			struct edge *p = graph[queue[front]].elist;
			for (; p != NULL; p = p->link) {
				if (p->next == del)
					continue;
				rear = (rear + 1) % MAX;
				count++;
				queue[rear] = p->next;
			}
			count--;
			front = (front + 1) % MAX;
		} else {
			count--;
			front = (front + 1) % MAX;
		}
	}
}
