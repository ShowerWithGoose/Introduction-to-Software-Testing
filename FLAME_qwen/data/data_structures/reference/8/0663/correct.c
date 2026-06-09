#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int g[101][101];
int visit[101];
int n,m;
void DFS(int p)
{
	printf("%d ",p);
	visit[p]=1;
	for(int i=0;i<n;i++)
	{
		if(visit[i]==0&&g[p][i]==1)
			DFS(i); 
	}
}
int queue[101];
int head=0,rear=-1;
//int isempty()
//{
//	return head>rear;
//}
void push(int x)
{
	queue[++rear]=x;
}
int pop()
{
	return queue[head++];
//	isempty?-1:queue[head++];
} 
void BFS(int p)
{
	push(p);
	printf("%d ",p);
	visit[p]=1;
	while(head<=rear)
	{
		int temp=pop();
		for(int i=0;i<n;i++)
		{
			if(visit[i]==0&&g[temp][i]==1)
			{
				push(i);
				printf("%d ",i);
				visit[i]=1;
			}
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	int u,v;
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&u,&v);
		g[u][v]=g[v][u]=1;
	}
	DFS(0);
	puts("\n");
	memset(visit,0,sizeof(visit));
	BFS(0);
	puts("\n");
	memset(visit,0,sizeof(visit));
	memset(queue,0,sizeof(queue));
	
	int dot;
	scanf("%d",&dot);
	visit[dot]=1;
	DFS(0);
	puts("\n");
	memset(visit,0,sizeof(visit));
	visit[dot]=1;
	BFS(0);
	puts("\n");
	return 0;
 } 

