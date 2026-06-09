#include <stdio.h>

int  n, a[1000], aa[1000];

void dfs(int step) {
	int i;
	if (step == n) {
		for (i = 0; i < n; i++) {
			printf("%d ", a[i]);
		}
		printf("\n");
	}
	for (i = 0; i < n; i++) {
		if (aa[i] == 0) {
			a[step] = i + 1;
			aa[i] = 1;
			dfs(step + 1);
			aa[i] = 0;
		}
	}
}

int main(void) {

	scanf("%d", &n);
	dfs(0);
	return 0;
}


