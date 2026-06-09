#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define M 100

int Push(int arr[],int i,int stack[],int top)
{
	if(top==99)
	{
		printf("error ");
		return top;
	}
	else
	{
		stack[++top]=arr[i+1];
		return top;
	}
}

int Pop(int stack[],int top)
{
	int item;
	if(top==-1)
	{
		printf("error ");
		return top;
	}
	else
	{
		item=stack[top--];
		printf("%d ",item);
		return top;
	}
}

int main()
{
	int arr[1031],i=0,n=0;
	int stack[M],top=-1;
	for(i=0;i>=0;i++)
	{
		scanf("%d",&arr[i]);
		n++;
		if(arr[i]==-1)
		{
			break;
		}
	}
	for(i=0;i<n-1;i++)
	{
		if(arr[i]==1)
		{
			top=Push(arr,i,stack,top);
			i++;
		}
		else if(arr[i]==0)
		{
			top=Pop(stack,top);
		}
		else
		{
			continue;
		}
	}
	return 0;
}

