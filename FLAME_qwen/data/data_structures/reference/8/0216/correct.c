#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int G[100][100]={0},n,V[100]={0},Q[100]={0},h=0,w=0,B[100]={0};
void DFS(int G[][100]){
	int i;
	for(i=0;i<n;i++)
	V[i]=0;
	for(i=0;i<n;i++){
		if(!V[i]){
			if(!B[i]) break;
			dfs(G,i);
		}
	}
	printf("\n");
}
void dfs(int G[][100],int a){
	int i;
	V[a]=1;
	printf("%d ",a);
	for(i=0;i<n;i++){
		if(G[a][i]&&!V[i]) dfs(G,i);
	}
}
void BFS(int G[][100]){
	int i,k;
	for(i=0;i<n;i++)
	V[i]=0;
	for(i=0;i<n;i++){
		if(!V[i]){
			if(!B[i]) continue;
			bfs(G,i);
		}	
	}
	printf("\n");
}
void bfs(int G[][100],int a){
	V[a]=1;
	Q[w]=a;
	w=(w+1)%100;
	while(w!=h){
		int x=Q[h];
		printf("%d ",Q[h]);
	    h=(h+1)%100;
		int i;
		for(i=0;i<n;i++){
			if(G[x][i]&&!V[i]){
			V[i]=1; 
			Q[w]=i;
	        w=(w+1)%100;
	        }
		}
	}
}
int main(){
    int m,i;
    scanf("%d %d",&n,&m);
	 for(i=0;i<m;i++){
	 	int a,b;
	 	scanf("%d %d",&a,&b);
	 	G[a][b]=G[b][a]=1,B[i]=1;
	 }
	 int v;
	 scanf("%d",&v);
	 DFS(G);
	 BFS(G);
	 for(i=0;i<n;i++){
	 	G[v][i]=G[i][v]=0;
	 }
	 B[v]=0;
	 DFS(G);
	 BFS(G);
	return 0;
}




