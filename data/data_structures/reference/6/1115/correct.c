#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int a[100];
int top=-1;
int isEmpty()
{
	return top==-1;
}
int isfull()
{
	return top==99;
}
int out()
{
	if(isEmpty()) 
	{
		printf("error ");
		return -1;
	}
	printf("%d ",a[top]);
	top--;
	
	return 1;
}
int in(int n)
{
	if(isfull())
	{
		printf("error ");
		return -1;
	}
	a[++top]=n;
	return 1;
}

int main()
{
	int x,n;
	int i,j;
	while((scanf("%d",&x))!=EOF)
	{
		
		switch(x)
		{
			case -1:
				return 0;
			case 0:
				out();
				break;
			case 1:
				scanf("%d",&n);
				in(n);
				break;
		}
	}
}




























