#include<stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define ll long long
#define eps 1e-6
#define MAX 1000005
int ver[105];
int visit1[105],visit2[105];
int a[105][105];
int quene[10000];
int r=-1,l=0;
int vn,t;

void DFS(int a[][105],int v){
	visit1[v]=1;
	printf("%d ",v);
	for(int i=0;i<vn;i++){
		if(visit1[i]==0&&a[v][i]==1)
		DFS(a,i);
	}
}
void BFS(int a[][105],int v){
	visit2[v]=1;
	quene[++r]=v;
	while(l<=r){
		v=quene[l++];
		printf("%d ",v);
		for(int i=0;i<vn;i++){
			if(visit2[i]==0&&a[v][i]==1){
				visit2[i]=1;
				quene[++r]=i;
			}
		}
	}
}
void traveldfs(int a[][105],int n){
	int i=0;
	for(i=0;i<n;i++){
		if(!visit1[i])
		DFS(a,i);
	}
}
void travelbfs(int a[][105],int n){
	int i;
	for(i=0;i<n;i++){
		if(!visit2[i])
		BFS(a,i);
	}
}
int main() {
	int v1,v2;
	scanf("%d%d",&vn,&t);
	for(int i=0; i<t; i++) {
		scanf("%d%d",&v1,&v2);
		a[v1][v2]=1;
		a[v2][v1]=1;
	}
	int del;
	scanf("%d",&del);	
	traveldfs(a,vn);
	printf("\n");
	travelbfs(a,vn);
	printf("\n");
	for(int i=0;i<vn;i++){
		visit1[i]=0;
		visit2[i]=0;
	}
	visit1[del]=1;
	visit2[del]=1;
	traveldfs(a,vn);
	printf("\n");
	travelbfs(a,vn);
	return 0;
}


