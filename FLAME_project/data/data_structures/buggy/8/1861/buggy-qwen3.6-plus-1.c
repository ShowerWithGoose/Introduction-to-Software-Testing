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

    DFS(109); // @@ The argument 109 is used as a marker to indicate traversal before deletion, but inside DFS, `visited[point] = 1` sets visited[109]=1 which is out of bounds for the logical graph size and unnecessary. More importantly, the logic for "before deletion" should simply traverse all nodes. The current implementation hardcodes printing "0 " and starting from 0, which is correct for the start node, but the `point` argument is misused.
    BFS(109); // @@ Similar to DFS, 109 is passed. Inside BFS, `visited[point] = 1` accesses visited[109], which is potentially out of bounds if MAXSIZE logic isn't careful, but mainly it's semantically confusing. The real issue is how deletion is handled in the subsequent calls.
    DFS(del); // @@ This call attempts to handle the "after deletion" case. Inside DFS, `visited[point] = 1` marks the deleted node as visited so it won't be traversed. However, the adjacency matrix G still contains edges to/from `del`. The DFS_search function checks `G[i][p] == 1`. If `del` is not 0, this works partially because `del` is marked visited. But if `del` was 0, it would fail (problem says del != 0). The critical error is that the adjacency matrix G is not modified to remove edges connected to `del`. While marking `del` as visited prevents visiting it, the traversal logic might still behave incorrectly if not careful. Actually, looking closely at DFS: it prints "0 ", marks 0 visited. Then calls DFS_search(0). DFS_search iterates neighbors. If a neighbor is `del`, `visited[del]` is 1 (set in DFS entry), so it skips it. This seems logically okay for DFS *if* `del` is not 0.
    BFS(del); // @@ Similar to DFS, `del` is marked visited. BFS starts at 0. It queues 0. Then processes neighbors. If a neighbor is `del`, `visited[del]` is 1, so it skips it. This also seems logically okay for BFS *if* `del` is not 0.
    
    // The primary issue causing Wrong Answer is likely subtle. Let's re-read the expected output.
    // Input: 3 3, edges 0-1, 1-2, 0-2. Del: 1.
    // Before Del:
    // DFS: 0 -> 1 -> 2 (or 0->2->1 depending on order). Adjacency: 0:{1,2}, 1:{0,2}, 2:{0,1}.
    // Code DFS: Prints "0 ". Visited[0]=1. DFS_search(0).
    // In DFS_search(0): loop i=0..2.
    // i=0: skip (i==p).
    // i=1: G[1][0]==1, visited[1]==0. Print "1 ", visited[1]=1. DFS_search(1).
    //   In DFS_search(1): loop i=0..2.
    //   i=0: G[0][1]==1, visited[0]==1. Skip.
    //   i=1: skip.
    //   i=2: G[2][1]==1, visited[2]==0. Print "2 ", visited[2]=1. DFS_search(2).
    //     In DFS_search(2): loop i=0..2. All visited or self. Return.
    //   Return.
    // i=2: G[2][0]==1, visited[2]==1. Skip.
    // Output: 0 1 2 . Correct.
    
    // BFS Before:
    // Prints "0 ". Queue[0]=0. rear=0, k=0.
    // Loop: k=0, i=queue[0]=0.
    // j=0: skip? No, G[0][0]=0.
    // j=1: G[0][1]=1, visited[1]=0. Print "1 ", visited[1]=1. queue[++rear]=queue[1]=1. rear=1.
    // j=2: G[0][2]=1, visited[2]=0. Print "2 ", visited[2]=1. queue[++rear]=queue[2]=2. rear=2.
    // k++ -> k=1.
    // Loop: k!=rear (1!=2).
    // i=queue[1]=1.
    // j=0: G[1][0]=1, visited[0]=1. Skip.
    // j=1: skip.
    // j=2: G[1][2]=1, visited[2]=1. Skip.
    // k++ -> k=2.
    // Loop: k!=rear (2!=2) False. End.
    // Output: 0 1 2 . Correct.

    // After Del (del=1):
    // DFS(del): visited[1]=1. Print "0 ". visited[0]=1. DFS_search(0).
    // In DFS_search(0):
    // i=1: G[1][0]=1, visited[1]=1. Skip.
    // i=2: G[2][0]=1, visited[2]=0. Print "2 ", visited[2]=1. DFS_search(2).
    //   In DFS_search(2):
    //   i=1: G[1][2]=1, visited[1]=1. Skip.
    //   i=0: visited[0]=1. Skip.
    // Output: 0 2 . Correct.

    // BFS(del): visited[1]=1. Print "0 ". queue[0]=0. rear=0, k=0.
    // Loop: k=0, i=0.
    // j=1: G[0][1]=1, visited[1]=1. Skip.
    // j=2: G[0][2]=1, visited[2]=0. Print "2 ", visited[2]=1. queue[++rear]=queue[1]=2. rear=1.
    // k++ -> k=1.
    // Loop: k!=rear (1!=1) False. End.
    // Output: 0 2 . Correct.

    // Why Wrong Answer?
    // Look at the output format. "0 1 2 " vs "0 1 2".
    // The code prints a space after every number including the last one.
    // Expected Output usually doesn't have trailing spaces or requires exact matching.
    // However, many judges ignore trailing whitespace.
    // Let's look closer at the `DFS` and `BFS` arguments.
    // In `main`, `DFS(109)` and `BFS(109)` are called for the "before" case.
    // Inside `DFS(int point)`: `visited[point] = 1;`. If point is 109, this writes to `visited[109]`.
    // `visited` is size 110. Index 109 is valid.
    // Inside `BFS(int point)`: `visited[point] = 1;`. Writes to `visited[109]`. Valid.
    
    // Is there an issue with `clear()`? No.
    // Is there an issue with global variables?
    // `queue` is global. `visited` is global.
    // In `DFS`, `visited` is reset.
    // In `BFS`, `visited` is reset.
    
    // Wait, look at `DFS` implementation again.
    // void DFS(int point) {
    //     for (int i = 0; i < n; i++) visited[i] = 0;
    //     visited[point] = 1; // If point is 109, this is outside the 0..n-1 range logic, but within array bounds.
    //     printf("0 ");
    //     visited[0] = 1;
    //     DFS_search(0);
    //     printf("\n");
    // }
    // If `point` is 109, `visited[109]` is set to 1. This doesn't affect nodes 0..n-1.
    // If `point` is `del` (e.g., 1), `visited[1]` is set to 1. Then `visited[0]` is set to 1.
    // This correctly prevents visiting `del`.

    // Let's check the BFS implementation again.
    // void BFS(int point) {
    //     for (int i = 0; i < n; i++) visited[i] = 0;
    //     visited[point] = 1;
    //     visited[0] = 1;
    //     printf("0 ");
    //     queue[0] = 0;
    //     int rear = 0, i = 0, k = 0;
    //     do {
    //         i = queue[k];
    //         for (int j = 0; j < n; j++) {
    //             if (G[i][j] == 1 && visited[j] == 0) {
    //                 printf("%d ", j);
    //                 visited[j] = 1;
    //                 queue[++rear] = j;
    //             }
    //         }
    //         k++;
    //     } while (k != rear);
    //     printf("\n");
    // }
    
    // The logic seems correct for the provided test case.
    // However, there is a potential bug in `DFS_search`.
    // void DFS_search(int p) {
    //     for (int i = 0; i < n; i++) {
    //         if (i == p) continue;
    //         if (visited[i] == 0 && G[i][p] == 1) { // Note: G[i][p] checks edge between i and p.
    //             printf("%d ", i);
    //             visited[i] = 1;
    //             DFS_search(i);
    //         }
    //     }
    // }
    // This is a standard recursive DFS.

    // Let's look at the "Wrong Answer" again.
    // Buggy Output:
    // 0 1 2 
    // 0 1 2 
    // 0 2 
    // 0 2 
    // Expected Output:
    // 0 1 2
    // 0 1 2
    // 0 2
    // 0 2
    
    // The only difference is the trailing space.
    // If the judge is strict about trailing spaces, this is the error.
    // However, usually "Wrong Answer" implies logical error.
    // Let's check if there's a logical error in other cases.
    // What if `del` is 2?
    // Graph: 0-1, 1-2, 0-2.
    // Before: 0 1 2 (DFS), 0 1 2 (BFS).
    // After Del 2:
    // DFS(2): visited[2]=1. Print 0. visited[0]=1. DFS_search(0).
    // i=1: G[1][0]=1, visited[1]=0. Print 1. visited[1]=1. DFS_search(1).
    //   i=2: G[2][1]=1, visited[2]=1. Skip.
    //   i=0: visited.
    // i=2: visited.
    // Output: 0 1. Correct.
    
    // BFS(2): visited[2]=1. Print 0. Queue 0.
    // Process 0: j=1 (G[0][1]=1, vis[1]=0). Print 1. vis[1]=1. Queue 1.
    // j=2 (vis[2]=1). Skip.
    // Process 1: j=2 (vis[2]=1). Skip.
    // Output: 0 1. Correct.

    // Is it possible the error is in `DFS(109)` accessing `visited[109]`?
    // If `n` is small, `visited` array is large enough (110).
    
    // Let's look at the `BFS` queue logic.
    // `queue` is global. `rear` and `k` are local.
    // `queue[++rear] = j;`
    // If the graph is large, `rear` can exceed `MAXSIZE`?
    // `n` <= 100. `rear` increments at most `n` times. `MAXSIZE` 110. Safe.

    // There is a subtle bug in `DFS_search` and `BFS` regarding the order of visiting neighbors.
    // The problem states: "When accessing adjacent vertices, visit them in ascending order of their vertex numbers."
    // In `DFS_search`: `for (int i = 0; i < n; i++)`. This iterates in ascending order. Correct.
    // In `BFS`: `for (int j = 0; j < n; j++)`. This iterates in ascending order. Correct.

    // So why Wrong Answer?
    // Maybe the trailing space IS the issue.
    // Or maybe the `DFS(109)` call is problematic if `109` >= `MAXSIZE`? No, 109 < 110.
    
    // Let's check the `BFS` loop condition: `while (k != rear);`
    // Initially `rear=0`, `k=0`.
    // If start node has no unvisited neighbors, `rear` remains 0.
    // Loop body executes once (do-while).
    // `i = queue[0]`. Processes neighbors.
    // `k++` becomes 1.
    // `while (1 != 0)` -> True.
    // Next iteration: `i = queue[1]`. **Bug!** `queue[1]` was never initialized if no neighbors were added.
    // If `rear` didn't change, `queue[1]` contains garbage (or -1 from initialization).
    // If `queue[1]` is -1, `i = -1`.
    // Loop `j=0..n-1`. `G[-1][j]` is out of bounds access! Undefined Behavior.
    
    // In the test case:
    // BFS Before: Start 0. Neighbors 1, 2 added. `rear` becomes 2.
    // k=0. Process 0. Adds 1, 2. rear=2. k=1.
    // k!=rear (1!=2). Loop.
    // i=queue[1]=1. Process 1. No new neighbors. k=2.
    // k!=rear (2!=2). Stop.
    // This worked because neighbors were added.
    
    // Consider a graph: 0-1. n=2. Del=1.
    // BFS Before:
    // Start 0. Neighbor 1 added. rear=1.
    // k=0. Process 0. Adds 1. rear=1. k=1.
    // k!=rear (1!=1). Stop.
    // Works.
    
    // Consider a graph with isolated node? No, connected.
    
    // Consider BFS After Del 1 in graph 0-1.
    // Nodes: 0, 1. Del 1.
    // BFS(1): visited[1]=1. visited[0]=1. Print 0. Queue[0]=0. rear=0. k=0.
    // Do:
    // i=queue[0]=0.
    // j=0: skip.
    // j=1: G[0][1]=1. visited[1]=1. Skip.
    // k++ -> k=1.
    // While (k != rear) -> 1 != 0 -> True.
    // Loop again:
    // i=queue[1]. **Queue[1] is uninitialized/garbage**.
    // Access G[i][j] with invalid i. Crash or Wrong Answer.
    
    // This is the bug. The `do-while` loop executes at least once, but if no children are added, `rear` stays same, `k` increments, and loop continues because `k != rear` (since k became 1 and rear is 0). It should be `while (k <= rear)` or use a `while` loop with check before processing, or check if `k > rear` inside.
    // Actually, standard BFS uses `while (front <= rear)`.
    // Here, `k` is front, `rear` is rear.
    // If we use `while (k <= rear)`, then:
    // Init: k=0, rear=0.
    // Process 0. No children. rear=0.
    // k++ -> k=1.
    // Check 1 <= 0 -> False. Stop.
    
    // So the error is in the BFS loop condition.

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
    visited[point] = 1;

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
    visited[point] = 1;

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

    } while (k != rear); // @@ The loop condition `k != rear` causes an extra iteration when `rear` does not advance (i.e., leaf node or all neighbors visited), leading to accessing uninitialized queue elements and out-of-bounds array access. It should be `k <= rear` or the loop structure should be changed to `while (k <= rear)`.

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