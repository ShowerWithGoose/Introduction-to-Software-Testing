#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#define ll long long
#define ull unsigned long long
int A[105][105];
int visited[105] = {0};
int dot, line;

void deleteDot(int v) {
	for (int i = 0; i < dot; i++) {
		A[v][i] = A[i][v] = 0;
	}
}

void DFSgraph(int v) {
	visited[v] = 1;
	printf("%d ", v);
	for (int i = 0; i < dot; i++) {
		if (A[v][i] == 1 && visited[i] == 0) {
			DFSgraph(i);
		}
	}
}

int Queue[105];
int rear = -1, front = 0;
void BFSgraph(int v) {
	visited[v] = 1;
	Queue[++rear] = v;
	while (rear >= front) {
		int q = Queue[front++];
		printf("%d ", q);
		for (int i = 0; i < dot; i++) {
			if (A[q][i] == 1 && visited[i] == 0) {
				Queue[++rear] = i;
				visited[i] = 1;
			}
		}
	}
}

int main() {
	int i, j;
	scanf("%d%d", &dot, &line);
	for (int k = 0; k < line; k++) {
		scanf("%d%d", &i, &j);
		A[i][j] = A[j][i] = 1;
	}
	DFSgraph(0);
	putchar('\n');
	for(i=0;i<dot;i++) visited[i]=0;
	BFSgraph(0);
	putchar('\n');
	for(i=0;i<dot;i++) visited[i]=0;
	int deDot;
	scanf("%d", &deDot);
	deleteDot(deDot);
	DFSgraph(0);
	putchar('\n');
	for(i=0;i<dot;i++) visited[i]=0;
	BFSgraph(0);
	return 0;
}

