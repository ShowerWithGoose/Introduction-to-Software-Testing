#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int n,mark=0,top=-1;
int a[100];
int main()
{
	while(scanf("%d",&n)!=-1)
	{
		if(n==1)
		{
			mark=1;
		}
		if(n!=1&&n!=0)
		{
			if(mark==1)
			{
				a[++top]=n;
				mark=0;
			}
		}
		if(n==0)
		{
			if(top!=-1)
			printf("%d ",a[top--]);
			else
				printf("error ");
		}
	}
	return 0;
}

