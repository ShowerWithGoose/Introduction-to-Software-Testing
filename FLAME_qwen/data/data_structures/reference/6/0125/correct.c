#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define MAXSIZE 100

typedef struct {
	int data[MAXSIZE];
	int top;
} stack;

stack zhai;
int op, num;

bool push(stack *s, int x);
bool pop(stack *s);

int main() {
	zhai.top = -1;
	scanf("%d", &op);
	while (op != -1) {
		if (op == 1) {
			scanf("%d", &num);
			push(&zhai, num);
		} else if (op == 0) {
			pop(&zhai);
		}
		scanf("%d", &op);
	}
	return 0;
}

bool push(stack *s, int x) {
	if (s->top == MAXSIZE - 1) {
		printf("error ");
		return true;
	}
	s->data[++s->top] = x;
	return true;
}

bool pop(stack *s) {
	if (s->top == -1) {
		printf("error ");
		return true;
	}
	printf("%d ", s->data[s->top]);
	s->top--;
	return true;
}
