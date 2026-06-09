#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int que[200];
int weights[200][200];
int visited[200];
int n,m;	
void dfs(int v)
{
	printf("%d ",v);	
	visited[v]=1;		
	for(int i = 0; i < n; i++)
		if (weights[v][i] &&visited[i]==0)	 
			dfs(i);	
}
void bfs(int v)
{
	int head=0,tail=1,tmp;	
	que[head]=v;	
	while(head<=tail)	
	{
		tmp=que[head];	
		head++;			
		if(visited[tmp])
			continue;	
		else
		{
			printf("%d ",tmp);	
			visited[tmp]=1;		
			for(int i=0;i<n;i++)
				if (weights[tmp][i] && !visited[i])	
					que[tail++]=i;	
		}
	}
	puts("");
}
int u,v,del;
int main()
{	
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&u,&v); 
		weights[u][v]=1;
		weights[v][u]=1;
	}
	dfs(0);puts("");
	memset(visited,0,sizeof(visited));	
	bfs(0);
	scanf("%d",&del);
	memset(visited,0,sizeof(visited));
	visited[del]=1;	
	dfs(0);puts("");
	memset(visited,0,sizeof(visited));
	memset(que,0,sizeof(que));
	visited[del]=1;	
	bfs(0);
	return 0;
}


