#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#define ll long long
#define ull unsigned long long
#define max 100

int stack[max];
int top=-1;

int isEmpty()
{
	return top==-1;
}

void push(int i)
{
	if(top==(max-1))
	{
		printf("error ");
	}
	else
	{
		stack[++top]=i;
	}
}

void pop()
{
	if(isEmpty())
	{
		printf("error ");
	}
	else
	{
		printf("%d ",stack[top]);
		top--;
	}
}

int main()
{
	int op,num;
	scanf("%d",&op);
	while(1)
	{
		if(op==1)
		{
			scanf("%d",&num);
			push(num);
		}
		else if(op==0)
		{
			pop();
		}
		else if(op==-1)
		{
			break;
		}
		scanf("%d",&op);
	}
	return 0;
}

