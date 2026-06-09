#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int link[100][100]={{0}};
int visit[100]={0},stack[100]={0},top=-1,ttnode,ttn,front=0,rear=-1;

void dfs(int node);
void bfs(int node);
int main(void)
{
	int edge,i,j,a,b,dlt;
	scanf("%d%d",&ttnode,&edge);
	ttn=ttnode;
	for(i=0;i<edge;i++)
	{
		scanf("%d%d",&a,&b);
		link[a][b]=1;
		link[b][a]=1;
	}
	scanf("%d",&dlt);		
	visit[0]=1;
	printf("0 ");
	top++;
	dfs(0);
	top=-1;
	memset(visit,0,ttnode*sizeof(int));
	bfs(0);
	memset(visit,0,ttnode*sizeof(int));
	for(i=0;i<ttnode;i++)
		link[dlt][i]=link[i][dlt]=0;
	ttn--;
	visit[0]=1;
	printf("0 ");
	top++;
	dfs(0);
	memset(visit,0,ttnode*sizeof(int));
	front=0;
	rear=-1;
	bfs(0);		
		
	return 0;	
} 

void dfs(int node)
{
	int i,j;
	for(i=0;i<ttnode;i++)
	{
		if(link[node][i]!=0&&visit[i]!=1)
		{
			printf("%d",i);
			top++;
			if(top<ttn-1)
				printf(" ");
			else
				printf("\n");
			visit[i]=1;
			dfs(i);	
		}	
	}
}
void bfs(int node)
{
	int i,j;
	stack[++rear]=node;
	visit[node]=1;
	printf("%d ",node);
	while(front<=rear)
	{
		for(j=0;j<ttnode;j++)
		{
			if(link[stack[front]][j]==0||visit[j]==1)
				continue;
			stack[++rear]=j;
			visit[j]=1;
			printf("%d",j);
			if(rear<ttn-1)
				printf(" ");
			else
				printf("\n");
		}		
		front++;
	}
}

