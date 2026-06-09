#include <stdio.h>
int STACK[100];
int Top = -1;

void push(int *s, int a) {
	s[++Top] = a;
}

void pop(int *s) {
	if (Top == -1) {
		printf("error ");
	} else {
		printf("%d ", s[Top--]);
	}
}

int main(void) {
	int data, sign;
	while (1) {
		scanf("%d", &sign);
		if (sign == 1) {
			scanf("%d", &data);
			push(STACK, data);
		}
		if (sign == 0) {
			pop(STACK);
		}
		if (sign == -1) {
			return 0;
		}
	}
}
