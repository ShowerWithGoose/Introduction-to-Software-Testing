#include <stdio.h>
int g[105][105]={0};
int v_num,e_num;
int visited[105]={0};
void DFS(int x){
	printf("%d ",x);
	visited[x]=1;
	int i;
	for(i=0;i<v_num;i++){
		if(g[x][i] && !visited[i]){
			DFS(i);
		}
	}
}
int queue[1000];
int front=0,rear=-1;
void BFS(int x){
	int y,i; 
	printf("%d ",x);
	visited[x]=1;
	queue[++rear]=x;
	while(rear>=front){
		y=queue[front++];
		for(i=0;i<v_num;i++){
			if(g[y][i] && !visited[i]){
				printf("%d ",i);
				visited[i]=1;
				queue[++rear]=i;
			}
		}
	}
}
int main(){
	scanf("%d%d",&v_num,&e_num);
	int i,a,b;
	for(i=0;i<e_num;i++){
		scanf("%d%d",&a,&b);
		g[a][b]=g[b][a]=1;
	}
	DFS(0);
	memset(visited,0,105*sizeof(int));
	putchar('\n');
	BFS(0);
	memset(visited,0,105*sizeof(int));
	putchar('\n');
	int v;
	scanf("%d",&v);
	for(i=0;i<v_num;i++){
		g[v][i]=g[i][v]=0;
	}
	DFS(0);
	memset(visited,0,105*sizeof(int));
	putchar('\n');
	BFS(0);
	return 0;
}

