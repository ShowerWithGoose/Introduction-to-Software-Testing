#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include <ctype.h>
#include <math.h>
/*typedef struct edge{ 
int adj;
int weight; 
struct edge *next;
}ELink;
typedef struct ver{
ELink * link;
}VLink;
VLink g[100];*/
int ch[101][101];
int visit[101]={0},visit2[101]={0};
int not,bian;
int queue[101];
void dfs(int v)
{
	printf("%d ",v);
	int i;
	visit[v]=1;
	for(i=0;i<not;i++)
	{
		if(ch[v][i+1]==1&&visit[i+1]==0)
		dfs(i+1);
	}
}
void bfs(int v)
{
	//printf("%d ",v);
	int flag=0;
	visit2[v]=1;
	int rear=0,front=-1;
	front++;
	queue[front]=v;
	while(rear<=front)
	{
		int x = queue[rear];
		rear++;
		printf("%d ",x);
		//visit2[x] = 1;
		for (int i = 0; i <not; i++)
			if (ch[x][i])
			{
				if (!visit2[i])
				{
					
					front++;
					queue[front] = i;
					visit2[i]=1;
					
					
				}
				
			}
	
	}
	
}
int main()
{
	int i;
	int x,y;
	scanf("%d %d",&not,&bian);
	for(i=0;i<bian;i++)
	{
		scanf("%d %d",&x,&y);
		ch[x][y]=1;
		ch[y][x]=1;		 
	}
	dfs(0);
	printf("\n");
	bfs(0);
	printf("\n");
	int d;
	scanf("%d",&d);
	for(i=0;i<not;i++)
	{
		ch[i][d]=0;
	}	
	for(int j=0;j<not;j++)
	{
		ch[d][j]=0;
	}
	memset(visit,0,sizeof(visit));
	memset(visit2,0,sizeof(visit2));
	memset(queue,0,sizeof(queue));
	dfs(0);
	printf("\n");
	bfs(0);
	printf("\n");
	
	return 0;
}



