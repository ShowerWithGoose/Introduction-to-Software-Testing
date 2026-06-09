#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define MAXSIZE 105
int stack[MAXSIZE];
int top=-1;

void push(int stack[],int num);
int pop(int stack[]);
int isFul();
int isEmpty();

int main(){
	int dec,num;
	while(1){
		scanf("%d",&dec);
		if(dec==-1)break;
		if(dec==1){
			scanf("%d",&num);
			push(stack,num);
		}
		else if(dec==0)pop(stack);
	}
	return 0;
}

void push(int stack[],int num){
	if(isFul()){
		printf("error ");
	}
	else{
		stack[++top]=num;
	}
}

int pop(int stack[]){
	if(isEmpty()){
		printf("error ");

	}
	else{
		printf("%d ",stack[top--]);
	}		
	return 0;
} 
int isFul(){
	return (top==MAXSIZE-1);
}

int isEmpty(){
	return (top==-1);
}


