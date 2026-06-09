#include <stdio.h>
int n, k, j;
int vis[100];
int gg[100];

void dfs(int x, int num) {
	int o;
	if (x == n + 1) {
		while (num != 0) {
			gg[k] = num % 10;
			num /= 10;
			k++;
		}
		for (j = k - 1; j >= 0; j--) {
			printf("%d ", gg[j]);
		}
		k = 0;
		printf("\b");
		printf("\n");
		return;
	}
	for (o = 1; o <= n; o++) {
		if (vis[o] == 0) {
			vis[o] = 1;
			dfs(x + 1, num * 10 + o);
			vis[o] = 0;
		}
	}
}

int main() {
	scanf("%d", &n);
	dfs(1, 0);
	return 0;
}


