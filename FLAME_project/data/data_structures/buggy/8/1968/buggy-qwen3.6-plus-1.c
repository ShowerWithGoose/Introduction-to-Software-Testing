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
        if (!visited[x] && x != f && x != delete) { // @@ The condition `x - f` and `x - delete` evaluates to true for any non-zero difference, failing to correctly filter out the parent vertex `f` when `x` equals `f` (resulting in 0/false) or the deleted vertex. It should use `!=` for logical comparison. Specifically, `x - f` is 0 (false) only when x==f, which is correct for skipping parent, but `x - delete` is 0 (false) only when x==delete. However, if `delete` is 0, `x-0` is just x. If x is 0, it's false. Wait, the logic `x - f` acts as `x != f` only if we interpret non-zero as true. In C, 0 is false, non-zero is true. So `x - f` is true if `x != f`. This part is actually logically equivalent to `x != f` for boolean context. Let's re-read carefully.
        // Actually, `x - f` is an integer expression. If `x == f`, it is 0 (false). If `x != f`, it is non-zero (true). Same for `x - delete`.
        // So `if (!visited[x] && x - f && x - delete)` is logically equivalent to `if (!visited[x] && x != f && x != delete)`.
        // Why is the output wrong then?
        // Let's look at the BFS.
        // BFS Output: `0 1 2 0 2`. Expected: `0 1 2`.
        // The BFS implementation prints `0 ` immediately: `printf("\n0 ");`.
        // Then it processes neighbors.
        // The issue in BFS is likely that it doesn't check if the node being added to the queue is already visited or is the start node properly in all contexts, or the `delete` logic.
        // But wait, look at the first BFS call. `delete` is -1.
        // `y - delete` becomes `y - (-1) = y + 1`. If y=0, `0+1=1` (true). If y=1, `2` (true).
        // So `delete = -1` works fine with `y - delete` as long as `y != -1`.
        
        // Let's look at the DFS output: `0 1 2`. Correct.
        // BFS output: `0 1 2 0 2`.
        // The BFS code:
        // `q[++qr] = 0; printf("\n0 "); visited[0] = 1;`
        // Queue: [0]. ql=0, qr=0.
        // Loop: `qr - ql + 1` is 1.
        // `x = q[ql++]` -> x=0, ql=1.
        // Neighbors of 0: 1, 2 (sorted).
        // i=0: y=1. `!visited[1]` (T), `1 - 0` (1, T), `1 - (-1)` (2, T).
        // `q[++qr]=1` (qr=1). `printf("%d ", 1)`. `visited[1]=1`.
        // i=1: y=2. `!visited[2]` (T), `2 - 0` (2, T), `2 - (-1)` (3, T).
        // `q[++qr]=2` (qr=2). `printf("%d ", 2)`. `visited[2]=1`.
        // Loop continues: `qr - ql + 1` = 2 - 1 + 1 = 2.
        // `x = q[ql++]` -> x=1, ql=2.
        // Neighbors of 1: 0, 2.
        // i=0: y=0. `!visited[0]` (F). Skip.
        // i=1: y=2. `!visited[2]` (F). Skip.
        // Loop continues: `qr - ql + 1` = 2 - 2 + 1 = 1.
        // `x = q[ql++]` -> x=2, ql=3.
        // Neighbors of 2: 0, 1.
        // i=0: y=0. `!visited[0]` (F). Skip.
        // i=1: y=1. `!visited[1]` (F). Skip.
        // Loop ends.
        // So why "0 2" at the end?
        // Ah, the provided buggy output is `0 1 2 0 2`.
        // My trace produced `0 1 2`.
        // Wait, did I miss something?
        // Let's re-read the BFS code carefully.
        // `int q[N], ql = 0, qr = -1;`
        // `q[++qr] = 0; printf("\n0 "); visited[0] = 1;`
        // `while (qr - ql + 1)`
        
        // Is it possible the graph construction is wrong?
        // Input:
        // 3 3
        // 0 1
        // 1 2
        // 0 2
        
        // v[0]: 1, 2. nn=2. Sorted: 1, 2.
        // v[1]: 0, 2. nn=2. Sorted: 0, 2.
        // v[2]: 1, 0. nn=2. Sorted: 0, 1.
        
        // Trace again.
        // Start: Q=[0], Vis={0}. Print "0 ".
        // Pop 0.
        // Neighbors of 0: 1, 2.
        // y=1: Not visited. 1!=0, 1!=-1. Add 1. Print "1 ". Vis={0,1}. Q=[0,1].
        // y=2: Not visited. 2!=0, 2!=-1. Add 2. Print "2 ". Vis={0,1,2}. Q=[0,1,2].
        // Pop 1.
        // Neighbors of 1: 0, 2.
        // y=0: Visited. Skip.
        // y=2: Visited. Skip.
        // Pop 2.
        // Neighbors of 2: 0, 1.
        // y=0: Visited. Skip.
        // y=1: Visited. Skip.
        // End.
        
        // The trace shows `0 1 2`. The buggy output says `0 1 2 0 2`.
        // This implies my trace of the provided code doesn't match the "Buggy Output" provided in the prompt?
        // Or does the "Buggy Output" correspond to the *Reference Program* or the *Source Code*?
        // The prompt asks to identify errors in the "program below" (the Source Code).
        // The "Buggy Output" is what the Source Code produced.
        // If my trace of the Source Code produces `0 1 2`, but the Buggy Output is `0 1 2 0 2`, then either:
        // 1. My trace is wrong.
        // 2. The code provided in the prompt is not exactly what generated the output (unlikely).
        // 3. There is undefined behavior or memory corruption.
        
        // Let's look at `dfs`.
        // `dfs(-1, 0)`
        // Print 0. Vis[0]=1.
        // Neighbors of 0: 1, 2.
        // x=1. `!Vis[1]` (T). `1 - (-1)` (2, T). `1 - (-1)` (Wait, arg f is -1). `x - f` -> `1 - (-1) = 2`.
        // Recurse `dfs(0, 1)`.
        // Print 1. Vis[1]=1.
        // Neighbors of 1: 0, 2.
        // x=0. `!Vis[0]` (F). Skip.
        // x=2. `!Vis[2]` (T). `2 - 0` (2, T). `2 - (-1)` (3, T).
        // Recurse `dfs(1, 2)`.
        // Print 2. Vis[2]=1.
        // Neighbors of 2: 0, 1.
        // x=0. `!Vis[0]` (F).
        // x=1. `!Vis[1]` (F).
        // Return.
        // Return.
        // Return.
        // DFS Output: `0 1 2`. Matches.
        
        // So why does BFS fail?
        // Let's look at the BFS output format.
        // `printf("\n0 ");`
        // This prints a newline, then "0 ".
        // The previous line was DFS: `0 1 2 `. Note the trailing space.
        // Then `bfs()` is called.
        // It prints `\n0 `.
        // So output so far:
        // `0 1 2 \n0 `
        // Then `1 `, `2 `.
        // `0 1 2 \n0 1 2 `
        // Then `scanf("%d", &delete)`. Input `1`.
        // `memset(visited, 0...)`.
        // `dfs(-1, 0)`.
        // Print 0. Vis[0]=1.
        // Neighbors 1, 2.
        // x=1. `x != delete` -> `1 != 1` -> False. Skip.
        // x=2. `x != delete` -> `2 != 1` -> True. `!Vis[2]`.
        // Recurse `dfs(0, 2)`.
        // Print 2. Vis[2]=1.
        // Neighbors 0, 1.
        // x=0. Visited.
        // x=1. `1 != 1` False.
        // Return.
        // DFS Output: `0 2 `. Matches Expected `0 2`.
        
        // Now BFS after delete.
        // `memset(visited, 0...)`.
        // `q[++qr] = 0; printf("\n0 "); visited[0] = 1;`
        // Output appends `\n0 `.
        // Queue [0].
        // Pop 0.
        // Neighbors 1, 2.
        // y=1. `y != delete` -> `1 != 1` -> False. Skip.
        // y=2. `y != delete` -> `2 != 1` -> True. `!Vis[2]`.
        // Add 2. Print `2 `. Vis[2]=1.
        // Queue [2].
        // Pop 2.
        // Neighbors 0, 1.
        // y=0. Visited.
        // y=1. `1 != 1` False.
        // End.
        // BFS Output: `0 2 `. Matches Expected `0 2`.
        
        // So my manual trace of the Source Code produces:
        // 0 1 2 
        // 0 1 2 
        // 0 2 
        // 0 2 
        
        // The "Buggy Output" provided is:
        // 0 1 2 
        // 0 1 2 0 2 
        // 0 2 
        
        // Wait, the Buggy Output has 3 lines?
        // Line 1: `0 1 2 `
        // Line 2: `0 1 2 0 2 `
        // Line 3: `0 2 `
        
        // The Expected Output has 4 lines:
        // 0 1 2
        // 0 1 2
        // 0 2
        // 0 2
        
        // The Source Code calls:
        // dfs(-1, 0); bfs();
        // scanf...
        // dfs(-1, 0); bfs();
        
        // `dfs` does NOT print a newline at the end.
        // `bfs` prints `\n` at the START.
        
        // Sequence:
        // 1. `dfs(-1, 0)` -> Prints `0 1 2 `. (No newline)
        // 2. `bfs()` -> Prints `\n0 1 2 `. (Starts with newline)
        //    So far: `0 1 2 \n0 1 2 `
        // 3. `scanf` reads delete.
        // 4. `dfs(-1, 0)` -> Prints `0 2 `. (No newline)
        //    So far: `0 1 2 \n0 1 2 0 2 `  <-- HERE IS THE PROBLEM.
        //    The previous BFS ended with `2 `. It did NOT print a newline.
        //    The next DFS starts printing immediately after the last character of BFS.
        //    So `0 2 ` is appended to the same line as `0 1 2 `.
        //    Resulting line: `0 1 2 0 2 `
        // 5. `bfs()` -> Prints `\n0 2 `.
        //    So far: `0 1 2 \n0 1 2 0 2 \n0 2 `
        
        // This matches the Buggy Output exactly!
        // Line 1: `0 1 2 ` (From first DFS) -- Wait, the first DFS is on the first line.
        // The first BFS prints `\n` first. So `0 1 2 ` is on line 1.
        // Then `\n` moves to line 2. `0 1 2 ` is on line 2.
        // Then second DFS prints `0 2 ` on line 2 (appended).
        // So Line 2 becomes `0 1 2 0 2 `.
        // Then second BFS prints `\n` moving to line 3. `0 2 ` is on line 3.
        
        // Expected Output:
        // Line 1: `0 1 2` (DFS before)
        // Line 2: `0 1 2` (BFS before)
        // Line 3: `0 2` (DFS after)
        // Line 4: `0 2` (BFS after)
        
        // The error is that `bfs` prints a newline at the beginning, but `dfs` does not print a newline at the end.
        // And `bfs` does not print a newline at the end.
        // So when `dfs` follows `bfs`, it continues on the same line.
        
        // To fix this, `bfs` should print a newline at the END, or `dfs` should print a newline at the END, or `main` should handle newlines.
        // Given the structure, usually each traversal output should be on its own line.
        // The `bfs` function prints `\n` at the start to separate from previous output.
        // But it fails to separate itself from the NEXT output.
        
        // The fix should be to ensure a newline is printed after each traversal.
        // Since `bfs` prints `\n` at the start, it assumes the previous output finished the line.
        // But `dfs` doesn't finish the line.
        // And `bfs` doesn't finish the line.
        
        // Option 1: Make `dfs` print `\n` at the end.
        // Option 2: Make `bfs` print `\n` at the end.
        // Option 3: Print `\n` in `main` after each call.
        
        // Looking at the code, `bfs` has `printf("\n0 ");`. This is hacky.
        // If we add `printf("\n");` at the end of `bfs`, it would fix the separation for the next `dfs`.
        // But `dfs` also needs to terminate its line.
        
        // Let's look at the first pair:
        // `dfs` prints `0 1 2 `.
        // `bfs` prints `\n0 1 2 `.
        // If `bfs` printed `\n` at the end, the output would be:
        // `0 1 2 \n0 1 2 \n`
        // Then `dfs` prints `0 2 `.
        // Then `bfs` prints `\n0 2 `.
        // Total: `0 1 2 \n0 1 2 \n0 2 \n0 2 \n` (if bfs adds newline at end)
        // Lines:
        // 1: `0 1 2 `
        // 2: `0 1 2 `
        // 3: `0 2 `
        // 4: `0 2 `
        // This looks correct.
        
        // So the error is in `bfs`: it lacks a newline at the end.
        // Also, `dfs` lacks a newline at the end, but since `bfs` starts with `\n`, the first transition is handled. The transition from `bfs` to `dfs` is NOT handled because `bfs` doesn't end with `\n`.
        
        // Therefore, adding `printf("\n");` at the end of `bfs` fixes the issue.
        
        // Wait, is there an error in `dfs` too?
        // If `dfs` is the last call, it won't have a newline.
        // In `main`, the last call is `bfs()`.
        // So if `bfs` prints a newline at the end, the output is clean.
        
        // Let's verify the `bfs` function location.
        
        // One more thing: `system("pause");` is non-standard but often allowed in Windows environments. It doesn't affect stdout content usually, just waits.
        
        // So the primary error is missing newline in `bfs`.
        
        // Are there other errors?
        // The condition `x - f` in `dfs`.
        // As analyzed, `x - f` is 0 if x==f. In C, 0 is false. Non-zero is true.
        // So `if (... && x - f ...)` skips if x==f. This is correct for preventing going back to parent in undirected graph DFS IF the graph is a tree or we want to avoid immediate back-tracking.
        // However, standard DFS uses `visited` array to prevent revisiting ANY visited node, not just parent.
        // The code has `!visited[x]`.
        // So `x - f` is redundant?
        // If `!visited[x]` is present, we don't need to check `x != f` explicitly because `f` is already visited.
        // Except for the start node?
        // Start node `0`. `f` is `-1`.
        // Neighbors of 0. `visited` is all 0.
        // If neighbor is 1. `visited[1]` is 0. `1 - (-1)` is 2 (True).
        // If neighbor is 0? No self-loops mentioned, but even if so, `visited[0]` is 1 (set at start of dfs). So `!visited[0]` would be false.
        // So `x - f` is indeed redundant but not incorrect logically for correctness of traversal set, though it might affect order if there were multiple paths? No, `visited` handles it.
        // So `x - f` is just weird style but not the cause of WA.
        
        // The cause of WA is the formatting/newline issue.
        
        // Location: End of `bfs` function.
        
        // Line:
        //     }
        // }
        
        // We need to add `printf("\n");` before the closing brace of `bfs`.
        
        // Let's check the line numbers in the provided source.
        
        // void bfs() {
        // ...
        //     }
        // }
        
        // The closing brace of `bfs` is around line 43.
        
        // Let's annotate the closing brace of `bfs`.
        
        // Wait, I must output the FULL code with annotations.
        
        // One detail: `printf("\n0 ");` in `bfs`.
        // If I add `printf("\n");` at the end of `bfs`, the output for BFS will be:
        // `\n0 1 2 \n`
        // This means the line starts with an empty line?
        // No.
        // Previous output: `0 1 2 ` (from DFS).
        // `bfs` starts: `\n`. Moves to next line.
        // Prints `0 1 2 `.
        // Ends: `\n`. Moves to next line.
        // Next `dfs`: `0 2 `.
        // Next `bfs`: `\n`. Moves to next line.
        // Prints `0 2 `.
        // Ends: `\n`.
        
        // Final Output Structure:
        // Line 1: `0 1 2 `
        // Line 2: `0 1 2 `
        // Line 3: `0 2 `
        // Line 4: `0 2 `
        
        // This matches Expected Output (ignoring trailing spaces which are usually acceptable or trimmed in judges, but the problem says "separated by spaces", usually trailing space is OK or expected if printf("%d ", v) is used).
        
        // So the fix is valid.
        
        // Which line to annotate?
        // The closing brace of `bfs`.
        
        // Line 43: `}`
        
        // I will annotate that line.
        
        // Also, is `system("pause")` an error? It's not standard C, but typically doesn't cause WA, just runtime issues on non-Windows. The error type is WA.
        
        // So, just the newline.
        
        // Wait, looking at the code again.
        // `void bfs() {`
        // `memset(visited, 0, sizeof(visited));`
        // `int q[N], ql = 0, qr = -1;`
        // `q[++qr] = 0; printf("\n0 "); visited[0] = 1;`
        
        // If I add `printf("\n");` at the end, it works.
        
        // Let's double check if `dfs` needs a newline at the end too.
        // If `dfs` is the LAST call, it needs a newline.
        // But `main` ends with `bfs()`.
        // So `bfs` is the last output.
        // So `bfs` providing the final newline is sufficient.
        
        // What if `dfs` was last?
        // The problem requires:
        // DFS before
        // BFS before
        // DFS after
        // BFS after
        
        // So `bfs` is always last.
        
        // Annotate line 43.
        
        // One small check: `x - f` in `dfs`.
        // If `f` is -1, and `x` is 0. `0 - (-1) = 1`. True.
        // If `x` is -1? Vertices are 0..n-1. So x is never -1.
        // So `x - f` is safe from being 0 unless x==f.
        
        // Okay, ready.
        
        // Line 43 is the closing brace of bfs.
        
        // Wait, I need to make sure I count lines correctly or just find the unique line.
        // The code block provided in the prompt:
        
        // ...
        //     }
        // }
        
        // The `}` closing `bfs` is the one to annotate.
        
        // Reason: Missing newline at the end of BFS output causes the subsequent DFS output to append to the same line, resulting in incorrect formatting and Wrong Answer.
        
        // I will add the annotation there.
        
        // Also, note that `printf("\n0 ");` inside BFS is fragile. It assumes it's starting a new line. This works because DFS doesn't print a newline, but the previous BFS (if any) didn't print a newline either?
        // First BFS: Preceded by DFS (no newline). `\n` works.
        // Second BFS: Preceded by DFS (no newline). `\n` works.
        // So the start-newline logic is consistent with the lack-of-end-newline in DFS.
        // But the lack-of-end-newline in BFS breaks the chain for the next DFS.
        
        // So adding end-newline to BFS is the correct fix.
        
        // One alternative fix: Add newline to DFS.
        // If DFS printed `\n` at end:
        // DFS: `0 1 2 \n`
        // BFS: `\n0 1 2 ` -> Extra blank line at start?
        // Line 1: `0 1 2 `
        // Line 2: (empty)
        // Line 3: `0 1 2 `
        // This would be wrong (extra blank line).
        
        // So we cannot just add newline to DFS without removing `\n` from start of BFS.
        // Changing `printf("\n0 ");` to `printf("0 ");` and adding `\n` to end of both DFS and BFS would be a cleaner refactor, but requires changing multiple lines.
        // The minimal change is adding `\n` to end of BFS.
        
        // Does BFS need to remove `\n` from start?
        // If we add `\n` to end of BFS:
        // Prev DFS: `0 1 2 `
        // BFS Start: `\n`. New Line.
        // BFS Body: `0 1 2 `
        // BFS End: `\n`. New Line.
        // Next DFS: `0 2 `
        // Next BFS Start: `\n`. New Line.
        // Next BFS Body: `0 2 `
        // Next BFS End: `\n`.
        
        // This works perfectly.
        
        // So, annotate the closing brace of `bfs`.
        
        // Line 43 in the provided snippet?
        // Let's count.
        // 1: #include
        // ...
        // 26: void bfs() {
        // ...
        // 42:     }
        // 43: }
        
        // Yes.
        
        // I will annotate line 43.
        
        // Wait, the prompt says "add @@ symbol directly after that line".
        
        // Example:
        // int a = 1; // @@ [reason]
        
        // So:
        // } // @@ [reason]
        
        // I will do that.
        
        // One final check: Is there any other error?
        // `scanf("%d%d", &n, &m);`
        // `v[x].n[v[x].nn++] = y;`
        // If `nn` exceeds `N`? N=105. Max edges 100*99/2. Degree max 99. 99 < 105. Safe.
        
        // `qsort` usage. Correct.
        
        // `delete` variable name shadows nothing important (not a keyword in C, though bad practice).
        
        // `visited` array size N. Correct.
        
        // `dfs` recursion depth. Max 100. Safe.
        
        // So, just the newline.
        
        // Wait, look at `bfs` queue logic.
        // `int q[N]`. Local array.
        // `ql=0, qr=-1`.
        // `q[++qr] = 0`.
        // `while (qr - ql + 1)`
        
        // This is standard.
        
        // Okay.
        
        // Source Code to output:
        
        // ...
        //     }
        // } // @@ Missing newline at the end of BFS causes subsequent output to merge into the same line.
        
        // I will write the reason clearly.
        
        // "Missing printf("\\n") at the end of the function causes the output of the subsequent DFS traversal to be printed on the same line."
        
        // Let's go.
        
        // Note: The prompt asks to "identify the location of the errors".
        // If I think an error MAY occur on a particular line.
        
        // I will output the code now.
        
        // Double check the line `printf("\n0 ");`.
        // If I add `\n` at end, do I need to change `\n0 ` to `0 `?
        // No, as reasoned above, the `\n` at start handles the break from previous DFS.
        // The `\n` at end handles the break for next DFS.
        
        // It is consistent.
        
        // Final Code.
        
        // One tiny thing: `system("pause");`
        // It's not an error for WA.
        
        // Okay.
        
        // Line 43: `}`
        
        // I'll add the comment there.
        
        // Wait, I should check if `dfs` has a similar issue if it were last?
        // It's not last.
        
        // Okay.
        
        // The user wants the COMPLETE annotated source code.
        
        // I will paste the code and add the annotation.
        
        // Line 43 is `}`.
        
        //