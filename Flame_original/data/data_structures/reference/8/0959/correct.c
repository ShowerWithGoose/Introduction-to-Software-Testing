#include <stdio.h>
#include <string.h>
int picture[101][101];
int time;
int d[101];
int b[101];

void dfs(int place, int n) {
	int t;
	printf("%d ", place);
	time++;
	if (time == n) {
		return ;
	}
	for (t = 0; t < n; t++) {
		if (d[t] == 0 && picture[t][place] == 1) {
			d[t] = 1;
			dfs(t, n);
		}
	}
	return ;
}

void bfs(int place, int n) {
	int head = 0, tail = 0;
	int que[1000];
	int v;
	int j;
	que[0] = 0;
	b[0] = 1;
	while (head <= tail) {
		v = que[head];
		head++;
		printf("%d ", v);
		for (j = 0; j < n; j++) {
			if (b[j] == 0 && picture[j][v] == 1) {
				que[++tail] = j;
				b[j] = 1;
			}
		}
	}
}

int main() {
	int n, m;
	int x, y;
	int delect;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &x, &y);
		picture[x][y] = picture[y][x] = 1;
	}
	scanf("%d", &delect);
	d[0] = 1, b[0] = 1;
	dfs(0, n);
	printf("\n");
	bfs(0, n);
	printf("\n");
	for (int i = 0; i < n; i++) {
		picture[delect][i] = picture[i][delect] = 0;
	}
	memset(d, 0, sizeof(d));
	memset(b, 0, sizeof(b));
	d[0] = 1, b[0] = 1;
	dfs(0, n);
	printf("\n");
	bfs(0, n);
	return 0;
}
