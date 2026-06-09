#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int a[101][101];
int visited[101];
int aflag[101];
int n;
int queqe[200];
int num;
int M;
int front=0;
int rear=-1;
int first(int v){
	int k;
	for(k=0;k<n;k++){
		if(a[v][k]==1&&aflag[k]!=1){
		aflag[k]=1;	
		return k;}
	}
	return -1;
}
void dfs(int v){
	int w;
	printf("%d ",v);
	visited[v]=1;
	w=first(v);
	while(w!=-1){
		if(visited[w]==0)
		dfs(w);
		w=first(v);
	}
}
void bfs(int v){
	int w;
	printf("%d ",v);
	visited[v]=1;
	queqe[++rear]=v;
	M++;
	while(M!=0){
		v=queqe[front];
		M--;
		front++;
		w=first(v);
		while(w!=-1){
			if(visited[w]==0){
				printf("%d ",w);
				queqe[++rear]=w;
				M++;
				visited[w]=1;
			}
			w=first(v);
		}
	}
}
int main(){
	int side;
	scanf("%d%d",&n,&side);
	int i;
	int p1,p2;
	for(i=0;i<side;i++){
		scanf("%d%d",&p1,&p2);
		a[p1][p2]=1;
		a[p2][p1]=1;
	}
	int d;
	scanf("%d",&d);
	for(i=0;i<n;i++){
		if(visited[i]==0)
		dfs(i);
	}
	printf("\n");
	memset(visited,0,sizeof(visited));
	memset(aflag,0,sizeof(aflag));
	for(i=0;i<n;i++){
		if(visited[i]==0)
		bfs(i);
	}
	printf("\n");
	memset(visited,0,sizeof(visited));
	memset(aflag,0,sizeof(aflag));
	for(i=0;i<n;i++){
		if(a[d][i]==1){
			a[d][i]=0;
			a[i][d]=0;
		}
	}
	visited[d]=1;
	for(i=0;i<n;i++){
		if(visited[i]==0)
		dfs(i);
	}
	printf("\n");
	memset(visited,0,sizeof(visited));
	memset(aflag,0,sizeof(aflag));
	visited[d]=1;
	for(i=0;i<n;i++){
		if(visited[i]==0)
		bfs(i);
	}
	return 0;
}

