#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define MAXSIZE 100

int top;
int stack[MAXSIZE];

void initstack()
{
	top=-1;
}

int isempty()
{
	return top==-1;
}

int isfull()
{
	return top==MAXSIZE-1;
}

void push(int s[],int item)
{
	if(isfull())
	{
		printf("error ");
	}
	else
	s[++top]=item;
}

int pop(int s[])
{
	if(isempty())
	{
		return -1; 
	}
	else
	return s[top--];
}

int main()
{
	initstack();
	
	int flag,i;
	
	while(1)
	{
		scanf("%d",&flag);
			if(flag==1)
			{
				scanf("%d",&i);
				push(stack,i);
			}
			if(flag==0)
			{
				if(top!=-1)
				{
					printf("%d ",pop(stack));
				}
				else
				printf("error ");
			}
			if(flag==-1)
			break;
	}
	return 0;
}

