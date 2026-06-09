#include<stdio.h>
#include<string.h>
int gra[110][110]={0},visbfs[110],visited[110]={0};
void DFS(int point,int p)
{
	printf("%d ",p);
	visited[p]=1;
	for(int i=1;i<=point;i++)
	{
		if(gra[p][i]&&visited[i]==0)DFS(point,i);
	}
}
void BFS(int point,int p)
{
	int a;
	visbfs[1]=p;
	for(int j=1,k=1;j<=k;j++)
	{
		a=visbfs[j];
		if(visited[a])continue;
		printf("%d ",a);
		visited[a]=1;
		for(int i=1;i<=point;i++)
		{
			if(gra[a][i]&&visited[i]==0)visbfs[++k]=i;
		}
	}
}

int main()
{
	int point,line,l,r,del;
	scanf("%d%d",&point,&line);
	for(int i=1;i<=line;i++)
	{
		scanf("%d%d",&l,&r);
		gra[l][r]=1;
		gra[r][l]=1;
	}
	scanf("%d",&del);
	DFS(point ,0);
	printf("\n");
	memset(visited,0,sizeof(visited));
	BFS(point ,0);
	printf("\n");
	
	memset(visited,0,sizeof(visited));
	visited[del]=1;
	DFS(point,0);
	printf("\n");
	
	memset(visited,0,sizeof(visited));
	visited[del]=1;
	BFS(point,0);
	printf("\n");
	return 0;
}

