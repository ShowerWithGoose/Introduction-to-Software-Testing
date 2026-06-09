#include <stdio.h>
#include <string.h>
int ed[200][200];
int vis[200];
int flag[200];
void dfs(int n,int k)
{
	if(!vis[k]) 
    printf("%d ",k);
    vis[k]=1;
    for(int j=0;j<n;j++)
    {
    	if(ed[k][j]&&!vis[j]) dfs(n,j);
	}
}
struct Queue
{
	int top;
	int rear;
	int edge[300];
};
struct Queue queue;
void insert(int k)
{
	queue.edge[queue.top++]=k;
}
int dequeue( )
{
	
	queue.rear++;
	return queue.edge[queue.rear-1];
}
int empty()
{
	if(queue.top<=queue.rear) return 1;
	else return 0;
}
void bfs(int n )
{
	for(int i=0;i<n;i++)
	{
		if(!vis[i]&&flag[i])
		{
			printf("%d ",i);
			vis[i]=1;
			insert(i);
			while(!empty())
			{
				int k=dequeue( );
				for(int j=0;j<n;j++)
				{
					if(!vis[j]&&ed[k][j]) 
					{
						printf("%d ",j);
						vis[j]=1;
						insert(j);
					}
				}
			}
		}
	}
}
int main()
{
	int d;
	int n;
	int op;
	int start;
	int end;
	scanf("%d%d",&d,&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&start,&end);
		ed[start][end]=1;
		ed[end][start]=1;
		flag[start]++;
		flag[end]++;
	}
	scanf("%d",&op);
	dfs(n,0);
	printf("\n");
	memset(vis,0,sizeof(vis));
	queue.top=0;
	queue.rear=0;
	bfs(n);
	printf("\n");
	memset(vis,0,sizeof(vis));
	for(int i=0;i<n;i++)
	{
		ed[op][i]=0;
		ed[i][op]=0;
	}
	flag[op]=0;
	dfs(n,0);
	printf("\n");
	memset(vis,0,sizeof(vis));
	queue.top=0;
	queue.rear=0;
	bfs(n);
	printf("\n");
	memset(vis,0,sizeof(vis));
	return 0;
}

