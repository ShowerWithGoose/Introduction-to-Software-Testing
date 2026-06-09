#include<stdio.h>
int a[100], flag[100];
int n;
void print() {
	for (int i = 1; i <= n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}
void dfs(int k) {
	if (k == n) {
		print();
		return;
	} else {
		for (int i = 1; i <= n; i++) {
			if (!flag[i]) {
				flag[i] = 1;
				a[k + 1] = i;
				dfs(k + 1);
				flag[i] = 0;
			}
		}
	}
}
int main() {
	scanf("%d", &n);
	dfs(0);
	return 0;
}



