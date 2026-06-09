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

    DFS(109); // @@ Error: The parameter 109 is used as the "point" to mark as visited, but this is incorrect. The function should not mark vertex 109 (which is out of range for n ≤ 100) as visited. Instead, it should only mark vertex 0 as visited and start traversal from 0. This causes the DFS to incorrectly skip vertex 0 and potentially other vertices.
    BFS(109); // @@ Error: Same issue as above. The parameter 109 is used incorrectly, causing the BFS to mark an invalid vertex as visited and potentially skip vertex 0.
    DFS(del); // @@ Error: The function marks the deleted vertex as visited, but the deleted vertex should be removed from the graph (edges set to 0) and not visited. This causes the traversal to incorrectly skip the deleted vertex's neighbors and may produce wrong sequences.
    BFS(del); // @@ Error: Same issue as above. The deleted vertex is marked as visited, which is incorrect. The graph should have the deleted vertex's edges removed, but the vertex itself should not be visited or traversed.

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
    visited[point] = 1; // @@ Error: This marks the parameter 'point' (which could be the deleted vertex or an invalid vertex) as visited, but the traversal should start from vertex 0. The deleted vertex should not be visited at all; its edges should be removed from the graph before traversal.

    printf("0 ");
    visited[0] = 1;
    DFS_search(0);

    printf("\n");
}
void DFS_search(int p) {
    for (int i = 0; i < n; i++) {
        if (i == p) // @@ Error: This condition skips the current vertex itself, but it is unnecessary and may cause issues if the graph has self-loops (which it shouldn't). More importantly, it does not handle the deletion of the vertex; the deleted vertex's edges should have been removed from G, so this check is redundant and could cause incorrect behavior if the vertex is not properly removed.
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
    visited[point] = 1; // @@ Error: Same issue as in DFS. The parameter 'point' (which could be the deleted vertex or an invalid vertex) is marked as visited, but the traversal should start from vertex 0. The deleted vertex should not be visited.

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