#include <stdio.h>
#include <string.h>
#define max 100
int stack[max];
int top = -1;
int isEmpty () {
	return top == -1;
}
int isFull () {
	return top == max - 1;
}
int main()
{
	int n;
	while (1) {
		scanf("%d", &n);
		if (n == 0) {
			if(isEmpty() == 0) printf("%d ", stack[top --]);
			else printf("error ");
		}
		if (n == 1) {
			if (isFull() == 0) scanf("%d", &stack[++top]);
			else printf("error ");
		}
		if (n == -1) {
			break;
		}
	}
}

