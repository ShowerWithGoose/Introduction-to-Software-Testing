#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define MAXSIZE 100
int stack[MAXSIZE];
int top=-1;
int isempty()
{
	return top==-1;
}
int isfull()
{
	return top==MAXSIZE-1;
}
void push(int stack[],int item)
{
	if(isfull())
		printf("error ");
	else
		stack[++top]=item;	
}
void pop(int stack[])
{
	if(isempty())
		printf("error ");
	else
		printf("%d ",stack[top--]);	
}
int main()
{
	int i,flag=-1,n;
	while((scanf("%d",&i))!=-1)
	{
		if(i==1) flag=1;
		else if(i==0) flag=0;
		if(flag&&i!=0&&i!=1)
		{
			push(stack,i);
			flag=-1;
		}
		else if(flag==0)
		{
			pop(stack);
			flag=-1;
		}
	}
	return 0;
}

