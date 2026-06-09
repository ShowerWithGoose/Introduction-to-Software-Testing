#include<stdio.h>
#include<stdlib.h>

typedef struct edge {
	int adjvex;
	struct edge *next;
} ELink;

typedef struct ver {
	int  vertex;
	ELink *link;
} VLink;
int top = -1;
int top1 = -1;
int num = 0;
int num1 = 0;
int bottom = 0;
int bottom1 = 0;
int stack[505];
int stack1[105];
int Visited[105] = {0};
void BFS(VLink G[ ], int v) {
	ELink *p;
	printf("%d ", G[v].vertex);
	Visited[v] = 1; //标识某顶点被访问过
	top++;
	num++;
	stack[top] = v;
	while ( num != 0) {
		v = stack[bottom];
		bottom++;
		num--;
		p = G[v].link; //获取该顶点第一个邻接顶点

		for (; p != NULL ; p = p->next )
			if ( !Visited[p->adjvex] ) {
				printf("%d ", p->adjvex);
				Visited[p->adjvex] = 1;
				top++;
				num++;
				stack[top] = p->adjvex;
			}
	}
}

void travelBFS(VLink G[ ], int n, int d) {
	int i;
	for (i = 0; i < n + 1; i++) {
		if (i == d) {
			continue;
		}
		Visited[i] = 0 ;
	}
	for (i = 0; i < n; i++)
		if ( !Visited[i] )
			BFS(G, i);
}


void DFS(VLink G[ ], int v) {
	ELink *p;
	printf("%d ", G[v].vertex); //访问某顶点
	Visited[v] = 1; //标识某顶点被访问过
	for (p = G[v].link; p != NULL; p = p->next)
		if ( !Visited[p->adjvex] )
			DFS(G, p->adjvex);
}

void travelDFS(VLink G[ ], int n, int d) {
	int i;
	for (i = 0; i < n + 1; i++) {
		if (i == d) {
			continue;
		}
		Visited[i] = 0 ;
	}

	for (i = 0; i < n; i++)
		if ( !Visited[i] )
			DFS(G, i);
}

void DELVER(VLink G[], int n, int item) {
	int i, k = -1;
	ELink *p, *q, *r;
	for (i = 0; i < n; i++)
		if (G[i].vertex == item) {
			k = i;
			break;
		}
	if (k != -1) {
		p = G[k].link;
		/*for (i = k + 1; i < n; i++) {
			G[i - 1].vertex = G[i].vertex;
			G[i - 1].link = G[i].link;
		}*/
		G[k].vertex=-1;
		G[k].link=NULL;
		n--;
		/*while (p != NULL) {
			r = p;
			p = p->next;
			free(r);
		}*/
		for (i = 0; i < n; i++) {
			p = G[i].link;
			while (p != NULL) {
				if (p->adjvex == k) {
					if (G[i].link == p)
						G[i].link = p->next;
					else {
						q->next = p->next;
					}
					r = p;
					p = p->next;
					free(r);
				} else {
					q = p;
					p = p->next;
				}
			}
		}
	}
}

int main() {
	VLink G[105];
	ELink* tail[105], *p, *q;
	int n, m, i, a1, a2, d;
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++) {
		G[i].link = NULL;
	}
	for (i = 0; i < m; i++) {
		scanf("%d%d", &a1, &a2);
		ELink *p;
		p = (ELink*)malloc(sizeof(ELink));
		p->adjvex = a2;
		p->next = NULL;
		G[a1].vertex = a1;
		if (G[a1].link == NULL) {
			G[a1].link = p;
			p->next = NULL;
			tail[a1] = p;
		} else {
			tail[a1]->next = p;
			tail[a1] = p;
			p->next = NULL;
		}
		ELink* t;
		t = (ELink*)malloc(sizeof(ELink));
		t->adjvex = a1;
		t->next = NULL;
		G[a2].vertex = a2;
		if (G[a2].link == NULL) {
			G[a2].link = t;
			tail[a2] = t;
		} else {
			tail[a2]->next = t;
			tail[a2] = t;
		}
	}
	for (i = 0; i < n; i++) {
		for (p = G[i].link; p != NULL; p = p->next) {
			for (q = p->next; q != NULL; q = q->next) {
				if (p->adjvex > q->adjvex) {
					int temp;
					temp = p->adjvex;
					p->adjvex = q->adjvex;
					q->adjvex = temp;
				}
			}
		}
	}
	scanf("%d", &d);
	travelDFS(G, n, -1);
	printf("\n");
	travelBFS(G, n, -1);
	DELVER(G, n, d);
	//Visited[d]=1;
	printf("\n");
	travelDFS(G, n , d);
	printf("\n");
	travelBFS(G, n , d);

	return 0;
}

