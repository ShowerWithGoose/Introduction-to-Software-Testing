#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h> 
int n, m, g[100][100], u = 101, v[100];

void dfs(int t) {
	int i;
	printf("%d ", t);
	v[t] = 1;
	for (i = 0; i < n; i++) {
		if (i == u || v[i] || !g[t][i]) continue;
		dfs(i);
	}
}
int q[200], front = 1, rear = 0;
void bfs() {
	int i;
	int x;
	q[++rear] = 0;
	while (front <= rear) {
		x = q[front];
		if (v[x]) {front++; continue;}
		printf("%d ", x);
		v[x] = 1;
		for (i = 0; i < n; i++) {
			if (i == u || v[i] || !g[x][i]) continue;
			q[++rear] = i;
		}
		front++;
	}
}
int main()
{
	int x, y, i;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= m; i ++) {
		scanf("%d%d", &x, &y);
		g[x][y] = g[y][x] = 1;
	}
	dfs(0); printf("\n");
	memset(v, 0, sizeof(v));
	bfs(); printf("\n");
	scanf("%d", &u);
	memset(v, 0, sizeof(v));
	dfs(0); printf("\n");
	memset(v, 0, sizeof(v));
	bfs(); printf("\n");
	return 0;
}

