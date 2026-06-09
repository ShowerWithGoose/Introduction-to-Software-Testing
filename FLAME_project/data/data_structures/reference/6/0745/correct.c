#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#define M 1000005
#define ll long long
#define ull unsigned long long
int top;
const int MAXSTUCK=100;
int stack[100];
void initStack()
{
	top=-1;
}
int isFull(int s[])
{
	return top==MAXSTUCK;
}
int isEmpty(int s[])
{
	return top==-1;
}
void push(int s[],int a)
{
	if(isFull(s)==1)
		printf("Full Stack!");
	else 
	{
		s[++top]=a;
	}
 } 
void pop(int s[])
{
	if(isEmpty(s)==1)
		printf("error ");
	else
	{
		top--;
	}
}

int getTop(int s[])
{
	return s[top];
}
int main()
{
	initStack();
	int i=0;int n,op=0;
	while(1)
	{
		scanf("%d",&op);
		if(op==-1) break;
		if(op==1)
		{
			scanf("%d",&n);
			push(stack,n);
		}
		if(op==0)
		{
			if(isEmpty(stack)!=1)
				printf("%d ",getTop(stack));
			pop(stack);
		}
	}
//	while(isEmpty(stack)!=-1)
//	{
//		printf("%d",getTop(stack));
//	}
	return 0;
}



