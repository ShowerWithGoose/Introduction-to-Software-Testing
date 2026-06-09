#include <stdio.h>

int stack[105];
int top=-1;

void push(int n);
void pop();

int main()
{
	int n;
	scanf("%d",&n);
	while(~n)
	{
		if(n==1)
		{
			scanf("%d",&n);
			push(n);
		}
		
		else pop();
			
		scanf("%d",&n);
	}
	
	return 0;
}

void push(int n)
{
	if(top==99)
	{
		printf("error ");
		return;
	}
	
	stack[++top]=n;
	return;
}

void pop()
{
	if(top==-1)
	{
		printf("error ");
		return;
	}
	
	printf("%d ",stack[top--]);
	return;
}

