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

    DFS(109); // @@ The argument 109 is used as a dummy value to indicate "before deletion". Inside DFS, this value is used to mark a vertex as visited. Since vertex indices are 0 to n-1 (max 99), index 109 is out of bounds for the `visited` array (size 110, but logically only 0-99 are valid graph vertices). More importantly, the logic inside DFS ignores this argument for traversal start (always starts at 0) but uses it to reset visited status. If `point` is 109, `visited[109]=1` accesses memory outside the logical graph vertices, which is harmless but semantically confusing. However, the real issue is likely in how the "deletion" is handled.
    BFS(109); // @@ Same as above. The BFS function also takes `point` to mark as visited initially.
    DFS(del); // @@ This call is intended to perform DFS after deleting vertex `del`. However, the current implementation of `DFS` and `BFS` does not actually remove the vertex from the graph structure `G`. It only marks the vertex `del` as visited at the beginning (`visited[point] = 1`). This prevents the traversal from *starting* at `del`, but if `del` is encountered as a neighbor during traversal from other nodes, the check `visited[i] == 0` will prevent visiting it. This effectively simulates deletion for traversal purposes.
    BFS(del); // @@ Same as above.

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
    visited[point] = 1; // @@ If point is 109, this accesses visited[109]. If point is `del`, it marks `del` as visited, effectively skipping it.

    printf("0 "); // @@ Always prints 0 first. This assumes 0 is never deleted (problem statement says "The vertex to be deleted is not vertex 0").
    visited[0] = 1; // @@ Marks 0 as visited.
    DFS_search(0); // @@ Starts search from 0.

    printf("\n");
}
void DFS_search(int p) {
    for (int i = 0; i < n; i++) {
        if (i == p)
            continue;
        if (visited[i] == 0 && G[i][p] == 1) { // @@ Checks if vertex i is unvisited and connected to p.
            printf("%d ", i);
            visited[i] = 1;
            DFS_search(i);

        }
    }
}
void BFS(int point) {
    for (int i = 0; i < n; i++)
        visited[i] = 0;
    visited[point] = 1; // @@ Marks the 'deleted' vertex or dummy vertex as visited.

    visited[0] = 1; // @@ Marks 0 as visited.
    printf("0 "); // @@ Always prints 0 first.
    queue[0] = 0; // @@ Enqueues 0.
    int rear = 0, i = 0, k = 0;
    do {
        i = queue[k]; // @@ Dequeues vertex i.
        for (int j = 0; j < n; j++) {
            if (G[i][j] == 1 && visited[j] == 0) { // @@ Checks neighbors. If j is the deleted vertex, visited[j] was set to 1 earlier, so it won't be enqueued/printed. This correctly simulates deletion.
                printf("%d ", j);
                visited[j] = 1;
                queue[++rear] = j;
            }
        }
        k++;

    } while (k != rear); // @@ Continues until queue is empty. Note: if rear < k initially or logic error, this might loop incorrectly. Standard BFS queue logic usually uses front/rear indices. Here k acts as front. If queue is empty, k==rear.

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