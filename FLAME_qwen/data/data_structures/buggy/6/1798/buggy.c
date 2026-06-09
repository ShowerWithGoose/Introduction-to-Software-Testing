#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef struct {
	int data[MAX_SIZE];
	int top;
} stack;

void init(stack *stack) {
	stack->top = 0;
}

void push(stack *stack, int value) {
	stack->data[++stack->top] = value;
}

int pop(stack *stack) {
	return stack->data[stack->top--];
}

int main() {
	int n, m;
	stack sta;
	while (~scanf("%d", &n)) {
		if (n == 1) {
			if (sta.top == MAX_SIZE)
				printf("error ");
			else {
				scanf("%d", &m);
				sta.data[sta.top ] = m;
				sta.top++;
			}
		}
		if (n == 0) {
			if (sta.top == 0)
				printf("error ");
			else {
				printf("%d", sta.data [sta.top - 1]);
				sta.top--;
			}
		} else
			break;
	}
	return 0;
}
