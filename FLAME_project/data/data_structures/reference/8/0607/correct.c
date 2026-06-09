#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define maxn 5120
int map[maxn][maxn],n,m;
char vis[maxn];

void dfs(int k){
	printf("%d ",k);
	vis[k]=1;
	int i;
	for(i=1; i<n; i++){
		if(!vis[i]&&map[k][i])
			dfs(i);
	}
}

void bfs(){
	int queue[maxn],head=1,tail=1;
	queue[head]=0;
	vis[0]=1;
	for(head=1; head<=tail; head++){
		printf("%d ",queue[head]);
		int i;
		for(i=0; i<n; i++){
			if(!vis[i]&&map[queue[head]][i]){
				vis[i]=1;
				queue[++tail]=i;
			}
		}
	}
}

int main(){
	scanf("%d%d",&n,&m);
	int i;
	for(i=1; i<=m; i++){
		int x,y;
		scanf("%d%d",&x,&y);
		map[x][y]=1; map[y][x]=1;
	}
	dfs(0);
	puts("");
	memset(vis,0,sizeof(vis));
	bfs();
	puts("");
	memset(vis,0,sizeof(vis));
	int x;
	scanf("%d",&x);
	for(i=0; i<n; i++){
		if(map[i][x]){
			map[i][x]=0;
			map[x][i]=0;
		}
	}
	dfs(0);
	puts("");
	memset(vis,0,sizeof(vis));
	bfs();
	return 0;
}


