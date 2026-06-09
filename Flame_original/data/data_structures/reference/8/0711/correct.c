#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define ll long long
#define MaxV    256
#define N 128
int  Q[1000], Qfirst, Qlast = 1;
int G[N][N];
int  Visited[N] = {0};
void travelDFS(int v, int n);
void  travelBFS( int v, int n);
void enQueue( int v);
int deQueue(int Q[]);
int emptyQ(int Q[]);
int main() {
	int dot, line, a, no, b;
	scanf("%d %d", &dot, &line);
	for (int i = 0; i <= line - 1; i++) {
		scanf("%d %d", &a, &b);
		G[a][b] = 1;
		G[b][a] = 1;
	}
	scanf("%d", &no);
	travelDFS(0, dot);
	memset(Visited, 0, sizeof(Visited));
	printf("\n");
	travelBFS(0, dot);
	memset(Visited, 0, sizeof(Visited));
	printf("\n");
	Visited[no] = 1;
	travelDFS(0, dot);
	memset(Visited, 0, sizeof(Visited));
	Visited[no] = 1;
	printf("\n");
	travelBFS(0, dot);
}
void travelDFS(int v, int n) {
	int i;
	printf("%d ", v);
	Visited[v] = 1;
	for (i = 0; i < n; i++)
		if (G[v][i] && !Visited[i]) {
			travelDFS(i, n); //DFS访问
		}
}

void  travelBFS(int v, int n) {
	Q[Qfirst] = v;
	int temp, Qfirst = 0, Qlast = 1;
	while (Qfirst <= Qlast) { //队列访问完毕
		temp = Q[Qfirst]; //出队
		Qfirst++;   //出队
		if (Visited[temp] == 1) continue; //如果访问过
		else {
			printf("%d ", temp); //打印出队元素
			Visited[temp] = 1; //已访问
			for (int i = 0; i < n; i++)
				if (G[temp][i] && !Visited[i]) { //如果矩阵元素为 1 且未访问过
					Q[Qlast] = i; //入队
					Qlast++;
				}
		}
	}
}

