#include <stdio.h>
int i, n, pos[20], vis[20], ans[20];
void DFS(int x);
int main()
{
	scanf ("%d", &n);
	DFS(1);
	return 0; 
}
void DFS(int x) {
	if (x == n+1) {
		for (i = 1; i <=n; i++){
			printf ("%d ", pos[i]);
		}
		printf ("\n");
		return  ;
	}
	for (pos[x] = 1; pos[x] <= n; pos[x]++) {
		if (!vis[pos[x]]) {
			vis[pos[x]] = 1;
			DFS(x+1);
			vis[pos[x]] = 0;
		}
	}
	return ;
}

