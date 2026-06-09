#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define MAX 10000
int Top=-1,a[MAX];
int m,n;
void initStack()
{
	Top=-1;
}
int isEmpty()
{
	return Top==-1;
}
int isFull()
{
	return Top==MAX-1;
}
void inStack(int *t)
{
	if(Top!=MAX-1);
	Top++;
	a[Top]=*t;
}
void outStack()
{
	if(isEmpty())
	{
		printf("error ");
		return ;
	}
	else 
	{
		printf("%d ",a[Top--]);
	}
}
int main()
{
	while(scanf("%d",&m)&&m!=-1)
	{
		if(m==1)
		{
			scanf("%d",&n);
			inStack(&n);
		}
		else if(m==0)
		{
			outStack();
		}
	}
	return 0;
}

