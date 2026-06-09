#include<stdio.h>
#include<string.h>
int n;
int vis[12]={0},ans[12];
void prin()
{
	int i;
	for(i=1;i<=n;i++)
	{
		printf("%d",ans[i]);
		if(i!=n)printf(" ");
		else printf("\n");
	}
}
void dfs(int x,int num)
{
	ans[num]=x;vis[x]=1;
	if(num==n)prin();
	else
	{
		int i;
	    for(i=1;i<=n;i++)if(!vis[i])dfs(i,num+1);
	}
	vis[x]=0;
	return;
}
int main()
{
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++)dfs(i,1);
} 

