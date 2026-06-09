#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int stack[MAXSIZE];

int main(int argc, char *argv[]) {
	int op, cnt;
	int top = -1;
	while((scanf("%d", &op)) != EOF){
		if(op == 1){
			scanf("%d", &cnt);
			if(top == MAXSIZE - 1){
				printf("error ");
			}
			else{
				top++;
				stack[top] = cnt;
			}
		}
		else if(op == 0){
			if(top == -1){
				printf("error ");
			}
			else{
				printf("%d ", stack[top]);
				top--;
			}
		}
		else if(op == -1){
			break;
		}
	}
	return 0;
}

