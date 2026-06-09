#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct stack{
	int item[MAX_SIZE];
	int top;
};
typedef struct stack Stack;

void initStack(Stack* s){
	s->top=-1;
}

int isFull(Stack* s){
	return s->top==MAX_SIZE-1;
}

int isEmpty(Stack* s){
	return s->top==-1;
}

void push(Stack* s,int item){
	if(isFull(s))
	{
		printf("error ");
		return;
	}
	s->item[++s->top]=item;
}

void pop(Stack* s){
	if(isEmpty(s))
	{
		printf("error ");
		return ;
	}
	printf("%d ",s->item[s->top--]);
}

int main()
{
	Stack s;
	initStack(&s);
	
	int running=1;
	int operation;
	while(scanf("%d",&operation)==1&&running)
	{
		switch(operation)
		{
			case 1: 
			{
				int data;
				scanf("%d",&data);
				push(&s,data);
				break;
			}
			case 0:
				pop(&s);
				break;
			case -1:
				running=0;
				break;
			default:
				printf("no such operation");
		}
	}
	return 0;

}
