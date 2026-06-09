#include <stdio.h>

int main() {
	int a[105];
	int top = -1;
	int n;
	int m;
	for (;;) {
		scanf("%d", &n);
		if (n == -1) {
			break;
		} else if (n == 1) {
			scanf("%d", &m);
			if (top == 100) {
				printf("error ");
			} else {
				a[++top] = m;
			}
		} else if (n == 0) {
			if (top == -1) {
				printf("error ");
			} else {
				printf("%d ", a[top]);
				top--;
			}
		}
	}
	return 0;
}
