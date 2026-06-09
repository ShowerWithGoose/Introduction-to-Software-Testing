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

    DFS(109); // @@ [Calling DFS with an invalid vertex index (109) instead of printing traversal before deletion. Should call DFS(0) or similar to indicate "before deletion". Also, the parameter 'point' is misused—it should not be used to mark deletion status.]
    BFS(109); // @@ [Same issue as above: passing 109 (invalid vertex) to BFS instead of performing traversal before deletion.]
    DFS(del); // @@ [This attempts to perform DFS after deletion, but the graph hasn't been modified yet—vertex 'del' is still present in G[]. Also, DFS() uses 'point' to set visited[point]=1, which marks an invalid or unintended vertex as visited.]
    BFS(del); // @@ [Same issue: BFS called with 'del', but graph not actually modified, and visited[del] is incorrectly marked.]

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
    visited[point] = 1; // @@ [If 'point' is 109 or 'del' (which may be >= n), this writes outside the valid range of 'visited' array (size MAXSIZE=110, but n <= 100). However, more critically, marking visited[point]=1 is meaningless when point is not part of the current graph (e.g., 109). Also, this interferes with traversal starting at 0.]

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
    visited[point] = 1; // @@ [Same problem: if 'point' is 109 or even 'del' (if del >= n), this is out-of-bounds. But more importantly, it's logically wrong—should not mark an arbitrary 'point' as visited before BFS from 0.]

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

    } while (k != rear); // @@ [Loop condition is incorrect. It should run while front <= rear (or k <= rear). As written, if only one node (0) is in queue, k=0, rear=0, loop runs once, then k=1, and stops—but that's correct for single node. However, if more nodes are added, say rear becomes 2, then k goes 0→1→2, and stops when k==2, but node at index 2 was never processed. So it misses the last node.]

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