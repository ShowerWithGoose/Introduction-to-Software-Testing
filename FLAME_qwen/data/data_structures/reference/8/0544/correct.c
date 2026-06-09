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
VLink g[110];
int visited[110] = { 0 };
int count = 0;
int	Q[500] = { 0 };
int front = -1, rear = -1;
void ADDQ(int Q[], int* rear, int item)
{
	Q[++(*rear)] = item;
}
void ADJLIST(VLink G[], int vn, int en)
{
	int k, vi, vj;
	ELink* p1=NULL, * p2=NULL, * q=NULL, * r=NULL;
	for (k = 0; k < vn; k++) {
		G[k].vertex = k;
		G[k].link = NULL;
	}
	for (k = 0; k < en; k++) {
		scanf("%d %d", &vi, &vj);
		p1 = (ELink*)malloc(sizeof(ELink));
		p1->adjvex = vj;
		p1->next = NULL;
		if (G[vi].link == NULL)
			G[vi].link = p1;
		else {
			q = G[vi].link;
			r = &G[vi];
			while (q != NULL && vj >= q->adjvex) {
				r = q;
				q = q->next;
			}
			p1->next = q;
			r->next = p1;
		}
		p2 = (ELink*)malloc(sizeof(ELink));
		p2->adjvex = vi;
		p2->next = NULL;
		if (G[vj].link == NULL)
			G[vj].link = p2;
		else {
			q = G[vj].link;
			r = &G[vj];
			while (q != NULL && vi >= q->adjvex) {
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
	int i;
	count = 0;
	for (i = 0; i < n; i++)
		visited[i] = 0;
	for (i = 0; i < n; i++)
		if (visited[i] == 0)
			DFS(G, i, n);
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
	int i;
	count = 0;
	for (i = 0; i < n; i++)
		visited[i] = 0;
	for (i = 0; i < n; i++)
		if (visited[i] == 0)
			BFS(G, i, n);
}
void DELVER(VLink G[], int* n, int item)
{
	int i, k = -1;
	ELink* p = NULL, * q = NULL, * r = NULL;
	for (i = 0; i < *n; i++)
		if (G[i].vertex == item) {
			k = i;
			break;
		}
		if (k != -1) {
			p = G[k].link;
			for (i = k + 1; i < *n; i++) {
				G[i - 1].vertex = G[i].vertex;
				G[i - 1].link = G[i].link;
			}
			(*n)--;
			while (p != NULL) {
				r = p;
				p = p->next;
				free(r);
			}
			for (i = 0; i < *n; i++) {
				p = G[i].link;
				while (p != NULL)
					if (p->adjvex == k) {
						if (G[i].link == p)
							G[i].link = p->next;
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
	int vn, en;//vn顶点个数,en边个数
	scanf("%d %d", &vn, &en);
	ADJLIST(g, vn, en);//此时已构建好链接表g[]
	int del;//要删除的结点
	scanf("%d", &del);
	TRAVEL_DFS(g, visited, vn);
	TRAVEL_BFS(g, visited, vn);
	DELVER(g, &vn, del);
	TRAVEL_DFS(g, visited, vn);
	TRAVEL_BFS(g, visited, vn);
	return 0;
}


