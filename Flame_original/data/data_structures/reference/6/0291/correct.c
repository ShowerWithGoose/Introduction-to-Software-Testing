#include<stdio.h>
int main()
{
	int a[101]={0};
	int flag,temp,i=1;
	while(scanf("%d",&flag)!=EOF)
	{
		if(flag==1)
		{
			scanf("%d",&temp);
			if(i==100)
				printf("error ");
			else
			{
				a[i]=temp;
				i++;
			}
		}
		else if(flag==0)
		{
			if(i==1)
				printf("error ");
			else
			{
				printf("%d ",a[i-1]);
				a[i-1]=0;
				i--;
			}
		}
	}
	return 0;
}

