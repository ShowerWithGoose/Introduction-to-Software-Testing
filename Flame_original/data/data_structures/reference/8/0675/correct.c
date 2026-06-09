#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int visited[100] = {0};

int queue[100] = {0}, j = 0, k = 1;

struct pointlink {
	int num;
	struct pointlink *next;
} *point[100];

void dfsearch(int t) {
	visited[point[t]->num] = 1;
	printf("%d ", t);
	struct pointlink *pt = point[t];
	while (pt->next != NULL) {
		pt = pt->next;
		if (visited[pt->num] == 0)
			dfsearch(pt->num);
	}
}

void bfsearch(int t) {
	visited[t] = 1;
	struct pointlink *pt = point[t];
	while (pt->next != NULL) {
		pt = pt->next;
		if (visited[pt->num] == 0) {
			printf("%d ", pt->num);
			queue[k++] = pt->num;
			visited[pt->num] = 1;
		}
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		point[i] = (struct pointlink *)malloc(sizeof(struct pointlink));
		point[i]->num = i;
		point[i]->next = NULL;
	}
	struct pointlink *p, *q;
	int a, b;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		p = (struct pointlink *)malloc(sizeof(struct pointlink));
		p->num = b;
		p->next = NULL;
		q = point[a];
		while (q->next != NULL && q->next->num < b)
			q = q->next;
		if (q->next == NULL) {
			q->next = p;
		} else {
			p->next = q->next;
			q->next = p;
		}
		p = (struct pointlink *)malloc(sizeof(struct pointlink));
		p->num = a;
		p->next = NULL;
		q = point[b];
		while (q->next != NULL && q->next->num < a)
			q = q->next;
		if (q->next == NULL) {
			q->next = p;
		} else {
			p->next = q->next;
			q->next = p;
		}
	}
	int dept;
	scanf("%d", &dept);
//	for (int i = 0; i < n; i++) {
//		p = point[i];
//		while (p != NULL) {
//			printf("%d ", p->num);
//			p = p->next;
//		}
//		printf("\n");
//	}
	for (int i = 0; i < n; i++) {
		if (visited[i] == 0)
			dfsearch(i);
	}
	printf("\n");
	for (int i = 0; i < n; i++)
		visited[i] = 0;
	printf("0 ");
	for (int j = 0; j < n; j++) {
		bfsearch(queue[j]);
	}
	printf("\n");
	for (int i = 0; i < n; i++)
		visited[i] = 0;
	visited[dept] = 1;
	for (int i = 0; i < n; i++) {
		if (visited[i] == 0)
			dfsearch(i);
	}
	printf("\n");
	for (int i = 0; i < n; i++) {
		visited[i] = 0;
		queue[i] = 0;
	}
	k = 1;
	visited[dept] = 1;
	printf("0 ");
	for (int j = 0; j < n; j++) {
		bfsearch(queue[j]);
	}
}
