#include<stdio.h>
int n,m,v[102][102],vis[102],q[102],ban;
void dfs(int pos)
{
	int i; 
	vis[pos]=1;
	printf("%d ",pos);
	for(i=1;i<n;i++)
	if(i!=ban&&v[pos][i]&&!vis[i]) dfs(i);
 } 
void bfs()
{
	memset(vis,0,sizeof(vis));
	int h=0,t=0,x,i;
	q[h]=0;vis[0]=1;
	while(h<=t)
	{
		x=q[h++];
		printf("%d ",x);
		for(i=1;i<n;i++)
		if(i!=ban&&v[x][i]&&!vis[i]) q[++t]=i,vis[i]=1;
	}
	putchar('\n');
}
int main()
{
	int i,j,a,b;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		v[a][b]=v[b][a]=1;
	}
	dfs(0);putchar('\n');
	bfs();
	scanf("%d",&ban);
	memset(vis,0,sizeof(vis));
	dfs(0);putchar('\n');
	bfs();
 } 

