#include <stdio.h>
int stack[100];
int top=-1;
int isempty()
{
	return top==-1;
}
int isfull()
{
	return top==99;
}
void push(int item)
{
	if(isfull())
	{
		printf("error ");
		return;
	}
	else
	{
		top++;
		stack[top]=item;
	}
}
void pop()
{
	int item;
	if(isempty())
	{
		printf("error ");
		return;
	}
	else 
	{
		printf("%d ",stack[top]);
		top--;
		
	}
}
int main()
{
	int n;
	int item;
	scanf("%d",&n);
	while(n!=-1)
	{
		if(n==1)
		{
			scanf("%d",&item);
			push(item);
		}
		if(n==0)
		{
		    pop();
		}
		scanf("%d",&n);
	}
	return 0;
}

