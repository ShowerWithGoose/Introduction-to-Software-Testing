#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int temp[105][105];
int flag=0;
int i;
int cun[105]; 
void dfs(int n){
	int t;
	if(flag==0){
		printf("%d",n);
		flag=1;
	}
	else{
		printf(" %d",n);
	}
	cun[n]=1;
	for(t=1;t<=i;t++){
		if(temp[n][t]==1){
			if(!cun[t]){
				dfs(t);			
				}
		}
	}
	
}
void bfs(int n){
	int queue[105];
	queue[1]=n;
	int rear=1,front=1;
	int t;
	while(rear<=front){
		int tem=queue[rear++];
		if(cun[tem]==1){
			continue;
		}
		if(flag==0){
			printf("%d",tem);
			flag=1;
		}
		else printf(" %d",tem);
		cun[tem]=1;
		for(t=1;t<=i;t++){
			if(temp[tem][t]){
				if(cun[t]==0){
					queue[++front]=t;
				}
			}
		}
	}
		memset(cun, 0, sizeof(cun));
}
int main(){
	int j,k;
	int a,b;
	scanf("%d%d",&i,&j);
	for(k=1;k<=j;k++){
		scanf("%d%d",&a,&b);
		temp[a][b]=1;
		temp[b][a]=1;
	}
	dfs(0);
	printf("\n");
	memset(cun, 0, sizeof(cun));
	flag=0;
	bfs(0);
	printf("\n");
	scanf("%d",&k);
	cun[k]=1;
	flag=0;
	dfs(0);
	printf("\n");
	memset(cun, 0, sizeof(cun));
	flag=0;
	cun[k]=1;
	bfs(0);
	printf("\n");
	return 0;
} 

