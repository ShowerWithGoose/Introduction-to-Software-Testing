#include<stdio.h>
int main()
{
	int a[105],i=0,n;
	while(scanf("%d",&n))
	{
		if(n==0)
		{
			if(i==0)
			{
				printf("error ");
			}
			else
			{
			i--;
			printf("%d ",a[i]);
			a[i]=0;
			}
		}
		else if(n==1)
		{
			if(i==99)
			{
				printf("error ");
			}
			else
			{
			scanf("%d",&a[i]);
			i++;
			}
		}
		else if(n==-1)
		break;
	}
	return 0;
 } 



