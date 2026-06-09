#include <stdio.h>
#include <string.h>
int a[12];
int b[12];
int n;

void fullpermentation(int step) {
	if (step == n) {
		for (int i = 0; i < n; i++) {
			printf("%d ", b[i]);
		}
		putchar('\n');
	}

	else {
		for (int i = 0; i < n; i++) {
			if (a[i] == 0) {
				b[step] = i + 1;
				a[i] = 1;
				fullpermentation(step + 1);
				a[i] = 0;
			}
		}
	}
}

int main() {
	scanf("%d", &n);
	fullpermentation(0);
}


