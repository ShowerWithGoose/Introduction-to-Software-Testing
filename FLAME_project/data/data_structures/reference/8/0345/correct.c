#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int m,n;//m为顶点个数，n为边的个数
int map[105][105];
int book[1000];
int dfs(int x);
int bfs(int x)
{
	int queue[10000]={0};
	int head=0,tail=1;
	int i;
	int mark[1000]={0};
	queue[head]=x;
	while(head<tail)
	{
		for(i=0;i<m;i++)
		{
			if(map[queue[head]][i]==1&&mark[i]==0)
			{
				printf("%d ",i);
				queue[tail]=i;
				mark[i]=1;
				tail++;
			}
		}
		mark[queue[head]]=1;
		head++;
	}
	return 0;
}
int main()
{
	scanf("%d %d",&m,&n);
	int i;
	int dele;
	
	for(i=1;i<=n;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		map[a][b]=1;
		map[b][a]=1;//因为是无向图 
	}
	scanf("%d",&dele);
	printf("0 ");
	dfs(0);
	printf("\n");
	printf("0 ");
	bfs(0);
	
	memset(book,0,1000);
	
	for(i=0;i<m;i++)
	{
		if(map[dele][i]==1||map[i][dele]==1)	
		{
			map[dele][i]=0;
			map[i][dele]=0;
		}	
	}
	printf("\n0 ");
	dfs(0);
	printf("\n");
	printf("0 ");
	bfs(0);
	
	return 0;
}

int dfs(int x)//x为当前顶点 
{
	int flag=0;
	book[x]=1;
	int i;
	for(i=0;i<m;i++)
	{
		if(map[x][i]!=0&&book[i]==0)	
		{
			flag=1;
			printf("%d ",i);
			dfs(i);
		}	
	}
	if(flag==0)return 0;
	return 0;
}





