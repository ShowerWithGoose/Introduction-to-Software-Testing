#include <stdio.h>
#define MAXSIZE 100
int stack[MAXSIZE],top;

void push(int stack[],int item);
void pop(int stack[]);

int main(){
	int flag;
	while(scanf("%d",&flag)!=-1){
		if(flag==1){
			int item;
			scanf("%d",&item);
			push(stack,item);
		}
		else if(flag==0){
			pop(stack);
		}
	}
	return 0;
}

void push(int stack[],int item){
	if(top==MAXSIZE){
		printf("error ");
	}
	else{
		stack[++top]=item;
	}
}

void pop(int stack[]){
	if(top==0){
		printf("error ");
	}
	else{
		printf("%d ",stack[top]);
		top--;
	}
}

