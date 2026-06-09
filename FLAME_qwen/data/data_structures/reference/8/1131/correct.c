#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n, m, a[105][105];
int vis[105], q[105],flag=0;
void dfs(int x)
{
	if (!flag) {
		printf("%d", x);
		flag = 1;
	}
	else
		printf(" %d", x);
	vis[x] = 1;
	int i;
	for (i = 1; i <= n; i++) {
		if (a[x][i]) {
			if (!vis[i]) {
				//			printf("&&%d %d\n",x,i);
				dfs(i);
			}
		}
	}
}
void bfs(int t){
	q[1] = t;
	int l = 1, r = 1, i;
	while (l <= r){
		int x = q[l];
		l++;
		if (vis[x])continue;
		if (!flag) {
			printf("%d", x); 
			flag = 1;
		}
		else printf(" %d", x);

		vis[x] = 1;
		for (i = 1; i <= n; i++) {
			if (a[x][i]) {
				if (!vis[i]) {
					q[++r] = i;
				}
			}
		}
	}
	memset(vis, 0, sizeof(vis));
}
int main(){
	int i;
	int x,y;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= m; i++){
		scanf("%d%d", &x, &y);
		a[x][y] = 1;
		a[y][x] = 1;
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

