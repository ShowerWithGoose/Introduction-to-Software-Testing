#include<stdio.h>
int pt,e;
int queue[1000];
int graph[1000][1000];
int visited[1000];
int v1,v2;

void DFS(int vex)
{
	int i;
	printf("%d ",vex);
	visited[vex]=1;
	for(i=0;i<pt;i++)
	{
		if(graph[vex][i]!=0&&visited[i]==0)
		{
			DFS(i);
		}
	}
}
void BFS(int vex)
{
	int i,head=0,tail=1;
	int tmp;
	queue[head]=vex;
	while(head<=tail)
	{
		tmp=queue[head];
		head++;
		if(visited[tmp]!=0)
		{
			continue;
		}
		else 
		{
			printf("%d ",tmp);
			visited[tmp]=1;
			for(i=0;i<pt;i++)
			{
				if(graph[tmp][i]!=0&&visited[i]==0)
				{
					queue[tail++]=i;
				}
			}
		}
	}
}

int main()
{

	int del;
	scanf("%d %d",&pt,&e);
	for(int i=0;i<e;i++)
	{
		scanf("%d %d",&v1,&v2);
		graph[v1][v2]=1;
		graph[v2][v1]=1;
	}
	
	DFS(0);
	printf("\n");
	
	memset(visited,0,sizeof(visited));
	BFS(0);
	printf("\n");
	
	memset(visited,0,sizeof(visited));
	scanf("%d",&del);
	visited[del]=1;
	DFS(0);
	printf("\n");
	
	memset(visited,0,sizeof(visited));
	memset(queue,0,sizeof(queue));
	visited[del]=1;
	BFS(0);
	printf("\n");
	return 0;
	
 } 

