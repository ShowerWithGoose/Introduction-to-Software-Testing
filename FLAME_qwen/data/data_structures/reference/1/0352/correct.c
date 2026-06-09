#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
int pd[11];
int ans[10],n;
void dg(int step)
{
	int j;
	int i;
	if(step==n-1)
	{
		for(j=0;j<n-1;j++)
			printf("%d ",ans[j]);
		printf("\n");
		return ;
	}
	for(i=1;i<n;i++)
	{
		if(pd[i]==0)
		{
			ans[step]=i;
			pd[i]=1;
			dg(step+1);
			pd[i]=0;
		}
	}
	if(step==0)
	{
		for(j=0;j<11;j++)pd[j]=0;
	}
}
int main()
{
	scanf("%d",&n);
	n++;
	dg(0);
	return 0;	
}




