#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<malloc.h>
#define MAXSIZE 100


int stack[MAXSIZE];
int Top=-1;
int isEmpty();
int isfull();
void push(int item);
void pop();
int main()
{
	int op,item;
	while(~scanf("%d",&op))
	{
		if(op==1)
		{
			scanf("%d",&item);
			push(item);
		}
		else if(op==0)
		{
			pop();
		}
		else
			return 0;
	}
	
	
}
int isEmpty()
{
	if(Top==-1)
		return 1;
	else
		return 0;
}
int isfull()
{
	if(Top==MAXSIZE-1)
		return 1;
	else
		return 0;
}
void push(int item)
{
	if(isfull())
		printf("error ");
	else
		stack[++Top]=item;
		
}
void pop()
{
	if(isEmpty())
		printf("error ");
	else
		printf("%d ",stack[Top--]);
}


