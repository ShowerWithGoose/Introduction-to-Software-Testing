//
// Created by  on 2022-05-26.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int vertex[101][101];
int flag[101];
int V, E;
int queue[101];
int rear = -1, front = 0,count = 0;

void dfs(int n, int V) {
    flag[n] = 1;
    printf("%d ", n);
    for (int i = 0; i < V; i++) {
        if (vertex[n][i] == 1 && !flag[i]) {
            dfs(i, V);
        }
    }
}

void bfs(int V) {
    queue[++rear] = 0,count++;
    int cur;
    while(count){
        cur = queue[front++],count--;
        flag[cur] = 1;
        printf("%d ",cur);
        for (int i = 0; i < V; i++) {
            if (vertex[cur][i] == 1 && !flag[i]) {
                queue[++rear] = i,count++;
                flag[i] = 1;
            }
        }
    }
}

int main() {
    scanf("%d%d", &V, &E);
    for (int i = 0; i < E; i++) {
        int v1, v2;
        scanf("%d%d", &v1, &v2);
        vertex[v1][v2] = 1;
        vertex[v2][v1] = 1;
    }
    memset(flag, 0, 101 * sizeof(int));
    dfs(0, V);
    printf("\n");
    memset(flag, 0, 101 * sizeof(int));
    rear = -1, front = 0,count = 0;
    bfs(V);
    printf("\n");

    int drop_v;
    scanf("%d", &drop_v);
    for (int i = 0; i < V; i++) {
        vertex[i][drop_v] = 0;
        vertex[drop_v][i] = 0;
    }
    memset(flag, 0, 101 * sizeof(int));
    dfs(0, V);
    printf("\n");
    memset(flag, 0, 101 * sizeof(int));
    rear = -1, front = 0,count = 0;
    bfs(V);
    printf("\n");
}


