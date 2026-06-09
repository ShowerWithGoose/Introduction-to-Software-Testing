#include<stdio.h>

int a[105];

int main()
{
	int n;
	int v=0;
	while(scanf("%d",&n))
	{
		if(n==-1)
		break;
		else if(n==1)
		{
			int num;
			scanf("%d",&num);
			if(v==100)
			printf("error ");
			else
			{
				v++;
				a[v]=num;
			}
		}
		else if(n==0)
		{
			if(v==0)
			printf("error ");
			else
			{
				printf("%d ",a[v]);
				a[v--]=0;
			}
		}
	}
	return 0;
} 

