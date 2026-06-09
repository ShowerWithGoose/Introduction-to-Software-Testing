#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define FOR(i,a,b) for(int i=a;i<b;i++)
int visited[100];
int G[100][100];
int n;
int que[100];
int f=0,r=1;
void dsf(int i){
	printf("%d ",i);
	FOR(j,0,n)if(G[i][j]&&!visited[j])visited[j]=1,dsf(j);
	return;
}
void bsf(){
	while(r>f){
		printf("%d ",que[f]);
		FOR(i,0,n)if(G[que[f]][i]&&!visited[i])visited[i]=1,que[r++]=i;
		f++;
	}
	f=0,r=1;
}
void clear(){
	FOR(i,1,n)visited[i]=0;
	return;
}
void output(){
	dsf(0),clear();
	printf("\n");
	bsf(),clear();
	printf("\n");
	return;
}
int main(){
	visited[0]=1;
	scanf("%d",&n);
	int a,i,j;
	scanf("%d",&a);
	while(a-->0){
		scanf("%d%d",&i,&j);
		G[i][j]=G[j][i]=1;
	}
	scanf("%d",&a);
	output();
	FOR(i,0,n)G[i][a]=G[a][i]=0;
	output();
	return 0;
}

