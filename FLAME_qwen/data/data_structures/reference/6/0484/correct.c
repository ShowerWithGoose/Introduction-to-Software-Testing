#include<stdio.h>
#define Maxsize 100
int top=-1;
int a[Maxsize];
void push(int num);
void pop();
int main()
{
	int op;
	char c;
	int num;
	while(1)
	{
		scanf("%d",&op);
		if(op==-1)
		{
			break;
		}
		else if(op==1)
		{
			scanf(" %d",&num);
			c=getchar();
			push(num);
		}
		else if(op==0)
		{
			c=getchar();
			pop();
		}
	}
	return 0; 
}
void push(int num)
{
	if(top==Maxsize-1)
	{
		printf("error ");
		return;
	}
	a[++top]=num;
}
void pop()
{
	int num;
	if(top==-1)
	{
		printf("error ");
		return;
	}
	num=a[top--];
	printf("%d ",num);
}


