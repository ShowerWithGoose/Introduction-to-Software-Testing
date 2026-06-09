#include<stdio.h>
int main()
{
	int a[200],b=0,c=0,d[100];
	while((scanf("%d",&a[c]))!=EOF)
	{
		c++;
	}
	c=0;
	printf("\n");
	while(1)
	{
		if(a[c]==1)
		{
			if(b==100)
			{
				printf("error ");
			}
			else
			{
				d[b]=a[c+1];
				b++;
				c++;
			}
		}
		else if(a[c]==0)
		{
			if(b==0)
			{
				printf("error ");
			}
			else
			{
				b--;
				printf("%d ",d[b]);
				
			}
		}
		else if(a[c]==-1)
		return 0;
		c++;
	}
	return 0;
 } 

