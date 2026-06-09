#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include <ctype.h>
#define MAX 100

int STACK[MAX];
int top;

void initStack(){
	top=-1;
}

int isEmpty(){
	return top==-1;
}

int isFull(){
	return top==MAX-1;
}

void push(int STACK[],int s){
	if(isFull()==1){
		printf("error ");
	}
	else STACK[++top]=s;
}

int pop(int STACK[]){
	if(isEmpty()==1){
		printf("error ");
	}
	else {
		printf("%d ",STACK[top]);
		return STACK[top--];
	}
}

int main(){
	int op;
	int s;
	initStack();
	while(scanf("%d",&op)!=-1){
		if(op==1)
		{
			scanf("%d",&s);
			push(STACK,s);
		}
		else if(op==0){
			pop(STACK);
		}
	}
	return 0;
}

