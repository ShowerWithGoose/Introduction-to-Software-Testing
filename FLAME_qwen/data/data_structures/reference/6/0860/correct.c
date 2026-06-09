#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Stack {
	int *base;
	int *top;
	int Maxsize;
} Stack1;

int main() {
	Stack1.Maxsize = 100;
	Stack1.base = (int *)malloc(100 * sizeof(int));
	Stack1.top = Stack1.base;
	int act, num;
	while (scanf("%d", &act) && act != -1) {
		if (act == 1) {
			scanf("%d", &num);
			if (Stack1.top - Stack1.base == 100) {
				printf("error ");
			} else {
				*(Stack1.top) = num;
				Stack1.top++;
			}
		} else {
			if (Stack1.top - Stack1.base == 0) {
				printf("error ");
			} else {
				printf("%d ", *(--Stack1.top));
			}
		}
	}
	return 0;
}
