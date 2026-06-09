#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxV    256

typedef struct edge {
	int adj;
	struct edge *next;
} Elink;

typedef struct ver {
	Elink *link;
} Vlink;
Vlink  G[MaxV];
Elink *createGraph(Elink *head, int avex);
void DFS(Vlink G[], int v);
void  travelDFS(Vlink  G[ ], int n);
Elink *deleteGraph(Elink *head, int num);
void  traveldeDFS(Vlink  G[ ], int n, int num);

int main() {
	int Vernum, Linknum;
	int deVer;
	scanf("%d %d", &Vernum, &Linknum);
	int a, b;
	for (int i = 0; i < Linknum; i++) {
		scanf("%d %d", &a, &b);
		G[a].link = createGraph(G[a].link, b);
		G[b].link = createGraph(G[b].link, a);
	}
	scanf("%d", &deVer);
	travelDFS(G, Vernum);
	printf("\n");
	int Visited[MaxV] = {0};
	for (int i = 0; i < MaxV; i++) {
		Visited[i] = 0;
	}
	Elink *p;
	int Q[500];
	int top = 0; //¶ÓÎ²
	int rear = -1; //¶ÓÍ·
	for (int i = 0; i < Vernum; i++) {
		if (Visited[i] == 0) {
			Visited[i] = 1;
			Q[top++] = i;
			while (rear < top - 1) {
				int tou = Q[++rear];
				printf("%d ", tou);
				for (p = G[tou].link; p != NULL; p = p->next) {
					if (Visited[p->adj] == 0) {
						Visited[p->adj] = 1;
						Q[top++] = p->adj;
					}
				}
			}

		}
	}
	/*for (int i = 0; i < Vernum; i++) {
		if (Visited[i] == 0) {
			printf("%d ", i);
		}
		Visited[i] = 1;
		for (p = G[i].link; p != NULL; p = p->next) {
			if (Visited[p->adj] == 0) {
				printf("%d ", p->adj);
				Visited[p->adj] = 1;
				//printf("\n");
			}
		}
		/*for (p = G[i].link; p->next != NULL; p = p->next) {
			printf("%d ", p->adj);
		}
		printf("\n");
	}*/
	printf("\n");
	for (int i = 0; i < Vernum; i++) {
		G[i].link = deleteGraph(G[i].link, deVer);
	}
	traveldeDFS(G, Vernum, deVer);
	printf("\n");
	for (int i = 0; i < MaxV; i++) {
		Visited[i] = 0;
	}
	top = 0;
	rear = -1;
	for (int i = 0; i < Vernum; i++) {
		if (i != deVer) {
			if (Visited[i] == 0) {
				Visited[i] = 1;
				Q[top++] = i;
				while (rear < top - 1) {
					int tou = Q[++rear];
					printf("%d ", tou);
					for (p = G[tou].link; p != NULL; p = p->next) {
						if (Visited[p->adj] == 0) {
							Visited[p->adj] = 1;
							Q[top++] = p->adj;
						}
					}
				}

			}
		}
	}
	/*for (int i = 0; i < MaxV; i++) {
		Visited[i] = 0;
	}
	for (int i = 0; i < Vernum; i++) {
		if (i != deVer) {
			if (Visited[i] == 0) {
				printf("%d ", i);
			}
			Visited[i] = 1;
			for (p = G[i].link; p != NULL; p = p->next) {
				if (Visited[p->adj] == 0) {
					printf("%d ", p->adj);
					Visited[p->adj] = 1;
					//printf("\n");
				}
			}
			/*for (p = G[i].link; p->next != NULL; p = p->next) {
				printf("%d ", p->adj);
			}
			printf("\n");
		}
	}*/


	return 0;
}

Elink *createGraph(Elink *head, int avex) {
	Elink *p, *e;
	e = (Elink *)malloc(sizeof(Elink));
	e->adj = avex;
	e->next = NULL;
	if (head == NULL) {
		head = e;
		return head;
	}
	if (head->adj > avex) {
		e->next = head;
		return e;
	}
	int flag = 0;
	for (p = head; p->next != NULL; p = p->next) {

		if (p->adj < avex && p->next->adj > avex) {
			e->next = p->next;
			p->next = e;
			flag = 1;
			break;
		}

	}
	if (flag == 0) {
		p->next = e;
	}
	return head;
}

int visited[MaxV] = {0};

void  travelDFS(Vlink  G[ ], int n) {
	int i;
	for (i = 0; i < n; i++)
		visited[i] = 0 ;
	for (i = 0; i < n; i++)
		if ( !visited[i] )
			DFS(G, i);
}

void  traveldeDFS(Vlink  G[ ], int n, int num) {
	int i;
	for (i = 0; i < n; i++)
		visited[i] = 0 ;
	for (i = 0; i < n; i++) {
		if (i != num) {
			if ( !visited[i] )
				DFS(G, i);
		}
	}
}

void DFS(Vlink G[], int v) {
	Elink *p;
	visited[v] = 1;
	printf("%d ", v);
	for (p = G[v].link; p != NULL; p = p->next) {
		if (visited[p->adj] == 0) {
			DFS(G, p->adj);
		}
	}
}

Elink *deleteGraph(Elink *head, int num) {
	Elink *p;
	if (head->adj == num) {
		head = head->next;
		return head;
	}
	for (p = head; p->next != NULL; p = p->next) {
		if (p->next->adj == num) {
			p->next = p->next->next;
			break;
		}

	}
	return head;
}
