#include <stdio.h>
#include <stdlib.h>

int E[100][100];

void addEdge(int u, int v){
	E[u][v] = E[v][u] = 1;
}

int visited[100];
void initVisit(int n){
	for(int i=0; i<n; i++){
		visited[i] = 0;
	}
}


void DFS(int u, int n){
	printf("%d ", u);
	visited[u] = 1;
	for(int v=0; v<n; v++){
		if(E[u][v] && !visited[v])
			DFS(v, n);
	}
}

void BFS(int s, int n){
	int queue[100], front=0, end=0;
	queue[end++] = s;
	visited[s] = 1;
	while(front != end){
		int u = queue[front++];
		printf("%d ", u);
		
		for(int v=0; v<n; v++){
			if(E[u][v] && !visited[v]){
				queue[end++] = v;
				visited[v] = 1;
			}
		}
	}
}

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	
	int u, v;
	for(int i=0; i<m; i++){
		scanf("%d%d", &u, &v);
		addEdge(u, v);
	}
	initVisit(n); DFS(0, n);	printf("\n");
	initVisit(n); BFS(0, n);	printf("\n");
	
	int k;
	scanf("%d", &k);
	for(int v=0; v<n; v++){
		E[k][v] = E[v][k] = 0;
	}
	
	initVisit(n); DFS(0, n);	printf("\n");
	initVisit(n); BFS(0, n);	printf("\n");
	
	
	return 0;
}

