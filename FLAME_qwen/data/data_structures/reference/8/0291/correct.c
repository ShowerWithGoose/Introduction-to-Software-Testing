#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int graph[200][200],visit[200],q[200];
int vex,edge,dele;
void DFS(int n)
{
	printf("%d ",n);
	int i;
	visit[n]=1;
	for(i=0;i<vex;i++)
	{
		if(graph[n][i]==1&&visit[i]==0)
			DFS(i);
	}
}
void BFS(int n)
{
	q[0]=n;
	int l=0,r=1,i,temp;
	while(l<=r)
	{
		temp = q[l++];//出队 
		if(visit[temp]==1)
			continue;
		else
		{
			printf("%d ",temp);
			visit[temp]=1;
			for(i=0;i<vex;i++)
			{
				if(graph[temp][i]==1&&visit[i]==0)
					q[r++] = i;//入队 
			}
		}
	}
	memset(visit,0,sizeof(visit));
}
int main()
{
	int a,b,i;
	scanf("%d %d",&vex,&edge);
	for(i=0;i<edge;i++)
	{
		scanf("%d %d",&a,&b);
		graph[a][b]=1;
		graph[b][a]=1;
	}
	memset(visit,0,sizeof(visit));
	DFS(0);
	printf("\n");
	memset(visit,0,sizeof(visit));
	BFS(0);
	printf("\n");
	scanf("%d",&dele);
	visit[dele]=1;
	DFS(0);
	printf("\n");
	memset(visit,0,sizeof(visit));
	visit[dele]=1;
	BFS(0);
	printf("\n");
	return 0;
} 

