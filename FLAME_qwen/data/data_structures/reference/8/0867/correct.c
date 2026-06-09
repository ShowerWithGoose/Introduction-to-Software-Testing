//
// Created by  on 2022-05-26.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int graph[101][101];
int visited[101];
int V, E;
int queue[101];
int tail = -1, front = 0,count = 0;

void dfs(int vnode, int vc) {
    visited[vnode] = 1;
    printf("%d ", vnode);
    for (int i = 0; i < vc; i++) {
        if (graph[vnode][i] == 1 && !visited[i]) {
            dfs(i, vc);
        }
    }
}

void bfs(int vc) {
    queue[++tail] = 0,count++;
    int cur;
    while(count){
        cur = queue[front++],count--;
        visited[cur] = 1;
        printf("%d ",cur);
        for (int i = 0; i < vc; i++) {
            if (graph[cur][i] == 1 && !visited[i]) {
                queue[++tail] = i,count++;
                visited[i] = 1;
            }
        }
    }
}

int main() {
    scanf("%d%d", &V, &E);
    for (int i = 0; i < E; i++) {
        int v1, v2;
        scanf("%d%d", &v1, &v2);
        graph[v1][v2] = 1;
        graph[v2][v1] = 1;
    }
    memset(visited, 0, 101 * sizeof(int));
    dfs(0, V);
    printf("\n");
    memset(visited, 0, 101 * sizeof(int));
    tail = -1, front = 0,count = 0;
    bfs(V);
    printf("\n");

    int delV;
    scanf("%d", &delV);
    for (int i = 0; i < V; i++) {
        graph[i][delV] = 0;
        graph[delV][i] = 0;
    }
    memset(visited, 0, 101 * sizeof(int));
    dfs(0, V);
    printf("\n");
    memset(visited, 0, 101 * sizeof(int));
    tail = -1, front = 0,count = 0;
    bfs(V);
    printf("\n");
}


