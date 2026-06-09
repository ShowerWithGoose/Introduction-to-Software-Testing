#include<stdio.h>
#include<stdlib.h>
typedef struct lio
{
	int lx;
	int rx;
	int ly;
	int ry;
}lines;
int rank(const void*a,const void*b)
{
	lines p=*(lines*)a;
	lines q=*(lines*)b;
	int k=p.lx-q.lx;
	if(k<0)return -1;
	else return 1;
}
lines line[105];
int dp[105];//假设dp为以第i线段结尾的连续线段的个数。 
int n=0;
int main()
{
	scanf("%d",&n);
	int i=0;
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d %d",&line[i].lx,&line[i].ly,&line[i].rx,&line[i].ry);
	}
	qsort(line,n,sizeof(lines),rank);
	dp[n-1]=1;
	int m=0,j=n-1;
	for(i=n-1;i>=0;i--)
	{
		m=0;
		for(j=n-1;j>i;j--)
		{
			if(line[j].lx==line[i].rx&&line[j].ly==line[i].ry)
			
			{
				if(dp[j]>m)m=dp[j];
			}
		}
		dp[i]=m+1;
	}
	m=0;
	int mi;
	for(i=n-1;i>=0;i--)
	{
		if(dp[i]>m){
		m=dp[i];mi=i;}
		
	}
	printf("%d %d %d",m,line[mi].lx,line[mi].ly);
	return 0;
	 
	
}

