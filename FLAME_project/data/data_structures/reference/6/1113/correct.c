#define  _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define MAX 105
int stack[MAX];
int main()
{
	int head=-1;
	int op;
	while (1) {
		scanf("%d", &op);
		if (op == -1) break;
		else if (op == 1) {
			if (head < 100) scanf("%d", &stack[++head]);
			else printf("error ");
		}
		else if (op == 0) {
			if (head >= 0) {
				printf("%d ", stack[head--]);
			}
			else printf("error ");
		}
	}
	return 0;
}
