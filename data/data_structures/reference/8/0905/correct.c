#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int visited1[100];
int visited2[100];
int st[101][101];
int que[202]={0};
int i,vi,del;
void dfs(int v)
{
	int j;
	printf("%d ",v);
	visited1[v]=1;
	for(j=0;j<vi;j++)
	{
		if(st[v][j]==1&&visited1[j]==0)
		{
			dfs(j);
		}
	}
}
void bfs(int v)
{
	int head=0,tail=1,tmp;
	que[head]=v;
	while(head<=tail)
	{
		tmp=que[head];
		head++;
		if(visited2[tmp]==1) continue;
		else
		{
			printf("%d ",tmp);
			visited2[tmp]=1;
			for(i=0;i<vi;i++)
			{
				if(st[tmp][i]==1&&visited2[i]==0)
				que[tail++]=i;
			}
		}
	}
}
int main()
{
	int ed,ed1,ed2;
	scanf("%d %d",&vi,&ed);
	for(i=0;i<ed;i++)
	{
		scanf("%d %d",&ed1,&ed2);
		st[ed1][ed2]=1;
		st[ed2][ed1]=1;
	}
	dfs(0);
	puts("");
	memset(visited1,0,sizeof(visited1));
	bfs(0);
	puts("");
	memset(visited2,0,sizeof(visited2));
	memset(que,0,sizeof(que));
	scanf("%d",&del);
	visited1[del]=1;visited2[del]=1;
	dfs(0);
	puts("");
	bfs(0);
	puts("");
	
	return 0;
}
