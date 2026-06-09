#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#include<malloc.h>
#define ll long long
#define Maxsize 100
int stack[Maxsize];
int top=-1; 
int isFull()
{
	return top==Maxsize-1;
}
int isEmpty()
{
	return top==-1;

}
void push(int data)
{
	if(isFull())
	{
		printf("error ");
		return;
	}
	else
	{
		stack[++top]=data;
		return;
	}
}
void pop()
{
	if(isEmpty())
	{
		printf("error ");
		return;
	}
	else
	{
		printf("%d ",stack[top--]);
		return;
	}
}
int main()
{
	int flag,item;
	while(scanf("%d ",&flag)!=EOF)
	{
	
		if(flag==1)
		{
			scanf("%d ",&item);
			push(item); 
		}
		else if(flag==0)
		{
			pop();
		}
		else
		{
			break;
		}
	}
	

 

	return 0;
}


