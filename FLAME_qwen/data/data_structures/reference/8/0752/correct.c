#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
int n;
int e[100][100];
int v[100];
void DFS(int vertex){
	v[vertex]=1;
	printf("%d ",vertex);
	for(int i=0;i<n;i++){
		if(e[vertex][i]&&v[i]==0){
			DFS(i);
		}
	}
}
void BFS(){
	int queue[n];
	int top=-1,rear=0;
	queue[++top]=0;
	v[0]=1;
	while(rear<=top){
		for(int i=0;i<n;i++){
			if(e[queue[rear]][i]&&v[i]==0){
				queue[++top]=i;
				v[i]=1;			
		    }
		}
		rear++;
	}
	for(int i=0;i<=top;i++){
		printf("%d ",queue[i]);
	}
	printf("\n");
}
int main(){
	int edge;
	scanf("%d%d",&n,&edge);
	for(int i=0;i<edge;i++){
		int start,end;
		scanf("%d%d",&start,&end);
		e[start][end]=1;
		e[end][start]=1;
	}
	int deleteVer;
	scanf("%d",&deleteVer);
	
	memset(v,0,sizeof(v));
	DFS(0);
	printf("\n");
	memset(v,0,sizeof(v));
	BFS();
	for(int i=0;i<n;i++){
		e[deleteVer][i]=0;
		e[i][deleteVer]=0;
	}
	memset(v,0,sizeof(v));
	DFS(0);
	printf("\n");
	memset(v,0,sizeof(v));
	BFS();
	return 0;
}



















