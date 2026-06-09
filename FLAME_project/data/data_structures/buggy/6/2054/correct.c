#include<stdio.h>
int top=-1;
int stack[200]={0};

int isEmpty(int s[])
{
	return top==-1;
}

int isFull(int s[])
{
	return top==199;
}
void haha11(char s[])
{
	printf("%s ",s);
}
void push(int stack[],int item)
{
	if(isFull(stack))
	{
		printf("error ");
	}
	else 
		stack[++top]=item;
}

int pop(int s[])
{
	if(isEmpty(s))
		{
			printf("error ");
		}
	else 
		return s[top--];
}
int main()
{
	int a,b,ans;
	while(~scanf("%d",&a))
	{
		if(a==-1)
		{
			break;
		}
		else if(a==1)
		{
			scanf("%d",&b);
			push(stack,b);
		}
		else if(a==0)
		{
			if(isEmpty(stack))
				printf("error ");
			else
				printf("%d ",ans=pop(stack));
		}
	}
}

