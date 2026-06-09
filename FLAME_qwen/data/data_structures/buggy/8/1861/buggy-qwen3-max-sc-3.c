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

    DFS(109); // @@ [Calling DFS with an invalid vertex index 109 instead of performing traversal before deletion. Should call DFS with logic to traverse from 0 without marking any irrelevant vertex as visited.]
    BFS(109); // @@ [Same issue as above: BFS called with invalid vertex 109, which marks visited[109]=1 but 109 is out of graph range (0 to n-1). This corrupts logic and skips actual traversal before deletion.]
    DFS(del); // @@ [This attempts to simulate "after deletion" by marking 'del' as visited, but it doesn't actually remove edges connected to 'del'. Also, the first two calls (with 109) were supposed to be "before deletion", but they are broken.]
    BFS(del); // @@ [Same issue: does not actually delete the vertex from the graph structure; only marks it visited, which interferes with traversal order and correctness.]

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
    visited[point] = 1; // @@ [If 'point' >= n (like 109), this writes outside valid visited[] range (0 to n-1), causing undefined behavior. Even if within bounds, marking an arbitrary 'point' as visited before traversal from 0 is logically wrong unless simulating deletion—but here it's misused.]

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
    visited[point] = 1; // @@ [Same out-of-bounds or logically incorrect marking of 'point' as visited. For BFS before deletion, no vertex should be pre-marked except during traversal.]

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

    } while (k != rear); // @@ [Loop condition is incorrect: when queue has one element, k=0, rear=0, loop doesn't run. Also, after enqueueing neighbors, rear increases, but k increments each time. The condition k != rear fails to process all nodes in many cases (e.g., linear graph). Should use while (k <= rear).]

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