#include<stdio.h>
int a[100];
int main()
{
	int m,n,i=1,flag1=0,flag2=0,j=-1;
	while(i==1)
	{
		scanf("%d",&m);
		if(m==-1)
		break;
		if(m==0)
		{
			if(j==-1)
			{
				printf("error ");
				flag1=1;
			}
			flag2=0;
			if(j>=0)
			{
				printf("%d ",a[j]);
				j--;
			}
			
		}
		if(m==1)
		{
			scanf("%d",&n);
			flag1=0;
			a[++j]=n;
			if(j==100)
			{
				printf("error ");
				flag2=1;
			}
			if(j==100)
			j=99;
			
		}
	}
	return 0;
}

