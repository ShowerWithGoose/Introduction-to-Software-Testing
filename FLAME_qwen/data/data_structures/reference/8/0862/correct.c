#include<stdio.h>
#include<math.h>
#include<string.h>
int jz[150][150];
int que[150];
int visit[150];
void dfs(int n);
void bfs(int l);
int front=0,rear=0;
int d,b;
int main()
{
	int a,c;
	scanf("%d%d",&d,&b);
	for(int i=0;i<b;i++)
	{
		scanf("%d%d",&a,&c);
		jz[a][c]=1;
		jz[c][a]=1;
	}
	dfs(0);
	printf("\n");
	for(int i=0;i<d;i++)
	{
		visit[i]=0;
	}
	bfs(0);
	printf("\n");
	int de;
	scanf("%d",&de);
	for(int i=0;i<d;i++)
	{
		jz[de][i]=0;
		jz[i][de]=0;
	}
	for(int i=0;i<d;i++)
	{
		visit[i]=0;
	}
	dfs(0);
	printf("\n");
	for(int i=0;i<d;i++)
	{
		visit[i]=0;
	}
	bfs(0);
 	return 0;
}


void dfs(int n)
{

	printf("%d ",n);
	visit[n]=1;
	for(int i=0;i<d;i++)
	{
		if(jz[i][n]&&visit[i]==0)
		{
			dfs(i);
		}
	}

}


void bfs(int n)//front和rear的关系front不要忘了加 
{
	printf("%d ",n);

	for(int i=1;i<d;i++)//把这个点的子节点都加入队列 
	{
		if(jz[i][n]&&visit[i]==0)//连着，没访问过 
		{
		
			que[rear]=i;
			rear++;	
			visit[i]=1;
		}
	}
	while(front<rear)
	{
		front++;
		bfs(que[front-1]);
	
	}

}

