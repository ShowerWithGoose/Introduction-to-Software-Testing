#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int s[100010];
int top = -1;
int op;
int num;

int main(void) {
	while (1) {
		scanf("%d", &op);
		if (op == -1)
			break;
		else if (op == 1) {
			scanf("%d", &s[++top]);
		} else if (op == 0) {
			if (top >= 0) {
				printf("%d ", s[top]);
				top--;
			} else {
				printf("error ");
			}
		}
	}
	return 0;
}

