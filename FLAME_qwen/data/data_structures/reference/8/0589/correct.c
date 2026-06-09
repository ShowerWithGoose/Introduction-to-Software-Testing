#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n1, n2, del;
int edge[1000][1000];
int st[1000], queue[1000];
void dfs(int index) {
	if (st[index])
		return ;
	st[index] = 1;
	printf("%d ", index);
	for (int i = 0; i < n1; i++)
		if (edge[index][i])
			dfs(i);
}

void bfs() {
	int hh = 0, tt = -1;
	queue[++tt] = 0;
	st[0] = 1;
	while (hh <= tt) {
		int temp = queue[hh++];
		printf("%d ", temp);
		for (int i = 0; i < n1; i++)
			if (!st[i] && edge[temp][i]) {
				st[i] = 1;
				queue[++tt] = i;
			}
	}
}

int main(void) {
	scanf("%d%d", &n1, &n2);
	memset(st, 0, sizeof(st));
	for (int i = 0; i < n2; i ++) {
		int a, b;
		scanf("%d%d", &a, &b);
		edge[a][b] = 1;
		edge[b][a] = 1;
	}
	dfs(0);
	memset(st, 0, sizeof(st));
	puts("");
	bfs();
	puts("");
	memset(st, 0, sizeof(st));
	scanf("%d", &del);
	for (int i = 0; i < n1; i++)
		edge[del][i] = 0, edge[i][del] = 0;
	dfs(0);
	puts("");
	memset(st, 0, sizeof(st));
	bfs();

	return 0;
}

