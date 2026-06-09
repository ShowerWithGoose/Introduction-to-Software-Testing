#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX_SIZE 100

int stack[MAX_SIZE] = {0};
int Top = -1;

void push(int a){
	if(Top == MAX_SIZE-1){
		printf("The stack is full!");
		exit(1);
	}
	else stack[++Top] = a;	
}

void pop(void ){
	if(Top == -1)
		printf("error ");
	else printf("%d ",stack[Top--]);
}

int main(){
	int op,num;
	while(scanf("%d",&op) && op != -1){
		switch (op){
			case 1:
				scanf("%d",&num);
				push(num);
				break;
			case 0:
				pop();
				break;
			default:break;
		}
	}
	return 0;
}

