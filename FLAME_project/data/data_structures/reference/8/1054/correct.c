#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int G[105][105] = { 0 };
vis[105] = { 0 };
int firstadj(int v,int n) {
	for (int i = 0; i < n; i++) {
		if (G[v][i] != 0) {
			return i;
		}
	}
	return -1;
}
int nextadj(int w,int v, int n) {
	for (int i = w+1; i < n; i++) {
		if (G[v][i] != 0) {
			return i;
		}
	}
	return -1;
}
void DFS(int v,int n) {
	int w = -1;
	printf("%d ", v);
	vis[v] = 1;
	w = firstadj(v, n);
	while (w != -1) {
		if (vis[w] == 0) {
			DFS(w, n);
		}
		w = nextadj(w, v, n);
	}
}

#define MAXSIZE     1000
int  queue[MAXSIZE];
int  front, rear, count;
void  initQueue()
{
	front = 0;
	rear = MAXSIZE - 1;
	count = 0;
}
int  isEmpty()
{
	if (count == 0) {
		return 1;
	}
	else {
		return 0;
	}
}
int  isFull()
{
	if (count == MAXSIZE) {
		return 1;
	}
	else {
		return 0;
	}
}
void enQueue(int item)
{
	if (isFull())                       /* 队满，插入失败 */
		printf("Full queue!\n");
	else {
		rear = (rear + 1) % MAXSIZE;
		queue[rear] = item;
		count++;
		/* 队未满，插入成功 */
	}
}
int  deQueue()
{
	int e;
	if (isEmpty())
		printf("GG!\n");     /* 队空，删除失败 */
	else {
		e = queue[front];
		count--;                             /* 队非空，删除成功 */
		front = (front + 1) % MAXSIZE;
		return e;//并返回队头元素
	}
}

void BFS(int v,int n) {
	int w;
	printf("%d ", v);
	vis[v] = 1;
	enQueue(v);
	while (!isEmpty()) {
		v = deQueue();
		w = firstadj(v, n);
		while (w != -1) {
			if (vis[w] == 0) {
				printf("%d ", w);
				enQueue(w);
				vis[w] = 1;
			}
			w = nextadj(w, v, n);
		}
	}
}

int main() {
	int v = 0, edge = 0,v1,v2,delv;
	int so = scanf("%d %d", &v, &edge);
	for (int i = 0; i < edge;i++) {
		int sowhat = scanf("%d %d", &v1, &v2);
		G[v1][v2] = 1;
		G[v2][v1] = 1;
	}
	DFS(0, v);
	printf("\n");
	for (int i = 0; i < v; i++) {
		vis[i] = 0;
	}
	BFS(0, v);
	printf("\n");
	scanf("%d", &delv);
	




	for (int i = 0; i < v; i++) {
		vis[i] = 0;
	}
	vis[delv] = 1;
	DFS(0,v);
	printf("\n");
	for (int i = 0; i < v; i++) {
		vis[i] = 0;
	}
	for (int i = 0; i < v; i++) {
		for (int j = 0; j < v; j++) {
			if (j == delv) {
				G[i][j] = 0;
				G[j][i] = 0;
			}
		}
	}
	for (int k = 0; k <= rear; k++) {
		queue[k] = 0;
	}
	initQueue();
	vis[delv] = 1;
	BFS(0, v);



	return 86;
}
