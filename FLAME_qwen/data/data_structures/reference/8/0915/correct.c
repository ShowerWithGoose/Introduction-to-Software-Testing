#include<stdio.h>
#include<string.h>
#define min(a,b) a<b?a:b;
int n,m;
int e[100][100];
int vis[100];
int path[100];
int queue[100010];
int head,rear;
void dfs(int x) {
	printf("%d ",x);
	vis[x]=1;
	for(int i=0; i<n; i++)
		if(e[x][i]&&!vis[i]) {
			dfs(i);
		}
}
void bfs(int x){
	queue[rear++]=x;
	vis[x]=1;
	while(head!=rear){
		int now=queue[head++];
		printf("%d ",now);
		for(int i=0;i<n;i++){
			if(e[now][i]&&!vis[i]){
			queue[rear++]=i;
			vis[i]=1;
			}
		}
	}
}
int main() {
	scanf("%d%d",&n,&m);
	int u,v;
	for(int i=1; i<=m; i++) {
		scanf("%d%d",&u,&v);
		e[u][v]=e[v][u]=1;
	}
	int x;
	scanf("%d",&x);
	dfs(0);
	puts("");
	memset(vis,0,sizeof(vis));
	bfs(0);
	puts("");
    for(int i=0;i<n;i++)
    e[x][i]=e[i][x]=0;
    memset(vis,0,sizeof(vis));
    vis[x]=1;
	dfs(0);
	puts("");
	memset(vis,0,sizeof(vis));
    vis[x]=1;
	bfs(0);
	return 0;
}


