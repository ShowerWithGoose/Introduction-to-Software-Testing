#include<stdio.h>
#include<string.h>
int weight[200][200],visit[200]={0},q[200];
int n,m;
void dfs(int v)
{
	int i;
	printf("%d ",v);
	visit[v]=1;
	for(i=0;i<n;i++)
	{
		if(weight[v][i]&&!visit[i])
		{
			dfs(i);
		}
	}
}
void bfs(int v)
{
	int i,head=0,tail=1,tmp;
	q[head]=v;
	while(head<=tail)
	{
		tmp=q[head];
		head++;
		if(visit[tmp])
		{
			continue;
		}
		else
		{
			printf("%d ",tmp);
			visit[tmp]=1;
			for(i=0;i<n;i++)
			{
				if(weight[tmp][i]&&!visit[i])
				{
					q[tail++]=i;
				}
			}
		}
	}
}
int main()
{
	int u,v,i,del;
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%d %d",&u,&v);
		weight[u][v]=1;
		weight[v][u]=1;
	}
	dfs(0);
	puts("");
	memset(visit,0,sizeof(visit));
	bfs(0);
	puts("");
	scanf("%d",&del);
	memset(visit,0,sizeof(visit));
	visit[del]=1;
	dfs(0);
	puts("");
	memset(visit,0,sizeof(visit));
	memset(q,0,sizeof(q));
	visit[del]=1;
	bfs(0);
	puts("");
	return 0;
}

