#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct edge//边结点
{
	int adjvex;
	struct edge* next;
}ELink;
typedef struct ver//顶点结点
{
	int vertex;
	ELink* link;
}VLink;
VLink G[110];
int visited[110] = { 0 };
int count = 0;
int	Q[500] = { 0 };
int front = -1, rear = -1;
void ADDQ(int Q[], int* rear, int item)
{
	Q[++(*rear)] = item;
}
void ADJLIST(VLink G[], int n, int l)
{
	int k, a, b;
	ELink* p1=NULL, * p2=NULL, * q=NULL, * r=NULL;
	for (k = 0; k < n; k++) {
		G[k].vertex = k;
		G[k].link = NULL;
	}
	for (k = 0; k < l; k++) {
		scanf("%d %d", &a, &b);
		p1 = (ELink*)malloc(sizeof(ELink));
		p1->adjvex = b;
		p1->next = NULL;
		if (G[a].link == NULL)
			G[a].link = p1;
		else {
			q = G[a].link;
			r = &G[a];
			while (q != NULL && b >= q->adjvex) {
				r = q;
				q = q->next;
			}
			p1->next = q;
			r->next = p1;
		}
		p2 = (ELink*)malloc(sizeof(ELink));
		p2->adjvex = a;
		p2->next = NULL;
		if (G[b].link == NULL)
			G[b].link = p2;
		else {
			q = G[b].link;
			r = &G[b];
			while (q != NULL && a >= q->adjvex) {
				r = q;
				q = q->next;
			}
			p2->next = q;
			r->next = p2;
		}
	}
}
void DFS(VLink G[], int v,int n)
{
	int w;
	ELink* q;
	count++;
	(count == n) ? (printf("%d\n", G[v].vertex)) : (printf("%d ", G[v].vertex));
	visited[v] = 1;
	q = G[v].link;
	while (q != NULL) {
		w = q->adjvex;
		if (visited[w] == 0)
			DFS(G, w, n);
		q = q->next;
	}
}
void TRAVEL_DFS(VLink G[], int visited[], int n)
{
	int j;
	count = 0;
	for (j = 0; j < n; j++)
		visited[j] = 0;
	for (j = 0; j < n; j++)
		if (visited[j] == 0)
			DFS(G, j, n);
}
void BFS(VLink G[], int v,int n)
{
	int w;
	ELink* q;
	count++;
	(count == n) ? (printf("%d\n", G[v].vertex)) : (printf("%d ", G[v].vertex));
	visited[v] = 1;
	ADDQ(Q, &rear, v);
	while (front != rear) {
		v = Q[++front];
		q = G[v].link;
		while (q != NULL) {
			w = q->adjvex;
			if (visited[w] == 0) {
				count++;
				(count == n) ? (printf("%d\n", G[w].vertex)) : (printf("%d ", G[w].vertex));
				ADDQ(Q, &rear, w);
				visited[w] = 1;
			}
			q = q->next;
		}
	}
}
void TRAVEL_BFS(VLink G[], int visited[], int n)
{
	int j;
	count = 0;
	for (j = 0; j < n; j++)
		visited[j] = 0;
	for (j = 0; j < n; j++)
		if (visited[j] == 0)
			BFS(G, j, n);
}
void DELVER(VLink G[], int* n, int item)
{
	int j, k = -1;
	ELink* p = NULL, * q = NULL, * r = NULL;
	for (j = 0; j < *n; j++)
		if (G[j].vertex == item) {
			k = j;
			break;
		}
		if (k != -1) {
			p = G[k].link;
			for (j = k + 1; j < *n; j++) {
				G[j - 1].vertex = G[j].vertex;
				G[j - 1].link = G[j].link;
			}
			(*n)--;
			while (p != NULL) {
				r = p;
				p = p->next;
				free(r);
			}
			for (j = 0; j < *n; j++) {
				p = G[j].link;
				while (p != NULL)
					if (p->adjvex == k) {
						if (G[j].link == p)
							G[j].link = p->next;
						else
							q->next = p->next;
						r = p;
						p = p->next;
						free(r);
					}
					else {
						if (p->adjvex > k)
							p->adjvex--;
						q = p;
						p = p->next;
					}
			}
		}
}
int main()
{
	int n, l;//vn顶点个数,en边个数
	scanf("%d %d", &n, &l);
	ADJLIST(G, n, l);//此时已构建好链接表g[]
	int del;//要删除的结点
	scanf("%d", &del);
	TRAVEL_DFS(G, visited, n);
	TRAVEL_BFS(G, visited, n);
	DELVER(G, &n, del);
	TRAVEL_DFS(G, visited, n);
	TRAVEL_BFS(G, visited, n);
	return 0;
}


