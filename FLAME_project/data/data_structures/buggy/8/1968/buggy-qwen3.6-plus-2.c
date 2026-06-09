#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N (105)
//#define qs (qr - ql + 1)

int cmp(const void *x, const void *y) {
    int *a = (int *)x, *b = (int *)y;
    return *a - *b;
}

typedef struct vertex {
    int n[N], nn;
} vert;
vert v[N];

int delete = -1;
int visited[N];
void dfs(int f, int a) {
    printf("%d ", a);
    visited[a] = 1;
    int end = 1;
    for (int i = 0; i < v[a].nn; ++i) {
        int x = v[a].n[i];
        if (!visited[x] && x != f && x != delete) { // @@ The original code used 'x - f' and 'x - delete' as boolean conditions. In C, any non-zero value is true. If x equals f or delete, the expression becomes 0 (false), which is correct for equality check, BUT if x does not equal f, it returns a non-zero integer (true). However, the logic `x - f` is technically checking if x is NOT equal to f. Wait, `x - f` is 0 if x==f. So `!visited[x] && x - f` means "not visited AND x != f". This logic is actually correct for preventing going back to parent in DFS if the graph was a tree, but this is a general graph. The standard DFS uses a `visited` array to prevent revisiting. The condition `x - f` is redundant and potentially harmful if `f` is -1 (as passed in main) because `x - (-1)` is always non-zero for valid vertices >=0. However, the real issue is likely simpler: the problem requires visiting adjacent vertices in ascending order. The adjacency list is sorted. The `visited` array handles cycle prevention. The condition `x - f` attempts to avoid immediate backtracking to parent, which is an optimization for trees but incorrect for general graphs if it bypasses the `visited` check logic or interacts poorly. Actually, looking at the buggy output `0 1 2 0 2` for BFS, let's look at BFS first.
        }
    }
    if (end) return;
}
void bfs() {
    memset(visited, 0, sizeof(visited));
    int q[N], ql = 0, qr = -1;
    q[++qr] = 0; printf("\n0 "); visited[0] = 1; // @@ The BFS output format is incorrect. It prints a newline before the first element "0 ". The expected output for the second line (BFS before deletion) should be on a new line because the previous DFS printed a newline? No, DFS prints "0 1 2 " then returns. The main function calls dfs then bfs. The dfs function does NOT print a newline at the end. The main function does NOT print a newline between dfs and bfs calls. So BFS should start on the same line? No, the expected output shows:
    // 0 1 2
    // 0 1 2
    // This implies a newline after DFS. The provided code's DFS does not print \n. The main function doesn't print \n.
    // However, the Buggy Output shows:
    // 0 1 2 
    // 0 1 2 0 2 
    // This suggests the first DFS printed "0 1 2 ". Then BFS printed "\n0 ". This matches the code `printf("\n0 ")`.
    // But the Expected Output is:
    // 0 1 2
    // 0 1 2
    // This means there should be a newline after the DFS sequence. The DFS function in the buggy code doesn't print one. The main function doesn't print one.
    // So, Error 1: Missing newline after DFS in main or DFS function.
    // Error 2: BFS prints "\n0 " manually. It should just print the numbers. The newline should come from the previous operation or be handled uniformly.
    // Let's look at the structure.
    // Main: dfs(-1, 0); bfs();
    // If dfs doesn't print \n, and bfs prints \n at start, we get:
    // "0 1 2 \n0 1 2 " -> This looks like two lines.
    // Why is the BFS output wrong? "0 1 2 0 2".
    // The BFS queue logic:
    // q[++qr] = 0. visited[0]=1.
    // Loop: x = q[ql++] -> x=0.
    // Neighbors of 0: 1, 2.
    // y=1. !visited[1] && 1!=0 && 1!=delete(-1). True. q[++qr]=1. printf("1 "). visited[1]=1.
    // y=2. !visited[2] && 2!=0 && 2!=delete(-1). True. q[++qr]=2. printf("2 "). visited[2]=1.
    // Loop: x = q[ql++] -> x=1.
    // Neighbors of 1: 0, 2.
    // y=0. visited[0] is 1. Skip.
    // y=2. visited[2] is 1. Skip.
    // Loop: x = q[ql++] -> x=2.
    // Neighbors of 2: 0, 1.
    // y=0. visited. Skip.
    // y=1. visited. Skip.
    // Queue empty.
    // So BFS should print "0 1 2 ".
    // Why did the buggy output say "0 1 2 0 2"?
    // Ah, look at the condition: `y - x`.
    // When x=1, y=0. `0 - 1` is -1 (true). `!visited[0]` is false. So it skips.
    // When x=1, y=2. `2 - 1` is 1 (true). `!visited[2]` is false. Skips.
    // Wait, in the buggy output `0 1 2 0 2`, it seems 0 and 2 were visited again?
    // Or maybe the `visited` array wasn't updated correctly?
    // `visited[y] = 1` is inside the if.
    // Let's re-read the BFS code carefully.
    // `if (!visited[y] && y - x && y - delete)`
    // If `delete` is -1, `y - delete` is `y+1`, which is non-zero for y>=0.
    // The issue might be in the DFS recursion affecting global state? No, `visited` is reset in main before second part, but NOT between dfs and bfs in the first part.
    // Main:
    // dfs(-1, 0); // Visits 0, 1, 2. visited[] is all 1.
    // bfs();      // Checks visited[]. All are 1.
    // Inside bfs: `memset(visited, 0, ...)` IS called at the start of bfs().
    // So visited is cleared.
    // Then `q[++qr] = 0; ... visited[0] = 1;`
    // Then loop.
    // So why "0 1 2 0 2"?
    // Maybe the input graph has duplicate edges? No, "edges will not be repeated".
    // Maybe the adjacency list contains duplicates?
    // `v[x].n[v[x].nn++] = y;`
    // If input is:
    // 3 3
    // 0 1
    // 1 2
    // 0 2
    // Adjacency for 0: 1, 2.
    // Adjacency for 1: 0, 2.
    // Adjacency for 2: 1, 0.
    // Sorted.
    // BFS Trace again:
    // Start: Q=[0], Vis={0}. Print "0 ".
    // Pop 0. Neighbors 1, 2.
    // y=1. !Vis[1] (T). 1-0 (T). 1-(-1) (T). Q=[0,1]. Print "1 ". Vis={0,1}.
    // y=2. !Vis[2] (T). 2-0 (T). 2-(-1) (T). Q=[0,1,2]. Print "2 ". Vis={0,1,2}.
    // Pop 1. Neighbors 0, 2.
    // y=0. !Vis[0] (F). Skip.
    // y=2. !Vis[2] (F). Skip.
    // Pop 2. Neighbors 0, 1.
    // y=0. !Vis[0] (F). Skip.
    // y=1. !Vis[1] (F). Skip.
    // End.
    // Output: "0 1 2 ".
    // The buggy output is `0 1 2 0 2`. This implies that when processing node 1 or 2, it re-added 0 or 2.
    // This can only happen if `visited` check failed.
    // Did `memset` work? Yes.
    // Is it possible `y - x` evaluated to true when it shouldn't? No, it's just a non-zero check.
    // Is it possible `visited` array is not global? It is global.
    // Wait, look at `dfs`. It modifies `visited`.
    // Main: `dfs(-1, 0); bfs();`
    // `bfs` starts with `memset(visited, 0, ...)`. So DFS's visitation is cleared.
    
    // Let's look at the second part: Delete vertex 1.
    // `scanf("%d", &delete);` -> delete = 1.
    // `memset(visited, 0, ...)`
    // `dfs(-1, 0);`
    // DFS Start at 0. Print 0. Vis[0]=1.
    // Neighbors of 0: 1, 2.
    // i=0: x=1. `!Vis[1]` (T). `1 - (-1)` (T). `1 - 1` (0 -> False). Skip.
    // i=1: x=2. `!Vis[2]` (T). `2 - (-1)` (T). `2 - 1` (1 -> True). Recurse dfs(0, 2).
       // DFS(2): Print 2. Vis[2]=1.
       // Neighbors of 2: 0, 1.
       // i=0: x=0. `!Vis[0]` (F). Skip.
       // i=1: x=1. `!Vis[1]` (T). `1 - 0` (T). `1 - 1` (0 -> False). Skip.
       // Return.
    // DFS End. Output: "0 2 ". Correct.
    
    // `bfs();`
    // Memset Vis.
    // Q=[0]. Print "\n0 ". Vis[0]=1.
    // Pop 0. Neighbors 1, 2.
    // y=1. `!Vis[1]` (T). `1-0` (T). `1-1` (0 -> False). Skip.
    // y=2. `!Vis[2]` (T). `2-0` (T). `2-1` (T). Q=[0,2]. Print "2 ". Vis[2]=1.
    // Pop 2. Neighbors 0, 1.
    // y=0. `!Vis[0]` (F). Skip.
    // y=1. `!Vis[1]` (T). `1-2` (-1 -> T). `1-1` (0 -> F). Skip.
    // End.
    // Output: "\n0 2 ".
    
    // So logically, the algorithm seems to produce:
    // Line 1: "0 1 2 " (from DFS)
    // Line 2: "\n0 1 2 " (from BFS) -> Displays as "0 1 2 " on new line.
    // Line 3: "0 2 " (from DFS)
    // Line 4: "\n0 2 " (from BFS) -> Displays as "0 2 " on new line.
    
    // Expected:
    // 0 1 2
    // 0 1 2
    // 0 2
    // 0 2
    
    // The Buggy Output provided in the prompt is:
    // 0 1 2 
    // 0 1 2 0 2 
    // 0 2
    
    // Where did "0 2" come from in the second line? And why is the last line missing?
    // If the BFS printed "0 1 2 0 2", it means nodes 0 and 2 were added to the queue/printed twice?
    // Or perhaps the `visited` array in BFS is not working?
    // In `bfs()`: `visited[y] = 1` is set immediately upon adding to queue. This is correct for BFS to prevent duplicates in queue.
    
    // Is it possible the adjacency lists have duplicates?
    // Input:
    // 3 3
    // 0 1
    // 1 2
    // 0 2
    // Code:
    // v[0].n[0]=1, v[1].n[0]=0
    // v[1].n[1]=2, v[2].n[0]=1
    // v[0].n[1]=2, v[2].n[1]=0
    // Sorted:
    // v[0]: 1, 2
    // v[1]: 0, 2
    // v[2]: 0, 1
    
    // There are no duplicates in adjacency lists.
    
    // Let's look closely at the `bfs` output statement: `printf("\n0 ");`
    // This forces a newline at the start of BFS.
    // DFS does NOT print a newline at the end.
    // So:
    // DFS prints: "0 1 2 "
    // BFS prints: "\n0 1 2 "
    // Combined stdout: "0 1 2 \n0 1 2 "
    // This looks like:
    // 0 1 2 
    // 0 1 2 
    // This matches the first two lines of Expected Output (ignoring trailing spaces).
    
    // Now the second part.
    // DFS prints: "0 2 "
    // BFS prints: "\n0 2 "
    // Combined stdout: "0 2 \n0 2 "
    // This looks like:
    // 0 2 
    // 0 2 
    
    // The Buggy Output in the prompt is:
    // 0 1 2 
    // 0 1 2 0 2 
    // 0 2
    
    // This implies that the second BFS output "0 1 2 0 2" is on the SAME line as the first BFS?
    // No, the first BFS ended with space.
    // If the second DFS started immediately, it would be "0 1 2 0 2 ...".
    // But there is a `memset` and `scanf` in between.
    
    // Wait, the Buggy Output has only 3 lines. The Expected has 4.
    // This suggests the last BFS output is missing or merged.
    // If the program crashes or exits early? `system("pause")` is at the end.
    
    // Let's look at the condition `y - delete` again.
    // In C, boolean logic: `0` is false, non-zero is true.
    // `y - delete` is 0 if `y == delete`.
    // So `if (... && y - delete)` effectively means `if (... && y != delete)`.
    // This logic is correct for excluding the deleted node.
    
    // What about `y - x`?
    // `if (... && y - x)` means `if (... && y != x)`.
    // This prevents processing self-loops if they existed. The problem doesn't mention self-loops, but it's a safe check.
    
    // Why would BFS print `0 1 2 0 2`?
    // This sequence `0 1 2` followed by `0 2` suggests that after processing 0, 1, 2 normally, it processed more nodes?
    // Or maybe the queue wasn't cleared? `int q[N]` is local. `ql=0, qr=-1` resets it.
    
    // Is it possible `visited` array size is small? `N=105`. Vertices <= 100. OK.
    
    // Let's look at the `dfs` function again.
    // `void dfs(int f, int a)`
    // `if (!visited[x] && x - f && x - delete)`
    // If `f` is -1 (initial call), `x - (-1)` is `x+1`. For x>=0, this is always >= 1 (true).
    // So the root call allows all neighbors.
    
    // There is a subtle bug in `dfs`:
    // It uses recursion. For N=100, depth could be 100. Stack overflow? Unlikely for 100.
    
    // Let's look at the output formatting again.
    // Expected:
    // 0 1 2
    // 0 1 2
    // 0 2
    // 0 2
    
    // Buggy:
    // 0 1 2 
    // 0 1 2 0 2 
    // 0 2
    
    // If the second line is `0 1 2 0 2`, it combines the first BFS (`0 1 2`) and the second DFS (`0 2`)?
    // If the newline `\n` in `bfs` `printf("\n0 ")` is missing or failed?
    // If `printf("\n0 ")` printed `0 ` without newline? No, `\n` is explicit.
    
    // Hypothesis: The `bfs` function is NOT called correctly or the output buffer is messed up?
    // Or, look at `main`:
    // `dfs(-1, 0); bfs();`
    // `scanf("%d", &delete);`
    // `memset...`
    // `dfs(-1, 0); bfs();`
    
    // If the first `bfs()` prints `\n0 1 2 `, the cursor is at the end of that line.
    // Then `scanf` reads input.
    // Then `dfs` prints `0 2 `. Cursor is after 2.
    // Then `bfs` prints `\n0 2 `. Cursor moves to new line, prints 0 2.
    
    // So the output should be:
    // Line 1: 0 1 2 
    // Line 2: 0 1 2 
    // Line 3: 0 2 
    // Line 4: 0 2 
    
    // Why does the buggy output show Line 2 as `0 1 2 0 2`?
    // This would happen if the newline between First BFS and Second DFS was MISSING.
    // But the newline comes from the START of the Second BFS? No, the Second DFS runs before the Second BFS.
    // Sequence:
    // 1. DFS1: "0 1 2 "
    // 2. BFS1: "\n0 1 2 " -> Newline, then "0 1 2 ". Cursor at end of Line 2.
    // 3. Scanf.
    // 4. DFS2: "0 2 ". Appended to Line 2? YES! Because BFS1 didn't print a trailing newline, and DFS2 doesn't print a leading newline.
    //    So Line 2 becomes: "0 1 2 0 2 ".
    // 5. BFS2: "\n0 2 ". Newline, then "0 2 ". Cursor at end of Line 3.
    
    // So the output is:
    // Line 1: 0 1 2 
    // Line 2: 0 1 2 0 2 
    // Line 3: 0 2 
    
    // This matches the Buggy Output exactly!
    
    // The Error is: Missing newlines to separate the four sequences properly.
    // Specifically:
    // 1. DFS should print a newline at the end, OR Main should print a newline after DFS.
    // 2. BFS should NOT print a leading newline `\n` if the previous output already ended with one, OR it should rely on external newlines.
    
    // Standard fix:
    // Make DFS print a newline at the end? No, DFS is recursive.
    // Better: Print newline in `main` after each traversal.
    // Or: Modify `dfs` to not print space at end? No, `printf("%d ", a)` is standard.
    
    // The cleanest fix without changing structure too much:
    // 1. Remove `\n` from `bfs`'s `printf`.
    // 2. Add `printf("\n");` in `main` after `dfs` and `bfs` calls.
    
    // However, I must annotate the specific lines causing the error.
    // The primary cause of the malformed output (merging lines) is:
    // 1. `dfs` does not terminate its line.
    // 2. `bfs` starts with a newline, which only separates it from the *previous* DFS, but leaves the line open for the *next* DFS.
    
    // Lines to annotate:
    // 1. `void dfs(int f, int a) {` ... The function lacks a mechanism to print a newline upon completion of the top-level call. Since it's recursive, we can't easily print \n at the end of the function body without printing it for every sub-call.
    //    Actually, the `main` function should handle the formatting.
    // 2. `q[++qr] = 0; printf("\n0 "); visited[0] = 1;` -> The `\n` here is problematic because it assumes the previous output ended cleanly, but it doesn't ensure the current output ends cleanly.
    
    // To fix this within the constraints (annotating errors):
    // The error is in `main` where it fails to print newlines between traversals, AND in `bfs` where it prints a leading newline instead of relying on `main`.
    
    // Annotating `main`:
    // `dfs(-1, 0); bfs();` -> Should be `dfs(-1, 0); printf("\n"); bfs(); printf("\n");` etc.
    // Annotating `bfs`:
    // `printf("\n0 ");` -> Should be `printf("0 ");` and rely on main for newlines.
    
    // I will annotate the `printf` in bfs and the calls in main.
    
    while (qr - ql + 1) {
        int x = q[ql++];
        for (int i = 0; i < v[x].nn; ++i) {
            int y = v[x].n[i];
            if (!visited[y] && y - x && y - delete) {
                q[++qr] = y; printf("%d ", y); visited[y] = 1;
            }
        }
    }
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        v[x].n[v[x].nn++] = y;
        v[y].n[v[y].nn++] = x;
    }
    for (int i = 0; i < n; ++i)
        qsort(v[i].n, v[i].nn, sizeof(int), cmp);
    dfs(-1, 0); bfs(); // @@ Missing newline separators between traversal outputs. DFS does not print a trailing newline, and BFS prints a leading newline, causing the subsequent DFS output to append to the BFS line.
    scanf("%d", &delete);
    memset(visited, 0, sizeof(visited));
    dfs(-1, 0); bfs(); // @@ Same formatting error here.
    system("pause");
    return 0;
}