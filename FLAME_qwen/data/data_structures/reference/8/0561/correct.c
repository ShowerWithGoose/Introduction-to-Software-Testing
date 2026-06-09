#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<time.h>
#define REP(i,a,b) for(register int i=a;i<=b;i++)
#define PER(i,a,b) for(register int i=a;i>=b;i--)
typedef long long LL;
int g[2001][2001];
int vis[2001];
int q[10010],head,rear;
int m,n,u,v,p;
void dfs(int u){
	vis[u]=1;
	printf("%d ",u);
	REP(i,0,n-1)
		if(g[u][i]&&!vis[i])
			dfs(i);
}
void bfs(int u){
	head=1,rear=0;
	memset(vis,0,sizeof(vis));
	q[++rear]=u;
	vis[u]=1;
	while(head<=rear){
		printf("%d ",q[head]);
		int tmp=q[head];head++;
		REP(i,0,n-1)
			if(g[tmp][i]&&!vis[i])
				q[++rear]=i,vis[i]=1;
	}
}
int main(){
	scanf("%d%d",&n,&m);
	REP(i,1,m)scanf("%d%d",&u,&v),g[u][v]=g[v][u]=1;
	scanf("%d",&p);
	dfs(0);
	puts("");
	bfs(0);
	puts("");
	REP(i,0,n-1)g[p][i]=g[i][p]=0;
	memset(vis,0,sizeof(vis));
	dfs(0);
	puts("");
	bfs(0);
}

