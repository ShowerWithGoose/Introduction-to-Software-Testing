#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 110

int n, e;
int del;

int G[MAXSIZE][MAXSIZE] = {{0}};
int visited[MAXSIZE] = {0};
int queue[MAXSIZE] = {-1};

void clear();
void DFS(int point);
void DFS_search(int p);
void BFS(int point);

int main() {
    clear();

    scanf("%d%d", &n, &e);

    for (int i = 0; i < e; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        G[a][b] = 1;
        G[b][a] = 1;
    }

    scanf("%d", &del);

    DFS(109); // @@ The parameter 109 is used as a sentinel to indicate no deletion, but this is incorrect because the graph only has vertices 0 to n-1. The function should be called with a value that is not a valid vertex (e.g., n or -1) to avoid marking a non-existent vertex as visited. Using 109 may cause out-of-bounds access if n is small, though here it works accidentally. The intended logic is to pass a vertex that is not in the graph (like n) to skip marking any vertex as deleted.
    BFS(109); // @@ Same issue as above: the parameter 109 is used as a sentinel, but it should be a value outside the valid vertex range (e.g., n) to avoid marking a non-existent vertex as visited.
    DFS(del);
    BFS(del);

    return 0;
}
void clear() {
    for (int i = 0; i < MAXSIZE; i++) {
        for (int j = 0; j < MAXSIZE; j++) {
            G[i][j] = 0;
        }
    }
}
void DFS(int point) {
    for (int i = 0; i < n; i++)
        visited[i] = 0;
    visited[point] = 1; // @@ This marks the deleted vertex (or sentinel) as visited, which is correct for deletion, but when point is 109 (sentinel), it marks an invalid vertex as visited, which is unnecessary but harmless. However, the logic is flawed because the sentinel should not be a valid vertex index.

    printf("0 ");
    visited[0] = 1;
    DFS_search(0);

    printf("\n");
}
void DFS_search(int p) {
    for (int i = 0; i < n; i++) {
        if (i == p)
            continue;
        if (visited[i] == 0 && G[i][p] == 1) {
            printf("%d ", i);
            visited[i] = 1;
            DFS_search(i);

        }
    }
}
void BFS(int point) {
    for (int i = 0; i < n; i++)
        visited[i] = 0;
    visited[point] = 1; // @@ Same issue as in DFS: marking the sentinel (109) as visited is unnecessary and conceptually wrong.

    visited[0] = 1;
    printf("0 ");
    queue[0] = 0;
    int rear = 0, i = 0, k = 0;
    do {
        i = queue[k];
        for (int j = 0; j < n; j++) {
            if (G[i][j] == 1 && visited[j] == 0) {
                printf("%d ", j);
                visited[j] = 1;
                queue[++rear] = j;
            }
        }
        k++;

    } while (k != rear);

    /*for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (visited[j] == 0 && G[i][j] == 1) {
                printf("%d ", j);
                visited[j] = 1;
            }
        }
        visited[i] = 1;
    }*/


    printf("\n");
}