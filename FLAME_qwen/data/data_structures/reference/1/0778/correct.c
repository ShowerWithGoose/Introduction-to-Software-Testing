#include <stdio.h>
void dfs(int n,int N);
int hold[15],mark[15];
int main()
{
	int N;
	scanf("%d",&N);//N代表边界level，即生成几个数字的全排列 
	dfs(1,N);
	return 0;
}
void dfs(int n,int N)
{
	if(n==N+1)
	{
		for(int i=1;i<=N;i++)
		{
			printf("%d ",hold[i]);
		}
		printf("\n");
		return ;
	}
	else 
	{
		for(int i=1;i<=N;i++)
		{
			if(mark[i]==0)
			{
				hold[n]=i;
				mark[i]=1;
				dfs(n+1,N);
				mark[i]=0;
			}
		}
	}
}

