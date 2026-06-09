#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int a[105];
int main()
{
	int n,m,count=0;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==1)
		{
			scanf("%d",&m);
			if(count>=100)
				printf("error ");
			else
			{
				a[count++]=m;
			}
		}
		else if(n==0)
		{
			if(count<=0)
				printf("error ");
			else
				printf("%d ",a[--count]);
		}
		else
			break; 
	}
	return 0;
}

