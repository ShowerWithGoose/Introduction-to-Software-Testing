#include<stdio.h>
int n;
int js[12]={1,2,6,24,120,720,5040,40320,362880,3628800};
void f(int k)
{
	int i,x,tem,j=n-2;
	int flag=0;
	int mark[12]={0};

	while(j>=0)
	{
		x=k/js[j];
		tem=k%js[j];
		
		for(i=1;i<=n;i++)
		{
			if(mark[i]==0)++flag;
			if(flag==x+1)
			{
				printf("%d ",i);
				mark[i]=1;
				flag=0;
				break;
			}
		}
		--j;
		k=tem;
	}
	for(i=1;i<=n;i++)
	{
		if(mark[i]==0)
		{
			printf("%d",i);
			break;
		}
	}
	putchar('\n');
	return;
}
int main()
{
	int ii;
	
	scanf("%d",&n);
	if(n==1)
	{
		printf("1");
		return 0;
	}
	
	for(ii=0;ii<js[n-1];ii++)
	{
		f(ii);
	}
	return 0;
}

