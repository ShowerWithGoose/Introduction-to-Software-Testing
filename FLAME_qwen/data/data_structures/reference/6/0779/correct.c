#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int stack[MAX];
int top = -1;

int isblank() 
{
	return top == -1;
}

int isfull() 
{
	return top == MAX - 1;
}

int pop() {
	return stack[top--];
}

void push(int a) {
	stack[++top] = a;
}

int main() {
	int op, a;
	while (scanf("%d", &op) != EOF) {
		switch (op) {
		case 1:
			scanf("%d", &a);
			if (isfull())
				printf("error ");
			else
				push(a);
			break;
		case 0:
			if (isblank())
				printf("error ");
			else
				printf("%d ", pop());
			break;
		case -1:
			return 0;
		}
	}
	return 0;
}
