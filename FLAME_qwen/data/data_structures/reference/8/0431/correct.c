#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int visit[110], graph[110][110];
void BFS(int graph[][110], int i, int n){
    int Queue[110], rear = -1, front = 0, nownum = i, j;   
    Queue[(++rear) % 110] = i;
    while (front <= rear) {
        nownum = Queue[(front++) % 110];
        if (!visit[nownum])
            printf("%d ", nownum);
        visit[nownum] = 1;
        for (j = 0; j < n; j++) {
            if (graph[j][nownum] == 1 && visit[j] == 0) {
                Queue[(++rear) % 110] = j;
            }
        }
    }
}
void DFS(int graph[][110], int i, int n) {
	int j;
    visit[i] = 1;
    printf("%d ", i);
    for (j = 0; j < n; j++) {
        if (!visit[j] && graph[i][j] == 1) {
            DFS(graph, j, n);
        }
    }
}
int main(){
	int n, e, i, p, q, del;
	scanf("%d%d", &n, &e);
	for(i = 0; i < e; i++){
		scanf("%d%d", &p, &q);
		graph[p][q] = graph [q][p] = 1;
	}
	scanf("%d", &del);
	DFS(graph, 0, n);
	printf("\n");
	memset(visit, 0, sizeof(visit));
	BFS(graph, 0, n);
	printf("\n");
	for(i = 0; i < n; i++){
		graph[del][i] = graph[i][del] = 0;
	}
	memset(visit, 0, sizeof(visit));
	DFS(graph, 0, n);
	printf("\n");
	memset(visit, 0, sizeof(visit));
	BFS(graph, 0, n);
	printf("\n");
}

