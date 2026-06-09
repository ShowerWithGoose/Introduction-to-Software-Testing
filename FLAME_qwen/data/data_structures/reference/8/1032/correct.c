#include<stdio.h>
int visited[105];
int arcs[105][105];
int vex,arc;
void dfs(int a);
void bfs(int a);
int main()
{
	
	scanf("%d%d",&vex,&arc);
	int i;
	for(i=0;i<arc;++i)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		arcs[a][b]=1;
		arcs[b][a]=1;
	}
	int del;
	scanf("%d",&del);
	dfs(0);
	printf("\n");
	
	for(i=0;i<vex;++i)
	visited[i]=0;
	
	bfs(0);
	printf("\n");
	
	for(i=0;i<vex;++i)
	visited[i]=0;
	
	for(i=0;i<vex;++i)
	{
		arcs[del][i]=0;
		arcs[i][del]=0;
	}
	
	dfs(0);
	printf("\n");
	
	for(i=0;i<vex;++i)
	visited[i]=0;
	
	bfs(0);
	
	return 0;
}

void dfs(int a)
{
	visited[a]=1;
	printf("%d ",a);
	int i=0;
	for(i=0;i<vex;++i)
	{
		if(arcs[a][i]!=0)
		  if(visited[i]==0)
		  dfs(i);
	}
}

void bfs(int a)
{
	int queue[105];
	queue[0]=a;
	printf("%d ",a);
	visited[a]=1;
	int i,head,q=0;
	for(head=0;head<=q;++head)
	{
		for(i=0;i<vex;++i)
		{
			if(arcs[queue[head]][i]!=0)
		  	if(visited[i]==0)
		  	{
		  	  visited[i]=1;
			  printf("%d ",i);
			  queue[++q]=i;
		  	}
		    
		}
	}

}

