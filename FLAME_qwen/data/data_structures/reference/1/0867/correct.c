#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int hash[10] = {0};
int n;
int ans[9];
int top = 0;

void print() {
	for (int i = 0; i < n; i++) {
		printf("%d ", ans[i]);
	}
	printf("\n");
}

void f(int s) {
	if (s == n) {
		print();
	} else {
		for (int i = 1; i <= n; i++) {
			if (!hash[i]) {
				hash[i] = 1;
				ans[s] = i;
				f(s + 1);
				hash[i] = 0;
			}
		}
	}
}

int main() {
	scanf("%d", &n);
	f(0);
}


