
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int st[200];
int top = -1;

int pus(int a) {
	if (top == 99) {
		printf("error ");
		return 1;
	}
	st[++top] = a;
	return 0;
}

int pop() {
	if (top == -1) {
		printf("error ");
		return 1;
	}
	printf("%d ", st[top]);
	top--;
	return 0;
}

int main() {
	int i = 1, a;
	while (i != -1) {
		scanf("%d", &i);
		if (i == 1) {
			scanf("%d", &a);
			pus(a);
		} else if (i == 0)
			pop();
	}

	return 0;
}

