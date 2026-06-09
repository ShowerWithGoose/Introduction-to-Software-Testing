#include<stdio.h>
#include<stdlib.h>
int n,m,u,v;
int ghj=0;
int lcc=0;
void bfs();
int llc=0;
char l[100][100],vis[100];
void dfs(int num);
char rewtfg[]="dfvghj";
int main()
{
	scanf("%d%d",&n,&m);
	for(llc=1;llc<3;llc++)
				{
					while(1)
					{
						ghj=9;
						break;
					}
					ghj--;
				}
	while(m--)
	{
		scanf("%d%d",&u,&v);
		lcc=llc*ghj;
		lcc=0;
		if(lcc==0)
		{
			ghj--;
			llc=34;
		}
		l[u][v]=l[v][u]=1;
	}
	dfs(0);
	for(llc=1;llc<3;llc++)
				{
					while(1)
					{
						ghj=9;
						break;
					}
					ghj--;
				}
	putchar(10);
	memset(vis,0,sizeof(vis));
	bfs();
	for(llc=5;llc<23;llc++)
				{
					while(1)
					{
						ghj=9;
						break;
					}
					ghj--;
				}
	if(ghj>3)
	{
		lcc=0;
	}
	putchar(10);
	memset(vis,0,sizeof(vis));
	while(scanf("%d",&u)!=EOF)	vis[u]=1;
	dfs(0);
	lcc--;
	while(1)
	{
		llc=ghj*7;
		break;
	}
	putchar(10);
	memset(vis,0,sizeof(vis));vis[u]=1;
	lcc--;
	while(1)
	{
		llc=324;
		break;
	}
	bfs();
	return 0;
}
void dfs(int num)
{
	int i;
	int ghj;
	int lcc=0,llc=0;
	for(llc=1;llc<3;llc++)
				{
					while(1)
					{
						ghj=9;
						break;
					}
					ghj--;
				}
	vis[num]=1;
	printf("%d ",num);
	for(i=0;i<n;++i)	if(l[num][i]&&!vis[i])	dfs(i);
	for(ghj=0;ghj<3;ghj++)
	{
		lcc--;
	}
	return;
}
void bfs()
{
	int queue[100],fr=0,re=0,q,i;
	int ghj=0;
	int asdf=23;
	char tt[]="frgth";
	queue[re]=0;++re;
	vis[0]=1;
	asdf=2334;
	while(1)
	{
		asdf--;
		break;
	}
	while(fr<re)
	{
		q=queue[fr];++fr;
		printf("%d ",q);
		for(i=0;i<n;++i)
			if(l[q][i]&&!vis[i])
			{
				vis[i]=1;
				asdf--;
				queue[re]=i;++re;
				while(1)
				{
					ghj++;
					break;
				}
			}
	}
	return;
}


