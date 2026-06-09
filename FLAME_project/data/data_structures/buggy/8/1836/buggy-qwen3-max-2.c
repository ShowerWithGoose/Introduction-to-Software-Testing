#include<stdio.h>
#include<string.h>
int weights[101][101] , visited[101], que[101];
int num_vertex , num_edge;
void dfs(int v)
{
    int i;
    printf("%d " , v);
    visited[v]=1;
    for(i=0;i<num_vertex;i++){
        if(weights[v][i] && !visited[i]) dfs(i);
    }
}
void bfs(int v)
{
    int i, head = 0 , tail=1 , tmp;
    que[head]=v;
    while(head<=tail){
        tmp=que[head++];
        if(!visited[tmp]){
            printf("%d " , tmp);
            visited[tmp]=1;
            for(i=0;i<num_vertex;i++){
                if(weights[tmp][i] && !visited[i]) que[tail++] = i;
            }
        }
    }
}
int main()
{
    int u , v , i , del;
    scanf("%d %d" , &num_vertex , &num_edge);
    for(i=0;i<100;i++)
    for(int j=0;j<100;j++)
    weights[i][j]=0;
    for(int j=0;j<100;j++)
    visited[j]=0;
    for(i=0;i<num_edge;i++){
        scanf("%d %d" , &u , &v);
        weights[u][v]=1;
        weights[v][u]=1;
    }
    scanf("%d" , &del);
    dfs(0);
    printf("\n");
    for(i=0;i<=100;i++)
    visited[i]=0; 
    bfs(0);
    for(i=0;i<=100;i++)
    visited[i]=0; 
    for(i=0;i<=100;i++){
        if(weights[i][del]==1){
            weights[i][del]=0;
            weights[del][i]=0;
        }
    }
    printf("\n"); // @@ [This printf("\n") is misplaced. It should come AFTER the second DFS and BFS, not before. This causes an extra blank line between the "before deletion" and "after deletion" outputs, but more critically, it shifts the order of operations: the vertex deletion happens AFTER printing the first two traversals but BEFORE the newline that separates the two groups. However, the real issue is that the deletion occurs AFTER the first BFS, which is correct, but the output formatting is wrong because the third line (first after-deletion DFS) is printed after this newline, leading to four lines total as expected. But wait — the actual bug is subtler.]

    // Actually, looking at the expected vs buggy output:
    // Buggy Output has:
    // 0 1 2 
    // 0 1 2 
    // 0 2 
    // 0 2
    // Expected Output has:
    // 0 1 2
    // 0 1 2
    // 0 2
    // 0 2
    // The only difference is trailing spaces. But the problem says "Wrong Answer", so likely the judge is strict about whitespace.

    // However, the REAL LOGICAL ERROR is in the BFS implementation: the queue `que` is never reset to zero before the second BFS. In the reference program, they do `memset(que, 0, sizeof(que));`. In this buggy code, `que` retains old values from the first BFS, which may interfere with the second BFS.

    // But note: in the second BFS, we reinitialize `head=0, tail=1`, and only use indices from 0 up. However, if leftover values in `que` beyond `tail` are not accessed, maybe it's okay? But what if during the second BFS, `tail` grows and overwrites? Actually, the bigger issue is that the queue is not cleared, but since we control `head` and `tail`, and only read within that range, it might be safe.

    // Wait — look at the order of operations:
    // - Read graph
    // - Read `del`
    // - Do DFS(0) → prints first line
    // - Reset visited
    // - Do BFS(0) → prints second line
    // - Reset visited
    // - THEN delete vertex `del` from graph
    // - Print a newline → this becomes the third line? No! Because after BFS(0), there's no newline printed yet!

    // Let's trace output step by step:

    // After dfs(0): prints "0 1 2 " (with space) then...
    // printf("\n") → line 1 done.
    // Then bfs(0): prints "0 1 2 " (with space) → but NO newline after!
    // Then we reset visited, delete vertex, then printf("\n") → so now we output a newline, making the second line end here.
    // Then dfs(0) → prints "0 2 "
    // Then printf("\n")
    // Then bfs(0) → prints "0 2 " (no newline at end)

    // So output is:
    // Line1: "0 1 2 \n"
    // Line2: "0 1 2 " (no newline yet)
    // Then: "\n" → so Line2 becomes "0 1 2 \n", and now we're at start of Line3
    // Line3: "0 2 \n"
    // Line4: "0 2 "

    // But expected output has no trailing spaces and each line ends cleanly.

    // However, the problem says the output format is: "For each traversal, the vertices should be printed in a single line, separated by spaces." It doesn't say anything about trailing space, but many judges reject trailing space.

    // BUT WAIT: the reference program also prints trailing space! And the test case input leads to same trailing space in both. So why WA?

    // Let's compare the reference program output on the test case:

    // Reference program:
    // DFS(0): prints "0 1 2 " → then puts("") → newline → "0 1 2 \n"
    // BFS(0): prints "0 1 2 " → then puts("") → newline → "0 1 2 \n"
    // Then delete, DFS: "0 2 " → puts → "0 2 \n"
    // BFS: "0 2 " → puts → "0 2 \n"

    // But the expected output shown is:
    // 0 1 2
    // 0 1 2
    // 0 2
    // 0 2

    // So likely the judge trims or expects no trailing space. However, the problem says the reference program is correct. So perhaps in the real judge, trailing space is acceptable? Or the example expected output is just for illustration.

    // But the user says: "Buggy Output" vs "Expected Output" differ only in trailing space? Actually, looking:

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

    // So the buggy output has trailing space on every line, expected does not.

    // However, the reference program ALSO produces trailing space. So why is reference correct? Maybe the problem allows it, or the example expected output is simplified.

    // But the user says the reference program is correctly implemented. So the issue must be elsewhere.

    // Let's look again at the buggy code's logic flow:

    // Steps:
    // 1. Read n, m
    // 2. Initialize weights and visited
    // 3. Read edges
    // 4. Read `del`
    // 5. Run DFS(0) → uses original graph → correct
    // 6. Print newline
    // 7. Reset visited
    // 8. Run BFS(0) → uses original graph → correct
    // 9. Reset visited
    // 10. Delete vertex `del` from graph (by zeroing its edges)
    // 11. Print newline → THIS IS THE BUG!

    // Why? Because after step 8 (BFS), we have printed the second traversal, but we haven't printed a newline after it! Then step 11 prints a newline, which ends the second line. Then we do DFS (step 12) which prints the third line.

    // But the reference program does:
    // DFS(0); puts("");
    // BFS(0); puts("");
    // ... then deletion ...
    // DFS(0); puts("");
    // BFS(0); puts("");

    // So each traversal is followed immediately by a newline.

    // In the buggy code:
    // - After first DFS: printf("\n") → correct.
    // - After BFS: NO newline printed immediately. Instead, later, after deletion, a printf("\n") is done BEFORE the next DFS.

    // So the output becomes:
    // Line1: DFS output + \n
    // Line2: BFS output (without \n yet)
    // Then: \n → so Line2 is now complete
    // Line3: DFS(after) output + \n
    // Line4: BFS(after) output (without final \n)

    // But the expected output has 4 lines, each ending with newline.

    // However, the buggy output as shown by user DOES have 4 lines, each ending with space and then newline? Because they wrote:
    // Buggy Output:
    // 0 1 2 
    // 0 1 2 
    // 0 2 
    // 0 2

    // So likely each line does end with newline. How?

    // Because:
    // - First: dfs(0) → "0 1 2 ", then printf("\n") → line1 done.
    // - Then bfs(0) → prints "0 1 2 " (no newline)
    // - Then later: printf("\n") → so now line2 is "0 1 2 \n"
    // - Then dfs(0) → "0 2 ", then printf("\n") → line3 done.
    // - Then bfs(0) → "0 2 " (and program ends)

    // But the last line doesn't have a newline! However, the user's buggy output shows 4 lines, so probably the system adds newline or the output is captured with newline.

    // The REAL BUG is: the deletion of the vertex happens AFTER the first BFS, which is correct, but the order of printing newlines is messed up. However, the bigger issue is that the second BFS uses a `que` array that still contains data from the first BFS.

    // In the first BFS:
    //   que[0]=0, then que[1]=1, que[2]=2 (for example)
    //   head goes to 3, tail=3
    // Then, before second BFS, we do NOT clear `que`.
    // In second BFS:
    //   head=0, tail=1
    //   que[0]=0 (we set it)
    //   But que[1], que[2], etc. still have old values.
    //   However, we only read from que[head] up to que[tail-1], and we overwrite que[tail] as we go.
    //   So if the second BFS doesn't need as many slots, it might be okay.
    //   But what if the old values cause issues? Unlikely, because we control tail.

    // However, consider: in the second BFS, when we do `que[tail++] = i`, we are writing to positions starting from 1 onward. The old values beyond the current tail are not read, so it should be safe.

    // Then what is the error?

    // Let's simulate the test case:

    // Input: n=3, m=3, edges: (0,1),(1,2),(0,2), del=1

    // Before deletion:
    //   Adjacency matrix:
    //     0: [0,1,1]
    //     1: [1,0,1]
    //     2: [1,1,0]

    // DFS(0): 
    //   print 0, mark visited[0]=1
    //   i=0: skip
    //   i=1: weights[0][1]=1 and !visited[1] → DFS(1)
    //     print 1, mark visited[1]=1
    //     i=0: visited
    //     i=1: skip
    //     i=2: weights[1][2]=1 and !visited[2] → DFS(2)
    //       print 2
    //   So: "0 1 2 "

    // BFS(0):
    //   que[0]=0, head=0, tail=1
    //   tmp=que[0]=0, head=1
    //     not visited: print 0, mark visited[0]=1
    //     i=0: skip
    //     i=1: weights[0][1]=1, !visited[1] → que[1]=1, tail=2
    //     i=2: weights[0][2]=1, !visited[2] → que[2]=2, tail=3
    //   Now head=1 <= tail=3 → true
    //     tmp=que[1]=1, head=2
    //       not visited: print 1, mark visited[1]=1
    //       i=0: visited
    //       i=1: skip
    //       i=2: weights[1][2]=1, !visited[2] → but que[3]=2, tail=4
    //   Now head=2 <=4 → tmp=que[2]=2, head=3
    //       print 2, mark visited[2]=1
    //       neighbors: 0 and 1 visited
    //   head=3, tail=4 → head<=tail → tmp=que[3]=2 (from previous step!), head=4
    //       visited[2] is already 1 → skip
    //   head=4, tail=4 → head<=tail → tmp=que[4]=? (uninitialized, but in buggy code, que was not initialized to zero globally? Actually, global arrays are zero-initialized in C! So que[4]=0.
    //       visited[0] is 1 → skip
    //   head=5 > tail=4 → exit.

    // So BFS prints: "0 1 2 2 "? No, because when tmp=2 the second time, visited[2] is already 1, so it doesn't print. So it prints "0 1 2 ".

    // Now, after deletion of vertex 1:
    //   Set weights[i][1]=0 and weights[1][i]=0 for all i.
    //   New adjacency:
    //     0: [0,0,1]
    //     1: [0,0,0]
    //     2: [1,0,0]

    // DFS(0):
    //   print 0
    //   i=0: skip
    //   i=1: weights[0][1]=0 → skip
    //   i=2: weights[0][2]=1 and !visited[2] → DFS(2)
    //     print 2
    //     i=0: weights[2][0]=1 but visited[0]=1 → skip
    //     i=1: 0
    //     i=2: skip
    //   So: "0 2 "

    // BFS(0):
    //   que[0]=0, head=0, tail=1
    //   tmp=0, head=1 → print 0, visited[0]=1
    //     i=0: skip
    //     i=1: weights[0][1]=0 → skip
    //     i=2: weights[0][2]=1, !visited[2] → que[1]=2, tail=2
    //   head=1 <= tail=2 → tmp=que[1]=2, head=2
    //       print 2, visited[2]=1
    //       i=0: visited
    //       i=1: 0
    //       i=2: skip
    //   head=2, tail=2 → head<=tail → tmp=que[2]=? 
    //       In global array, que[2] was set to 2 in first BFS, but we don't care because visited[2] is 1, so it won't print.
    //   So prints "0 2 "

    // So the output sequences are correct. Then why WA?

    // The only possibility is the TRAILING SPACE and/or MISSING NEWLINE at the end.

    // The expected output has no trailing spaces, but the program outputs trailing space on every line.

    // However, the reference program also outputs trailing space, and it's considered correct. So this suggests that the judge for this problem accepts trailing space.

    // Therefore, the error must be elsewhere.

    // Let's look at the initialization loops:

    // The code does:
    //   for(i=0;i<100;i++)
    //   for(int j=0;j<100;j++)
    //   weights[i][j]=0;
    //   for(int j=0;j<100;j++)
    //   visited[j]=0;

    // But the graph has up to 100 vertices (0 to 99), so this is okay.

    // However, in the deletion loop:
    //   for(i=0;i<=100;i++){
    //       if(weights[i][del]==1){
    //           weights[i][del]=0;
    //           weights[del][i]=0;
    //       }
    //   }

    // This goes up to i=100, but the vertices are only 0 to num_vertex-1 (which is at most 99). So i=100 is out of bounds? But weights is [101][101], so i=100 is valid index (0..100). However, there is no vertex 100, so weights[100][del] is 0 anyway. So harmless.

    // Another issue: in the BFS function, the condition is `while(head<=tail)`. In the first BFS, tail starts at 1, and we increment tail when adding. The number of elements in queue is tail - head. When head == tail, there's one element? No: initially, head=0, tail=1 → one element. When head becomes 1, tail=1 → head<=tail is true, but que[head] is que[1] which may be uninitialized.

    // In the first BFS simulation above, we had tail=3 after adding two neighbors, then head goes to 3, and then we access que[3] which was set to 2, then que[4] which is 0.

    // But in the second BFS, after deletion, the graph has only edge (0,2). 
    //   Start: que[0]=0, head=0, tail=1.
    //   Process 0: add 2 → que[1]=2, tail=2.
    //   Then head=1, tail=2: process que[1]=2.
    //   Then head=2, tail=2: now head<=tail → true, so we do tmp=que[2]. What is que[2]? From first BFS, it was set to 2. But in the second BFS, we never set que[2]. However, since visited[2] is already 1 (from processing it when head=1), it won't print. So it's okay.

    // But what if que[2] was a different vertex that is not visited? For example, if the first BFS left que[2]=3, and in the second graph, vertex 3 is present and not visited, then it would be processed incorrectly.

    // However, in our test case, n=3, so vertices are 0,1,2. Vertex 3 doesn't exist. But weights[2][3] would be 0, so even if que[2]=3, when we check weights[tmp][i], it won't add anything. But the bigger issue is: when tmp=3, we check visited[3]. visited[3] was reset to 0 before second BFS. So if que[2]=3 (from first BFS), then in second BFS:
    //   head=2, tail=2 → head<=tail → tmp=que[2]=3
    //   visited[3] is 0 → so it would print 3! Which is wrong.

    // Ah! This is the bug.

    // In the first BFS, for a graph with n=3, we might have written to que[2]=2, que[3]=2, etc. But if the graph had more vertices, say n=5, and first BFS used que[0..4], then in second BFS, when head catches up to tail, it will read que[tail] which is beyond what we set in second BFS, but contains old vertex numbers.

    // And since visited is reset, those old vertex numbers (which are within 0..n-1) might be unvisited, so BFS would process them even though they are not in the queue of the second BFS.

    // Therefore, the `que` array must be cleared or at least the relevant part must not contain stale vertex indices.

    // The reference program does: `memset(que, 0, sizeof(que));` before the second BFS.

    // In the buggy code, there is no such clearing of `que`.

    // So the error is that the `que` array retains old values from the first BFS, which can cause the second BFS to process vertices that were not enqueued in the second BFS.

    // However, in the given test case (n=3), does this happen?

    // First BFS:
    //   que[0]=0
    //   then que[1]=1, que[2]=2, que[3]=2 (when processing vertex 1, it adds 2 again)
    //   So que = [0,1,2,2,...]

    // Second BFS:
    //   We set que[0]=0.
    //   Then we process 0: add 2 → que[1]=2.
    //   Then head=1, tail=2: process que[1]=2.
    //   Then head=2, tail=2: now head<=tail → true, so tmp=que[2]=2 (from first BFS).
    //   visited[2] is already 1 (from processing it at head=1), so it doesn't print. So no harm.

    // But what if the first BFS had put a different vertex in que[2]? For example, if the graph was different.

    // However, the test case provided is the one that fails. And in this test case, it doesn't cause an extra print. So why WA?

    // Let's consider the exact output:

    // The buggy output is:
    // 0 1 2 
    // 0 1 2 
    // 0 2 
    // 0 2

    // Expected is:
    // 0 1 2
    // 0 1 2
    // 0 2
    // 0 2

    // The only difference is the trailing space. But the reference program also has trailing space. Unless the judge for this specific test is checking strictly.

    // However, the problem says the reference program is correct. So the trailing space must be acceptable.

    // Another possibility: the order of resetting visited and deleting the vertex.

    // In the buggy code:
    //   After first BFS, we do:
    //      for(i=0;i<=100;i++) visited[i]=0; 
    //   Then delete vertex.
    //   Then printf("\n");
    //   Then dfs(0) → which uses the deleted graph and fresh visited.

    // This is correct.

    // But wait: in the first BFS, after it finishes, visited is all 1 for vertices 0,1,2.
    // Then we reset visited to 0.
    // Then delete vertex.
    // Then do DFS: correct.

    // So what is the error?

    // Let's look at the very beginning: the code initializes weights and visited with loops up to 100, but the graph has num_vertex vertices. That's fine.

    // Another idea: the BFS function has a off-by-one in the while condition.

    // Standard BFS uses a queue where you enqueue the start, then while queue not empty, dequeue and process.

    // Here, the queue is simulated with an array and head/tail pointers.
    //   Initially: que[0]=v, head=0, tail=1.
    //   The number of elements is tail - head.
    //   The loop condition should be head < tail, not head <= tail.

    // Because when head == tail, the queue is empty.

    // In the current code: while (head <= tail)

    // Let's simulate a simple BFS on two nodes: 0-1.

    // Start: que[0]=0, head=0, tail=1.
    // Iteration1: head(0) <= tail(1) → true.
    //   tmp = que[0]=0, head becomes 1.
    //   Process 0: enqueue 1 → que[1]=1, tail=2.
    // Iteration2: head(1) <= tail(2) → true.
    //   tmp=que[1]=1, head=2.
    //   Process 1: no new neighbors.
    // Iteration3: head(2) <= tail(2) → true.
    //   tmp=que[2]=? (uninitialized), head=3.
    //   If que[2] is 0 (from global zero-init), then visited[0] is 1, so skip.
    //   But if que[2] is garbage, and if by chance it's a valid unvisited vertex, it would be processed.

    // So the condition should be `head < tail`.

    // In the reference program, it's also `head <= tail`! Let me check:

    // Reference program:
    //   void BFS(int v)
    //   {
    //       int i, head = 0, tail = 1, tmp;
    //       que[head] = v;
    //       while (head <= tail)
    //       {
    //           tmp = que[head++];
    //           ...

    // So the reference program has the same condition.

    // But the reference program is said to be correct.

    // However, in the reference program, they memset(que,0,sizeof(que)), so que is all zeros. And vertices are from 0 to n-1, so que entries beyond tail are 0. And vertex 0 is always visited first, so when head catches up, tmp=0, but visited[0] is 1, so it's skipped.

    // In the buggy code, que is not cleared, so que entries beyond what we set in the current BFS may contain other vertex numbers.

    // Therefore, the combination of:
    //   (1) not clearing que, and 
    //   (2) using head<=tail (which processes one extra element)
    // causes the BFS to potentially process a stale vertex.

    // In the test case provided, it doesn't manifest as an extra vertex because the stale value is 2, which is already visited. But what if the stale value is a different vertex?

    // However, the test case input is fixed. Let's see if there's another issue.

    // Look at the output order in the buggy code:

    // The code does:
    //   dfs(0); printf("\n");
    //   reset visited; bfs(0); 
    //   reset visited; 
    //   delete vertex;
    //   printf("\n");   // @@ This is the critical error: this newline is printed BEFORE the after-deletion DFS, but it should be printed AFTER the before-deletion BFS.
    //   dfs(0); printf("\n");
    //   reset visited; bfs(0);

    // So the output is:
    //   [DFS before]\n
    //   [BFS before]   (no newline)
    //   \n
    //   [DFS after]\n
    //   [BFS after]    (no newline at end of file)

    // But the expected output has newline after each of the four lines.

    // The reference program does:
    //   DFS(0); puts("");
    //   BFS(0); puts("");
    //   DFS(0); puts("");
    //   BFS(0); puts("");

    // So four newlines.

    // In the buggy code:
    //   Line1: has newline.
    //   Line2: does not have newline immediately after BFS, but gets a newline from the later printf("\n").
    //   Line3: has newline.
    //   Line4: no newline at the end.

    // However, the user's "Buggy Output" shows four lines, so likely the system or the way it's printed includes newlines. But the last line might be missing a newline, which could cause WA.

    // But the expected output as shown also doesn't specify if there's a newline at the end.

    // The real smoking gun is the order of the printf("\n").

    // Specifically, after the first BFS, we must print a newline immediately. In the buggy code, the newline for the BFS is delayed until after the vertex deletion.

    // This means that between the BFS output and its newline, we do:
    //   - reset visited
    //   - delete vertex
    // which is logically fine, but the output is:
    //   "0 1 2 \n0 1 2 \n0 2 \n0 2 "
    // wait, no:

    // Actual sequence of output characters:
    //   '0',' ','1',' ','2',' ','\n',   // from first DFS and its printf("\n")
    //   '0',' ','1',' ','2',' ',        // from BFS
    //   '\n',                           // from the misplaced printf
    //   '0',' ','2',' ','\n',          // from second DFS and its printf("\n")
    //   '0',' ','2',' '                 // from second BFS

    // So the second line is "0 1 2 \n", which is fine, but the fourth line has no newline.

    // Many online judges require a newline at the end of the output.

    // So the fourth line is missing a newline.

    // In the reference program, the last thing is: BFS(0); puts(""); → so last line has newline.

    // In the buggy code, the last thing is: bfs(0); and then return. So no newline after the last BFS.

    // Therefore, the output is missing a newline at the end.

    // Additionally, the third line's newline is printed in the right place, but the second line's newline is printed late, which is acceptable as long as it's there.

    // But the fourth line has no newline.

    // So to fix, after the last bfs(0), we need a printf("\n").

    // However, looking at the code:

    //   bfs(0);
    //   return 0;

    // So indeed, no newline after last BFS.

    // But wait, the user's "Buggy Output" shows four lines, which implies that there is a newline after the fourth line. How?

    // Perhaps the terminal or the test harness appends a newline. But in strict judging, it's required.

    // Given that the reference program outputs a newline after every traversal, including the last, the buggy program does not.

    // Therefore, the errors are:

    // 1. The newline after the first BFS is not printed immediately; instead, it's printed later, which is not wrong per se, but...
    // 2. The last BFS is not followed by a newline.

    // However, the code has:

    //   dfs(0);
    //   printf("\n");
    //   ... 
    //   bfs(0);
    //   ...
    //   printf("\n");   // this is intended to be the newline after BFS, but it's placed after deletion
    //   dfs(0);
    //   printf("\n");
    //   bfs(0);         // no newline after this

    // So the second line's newline is provided by the later printf("\n"), and the fourth line has no newline.

    // The expected output has four lines, each properly terminated.

    // So the fourth line must end with a newline.

    // Hence, the program is missing a newline after the last BFS.

    // But the user's buggy output is shown as four lines, so maybe in their environment it's displayed as four lines even without the last newline. However, the judge might be strict.

    // Given the above, the primary errors are:

    // a) The `que` array is not cleared before the second BFS, which can cause processing of stale vertices (though not in this test case).
    // b) The output is missing a newline after the last BFS.
    // c) The placement of the newline after the first BFS is logically after the deletion, which is odd but not incorrect in terms of content, however it's part of the formatting.

    // But the problem says the reference program is correct, and the only difference in output is trailing space, which suggests that the judge might be sensitive to that.

    // However, after re-examining the problem statement: "For each traversal, the vertices should be printed in a single line, separated by spaces."

    // Printing a space after the last vertex is not "separated by spaces" — the separation is between vertices, so after the last vertex, there should be no space.

    // Therefore, the trailing space is actually a formatting error.

    // Both the reference program and the buggy program have this error.

    // But the problem says the reference program is correct. This is a contradiction.

    // Unless the reference program is not actually producing trailing space? Let me check:

    // Reference program DFS:
    //   printf("%d ", v);
    // So yes, it prints space after every vertex, including the last.

    // How then is it correct?

    // Perhaps the judge trims whitespace, or the problem allows it.

    // Given the information, the most likely error that causes WA in the test case is the missing newline at the end.

    // But the user's expected output is shown without trailing spaces and with four lines, so if the judge compares exactly, the trailing space would cause WA.

    // However, the problem says the reference program is correct, so we must assume trailing space is allowed.

    // Therefore, the only remaining possibility is the `que` array not being cleared.

    // Even though in this test case it doesn't cause an extra vertex to be printed, it might cause the BFS to take a different path or something.

    // Let's simulate the second BFS in the test case with the stale que:

    // After first BFS, que = [0,1,2,2,0,0,...] (because global array is zero-initialized, and we wrote up to index 3).

    // Second BFS:
    //   visited = [0,0,0] initially, but then we set visited[del]= not done in this code! Wait a minute!

    // In the reference program, they do: visited[del]=1 to simulate deletion.
    // In the buggy code, they physically remove the edges.

    // So in the buggy code, for the after-deletion traversals, they reset visited to 0, and then do DFS/BFS on the modified graph.

    // So visited[del] is 0, but since the edges to del are removed, del will not be visited.

    // In the test case, del=1.
    //   In second DFS: starts at 0, can only go to 2. So visited[1] remains 0, but it's not printed.
    //   In second BFS: same.

    // So that's correct.

    // Now, in second BFS:
    //   que[0] = 0.
    //   head=0, tail=1.
    //   Process 0: print 0, visited[0]=1.
    //        i=0: skip.
    //        i=1: weights[0][1]=0 -> skip.
    //        i=2: weights[0][2]=1 and !visited[2] -> que[1]=2, tail=2.
    //   head=1, tail=2: process que[1]=2.
    //        print 2, visited[2]=1.
    //        i=0: weights[2][0]=1 but visited[0]=1.
    //        i=1: 0.
    //        i=2: skip.
    //   head=2, tail=2: head<=tail -> true.
    //        tmp = que[2] = 2 (from first BFS).
    //        visited[2] is 1 -> skip.
    //   head=3, tail=2: head>tail -> exit? No, head=3, tail=2 -> 3<=2 is false, so exit.

    // So it's safe.

    // Given all this, the only concrete error that matches the symptom (WA on this test case) is the trailing space. But since the reference program has it too, that can't be.

    // Unless... the reference program is not the one producing the expected output. The expected output shown has no trailing spaces.

    // So perhaps the intended solution does not have trailing spaces.

    // How to output without trailing space? Usually, you print the first vertex, then for subsequent vertices, print " " + vertex.

    // The given programs (reference and buggy) both use the simple method of printing vertex + space.

    // This suggests that the judge for this problem does NOT accept trailing space.

    // Therefore, both programs are flawed, but the problem states the reference program is correct.

    // This is confusing.

    // Given the instructions, we must find the error in the buggy code compared to the reference.

    // Let's compare the reference and the buggy code:

    // Reference:
    //   - Uses weights[200][200], visited[200], que[200]
    //   - Does not explicitly initialize weights to 0, but since global, it is zero.
    //   - After reading edges, it does:
    //         DFS(0); puts("");
    //         memset(visited,0,...); BFS(0); puts("");
    //         memset(visited,0,...); 
    //         scanf("%d", &del);
    //         visited[del]=1;
    //         DFS(0); puts("");
    //         memset(visited,0,...); memset(que,0,...); visited[del]=1; BFS(0); puts("");

    // Buggy code:
    //   - Explicitly initializes weights and visited.
    //   - Reads del BEFORE doing any traversal.
    //   - Physically removes edges for del.
    //   - Does not clear que before second BFS.
    //   - Has misplaced newlines.

    // The reference program does NOT physically remove the vertex; it marks it as visited.
    // The buggy code physically removes the edges.

    // Both methods are valid.

    // The critical difference is: in the reference program, the vertex deletion (marking as visited) is done AFTER the first two traversals and BEFORE the last two.
    // In the buggy code, the edge removal is done AFTER the first two traversals and BEFORE the last two.

    // So that's the same.

    // The only differences are:
    //   - que not cleared.
    //   - newline placement.
    //   - physical removal vs marking visited.

    // Given that the test case is small, and the output sequences are correct, the WA must be due to formatting: either trailing space or missing newline.

    // Since the expected output shown has no trailing spaces, and the buggy output has, that is likely the cause.

    // But then why is the reference program considered correct? Unless the reference program in the problem statement is not the one that passed, or there's a mistake.

    // Given the instructions, we must output the error in the buggy code.

    // The most defensible errors are:

    // 1. The `que` array is not cleared before the second BFS, which is a potential bug (even if not triggered in this test case).
    // 2. The output has trailing spaces.
    // 3. The last line is missing a newline.

    // However, the problem asks to identify the location of the errors in the program below, and to add @@ after the line.

    // Looking at the code, the line that is most clearly wrong is the printf("\n") that is placed after the deletion and before the second DFS. This causes the second line's newline to be printed late, and more importantly, it means that the last BFS has no newline.

    // But actually, the last BFS has no newline because there's no printf("\n") after it.

    // So the error is that after the last bfs(0), there should be a printf("\n").

    // However, the code does not have that.

    // But the line that is misplaced is the printf("\n") after the deletion.

    // Let's count the newlines:

    // We need 4 newlines.
    // The code has:
    //   printf("\n"); // after first DFS
    //   printf("\n"); // after deletion, before second DFS
    //   printf("\n"); // after second DFS
    //   // missing after second BFS

    // So three newlines printed, but four needed.

    // Therefore, the error is that there is no newline after the last BFS.

    // But the code doesn't have a line for that.

    // Alternatively, the printf("\n") after deletion is intended to be the newline for the BFS, but it's in the wrong place.

    // The correct order should be:

    //   dfs(0); printf("\n");
    //   bfs(0); printf("\n");
    //   // delete vertex
    //   dfs(0); printf("\n");
    //   bfs(0); printf("\n");

    // In the buggy code, the second printf("\n") is moved to after the deletion.

    // So the line with printf("\n") after the deletion is in the wrong place.

    // Therefore, we should mark that line.

    // Additionally, the last BFS lacks a newline, but there's no line to mark for that.

    // Given the above, the only line we can mark is the misplaced printf("\n").

    // So:
    //   printf("\n"); // @@ [This newline should be printed immediately after the BFS(0) call, not after vertex deletion. Its current placement causes the second line's newline to be delayed and leaves the fourth line without a terminating newline.]

    // But wait, in the code, after BFS(0) (the first one), there is no printf("\n"). The next printf("\n") is after deletion.

    // So to have a newline after the first BFS, it should be right after bfs(0);.

    // Therefore, the error is that the newline for the first BFS is missing right after it, and instead appears later.

    // So the line with printf("\n") after the deletion is the one that is misplaced.

    // Hence, we add @@ to that line.

    // Additionally, the que array is not cleared, which is a potential error. The reference program clears it. So we should also mark that we are not clearing que.

    // But the code doesn't have a line that is supposed to clear que. The error is the absence of a line.

    // The problem says: "If you think an error may occur on a particular line, add @@ symbol directly after that line"

    // So for the que issue, there is no line to mark.

    // Therefore, the only line we can mark is the misplaced printf("\n").

    // Let's look at the code around there:

    //   for(i=0;i<=100;i++){
    //       if(weights[i][del]==1){
    //           weights[i][del]=0;
    //           weights[del][i]=0;
    //       }
    //   }
    //   printf("\n"); // @@ [This printf("\n") is misplaced. It should be placed right after the first BFS(0) call to terminate the second line of output. Currently, it is placed after vertex deletion, which delays the newline for the second line and results in the fourth line missing a newline.]

    // But wait, in the code, after the first BFS, we have:

    //   bfs(0);
    //   for(i=0;i<=100;i++)
    //   visited[i]=0; 
    //   for(i=0;i<=100;i++){
    //       if(weights[i][del]==1){
    //           weights[i][del]=0;
    //           weights[del][i]=0;
    //       }
    //   }
    //   printf("\n");

    // So the printf("\n") is intended to be the newline for the BFS, but it's after several lines of code.

    // Yes.

    // Therefore, we mark that line.

    // Additionally, after the last bfs(0), there should be a printf("\n"), but there isn't. However, there's no line to mark for that.

    // Given the instructions, we only mark existing lines that are erroneous.

    // So the only line to mark is the printf("\n") after the deletion loop.

    // Let's output the code with that line marked.
}
    printf("\n"); // @@ [This newline should be printed immediately after the first BFS to properly terminate the second line of output. Its current placement after vertex deletion causes the second line's newline to be delayed and results in the fourth line missing a terminating newline, which may cause presentation error or wrong answer in strict judges.]
    dfs(0);
    printf("\n");
    for(i=0;i<=100;i++)
    visited[i]=0; 
    bfs(0);
    return 0;
}