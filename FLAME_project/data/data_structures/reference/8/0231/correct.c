
#include <stdio.h>
#include <string.h>

int n,e;
int weights[200][200],visited[200],que[200];

void dfs(int v)
{
	int i;
	printf("%d ",v);
	visited[v]=1;
	for(i=0;i<n;i++)
		if(weights[v][i]==1&&visited[i]==0)
			dfs(i);
}

void bfs(int v)
{
	int i,head=0,end=1,temp;
	que[head]=v;
	while(head<=end)
	{
		temp=que[head];
		head++;
		if(visited[temp]==1)
			continue;
		else
		{
			printf("%d ",temp);
			visited[temp]=1;
			for(i=0;i<n;i++)
				if(weights[temp][i]==1&&visited[i]==0)
					que[end++]=i;
		}
	}
}
int main()
{
	int i,x,y,del;
	scanf("%d%d",&n,&e);
	for(i=0;i<e;i++)
	{
		scanf("%d%d",&x,&y);//Â¼Èë 
		weights[x][y]=1;
		weights[y][x]=1;
	}
	dfs(0);
	printf("\n");
	memset(visited,0,sizeof(visited));
	
	bfs(0);
	printf("\n");
	scanf("%d",&del);
	memset(visited,0,sizeof(visited));
	
	visited[del]=1;//Ò»·ÃÎÊ
	dfs(0);
	printf("\n"); 
	
	memset(visited,0,sizeof(visited));
	memset(que,0,sizeof(que));
	visited[del]=1;
	bfs(0);
	printf("\n");
	return 0;
} 

