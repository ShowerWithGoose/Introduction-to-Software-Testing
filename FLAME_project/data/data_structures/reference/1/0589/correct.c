#include <stdio.h>
int n;
int a[12];
int use[12];

int dfs(int idx) {
	if (idx == n) {
		for (int i = 0; i < n; i++)
			printf("%d ", a[i]);
		puts("");
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		if (!use[i]) {
			a[idx] = i;
			use[i] = 1;
			dfs(idx + 1);
			use[i] = 0;
		}
	}
	return 0;
}

int main(void) {
	scanf("%d", &n);
	dfs(0);
	return 0;
}

