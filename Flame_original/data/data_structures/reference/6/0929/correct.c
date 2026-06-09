#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max 100
int main()
{
	int n,m,a[max],top=-1;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==1)
		{
			scanf("%d",&m);
			if(top==max-1)
				printf("error ");
			else
				a[++top]=m;
		}
		else if(n==0)
		{
			if(top==-1)
				printf("error ");
			else
			{
				printf("%d ",a[top]);
				top--;
			}
		}
		else
			break;
	}
	return 0;
}

