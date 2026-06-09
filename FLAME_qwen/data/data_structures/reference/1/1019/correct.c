#include<stdio.h>
int n;
int a[10];
int book[10]={0};
void dfs(int step)
{
	if(step==n)
	{
		for(int i=0;i<n;i++)
		{
			printf("%d ",a[i]);
		}
		printf("\n");
		return;
	}
	
	for(int i=0;i<n;i++)
	{
		if(book[i]==0)
		{
			a[step]=i+1;
			book[i]=1;
			dfs(step+1);
			book[i]=0;
		}
	}
	return;
}
int main()
{
	scanf("%d",&n);
	int step=0;
	dfs(step);
	return 0;
}

