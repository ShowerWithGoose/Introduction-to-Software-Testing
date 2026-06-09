#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define maxsize 100
typedef int type;

void error(char s[]){
	printf("%s ",s);
}

type stack[maxsize-1];
int top=-1;

void push(type stack[],type item){
	if(top==maxsize-1)	error("error");
	else stack[++top]=item;
}

type pop(type stack[]){
	if(top==-1) error("error");
	else{
		printf("%d ",stack[top]);
		return stack[top--];
	}
}

int main(){
	int op,item;
	scanf("%d",&op);
	while(op!=-1){
	if(op==1){
		scanf("%d",&item);
		push(stack,item);
	}
	else{
        pop(stack);
	}
	scanf("%d",&op);
	}
	return 0;
}








