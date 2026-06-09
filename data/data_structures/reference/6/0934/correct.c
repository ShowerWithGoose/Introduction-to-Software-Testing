#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include<string.h>
int top = 0,op,num,stack[105],rec[105],recnum=0;
int main() {
	while (1) {
		scanf("%d", &op);
		if (op == -1)break;
		else if (op == 0) {
			if (top == 0)rec[recnum++] = -1;
			else {
				rec[recnum++] = stack[top];
				stack[top--] = 0;
			}
		}
		else {
			scanf("%d", &num);
			if (top == 100)rec[recnum++] = -1;
			else stack[++top] = num;
		}
	}
	for (int i = 0; i < recnum; i++) {
		if (rec[i] == -1)printf("error ");
		else printf("%d ", rec[i]);
	}
	return 0;
}

