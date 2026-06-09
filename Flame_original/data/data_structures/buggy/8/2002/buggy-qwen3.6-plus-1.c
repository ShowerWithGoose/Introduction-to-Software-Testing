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
    scanf("%d %d", &n, &n); // 读取顶点和边的数量 // @@ 错误：将顶点数n和边数m都读入到了变量n中，导致n的值被边数覆盖，后续遍历循环边界错误。应声明变量m并改为scanf("%d %d", &n, &m);

    // 初始化图
    memset(adjMatrix, 0, sizeof(adjMatrix));
    memset(visited, 0, sizeof(visited));
    
    // 读取图的边信息
    int u, v;
    for (int i = 0; i < n; i++) { // @@ 错误：读取边的循环次数应为输入的边数m，而不是顶点数n。应改为for (int i = 0; i < m; i++)
        scanf("%d %d", &u, &v);
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1; // 因为是无向图，所以需要添加两个方向的边
    }

    int j;
    scanf("%d", &j); // 读取要删除的顶点编号

    //printf("\nDFS before removal:\n");
    memset(visited, 0, sizeof(visited));
    dfs(0);

   // printf("\nBFS before removal:\n");
    memset(visited, 0, sizeof(visited));
    bfs(0);

    removeVertex(j);

    //printf("\nDFS after removal:\n");
    memset(visited, 0, sizeof(visited));
    dfs(0);

    //printf("\nBFS after removal:\n");
    memset(visited, 0, sizeof(visited));
    bfs(0);

    return 0;
}