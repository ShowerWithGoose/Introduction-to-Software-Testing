#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 100
int stack[MAXSIZE];
int top=-1;
int isEmpty()
{
	return top==-1;
}
int isFull()
{
	return top==MAXSIZE-1;
}
void push(int s[],int item)
{
	if(isFull())
	{
		printf("error ");
	}
	else s[++top]=item;
}
void pop(int s[])
{
	if(isEmpty())
	{
		printf("error ");
	}
	else printf("%d ",s[top--]);
}
int main()
{
	int op,num,item;
	while(scanf("%d",&op)!=-1)
	{
		if(op==-1)break;
		else if(op==1)
		{
			scanf("%d",&item);
			push(stack,item);
		}
		else pop(stack);		
	}
	return 0;
}


