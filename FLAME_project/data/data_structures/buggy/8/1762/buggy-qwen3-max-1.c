#include<stdio.h>
int v[150]={0},A[150][150]={0},m,n,del=140,queue[150]={0};
void rejust()
{
    int i;
    for(i=0;i<m;i++)
    {
        if(i==del)
        v[i]=2;
        else
        v[i]=0;
    }
    printf("\n"); // @@ [This prints a newline immediately after resetting visited array, causing extra blank lines in output. It should only reset the array without printing.]
}
int isend()
{
    int i,flag=0;
    for(i=0;i<m;i++)
    if(v[i]==0)
    flag=1;
    if(flag==1)
    return -1;
    else
    return 1;
}
void DFS(int x)
{
    int i,j;
    if(v[x]==0)
    {
        v[x]=1;
        printf("%d ",x);
    }
    if(isend()==1)
    return ;
    for(i=0;i<m;i++)
    {
        if(A[x][i]==1&&v[i]==0)
        {
            DFS(i);
        }
    }
}
void BFS()
{
    int rear,front,x,i;
    queue[0]=0;
    rear=front=0;
    while(front<=rear)
    {
        if(isend()==1)
        break;
        x=queue[front++];
        printf("%d ",x); // @@ [Vertex x is printed before marking it as visited. However, in this implementation, v[x] might still be 0 when printed, but more critically, vertex 0 is never marked as visited before being enqueued or printed, leading to potential duplication or incorrect traversal order. Also, v[0] remains 0 initially, so it may be revisited.]
        for(i=0;i<m;i++)
        {
            if(A[x][i]==1&&v[i]==0)
            {
                queue[++rear]=i;
                v[i]=1; // @@ [Adjacent nodes are marked visited when enqueued, which is correct for BFS, but since the starting node (0) is not marked visited before the loop, it causes inconsistency.]
            }
        }
    }
}
int main()
{
    int a,b,i,j;
    scanf("%d%d",&m,&n);
    for(i=0,j=0;i<n;i++)
    {
        scanf("%d%d",&a,&b);
        A[a][b]=A[b][a]=1;
    }
    DFS(0);
    rejust();
    BFS(); // @@ [At this point, v[0] is still 0 because rejust() sets all non-del vertices to 0, including 0. But BFS() does not mark v[0] = 1 before printing, so it prints 0, but then when processing neighbors, it may enqueue 0 again if there's a self-loop (though none here), but more importantly, the logic in BFS doesn't ensure 0 is marked visited at start, leading to possible issues. However, the main error is that BFS prints "0 1" instead of "0 1 2" because after printing 0, it enqueues 1 and 2 (since graph is triangle), but due to the isend() check and loop condition, it may terminate early. Actually, the real issue is that in BFS, after printing x, it only enqueues unvisited neighbors, but since v[0] was never set to 1 before the loop, and is printed without being marked, but then when x=0 is processed, it marks neighbors 1 and 2 as visited and enqueues them. Then front=1, x=1 is dequeued and printed. Then from x=1, it checks neighbors: 0 (v[0]==0? Yes! Because v[0] was never set to 1!) so it would try to enqueue 0 again—but wait, in the given test case, after first BFS call, the output is "0 1", missing 2. Why? Because when x=0 is processed, it prints 0, then enqueues 1 and 2 and marks them visited. Then x=1 is dequeued and printed. Now from x=1, neighbors are 0 and 2. v[0] is still 0 (never marked!), so it would enqueue 0 again? But in the output we see only "0 1", so perhaps the loop ends early. Actually, looking at the BFS code: queue[0]=0; rear=front=0; then while(front<=rear): first iteration: x = queue[0] → front becomes 1, so x=0. Print 0. Then enqueue 1 and 2 → rear=2. Now front=1, rear=2 → continue. Next: x = queue[1] = 1, front=2. Print 1. Then from 1, check neighbors: i=0: A[1][0]=1, v[0]=0 → enqueue 0 again (rear=3, v[0]=1 now). i=2: A[1][2]=1, but v[2] was set to 1 when processing x=0, so skip. Then front=2, rear=3 → next: x=queue[2]=2, print 2. So why output is "0 1"? Because in the test run, the BFS output is "0 1", meaning it stopped early. The reason is the isend() function: isend() returns 1 only when all vertices are visited (v[i]!=0 for all i). But in rejust(), v[del] is set to 2, others to 0. So during BFS, when some vertices are still 0, isend() returns -1. But in the first BFS, del=140 (initial value), and m=3, so i from 0 to 2, del=140 ≠ i, so v[i]=0 for all. So isend() returns -1 until all are visited. So why early termination? Actually, the BFS code has: while(front<=rear) { if(isend()==1) break; ... } — so it shouldn't break early. But in the buggy output, BFS before deletion outputs "0 1", missing 2. This suggests that vertex 2 is not being printed. Looking again: when x=0 is processed, it prints 0, then for i=0 to m-1 (i=0,1,2): A[0][1]=1, v[1]=0 → enqueue 1, v[1]=1; A[0][2]=1, v[2]=0 → enqueue 2, v[2]=1. So queue = [0,1,2], rear=2, front becomes 1 after x=0. Then x=1 is printed. Then from x=1: i=0: A[1][0]=1, v[0]=0 → enqueue 0, v[0]=1; i=1: skip; i=2: A[1][2]=1, v[2]=1 → skip. Now queue has [0,1,2,0], rear=3, front=2. Then x=2 is dequeued (front=2 → x=queue[2]=2), printed. So output should be "0 1 2". But actual buggy output is "0 1". Therefore, the issue must be elsewhere. Wait: in main(), after DFS(0), it calls rejust(), which prints a newline. Then calls BFS(). But in BFS(), the starting vertex 0 is not marked as visited before the loop. However, in the BFS function, the first thing is queue[0]=0, then in the loop, x=queue[front++] → x=0, then it prints "0 ", but v[0] is still 0. Then it processes neighbors. But note: in the DFS call before, v[0] was set to 1, then rejust() sets v[0]=0 (since del=140≠0). So v[0]=0 at start of BFS. So far so good. But why is 2 not printed? Let's simulate step by step for test case:

Initial after reading: m=3, n=3, edges: 0-1,1-2,0-2. del=140.

DFS(0):
- v[0]=0 → print "0 ", v[0]=1
- isend(): v=[1,0,0] → flag=1 → return -1
- loop i=0→2: A[0][1]=1, v[1]=0 → DFS(1)
  - v[1]=0 → print "1 ", v[1]=1
  - isend(): v=[1,1,0] → -1
  - loop: A[1][0]=1 but v[0]=1; A[1][2]=1, v[2]=0 → DFS(2)
    - print "2 ", v[2]=1
    - isend(): all 1 → return
  - return
- then i=2: A[0][2]=1 but v[2]=1 → skip
So DFS prints "0 1 2 "

Then rejust(): sets v[0]=0, v[1]=0, v[2]=0 (since del=140), and prints "\n" → so output now: "0 1 2 \n\n"

Then BFS():
- queue[0]=0, rear=front=0
- while(front<=rear): front=0<=rear=0 → enter
  - isend(): v=[0,0,0] → -1 → continue
  - x = queue[0], front becomes 1 → x=0
  - print "0 "
  - for i=0→2:
    - i=0: A[0][0]=0 → skip
    - i=1: A[0][1]=1, v[1]=0 → queue[1]=1, rear=1, v[1]=1
    - i=2: A[0][2]=1, v[2]=0 → queue[2]=2, rear=2, v[2]=1
- now front=1, rear=2 → loop continues
  - isend(): v=[0,1,1] → flag=1 (v[0]=0) → -1
  - x=queue[1]=1, front=2
  - print "1 "
  - for i=0→2:
    - i=0: A[1][0]=1, v[0]=0 → queue[3]=0, rear=3, v[0]=1
    - i=1: skip
    - i=2: A[1][2]=1, v[2]=1 → skip
- front=2, rear=3 → continue
  - isend(): v=[1,1,1] → return 1 → break out of loop!
- So BFS prints "0 1 " and breaks before processing x=2.

Ah! Here's the critical error: after processing x=1, v becomes [1,1,1], so isend() returns 1, and the loop breaks before dequeuing and printing x=2 (which is at queue[2]). So vertex 2 is never printed in BFS.

Thus, the BFS function incorrectly uses isend() to break early, before processing all queued elements. The isend() check should not cause early termination because even if all vertices are visited, there might be remaining vertices in the queue that haven't been printed yet. In fact, in BFS, you should process all nodes in the queue regardless of whether all vertices are visited, because the queue contains nodes that need to be printed and processed.

But wait: in a connected graph, once all vertices are visited, no new nodes will be added, but already queued nodes still need to be printed. However, in this implementation, nodes are printed when dequeued, not when enqueued. So if the queue has [0,1,2], and after processing 0 and 1, all vertices become visited, then when about to process 2, isend() returns 1 and breaks, so 2 is never printed.

Therefore, the use of isend() inside BFS to break early is wrong.

Similarly, in DFS, isend() is used to return early, but DFS is recursive and may also skip printing some nodes if isend() triggers prematurely—though in DFS, since it's depth-first, it usually visits all before backtracking, so it might be less problematic, but still logically flawed.

However, in the test case, DFS worked correctly because it visited all before any isend() returned 1.

So the main errors are:

1. The rejust() function prints a newline, causing extra blank lines.
2. The BFS function uses isend() to break early, skipping printing of queued vertices.
3. Additionally, in BFS, the starting vertex is not marked as visited before the loop, but in this case, it gets printed and then its neighbors are processed, but the real issue is the premature break.

Also, note that in main(), the deletion happens after the first DFS and BFS, but the input for del is read after the first two traversals. That is correct per problem: first do traversals on original graph, then read del vertex, delete it, then do traversals again.

But in the provided code, del is initialized to 140, and the first rejust() uses this del=140, which is fine since 140 >= m (which is 3), so no vertex is marked as deleted in the first part.

Now, looking at the expected vs buggy output:

Buggy:
0 1 2 
0 1 
0 2 
0 2

Expected:
0 1 2
0 1 2
0 2
0 2

So the second line (BFS before deletion) is wrong: it's "0 1" instead of "0 1 2".

Thus, the key error is in BFS() using isend() to break early.

Additionally, the rejust() function prints a newline after each reset, which adds extra newlines. The expected output has no blank lines—each traversal is on its own line, four lines total. But the buggy output shows four lines as well, but with spaces at end and possibly extra newlines. However, the problem says "For each traversal, the vertices should be printed in a single line, separated by spaces." and the example output has no trailing spaces or blank lines. But the immediate issue is the missing "2" in BFS.

So to summarize errors:

- Line in rejust(): printf("\n"); → adds unwanted newline.
- BFS function: the isend() check causes early termination, skipping printing of remaining queue elements.
- Also, in BFS, the starting node is not marked visited before the loop, but in this logic, it's printed when dequeued, and since it's the first, it's okay, but the marking happens only for neighbors. However, v[0] remains 0 until it's encountered as a neighbor of someone else (like node 1), which causes isend() to think not all are visited until then. But the core issue is breaking before printing all queued nodes.

Now, annotating the code as instructed: add @@ after the line where error occurs.

We identify:

1. In rejust(), the printf("\n"); line → causes extra newline.
2. In BFS(), the line with "if(isend()==1) break;" → causes early termination.
3. Also, in BFS(), the printing of x happens without ensuring it's marked visited, but the bigger issue is the break.

But the problem says: "If you think an error may occur on a particular line, add @@ symbol directly after that line"

So:

- The printf("\n"); in rejust()
- The break statement in BFS (the line with "break;")
- Possibly the printing of x in BFS without prior visit mark, but the specification says to start from 0 and visit in order, and the main issue is the missing vertex due to early break.

Also, note that in the DFS function, the isend() check might be unnecessary but didn't cause error in this test case. However, it's still a flaw, but since the output for DFS is correct, maybe not required to mark. But to be safe, if isend() causes early return in DFS, it could skip some paths, but in a tree it's okay, but in graph with cycles, DFS marks visited so it won't revisit, so isend() is redundant and potentially harmful. However, in this test case, it worked.

But the problem only requires to mark lines that cause the observed error (wrong answer on given test case). The observed error is BFS before deletion missing vertex 2, which is due to the break in BFS.

Also, the extra newline from rejust() causes the output to have blank lines, but the sample buggy output shows four lines (with spaces), so maybe the judge trims or the newline is absorbed. However, the expected output has no blank lines, and the buggy output as shown has four lines, so perhaps the extra printf("\n") in rejust() is causing an extra newline between outputs. Looking at the buggy output:

"0 1 2 \n0 1 \n0 2 \n0 2"

But with rejust() printing \n after DFS and after BFS, the output becomes:

DFS: "0 1 2 "
rejust: prints \n → so line1: "0 1 2 \n"
then BFS: "0 1 "
rejust: prints \n → line2: "0 1 \n"
then after deletion: DFS: "0 2 "
rejust: \n
BFS: "0 2"

So total output: "0 1 2 \n\n0 1 \n\n0 2 \n\n0 2"

But the buggy output is shown as four lines, so maybe the display collapses, but the problem says "Wrong Answer", and expected has no trailing spaces or extra newlines. However, the primary issue is the content of the second line.

Given the instructions, we mark the lines that directly cause the logical error in traversal.

Thus:

- In rejust(), the printf("\n"); line.
- In BFS(), the "break;" line (inside if(isend()==1)).
- Also, in BFS(), the printing of x without having marked it visited might not be the direct cause, but the break is.

Additionally, note that in the BFS function, the starting vertex 0 is enqueued but not marked visited. Then when it's dequeued and printed, it's still unmarked, and later when processing neighbor 1, it sees 0 as unvisited and enqueues it again. This causes duplicate enqueue, but in this case, it leads to v[0] being marked only when processed as neighbor, which delays isend() returning 1. But the immediate cause of missing "2" is the break before processing queue[2].

So annotate:

- rejust()'s printf("\n");
- BFS's break statement line.

Also, note that in main(), the order is: do DFS, rejust (which prints \n), do BFS, rejust (prints \n), then read del, delete, then DFS, rejust, BFS.

But the problem expects:

line1: DFS before
line2: BFS before
line3: DFS after
line4: BFS after

With no extra lines. So the two rejust() calls after first DFS and BFS each add a newline, resulting in:

line1: DFS output + space + \n (from DFS's own printf with space and then \n from rejust)
Actually, DFS prints "0 1 2 " (with trailing space), then rejust prints \n → so line1 ends with space and \n.
Then BFS prints "0 1 " (with trailing space), then rejust prints \n → line2 ends with space and \n.
Then after deletion: DFS prints "0 2 ", rejust prints \n.
BFS prints "0 2" (no trailing space? but in code, it prints with space), and no rejust after last BFS.

But the expected output has no trailing spaces, but the problem may ignore whitespace. However, the main issue is the missing "2" in BFS before.

So focus on the BFS break.

Now, write the annotated code.