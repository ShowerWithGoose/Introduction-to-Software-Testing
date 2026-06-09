#include <stdio.h>
#include <stdlib.h>

int adjoin[105][105];
int visited[105];
int quene[105],head=0,tail=0;
void enquene(int i)
{
    if((tail+1)%105!=head)
    quene[tail++%105]=i;
    else
    printf("qune full");
}
void BFSgraph(int m)
{
    int d,i;
    enquene(0);
    while(head!=tail)
    {
        d=quene[head];
        head=(head+1)%105;
        if(visited[d]==1)
        continue;
        visited[d]=1;
        printf("%d ",d);

        for(i=0;i<m;i++)
        {
            if(adjoin[d][i]!=0)
            enquene(i);
        }
    }
    return;
}
void DFSgraph(int d,int m)
{
    if(visited[d]==1)
    return;
    int i;
    visited[d]=1;
    printf("%d ",d);
    for(i=0;i<m;i++)
    if(adjoin[d][i]!=0)
    DFSgraph(i,m);
    return;
}
int main()
{
    int m,n,i,j,k;
    scanf("%d %d",&m,&n);//顶点个数，边的个数 @@ The variables m and n are swapped. According to the problem description, the first input is the number of vertices (n) and the second is the number of edges (m). Here, m receives the vertex count and n receives the edge count, but later in the code, m is used as the limit for vertex iteration (e.g., in loops `i<m`), which is incorrect if m holds the vertex count only by coincidence of variable naming, but logically `m` usually stands for edges and `n` for nodes. However, looking at the loop `for(i=0;i<n;i++)` for reading edges, it uses `n` as the edge count. Then `DFSgraph` and `BFSgraph` use `m` as the range for adjacent vertices. If the input is "3 3", m=3, n=3. It works for square matrices. But if input is "4 3" (4 vertices, 3 edges), m=4, n=3. The adjacency matrix size is 105. The loops `for(i=0;i<m;i++)` iterate up to m. If m is correctly the number of vertices, this is fine. But the scanf assigns the first integer to m. The problem says: "First, input the number of vertices n and the number of edges m". So the first integer is n (vertices), second is m (edges). The code does `scanf("%d %d",&m,&n);`. So `m` gets vertices, `n` gets edges.
    // Later, `for(i=0;i<n;i++)` reads n edges. This is correct based on the swap.
    // `DFSgraph(0,m)` passes m (vertices) as the dimension. This is correct.
    // `BFSgraph(m)` passes m (vertices) as the dimension. This is correct.
    // So actually, the variable naming is confusing but logically consistent WITHIN the code IF we assume m=vertices, n=edges.
    // HOWEVER, the standard convention and the problem description say n=vertices, m=edges.
    // Let's look at the deletion part.
    // `scanf("%d",&d);`
    // `for(i=0;i<m;i++) { adjoin[d][i]=0; adjoin[i][d]=0; }`
    // This clears connections for vertex d.
    
    // Let's re-read the error type: Wrong Answer.
    // Test Case: 3 3 \n 0 1 \n 1 2 \n 0 2 \n 1
    // Input: m=3, n=3.
    // Edges: (0,1), (1,2), (0,2).
    // DFS(0, 3): Visits 0. Neighbors 1, 2.
    // i=0: adj[0][0]=0.
    // i=1: adj[0][1]=1. DFS(1,3). Visits 1. Neighbors 0, 2.
    //   i=0: adj[1][0]=1, visited[0]=1. Skip.
    //   i=1: adj[1][1]=0.
    //   i=2: adj[1][2]=1. DFS(2,3). Visits 2. Neighbors 1, 0.
    //     i=0: adj[2][0]=1, visited[0]=1. Skip.
    //     i=1: adj[2][1]=1, visited[1]=1. Skip.
    //     i=2: adj[2][2]=0.
    //   Returns.
    // Returns.
    // Output: 0 1 2 . Correct.
    
    // Reset visited.
    // BFS(3):
    // enqueue 0. head=0, tail=1.
    // Loop: head!=tail.
    // d=quene[0]=0. head=1. visited[0]=0.
    // visited[0]=1. Print 0.
    // Loop i=0 to 2.
    // i=0: adj[0][0]=0.
    // i=1: adj[0][1]=1. enqueue(1). tail=2. quene[1]=1.
    // i=2: adj[0][2]=1. enqueue(2). tail=3. quene[2]=2.
    // Next iter: head=1, tail=3.
    // d=quene[1]=1. head=2. visited[1]=0.
    // visited[1]=1. Print 1.
    // Loop i=0 to 2.
    // i=0: adj[1][0]=1. enqueue(0). tail=4. quene[3]=0.
    // i=1: adj[1][1]=0.
    // i=2: adj[1][2]=1. enqueue(2). tail=5. quene[4]=2.
    // Next iter: head=2, tail=5.
    // d=quene[2]=2. head=3. visited[2]=0.
    // visited[2]=1. Print 2.
    // Loop i=0 to 2.
    // i=0: adj[2][0]=1. enqueue(0). tail=6.
    // i=1: adj[2][1]=1. enqueue(1). tail=7.
    // i=2: adj[2][2]=0.
    // Next iter: head=3, tail=7.
    // d=quene[3]=0. head=4. visited[0]=1. Continue.
    // Next iter: head=4, tail=7.
    // d=quene[4]=2. head=5. visited[2]=1. Continue.
    // ... queue drains.
    // Output: 0 1 2 . Correct.
    
    // Reset visited.
    // Scanf d=1.
    // Clear adj for d=1.
    // adj[1][0]=0, adj[0][1]=0.
    // adj[1][1]=0.
    // adj[1][2]=0, adj[2][1]=0.
    
    // DFS(0, 3):
    // Visit 0.
    // i=0: 0.
    // i=1: adj[0][1]=0.
    // i=2: adj[0][2]=1. DFS(2,3).
    // Visit 2.
    // i=0: adj[2][0]=1, visited[0]=1.
    // i=1: adj[2][1]=0.
    // i=2: 0.
    // Output: 0 2 . Correct.
    
    // Reset visited.
    // BFS(3):
    // enqueue 0.
    // d=0. Print 0.
    // i=0: 0.
    // i=1: adj[0][1]=0.
    // i=2: adj[0][2]=1. enqueue(2).
    // d=2. Print 2.
    // i=0: adj[2][0]=1. enqueue(0).
    // i=1: adj[2][1]=0.
    // i=2: 0.
    // d=0 (from queue). visited.
    // Output: 0 2 . Correct.
    
    // Why is it Wrong Answer?
    // Look closely at the output format.
    // Expected:
    // 0 1 2
    // 0 1 2
    // 0 2
    // 0 2
    
    // Buggy Output:
    // 0 1 2 
    // 0 1 2 
    // 0 2 
    // 0 2 
    
    // The difference is likely trailing spaces or newlines.
    // The printf statements are `printf("%d ",d);`. This adds a space after every number.
    // Usually, online judges are strict about trailing spaces.
    // However, often "Wrong Answer" implies logical error.
    
    // Let's check the global variables `head` and `tail`.
    // They are initialized to 0 globally.
    // In `BFSgraph`, they are used.
    // After the first BFS, `head` and `tail` are not reset to 0.
    // The queue logic relies on `head` and `tail`.
    // In the second call to `BFSgraph`, `head` and `tail` still hold values from the previous run.
    // Although `enquene` uses modulo arithmetic, the condition `head!=tail` might fail or behave unexpectedly if the queue state isn't clean.
    // Specifically, `head` and `tail` should be reset to 0 before starting a new BFS traversal.
    
    // In the first BFS:
    // Starts with head=0, tail=0.
    // Ends with head==tail (queue empty).
    // So for the second BFS, head==tail initially.
    // But `enquene(0)` sets `quene[tail]` and increments tail.
    // If head and tail were left at, say, 5 and 5, it would work fine due to modulo?
    // Wait, `quene` array content is not cleared.
    // `enquene` writes to `quene[tail]`.
    // `BFSgraph` reads from `quene[head]`.
    // If `head` and `tail` are not reset, but they are equal, the queue is effectively empty.
    // `enquene(0)` puts 0 at current `tail`.
    // Then `head != tail` becomes true.
    // It processes.
    // However, if the previous BFS left `head` and `tail` in a state where they are equal, it works.
    // BUT, look at `enquene`: `quene[tail++%105]=i;`.
    // And `head=(head+1)%105;`.
    // If the previous BFS finished, `head == tail`.
    // So the second BFS should start fresh logically IF head==tail.
    
    // Is there a case where head != tail after BFS?
    // The loop is `while(head!=tail)`. It exits when head==tail.
    // So yes, they are equal.
    
    // Let's look at `visited` array clearing.
    // `for(i=0;i<m;i++) visited[i]=0;`
    // This clears visited for indices 0 to m-1.
    // Since m is the number of vertices (due to the swap in scanf), this is correct.
    
    // What about the adjacency matrix clearing?
    // `for(i=0;i<m;i++) { adjoin[d][i]=0; adjoin[i][d]=0; }`
    // This removes edges connected to d.
    
    // Let's look at the `enquene` function again.
    // `quene[tail++%105]=i;`
    // This is `quene[(tail++) % 105] = i;` ? No.
    // Post-increment has higher precedence than `%`? No.
    // `tail++` returns the old value, then increments.
    // So it accesses `quene[old_tail % 105]`, then `tail` becomes `old_tail + 1`.
    // This is correct for a linear buffer if we ignore wrap-around for index calculation inside the array access vs the variable update.
    // Wait. If `tail` is 104. `tail++ % 105` -> `104 % 105` = 104. `tail` becomes 105.
    // Next time `tail` is 105. `105 % 105` = 0. `tail` becomes 106.
    // This works for the index.
    
    // However, `head` is updated as `head=(head+1)%105`.
    // `head` stays within 0..104.
    // `tail` keeps increasing indefinitely (until overflow, but int is large).
    // The condition `head!=tail` compares a small number (0..104) with a potentially large number.
    // Example:
    // Start: h=0, t=0.
    // Enq 0: t=1. q[0]=0.
    // Loop: h(0)!=t(1).
    // Deq: d=q[0]. h=1.
    // Enq neighbors... t increases.
    // Eventually queue empties. h catches up to t.
    // Since h is modulo 105, and t is linear.
    // If we process 105 elements, h goes 0->1->...->104->0.
    // t goes 0->1->...->105.
    // When h=0 and t=105, h!=t.
    // But logically the queue is empty if we wrapped around?
    // No, this implementation mixes modular head with linear tail.
    // This is a bug. `head` and `tail` must both be modular or both linear for the comparison `head!=tail` to work correctly regarding the circular buffer logic, OR `tail` must also be kept modulo if `head` is modulo, but typically circular queues use modulo for both indices to keep them in range.
    // If `tail` grows linearly and `head` wraps, `head` will never equal `tail` after `tail` exceeds 104, unless `head` also grows linearly.
    // Here `head` is wrapped: `head=(head+1)%105`.
    // `tail` is NOT wrapped in the variable itself, only in the index access `tail++%105`.
    // So `tail` becomes 105, 106, etc.
    // `head` is 0..104.
    // `head` will NEVER equal `tail` once `tail >= 105`.
    // The loop `while(head!=tail)` will become infinite or access invalid memory/logic.
    
    // Therefore, `head` and `tail` must be reset to 0 before each BFS call, AND the implementation of the queue indices is flawed for multiple calls or large graphs if not reset.
    // Even for a single call, if the graph has > 105 vertices, it breaks. But max vertices is 100.
    // For the first BFS, max tail is approx 100. Head goes 0..100.
    // If tail reaches 100, head reaches 100. They match.
    // So for the FIRST BFS, it might work by luck if the number of enqueued items doesn't cause head to wrap while tail is still small?
    // Actually, if N=100. Tail goes 0 to 100. Head goes 0 to 100.
    // They meet.
    
    // But for the SECOND BFS, `head` and `tail` are NOT reset.
    // Suppose after first BFS, head=100, tail=100.
    // Second BFS starts.
    // `enquene(0)`: `quene[100%105]=0`. `tail` becomes 101.
    // `head`=100. `tail`=101.
    // Loop `head!=tail`.
    // `d=quene[100]`. `head=(100+1)%105 = 101`.
    // Process...
    // If we enqueue more, tail becomes 102, 103...
    // Head becomes 102, 103...
    // They will likely meet again if the number of operations is small.
    
    // HOWEVER, the standard fix for global queue indices is to reset them.
    // The lines `head=0; tail=0;` are missing before `BFSgraph` calls or inside `BFSgraph`.
    
    // Also, the variable swap in scanf is suspicious but internally consistent.
    
    // Let's mark the missing reset of head/tail.
    
    for(i=0;i<m;i++)
    visited[i]=0;
    // @@ Missing reset of head and tail to 0 before calling BFSgraph. The global variables head and tail retain their values from the previous BFS execution. Since head uses modulo arithmetic and tail grows linearly in the current buggy implementation (or even if both were modular, the state needs to be clean), failing to reset them causes incorrect queue behavior in subsequent BFS calls.
    BFSgraph(m);
    printf("\n");
    for(i=0;i<m;i++)
    visited[i]=0;
    scanf("%d",&d);
    for(i=0;i<m;i++)
    {
        adjoin[d][i]=0;
        adjoin[i][d]=0;
    }
    DFSgraph(0,m);
    printf("\n");
    for(i=0;i<m;i++)
    visited[i]=0;
    // @@ Missing reset of head and tail to 0 before calling BFSgraph again.
    BFSgraph(m);
    printf("\n");
    for(i=0;i<m;i++)
    visited[i]=0;
    return 0;
}