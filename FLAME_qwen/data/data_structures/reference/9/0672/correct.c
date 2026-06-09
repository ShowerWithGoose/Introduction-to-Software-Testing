#include<stdio.h>
struct edge
{
	int to,nxxt;
}e[1001001];
int head[1001001],cnt;
void addedge(int u,int v)
{
	cnt++;
	e[cnt].to=v;
	e[cnt].nxxt=head[u];
	head[u]=cnt;
}
void superadd(int u,int v)
{
	addedge(u,v);addedge(v,u);
}
struct node
{
	int x,y,xx,yy;
}p[1001001];
int n;
int dfs(int u)
{
	int ans=1,i;
	for(i=head[u];i;i=e[i].nxxt)
	{
		ans=dfs(e[i].to)+1;
	}
	return ans;
}
int main()
{
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d%d%d%d",&p[i].x,&p[i].y,&p[i].xx,&p[i].yy);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(p[i].xx==p[j].x&&p[i].yy==p[j].y)
			{
//				printf("%d %d\n",i,j); 
				addedge(i,j);
			}
		}
	}
	int ans=0,t=0;
	for(i=1;i<=n;i++)
	{
		int s=dfs(i);
		if(s>ans)
		{
			ans=s;
			t=i;
		}
	}
	printf("%d %d %d\n",ans,p[t].x,p[t].y);
}


