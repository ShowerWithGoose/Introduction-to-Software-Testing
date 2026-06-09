#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#include<string.h>
int v[105],a[105][105]={},vis[105],queue[105],front,rear;
void dfs(int n,int v){
	int i;
	vis[v]=1;
	printf("%d ",v);
	for(i=0;i<n;i++){
		if(a[v][i]==1&&vis[i]==0) dfs(n,i);
	}
}
void traveldfs(int n){
	int i;
	for(i=0;i<n;i++) vis[i]=0;
	for(i=0;i<n;i++){
		if(!vis[i]) dfs(n,i);
	}
}
void bfs(int n,int v){
	int i;
	vis[v]=1;
	queue[++rear]=v;
	while(front!=rear){
		v=queue[++front];
		printf("%d ",v);
		for(i=0;i<n;i++){
			if(a[v][i]==1&&vis[i]==0){
				vis[i]=1;
				queue[++rear]=i;
			}
		}
	}
}
void travelbfs(int n){
	int i;
	for(i=0;i<n;i++) vis[i]=0;
	front=rear=-1;
	for(i=0;i<n;i++){
		if(!vis[i]) bfs(n,i);
	}
}
void dtraveldfs(int n,int d){
	int i;
	for(i=0;i<n;i++) vis[i]=0;
	vis[d]=1;
	for(i=0;i<n;i++){
		if(!vis[i]) dfs(n,i);
	}
}
void dtravelbfs(int n,int d){
	int i;
	for(i=0;i<n;i++) vis[i]=0;
	vis[d]=1;
	front=rear=-1;
	for(i=0;i<n;i++){
		if(!vis[i]) bfs(n,i);
	}
}
int main(){
	int i,j,Vnum,Enum,v1,v2,delv;
	scanf("%d%d",&Vnum,&Enum);
	for(i=0;i<Vnum;i++) v[i]=i;
	for(i=0;i<Enum;i++){
		scanf("%d%d",&v1,&v2);
		a[v1][v2]=1;
		a[v2][v1]=1;
	}
	scanf("%d",&delv);
	traveldfs(Vnum);
	printf("\n");
	travelbfs(Vnum);
	printf("\n");
	for(i=0;i<Vnum;i++){
		a[delv][i]=0;
		a[i][delv]=0;
	}
	dtraveldfs(Vnum,delv);
	printf("\n");
	dtravelbfs(Vnum,delv);
	printf("\n");
	return 0;
}


