#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
int stack[MAXSIZE],top;
int main()
{
	int flag,num;
	initStack();
	while(scanf("%d",&flag)!=EOF)	
	{
		if(flag==1)
		{
			scanf("%d",&num);
			push(stack,num);
		}
		else if(flag==0)
		{
			pop(stack);
			printf(" ");
		}
		else if(flag==-1)
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

