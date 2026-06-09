#include<stdio.h>
int main()
{
	int a[105]={},r=0,b,m;
	while(~scanf("%d",&b) && b!=-1)
	{
		if(b==1)
		{
			if(r==100)
			{
				printf("error ");
				continue;
			}
			scanf("%d",&m);
			a[r]=m;
			r++; 
		}
		else if(b==0)
		{
			r--;
			if(r<0)
			{
				printf("error ");
				r++;
				continue;
			}
			printf("%d ",a[r]);
		}
	}
	return 0;
} 

