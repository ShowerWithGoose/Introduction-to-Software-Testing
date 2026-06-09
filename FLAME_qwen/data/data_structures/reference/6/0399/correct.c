#include<stdio.h>

int a[1000];
int main()
{
	int n,m,i;
	i=0;
	while(~scanf("%d",&n))
	{
		if(n==1)
		{
			scanf("%d",&m);
			if(i>100)
			printf("error ");
			else
			{
				a[i]=m;
				i++;
			}
		}
		else if(n==0)
		{
			if(i<=0)
			printf("error ");
			else
			{
				printf("%d ",a[--i]);
			}
		}
		else if(n==-1)
		break;
	}
	return 0;
}

