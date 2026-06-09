#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<malloc.h>
#include<math.h>
typedef struct g{
	int nv, ne;
	int edge[105][105];
}Graph;
int visited[105]={0};
void dfs(Graph g,int i);
void bfs(Graph g, int i);
int main()
{
	Graph g;
	int dv;
	scanf("%d%d",&g.nv,&g.ne);
	for(int i=0;i<g.ne;i++)
	{
		int line1, line2;
		scanf("%d%d",&line1,&line2);
		g.edge[line1][line2]=1;
		g.edge[line2][line1]=1;
	}
	/*for(int i=0;i<g.ne;i++)
	{
		for(int j=0;j<g.ne;j++)
			printf("%d ",g.edge[i][j]);
		printf("\n");
	}*/
	scanf("%d",&dv);
	dfs(g,0);
	memset(visited,0,sizeof(visited));
	printf("\n");
	bfs(g,0);
	for(int i=0;i<g.ne;i++)
	{
		g.edge[dv][i]=0;
		g.edge[i][dv]=0;
	}
	memset(visited,0,sizeof(visited));
	printf("\n");
	dfs(g,0);
	memset(visited,0,sizeof(visited));
	printf("\n");
	bfs(g,0);
	return 0;
}
void dfs(Graph g,int i)         //深度优先搜索，从顶点i开始遍历
{
    int j;
    printf("%d ",i);         //输出访问顶点
    visited[i]=1;            //全局数组访问标记置1表示已经访问
    for(j=0;j<g.nv;j++)
        if((g.edge[i][j]==1)&&(!visited[j]))
            dfs(g,j);
}
void bfs(Graph g, int i)
{
    int q[105];
    int f=0,r=1,j;
    printf("%d ",i);
    visited[i]=1;
	q[r]=i;
    while(f<r)
    {   
		f++;
		i=q[f];
        for(j=0;j<g.nv;j++)
            if((g.edge[i][j]==1)&&(!visited[j]))
            {	
				printf("%d ",j);
				visited[j]=1;
				r++;
				q[r]=j;
			}
    }
}

