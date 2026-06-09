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

    DFS(109); // @@ [Passing an invalid vertex index (109) to mark "no deletion" is incorrect logic. Should pass a value that doesn't interfere, but the real issue is that DFS() uses this parameter to set visited[point]=1, which corrupts traversal when point >= n. For the first two traversals (before deletion), nothing should be marked as deleted, so visited[point] = 1 should not happen for an out-of-range point.]
    BFS(109); // @@ [Same issue as above: passing 109 causes visited[109] = 1, which is outside the graph and unnecessary, but more critically, it doesn't simulate "no deletion". The correct approach is to not mark any extra vertex as visited before the first traversals.]
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
    visited[point] = 1; // @@ [If 'point' is >= n (like 109), this writes beyond the intended range of relevant vertices (0 to n-1). While it may not crash due to MAXSIZE=110, it's logically wrong. More importantly, for the "before deletion" case, we should NOT mark any vertex as visited except during traversal. This line incorrectly marks an irrelevant or deleted vertex before traversal starts.]

    printf("0 "); // @@ [Hardcoding the start vertex "0" here breaks the general DFS logic. The traversal should start at 0, but the printing should be done inside DFS_search or in a unified way. However, the bigger issue is that if vertex 0 were the deleted one (which it isn't per problem constraints), this would be wrong—but the real bug is that this assumes 0 is always first, yet the recursive call may not handle ordering correctly. But the critical error is in how 'point' is used above.]
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
    visited[point] = 1; // @@ [Same fundamental flaw as in DFS: marking visited[point] = 1 where point may be 109 (invalid) or 'del'. For the "before deletion" calls, point=109 causes an out-of-bounds (though safe) write, but logically, no vertex should be pre-marked as visited except during traversal. For "after deletion", marking visited[del]=1 is correct—but the same function is used for both cases with flawed parameter interpretation.]

    visited[0] = 1;
    printf("0 "); // @@ [Same issue as in DFS: hardcoding the output of "0 " assumes 0 is always the start and always present, which is true per problem constraints, but the real issue is that the BFS loop logic may not respect ascending order of neighbors because it iterates i from 0 to n-1 in the outer loop but the inner loop also goes from 0 to n-1—however, since adjacency is checked via G[i][j], and j increases, it actually does visit in ascending order. So this may not be the primary bug. The main bug remains the misuse of 'point'.]
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

    } while (k != rear); // @@ [This loop condition is incorrect. It should run while the queue is not empty, but 'rear' is the last enqueued index, and 'k' is the current dequeue index. The condition k != rear fails when only one element is in the queue (k=0, rear=0 initially after enqueueing 0), so the loop body never runs. However, in the test case, after printing "0 ", the loop should process neighbors of 0. But because k=0 and rear=0, the loop condition (0 != 0) is false, so it exits immediately. This causes BFS to only print "0 " and miss the rest. But wait—the test output shows "0 1 2" for BFS before deletion, so this suggests the loop did run. Let's check: queue[0]=0, rear=0, k=0. Then do-while runs once: i=queue[0]=0, then j=0..2: finds j=1 and j=2 (since G[0][1]=1, G[0][2]=1), prints "1 2", sets visited, and queue[1]=1, queue[2]=2, so rear becomes 2. Then k increments to 1. Now k=1, rear=2 → loop continues. Next iteration: i=queue[1]=1, checks neighbors: 0 (visited), 2 (not visited? But in full graph, G[1][2]=1, and if not visited, prints 2 again! But expected output is "0 1 2", not "0 1 2 2". However, in the test input, after printing 0, then 1 and 2 are printed from node 0, so when processing node 1, 2 is already visited. So it works. But the real bug is elsewhere.]

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