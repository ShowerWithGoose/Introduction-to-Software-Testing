#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int edge[105][105],visited[105],quene[105],n,m; 
void dfs(int x)
{
	int i;
	printf("%d ",x);
	visited[x]=1;
	for(i=0;i<n;i++)
	{
		if(edge[x][i]==1&&visited[i]==0)//矩阵元素为1且未访问过 
			dfs(i);
	}
}
void bfs(int x)
{
	int i,head=0,tail=1,item;
	quene[head]=x;
	while(head<tail)
	{
		item=quene[head++];
		if(visited[item]) continue;
		else
		{
			printf("%d ",item);
			visited[item]=1;
			for(i=0;i<n;i++)
			{
				if(edge[item][i]==1&&visited[i]==0)
					quene[tail++]=i; 
			}
		}
	}
}
int main()
{
	int a,b,c,i;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&a,&b);
		edge[a][b]=1;edge[b][a]=1;//无向图	
	}
	scanf("%d",&c);
	dfs(0);
	printf("\n");
	memset(visited,0,sizeof(visited));
	bfs(0);
	printf("\n");
	memset(visited,0,sizeof(visited));
	visited[c]=1;
	dfs(0);
	printf("\n");
	memset(visited,0,sizeof(visited));
	memset(quene,0,sizeof(quene));
	visited[c]=1;
	bfs(0);
	return 0;
}

