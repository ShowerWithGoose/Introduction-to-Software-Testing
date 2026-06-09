#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxsize 100
int top;
//³õÊ¼»¯Õ»
void buildstack()
{
	top=-1;
} 
//ÅÐ¶ÏÕ»¿Õ
int isempty()
{
	if(top==-1) return 1;
	else return 0;
} 
//ÅÐ¶ÏÕ»Âú
int isfull()
{
	if(top==maxsize-1) return 1;
	else return 0;
}
//Ñ¹Õ»
void push(int stack[],int e)
{
	top++;
	stack[top]=e;
} 
//³öÕ»
int pop(int stack[])
{
	int e;
	e=stack[top];
	top--;
	return e;
}
int main()
{
	int stack[maxsize],command,num,e;
	buildstack();
	while(scanf("%d",&command)!=-1)
	{
		if(command==1)
		{
			if(isfull()==0)
			{
				scanf("%d",&num);
				push(stack,num);
			}
			else printf("error ");
		}
		if(command==0)
		{
			if(isempty()==0)
				printf("%d ",pop(stack));
			else printf("error ");
		}
	}
	return 0;
} 

