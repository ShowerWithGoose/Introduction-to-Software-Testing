#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int stack[100],Top=-1;
int isEmpty();
int isFull();
void push(int num);
int pop();

int main (){
	int op,num;
	while(1){
		scanf("%d",&op);
		if(op==-1) break;
		else if(op==1){
			if(isFull()){
				printf("error ");
			}
			else {
				scanf("%d",&num);
				push(num);
			}
		}
		else if(op==0){
			if(isEmpty()){
				printf("error ");
			}
			else {
				pop();
			}
		}
	}
}

int isEmpty(){
	return Top==-1;
}

int isFull(){
	return Top==100;
}

void push(int num){
	stack[++Top]=num;
}

int pop(){
	printf("%d ",stack[Top--]);
}


