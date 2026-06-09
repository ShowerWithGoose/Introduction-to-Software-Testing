#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int top=-1;
int s[100];
int isfull();
int isempty();
void push(int item);
void pop();
int main()
{
	int op=0;
	int item=0;
	while(~scanf("%d",&op))
	{
		if(op==1)
		{
			scanf("%d",&item);
			push(item);
		}
		else if(op==0)
		pop();
		else
		break;
	}
	return 0;
} 
int isfull()
{
	return top==99;
}
int isempty()
{
	return top==-1;
}
void push(int item)
{
	if(isfull())
	printf("error ");
	else
	{
		s[++top]=item;
	}
}
void pop()
{
	if(isempty())
	printf("error ");
	else
	{
		printf("%d ",s[top--]);
	}
}

