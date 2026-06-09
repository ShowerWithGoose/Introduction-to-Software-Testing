#include <stdio.h>
#include <string.h>
#define max 1000
int i,n,m,x,y,a[max][max];
int vis[max], flag, q[max];
void dfs(int x);
void bfs(int t);
int main() {
	scanf("%d%d", &n, &m);
	for (i = 1; i <= m; i++) {
		scanf("%d%d", &x, &y);
		a[x][y] =a[y][x]= 1;
	}
	flag = 0;
	dfs(0);
	printf("\n");
	memset(vis, 0, sizeof(vis));
	flag = 0;
	bfs(0);
	printf("\n");

	scanf("%d", &i);
	vis[i] = 1;
	flag = 0;
	dfs(0);
	printf("\n");
	memset(vis, 0, sizeof(vis));
	vis[i] = 1;
	flag = 0;
	bfs(0);
	printf("\n");
	return 0;
}
void dfs(int x) {
	if (!flag) {
		printf("%d", x);
		flag = 1;
	} else
		printf(" %d", x);
	vis[x] = 1;
	int i;
	for (i = 1; i <= n; i++)
		if (a[x][i]&&!vis[i])
			dfs(i);
}
void bfs(int t) {
	q[1] = t;
	int l = 1, r = 1, i;
	while (l <= r) {
		x = q[l];
		l++;
		if (vis[x])
			continue;
		if (!flag) {
			printf("%d", x);
			flag = 1;
		} else
			printf(" %d", x);

		vis[x] = 1;
		for (i = 1; i <= n; i++)
			if (a[x][i]&&!vis[i])
				q[++r] = i;
	}
	memset(vis, 0, sizeof(vis));
}


