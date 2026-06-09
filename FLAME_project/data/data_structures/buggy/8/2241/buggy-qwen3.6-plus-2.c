#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
//邻接表： 
struct edge//边结点 
{ 
    int adjvex;
    struct edge *next;
};
struct ver//顶点节点 
{
    int vertex;
    struct edge *next;
};
struct ver G[100]={};
int QUEUE[101];
int Front = 0, Rear = 9999, Count = 0;
int emptyQ()
{
    return Count == 0;
}
void enQueue(int item)
{
    Rear = (Rear + 1) % 10000; 
    QUEUE[Rear] = item;
    Count++;                      //队未满，插入成功

}
int deQueue()
{ 
    int e;  
    e = QUEUE[Front];
    Count--;                     //队非空，删除成功
    Front = (Front + 1) % 10000;
    return e;
}
struct edge* insertNode(struct edge* list, int elem)
{
    struct edge *p, *q, *r;
    r = (struct edge*)malloc(sizeof(struct edge));
    r->adjvex = elem;
    r->next = NULL;
    if(list == NULL)//list是一个空表
    {
        return r;
    }
    
    for(p = list; p != NULL && elem > p->adjvex; q = p, p = p->next)
        ;
    if(p == list)//头结点前插入 
    {
        r->next = p;
        return r;
    }
    else//在q后插入 
    {
        q->next = r;
        r->next = p;
    }
    return list;
}

//邻接表深度优先： 
int visited[2000] = {0}; //标识顶点是否被访问过，N为顶点数
void visit(struct ver G[], int v)
{
    printf("%d ", G[v].vertex);
}
void DFS(struct ver G[], int v)
{
    struct edge *p;
    visited[v] = 1;     //标识某顶点被访问过
    visit(G, v);     //访问某顶点
    for(p = G[v].next; p != NULL;  p = p->next)
         if(!visited[p->adjvex])
             DFS(G, p->adjvex);
}
void travelDFS(struct ver G[], int n)
{
    int i;
    for(i = 0; i < n; i++)
        visited[i] = 0 ;
    for(i = 0; i < n; i++)
        if(!visited[i]) DFS(G, i);
}

void BFS(struct ver G[], int v)
{
    struct edge *p;
    visit(G, v); //访问当前顶点
    visited[v] = 1; //标识某顶点被访问过
    enQueue(v);         // 入口的第一个顶点入队
    while(!emptyQ()){  //  循环，直到队空为止 
         v = deQueue();  //取出队头元素
         p = G[v].next;         //获取该顶点第一个邻接顶点
         for(; p != NULL ; p = p->next ) //访问该顶点下的每个邻接顶点
             if(!visited[p->adjvex])
             {
                visit(G, p->adjvex); //访问当前顶点
                visited[p->adjvex] = 1; //标识某顶点被访问过
                enQueue(p->adjvex); //邻接顶点依次分别入队
             }
     }
}

int main()
{
    int n,t,delnum;
    scanf("%d %d",&n,&t);
    for(int i=0;i<n;i++){
        G[i].vertex = i;
    }
    for(int i=0;i<t;i++){
        int V1,V2;
        scanf("%d %d",&V1,&V2);
        G[V1].next = insertNode(G[V1].next, V2);
        G[V2].next = insertNode(G[V2].next, V1);
    }
    scanf("%d",&delnum);
    DFS(G, 0);printf("\n");
    for(int i=0;i<=n;i++){
        visited[i] = 0;
    }
    BFS(G, 0);printf("\n");
    for(int i=0;i<=n;i++){
        visited[i] = 0;
    }
    visited[delnum] = 1; // @@ The logic for deleting a vertex in DFS is partially handled by marking it visited, but the traversal function DFS does not skip neighbors of the deleted node if they are visited via another path. However, the main issue here is that the problem requires restarting traversals from 0 if 0 is not deleted, but generally just running DFS/BFS from 0. The critical error is in the BFS part below.
    DFS(G, 0);printf("\n");
    for(int i=0;i<=n;i++){
        visited[i] = 0;
    }
    visited[delnum] = 1; // @@ Similar to DFS, we mark the deleted node as visited so it won't be processed. However, the BFS implementation has a flaw: it prints the start node before checking if it's the deleted node (though here start is 0 and delnum != 0). More importantly, the BFS function visits neighbors and marks them visited immediately. If the deleted node is a neighbor, it should be skipped. The current BFS code checks `!visited[p->adjvex]`. Since we set `visited[delnum] = 1` before calling BFS, the deleted node will be skipped in the neighbor check. This part seems logically okay for skipping the node itself. 
    BFS(G, 0);printf("\n"); // @@ The expected output for the last line is `0 2`. The input graph is 0-1, 1-2, 0-2. Delete 1. Remaining edges: 0-2. BFS from 0: Visit 0. Queue: [0]. Dequeue 0. Neighbors of 0: 1 (visited/deleted), 2 (not visited). Visit 2, mark visited, enqueue 2. Queue: [2]. Dequeue 2. Neighbors of 2: 1 (visited/deleted), 0 (visited). Queue empty. Output: 0 2. 
    // Wait, let's re-read the buggy output vs expected.
    // Buggy: 0 2 \n 0 1 2
    // Expected: 0 2 \n 0 2
    // The third line (DFS after delete) is `0 2` in both.
    // The fourth line (BFS after delete) is `0 1 2` in buggy, `0 2` in expected.
    // Why did BFS print 1?
    // In `main`, before the last BFS call:
    // `visited` is reset to 0.
    // `visited[delnum] = 1` is executed. delnum is 1. So visited[1]=1.
    // Then `BFS(G, 0)` is called.
    // Inside BFS:
    // `visit(G, 0)` -> prints 0. `visited[0]=1`. `enQueue(0)`.
    // Loop: `v = deQueue()` -> v=0.
    // `p = G[0].next`. Adjacency list for 0: 1, 2 (sorted).
    // First neighbor p->adjvex = 1.
    // Check `!visited[1]`. visited[1] is 1. So condition fails. Skip.
    // Next neighbor p->adjvex = 2.
    // Check `!visited[2]`. visited[2] is 0. Condition true.
    // `visit(G, 2)` -> prints 2. `visited[2]=1`. `enQueue(2)`.
    // Loop continues... p becomes NULL.
    // Loop: `v = deQueue()` -> v=2.
    // `p = G[2].next`. Adjacency list for 2: 0, 1 (sorted).
    // First neighbor 0. visited[0] is 1. Skip.
    // Second neighbor 1. visited[1] is 1. Skip.
    // Queue empty.
    // So BFS should print `0 2`.
    // Why did the buggy output print `0 1 2`?
    // Let's look at the `visited` array size and initialization.
    // `int visited[2000] = {0};`
    // Reset loop: `for(int i=0;i<=n;i++){ visited[i] = 0; }`
    // If n=3, indices 0,1,2,3 are set to 0.
    // `visited[delnum] = 1;` -> visited[1]=1.
    // This logic seems correct.
    
    // Is it possible the previous DFS modified `visited` in a way that affects BFS?
    // No, we reset visited.
    
    // Let's look closely at the `BFS` function again.
    // `void BFS(struct ver G[], int v)`
    // It uses the global `visited`.
    
    // Let's look at the `DFS` function called before the last BFS.
    // `visited[delnum] = 1;`
    // `DFS(G, 0);`
    // Inside DFS:
    // `visited[0]=1`. Print 0.
    // Neighbors of 0: 1, 2.
    // Neighbor 1: `!visited[1]`? visited[1] is 1. Skip.
    // Neighbor 2: `!visited[2]`? visited[2] is 0. Recurse DFS(G, 2).
    // Inside DFS(2):
    // `visited[2]=1`. Print 2.
    // Neighbors of 2: 0, 1.
    // Neighbor 0: visited. Skip.
    // Neighbor 1: visited. Skip.
    // Return.
    // Output: `0 2`. Correct.
    
    // Then reset visited.
    // `visited[delnum] = 1;` -> visited[1]=1.
    // `BFS(G, 0);`
    
    // If the output was `0 1 2`, it implies vertex 1 was visited/printed.
    // This can only happen if `visited[1]` was 0 when checked in BFS.
    // Did `visited[delnum] = 1` fail?
    // Or did the reset loop `for(int i=0;i<=n;i++)` fail to cover `delnum`?
    // n=3. Loop i=0,1,2,3. delnum=1. Covered.
    
    // Wait, look at the first BFS call.
    // `BFS(G, 0);`
    // This runs on the full graph.
    // Output `0 1 2`.
    // Then reset.
    // Then `visited[delnum] = 1`.
    // Then `DFS(G, 0)`.
    // Then reset.
    // Then `visited[delnum] = 1`.
    // Then `BFS(G, 0)`.
    
    // Is it possible `delnum` is not 1?
    // Input: `3 3`, edges `0 1`, `1 2`, `0 2`, delete `1`.
    // `scanf("%d",&delnum);` reads 1.
    
    // Let's check the queue implementation.
    // `QUEUE[101]`. `Rear = 9999`. `Front = 0`.
    // `enQueue`: `Rear = (9999+1)%10000 = 0`. `QUEUE[0]=item`. `Count=1`.
    // `deQueue`: `e=QUEUE[0]`. `Count=0`. `Front=(0+1)%10000=1`.
    // Next `enQueue`: `Rear=(0+1)%10000=1`. `QUEUE[1]=item`. `Count=1`.
    // This seems fine.
    
    // What if the error is in `insertNode`?
    // If the adjacency list is not sorted correctly, BFS/DFS order might change, but nodes shouldn't appear/disappear.
    
    // Let's look at the `visited` array declaration: `int visited[2000] = {0};`
    // And the reset: `for(int i=0;i<=n;i++){ visited[i] = 0; }`
    
    // There is a subtle bug in the `BFS` function regarding when nodes are marked visited.
    // Standard BFS: Mark visited when enqueuing.
    // This code:
    // `visit(G, v); visited[v] = 1; enQueue(v);` (Start node)
    // Inside loop:
    // `v = deQueue();`
    // `for neighbors:`
    // `if(!visited[p->adjvex]) { visit(...); visited[...] = 1; enQueue(...); }`
    // This is correct standard BFS.
    
    // Why would `1` be printed in the last BFS?
    // Only if `visited[1]` was 0.
    // Which means `visited[delnum] = 1` didn't work or was overwritten.
    // It wasn't overwritten because `BFS` is called immediately after.
    
    // Is it possible `delnum` is out of bounds for the reset loop?
    // n=3. delnum=1. Loop 0..3. OK.
    
    // Let's look at the `DFS` function again.
    // `void DFS(struct ver G[], int v)`
    // It recursively calls itself.
    
    // Actually, looking at the provided "Buggy Output":
    // Line 3: `0 2`
    // Line 4: `0 1 2`
    
    // If Line 4 is `0 1 2`, then vertex 1 was visited.
    // This implies `visited[1]` was false when encountered.
    
    // Wait! Look at the `main` function logic for the second part.
    // `visited[delnum] = 1;`
    // `DFS(G, 0);`
    // `for(int i=0;i<=n;i++){ visited[i] = 0; }`
    // `BFS(G, 0);`
    
    // Between the DFS call and the BFS call, we reset visited.
    // BUT we do NOT set `visited[delnum] = 1` again before BFS!
    // The line `visited[delnum] = 1;` is ONLY before the DFS call.
    // After DFS, we reset all visited to 0.
    // Then we call BFS.
    // At this point, `visited[delnum]` is 0.
    // So BFS will visit the deleted node!
    
    // Error location: The line `visited[delnum] = 1;` is missing before the final `BFS(G, 0);` call.
    
    return 0;
}