#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_STACK 105

int main(){
	
	int top=-1;
	int stack[MAX_STACK],num,op;
	scanf("%d",&op);
	while(op!=-1){
		switch (op){
			case 0:
				if(top<0){
					printf("error ");
				}
				else{
					num=stack[top--];
					printf("%d ",num);
				}
				scanf("%d",&op);
				break;
			case 1:
				scanf(" %d",&num);
				stack[++top]=num;
				scanf("%d",&op);
				break;

		}
	}
	return 0;
}

