#include<string.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define MAXSIZE 100

int STACK[MAXSIZE],Top=-1;//创建一个栈，初始化栈顶 

void push(int STACK[],int item)//进栈操作 
{
	if(Top==MAXSIZE-1)//判断是否满栈 
	{
		printf("error ");
	}
	else if(Top<MAXSIZE-1)
	{
		STACK[++Top]=item;
	}
}

void pop(int STACK[])//出栈操作 
{
	if(Top==-1)
	{
		printf("error ");
	}
	else if(Top>-1)
	{
		printf("%d ",STACK[Top--]);
	}
}

int main()
{
	int judge,item;
	while(~scanf("%d",&judge))
	{
		if(judge==-1)
		{
			break;
		}
		else if(judge==1)
		{
			scanf("%d",&item);
			push(STACK,item);
		}
		else if(judge==0)
		{
			pop(STACK);
		}
	}
	return 0;
}

