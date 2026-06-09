#include<stdio.h>
#include<string.h>
int n;
int result[100];
int book[100];
void dfs(int i)
{
	int j;
	if(i>n)
	{
		for(j=1;j<=n;j++)
		{
			printf("%d ",result[j]);
		}
		printf("\n");
		return;
	}
	for(j=1;j<=n;j++)
	{
		if(!book[j])
		{
			result[i]=j;
			book[j]=1;
			dfs(i+1);
			book[j]=0;
		}
	}
}
int main()
{
	scanf("%d",&n);
	dfs(1);
	return 0;
}



