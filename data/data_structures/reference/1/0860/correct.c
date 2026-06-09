#include <stdio.h>
#include <string.h>
int vis[11];
int num[11];

void list(int m, int n) {
	int i;
	int k;
	if (m > n) {
		for (i = 1; i <= n; i++) {
			if (i < n)
				printf("%d ", num[i]);
			else
				printf("%d\n", num[i]);
		}
		return;
	}
	for (i = 1; i <= n; i++) {
		if (vis[i] == 0) {
			num[m] = i;
			vis[i] = 1;
			list(m + 1, n);
			vis[i] = 0;
		}
	}
}

int main() {
	int N;
	scanf("%d", &N);
	list(1, N);
	return 0;
}


