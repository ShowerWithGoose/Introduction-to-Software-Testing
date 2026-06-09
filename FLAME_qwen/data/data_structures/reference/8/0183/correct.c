#include<stdio.h>
#include<string.h>
int weights[200][200],visited[200]={0},que[200];

int n,m;	
void DFS(int v)
{
	int i;
	printf("%d ",v);	
	visited[v]=1;		
	for(i = 0; i < n; i++)
		if (weights[v][i] && !visited[i])	
		{
			DFS(i);	
		}
}
void BFS(int v)
{
	int i,head=0,tail=1,tmp;	
	que[head]=v;	
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
	DFS(0);puts("");
	
	memset(visited,0,sizeof(visited));
	BFS(0);puts("");
	
	scanf("%d",&del);
	memset(visited,0,sizeof(visited));	
	visited[del]=1;		
	DFS(0);puts("");	
	memset(visited,0,sizeof(visited));memset(que,0,sizeof(que));
	visited[del]=1;		 
	BFS(0);puts("");
	return 0;
}

