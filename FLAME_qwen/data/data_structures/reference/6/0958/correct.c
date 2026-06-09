#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int stack[100],top=-1;
void Push(int n);
void Pop();
int main()
{
	int op;
	scanf("%d",&op);
	while(op!=-1)
	{
		switch(op)
		{
			case 1: scanf("%d",&op);Push(op);break;
			case 0: Pop();break;
		}
		scanf("%d",&op);
	}
	return 0;
}
void Push(int n)
{
	if(top==99)
	{
		printf("error ");
	}
	else
	{
		stack[++top]=n;
	}
}
void Pop()
{
	if(top==-1)
	{
		printf("error ");
	}
	else
	{
		printf("%d ",stack[top--]);
	}
}

