#include <stdio.h>

int book[12], num[12];

void solve(int n, int step) {
	
	if (n + 1 == step) {
		for (int i = 1; i <= n; i++) 
			printf("%d ", num[i]);
			puts("");
		return;
	}
	
	for (int i = 1; i <= n; i++) {
		if (!book[i]) {
			num[step] = i;
			book[i] = 1;
			solve(n, step + 1);
			book[i] = 0;
		}
	}
	
}

int main() {
	int N;
	scanf("%d", &N);
	solve(N, 1);
	return 0;
}



