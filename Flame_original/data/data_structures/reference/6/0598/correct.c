#include <stdio.h>

int main() {
	int stack[100];
	int top = 0;

	int op;
	int num;
	int loop = 1;
	while (loop) {
		scanf("%d", &op);
		switch (op)
		{
		case 1:
			scanf("%d", &num);
			if (top == 100) {
				printf("error ");
				break;
			}
			stack[top++] = num;
			break;
		case 0:
			if (!top) {
				printf("error ");
				break;
			}
			num = stack[--top];
			printf("%d ", num);
			break;
		case -1:
			loop = 0;
			break;
		}
	}
	return 0;
}
