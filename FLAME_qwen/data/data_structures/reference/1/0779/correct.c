#include<stdio.h>
#pragma warning(disable:4996)

void invert(int* p1, int* p2) {
	int temp;
	for (; p1 < p2; p1++, p2--) {
		temp = *p1;
		*p1 = *p2;
		*p2 = temp;
	}
}

int main() {
	int n, a[10];
	int i, j, temp;
	scanf("%d", &n);
	for (int x = 0, y = 1; x < n; x++, y++)
		a[x] = y;
	while (1) {
		for (int x = 0; x < n; x++) {
			printf("%d ", a[x]);
		}
		printf("\n");
		for (i = n - 2; i >= 0 && a[i] > a[i + 1]; i--);
		if (i < 0)
			return 0;
		for (j = n - 1; j > 0 && a[j] < a[i]; j--);
		temp = a[i];
		a[i] = a[j];
		a[j] = temp;
		invert(&a[i + 1], &a[n - 1]);
	}
	return 0;
}
