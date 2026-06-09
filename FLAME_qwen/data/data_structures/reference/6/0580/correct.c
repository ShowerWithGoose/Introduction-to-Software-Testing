#include <stdio.h>
int main()
{
	int a,b,r=0,z[100],i;
	scanf("%d",&a);
	for(;a!=-1;)
	{
		if(a==1)
		{
			scanf("%d",&b);
			if(r==100)
			{
				printf("error ");
			}
			else
			{
				z[r]=b;
				r++;
			}
		}
		else if(a==0)
		{
			if(r==0)
			{
				printf("error ");
			}
			else
			{
				printf("%d ",z[r-1]);
				r--;
			}
		}
		scanf("%d",&a);
	}
	return 0;
} 

