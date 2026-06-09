#include<stdio.h>
int a[100]={0};
int main()
{
	int x,i=0;
	scanf("%d",&x);
	while(x!=-1)
	{
		if(x==1)
		{
			scanf("%d",&x);
			if(i==100)
			{
				printf("error ");
			}
			else
			{
				a[i]=x;
				i++;
			}
		}
		else
		{
			if(i==0)
			{
				printf("error ");
			}
			else
			{
				printf("%d ",a[i-1]);
				a[i]=0;
				i--;
			}
		}
		scanf("%d",&x);
	}
	return 0;
}

