#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define MAXSIZE 102
typedef int Elem;
typedef struct stack{
	Elem data[MAXSIZE];
	int top;
}stack;
stack s;
void  initStack(stack *s){//初始化栈 
	s->top=-1;
}
int isEmpty(stack *s){//检验是否为空 
	return s->top==-1;
}
int isFull(stack *s){//检验是否为满 
	s->top==MAXSIZE-1;
}
int push(stack *s,int n){//进栈 
	if(isFull(s)==1){
		printf("error ");
		}
	s->top++;
	s->data[s->top]=n;		
}
void pop(stack s[],int n){
	if(isEmpty(s)==1){
		printf("error ");
	}
	else{
		n=s->data[s->top];
		s->top--;
		printf("%d ",n);
	}
}

int main(){
	
	initStack(&s);
	int op,num;
	while(1){
		scanf("%d",&op);
		if(op==-1)
		break;
		else if(op==1){
			scanf("%d",&num);
			push(&s,num);
		}
		else if(op==0){
			pop(&s,num);
		}
	}
	return 0; 
} 

