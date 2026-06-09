#include<stdio.h>

struct node
{
	int x1,x2,y1,y2;
}l[5005];

int vis[5005];

int n;

int ans,ansu;

void dfs(int u,int k,int s)
{
	if(k>ans)
	{
		ans=k;
		ansu=s;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i]&&l[i].x1==l[u].x2&&l[i].y1==l[u].y2)
		{
			vis[i]=1;
			dfs(i,k+1,s);
			vis[i]=0;
		}
	}
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d%d",&l[i].x1,&l[i].y1,&l[i].x2,&l[i].y2);
	}
	for(int i=1;i<=n;i++)
		dfs(i,1,i);
	printf("%d %d %d\n",ans,l[ansu].x1,l[ansu].y1);
	return 0;
}

