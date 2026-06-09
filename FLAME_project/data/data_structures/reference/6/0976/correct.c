#include <stdio.h>
#include <stdlib.h>
#define MaxSize 100
int stack[MaxSize];
int top = -1;
void push_stack(int num);
void pop_stack();

int main() {
	int a, b, flag = 0;
	while (scanf("%d", &a) != EOF) {
		switch (a) {
			case 1:
				scanf("%d", &b);
				push_stack(b);
				break;
			case 0:
				pop_stack();
				break;
			case -1:
				flag = 1;
				break;
		}
		if (flag == 1)
			break;
	}
	return 0;
}

void push_stack(int num) {
	if (top == MaxSize - 1) {
		printf("error ");
	}
	stack[++top] = num;
}

void pop_stack() {
	if (top == -1) {
		printf("error ");
	} else {
		printf("%d ", stack[top--]);
	}

}
