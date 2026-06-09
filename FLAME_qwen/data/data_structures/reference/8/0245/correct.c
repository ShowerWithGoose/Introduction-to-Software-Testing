#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void DFSearch(int, int, int**, int);
void BFSearch(int, int, int**, int);

int main() {
	int a = 0, b = 0, target = 0;
	scanf("%d %d", &a, &b);
	int** graph = (int**)malloc(sizeof(int*) * a);
	for (int i = 0; i < a; ++i) {
		graph[i] = (int*)malloc(sizeof(int) * a);
		for (int j = 0; j < a; ++j) {
			graph[i][j] = 0;
		}
	}
	for (int i = 0; i < b; ++i) {
		int m = 0, n = 0;
		scanf("%d %d", &m, &n);
		graph[m][n] = graph[n][m] = 1;
	}
	scanf("%d", &target);
	DFSearch(0, a, graph, 0);
	BFSearch(0, a, graph, 0);
	int** newGraph = (int**)malloc(sizeof(int*) * (a - 1));
	for (int i = 0; i < a; ++i) {
		newGraph[i] = (int*)malloc(sizeof(int) * a);
		for (int j = 0; j < a; ++j) {
			newGraph[i][j] = 0;
		}
	}
	for (int i = 0; i < target; ++i) {
		for (int j = 0; j < target; ++j) {
			newGraph[i][j] = graph[i][j];
		}
		for (int j = target + 1; j < a; ++j) {
			newGraph[i][j - 1] = graph[i][j];
		}
	}
	for (int i = target + 1; i < a; ++i) {
		for (int j = 0; j < target; ++j) {
			newGraph[i - 1][j] = graph[i][j];
		}
		for (int j = target + 1; j < a; ++j) {
			newGraph[i - 1][j - 1] = graph[i][j];
		}
	}
	DFSearch(0, a - 1, newGraph, target);
	BFSearch(0, a - 1, newGraph, target);
	return 0;
}

void DFSearch(int start, int total, int** graph, int del) {
	int* stack = (int*)malloc(sizeof(int) * total);
	int* flag = (int*)malloc(sizeof(int) * total);
	for (int i = 0; i < total; ++i) {
		flag[i] = 0;
	}
	int top = -1, cnt = 1;
	stack[++top] = start;
	flag[start] = cnt;
	printf("%d ", start);
	while (cnt < total) {
		int changeflag = 0;
		for (int i = 0; i < total; ++i) {
			if (graph[stack[top]][i] == 1 && flag[i] == 0) {
				if (del == 0 || i < del) {
					printf("%d ", i);
				}
				else {
					printf("%d ", i + 1);
				}
				stack[++top] = i;
				changeflag = 1;
				flag[i] = ++cnt;
				break;
			}
		}
		if (changeflag == 0) {
			--top;
		}
	}
	printf("\n");
}

void BFSearch(int start, int total, int** graph, int del) {
	int* queue = (int*)malloc(sizeof(int) * total);
	int* flag = (int*)malloc(sizeof(int) * total);
	for (int i = 0; i < total; ++i) {
		flag[i] = 0;
	}
	int head = -1, tail = -1, cnt = 1;
	queue[++tail] = start;
	flag[start] = cnt;
	printf("%d ", start);
	while (cnt < total) {
		int target = queue[++head];
		for (int i = 0; i < total; ++i) {
			if (graph[target][i] == 1 && flag[i] == 0) {
				if (del == 0 || i < del) {
					printf("%d ", i);
				}
				else {
					printf("%d ", i + 1);
				}
				queue[++tail] = i;
				flag[i] = ++cnt;
			}
		}
	}
	printf("\n");
}


