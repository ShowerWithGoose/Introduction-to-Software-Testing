#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 10
int STACK[MAX];
int top=-1; 
int empty();
int full();
void push(int a[],int b);
int out(int a[]);
int main()
{
	int a,b;
	while(scanf("%d",&a)!=-1)
	{
		if(a==1)
		{
			scanf(" %d ",&b);
			if(full())
			printf("error ");
			else
			push(STACK,b);
		}
		else
		{
			if(a==0)
			{
				if(empty())
				printf("error ");
				else
				printf("%d ",out(STACK));
			}
		}
	}
	
	
	return 0;
 } 
int empty()
{
	return top==-1;
}
int full()
{
	return top==MAX-1;
}
void push(int a[],int b)
{
   a[++top]=b;
   	
}
int out(int a[])
{
	return a[top--];
}

