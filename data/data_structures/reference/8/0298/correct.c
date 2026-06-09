#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int graph[100][100];
int visit[100];
int queue[10000];
int front = 0, rear = -1;
void DFS(int v,int n){
	visit[v] = 1;
	printf("%d ", v);
	for(int i = 0; i < n; i++){
		if(graph[v][i] != 0 && visit[i] != 1)
			DFS(i, n);
	}
}
void BFS(int v, int n){
	visit[v] = 1;
	queue[++rear] = v;
	while(rear >= front){
		v = queue[front++];
		printf("%d ", v);
		for(int i = 0; i < n; i++){
			if(graph[v][i] != 0 && visit[i] != 1){
				visit[i] = 1;
				queue[++rear] = i;
			}
		}
	}
}
int main(){
	int n, link, del;
	scanf("%d%d", &n, &link);
	while(link--){
		int a, b;
		scanf("%d%d", &a, &b);
		graph[a][b] = 1;
		graph[b][a] = 1;
	}
	scanf("%d", &del);
	DFS(0, n); puts("");
	memset(visit, 0, 100);
	BFS(0, n); puts("");
	memset(visit, 0, 100);
	for(int i = 0; i < n; i++)
	graph[i][del] = 0, graph[del][i] = 0;
	DFS(0, n); puts("");
	memset(visit, 0, 100);
	BFS(0, n);
	return 0;
}



