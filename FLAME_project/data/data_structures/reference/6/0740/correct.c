#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define MAX 2000
int top=-1;
int data[MAX];

int isEmpty()
{
	return top==-1;
}

int isFull()
{
	return top==MAX-1;
}

/*void InitStack()
{
	top=-1;
}*/

int Getstack(int *num)
{
	if(top!=MAX-1)
	data[++top]=*num;
}

int OutStack()
{
	if(isEmpty())
	{
		printf("error ");
		return 0;
	}
	else
	{
		printf("%d ",data[top--]);
	}
}

int main()
{
	int a[10000],i=0,j;
	scanf("%d",&a[0]);
	while(a[i]!=-1)
	{
	    i++;
		scanf("%d",&a[i]);
	}
	for(j=0;j<i;j++)
	{
		if(a[j]==1)
		{
			Getstack(&a[j+1]);
			j++;
		}
		if(a[j]==0)
		{
			OutStack();
		}
	}
	return 0;
}

