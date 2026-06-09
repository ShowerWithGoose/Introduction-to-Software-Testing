#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define N 100
int top=-1;
int isempty()
{
	return top==-1;
}
int isfull()
{
	return top==N-1;
}
void error(char *a)
{
	printf("%s ",a);
}
void push(int s[],int e)
{
	if(isfull())
	error("error");
	else
	s[++top]=e;	
}
void pop(int s[])
{
	if(isempty())
	{
		error("error");
	}
	else
	printf("%d ",s[top--]);
}


int main()
{
	int op;
	int num;
	int s[N];//Õ» 
	while(scanf("%d",&op)!=EOF)
	{
		if(op==-1)
		return 0;
		if(op==1)
		{
			scanf("%d",&num);
			push(s,num);
		}
		else if(op==0)
		{
			pop(s);
		}
	}
	return 0;
}


