#include <stdio.h>
#include <string.h>
int book[11];
int a[11];
int n;

void dfs(int step) {
	int i;
	if (step == n + 1) {
		for (int i = 1; i <= n; i++) {
			printf("%d ", a[i]);
		}
		printf("\n");
		return;
	}
	for (i = 1; i <= n; i++) {
		if (book[i] == 0) {
			a[step] = i;
			book[i] = 1;
			dfs(step + 1);
			book[i] = 0;
		}
	}
	return;
}

int main() {
	scanf("%d", &n);
	dfs(1);
	return 0;
}
