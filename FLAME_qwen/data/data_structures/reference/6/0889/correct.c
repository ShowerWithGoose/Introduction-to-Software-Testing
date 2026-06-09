#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100
int a[MAX],top=-1;
void push()
{
	int item;
	scanf("%d",&item);
	if(top==MAX-1)
	{
		printf("error ");
		return ;
	}
	else
	{
		a[++top]=item;
		return ;
	}
}

void pop()
{
	if(top==-1)
	{
		printf("error ");
		return ;
	}
	else
	{
		printf("%d ",a[top--]);
	}
}

int main()
{
	int t;
	while(1)
	{
		scanf("%d",&t);
		if(t==1)
		{
			push();
		}
		if(t==0)
		{
			pop();
		}
		if(t==-1)
		break;
	}
 	return 0;
}


