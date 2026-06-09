#include<stdio.h>

int n,m,b[100005],p,q[100005],h,t,vis[100005],a[1005][1005];

void dfs(int o)
{
	printf("%d ",o);vis[o]=1;
	for(int i=1;i<=a[o][0];i++)
		if(!vis[a[o][i]]) dfs(a[o][i]);
}

void bfs()
{
	h=t=1;q[1]=0;vis[0]=1;
	while(h<=t)
	{
		int yu=q[h++];printf("%d ",yu);
		for(int i=1;i<=a[yu][0];i++)
			if(!vis[a[yu][i]]) 
			{
				q[++t]=a[yu][i];
				vis[a[yu][i]]=1;
			}
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x,y;scanf("%d%d",&x,&y);
		a[x][++a[x][0]]=y;
		a[y][++a[y][0]]=x;
	}
	scanf("%d",&p);
	for(int i=0;i<n;i++)
		for(int j=1;j<=a[i][0];j++)
			for(int k=j+1;k<=a[i][0];k++)
				if(a[i][j]>a[i][k]) {int t=a[i][j];a[i][j]=a[i][k];a[i][k]=t;}
	for(int i=0;i<n;i++) vis[i]=0;dfs(0);puts("");
	for(int i=0;i<n;i++) vis[i]=0;bfs();puts("");
	for(int i=0;i<n;i++) vis[i]=0;vis[p]=1;dfs(0);puts("");
	for(int i=0;i<n;i++) vis[i]=0;vis[p]=1;bfs();puts("");
	return 0;
}

