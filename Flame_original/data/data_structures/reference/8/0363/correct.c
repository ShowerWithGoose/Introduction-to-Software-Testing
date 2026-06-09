#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_N 5010

int e[MAX_N][MAX_N];
int vis[MAX_N];
int n,m;
int x=-1;
void dfs(int now) {
	printf("%d ",now);
	vis[now]=1;
	int i;
	for(i=1;i<=n;i++) {
		if(vis[i]) continue;
		if(!e[now][i]) continue;
		if(i==x) continue;
		dfs(i);
	}
	return ;
}
int q[MAX_N],head,tail;
void BFS(int S) {
	q[++tail]=S;
	vis[S]=1;
	int i;
	while(head<tail) {
		int t=q[++head];
		printf("%d ",t);
		for(i=1;i<=n;i++) {
			if(i==x) continue;
			if(vis[i]) continue;
			if(!e[t][i]) continue;
			vis[i]=1;
			q[++tail]=i;
		}
	}
}
int main() {
	scanf("%d%d",&n,&m);
	int i;
	for(i=1;i<=m;i++) {
		int u,v;
		scanf("%d%d",&u,&v);
		e[u][v]=1;
		e[v][u]=1;
	}
	dfs(0);
	for(i=1;i<=n;i++) vis[i]=0;
	puts("");
	BFS(0);
	puts("");
	scanf("%d",&x);
	for(i=1;i<=n;i++) vis[i]=0;
	dfs(0);
	puts("");
	for(i=1;i<=n;i++) vis[i]=0;
	BFS(0);
	return 0;
}

