#include<stdio.h>
#include<string.h>
#include<stdlib.h> 
int read(){
	int s=0,f=1;char t=getchar();
	while('0'>t||t>'9'){
		if(t=='-')f=-1;
		t=getchar();
	}
	while('0'<=t&&t<='9'){
		s=(s<<1)+(s<<3)+(t-'0');
		t=getchar();
	}
	return s*f;
}
int G[105][105],n,m;
int q[105];
int vis[105];
void Bfs(){
	memset(vis,0,sizeof(vis));
	int H=1,T=0;
	q[++T]=0;vis[0]=1;
	while(H<=T){
		int u=q[H++];
		for(int v=0;v<n;v++){
			if(G[u][v]&&!vis[v]){
				q[++T]=v;
				vis[v]=1;
			}
		}
		printf("%d ",u);
	}printf("\n");
}
void Dfs(int u){
	vis[u]=1;
	printf("%d ",u);
	for(int v=0;v<n;v++){
		if(!vis[v]&&G[u][v]){
			Dfs(v);
		}
	}
}
int main(){
	n=read();m=read();
	for(int i=1,u,v;i<=m;i++){
		u=read();v=read();
		G[u][v]=G[v][u]=1;
	}
	int node=read();
	
	memset(vis,0,sizeof(vis));
	Dfs(0);printf("\n");
	Bfs();
	
	for(int i=0;i<n;i++){
		G[node][i]=0;
		G[i][node]=0;
	}
	
	memset(vis,0,sizeof(vis));
	Dfs(0);printf("\n");
	Bfs();
	return 0;
}
/*
9 10
0 1
0 2
1 4
1 3
1 8
8 6
3 6
7 2
7 5
5 2
3
*/

