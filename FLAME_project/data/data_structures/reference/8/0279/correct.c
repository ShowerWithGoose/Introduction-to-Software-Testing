#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct _Graph {
	int num;
	struct _Graph *link;
} Graph, *pGraph;
Graph Vlink[100];
int visited[100] = {0};
int del;
void DFS(Graph Vlink[], int i) {
	visited[i] = 1;
	pGraph p;
	printf("%d ", i);
	for (p = Vlink[i].link; p != NULL; p = p->link ) {
		if (visited[p->num ] == 0) {
			DFS(Vlink, p->num);
		}
	}
}
void graphDFS(Graph Vlink[], int n) {
	int i;
	for (i = 0; i < n; i++) {
		visited[i] = 0;
	}
	for (i = 0; i < n; i++) {
		if (visited[i] == 0) {
			DFS(Vlink, i);
		}
	}
}
void graphDFSdel(Graph Vlink[], int n) {
	int i;
	for (i = 0; i < n; i++) {
		visited[i] = 0;
		visited[del] = 1;
	}
	for (i = 0; i < n; i++) {
		if (visited[i] == 0) {
			DFS(Vlink, i);
		}
	}
}

int Queue[100];
int front = 0, rear = -1, count = -1;
void BFS(Graph Vlink[], int i) {
	pGraph p;
	printf("%d ", i);
	visited[i] = 1;
	Queue[++rear] = i;
	count++;
	while (count >= 0) {
		i = Queue[front++];
		count--;
		p = Vlink[i].link;
		for (; p != NULL; p = p->link ) {
			if (visited[p->num] != 1) {
				printf("%d ", p->num );
				visited[p->num] = 1;
				Queue[++rear] = p->num;
				count++;
			}
		}
	}
}
void graphBFS(Graph Vlink[], int n) {
	int i;
	for (i = 0; i < n; i++) {
		visited[i] = 0;
	}
	for (i = 0; i < n; i++) {
		if (visited[i] == 0) {
			BFS(Vlink, i);
		}
	}
}
void graphBFSdel(Graph Vlink[], int n) {
	int i;
	for (i = 0; i < n; i++) {
		visited[i] = 0;
		visited[del] = 1;
	}
	front = 0;
	rear = -1;
	count = -1;
	for (i = 0; i < n; i++) {
		if (visited[i] == 0) {
			BFS(Vlink, i);
		}
	}
}
int main() {
	int a, b;
	int i, j, k;
	int d1, d2;
	pGraph p, q, r;
	scanf("%d%d", &a, &b);
	for (i = 0; i < b; i++) {
		scanf("%d%d", &d1, &d2);
		p = (pGraph)malloc(sizeof(Graph));
		p->num = d2;
		p->link = NULL;
		if (Vlink[d1].link == NULL) {
			Vlink[d1].link = p;
			Vlink[d1].num = d1;
		} else {
			for (q = Vlink[d1].link, r = q; q->link != NULL && q->num < p->num; r = q, q = q->link );
			if (q->link == NULL) {
				if (q->num < p->num ) {
					q->link = p;
				} else if (q->num > p->num && r != q) {
					p->link = q;
					r->link = p;
				} else if (q->num > p->num && r == q) {
					p->link = q;
					Vlink[d1].link = p;
				}
			} else {
				if (r != q) {
					p->link = q;
					r->link = p;
				} else {
					p->link = q;
					Vlink[d1].link = p;
				}

			}
		}
		p = (pGraph)malloc(sizeof(Graph));
		p->num = d1;
		p->link = NULL;
		if (Vlink[d2].link == NULL) {
			Vlink[d2].link = p;
			Vlink[d2].num = d1;
		} else {
			for (q = Vlink[d2].link, r = q; q->link != NULL && q->num < p->num; r = q, q = q->link );
			if (q->link == NULL) {
				if (q->num < p->num )
					q->link = p;
				else if (q->num > p->num && r != q) {
					p->link = q;
					r->link = p;
				} else if (q->num > p->num && r == q) {
					p->link = q;
					Vlink[d2].link = p;
				}
			} else {
				if (r != q) {
					p->link = q;
					r->link = p;
				} else {
					p->link = q;
					Vlink[d2].link = p;
				}
			}
		}
	}
	scanf("%d", &del);
	graphDFS(Vlink, a);
	printf("\n");
	graphBFS(Vlink, a);
	printf("\n");
	graphDFSdel(Vlink, a);
	printf("\n");
	graphBFSdel(Vlink, a);
	printf("\n");
	return 0;
}

