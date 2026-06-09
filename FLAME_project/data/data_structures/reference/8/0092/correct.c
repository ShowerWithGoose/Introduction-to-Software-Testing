#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int temp[200]={0},flag,n,m,str[200][200]={0},r,j,tempp[200]={0};
void dfs(int p);
void bfs(int p);
int main()
{
	int x,y;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		str[x][y]=1;
		str[y][x]=1;
	}
	for(int i=0;i<200;i++)
	{
		temp[i]=0;
		flag=0;
	}
	dfs(0);
	printf("\n");
	for(int i=0;i<200;i++)
	{
		temp[i]=0;
		flag=0;
	}
	bfs(0);
	printf("\n");
	for(int i=0;i<200;i++)
	{
		temp[i]=0;
		flag=0;
	}
	scanf("%d",&x);
	temp[x]=1;
	dfs(0);
	printf("\n");
	for(int i=0;i<200;i++)
	{
		temp[i]=0;
		flag=0;
	}
	temp[x]=1;
	bfs(0);
	printf("\n");
}
void dfs(int p)
{
	if(flag==0)
	{
		printf("%d",p);
		flag=1;
	}
	else 
	{printf(" %d",p);}
	temp[p]=1;
	for(int i=1;i<=n;i++)
	{
		if(temp[i]==0&&str[p][i]==1)
		{dfs(i); }
	}
}
void bfs(int p)
{
	int t;
	tempp[1]=p;
	for(j=1,r=1;j<=r;)
	{
		t=tempp[j++];
		if(temp[t]==1)
		{
			continue;
		}
		if(flag==0)
		{
			printf("%d",t);
			flag=1;
		}
		else 
		printf(" %d",t);
		temp[t]=1;
		for(int i=1;i<=n;i++)
		{
			if(str[t][i]==1&&temp[i]==0)
			{
				tempp[++r]=i;
			}
		}
	}
}

