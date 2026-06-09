#include<stdio.h>
#include<stdlib.h>
#define max 100

struct setstack{
	int data[max];
	int top;
};
typedef struct setstack stack;
//栈的操作
void initial(stack*a)//初始化一个栈 
{a->top=-1;}
int isempty(stack*a)//判断栈是否为空 
{return a->top==-1;}
int isfull(stack*a)//判断栈是否为满
{return a->top==max-1;}
int push(stack*a,int pushdata)//插入一个元素 
{
	a->data[++a->top]=pushdata;
	return 1;
}
int pop(stack*a)//弹出一个元素 
{
	int i;
	i=a->data[a->top--];
	return i;
}
 
 
int main()
{
	stack stk;
	initial(&stk);
	int j,n;
	while(scanf("%d",&j)!=EOF)
	{
		if(j==-1) break;
		if(j==1)
		{
			scanf("%d",&n);
			if(isfull(&stk)) printf("error ");
			else push(&stk,n);
		}
		if(j==0)
		{
			if(isempty(&stk)) printf("error ");
			else printf("%d ",pop(&stk));
		}
	}
	return 0;
}



