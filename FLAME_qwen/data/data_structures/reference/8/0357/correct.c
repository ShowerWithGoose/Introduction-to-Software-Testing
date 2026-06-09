#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>
int visited[200]={0},que[200];
typedef struct graph
{
	int arc[200][200];
	int num_ver,num_edge;
	int vexs[200];	
}MGraph;
void DFS(MGraph G, int i)
{
	int j;
	printf("%d ",i); //打印顶点 
	visited[i]=1;	
	for(j=0;j<G.num_ver;j++)
	{
		if(G.arc[i][j]==1&&!visited[j])
		DFS(G,j); //对未访问的邻接顶点进行访问 
	}
}
void BFS(MGraph G)
{
	int i ,j,rear=-1,top=0;
	for(i=0;i<G.num_ver;i++)
	{
		if(!visited[i])
		{
			visited[i]=1;
			printf("%d ",i);
			que[++rear] = i;
			while(top<=rear)
			{
				i=que[top++] ;
				for(j=0;j<G.num_ver;j++)
				{
					if(G.arc[i][j]==1&&!visited[j])
					{
						visited[j]=1;
						printf("%d ",j);
						que[++rear]=j;
					}
				}
			}
		}
	}
} 
MGraph GGG;
int k,x,y,del;
int main(){
	scanf("%d %d",&GGG.num_ver,&GGG.num_edge);
	for(k=0;k<GGG.num_edge;k++)
	{
		scanf("%d %d",&x,&y);
		GGG.arc[x][y]=1;
		GGG.arc[y][x]=1;
	}
	DFS(GGG,0);
	printf("\n");
	memset(visited,0,sizeof(visited));
	BFS(GGG);
	printf("\n");
	scanf("%d",&del);
	memset(visited,0,sizeof(visited));
	visited[del]=1;
	DFS(GGG,0);
	printf("\n");
	memset(visited,0,sizeof(visited));
	memset(que,0,sizeof(que));
	visited[del]=1;
	BFS(GGG);
	printf("\n");
return 0;
}

