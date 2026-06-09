#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
#define M 100
int top=-1;
void push(int stack[],int item);
int pop(int stack[]);

int main(int argc, char *argv[]) {
	int stack[110];
	int item,op;
	while(1){
		scanf("%d",&op);
		if(op==-1)break;
		if(op==1){
			scanf("%d",&item);
			push(stack,item);
		}
		if(op==0){
			item=pop(stack);
			if(item!=-1)printf("%d ",item);
		}
		
			
	}
		return 0;
}
void push(int stack[],int item){
	if(top==M-1)printf("error ");
	else stack[++top]=item;
	return ;
}
int pop(int stack[]){
	if(top==-1){
	printf("error ");
	return -1;
	}
	else return stack[top--];
}


