#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 300
int n, m, mat[MAX][MAX], visited[MAX], que[MAX];
int flag;

void DFS(int);
void BFS(int);

int main() {
    int x, y;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &x, &y);
        mat[x][y] = 1;
        mat[y][x] = 1;
    }
    flag = 0;
    DFS(0);
    printf("\n");

    memset(visited, 0, sizeof(visited));
    flag = 0;
    BFS(0);
    printf("\n");

    int k;
    scanf("%d", &k);
    visited[k] = 1;
    flag = 0;
    DFS(0);
    printf("\n");

    memset(visited, 0, sizeof(visited));
    visited[k] = 1;
    flag = 0;
    BFS(0);
    printf("\n");
    return 0;
}

void DFS(int v) {
    if (!flag)
        printf("%d", v), flag = 1;
    else
        printf(" %d", v);
    visited[v] = 1;  //已访问
    for (int i = 0; i < n; i++)
        if (mat[v][i] && !visited[i]) {
            DFS(i);
        }
}

void BFS(int t) {
    que[1] = t;
    int l = 1, r = 1, i;
    while (l <= r) {
        int x = que[l];
        l++;
        if (visited[x])
            continue;
        if (!flag)
            printf("%d", x), flag = 1;
        else
            printf(" %d", x);
        visited[x] = 1;
        for (i = 1; i <= n; i++)
            if (mat[x][i]) {
                if (!visited[i])
                    que[++r] = i;
            }
    }
    memset(visited, 0, sizeof(visited));
}

