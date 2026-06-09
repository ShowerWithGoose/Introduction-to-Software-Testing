#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
int stack[100];

int main()
{
	int op, item, top = -1;
	while (scanf("%d", &op) != EOF) {
		if (op == 1) {
			scanf("%d", &item);
			if (top == 100) {
				printf("error ");
				continue;
			}
			stack[++top] = item;
		}
		else if (op == 0) {
			if (top == -1) {
				printf("error ");
				continue;
			}
			printf("%d ", stack[top--]);
		}
		else if (op == -1) {
			break;
		}
	}
	return 0;
}
