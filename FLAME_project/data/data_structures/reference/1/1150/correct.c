#include<stdio.h>
int vis[10002], q[1001], n;
void dfs(int x) {
	if(x > n) {
		int i;
		for(i = 1; i <= n; ++ i)
			printf("%d ", q[i]);
		printf("\n");
		return ;
	}
	int i;
	for(i = 1; i <= n; ++ i)
		if(!vis[i])
		q[x] = i, vis[i] = 1, dfs(x + 1), vis[i] = 0;
}
int main() {
	scanf("%d", &n);
	dfs(1);
}

