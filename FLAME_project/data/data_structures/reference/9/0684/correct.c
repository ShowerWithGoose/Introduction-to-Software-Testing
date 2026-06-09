#include<stdio.h>
int a[105],b[105],x[105],y[105],len[105];
int main()
{
	int N,i,num=0,j,k,max,maxi;
	scanf("%d",&N);
	for(i=1;i<=N;i++)//录入没问题 
	{
		scanf("%d%d%d%d",&a[i],&b[i],&x[i],&y[i]);
		len[i]=1;	
	}
	for(j=1;j<=N;j++)
	{
		if(len[j]==0)
		{
			continue;
		}
		for(i=1;i<=N;i++)
		{
			if(x[j]==a[i]&&y[j]==b[i]&&len[i]!=0)
			{
				x[j]=x[i];y[j]=y[i];
				len[j]+=len[i];len[i]=0;i=0;
			}
		}
	}
	max=len[1];maxi=1;
	for(i=2;i<=N;i++)
	{
		if(len[i]>max)
		{
			maxi=i;
			max=len[i];
		}
	}
	printf("%d %d %d",max,a[maxi],b[maxi]);
	return 0;
	
}

