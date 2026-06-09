#include<stdio.h>
#define N 4002
int n, m, del;
int G[N][N], vis[N], q[N];
void dfs(int x) {
	int i;
	printf("%d ", x), vis[x] = 1;
	for(i = 0; i <= n; ++ i) {
		if(vis[i] || !G[x][i]) continue;
		dfs(i);
	}
	return ;
}
void bfs(int x) {
	int i, l = 1, r = 0;
	q[++ r] = x, vis[x] = 1;
	while(l <= r) {
		x = q[l ++], printf("%d ", x);
		for(i = 0; i <= n; ++ i) {
			if(vis[i] || !G[x][i]) continue;
			vis[i] = 1, q[++ r] = i; 
		}
	}
}
int main() {
	int i, x, v;
	scanf("%d%d", &n, &m);
	for(i = 1; i <= m; ++ i)
		scanf("%d%d", &x, &v), G[x][v] = G[v][x] = 1;
	scanf("%d", &del);
	dfs(0), printf("\n");
	for(i = 0; i <= n; ++ i) vis[i] = 0;
	bfs(0), printf("\n");
	for(i = 0; i <= n; ++ i) vis[i] = 0;
	vis[del] = 1;
	dfs(0), printf("\n");
	for(i = 0; i <= n; ++ i) vis[i] = 0;
	vis[del] = 1;
	bfs(0), printf("\n");

}

