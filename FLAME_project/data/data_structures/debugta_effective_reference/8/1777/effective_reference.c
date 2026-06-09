#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 1000
int g[101][101],visit[101],q[MAX];
int n,m,head,rear=-1;
void dfs(int v){
	printf("%d ",v);
	visit[v]=1;
	for(int i=1;i<n;i++) if(!visit[i]&&g[v][i]==1) dfs(i);
}
void in(int x){
	q[++rear]=x;
}
int out(){
	return q[head++];
}
void bfs(){
	in(0);
	printf("0 ");
	visit[0]=1;
	while(head<=rear){
		int v=out();
		for(int i=1;i<n;i++){
			if(!visit[i]&&g[v][i]==1){
				in(i);
				printf("%d ",i);
				visit[i]=1;
			}
		}
	}
}
int main(){
	int u,v;
	scanf("%d%d",&n,&m);
	while(~scanf("%d",&u)){
		if(~scanf("%d",&v)){
			g[u][v]=g[v][u]=1;
		}
	}
	dfs(0);
	printf("\n");
	memset(visit,0,sizeof(visit));
	bfs();
	printf("\n");
	memset(visit,0,sizeof(visit));
	memset(q,0,sizeof(q));
	for(int i=0;i<n;i++){
		g[u][i]=0;
		g[i][u]=0;
	}
	dfs(0);
	printf("\n");
	memset(visit,0,sizeof(visit));
	bfs();
	printf("\n");
	return 0;
}


