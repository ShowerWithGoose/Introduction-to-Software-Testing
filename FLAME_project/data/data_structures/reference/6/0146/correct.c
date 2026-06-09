#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

int top=-1;
int empty()
{
	return top==-1;
}
int full()
{
	return top==99;
}
void push(int e[],int item)
{
	if(full())
	{
		printf("error ");
	}
	else
	{
		e[++top]=item;
	}
}
int pop(int e[])
{
	if(empty())
	{
		printf("error ");
		return 0;
	}
	else
	{
		return e[top--];
	}
}

int main()
{
	int elem[100];
	int order;
	int i;
	int n;
	while(1)
	{
		scanf("%d",&order);
		if(order==-1)
		break;
		else if(order==1)
		{
			scanf("%d",&i);
			push(elem,i);
		}
		else if(order==0)
		{
			n=pop(elem);
			if(n!=0)
			printf("%d ",n);
		}
	}
	return 0;
}

