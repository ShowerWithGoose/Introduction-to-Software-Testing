#include <stdio.h>
int stack[100]={0};
int top=-1;
int i=0;
void push(int s[],int item);
void pop(int s[]);
int main()
{
	int op;
	while(scanf("%d",&op)!=-1)
	{
		if(op==1)
		{
			int in;
			scanf("%d",&in);
			push(stack,in);
		}
		else if(op==0)
		{
			pop(stack);
		}
	}
	return 0;
} 
void push(int s[],int item)
{
	if(top==99)
	{
		printf("error ");
	}
	else s[++top]=item;
}
void pop(int s[])
{
	if(top==-1)
	{
		printf("error ");
	}
	else printf("%d ",s[top--]);
}

