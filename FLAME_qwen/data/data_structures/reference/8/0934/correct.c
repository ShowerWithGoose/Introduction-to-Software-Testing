#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
struct edge {
	int id;
	struct edge* next;
}Elink;
struct ver {
	int id;
	struct edge* link;
};
struct ver*v[105];
void insert(struct ver* head, int b) {
	struct edge* p,*q;
	p = (struct edge*)malloc(sizeof(struct edge));
	p->id = b;
	p->next = NULL;
	if (head->link == NULL)head->link = p;
	else {
		q = head->link;
		while (q->next != NULL)q = q->next;
		q->next = p;
	}
}
int visit[105];
int sel(struct edge* p) {
	int min = 110;
	for (; p != NULL; p = p->next) {
		//printf(" %dn%d ", p->id,visit[p->id]);
		if (min > p->id && visit[p->id] == 0)min = p->id;
	}
	return min;
}
void DFS(int i) {
	visit[i] = 1;
	printf("%d ", i);
	struct edge* p = v[i]->link;
	struct edge* q = p;
	for (; p != NULL; p = p->next) {
		int min=sel(q);
		if (visit[min] == 0&&min!=110)DFS(min);
	}
}
void BFS(int i) {
	int front = 0, rear = 0, quene[300] = { 0 };
	visit[i] = 1;
	struct edge* p, * q;
	quene[rear++] = i;
	while (front <rear) {
		i = quene[front++];
		printf("%d ", i);
		q = v[i]->link;
		for (p = v[i]->link; p != NULL; p = p->next) {
			//printf("num%d ", p->id);
			int min = sel(q);// printf("s%d ", min);
			if (min != 110 ) {
				visit[min] = 1;
				quene[rear++] = min;
			}
		}
	}
}
int main() {
	for (int i = 0; i < 105; i++) {
		v[i] = (struct ver*)malloc(sizeof(struct ver));
		v[i]->id = i;
		v[i]->link = NULL;
	}
	int nume, numv,v1,v2,des;
	scanf("%d%d", &numv, &nume);
	for (int i = 0; i < nume; i++) {
		scanf("%d %d", &v1, &v2);
		insert(v[v1], v2);
		insert(v[v2], v1);
	}
	scanf("%d", &des);
	for (int i = 0; i < numv; i++) {
		if (visit[i] == 0) {
			DFS(i);
		}
	}
	putchar('\n');
	for (int i = 0; i < 105; i++)visit[i] = 0;
	for (int i = 0; i < numv; i++) {
		if (visit[i] == 0)BFS(i);
	}
	putchar('\n');
	for (int i = 0; i < 105; i++)visit[i] = 0;
	visit[des] = 1;
	for (int i = 0; i < numv; i++) {
		if (visit[i] == 0)DFS(i);
	}
	putchar('\n');
	for (int i = 0; i < 105; i++)visit[i] = 0;
	visit[des] = 1;
	for (int i = 0; i < numv; i++) {
		if (visit[i] == 0)BFS(i);
	}

}

