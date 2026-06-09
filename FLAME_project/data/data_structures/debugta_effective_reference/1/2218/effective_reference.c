#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
int mark[11];
int ans[10],x;
void dg(int m)
{
	int j;
	int i;
	if(m==x-1)
	{
		for(j=0;j<x-1;j++)
			printf("%d ",ans[j]);
		printf("\n");
		return ;
	}
	for(i=1;i<x;i++)
	{
		if(mark[i]==0)
		{
			ans[m]=i;
			mark[i]=1;
			dg(m+1);
			mark[i]=0;
		}
	}
	if(m==0)
	{
		for(j=0;j<11;j++)mark[j]=0;
	}
}
int main()
{
	scanf("%d",&x);
	x++;
	dg(0);
	return 0;	
}




