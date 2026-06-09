#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int sumV, sumE, c;
int tmp_v1, tmp_v2;
bool flag[110];

struct edge{
	int nextv;
	struct edge * next;
};

struct ver{
	struct edge * link;
}linkV[110];

void insert(int, int);
void delet(int);
void DFS(int);
void BFS(int);
void print();

int main() {
	
	scanf("%d%d", &sumV, &sumE);
	for (int i = 0; i < sumE; i++) {
		scanf("%d%d", &tmp_v1, &tmp_v2);
		insert(tmp_v1, tmp_v2);
		insert(tmp_v2, tmp_v1);
	}
	
	
	memset(flag, 0, 110);
	DFS(0);
	printf("\n");
	BFS(0);
	
	scanf("%d", &c);
	linkV[c].link = NULL;
	delet(c);
	
	memset(flag, 0, 110);
	DFS(0);
	printf("\n");
	BFS(0);
	
	return 0;
}

void insert(int v1, int v2) {
	struct edge * p = (struct edge *)malloc(sizeof(struct edge));
	struct edge * q;
	p -> nextv = v2;
	p -> next = NULL;
	if (linkV[v1].link == NULL) {//没有，直接丢进去
		linkV[v1].link = p;
		return;
	}
	if (v2 < linkV[v1].link -> nextv) {//要放在第一个节点的位置
		p -> next = linkV[v1].link;
		linkV[v1].link = p;
		return;
	}
	for (q = linkV[v1].link; q -> next != NULL; q = q -> next) {//他比第一个节点的数大
		if (q -> next -> nextv > v2) {
			p -> next = q -> next;
			q -> next = p;
			return;
		}
	}
	q -> next = p;//恰好是最大的,放最后
}

void delet(int v2) {
	for (int i = 0; i < 105; i++) {
		if(linkV[i].link != NULL) {
			if (linkV[i].link -> nextv == v2) 
				linkV[i].link = linkV[i].link -> next;
			else {
				for (struct edge * p = linkV[i].link; p -> next != NULL; p = p -> next) {
					if (p -> next -> nextv == v2) {
						p -> next = p -> next -> next;
						break;
					}
				}
			}
		}
	}
}

void DFS(int n) {
	printf("%d ", n);
	flag[n] = 1;
	struct edge * p = linkV[n].link;
	for (; p != NULL; p = p -> next) {
		if (!flag[p -> nextv])
			DFS(p -> nextv);
	}
}

void BFS(int n) {
	memset(flag, 0, 110);
	struct ver queue[110] = {};
	queue[0] = linkV[n];
	flag[n] = 1;
	printf("%d ", n);
	int head = 0, tail = 0;
	while(head <= tail) {
		if(queue[head].link != NULL) {
			for (struct edge * p = queue[head].link; p != NULL; p = p -> next) {
				if (!flag[p -> nextv]) {
					printf("%d ", p -> nextv);
					flag[p -> nextv] = 1;
					queue[++tail] = linkV[p -> nextv];
				}
			}
		}
		head ++;
	}
	printf("\n");
}

void print() {
	for (int i = 0; i < 104; i++) {
		if (linkV[i].link != NULL) {
			printf("\n%d->", i);
			for (struct edge * p = linkV[i].link; p != NULL; p = p->next)
				printf(" %d", p->nextv);
		}
	}
}

