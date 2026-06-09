#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int a[15],flag[15];
void dps(int m,int n)
{
	if(m==n)
	{
		for(int i=n;i>=1;i--)
		{
			printf("%d ",a[i]);
		}
		printf("\n");
		return ;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(flag[i]==0)
			{
				a[n-m]=i;
				flag[i]=1;
				dps(m+1,n);
				flag[i]=0;
			}
		}
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	a[i]=i;
	dps(0,n);
	return 0;
}

