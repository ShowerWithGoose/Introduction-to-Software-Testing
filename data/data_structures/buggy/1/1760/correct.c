#include <stdio.h>

int mark[10] = {0};
char a[11];

void pl(int m, int n) {
	if (m == n) {

		for (int i = 0; a[i] != '\0'; i++) {
			if (i == 0) {
				printf("%c", a[i]);
			} else {
				printf(" ");
				printf("%c", a[i]);
			}


			if (i == n - 1) {
				printf("\n");
			}
		}
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (mark[i] == 0) {
			mark[i] = 1;
			a[m] = '0' + i;
			pl(m + 1, n);
			mark[i] = 0;
		}
	}
}

int main() {
	int n;
	scanf("%d", &n);
	pl(0, n);
	return 0;
}
