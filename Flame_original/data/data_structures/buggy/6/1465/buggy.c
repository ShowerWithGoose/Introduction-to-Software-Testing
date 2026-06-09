#include<stdio.h>
void pop(int A[]);
void push(int A[],int a);
int Stack[100];
int top = -1;
int main()
{
	while(1)
	{
	int n;
	scanf("&d",&n);
	printf("%d ",n);
		/*int a,n;
		scanf("%d",&n);
		if(n==1)
		{
			scanf("%d",&a);
			push(Stack,a);
		}
		else if(n==0)
		{
			pop(Stack);
		}
		else */if(n==-1)
		{
			break;
		}
	}
	return 0;
}

void pop(int A[])
{
	if(top==-1)
	{
		printf("error ");
	}
	printf("%d ",Stack[top--]);
}

void push(int A[],int a)
{
	if(top==99)
	{
		printf("error ");
	}
	Stack[++top]=a;
}

