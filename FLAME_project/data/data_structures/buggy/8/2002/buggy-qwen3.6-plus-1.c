#define _CRT_SECURE_NO_WARNINGS



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 100

int n; // 顶点数量
int adjMatrix[MAX_VERTICES][MAX_VERTICES]; // 邻接矩阵表示图
int visited[MAX_VERTICES]; // 访问标记数组

// 深度优先搜索辅助函数
void dfs(int v) {
    visited[v] = 1;
    printf("%d ", v);
    for (int i = 0; i < n; i++) {
        if (adjMatrix[v][i] && !visited[i]) {
            dfs(i);
        }
    }
}

// 广度优先搜索辅助函数
void bfs(int v) {
    int queue[MAX_VERTICES], front = 0, rear = 0;
    queue[rear++] = v;
    visited[v] = 1;
    while (front != rear) {
        int current = queue[front++];
        printf("%d ", current);
        for (int i = 0; i < n; i++) {
            if (adjMatrix[current][i] && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}


// 删除顶点
void removeVertex(int v) {
    for (int i = 0; i < n; i++) {
        adjMatrix[v][i] = 0;
        adjMatrix[i][v] = 0;
    }
}

int main() {
    int m; // @@ The variable for number of edges was missing, and 'n' was incorrectly used to store both vertex count and edge count due to scanf("%d %d", &n, &n). A separate variable 'm' is needed.
    scanf("%d %d", &n, &m); // @@ The original code read into &n twice, overwriting the vertex count with the edge count. It should read into &n and &m.

    // 初始化图
    memset(adjMatrix, 0, sizeof(adjMatrix));
    memset(visited, 0, sizeof(visited));
    
    // 读取图的边信息
    int u, v;
    for (int i = 0; i < m; i++) { // @@ The loop condition was using 'n' (vertex count) instead of 'm' (edge count), causing incorrect number of iterations for reading edges.
        scanf("%d %d", &u, &v);
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1; // 因为是无向图，所以需要添加两个方向的边
    }

    int j;
    scanf("%d", &j); // 读取要删除的顶点编号

    //printf("\nDFS before removal:\n");
    memset(visited, 0, sizeof(visited));
    dfs(0);
    printf("\n"); // @@ Missing newline after DFS output. The expected output format requires each traversal sequence on a new line.

   // printf("\nBFS before removal:\n");
    memset(visited, 0, sizeof(visited));
    bfs(0);
    printf("\n"); // @@ Missing newline after BFS output. The expected output format requires each traversal sequence on a new line.

    removeVertex(j);

    //printf("\nDFS after removal:\n");
    memset(visited, 0, sizeof(visited));
    dfs(0);
    printf("\n"); // @@ Missing newline after DFS output. The expected output format requires each traversal sequence on a new line.

    //printf("\nBFS after removal:\n");
    memset(visited, 0, sizeof(visited));
    bfs(0);
    printf("\n"); // @@ Missing newline after BFS output. Although it's the last line, consistent formatting is good, and often tests expect a trailing newline.

    return 0;
}