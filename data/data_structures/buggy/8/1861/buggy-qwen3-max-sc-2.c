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

    DFS(109); // @@ [Calling DFS with an invalid vertex index (109) which is out of range [0, n-1]; should call DFS before deletion without marking any irrelevant vertex as visited]
    BFS(109); // @@ [Same issue: passing 109 to BFS marks an out-of-bound vertex as visited, corrupting traversal logic]
    DFS(del); // @@ [After deletion, the graph structure hasn't been modified (edges to 'del' not removed), and DFS still uses original 'n'; also, passing 'del' causes it to be marked visited even though it should be excluded]
    BFS(del); // @@ [Same as above: BFS called with 'del', which incorrectly marks deleted vertex as visited and doesn't reflect actual graph after deletion]

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
    visited[point] = 1; // @@ [If 'point' >= n (like 109), this writes beyond array bounds; even if in range, marking a non-existent or deleted vertex as visited breaks traversal]

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
    visited[point] = 1; // @@ [Same out-of-bounds or logically incorrect marking of 'point' (e.g., 109 or 'del') as visited]

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

    } while (k != rear); // @@ [Loop condition may cause infinite loop or premature termination; standard BFS uses 'front <= rear' with separate front/rear pointers]

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