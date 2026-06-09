#include<stdio.h>
#include<stdlib.h>
int a[101], top;
int op, x;
int main()
{
	while (scanf("%d", &op) != EOF && op!=-1) {
		if (op == 1) {
			scanf("%d", &x);
			if (top >= 100) printf("error ");
			else a[++top] = x;
		}
		else {
			if (!top) printf("error ");
			else printf("%d ", a[top--]);
		}
	}
	return 0;
} 

