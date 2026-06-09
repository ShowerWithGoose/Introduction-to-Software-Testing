#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#define MAX 100
int stack[MAX],pop[MAX];
int main() {
	int top = -1, item, op, cnt = 0;
	while (scanf("%d", &op) != EOF) {
		switch (op) {
		case 1:
			if (top == MAX - 1) {
				printf("error ");
			}
			else {
				scanf("%d", &item);
				stack[++top] = item;
			}
			break;
		case 0:
			if (top == -1) {
				printf("error ");
			}
			else {
				printf("%d ", stack[top--]);
			}
			break;
		case -1:
			return 0;
			break;
		default:
			break;
		}
	}
	return 0;
}

