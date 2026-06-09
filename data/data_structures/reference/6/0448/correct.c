#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
int stack[MAXSIZE],top;
int main()
{
	int op,num;
	initStack();
	while(scanf("%d",&op)!=EOF)	
	{
		if(op==1)
		{
			scanf("%d",&num);
			push(stack,num);
		}
		else if(op==0)
		{
			pop(stack);
			printf(" ");
		}
		else if(op==-1)
		{
			goto out;
		}
	}
	out:
		return 0;
} 
void initStack()
{
	top=-1;
}
int isEmpty()
{
	return top==-1;
}
int isFull()
{
	return top==MAXSIZE-1;
}
void push(int stack[],int item)
{
	if(isFull())
	{
		printf("error");
	}
	else
	{
		stack[++top]=item;
	}
}
int pop(int stack[])
{
	if(isEmpty())
	{
		printf("error");
	}
	else
		printf("%d",stack[top--]);
}

