#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 1000
int stack[MAXSIZE];
int top;
void initstack()
{
	top=-1;
}
int isempty()
{
	return top==-1;
}
int isfull()
{
	return top==MAXSIZE-1;
}
void push(int s[],int a)
{
	if(isfull())
		printf("error ");
	else
		s[++top]=a;
}
int pop(int s[])
{
	if(isempty())
		printf("error ");
	else
	{
		printf("%d ",s[top]);
		return s[top--];
	}
}
int main()
{
	initstack();
	int i=0,a=0;
	int order[1000]={0};
	while(1)
	{
		scanf("%d",&order[i]);
		if(order[i]==-1)
		{
			break;
		}
		i++;
	}
	for(a=0;a<i;a++)
	{
		if(order[a]==0)
			pop(stack);
		else if(order[a]==1)
			push(stack,order[a+1]);
	}
	return 0; 
}

