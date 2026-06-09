#include <stdio.h>
#define error printf("error ");
int Top = -1;
int s[100];

int  isEmpty() {
	return Top == -1;
}

int isFull() {
	return Top == 99;
}

void push(int item) {
	if (isFull())
		error;
	s[++Top] = item;
}

void pop() {
	if (isEmpty()) {
		error;
	} else
		printf("%d ", s[Top--]);
}

int main() {
	int op, n;
	scanf("%d", &op);
	while (op != -1) {
		if (op == 1) {
			scanf("%d", &n);
			push(n);
			scanf("%d", &op);
		}
		if (op == 0) {
			pop();
			scanf("%d", &op);
		}
	}
	return 0;
}
