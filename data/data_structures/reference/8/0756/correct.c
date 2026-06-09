#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int g[105][105]={0},u,v,numd,numb,i=0,de,sum=0,b[105],p=0;
int vis[105]={0};
int queue[105]={0},front=0,rear=-1;
void dfs(int x,int depth)
{
	vis[x]=1;
	for(int a=0;a<numd;a++)
	{
		if(vis[a]==0&&g[x][a]==1)
		{
			printf("%d ",a);
			dfs(a,depth+1);
		}
	}
}
void dfstrave()
{
	printf("0 ");
	for(int u=0;u<numd;u++)
	{
		if(vis[u]==0)
		dfs(u,1);
	}
}
void bfs()
{
	printf("0 ");
	queue[++rear]=0;
	vis[0]=1;
	while(front<=rear&&rear<numd)
	{
		for(int i=0;i<numd;i++)
		{
			if(g[queue[front]][i]==1&&vis[i]==0)
			{
				printf("%d ",i);
				vis[i]=1;
				queue[++rear]=i;
		    }
		}
		front++;
	}
}
int main()
{
	scanf("%d%d",&numd,&numb);
	for(i=0;i<numb;i++)
	{
		scanf("%d%d",&u,&v);
		g[u][v]=1;
		g[v][u]=1;
	}
	scanf("%d",&de);
	dfstrave();
	printf("\n");
	for(i=0;i<105;i++)  vis[i]=0;
	bfs();
	printf("\n");
	for(i=0;i<numd;i++)
	{
		g[i][de]=0;
		g[de][i]=0;
	}
	for(i=0;i<105;i++)  vis[i]=0;
	dfstrave();
	printf("\n");
	for(i=0;i<105;i++)  vis[i]=0;
	front=0;rear=-1;
	bfs();
	return 0;
 } 

