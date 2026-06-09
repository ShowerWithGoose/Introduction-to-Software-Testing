#include <stdio.h>
#include <stdlib.h>
int e[110][110]={0},n,h[100]={0},s[100],f=-1,r=0;;
void dfs(int a)
{
	int i;
	h[a]=1;
	printf("%d ",a);
	for(i=0;i<n;i++)
	{
		if(e[a][i]==1 && h[i]==0)
		{
			dfs(i);
		}
	}
}
void bfs(int a)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(e[a][i]==1 && h[i]==0)
		{
			printf("%d ",i);
			s[r]=i;
			r++;
			h[i]=1;
		}
	}
}
int main()
{
	int a,d,x,y,i,j;
	scanf("%d%d",&n,&a);
	for(i=0;i<a;i++)
	{
		scanf("%d%d",&x,&y);
		e[x][y]=1;
		e[y][x]=1;
	}
	scanf("%d",&d);
	dfs(0);
	for(i=0;i<100;i++)
	{
		h[i]=0;
	}
	printf("\n");
	printf("0 ");
	s[r]=0;
	r++;
	f++;
	h[0]=1;
	for(;r!=f;)
	{
		bfs(s[f]);
		f++;
	}
	printf("\n");
	for(i=0;i<100;i++)
	{
		h[i]=0;
	}
	for(i=0;i<n;i++)
	{
		e[d][i]=0;
		e[i][d]=0;
	}
	dfs(0);
	for(i=0;i<100;i++)
	{
		h[i]=0;
	}
	printf("\n");
	printf("0 ");
	r=0;
	f=-1;
	s[r]=0;
	r++;
	f++;
	h[0]=1;
	for(;r!=f;)
	{
		bfs(s[f]);
		f++;
	}
	return 0;
}

