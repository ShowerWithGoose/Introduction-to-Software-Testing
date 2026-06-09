#include<stdio.h>
#define max 100
int STACK[max];
int  top;
void init()
{
	top=-1;
}

int isempty()
{
	return (top==-1);
}

int isfull()
{
	return (top==max-1);
}

void push(int b)
{
	if(isfull())
	{
		printf("error ");
	}
	else STACK[++top]=b;
}
void pop()
{
	if(isempty())
	{
		printf("error ");
		
	}
	else 
	{
		printf("%d ",STACK[top]);
		return STACK[top--];
	}
}
int main()
{
	int x,a;
	init();
	
	while(scanf("%d ",&x))
	{
		if(x==1)
		{
			scanf("%d ",&a);
			push(a);
		}
		else if(x==0)
		{
			pop();
		}
		else break;
	}
	return 0;
}

