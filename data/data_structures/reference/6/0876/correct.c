#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define MAXSIZE 100

int stack[MAXSIZE];
int top=-1;

int push(int);
int pop();

int main()
{
	int i, j, k;
	int op, item;
	while(scanf("%d",&op)!=EOF){
		if( op == 1){
			scanf("%d",&item);
			push(item);
		}
		else if(op == 0){
			if(top!=-1)
				printf("%d ",pop());
			else
				printf("error ");
		}
		else if(op == -1){
			return 0;
		}
	}
}

int push(int item){
	if(top == MAXSIZE-1){
		printf("error ");
		return 0;
	}
	stack[++top] = item;
	return 0;
}
int pop(){
	if(top == -1){
		printf("error ");
	}
	int item = stack[top];
	stack[top--] = 0;
	return item;
}

