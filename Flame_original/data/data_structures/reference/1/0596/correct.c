#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int list[12], flag[12];

int main() {
	int n;
	scanf("%d", &n);
	func(0, n);
	return 0; 
}

void func(int m, int n) {
	int i;
	if (m == n) {
		for (i = 0; i < n; i++) 
			printf("%d ", list[i]);
		printf("\n");
	}
	else {
		for (i = 1; i <= n; i++) {
			if (!flag[i]) {
				list[m] = i;
				flag[i] = 1;
				func(m + 1, n);
				flag[i] = 0;
			}
		}
	}
}

