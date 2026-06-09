#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define pf printf
#define sf scanf
#define ll long long
#define ull unsigned long long
#define eps 1e-10
#define MAX(a,b) ((a)>(b)?(a) : (b))
#define MIN(a,b) ((a)<(b)?(a) : (b))
typedef struct edge {
	int data;
	struct edge *next;
} Elink;
typedef struct ver {
	Elink *link;
} Vlink;
Vlink V[105];
int n, m;
Elink* insertGraph(Elink *head, int ver) {
	Elink *e, *p;
	e = (Elink*)malloc(sizeof(Elink));
	e->data = ver;
	e->next = NULL;
	if (head == NULL)
		head = e;
	else {
		for (p = head; p->next != NULL; p = p->next);
		p->next = e;
	}
	return head;
}
void create(){
	int i,  v1, v2;
	sf("%d%d", &n, &m);
	for (i = 0; i < m; i++) {
		sf("%d%d", &v1, &v2);
		V[v1].link = insertGraph(V[v1].link, v2);
		V[v2].link = insertGraph(V[v2].link, v1);
	}
}
void quickSort(int k[ ], int left, int right) {
	int i, last;
	int temp;
	if (left < right) {
		last = left;
		for (i = left + 1; i <= right; i++) {
			if (k[i] < k[left]) {
				temp = k[i];
				k[i] = k[++last];
				k[last] = temp;
			}
		}
		temp = k[left];
		k[left] = k[last];
		k[last] = temp;
		quickSort(k, left, last - 1);
		quickSort(k, last + 1, right);
	}
}
void sort() {
	int i, j = 0;
	int k = 0;
	int num[105];
	Elink *p;
	for (i = 0; i < m; i++) {
		for (p = V[i].link; p != NULL; p = p->next) {
			num[k++] = p->data;
		}
		quickSort(num, 0, k - 1);
		for (p = V[i].link; p != NULL; p = p->next) {
			p->data = num[j++];
		}
		j = 0;
		k = 0;
	}
}
int visit[105] = {0};
void DFS(int v) {
	Elink *p;
	visit[v] = 1;
	pf("%d ", v);
	for (p = V[v].link; p != NULL; p = p->next) {
		if (visit[p->data] == 0) {
			DFS(p->data);
		}
	}
}
void travelDFS(int t) {
	int i;
	for (i = 0; i < n; i++) {
		visit[i] = 0;
		if (i == t) {
			visit[i] = 1;
		}
	}
	for (i = 0; i < n; i++) {
		if (visit[i] == 0) {
			DFS(i);
		}
	}
}
void BFS(int v) {
	Elink *p;
	int line[105], head, rear = -1, front = 0;
	visit[v] = 1;
	pf("%d ", v);
	line[++rear] = v;
	while (front <= rear) {
		head = line[front++];
		for (p = V[head].link; p != NULL; p = p->next) {
			if (visit[p->data] == 0) {
				visit[p->data] = 1;
				pf("%d ", p->data);
				line[++rear] = p->data;
			}
		}
	}
}
void travelBFS(int t) {
	int i;
	for (i = 0; i < n; i++) {
		visit[i] = 0;
		if (i == t) {
			visit[i] = 1;
		}
	}
	for (i = 0; i < n; i++) {
		if (visit[i] == 0) {
			BFS(i);
		}
	}
}
int main () {
	create();
	sort();
	int t;
	t = -1;
	travelDFS(t);
	pf("\n");
	travelBFS(t);
	pf("\n");
	sf("%d", &t);
	travelDFS(t);
	pf("\n");
	travelBFS(t);
}

