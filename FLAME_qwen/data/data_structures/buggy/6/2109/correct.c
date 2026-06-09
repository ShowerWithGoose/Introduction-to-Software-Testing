#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
int stack[MAXSIZE];
int top=-1;
void initstack();
int isempty();
int isfull();
void push(int stack[],int a);
void pop(int stack[]);
void error(char s[]);
int main()
{
	int op,a;
	scanf("%d",&op);
	while(op != -1){
		if(op == 1){
			scanf("%d %d",&a,&op);
			push(stack,a);
		}
		else{
			scanf("%d",&op);
			pop(stack);
		}
	}
	return 0;
}

void initstack(){
	top = -1;
}

int isempty(){
	return top == -1;
}

int isfull(){
	return top == MAXSIZE - 1;
}

void push(int stack[],int a){
	if(isfull()){
		printf("error ");
	}
	else{
		stack[++top] = a;
	}
}

void pop(int stack[]){
	if(isempty()){
		printf("error ");
	}
	else{
		printf("%d ",stack[top--]);
	}
}

void error(char s[]){
	printf("%s",s);
}

