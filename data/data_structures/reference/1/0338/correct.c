#include<stdio.h>
#include<string.h>
int n;
int res[20]={0};//用来输出的数组 
int mark[20]={0}; //判断是否已经有数字的数字 
int a[20]={0};//待输入的数组(本题中为：1,2,3,……,n) 

void dfs(int step)
{
	int i;
	if(step==n+1)
	{
		for(i=1;i<n;i++)
		printf("%d ",res[i]);
		printf("%d\n",res[n]);
		return;
	}
	for(i=1;i<=n;i++)
	{
		if(mark[i]==0)
		{
			res[step]=a[i];
			mark[i]=1;
			dfs(step+1);//?
			mark[i]=0;
		}
	}
}

int main()
{
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++)
		a[i]=i;
	dfs(1);
	return 0;
}

