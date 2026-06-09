#include<stdio.h>
int main()
{
	int x,i=0,a[105]={0};
	while(scanf("%d",&x)!=EOF)
	{
		if(x==1)
		{
			if(i==100)
			{
				printf("error ");
				continue;
			}
			scanf("%d",&a[++i]);
		}
		else if(x==0)
		{
			if(i==0)
			{
				printf("error ");
				continue;
			}
			printf("%d ",a[i--]);
		}
		else if(x==-1) break;
	}
	return 0;
} 

