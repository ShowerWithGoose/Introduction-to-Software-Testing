#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define MaxSize 1000
int Top=-1;
int STACK[MaxSize];
void Push(int s[],int m)
{
	if(Top==MaxSize-1)
	{
		printf("error ");
	}
	else
	{
		s[++Top]=m;
	}
}
void Pop(int s[])
{
	if(Top==-1)
	{
		printf("error ");
	}
	else
	{
		printf("%d ",s[Top--]);
	}
}

int main()
{
	while(1)
	{
		int n;
		scanf("%d",&n);
		if(n==1)
		{
			int m;
			scanf("%d",&m);
			Push(STACK,m);
		}
		else if(n==0)
		{
			Pop(STACK);
		}
		else if(n==-1) break;
	}
	return 0;
} 

