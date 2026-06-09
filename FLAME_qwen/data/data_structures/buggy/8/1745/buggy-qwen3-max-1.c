#include<stdio.h>
#include<string.h>
#include<ctype.h>

int n,m,del;
int G[110][110];
int vis[110],vis_[110];

void dfs(int x) {
    printf("%d ",x);
    vis[x] = 1;
    for(int i=0 ; i<n ; i++) {
        if(i == x || vis[i] || !G[x][i]) continue;
        dfs(i);
    }
}

void dfs_(int x) {
    printf("%d ",x);
    vis_[x] = 1;
    for(int i=0 ; i<n ; i++) {
        if(i == x || vis_[i] || i == del || !G[x][i]) continue;
        dfs_(i);
    }
}

int l = -1,r,q[200];
int Vis[110],Vis_[110];

void bfs() {
    q[++ l] = 0;
    Vis[0] = 1;
    while(l <= r) { // @@ [The queue indices are incorrectly managed: 'l' is incremented before processing, and 'r' is never initialized properly for the first BFS call, leading to undefined behavior. Also, 'r' should be initialized to 0 when starting BFS, but it's only set in bfs_().]
        int x = q[l];
        printf("%d ",x);
        l ++;
        for(int i=0 ; i<n ; i++) {
            if(Vis[i] || !G[x][i]) continue;
            q[++ r] = i;
            Vis[i] = 1;
        }
    }
}

void bfs_() {
    l = -1,r = 0;
    q[++ l] = 0;
    Vis_[0] = 1;
    while(l <= r) {
        int x = q[l];
        printf("%d ",x);
        l ++;
        for(int i=0 ; i<n ; i++) {
            if(Vis_[i] || !G[x][i] || i == del) continue;
            q[++ r] = i;
            Vis_[i] = 1;
        }
    }
}

int main() {
    scanf("%d%d",&n,&m);
    for(int i=1 ; i<=m ; i++) {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u][v] = 1;
        G[v][u] = 1;
    }
    scanf("%d",&del);
    dfs(0); printf("\n");
    dfs_(0); printf("\n"); // @@ [The problem requires outputting DFS and BFS sequences BEFORE deletion first, then AFTER. But here, the second line is dfs_ (after deletion), which is correct, however the next two lines call bfs() and bfs_(), but bfs() uses global variables 'l' and 'r' that were modified by previous traversals and not reset properly. Specifically, 'r' is uninitialized in bfs().]
    bfs(); printf("\n"); // @@ [In bfs(), 'r' is used uninitialized. At program start, 'r' is 0 globally, but after dfs_(), nothing resets 'r'. However, more critically, in the first call to bfs(), 'r' is 0 from global init, but the queue logic is flawed because 'l' starts at -1, then q[++l]=0 sets l=0, but the loop condition is l<=r (0<=0), then inside, x=q[0], then l++ makes l=1, so next iteration l=1, r=0 -> loop ends. That works for first BFS. BUT the real issue is that in bfs(), the variable 'r' is global and shared with bfs_(), and after bfs_() runs, 'r' is left at some value, but that doesn't affect first bfs(). However, looking closer: the main error is that in bfs(), the queue index 'r' is never initialized at the start of the function. It relies on global initialization (which sets r=0), but after the first bfs() call, if we were to call it again, it would fail. However, in this code, bfs() is only called once. But wait: the bigger issue is in the BFS logic itself — the queue management is off-by-one and inconsistent. However, the immediate cause of failure is likely that in bfs(), the variable 'r' is not reset to 0 at the beginning of the function. Since 'r' is global and initially 0, the first bfs() might work, but let's check the test case. However, the problem says the buggy output is a compilation error: "/bin/sh: 1: gcc: not found", which is not a code error but an environment issue. But the user says "Error type: Compilation Error", yet the provided source compiles fine. This suggests the actual error is runtime or logical. But the instruction says to find errors in the program based on failed test cases. Given the expected behavior, the real bug is in BFS implementation: in bfs(), 'r' is not initialized. In the global scope, 'r' is initialized to 0, so first call may work. However, in bfs_(), 'r' is set to 0, but in bfs(), it's not. But since bfs() is called before bfs_(), and 'r' starts as 0, it's okay. However, looking at the BFS loop: 
        q[++l] = 0; // l becomes 0
        while (l <= r) // r is 0, so enter
            x = q[l]; // x = q[0]
            printf...
            l++; // l becomes 1
            then enqueue neighbors: q[++r] = i; so r becomes number of neighbors
        Then next iteration: l=1, r = (say) 2 -> l<=r true
        Then x = q[1], then l becomes 2
        Then process, etc.
    This seems okay. But wait: the initial value of 'r' is 0 (from global init). So for the first BFS, it's correct.

    However, there's another critical error: in main(), the output order is:
        dfs(0);      // before deletion DFS
        dfs_(0);     // after deletion DFS
        bfs();       // before deletion BFS
        bfs_();      // after deletion BFS
    But the problem says:
        First, output DFS and BFS sequences BEFORE deleting
        Then, output DFS and BFS sequences AFTER deleting

    So the expected output order is:
        DFS_before
        BFS_before
        DFS_after
        BFS_after

    But the code outputs:
        DFS_before
        DFS_after
        BFS_before
        BFS_after

    This is a logic error in output order.

    Therefore, the main error is in main(): the calls to dfs_ and bfs are in wrong order.

    So the error is in main() function: after printing dfs(0), it should print bfs(), not dfs_(0).

    Hence, the lines in main() are incorrect.

    Specifically:
        dfs(0); printf("\n");
        dfs_(0); printf("\n");   // @@ [This should be BFS before deletion, not DFS after. The output order is wrong: it prints DFS before, then DFS after, but should print DFS before, then BFS before, then DFS after, then BFS after.]
        bfs(); printf("\n");
        bfs_();

    So the second and third lines in the output section of main() are swapped in purpose.

    Therefore, the error is on the line calling dfs_(0) too early.

    Additionally, the bfs() function has a potential issue with queue indexing, but the primary error causing wrong output is the order.

    Also, note that in bfs(), the variable 'r' is global and not reset, but since it's the first use and initialized to 0 globally, it's okay. However, in a stricter sense, it's bad practice, but not the cause of failure.

    The problem states the graph is connected and vertex 0 is not deleted, so traversals start at 0.

    Given the test case input, the expected output order is:
        DFS before
        BFS before
        DFS after
        BFS after

    But the program outputs:
        DFS before
        DFS after
        BFS before
        BFS after

    So the second line is wrong.

    Therefore, the error is in main() where dfs_(0) is called before bfs().

    Also, note that the bfs() function uses global queue state, but since it's only called once, and 'r' starts at 0, it might work. However, the line in bfs() has a logical flaw in queue management: using 'l' as both front and incrementing it before processing next, but actually the standard way is to use a separate front index. However, the current method may work if consistent.

    But the primary error is the output order.

    So annotate the line in main() that calls dfs_(0) as being in the wrong place.

    Also, the last line bfs_() doesn't print a newline, but the others do. The problem says each traversal on a single line, so each should end with newline. The last printf("\n") is missing for bfs_().

    Looking at main():
        dfs(0); printf("\n");
        dfs_(0); printf("\n");
        bfs(); printf("\n");
        bfs_();   // @@ [Missing printf("\n") at the end, so the last line may not have a newline, causing presentation error.]

    So two errors in main():
        1. Wrong order: should do BFS before deletion before DFS after deletion.
        2. Missing newline after bfs_().

    However, the problem says "output the vertex sequences... in a single line, separated by spaces", implying each sequence is on its own line, so four lines total. Thus, each of the four traversals must be followed by a newline.

    Therefore, the line "bfs_();" is missing a newline.

    Now, regarding the BFS functions: in bfs(), the queue indices use 'l' and 'r', but 'l' is incremented at the start of the loop body, which is unusual. Typically, you dequeue at the beginning. Let's simulate:

        Initially: l=-1, r=0 (but wait, in bfs(), r is not set! Global r=0)
        q[++l] = 0 → l=0, q[0]=0
        while (l<=r) → 0<=0 → true
            x = q[l] → x=q[0]=0
            printf 0
            l++ → l=1
            then for neighbors: enqueue to q[++r], so r becomes number of neighbors
        Next iteration: l=1, r= (say) 2 → 1<=2 true
            x=q[1]
            l becomes 2
            enqueue more, r increases
        When l > r, stop.

        This actually works because 'l' points to the current element to process, and after processing, it's incremented. The queue is stored from index 0 to r, and l goes from 0 upward.

        However, the standard is to have a front pointer that you increment after dequeuing. Here, they set x = q[l], then immediately do l++, so effectively, l is the next front. It's a bit confusing but functionally correct.

        BUT: in bfs_(), they do:
            l = -1, r = 0;
            q[++l] = 0; // l=0
            while (l<=r) {
                x = q[l]; // x = q[0]
                printf...
                l++; // l=1
                ... enqueue to q[++r]
            }

        Same logic. So BFS implementation is okay.

        The real issues are:
          - Output order in main()
          - Missing newline after bfs_()

        Also, note that the global variables for BFS (l, r, Vis, Vis_) are not reset between calls, but since each BFS function uses its own Vis array and initializes l and r (bfs_ does, bfs doesn't initialize r but relies on global init), and they are called only once, it's acceptable. However, bfs() does not initialize r, but r is global and zero-initialized, so first call is okay.

        But to be safe, bfs() should initialize r=0. However, the problem states the graph is connected and small, so it might work.

        Given the above, the errors are in main().

        Specifically:
          Line: dfs_(0); printf("\n"); 
             → This should not be here; instead, bfs() should be called here.

          Line: bfs_(); 
             → Missing printf("\n");

        However, the problem says: "If you think an error may occur on a particular line, add @@ symbol directly after that line"

        So:

          In main():
            dfs(0); printf("\n");
            dfs_(0); printf("\n"); // @@ [Incorrect order: should output BFS before deletion here, not DFS after deletion. The required output order is: DFS_before, BFS_before, DFS_after, BFS_after.]
            bfs(); printf("\n");
            bfs_(); // @@ [Missing newline character at the end of output; each traversal sequence must be on its own line.]

        Additionally, is there an error in bfs()? The variable 'r' is not initialized in bfs(), but since it's global and zero-initialized, and bfs() is called before any modification to 'r' (because bfs_() hasn't run yet), it's okay. So no error there.

        Another potential issue: in dfs and dfs_, the condition "i == x" is redundant because G[x][x] is 0 (no self-loops, as per input: edges are between distinct vertices). But it's harmless.

        So only two errors in main().

    Let's write the annotations accordingly.
*/