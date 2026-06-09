#include<stdio.h>
#include <malloc.h>
#include <string.h>
struct Stack
{
	int top;
	int item[10000];
};
int full(struct Stack* p)
{
	if(p->top==999) return 1;
	else return 0;
};
void push(struct Stack* p,int n)
{
	p->top++;
	p->item[p->top]=n;
	return;
}
int empty(struct Stack* p)
{
	if(p->top==-1) return 1;
	else return 0;
}
void pop(struct Stack* p)
{
	printf("%d ",p->item[p->top]);
	p->top--;
	return ;
}
int main()
{
	struct Stack* stack;
	stack=(struct Stack*)malloc(sizeof(struct Stack));
	stack->top=-1;
	int op;
	int num;
	while(1)
	{
		scanf("%d",&op);
		if(op==-1) break;
		else if(op==1)
		{   scanf("%d",&num);
		if(full(stack)) printf("error ");
		else	push(stack,num);
		}
		else if(op==0)
		{
			if(empty(stack)) printf("error ");
			else pop(stack);
		}
	}
	return 0;
}

