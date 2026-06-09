#include<stdio.h>
int s[102][102];
int vertex,edge,i;
int visit[102];
int dele;
void DFS(int vertex_)
{
	printf("%d ",vertex_);
	visit[vertex_]=1;
	int i;
	for(i=0;i<vertex;i++)
	if(visit[i]==0&&s[vertex_][i]==1)
	{
		visit[i]=1;
		DFS(i);
	}
}
void BFS(int vertex_)
{
	int a[1000];
	int front=0,rear=0;
	a[0]=0;
	visit[0]=1;
	while(rear>=front)
	{
		int now=a[front++];
		printf("%d ",now);
		for(i=0;i<vertex;i++)
	    if(visit[i]==0&&s[now][i]==1)
	    {
		  visit[i]=1;
		  a[++rear]=i;
	    }
	}
}
void ori()
{
	int i,j;
	for(i=0;i<100;i++)
	visit[i]=0;
}
void delete_(int n)
{
	int i;
	for(i=0;i<vertex;i++)
	s[i][n]=s[n][i]=0;
}
int main()
{
	scanf("%d%d",&vertex,&edge);
	for(i=1;i<=edge;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		s[a][b]=s[b][a]=1;
	}
	scanf("%d",&dele);
	DFS(0);
	printf("\n");
	ori();
	BFS(0);
	printf("\n");
	ori();
	delete_(dele);
	DFS(0);
	printf("\n");
	ori();
	BFS(0);
} 

