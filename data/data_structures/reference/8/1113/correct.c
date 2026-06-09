#define  _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define TypeG int
#define MAXVER 200
 int queue[MAXVER]; int front = 0, rear = -1;
 int Visited[MAXVER];
 int V[MAXVER][MAXVER];
void DFS(int v,int n)
{
	printf("%d ", v);
	Visited[v] = 1;
	for (int i = 0; i < n; i++) {
		if (V[v][i] && !Visited[i])
			DFS(i, n);
	}
}
void  travelDFS(int n,int flag)
{
	int i;
	for (i = 0; i < n; i++) Visited[i] = 0;
	if (flag >= 0) Visited[flag] = 1;
	for (i = 0; i < n; i++)
		if (!Visited[i]) DFS(i,n);
	printf("\n");
}
void BFS(int v,int n)
{
	int temp;
	queue[++rear] = v;//入队
	while (front <= rear) {
		temp = queue[front++];//出队
		if (!Visited[temp]) {
			printf("%d ", temp);
			Visited[temp] = 1;
			for (int i = 0; i < n; i++) {
				if (V[temp][i] && !Visited[i])
					queue[++rear] = i;
			}
		}
	}
}
void  travelBFS(int n,int flag)
{
	front = 0, rear = -1;
	int i;
	memset(queue, 0, sizeof(queue));
	for (i = 0; i < n; i++) Visited[i] = 0;
	if (flag >= 0) Visited[flag] = 1;
	for (i = 0; i < n; i++)
		if (!Visited[i]) BFS(i,n);
	printf("\n");
}
int main()
{
	int v, e;
	scanf("%d %d", &v, &e);
	int a, b;
	for (int i = 0; i < e; i++) {
		scanf("%d%d", &a, &b);
		V[a][b] = 1;
		V[b][a] = 1;
	}
	int del; scanf("%d", &del);
	travelDFS(v,-1);
	travelBFS(v,-1);
	travelDFS(v,del);
	travelBFS(v,del);
	return 0;
}



