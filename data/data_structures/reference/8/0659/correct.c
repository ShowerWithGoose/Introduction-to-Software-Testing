#include<stdio.h>
#include<string.h>
#include <ctype.h>
#include <stdlib.h>

int wei[500][500],vis[500]={0},que[500];
int n,m;
void travelDFS(int v)
{
	int i;
	printf("%d ",v);
	vis[v]=1;
	for(i = 0; i < n; i++)
		if (wei[v][i] && !vis[i])
		{
			travelDFS(i);
		}
}
void travelBFS(int v)
{
	int i,head=0,tail=1,tmp;
	que[head]=v;
	while(head<=tail)
	{
		tmp=que[head];
		head++;
		if(vis[tmp])	
			continue;
		else
		{
			printf("%d ",tmp);
			vis[tmp]=1;
			for(i=0;i<n;i++)
				if (wei[tmp][i] && !vis[i])	
					que[tail++]=i;
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
		wei[u][v]=1;
		wei[v][u]=1;
	}
	travelDFS(0);
	printf("\n");
	
	memset(vis,0,sizeof(vis));
	travelBFS(0);
	printf("\n");
	
	scanf("%d",&del);
	memset(vis,0,sizeof(vis));
	vis[del]=1;
	travelDFS(0);
	printf("\n");
	
	memset(vis,0,sizeof(vis));memset(que,0,sizeof(que));
	vis[del]=1;
	travelBFS(0);
	printf("\n");
}

