#include<stdio.h>
#include<string.h>


int weights[200][200],visited[200]={0},que[200];
int n,m;

void tBFS(int x)
{
	int i,head=0,tail=1,tmp;
	que[head]=x;
	while(head<=tail)
	{
		tmp=que[head];
		head++;
		if(visited[tmp])	continue;
		else
		{
			printf("%d ",tmp);
			visited[tmp]=1;
			for(i=0;i<n;i++)
				if (weights[tmp][i] && !visited[i])
					que[tail++]=i;
		}
	}
}

void tDFS(int x)
{
	int i;
	printf("%d ",x);
	visited[x]=1;
	for(i = 0; i < n; i++)
		if (weights[x][i] && !visited[i])
		{
			tDFS(i);
		}
}
int main()
{	
	int u,v,i,del;
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%d %d",&u,&v);
		weights[u][v]=1;
		weights[v][u]=1;
	}
	tDFS(0);
	puts("");
	memset(visited,0,sizeof(visited));
	tBFS(0);
	puts("");
	scanf("%d",&del);
	memset(visited,0,sizeof(visited));
	visited[del]=1;	
	tDFS(0);
	puts("");
	memset(visited,0,sizeof(visited));memset(que,0,sizeof(que));
	visited[del]=1;
	tBFS(0);
	puts("");
	return 0;
}
