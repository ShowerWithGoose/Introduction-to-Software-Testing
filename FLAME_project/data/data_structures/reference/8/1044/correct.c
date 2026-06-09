#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int path[110][110]={0};
int record[110]={0};
int n,m;
int a[110];
void DFS(int p)
{
    printf("%d ",p);
	record[p]=1;
	for(int i=0;i<n;i++){
		if(path[p][i]==1&&record[i]==0) DFS(i);
	}
}
void BFS(int p){
	a[0]=p;
	int l=0,r=0,t;
	while(l<=r){
		t=a[l];
		l++;
		if(record[t]) continue;
		printf("%d ",t);
		record[t]=1;
		for(int i=0;i<n;i++){
			if(path[t][i]==1&&record[i]==0) a[++r]=i;
		}
	}
}
int main()
{
	int i,j,d;
	scanf("%d %d",&n,&m);
	for(int k=0;k<m;k++){
		scanf("%d %d",&i,&j);
		path[i][j]=1;
		path[j][i]=1;
	}
	scanf("%d",&d);
	DFS(0);
	printf("\n");
	for(int k=0;k<110;k++) record[k]=0;
	BFS(0);
	printf("\n");
	for(int k=0;k<110;k++) record[k]=0;
	for(int k=0;k<110;k++) a[k]=0;
	for(int k=0;k<n;k++){
		path[d][k]=0;
		path[k][d]=0;
	}
	DFS(0);
	printf("\n");
	for(int k=0;k<110;k++) record[k]=0;
	BFS(0);
}


