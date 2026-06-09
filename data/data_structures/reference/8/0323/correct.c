#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int G[100][100];
int visited[100];
void sweep(int n)
{
    for(int i=0;i<n;i++)
        visited[i]=0;
}
void dfs(int u,int n)
{
    printf("%d ",u);
    visited[u]=1;
    for (int i=0;i<n;i++)//深度遍历
    {
        if(i!=u)
            if(G[u][i]==1&&!visited[i])
                dfs(i,n);
    }
}
int queue[100],head=0,rear=-1;
int isempty(){return head>rear;}
void push (int x){queue[++rear]=x;}
int pop(){return isempty() ? -1 : queue[head++];}
void bfs (int u,int n)
{
	push(u);
	printf("%d ",u);
	visited[u]=1;
	while(!isempty())
{	u=pop();
	for(int i=0;i<n;i++)
	{
		if(i!=u)
		{
			if(G[u][i]==1&&!visited[i])
			{
				push(i);
				printf("%d ",i);
				visited[i]=1;
}}}}}
int main()
{
    int n,m,u,v,del;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++)
{
      scanf(" %d %d",&u,&v);
      G[u][v]=G[v][u]=1;
}
    scanf("%d",&del);
    dfs(0,n);
    sweep(n);
    printf("\n");
    bfs(0,n);
    printf("\n");
    sweep(n);
   for(int i=0;i<m;i++)
{
      G[del][i]=G[i][del]=0;
}
dfs(0,n);
    sweep(n);
    printf("\n");
    bfs(0,n);
    printf("\n");
    sweep(n);
    return 0;
}
