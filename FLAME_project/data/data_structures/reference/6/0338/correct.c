#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
int STACK[MAXSIZE];
int top=-1;

int isempty()
{
	return (top==-1);
}

int isfull()
{
	return (top==MAXSIZE-1);
}

void push(int s[],int item)
{
	if(isfull())
		printf("error ");
	else
		s[++top]=item;
}

int pop(int s[])
{
		return s[top--];
}



int main()
{
	int m,n;
	while(~scanf("%d",&m))
	{
		if(m==1)
		{	
			scanf("%d",&n);
			push(STACK,n);
		}
		else if(m==0)
		{
			if(isempty())
			
				printf("error ");
			
			else
				printf("%d ",pop(STACK));
		}
		else if(m==-1)
		return 0;
	}
}

