#include<stdio.h>
int box[11];
int book[11];
int n; 
void dfs(int x);
int main()
{
	scanf("%d",&n);
	dfs(0);
return 0;
} 
void dfs(int x)
{
	if(x==n)
	{
		for(int i=0;i<n;i++)
			printf("%d ",box[i]);
		printf("\n");
		return;
	}
	int i;
	for(i=1;i<=n;i++)
	{
		if(book[i]==1)
			continue;
		else
			{
				box[x]=i;
				book[i]=1;
				dfs(x+1);
				book[i]=0;
			}
	}

return;
}



