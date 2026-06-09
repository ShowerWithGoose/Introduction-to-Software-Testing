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

    DFS(109); // @@ [Calling DFS with an invalid vertex 109 instead of printing traversal before deletion. Should call DFS(0) or similar without marking invalid vertex as visited.]
    BFS(109); // @@ [Same issue: passing 109 to BFS which marks it as visited even though it's outside valid range [0, n-1], causing incorrect behavior.]
    DFS(del); // @@ [This is intended to simulate deletion by marking 'del' as visited, but the approach is flawed because it doesn't actually remove edges involving 'del'. Also, DFS already prints "0 " unconditionally, which may be wrong if 0 is affected (but per problem, del != 0). However, the bigger issue is that the graph structure isn't modified—only marking 'del' as visited doesn't prevent traversal through its neighbors correctly in all cases.]
    BFS(del); // @@ [Same flaw as above: using visited[del]=1 to simulate deletion is insufficient; edges to 'del' should be removed from adjacency matrix.]

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
    visited[point] = 1; // @@ [If 'point' >= n (like 109), this writes out of bounds of 'visited' array (size MAXSIZE=110, but n <= 100). However, since MAXSIZE=110 and point=109, it's within array bounds but logically wrong because vertex 109 doesn't exist in graph of size n.]

    printf("0 "); // @@ [Unconditionally prints "0 ", assuming start vertex is always 0, which is correct per problem, but if 0 were deleted (which it won't be per constraints), this would be wrong. However, main issue is that this print happens even when simulating after deletion, but the real bug is in how deletion is simulated.]
    visited[0] = 1;
    DFS_search(0);

    printf("\n");
}
void DFS_search(int p) {
    for (int i = 0; i < n; i++) {
        if (i == p)
            continue;
        if (visited[i] == 0 && G[i][p] == 1) { // @@ [Condition checks G[i][p] but should check G[p][i]; however, since graph is undirected and symmetric, this is okay. But more importantly, when simulating deletion by marking 'del' as visited, this prevents visiting 'del', but does not prevent traversing edges that connect through 'del' indirectly? Actually no—if 'del' is marked visited, it won't be entered, but its neighbors can still be reached via other paths. However, the real issue is that the graph structure isn't updated, so during traversal, edges to 'del' are still present, but since 'del' is marked visited, they are ignored—which is acceptable simulation. BUT: the initial calls with point=109 corrupt visited array.]
            printf("%d ", i);
            visited[i] = 1;
            DFS_search(i);

        }
    }
}
void BFS(int point) {
    for (int i = 0; i < n; i++)
        visited[i] = 0;
    visited[point] = 1; // @@ [Same out-of-logical-bounds issue as in DFS: marking non-existent vertex 109 as visited.]

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

    } while (k != rear); // @@ [Loop condition is incorrect: when rear increments, k may never catch up if multiple nodes are added. For example, if starting with 0, and 0 connects to 1 and 2, then rear becomes 2, k starts at 0, then k=1, then k=2—but loop stops when k==rear, missing processing of node at index 2. Should be while(k <= rear).]

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