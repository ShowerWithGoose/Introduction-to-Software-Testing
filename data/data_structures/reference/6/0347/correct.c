#include<stdio.h>
#include<stdlib.h>
int stack[100];
int top;
int stackFull(int stack[],int n,int* top){
	if((*top)==n+1){
		return 1;
	}
	return 0;
}
int stackEmpty(int stack[],int n,int* top){
	if((*top)==0){
		return 1;
	}
	return 0;
}
stackPush(int stack[],int n,int* top,int num){
	stack[(*top)] = num;
	(*top)++;
}
stackPop(int stack[],int n,int* top){
	printf("%d ",stack[(*top)-1]);
	(*top)--;
}
int main() {
	int op;
	int num;
	while(1){
		scanf("%d",&op);
		if(op==-1){
			break;
		}
		if(op==1){
			if(stackFull(stack,100,&top)){
				printf("error ");
			}
			else{
				scanf("%d",&num);
				stackPush(stack,100,&top,num);
			}
		}
		if(op==0){
			if(stackEmpty(stack,100,&top)){
				printf("error ");
			}
			else{
			    stackPop(stack,100,&top);
			}
		}
	}
}

