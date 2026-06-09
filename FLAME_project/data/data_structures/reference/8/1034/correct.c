#include <stdio.h>
#include <string.h>
#define MAX 200
int angle=0,side=0;
int del;
int a[MAX][MAX];
int visited[MAX];
int queue[MAX];
void dfs(int x)
{
	printf("%d ",x);
	visited[x]=1;
	int i;
	for (i=1; i<angle; i++)
	{
		if(a[x][i]==1)
		{
			if(visited[i]==0)
				dfs(i);
		}
	}
}
void bfs(int x)
{
//	visited[x]=1;
	int left=0,right=0,i;
	queue[0]=x;
	while(left<=right){
		int t=queue[left];
		left++;
		if(visited[t]==1)
			continue;
		else
			printf("%d ",t);
		visited[t]=1;
		for(i=0;i<angle;i++)
			if(a[t][i]==1)
			{
					if(visited[i]==0)
						queue[++right]=i;
			}
	}
	
	
}
int main(int argc, char *argv[]) {
	scanf("%d%d",&angle,&side);
	for (int i=0; i<side; i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		a[x][y]=1;
		a[y][x]=1;
	}
	dfs(0);
	printf("\n");
	memset(visited, 0, sizeof(visited));
	bfs(0);
	printf("\n");
	memset(visited, 0, sizeof(visited));
	scanf("%d",&del);
//	for (int i=0; i<angle; i++)
//	{
//		a[3][i]=0;
//		a[i][3]=0;
//	}
	visited[del]=1;
	dfs(0);
	printf("\n");
	memset(visited, 0, sizeof(visited));
	visited[del]=1;
	bfs(0);
}


