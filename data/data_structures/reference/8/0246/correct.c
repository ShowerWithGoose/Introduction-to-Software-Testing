#include<stdio.h>
#include<string.h>
#define N 100
int n,m,g[N][N],del;
void init(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		int u,v; scanf("%d%d",&u,&v);
		g[u][v]=g[v][u]=1;
	}
	scanf("%d",&del);
}
int q[N],cnt,h,t,vis[N];
void dfs(int u){
	vis[u]=1; printf("%d ",u);
	for (int i=0;i<n;i++) if (!vis[i]&&g[u][i]) dfs(i);
}
void bfs(){
	h=t=0; 
	q[++t]=0; vis[0]=1;
	while (h<t){
		int u=q[++h]; printf("%d ",u);
		for (int i=0;i<n;i++)
			if (!vis[i]&&g[u][i]) q[++t]=i,vis[i]=1;
	}
	puts("");
}
void solve(){
	dfs(0); puts("");
	memset(vis,0,sizeof vis);
	bfs();	memset(vis,0,sizeof vis);  vis[del]=1;
	dfs(0); puts("");
	memset(vis,0,sizeof vis); vis[del]=1;
	bfs();
}
int main(){
	init(); solve(); 
	return 0;
}



