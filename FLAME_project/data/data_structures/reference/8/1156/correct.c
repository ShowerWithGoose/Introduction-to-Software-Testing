#include<stdio.h>
#include<string.h>
#define N 110
int n,K=-1;
int vis[N],D[N][N],Q[N];
void DFS(int x){
	printf("%d ",x);
	vis[x]=1;
	int i;
	for (i=0;i<n;i++){
		if (D[x][i] && !vis[i] && i!=K){
			DFS(i);
		}
	}
}
void BFS(){
	int i,l=1,r=1;
	Q[1]=0;
	vis[0]=1;
	while (l<=r){
		int x=Q[l++];
		printf("%d ",x);
		for (i=0;i<n;i++){
			if (D[x][i] && !vis[i] && i!=K){
				vis[i]=1;
				Q[++r]=i;
			}
		}
	}
}
int main(){
	int m,i;
	scanf("%d%d",&n,&m);
	for (i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		D[x][y]=D[y][x]=1;
	}
	memset(vis,0,sizeof(vis));
	DFS(0);printf("\n");
	memset(vis,0,sizeof(vis));
	BFS();printf("\n");
	scanf("%d",&K);
	memset(vis,0,sizeof(vis));
	DFS(0);printf("\n");
	memset(vis,0,sizeof(vis));
	BFS();printf("\n");
	return 0;
}

