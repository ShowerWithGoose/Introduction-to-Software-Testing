#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int graph[200], con[200][200], visit[200], temp[200], len ;

void dfs(int begin) {
	int i;
	printf("%d ", begin);
	visit[begin] = 1;
	for (i = 0; i < len; i++) {
		if (visit[i] == 0 && con[begin][i] == 1)
			dfs(i);
	}
}

void bfs(int n) {
	int i, j, t;
	temp[1] = n;
	for (i = 1, j = 1; i <= j;) {
		t = temp[i];
		i++;
		if (visit[t] == 1) {
			continue;
		}
		printf("%d ", t);
		visit[t] = 1;
		for (int k = 1; k < len; k++) {
			if (con[t][k] == 1 && visit[k] == 0) {
				j++;
				temp[j] = k;
			}
		}
	}
}

int main() {
	int i, j, n, m, x, y;
	scanf("%d %d", &len, &n);
	for (i = 0; i < n; i++) {
		scanf("%d %d", &x, &y);
		con[x][y] = 1;
		con[y][x] = 1;
	}

	dfs(0);
	printf("\n");
	for (i = 0; i < len; i++)
		visit[i] = 0;
	bfs(0);
	printf("\n");
	scanf("%d", &n);
	for (i = 0; i < len; i++)
		visit[i] = 0;
	visit[n] = 1;
	dfs(0);
	printf("\n");
	for (i = 0; i < len; i++)
		visit[i] = 0;
	visit[n] = 1;
	bfs(0);
	return 0;
}

