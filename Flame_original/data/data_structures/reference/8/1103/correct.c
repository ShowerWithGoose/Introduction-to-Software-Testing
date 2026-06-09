#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>	
#include<ctype.h>
int map[114][114],visited[114],q[114];

void DFS(int v,int n){
	int i;
	visited[v]=1;
	printf("%d ",v);
	for(i=0;i<n;i++){
		if(map[v][i]==1){
			if(visited[i]==0){
				DFS(i,n);
			}
		}
	}
}
void BFS(int v,int n){
	int i=0,head=0,tail=0;
	memset(q,0,sizeof(q));
	visited[v]=1;
	q[0]=v;
	while(head<=tail){
		v=q[head];
		printf("%d ",v);
		for(i=0;i<n;i++){
			if(map[v][i]==1&&visited[i]==0){
				visited[i]=1;
				tail++;
				q[tail]=i;
				}
			}
		head++;
	}
}
int main(){
	int n,m,i,a,b,del;
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++){
		scanf("%d %d",&a,&b);
		map[a][b]=1;
		map[b][a]=1;
	}
	scanf("%d",&del);
	DFS(0,n); 
	printf("\n");
	memset(visited,0,sizeof(visited));
	BFS(0,n);
	memset(visited,0,sizeof(visited));
	printf("\n");
	for(i=0;i<n;i++){
		map[del][i]=0;
		map[i][del]=0;
	}
	
	DFS(0,n);printf("\n");
	memset(visited,0,sizeof(visited));
	BFS(0,n);printf("\n");
	memset(visited,0,sizeof(visited));
	return 0;
}

