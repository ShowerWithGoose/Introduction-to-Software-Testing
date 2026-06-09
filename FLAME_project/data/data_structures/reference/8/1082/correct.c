#include<stdio.h>
int n;
int m;
int biao[105][105];
int visited[105];
int queue[256];
int vex[105];
void DFS(int v)//深搜函数 
{
	int w;
    printf("%d ",vex[v]);
    visited[v] = 1;
    for(w=0; w<n ;w++)
    {
        if(biao[v][w] == 1&& !visited[w])
        {
            DFS(w);
        }
    }
}
void DFSTraverse()
{
    int v;
    for(v = 0;v<n ;v++)
    {
        if(!visited[v])
        {
            DFS(v);
        }
    }
}
// 邻接矩阵的广度遍历算法
int step0=0;
void into(int v)//类似于层次遍历 
{
	int w;
	printf("%d ",queue[v]);
	visited[queue[v]]=1;
    for(w=0; w<105 ;w++)
    {
        if(biao[queue[v]][w] == 1 && !visited[w])
        {
            queue[++step0]=w;
//            printf("\n   %d\n",w);
            visited[w]=1;
        }
    }
}
void BFSTraverse()
{
	for(int i=0;i<n;i++)
	{
		into(i);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	int x,y;
	for(int i=0;i<n;i++)
	{
		vex[i]=i;
	}
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&x,&y);
		biao[x][y]=1;
		biao[y][x]=1;
	}
	
	int k;
	scanf("%d",&k);
	DFSTraverse();puts("");
	for(int i=0;i<105;i++)
	{
		visited[i]=0;
	}
	BFSTraverse();puts("");
	for(int i=0;i<105;i++)
	{
		visited[i]=0;
	}
	visited[k]=1;
	for(int i=0;i<105;i++)
	{
		biao[k][i]=0;
		biao[i][k]=0;
	}
	DFSTraverse();puts("");
	for(int i=0;i<105;i++)
	{
		visited[i]=0;
	}
	n-=1;
	for(int i=0;i<=step0;i++)
	{
		queue[i]=0;
	}
	step0=0;
	for(int i=0;i<105;i++)
	{
		biao[k][i]=0;
		biao[i][k]=0;
	}
	BFSTraverse();
}

