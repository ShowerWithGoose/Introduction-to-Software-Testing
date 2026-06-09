#include<stdio.h>
#include<stdlib.h>
typedef struct edge {
	int  adjvex;
	int  weight;
	struct edge*next;
} ELink;
typedef struct ver {
	int number;
	ELink*link;
} VLink;
VLink graph[102];
int queue[102];
int top = 0;
int rear = 0;
void enter(int v);
int out();
int V, E;
void crea(int vi, int vj);
void createGraph(int V, int E) {
	for (int i = 0; i < V; i++) {
		graph[i].number = i;
		graph[i].link = NULL;
	}/*建立n个结点*/
	int vi, vj;
	for (int j = 0; j < E; j++) {
		scanf("%d%d", &vi, &vj);
		crea( vi, vj);
		crea( vj, vi);
	}
}
void deleteV(int n, int V) {
	int i, k = -1;
	ELink*p, *q, *r;
	for ( i = 0; i < V; i++) {
		if (graph[i].number == n) {
			k = i;
			break;
		}
	}
	if (k != -1) {
		p = graph[k].link;
		for ( i = k + 1; i < V; i++) {
			graph[i - 1].link = graph[i].link;
			graph[i - 1].number = graph[i].number;
		}
		V--;
		while (p != NULL) {
			r = p;
			p = p->next;
			free(r);
		}
	}
	for ( i = 0; i < V; i++) {
		p = graph[i].link;
		while (p != NULL) {
			if (p->adjvex == k) {
				if (graph[i].link == p) {
					graph[i].link = p->next;
				} else {
					q->next = p->next;
				}
				r = p;
				p = p->next;
				free(r);
			} else {
				if (p->adjvex > k) {
					p->adjvex--;
				}
				q = p;
				p = p->next;
			}
		}
	}
}
void dfs(int V);
void bfs(int V);
void Dfs(VLink a, int V);
void Bfs(VLink a, int V);
int visited[102];
int main() {

	scanf("%d%d", &V, &E);
	createGraph(V, E);
//	for (int i = 0; i < V; i++) {
//		ELink*s = graph[i].link;
//		printf("%d->", graph[i].number);
//		while (s != NULL) {
//			printf("%d->", s->adjvex);
//			s = s->next;
//		}
//		printf("\n");
//	}
	Dfs(graph[0], V);
	Bfs(graph[0], V);
	int n;
	scanf("%d", &n);
	deleteV(n, V);
	V--;
//	for (int i = 0; i < V; i++) {
//		ELink*s = graph[i].link;
//		printf("%d->", graph[i].number);
//		while (s != NULL) {
//			printf("%d->", graph[s->adjvex].number);
//			s = s->next;
//		}
//		printf("\n");
//	}
	Dfs(graph[0], V);
	Bfs(graph[0], V);

	return 0;
}
void Dfs(VLink a, int V) {
	for (int i = 0; i < V; i++) {
		visited[i] = 0;
	}
	for (int i = 0; i < V; i++) {
		if (visited[i] == 0) {
			dfs(i);
		}
	}
	printf("\n");
}
void Bfs(VLink a, int V) {
	for (int i = 0; i < V; i++) {
		visited[i] = 0;
	}
	for (int i = 0; i < V; i++) {
		if (visited[i] == 0) {
			bfs(i);
		}
	}
	printf("\n");
}
void dfs(int v) {
	int w = -1;
	printf("%d ", graph[v].number);
	visited[v] = 1;
	ELink*q = graph[v].link;
	while (q != NULL) {
		w = q->adjvex;
		if (visited[w] == 0) {
			dfs(w);
		}
		q = q->next;
	}
}
void bfs(int v) {
	int w = -1;
	printf("%d ", graph[v].number);
	visited[v] = 1;
	enter(v);
	while (top != rear) {
		v = out();

		ELink*q = graph[v].link;
		while (q != NULL) {
			w = q->adjvex;
			if (visited[w] == 0) {
				printf("%d ", graph[w].number);
				enter(w);
				visited[w] = 1;
			}
			q = q->next;
		}
	}
}
void enter(int v) {
	queue[rear++] = v;
	return;
}
int out() {
	int a = queue[top];
	top++;
	return a;
}
void crea(int vi, int vj) {
	ELink*p = (ELink*)malloc(sizeof(ELink));
	p->adjvex = vj;
	p->next = NULL;
	if (!graph[vi].link) {
		graph[vi].link = p;
	} else {
		ELink*q = graph[vi].link;
		ELink*r;
		if (graph[vi].link->adjvex > p->adjvex) {
			graph[vi].link = p;
			p->next = q;
		} else {
			if (q->next == NULL) {
				q->next = p;
			} else {
				r = q->next;
				while (1) {if(r==NULL){
					q->next=p;
					break;
				}
					if (q->adjvex < p->adjvex && r->adjvex > p->adjvex) {
						p->next = r;
						q->next = p;
						break;
					}
					q = q->next;
					r = r->next;
				}
			}
		}
	}
}

