#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h> 
int o[101][101],vis[101],op,q[101];
int a,b,i,n,x,y;
void dfs(int x)
{
	if(!op)
	{
		printf("%d",x);
		op=1;
	}
	else printf(" %d",x);
	vis[x]=1;
	int i;
	for(i=1;i<n;i++)
	{
		if(o[x][i])
		{
			if(!vis[i])
			dfs(i);
		}
	}
}

void bfs(int x)
{
	q[1]=x;
	int l=1,r=1,i;
	while(l<=r)
	{
		int t=q[l];
		l++;
		if(vis[t])
		continue;
		if(!op)
		{
			printf("%d",t);
			op=1;
		}
		else printf(" %d",t);
		vis[t]=1;
		for(i=1;i<n;i++)
		if(o[t][i])
		{
			if(!vis[i])
			q[++r]=i;
			
		}
	}
	memset(vis,0,sizeof(vis));
}
int main()
{
	scanf("%d %d",&a,&b);
	for(n=0;n<b;n++)
	{
		scanf("%d %d",&x,&y);
		o[x][y]=1;
		o[y][x]=1;
	}
	op=0;
	dfs(0);
	printf("\n");
	memset(vis,0,sizeof(vis));
	op=0;
	bfs(0);
	printf("\n");
	memset(vis,0,sizeof(vis));
	scanf("%d",&i);
	for(x=0;x<n;x++)
	{
		o[i][x]=0;
		o[x][i]=0;
	}
	op=0;
	dfs(0);
	printf("\n");
	memset(vis,0,sizeof(vis));
	op=0;
	bfs(0);
	printf("\n");
	return 0;
}

