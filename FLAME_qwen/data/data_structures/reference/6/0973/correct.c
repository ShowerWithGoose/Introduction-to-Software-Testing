#include <stdio.h>
#include <stdlib.h>

int main() {
	int top = 0, stack[100] = {};
	int op;
	while (scanf("%d", &op)) {
		if (op == -1)
			break;
		else if (op == 1) {
			if (top < 100)
				scanf("%d", &stack[top++]);
			else
				printf("error ");

		} else if (op == 0) {
			if (top > 0) {
				top--;
				printf("%d ", stack[top]);
			} else
				printf("error ");

		}
	}
	return 0;
}
