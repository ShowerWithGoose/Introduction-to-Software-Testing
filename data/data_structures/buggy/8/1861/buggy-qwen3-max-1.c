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

    DFS(109); // @@ [Calling DFS with an invalid vertex index 109 instead of the correct deletion flag or no argument; this causes visited[109]=1 which is out-of-bound and logically wrong. Should perform traversal before deletion without marking any irrelevant vertex.]
    BFS(109); // @@ [Same issue as above: passing 109 to BFS marks visited[109]=1, which is beyond graph size and corrupts logic. Also, BFS should start from 0 without pre-marking unrelated vertices.]
    DFS(del); // @@ [Passing 'del' to DFS marks visited[del]=1 before traversal, effectively deleting it, but the function also prints "0 " unconditionally even if 0 is not connected after deletion (though problem states graph remains connected). However, the bigger issue is inconsistent design: first two calls use dummy 109, next two use del — but all should just control whether 'del' is removed from graph structure, not via marking visited.]
    BFS(del); // @@ [Same as above: using 'del' as argument to mark it visited before traversal simulates deletion, but this approach fails because adjacency matrix still contains edges to 'del', leading to incorrect traversal behavior. Proper way is to zero out rows/cols of 'del' in G before second pair of traversals.]

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
    visited[point] = 1; // @@ [If 'point' >= n (like 109), this writes outside array bounds, causing undefined behavior. Even if within bounds, marking an arbitrary 'point' as visited before traversal distorts the DFS result.]

    printf("0 "); // @@ [Unconditionally prints "0 " even if vertex 0 is not the start or has been deleted (but per problem, 0 is never deleted). However, if the graph were disconnected (which it isn't per spec), this would be wrong. Main issue: this assumes 0 is always first, but doesn't check if 0 is accessible — though problem guarantees connectivity. Still, printing before checking visit status is risky.]
    visited[0] = 1;
    DFS_search(0);

    printf("\n");
}
void DFS_search(int p) {
    for (int i = 0; i < n; i++) {
        if (i == p)
            continue; // @@ [Unnecessary: self-loop check, but graph has no self-loops per input. Not harmful, but redundant.]
        if (visited[i] == 0 && G[i][p] == 1) { // @@ [Correctly checks adjacency and unvisited status, but note: G[i][p] is same as G[p][i], so okay. However, neighbors should be visited in ascending order — this loop does that since i goes from 0 to n-1. So this part is actually correct.]
            printf("%d ", i);
            visited[i] = 1;
            DFS_search(i);

        }
    }
}
void BFS(int point) {
    for (int i = 0; i < n; i++)
        visited[i] = 0;
    visited[point] = 1; // @@ [Same out-of-bounds risk as in DFS when point=109. Also, logically flawed: simulating deletion by marking visited instead of modifying graph structure.]

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

    } while (k != rear); // @@ [Loop condition is incorrect: when k==rear, it stops, but if multiple nodes are enqueued, rear increases, and k may never catch up properly. For example, if rear=2 and k=2, loop stops, but if more nodes were added earlier, they might not be processed. Standard BFS uses while(front <= rear) with separate front/rear. This implementation uses k as front and rear as tail, but condition k != rear fails when queue has one element (k=0, rear=0 → loop doesn't run). Actually, initial state: queue[0]=0, rear=0, k=0 → do-while runs once, then k=1, rear may be >0. But if no neighbors, k=1, rear=0 → k>rear, loop stops. However, if graph has more than one node, this may terminate early. Example: n=3, edges (0-1),(0-2). First iteration: i=0, enqueue 1 (rear=1), enqueue 2 (rear=2). Then k=1. Next: i=queue[1]=1, process neighbors → maybe enqueue nothing. k=2. Now k=2, rear=2 → loop stops. But node 2 hasn't been processed! So BFS misses processing node 2's neighbors. Thus, condition should be while(k <= rear), not do-while with k != rear.]

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