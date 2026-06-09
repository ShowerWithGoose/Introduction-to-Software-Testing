#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int Visited[110];
int V[110][110];
void DFS(int n,int a);
void re(int n);
void BFS(int n);
int main(){
	int n,e,v1,v2,i;
	scanf("%d %d",&n,&e);
	for(i=0;i<e;i++){
		scanf("%d %d",&v1,&v2);
		V[v1][v2]=V[v2][v1]=1;
	}
	DFS(n,0);
	printf("\n");
	re(n);
	BFS(n);
	printf("\n");
	re(n);
	scanf("%d",&v1);
	for(i=0;i<n;i++){
		V[v1][i]=V[i][v1]=0;
	}
	Visited[v1]=1;
	DFS(n,0);
	printf("\n");
	re(n);
	Visited[v1]=1;
	BFS(n);
	return 0;
	
}
void DFS(int n,int a){
	int i;
	if(Visited[a]==0){
		Visited[a]=1;
		printf("%d ",a);
		for(i=0;i<n;i++){
			if(V[a][i]==1){
				DFS(n,i);
			}
		}
	}
}
void BFS(int n){
	int queue[110],sta=0,end=1,a,i;
	queue[0]=0;
	Visited[0]=1;
	while(sta<end){
		a=queue[sta];
		printf("%d ",a);
		sta++;
		for(i=0;i<n;i++){
			if(V[a][i]==1&&Visited[i]==0){
				queue[end++]=i;
				Visited[i]=1;
			}
		}
	}
}
void re(int n){
	int i;
	for(i=0;i<n;i++){
		Visited[i]=0;
	}
}

