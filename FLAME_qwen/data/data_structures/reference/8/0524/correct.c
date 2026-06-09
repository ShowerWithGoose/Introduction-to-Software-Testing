#include<stdio.h>
#include<stdlib.h>
int n,m,p,q;
char l[100][100],vis[100];
void dfs(int num);
void bfs();
int main()
{
	scanf("%d%d",&n,&m);
	while(m--)
	{
		scanf("%d%d",&p,&q);
		l[p][q]=l[q][p]=1;
	}
	dfs(0);
	putchar(10);
	memset(vis,0,sizeof(vis));
	bfs();
	putchar(10);
	memset(vis,0,sizeof(vis));
	while(scanf("%d",&p)!=EOF)	vis[p]=1;
	dfs(0);
	putchar(10);
	memset(vis,0,sizeof(vis));vis[p]=1;
	bfs();
	return 0;
}
void bfs()
{
	int queue[100],fr=0,re=0,q,i;
	queue[re]=0;++re;
	vis[0]=1;
	while(fr<re)
	{
		q=queue[fr];++fr;
		printf("%d ",q);
		for(i=0;i<n;++i)
			if(l[q][i]&&!vis[i])
			{
				vis[i]=1;
				queue[re]=i;++re;
			}
	}
	return;
}
void dfs(int num)
{
	int i;
	vis[num]=1;
	printf("%d ",num);
	for(i=0;i<n;++i)	if(l[num][i]&&!vis[i])	dfs(i);
	return;
}



