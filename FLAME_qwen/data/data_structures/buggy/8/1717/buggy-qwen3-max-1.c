#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
int visit[100]={0},map[100][100];
void sdbl(int n,int p)
{
    int i;
    printf("%d ",p);
    visit[p]=1;
    for(i=0;i<n;i++)
    {
        if(map[p][i]==1&&visit[i]==0){
            sdbl(n,i);
        }
    }
}
void gdbl(int n,int p)
{
    int i,h=0,t=1,tmp,dui[n]; // @@ [Variable-length array 'dui' may not be supported in all C standards (e.g., C89), and more critically, the queue size may be insufficient because BFS might enqueue more than 'n' elements during traversal due to revisiting logic issues. However, the primary error causing failure is likely logical, not compilation. But since the reported error type is "Compilation Error" and the test environment lacks gcc, this may be a red herring. However, looking at the actual code: the real issue is that the BFS implementation uses a VLA with size 'n', which is acceptable in C99+, but the bigger problem is that the queue index 't' starts at 1 and increments before assignment, potentially exceeding array bounds. Yet the prompt says "Compilation Error", but the provided buggy output is "/bin/sh: 1: gcc: not found", which is not a code error—it's an environment issue. However, assuming the error type is misreported and we must find logical errors that cause wrong output:]

    // Actually, re-evaluating: the problem states "Error type: Compilation Error", but the given source compiles under C99. However, the reference program uses fixed-size arrays, while this uses VLA 'dui[n]'. Some strict compilers or older standards may reject this. But more importantly, the BFS loop condition and indexing are flawed.

    // But per instructions, we must mark lines with @@ if they contain errors. The main logical errors are:
    // 1. In BFS (gdbl), the queue 'dui' is declared as size 'n', but in worst case, BFS may try to enqueue up to n-1 nodes, and with t starting at 1 and doing t++ after assignment, it may write to dui[n-1] safely? Let's see: h=0, t=1 initially. Then dui[0]=p. Then in loop, tmp=dui[0], then for neighbors, if unvisited, dui[t++]=i → first neighbor goes to dui[1], t becomes 2, etc. Max index written is t-1, and t can go up to n (if all n nodes are enqueued), so dui[n] would be out of bounds (since indices 0..n-1). So buffer overflow possible.

    // However, the problem says the graph is connected and n>=3, so worst-case BFS enqueues all n nodes. With t starting at 1, and incrementing after assignment, the last assignment is dui[n-1] when t = n-1 before increment. Wait: initial t=1. After assigning dui[1], t becomes 2. To enqueue n nodes, we need indices 0 to n-1. The first node is at index 0. Then we enqueue up to n-1 more, so max index is n-1. But t starts at 1, and we do dui[t++] = i → first enqueued neighbor goes to index 1, then 2, ..., up to index n-1 when t = n-1 before increment, then t becomes n. So the array of size n (indices 0..n-1) is sufficient. So maybe not overflow.

    // But the real issue: in BFS, when popping a node (tmp=dui[h++]), it checks if visit[tmp]==1, and if so, skips. However, nodes are marked visited only when printed. But a node might be enqueued multiple times before being visited, because when we check for neighbors, we only check !visit[i], but if a node is already in the queue but not yet visited, it can be enqueued again by another neighbor. This leads to duplicate enqueues, and the queue may grow beyond n, causing overflow. For example, in a triangle 0-1-2-0: start at 0, enqueue 1 and 2. Then when processing 1, it sees 0 (visited? no, but 0 is already processed? Actually, 0 is marked visited when printed at start). Wait, in this code: when we print tmp, we mark it visited. So when processing 0, we mark visit[0]=1. Then enqueue 1 and 2. Then process 1: print 1, mark visited, then look at neighbors: 0 (visited), 2 (not visited) → enqueue 2 again. So 2 is enqueued twice. Then when processing first 2: print 2, mark visited. Then next time 2 is dequeued, it sees visit[2]==1 and skips. But the queue now has two 2s. So the queue size needed could be more than n. Hence, dui[n] is too small.

    // Therefore, the declaration 'dui[n]' is insufficient; it should be larger, e.g., dui[100]. This is a bug that may cause runtime error (buffer overflow), but not compilation error. However, the problem states the error type is "Compilation Error", which is confusing.

    // Given the discrepancy, and since the user says the buggy output is "/bin/sh: 1: gcc: not found", which is not a code issue, but the instruction says to find errors in the program, we must assume the error type is mislabeled and focus on logical errors that cause wrong output.

    // Another critical error: in the deletion step, the code sets map[d][i]=map[i][d]=0 for all i, which correctly removes edges incident to d. However, in the DFS and BFS after deletion, the traversal should skip the deleted vertex entirely. But the current DFS (sdbl) and BFS (gdbl) still iterate over all vertices from 0 to n-1, including the deleted vertex d. However, since all edges to d are removed, d will not be reached from 0 (as graph remains connected without d, and d != 0). But what if the traversal tries to go to d? It won't, because edges are removed. However, the visit array is reset, but d is not explicitly excluded. But since there are no edges to d, it won't be visited. So that part is okay.

    // However, the main issue causing wrong output is likely in the BFS implementation: the queue management and the fact that nodes can be enqueued multiple times, leading to incorrect order or crashes. But the problem says the graph is small (n<=100), so maybe it doesn't crash but produces wrong order.

    // But looking at the reference program: it uses a fixed-size queue of 100, and marks visited when dequeuing (but skips if already visited). The reference BFS has:
    //   queue[1]=v; front=1,rear=1;
    //   while(front<=rear){
    //       v=queue[front++];
    //       if(visit[v]) continue;
    //       else print and mark visited;
    //       for neighbors: if not visited, enqueue.
    //   }
    // This is standard, but note: it enqueues only unvisited neighbors, so no duplicates. Why? Because when enqueueing, it checks !visit[i]. So a node is enqueued only once.

    // In the buggy code's BFS (gdbl):
    //   for(i=0;i<n;i++) {
    //       if(map[tmp][i]==1 && visit[i]==0) {
    //           dui[t++]=i;
    //       }
    //   }
    // This also checks visit[i]==0 when enqueueing, so it should not enqueue duplicates. Then why the skip check when dequeuing? It's redundant but safe. So the queue size n should be enough, because each node is enqueued at most once. So dui[n] is sufficient (since there are n nodes, and we start with one, enqueue at most n-1 more).

    // Then what's the error?

    // Let's compare the DFS: 
    // Reference DFS: for(i=1;i<=n;i++) ... but vertices are 0 to n-1, so this is wrong! It should be i=0 to n-1. But the reference program uses 1-indexed? No, input vertices are 0 to n-1. So reference program has a bug: it loops from 1 to n, but vertices are 0..n-1, so it misses vertex 0's connections to other vertices? Actually, no: in reference, picture[x][y] is set for input x,y which are 0..n-1. But in dfs, for(i=1;i<=n;i++) — this would access picture[v][1] to picture[v][n], but n is the number of vertices, so valid indices are 0..n-1. So picture[v][n] is out of bounds! And it never checks picture[v][0]. So reference program is broken. But the problem says "reference program correctly implemented", so maybe the reference uses 1-indexed internally? But input is 0-indexed. Contradiction.

    // Given the confusion, let's focus on the provided buggy code.

    // The provided code uses 0-indexed correctly: for(i=0;i<n;i++).

    // Another possibility: in the BFS, the queue indices. The code declares dui[n], and uses h=0, t=1. Then dui[0]=p. Then in the loop, when processing, it does:
    //   tmp = dui[h++];   // h starts at 0, so first tmp = dui[0], h becomes 1.
    //   then for neighbors, dui[t++] = i;  // t starts at 1, so first neighbor goes to dui[1], t becomes 2.
    // The loop condition is h<=t. Initially h=0, t=1 → 0<=1 true. After processing first node, h=1, t= (say) 3. Then next iteration: h=1<=3 true. When h becomes greater than t, stop.
    // The number of elements in queue is t - h. But the array dui has size n, and we enqueue at most n nodes, so indices 0 to n-1 are used. Since t starts at 1 and increments after assignment, the maximum value of t is n (when n nodes are enqueued: index 0 to n-1). So dui[n-1] is the last, and t becomes n. Then h goes from 0 to n, and when h=n, t=n, so h<=t is true, but dui[h] = dui[n] which is out of bounds! Because dui has indices 0..n-1.

    // Example: n=3. dui[3] (indices 0,1,2). 
    // Start: dui[0]=0, h=0, t=1.
    // Iteration1: h=0<=1 → tmp=dui[0]=0, h=1. Print 0, mark visited. Enqueue neighbors: say 1 and 2. So dui[1]=1, t=2; dui[2]=2, t=3.
    // Now h=1, t=3.
    // Iteration2: h=1<=3 → tmp=dui[1]=1, h=2. Print 1, enqueue its unvisited neighbors (only 2, but 2 is not visited yet? But 2 is already in queue. However, when enqueueing, we check visit[i]==0, and 2 is not visited, so we enqueue 2 again? But wait, in this graph 0-1-2, and 0-2, then when processing 1, neighbor 2 is not visited, so enqueue. But 2 was already enqueued by 0. So now dui[3]=2, t=4. But dui has size 3 (indices 0,1,2), so dui[3] is out of bounds.

    // But earlier we thought the enqueue condition prevents duplicates, but it doesn't: because when 0 enqueues 2, visit[2] is still 0. Then when 1 is processed, visit[2] is still 0 (because 2 hasn't been dequeued and printed yet), so 1 will enqueue 2 again. Hence, duplicates occur, and queue size exceeds n.

    // Therefore, the BFS implementation is flawed because it allows duplicate enqueues, leading to potential buffer overflow and also incorrect traversal order (though the skip when dequeuing might save the order, but the buffer overflow is a critical error).

    // How to fix: mark a node as visited when enqueuing, not when dequeuing. Or ensure no duplicates by checking a separate in-queue status. But the standard method is to mark visited when enqueuing.

    // In the reference program, it marks visited only when dequeuing, but it avoids duplicates by checking !visit[i] when enqueuing. However, because visit[i] is still 0 until dequeued, duplicates can happen. But the reference program uses a large enough queue (size 100) so it doesn't overflow. In the buggy code, the queue is size n, which is too small when duplicates occur.

    // Therefore, the line declaring 'dui[n]' is problematic because the queue may need to hold more than n elements due to duplicate enqueues.

    // So we mark that line.

    // Additionally, the BFS logic is inefficient and unsafe, but the immediate error is the undersized queue.

    // Another issue: the problem states that after deletion, the graph is still connected, and we start from 0, and the deleted vertex is not 0, so 0 is always present.

    // Let's check the deletion part: 
    //   for(int i=0;i<n;i++) { map[d][i]=map[i][d]=0; }
    // This correctly removes all edges incident to d.

    // But what about the visit array? Before the second DFS and BFS, it is reset with memset(visit,0,sizeof(visit)). However, the deleted vertex d should not be visited, and since it's disconnected, it won't be. So that's fine.

    // Now, the DFS seems correct.

    // So the main error is in BFS queue size.

    // Also, note: the reference program resets visit array after BFS, but the buggy code does not reset after BFS? Let's see:
    //   After first BFS: memset(visit,0,...) is done before calling gdbl, and inside gdbl, there's no reset. After gdbl, the visit array is left with all 1s. Then before second DFS, it does memset(visit,0,...). Similarly before second BFS. So it's okay.

    // Therefore, the critical error is the VLA size in BFS.

    // But the problem says "Compilation Error", and VLA is standard in C99, so it should compile. However, if the compiler is C89, it won't. But the includes have <malloc.h> which is non-standard (should be <stdlib.h> for malloc, but here malloc isn't used). The use of // comments is C99. So likely the environment is C99.

    // Given the instructions, and since the test case input is not provided (it's empty in the prompt), but the expected output is also empty, it's hard to tell.

    // However, the most probable cause of failure is the BFS queue overflow.

    // So we annotate the line with the queue declaration.

    // Also, note: the initial setting of the queue: dui[h]=p; with h=0. Then t=1. This is correct.

    // Another minor issue: the BFS function uses 'dui' as the queue name, but that's not an error.

    // So only one line to annotate.
}
int main()
{
    int n,e,a,b,d;
    scanf("%d %d",&n,&e);
    memset(visit,0,sizeof(visit));
    for(int i=0;i<e;i++)
    {
        scanf("%d %d",&a,&b);
        map[a][b]=map[b][a]=1;
    }
    sdbl(n,0);
    printf("\n");
    memset(visit,0,sizeof(visit));
    gdbl(n,0);
    printf("\n");
    scanf("%d",&d);
    for(int i=0;i<n;i++)
    {
        map[d][i]=map[i][d]=0;
    }
    memset(visit,0,sizeof(visit));
    sdbl(n,0);
    printf("\n");
    memset(visit,0,sizeof(visit));
    gdbl(n,0);
    printf("\n");

    return 0;
}