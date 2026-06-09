#include<stdio.h>
#define MAX 100
int Map[MAX][MAX]={0};
int Visited[MAX]={0};
void DFS(int Map[][MAX],int Visited[],int i,int n){
	int j;
	Visited[i]=1;
	printf("%d ",i);
	for(j=0;j<n;j++){
		if(Map[i][j]&&!Visited[j]){
			DFS(Map,Visited,j,n);
		}
	}
}
void BFS(int Map[][MAX],int Visited[],int i,int n){
	int j,r=0,h=0;
	int Queue[MAX]={0};
	printf("%d ",i);
	Visited[i]=1;
	for (j=0;j<n;j++){
		if(Map[i][j]&&!Visited[j]){
			Queue[r]=j;
			r++;
		}
	}
	while(h<r){
		if(!Visited[Queue[h]]){
			printf("%d ",Queue[h]);
			Visited[Queue[h]]=1;	
			
			for (j=0;j<n;j++){
				if(Map[Queue[h]][j]&&!Visited[j]){
					Queue[r]=j;
					r++;
				}
			}
		}
		h++;
	}
}
int main(){
	int n,p,a,b,i,j,h;
	scanf("%d %d",&n,&p);
	for(i=0;i<p;i++){
		scanf("%d %d",&a,&b);
		Map[a][b]=Map[b][a]=1;
	}
	scanf("%d",&a);
	
	h=0;
	DFS(Map,Visited,h,n);
	printf("\n");
	for(i=0;i<n;i++)
		Visited[i]=0;
	BFS(Map,Visited,h,n);
	printf("\n");
	for(i=0;i<n;i++)
		Visited[i]=0;

	for(i=0;i<n;i++){
		Map[a][i]=Map[i][a]=0;
	}
	if(a==0){
		h=1;
		DFS(Map,Visited,h,n);
		printf("\n");
		for(i=0;i<n;i++)
			Visited[i]=0;
		BFS(Map,Visited,h,n);
		printf("\n");
		for(i=0;i<n;i++)
			Visited[i]=0;
	}else{
		h=0;
		DFS(Map,Visited,h,n);
		printf("\n");
		for(i=0;i<n;i++)
			Visited[i]=0;
		BFS(Map,Visited,h,n);
		printf("\n");
		for(i=0;i<n;i++)
			Visited[i]=0;
	}
	return 0;
}




