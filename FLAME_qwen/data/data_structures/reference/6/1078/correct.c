#include<stdio.h>
int main()
{
	int a[1000],i,j,b[100];
	scanf("%d ",&a[0]);
	i=0;
	while(a[i]!=-1)
	{
		i++;
		scanf("%d ",&a[i]);
	}
	j=0;
	for(i=0;a[i]!=-1;i++)
	{
		if(a[i]==1)
		{
			i+=1;
			if(j<=99)
			{
			b[j]=a[i];
			j+=1;
		    }
		    else
		    {
		    	printf("error ");
			}
		}
		if(a[i]==0)
		{
			if(j>=1)
			{
				j-=1;
				printf("%d ",b[j]);
			}
			else
			{
				printf("error ");
			}
		}
	}
}

