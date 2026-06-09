#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int tu[101][101], flag[101], queue[101];
int d, i, j, k, n, m, head, tail;

void dfs(int a) {
	int i, s;
	printf("%d ", a);
	s++;
	if (s == n)
		return;
	for (i = 0; i < n; i++) {
		if (tu[a][i] == 1 && flag[i] == 0) {
			flag[i] = 1;
			dfs(i);
		}
	}
}

void bfs() {
	while (head < tail) {
		int cur = queue[head];
		int i = 0;
		for (; i < n; i++) {
			if (tu[cur][i] == 1 && flag[i] == 0) {
				flag[i] = 1;
				queue[tail++] = i;
			}
			if (tail > n)
				break;
		}
		head++;
	}
}

int main( ) {
	scanf("%d%d", &n, &m);
	for (k = 0; k < m; k++) {
		scanf("%d%d", &i, &j);
		tu[i][j] = 1;
		tu[j][i] = 1;
	}
	scanf("%d", &d);
	flag[0] = 1;
	dfs(0);
	printf("\n");
	for (i = 1; i <= n; i++)
		flag[i] = 0;
	queue[head] = 0;
	tail++;
	bfs();
	for (i = 0; i < n; i++) {
		printf("%d ", queue[i]);
	}
	printf("\n");
	for (i = 1; i < n; i++) {
		flag[i] = 0;
	}
	for (i = 0; i < n; i++) {
		tu[d][i] = tu[i][d] = 0;
	}
	dfs(0);
	printf("\n");
	for (i = 1; i <= n; i++)
		flag[i] = 0;
	for (i = 0; i <= n; i++) {
		queue[i] = 0;
	}
	head = 0;
	tail = 1;
	bfs();
	for (i = 0; i < n - 1; i++) {
		printf("%d ", queue[i]);
	}
	return 0;
}



