#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#define Maxsize 105

int G[Maxsize][Maxsize];
int visited[Maxsize];
int queue[Maxsize];
int rear = -1, front = 0;
int vert, edge;

//function
void travelDFS(int x);//访问x结点
void DFS(int x);
void travelBFS(int x);
void BFS(int x);
int isempty() {
	return rear < front ? 1 : 0;
}

void push(int data) {
	queue[++rear] = data;
}

int pop() {
	return isempty() ? -1 : queue[front++];
}

int main() {
	int  x, y, item;
	scanf("%d%d", &vert, &edge);
	//邻接矩阵
	for (int i = 0; i < edge; i++) {
		scanf("%d%d", &x, &y);
		G[x][y] = 1;
		G[y][x] = 1;
	}
	scanf("%d", &item);

	//遍历
	travelDFS(0);
	printf("\n");
	for (int i = 0; i < vert; i++)
		visited[i] = 0;
	travelBFS(0);
	printf("\n");

	//删除顶点
	for (int i = 0; i < vert; i++) {
		G[item][i] = G[i][item] = 0;
	}

	//遍历
	for (int i = 0; i < vert; i++)
		visited[i] = 0;
	travelDFS(0);
	printf("\n");
	for (int i = 0; i < vert; i++)
		visited[i] = 0;
	travelBFS(0);
	printf("\n");


	return 0;
}


void travelDFS(int x) {
	printf("%d ", x);
	visited[x] = 1;
	for (int i = 0; i < vert; i++) {
		if (G[x][i] == 1 && visited[i] == 0)
			travelDFS(i);
	}
	return ;
}

void travelBFS(int x) {
	int cur;
	push(x);
	visited[x] = 1;
	while (!isempty()) {
		cur = pop();
		printf("%d ", cur);
		for (int i = 0; i < vert; i++) {
			if (G[cur][i] == 1 && visited[i] == 0) {
				push(i);
				visited[i] = 1;
			}
		}
	}
}


