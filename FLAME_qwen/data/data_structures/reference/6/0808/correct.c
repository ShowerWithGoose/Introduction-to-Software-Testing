#include<stdio.h>
int main()
{
	int z[100],a,n=0;
	while(scanf("%d",&a)!=-1)
	{
		if(a==1)
		{
			if(n==100)
			{
				printf("error ");
			}
			else
			{
			    scanf("%d",&z[n]);
			    n++;
		    }
		}
		else if(a==0)
		{
			if(n==0)
			{
				printf("error ");
			}
			else
			{
				n--;
			    printf("%d ",z[n]);
			}
		}
		else
		return 0;
	}
	return 0;
}

