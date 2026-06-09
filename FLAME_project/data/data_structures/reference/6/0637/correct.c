#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
int stack[110];//整数栈
int main(){
	int op, num, top = 0, i;
	scanf("%d", &op);
	while (op != -1){
		if (op == 1){//入栈
			scanf("%d", &num);
			if (top == 99){//说明栈已经满了
				printf("error ");
			}
			else  stack[++top] = num;
		}
		else{//op == 0 出栈
			if (top == 0){//说明栈空了
				printf("error ");
			}
			else {
				printf("%d ", stack[top]);
				top--;
			}
		}
		scanf("%d", &op);
	}
	return 0;
}
