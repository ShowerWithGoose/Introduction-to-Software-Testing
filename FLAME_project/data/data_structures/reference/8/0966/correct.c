//graphSearch
#include<stdio.h>
#include<stdlib.h>
struct topone {
	int serial;
	struct topone * next;
};
typedef struct topone* top;
top num[120];
top linke(top, int);
void deeplin(top p[], int, int);
int visited[120] = {0};
void DFS(top p[], int i);
void breaflin(top p[], int, int);
void BFS(top p[], int i);
int left = 0, right = -1;
top t[120];
int main() {
	int i;
	for (i = 0; i < 120; i++) {
		num[i] = NULL;
	}
	int point,	line;
	scanf("%d %d", &point, &line);
	for (i = 0; i < point; i++) {
		top p = (top)malloc(sizeof(struct topone));
		p->next = NULL;
		p->serial = i;
		num[i] = p;
	}
	int left, right;
	for (i = 0; i < line; i++) {
		scanf("%d %d", &left, &right);
//		printf("%d",right);
		num[left]->next = linke(num[left]->next, right);
		num[right]->next=linke(num[right]->next,left);
	}
/*		for (i = 0; i < point; i++) {
			top q = num[i];
			while (q != NULL) {
				top r = q;
				q = q->next;
				printf("%d ",r->serial);
			}
			printf("\n");
		}*/
	int op;
	scanf("%d", &op);
	deeplin(num, point, -1);
	printf("\n");
	breaflin(num, point, -1);
	printf("\n");
	deeplin(num, point, op);
	printf("\n");
	breaflin(num, point, op);
	printf("\n");
	for (i = 0; i < point; i++) {
		top q = num[i];
		while (q != NULL) {
			top r = q;
			q = q->next;
			free(r);
		}
	}
	return 0;
}
top linke(top p, int right) {
	top head=p;
	top q = (top)malloc(sizeof(struct topone));
	q->serial = right;
	q->next = NULL;
	if(p==NULL){
		return q;
	}
	if (p->serial > right) {
		q->next = p;
		return q;
	}
	while (p->next != NULL) {
		if(p->next->serial>right){
			q->next=p->next;
			p->next=q;
			return head;
		}
		p = p->next;
	}
	p->next = q;
	return head;
}
void deeplin(top p[], int n, int nt) {
	int i;
	for (i = 0; i < n; i++) {
		visited[i] = 0;
	}
	if (nt != -1) {
		visited[nt] = 1;
	}
	for (i = 0; i < n; i++) {
		if (!visited[i]) {
			DFS(p, i);
		}
	}
}
void DFS(top p[], int i) {
	top q;
	visited[i] = 1;
	printf("%d ", p[i]->serial);
	for (q = p[i]->next; q != NULL; q = q->next) {
		if (!visited[q->serial]) {
			DFS(p, q->serial);
		}
	}
	return;
}
void breaflin(top p[], int n, int nt) {
	int i;
	for (i = 0; i < n; i++) {
		visited[i] = 0;
	}
	if (nt != -1) {
		visited[nt] = 1;
	}
	for (i = 0; i < n; i++) {
		if (!visited[i]) {
			BFS(p, i);
		}
	}
}
void BFS(top p[], int i) {
	top q;
	right = (right + 1) % 120;
	t[right] = p[i];
	while (right >= left) {
		q = t[left];
		left = (left + 1) % 120;
		if (visited[q->serial]) {
			continue;
		}
		visited[q->serial] = 1;
		printf("%d ", q->serial);
		for (q = q->next; q != NULL; q = q->next) {
			right = (right + 1) % 120;
			t[right] = num[q->serial];
		}
	}
	return;
}

