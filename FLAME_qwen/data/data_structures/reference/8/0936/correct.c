#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
int grape[100][100];
int vist[100];
int N, d, flag = 0;
void DFS(int v) {
	vist[v] = 1;
	printf("%d ", v);
	for (int i = 0; i < N; i++) {
		if (grape[v][i] == 1) {
			if (!vist[i]) {
				DFS(i);
			}
		}
	}
}
void trDFS() {
	for (int i = 0; i < N; i++) {
		if (!vist[i]) {
			DFS(i);
		}
	}
}
int Cqueue[100];
int Cfront = 0;
int  Crear = -1;
int Cnum = 0;
int  isEmpty() {
	return Cnum == 0;
}
int  isFull()  {
	return Cnum == 100;
}
void enCustqueue(int c) {
	if (isFull()) {
		printf("Full queue!");
		exit(-1);
	} else {
		Crear = (Crear + 1) % 100;
		Cqueue[Crear] = c;
		Cnum++;
	}
}
int deCustqueue() {
	int c;
	if (isEmpty()) {
		printf("Empty queue!");
		exit(-1);
	} else {
		c = Cqueue[Cfront];
		Cnum--;
		Cfront = (Cfront + 1) % 100;
		return c;
	}
}
void BFS(int v) {
	vist[v] = 1;
	enCustqueue(v);
	while (!isEmpty()) {
		v = deCustqueue();
		printf("%d ", v);
		for (int i = 0; i < N; i++) {
			if (grape[v][i] == 1) {
				if (!vist[i]) {
					vist[i] = 1;
					enCustqueue(i);
				}
			}
		}
	}
}
void trBFS() {
	for (int i = 0; i < N; i++) {
		if (!vist[i]) {
			BFS(i);
		}
	}
}
int main() {
	int b, m, n;
	scanf("%d %d", &N, &b);
	for (int i = 0; i < b; i++) {
		scanf("%d %d", &m, &n);
		grape[m][n] = grape[n][m] = 1;
	}
	scanf("%d", &d);
	for (int i = 0; i < N; i++) {
		vist[i] = 0;
	}
	trDFS();
	printf("\n");
	for (int i = 0; i < N; i++) {
		vist[i] = 0;
	}
	trBFS();
	printf("\n");

	for (int i = 0; i < N; i++) {
		vist[i] = 0;
	}
	vist[d] = 1;
	trDFS();
	printf("\n");
	for (int i = 0; i < N; i++) {
		vist[i] = 0;
	}
	vist[d] = 1;
	trBFS();
	return 0;
}

