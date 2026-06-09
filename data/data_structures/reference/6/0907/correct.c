#include <stdio.h>
int op, d;
int st[105], top = -1;

int main() {
	while (scanf("%d", &op) != EOF) {
		if (op == 1) {
			scanf("%d",&d);
			if (top == 99)
				printf("error ");
			else
				st[++top] = d;
		}

		if (op == 0) {
			if (top == -1)
				printf("error ");
			else {
				printf("%d ", st[top]);
				top--;
			}
		}

		if (op == -1)
			return 0;
	}
}
