#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>

int edge[101][101]= {{0}};
int dot[101]= {0};
int n,e;
int Q[200];
int f=0,r=0;
void dfs(int p);
void bfs(int p);
void pra();

int main()
{
	int w=0,ii=0,i=0,j=0,t=0;
	scanf("%d%d",&n,&e);
	for(t=0; t<e; t++)
	{
		scanf("%d%d",&i,&j);
		edge[i][j]=1;
		edge[j][i]=1;
	}
	scanf("%d",&ii);
	dfs(0);pra();
	bfs(0);pra();
	dot[ii]=1;
	w=ii==0?1:0;
	dfs(w);pra();
	dot[ii]=1;
	bfs(w);pra();
	return 0;
}
void dfs(int p)
{
	int i=0;
	printf("%d ",p);
	dot[p]=1;
	for(i=0; i<n; i++)
	{
		if(edge[p][i]==1&&dot[i]==0)
		{
			dfs(i);
		}
	}
	return;
}
void bfs(int p)
{
	int v=0,i=0;
	printf("%d ",p);
	dot[p]=1;
	Q[r++]=p;
	while(f!=r)
	{
		v=Q[f++];
		for(i=0; i<n; i++)
		{
			if(edge[v][i]==1&&dot[i]==0)
			{
				printf("%d ",i);
				Q[r++]=i;
				dot[i]=1;
			}
		}
	}
	return;
}
void pra()
{
	int i=0;
	printf("\n");
	for(i=0;i<n;i++)
	{
		dot[i]=0;
	}
}

