#include <stdio.h>
#include <stdlib.h>
#define N 100

int top = -1;
int stack[N];

void push(int n) {
	if (top == N - 1)
		printf("error ");
	else 
		stack[++top] = n;
}

void pop() {
	if (top == -1)
		printf("error ");
	else 
		printf("%d ", stack[top--]);
}

int main() {
	int op, num;
	while (op != -1) {
		scanf("%d", &op);
		switch (op) {
			case 1:
				scanf("%d", &num);
				push(num);
				break;
			case 0:
				pop();
				break;
			default:
				break;
		}
	}
	return 0;
}



