#include <stdio.h>

int n, a[11] = {0}, b[11];

void DFS(int k) {
	if (k == n + 1) {
		for (int i = 1; i <= n; i++) {
			printf("%d ", b[i]);
		}
		printf("\n");
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] == 0) {
			b[k] = i;
			a[i] = 1;
			DFS(k + 1);
			a[i] = 0;
		}
	}
}

int main() {

	scanf("%d", &n);
	DFS(1);
}
