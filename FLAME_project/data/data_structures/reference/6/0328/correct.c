#include <stdio.h>
#include <stdlib.h>

int top = -1;

int main() {
	int stack[100 + 5];
	int num, cat;
	while (scanf("%d", &cat) && cat != -1) {
		if (cat == 1) {
			if (top == 99)
				printf("error ");
			else {
				scanf("%d", &num);
				stack[++top] = num;
			}
		}
		if (cat == 0) {
			if (top == -1)
				printf("error ");
			else {
				printf("%d ", stack[top]);
				top--;
			}

		}
	}
	return 0;
}
