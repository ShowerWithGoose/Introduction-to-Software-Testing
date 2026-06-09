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
    printf("\n"); // @@ [This printf("\n") is misplaced. It should come AFTER the second DFS and BFS, not before. This causes an extra blank line between the "before deletion" and "after deletion" outputs, but more critically, it shifts the order of operations: the vertex deletion happens AFTER printing the first two traversals but BEFORE the newline that separates the two groups. However, the real issue is that the deletion occurs AFTER the first BFS, which is correct, but the output formatting is wrong because the newline separating the two groups is printed BEFORE the second DFS, causing the second DFS to be on a new line (which is okay), but the bigger problem is in BFS queue handling and visited array reset timing. However, looking at the actual output vs expected, the sequences are correct but the newlines may not match. But the test case shows the output has correct sequences and same number of lines. So the real bug is elsewhere.]

    // Actually, looking closer: the expected output has 4 lines, and the buggy output also has 4 lines.
    // The real issue is that in the BFS function, the queue 'que' is never reset to zero before the second BFS.
    // In the reference program, they do: memset(que, 0, sizeof(que));
    // But in this buggy code, after the first BFS, the 'que' array still contains old values.
    // During the second BFS, the while loop condition uses 'head <= tail', and 'tail' starts at 1,
    // but the que array might have leftover indices from the first BFS that are beyond tail,
    // however, more critically, the que array is not reinitialized, so when we do que[tail++] = i,
    // we are writing into potentially dirty memory, but more importantly, the initial state of que is not clean.

    // However, note that in the second BFS call, we set:
    //   head = 0, tail = 1, and que[head] = v (which is 0).
    // So the initial setup overwrites que[0]. But what about other positions?
    // The BFS loop only accesses que from head to tail-1, and we start with tail=1, so only que[0] is used initially.
    // Then we add new nodes starting at que[1], que[2], etc.
    // So maybe the que array doesn't need to be zeroed? But the reference program does it.

    // Let's check the test case:
    // After deleting vertex 1, the graph has edges: 0-2 only.
    // Second DFS: starts at 0, prints 0, then visits 2 (since 1 is removed), prints 2 -> "0 2"
    // Second BFS: 
    //   que[0] = 0, head=0, tail=1.
    //   tmp = que[0] = 0, head becomes 1.
    //   visited[0] is 0 -> print 0, mark visited[0]=1.
    //   Then loop i=0 to 2: 
    //      i=0: weights[0][0]=0 -> skip.
    //      i=1: weights[0][1] was set to 0 (because we deleted 1) -> skip.
    //      i=2: weights[0][2]=1 and visited[2]=0 -> que[tail=1] = 2, tail becomes 2.
    //   Now head=1, tail=2 -> head<=tail -> true.
    //   tmp = que[1] = 2, head becomes 2.
    //   visited[2] is 0 -> print 2, mark visited[2]=1.
    //   Then for i=0..2: 
    //        i=0: weights[2][0]=1 but visited[0]=1 -> skip.
    //        i=1: weights[2][1]=0 -> skip.
    //        i=2: skip.
    //   Then head=2, tail=2 -> head<=tail -> true.
    //   tmp = que[2] -> but what is que[2]? 
    //   In the first BFS, que might have had values beyond index 1. 
    //   For the first BFS (before deletion): 
    //        n=3, graph complete.
    //        que[0]=0, then we add 1 and 2 -> que[1]=1, que[2]=2, tail=3.
    //        Then we process que[1]=1 -> add nothing new (0 and 2 already in queue or visited? Actually, when processing 1, 0 is visited, 2 is not visited -> so que[3]=2? But wait, 2 was already added by 0? 
    //        Actually, in BFS from 0: 
    //          Start: que=[0], head=0, tail=1.
    //          Process 0: print 0, then add 1 and 2 -> que[1]=1, que[2]=2, tail=3.
    //          Then process 1: print 1, then check neighbors: 0 (visited), 2 (not visited? But 2 is already in the queue, but visited[2] is still 0 -> so we would add 2 again? 
    //        This is a flaw in the BFS implementation: it adds nodes to the queue even if they are already in the queue (but not visited). This leads to duplicates.
    //        So in the first BFS, que might be [0,1,2,2] or something.
    //        Then when we do the second BFS, we start with que[0]=0, but que[1], que[2], etc. still have old values.
    //        In the second BFS, after processing 0 and adding 2 at que[1], then we process que[1]=2 (correctly).
    //        Then head becomes 2, and we look at que[2] which is leftover from first BFS (say 2 or something else).
    //        If que[2] is 2, then we try to process 2 again, but visited[2] is now 1, so we skip.
    //        Then head=3, tail=2 -> head>tail -> loop ends.
    //        So it might still work.

    // But wait, the test case output for BFS after deletion is "0 2", which is correct.

    // So why is the judge saying Wrong Answer? The output shown matches expected.

    // However, looking at the provided "Buggy Output" and "Expected Output", they are identical in content, but the problem says "Wrong Answer".

    // But note: the problem says:
    //   Buggy Output:
    //   0 1 2 
    //   0 1 2 
    //   0 2 
    //   0 2
    //
    //   Expected Output:
    //   0 1 2
    //   0 1 2
    //   0 2
    //   0 2
    //
    // The only difference is trailing spaces. The problem likely does not want trailing spaces at the end of each line.

    // In the DFS and BFS functions, they print each vertex as "%d ", which includes a space after the last number.

    // The reference program also does this, but the problem's expected output does not have trailing spaces.

    // However, the problem statement says: "the vertices should be printed in a single line, separated by spaces." 
    // It doesn't specify no trailing space, but many judges are strict.

    // But the reference program is given as correct, and it uses the same printf("%d ", v). 
    // So probably the judge trims or accepts trailing space.

    // Alternatively, the real bug is in the order of operations:

    // In the buggy code:
    //   - Read n, m
    //   - Initialize weights and visited
    //   - Read edges
    //   - Read 'del'
    //   - Then do DFS(0) [before deletion]
    //   - Then reset visited and do BFS(0) [before deletion]
    //   - Then reset visited
    //   - Then delete the vertex (by zeroing edges to 'del')
    //   - Then print a newline
    //   - Then do DFS(0) [after deletion]
    //   - Then reset visited
    //   - Then do BFS(0) [after deletion]

    // This seems correct.

    // But wait: the reference program does:
    //   - Read n, m
    //   - Read edges
    //   - Do DFS(0) [before]
    //   - Reset visited, do BFS(0) [before]
    //   - Read 'del'
    //   - Mark visited[del]=1 (so it's skipped in traversal)
    //   - Do DFS(0) [after]
    //   - Reset visited and que, mark visited[del]=1, do BFS(0) [after]

    // The buggy code physically removes the edges, while the reference marks the vertex as visited.

    // Both approaches are valid.

    // However, there is a critical bug in the buggy code's BFS: the queue 'que' is a global array and is not reset before the second BFS.
    // In the first BFS, the 'tail' might go up to, say, 3 (for n=3). Then in the second BFS, we start with tail=1, but the que array still has values at indices >=1 from the first BFS.
    // Although we overwrite que[0] and then write new values starting at que[1], the while loop condition is 'head <= tail', and we only write up to tail-1 in the new BFS.
    // However, when we do 'que[tail++] = i', we are writing to que[1], que[2], etc., which might have old values, but that's okay because we are overwriting.
    // The real issue is that the BFS loop might read beyond what we wrote if the old 'tail' was larger, but no: in the second BFS, we start with tail=1, and we only increment tail as we add new nodes.
    // And head starts at 0 and increases. So it should be safe.

    // Another possibility: the visited array reset loops go to i<=100, but the array is of size 101 (indices 0..100). So that's correct.

    // But note: in the first visited reset after DFS:
    //   for(i=0;i<=100;i++) visited[i]=0;
    // This is okay.

    // However, there is a more subtle bug: in the BFS function, the condition is 'while (head <= tail)'. 
    // Initially, tail=1, so the queue has one element at index 0.
    // After processing that, head becomes 1, and if no new elements are added, tail is still 1, so head(1) <= tail(1) -> true, and we try to access que[1], which was not initialized in the second BFS (but might have old value).
    // In the second BFS for the test case:
    //   After processing 0, we add 2 at que[1], so tail becomes 2.
    //   Then head=1, tail=2 -> process que[1]=2.
    //   Then after processing 2, no new nodes, so tail remains 2.
    //   Then head becomes 2, and 2<=2 -> true, so we access que[2].
    //   What is que[2]? It's leftover from the first BFS. In the first BFS, que[2] was set to 2 (when adding neighbors of 0).
    //   So we get tmp = 2, but visited[2] is already 1 (from when we processed it as que[1]), so we skip.
    //   Then head becomes 3, and 3<=2 is false -> exit.
    //   So it works.

    // But what if the leftover value in que[2] was a different vertex, say 1? 
    //   Then we would try to process vertex 1, but visited[1] is 0? 
    //   However, we have deleted vertex 1 by removing its edges, but we haven't marked it as visited.
    //   In the second BFS, visited[1] is 0 (because we reset visited before the second BFS, and then didn't touch it).
    //   But vertex 1 is disconnected (since we removed all its edges), so it shouldn't be traversed.
    //   However, if que[2] is 1 (from first BFS), then in the second BFS:
    //        When head=2, tmp=1.
    //        visited[1] is 0 -> so we would print 1 and mark it visited.
    //        But vertex 1 is not connected to 0 anymore, so it should not be printed.
    //   This would be an error.

    // Let's simulate the first BFS for the test case (n=3, edges: 0-1,1-2,0-2):
    //   Start: que[0]=0, head=0, tail=1.
    //   Process 0: print 0, visited[0]=1.
    //        Add 1: que[1]=1, tail=2.
    //        Add 2: que[2]=2, tail=3.
    //   Then head=1: tmp=1, not visited -> print 1, visited[1]=1.
    //        Check neighbors: 0 (visited), 2 (not visited) -> add 2: que[3]=2, tail=4.
    //   Then head=2: tmp=2, not visited -> print 2, visited[2]=1.
    //        Neighbors: 0 (visited), 1 (visited) -> nothing added.
    //   Then head=3: tmp=2 (from que[3]), but visited[2] is 1 -> skip.
    //   Then head=4: 4<=4? tail=4, so head=4<=4 -> true, tmp=que[4] -> uninitialized! 
    //   But in C, global arrays are zero-initialized, so que[4]=0.
    //   Then tmp=0, visited[0]=1 -> skip.
    //   Then head=5, 5<=4 -> false.
    //   So que[0]=0, que[1]=1, que[2]=2, que[3]=2, que[4]=0.

    // Now, second BFS (after deleting vertex 1, so edges: only 0-2):
    //   Start: que[0]=0, head=0, tail=1.
    //   Process 0: print 0, visited[0]=1.
    //        i=0: skip.
    //        i=1: weights[0][1]=0 -> skip.
    //        i=2: weights[0][2]=1 and visited[2]=0 -> que[1]=2, tail=2.
    //   Then head=1: tmp=que[1]=2 -> print 2, visited[2]=1.
    //        Then for i: no new nodes, tail remains 2.
    //   Then head=2: 2<=2 -> true, tmp=que[2]=2 (from first BFS).
    //        visited[2] is 1 -> skip.
    //   Then head=3: 3<=2 -> false.
    //   So output is "0 2", which is correct.

    // But what if the graph was different? The problem states the graph is connected after deletion, and the test case is small.

    // However, the problem says the program failed on this test case, but the output matches.

    // Re-examining the provided "Buggy Output" and "Expected Output": 
    //   They are shown with trailing spaces in the buggy output, but without in expected.
    //   But the problem might be that the judge is comparing exactly, and the trailing space causes WA.

    // But the reference program also outputs trailing spaces, and it's given as correct.

    // Another possibility: the order of resetting visited and reading 'del'.

    // In the buggy code, 'del' is read BEFORE the first DFS and BFS.
    // That is correct.

    // The real bug is in the BFS function: the queue 'que' is global and not reset, but as we saw, it might work for this test case.

    // However, there's a more fundamental issue: in the second BFS, after resetting visited, we do not reset the 'que' array, but the BFS function uses a local 'head' and 'tail', so it should be fine.

    // Let me check the array bounds in the visited reset:
    //   for(i=0;i<=100;i++) visited[i]=0;
    //   visited is of size 101, so indices 0..100 -> correct.

    // But wait: in the edge initialization:
    //   for(i=0;i<100;i++)
    //   for(int j=0;j<100;j++)
    //   weights[i][j]=0;
    //   This only initializes up to 99x99, but the graph can have up to 100 vertices (0..99), so it's okay.
    //   However, if num_vertex is 100, then we access weights[99][99], which is within [0..99][0..99] -> okay.

    // Another issue: in the deletion loop:
    //   for(i=0;i<=100;i++){
    //        if(weights[i][del]==1){
    //            weights[i][del]=0;
    //            weights[del][i]=0;
    //        }
    //   }
    //   This goes to i=100, but weights is [101][101], so i=100 is valid.
    //   But the graph only has vertices 0 to num_vertex-1, so for i>=num_vertex, weights[i][del] is 0 anyway.
    //   So it's harmless.

    // After careful analysis, the only discrepancy is the extra printf("\n") in the middle.

    // In the buggy code:
    //   After the first BFS, we have:
    //        bfs(0);
    //        for(i=0;i<=100;i++) visited[i]=0; 
    //        [deletion loop]
    //        printf("\n");   // This prints a newline HERE
    //        dfs(0);
    //        printf("\n");
    //        ...
    //   So the output is:
    //        [DFS before] \n
    //        [BFS before] 
    //        \n
    //        [DFS after] \n
    //        [BFS after]
    //
    //   Which means:
    //        Line1: DFS before
    //        Line2: BFS before
    //        Line3: (empty)
    //        Line4: DFS after
    //        Line5: BFS after
    //
    //   But the expected output has 4 lines, not 5.

    // However, looking at the provided "Buggy Output", it shows 4 lines:
    //        0 1 2 
    //        0 1 2 
    //        0 2 
    //        0 2
    //
    //   How is that possible?

    // Let's trace the print statements:
    //   dfs(0); -> prints "0 1 2 " (without newline)
    //   printf("\n"); -> so line1: "0 1 2 "
    //   bfs(0); -> prints "0 1 2 " (without newline)
    //   [then we do deletion and then] printf("\n"); -> so after BFS, we haven't printed a newline yet!
    //   So after bfs(0), the output is: "0 1 2 0 1 2 "
    //   Then we print a newline -> so line2: "0 1 2 0 1 2 "
    //   Then dfs(0) for after: prints "0 2 "
    //   Then printf("\n") -> line3: "0 2 "
    //   Then bfs(0) for after: prints "0 2"
    //   And no final newline? But the program ends.

    // But wait, the code:
    //   dfs(0); 
    //   printf("\n");   // after first DFS
    //   ... reset visited
    //   bfs(0);         // this prints without a newline at the end
    //   ... reset visited and delete
    //   printf("\n");   // this prints a newline AFTER bfs(0) and BEFORE second dfs
    //   dfs(0);
    //   printf("\n");
    //   ... reset visited
    //   bfs(0);         // prints without newline

    // So the output is:
    //   [first DFS] + '\n' 
    //   [first BFS] 
    //   '\n'
    //   [second DFS] + '\n'
    //   [second BFS]

    // Which is:
    //   Line1: first DFS
    //   Line2: first BFS (but without a newline, so it's on the same line as the next thing? No, because after first BFS, we don't print newline, then we print a newline -> so first BFS is on line1? Let me see:

    //   After first DFS: we have "0 1 2 \n"
    //   Then first BFS: appends "0 1 2 " to the output -> so now: "0 1 2 \n0 1 2 "
    //   Then we do: printf("\n") -> appends "\n", so now: "0 1 2 \n0 1 2 \n"
    //   Then second DFS: appends "0 2 \n" -> "0 1 2 \n0 1 2 \n0 2 \n"
    //   Then second BFS: appends "0 2"

    //   So the output has:
    //        Line1: "0 1 2 "
    //        Line2: "0 1 2 "
    //        Line3: "0 2 "
    //        Line4: "0 2"

    //   Which matches the "Buggy Output" shown.

    //   And the expected output is shown as:
    //        0 1 2
    //        0 1 2
    //        0 2
    //        0 2

    //   So the only difference is trailing spaces.

    //   But the problem says "Wrong Answer", so likely the judge does not want trailing spaces.

    //   However, the reference program also outputs trailing spaces, and it's given as correct.

    //   Unless... the reference program is not actually used for judging, but is just a correct logic example.

    //   The problem says: "the reference program correctly implemented", so it should be accepted.

    //   This suggests that the trailing space is acceptable.

    // Given the above, the only remaining possibility is that the BFS function has a bug in the queue management that manifests in other test cases, but for this test case it works.

    // But the problem states that the program failed on this test case.

    // Re-read the problem: "the test case inputs that the program failed"

    // And the buggy output is shown as having trailing spaces, and expected without, but maybe the judge's expected output also has trailing spaces and the display here is trimmed.

    // After re-examining the code structure, I notice:

    // In the main function, after the first BFS, we reset visited, then do the deletion, then print a newline, then do second DFS.

    // But the reference program does:
    //   DFS(0); puts("");
    //   memset(visited,0,...); BFS(0); puts("");
    //   then read del
    //   then set visited[del]=1, DFS(0); puts("");
    //   then reset visited and que, set visited[del]=1, BFS(0); puts("");

    // So the reference program outputs a newline after EVERY traversal.

    // In the buggy code:
    //   First DFS: followed by printf("\n") -> good.
    //   First BFS: NOT followed by a newline immediately. Instead, after first BFS, we do some resets and deletion, then printf("\n") which serves as the newline for the first BFS.
    //   So first BFS does get a newline, but it's delayed.

    //   Second DFS: followed by printf("\n") -> good.
    //   Second BFS: NOT followed by a newline.

    //   The expected output has 4 lines, so each traversal should be on its own line.

    //   In the buggy output as shown, there are 4 lines, so it seems okay.

    //   But the very last line (second BFS) does not have a newline at the end of the output.
    //   Some judges require a newline at the end of the output.

    //   The expected output as shown has 4 lines, which implies the last line should end with a newline.

    //   In the buggy code, after the second BFS, there is no printf("\n").

    //   Whereas in the reference program, after the last BFS, there is puts("").

    //   So the buggy code's output is:
    //        line1: ...\n
    //        line2: ...\n
    //        line3: ...\n
    //        line4: ...   [no newline]

    //   This might cause a "Presentation Error" or "Wrong Answer" if the judge expects a newline at the end.

    //   The expected output as displayed in the problem has 4 lines, which typically means 4 newline characters, i.e., the last line also ends with a newline.

    //   Therefore, the bug is that the last BFS is not followed by a newline.

    //   Additionally, the first BFS's newline is printed in the wrong place (after the deletion), but that doesn't affect the line count.

    //   However, the immediate cause for WA on this test case is likely the missing newline after the last BFS.

    //   But the provided "Buggy Output" shows 4 lines, which suggests that the output does have newlines after each, including the last.

    //   How? Because the second BFS is the last thing, and if the output is "0 2" without newline, then when displayed, it might appear as a fourth line, but technically it's not a complete line.

    //   Judges usually require a newline at the end.

    //   So the error is: missing newline after the last BFS.

    //   But looking at the code: after bfs(0) at the end, there is no printf("\n").

    //   In the reference program, there is puts("") after every traversal.

    //   So the buggy code should have a printf("\n") after the last bfs(0).

    //   However, the problem says to identify the location of the errors by adding @@ after the line.

    //   The last line of main is: bfs(0);
    //   And there's no newline after it.

    //   But the expected output format says: "For each traversal, the vertices should be printed in a single line", which implies each of the four traversals should be on its own line, so four newlines.

    //   The buggy code only prints three newlines:
    //        after first DFS
    //        after first BFS (via the misplaced printf("\n"))
    //        after second DFS
    //   and none after second BFS.

    //   Therefore, the error is that the last BFS is not followed by a newline.

    //   However, the line that is missing the newline is not present in the code; we need to add it.

    //   But the instruction is: "If you think an error may occur on a particular line, add @@ symbol directly after that line"

    //   The last line is: bfs(0);
    //   After this line, we should have a newline, but we don't.

    //   So we can annotate the bfs(0); line as missing a newline.

    //   But the error is not in the bfs function, but in the main function after calling bfs.

    //   Since the line "bfs(0);" is the last line, and it doesn't print a newline, and the problem requires each traversal on its own line, this line is where the error manifests.

    //   However, the reference program does puts("") after BFS, so the fix is to add a newline after bfs(0).

    //   Therefore, the line "bfs(0);" is missing a subsequent newline.

    //   But the instruction is to add @@ after the line that has the error.

    //   So: bfs(0); // @@ [Missing newline after last BFS traversal]

    //   Additionally, there's another issue: the newline after the first BFS is printed AFTER the deletion, which is logically after the "before deletion" part, but it's still before the "after deletion" traversals, so it separates the two groups. However, the bigger issue is the missing final newline.

    //   Given the test case output shown has 4 lines, and if the judge requires exactly 4 lines with newlines, then the absence of the final newline would make it 3 full lines and a partial fourth, which might be reported as WA.

    //   So the primary error is the missing newline after the last BFS.

    //   Let's check the reference program: it has puts("") after every traversal, including the last.

    //   Therefore, the buggy code should have a printf("\n") after the last bfs(0).

    //   Hence, the error is on the last line.

    //   But wait, the problem's expected output is shown without trailing spaces and with 4 lines, so likely they do want a newline at the end.

    //   Conclusion: the last line "bfs(0);" should be followed by a newline.

    //   Annotate that line.

    //   However, there's also a potential issue with the BFS queue not being reset, but for this test case it works, and the problem says it failed on this test case, so the newline is the likely culprit.

    //   Given the output shown in the problem for buggy output has spaces at the end of each line, and if the judge is strict about whitespace, then the trailing space might be the issue.

    //   But the reference program has the same trailing space issue, so probably not.

    //   Given the time, I'll go with the missing final newline.

    //   So the last line: bfs(0); // @@ [Missing newline after the last BFS output]

    //   But the problem says the output has 4 lines, so maybe in their system it's displayed as 4 lines even without the final newline.

    //   Another possibility: the first BFS is not followed by a newline immediately, but that doesn't cause a problem because we later print a newline.

    //   The real smoking gun is in the BFS function: the condition 'head <= tail' should be 'head < tail'.

    //   Let me check:
    //        Initially, tail=1, head=0: 0<=1 -> true.
    //        After processing head=0, head becomes 1.
    //        If no new elements, tail=1, then head=1<=1 -> true, and we access que[1], which is out of the current queue.
    //   In a standard queue, we should have head < tail.

    //   In the first BFS for the test case, after processing 0, we have head=1, tail=3.
    //   Then we process head=1 (que[1]=1), head becomes 2.
    //   Then process head=2 (que[2]=2), head becomes 3.
    //   Then head=3, tail=3: 3<=3 -> true, and we access que[3]=2 (from duplicate addition), which is okay because we check visited.
    //   But ideally, the condition should be head < tail.

    //   However, the reference program uses 'head <= tail', so it's intentional.

    //   Given the above, the only concrete error that fits the symptom (WA on this test case with otherwise correct sequences) is the trailing space or the missing final newline.

    //   Since the problem's expected output is shown without trailing spaces, and the buggy output with, and many judges trim spaces, but some don't, it's possible.

    //   But the reference program is given as correct and it uses trailing spaces, so likely the judge accepts trailing spaces.

    //   Therefore, the missing final newline is the error.

    //   Annotate the last line.

    //   However, looking back at the provided buggy output, it shows 4 lines, which suggests that in the testing environment, the output is being displayed as 4 lines, so maybe the final newline is not the issue.

    //   Let me count the newlines in the buggy code output:
    //        Line1: dfs(0) + "\n" -> 1 newline.
    //        Then bfs(0) prints without newline.
    //        Then printf("\n") -> second newline.
    //        Then dfs(0) + "\n" -> third newline.
    //        Then bfs(0) prints without newline.
    //        So total newlines: 3.
    //        This means the output has 3 newlines, so 4 lines only if the last line is non-empty, but technically, the POSIX standard requires a newline at the end of the file.

    //   Many judges require the last line to end with a newline.

    //   So the output is:
    //        "0 1 2 \n0 1 2 \n0 2 \n0 2"
    //   This is 3 newlines, and the last line "0 2" is not terminated.

    //   The expected output should be:
    //        "0 1 2\n0 1 2\n0 2\n0 2\n"
    //   or at least
    //        "0 1 2\n0 1 2\n0 2\n0 2" with a newline at the end.

    //   Given the problem's expected output is shown as 4 lines, it likely includes a newline after the last line.

    //   Therefore, the error is the missing newline after the last BFS.

    //   So the last line of code: bfs(0); should be followed by a newline.

    //   Annotate that line.

    //   Additionally, there's another error: the newline after the first BFS is printed AFTER the deletion, which is after we've already read 'del' and done the first two traversals, but before the second DFS. This is logically after the "before deletion" section, so it's okay as a separator. But the reference program prints the newline immediately after each traversal.

    //   However, the critical error for WA is the missing final newline.

    //   So I will annotate the last line.

    //   But wait, the problem might have another error: in the BFS function, the queue 'que' is not reset, and for larger graphs, it might cause issues, but for this test case it works.

    //   Given the instructions, and since the test case is small, the intended error is the missing final newline.

    //   Final decision: annotate the last line.

    //   However, looking at the code again, after the second DFS, we have:
    //        dfs(0);
    //        printf("\n");
    //        for(i=0;i<=100;i++)
    //        visited[i]=0; 
    //        bfs(0);
    //   So the last thing is bfs(0), and no newline.

    //   Yes.

    //   Therefore:
    bfs(0); // @@ [Missing newline after the last BFS traversal; each traversal must be on its own line, so a newline is required after the last BFS output]
    return 0;
}