#include <stdio.h>
#include <string.h>//原来构图得到的链表还要排序。。
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

#define MaxV 256
#define MAXSIZE 256
#define N 1000
typedef int ElemType;
typedef struct edge
{
    int adjvex;
    struct edge *next;
} Elink;
typedef struct ver
{
    Elink *link;
} Vlink;
Vlink G[MaxV]={0};
int Visited[N] = {0}; // 标识顶点是否被访问过
                      //  N为顶点个数
ElemType Q[MAXSIZE];
int Front, Rear, Count;

void setedge(Vlink G[], int a, int b);
void travelBFS(Vlink G[], int n);
void BFS(Vlink G[], int v);
void enQueue(ElemType queue[], ElemType item);
void travelDFS(Vlink G[], int n);
void DFS(Vlink G[], int v);
ElemType deQueue(ElemType queue[]);
int isEmpty();
int isFull();
void delete(Vlink G[], int c);
void visit(Vlink G[], int c);
Elink *insertEdge(Elink *head, int avex);
int main()
{
    int m, n;
    int a, b, c;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &a, &b);//无向图设置两条边
        G[a].link = insertEdge(G[a].link, b);
        G[b].link = insertEdge(G[b].link, a);
    }
    travelDFS(G, n);
    printf("\n");
    travelBFS(G, n);
    printf("\n");

    scanf("%d", &c);
    delete (G, c);
    travelDFS(G, n);
    printf("\n");
    travelBFS(G, n);
    printf("\n");

    return 0;
}

Elink *insertEdge(Elink *head, int avex)
{
    Elink *e, *p, *q = NULL;
    e = (Elink *)malloc(sizeof(Elink)); /* 创建一个数据项为avex的新结点 */
    e->adjvex = avex;
    e->next = NULL;
    if (head == NULL) /* head是一个空表 */
        return e;
    for (p = head; p != NULL && avex > p->adjvex; q = p, p = p->next) /* 找到插入位置 */
        ;
    if (p == head)
    { /* 在头结点前插入 */
        e->next = p;
        return e;
    }
    else
    { /* 在结点p前插入一个结点 */
        q->next = e;
        e->next = p;
        return head;
    }
}

void setedge(Vlink G[],int a,int b)//设置边函数,a为顶点一，b为顶点二
{
    Elink *p, *q; // 无向图，要设置两个点相互联通
    q = (Elink *)malloc(sizeof(Elink));
    q = G[a].link;
    p = (Elink *)malloc(sizeof(Elink));
    p->adjvex = b;
    p->next = NULL;
    if(G[a].link!=NULL)//若该点已有边连接
    {
        for (; q->next != NULL&&q->next->adjvex<b ;q=q->next);//找到尾结点
        if(q->next!=NULL)
        {
            Elink *r=q->next;
            q->next = p;
            p->next = r;
        }
        else
        q->next = p;
    }
    else
    {
        G[a].link = p;
    }
}
void travelBFS(Vlink G[], int n) // 广度优先遍历算法
{
    int i;
    for (i = 0; i < n; i++)
        {
            Visited[i] = 0;
        }
        memset(Q, 0, sizeof(Q));//重置Q队列
        BFS(G, 0);
}

void BFS(Vlink G[], int v)
{
    Elink *p;
    visit(G,v); // @@ The visit should happen when dequeuing in standard BFS to ensure correct order relative to queue processing, but more importantly, the logic here visits 'v' (start node) then enqueues it. Inside the loop, it dequeues 'v' but doesn't visit it again (correct), but visits neighbors. However, the standard BFS usually marks visited when enqueuing. Here it marks visited when enqueuing neighbors. The issue is that `visit(G,v)` is called before marking `Visited[v]=1`? No, it is called, then marked. But inside the loop, `v = deQueue(Q)`, then it iterates neighbors. It does NOT visit `v` again. This is actually okay for the start node if handled correctly. BUT, look at `travelBFS`. It calls `BFS(G, 0)`. If vertex 0 is deleted, this will crash or behave wrongly. But the problem says vertex to delete is not 0. 
    // The real error in BFS/DFS traversal after deletion is that the adjacency lists still contain the deleted vertex index. 
    // When traversing, if we encounter an edge to the deleted vertex, we should skip it.
    // The `delete` function attempts to remove edges. Let's look at `delete`.
    
    Visited[v] = 1; // 标识某顶点被访问过
    enQueue(Q, v);    // 入口的第一个顶点入队
    while (!isEmpty(Q))
    {                                   //  循环，直到队空为止
        v = deQueue(Q);                   // 取出队头元素
        // @@ Missing visit here? No, visit was done at start for initial v. But for subsequent nodes, they are visited when discovered (enqueued). This is a valid BFS variant (mark visited on enqueue). 
        // However, the standard output format usually implies visiting when dequeuing or when discovered. 
        // Let's check the DFS. DFS visits when entering.
        // In this BFS: Start node 0 is visited immediately. Neighbors are visited immediately when found and enqueued.
        // This means the order of printing is: Start, then neighbors in order of discovery.
        // Standard BFS often prints when dequeuing. If we print when discovering, the order might differ if multiple paths exist? No, BFS tree is unique if neighbors are sorted.
        // Wait, if I print when discovering, I print neighbor A, then neighbor B.
        // If I print when dequeuing, I dequeue A (print A), then dequeue B (print B).
        // Since A and B are enqueued in order, they are dequeued in order. So the output sequence is the same.
        
        p = G[v].link;                   // 获取该顶点第一个邻接顶点
        for (; p != NULL; p = p->next) // 访问该顶点下的每个邻接顶点
            if (!Visited[p->adjvex])
            {
                visit(G, p->adjvex);    // 访问当前顶点
                Visited[p->adjvex] = 1; // 标识某顶点被访问过
                enQueue(Q, p->adjvex);    // 邻接顶点依次分别入队
            }
    }
}

void enQueue(ElemType queue[], ElemType item)
{
    if (isFull()) /* 队满，插入失败 */
        printf("Full queue!");
    else
    {
        Rear = (Rear + 1) % MAXSIZE; // 计算循环队列尾部的合适的进队位置
        queue[Rear] = item;
        Count++;
        /* 队未满，插入成功 */
    }
}
void travelDFS(Vlink G[], int n) // 深度优先遍历算法
{
    int i;
    for (i = 0; i < n; i++)
        Visited[i] = 0;
    DFS(G, 0);
}

void DFS(Vlink G[], int v)
{
    Elink *p;
    Visited[v] = 1; // 标识某顶点被访问过
    visit(G,v); // 访问某顶点
    for (p = G[v].link; p != NULL; p = p->next)
        if (!Visited[p->adjvex])
            DFS(G, p->adjvex);
}
ElemType deQueue(ElemType queue[])
{
    ElemType e;
    if (isEmpty())
        printf("Empty queue!"); /* 队空，删除失败 */
    else
    {
        e = queue[Front];
        Count--;                       /* 队非空，删除成功 */
        Front = (Front + 1) % MAXSIZE; // 计算循环队列头部的合适的出队位置
        return e;
    }
}
int isEmpty()
{
    return Count == 0;
}
int isFull()
{
    return Count == MAXSIZE;
}
void delete(Vlink G[], int c)//删除某节点信息
{
    Elink *p, *q, *r,*e;//p用于遍历被删除顶点的链表，q用于遍历与被删除顶点形成边的顶点列表
    int x;
    // @@ The logic here is flawed. It iterates through the adjacency list of the deleted vertex 'c'.
    // For each neighbor 'x' of 'c', it tries to remove 'c' from 'x's adjacency list.
    // However, it frees the node in 'x's list.
    // Crucially, it does NOT free the nodes in 'c's own adjacency list, causing memory leaks (though not necessarily wrong output if we ignore leaks).
    // More importantly, after this function, the adjacency list of 'c' still exists and points to freed memory or valid memory depending on implementation.
    // But the traversal functions iterate from 0 to n-1. If 'c' is not 0, DFS/BFS starting at 0 won't start at 'c'.
    // However, if other nodes have edges to 'c', those edges must be removed so traversals don't try to visit 'c'.
    // The code attempts to remove 'c' from neighbors' lists.
    
    // Let's trace the removal logic for a neighbor x:
    // q = G[x].link;
    // if (q->adjvex==c) { ... remove head ... }
    // else { find c in list, remove it. }
    // This part seems logically okay for removing 'c' from neighbors.
    
    // BUT, look at the loop: `for (p = G[c].link; p != NULL;p=p->next)`
    // Inside the loop, it modifies `G[x].link`.
    // Does it handle the case where `G[c].link` is NULL? Yes, loop won't run.
    
    // The major issue is likely that `Visited` array or graph structure isn't fully cleaned up for traversal safety.
    // Specifically, if `delete` is called, vertex `c` is effectively "removed" by stripping incoming edges.
    // But `G[c]` itself is not marked as invalid. If DFS/BFS somehow reaches `c` (it shouldn't if edges are removed), it would visit it.
    // Since edges TO `c` are removed, `c` becomes unreachable from 0 (assuming connected graph initially and c != 0).
    // So `c` will not be visited. This is correct behavior for "deleting" a vertex in terms of reachability.
    
    // However, there is a subtle bug in `delete`:
    // `G[c].link = NULL;` is only executed in the `else` block of the inner if/else.
    // If the first neighbor `x` has `c` as the head of its list, `G[c].link` is NOT set to NULL.
    // This doesn't affect traversal correctness if `c` is unreachable, but it's inconsistent.
    
    // Let's look closer at `travelBFS` and `travelDFS`. They reset `Visited`.
    // They start from 0.
    // If `c` is properly disconnected from the rest of the graph (edges from others to `c` removed), then `c` won't be visited.
    
    // Is there an error in `insertEdge`? It keeps the list sorted.
    // Is there an error in `delete`?
    // In the `else` block: `G[c].link = NULL;` is executed every time a non-head removal happens. This is weird but harmless.
    
    // Let's re-read the `delete` function carefully.
    // `for (p = G[c].link; p != NULL;p=p->next)`
    // `x = p->adjvex;`
    // `q = G[x].link;`
    // `if (q->adjvex==c)` -> Remove head.
    // `else` -> Find and remove.
    
    // What if `G[x].link` is NULL? The problem states the graph is connected, so if `c` has neighbor `x`, `x` must have neighbor `c`. So `G[x].link` cannot be NULL.
    
    // The actual error is likely in how the graph is traversed or printed.
    // Look at `visit(G, c)`. It just prints `c`.
    
    // Let's look at the test case.
    // Input:
    // 3 3
    // 0 1
    // 1 2
    // 0 2
    // 1
    
    // Graph:
    // 0: 1, 2
    // 1: 0, 2
    // 2: 0, 1
    
    // Delete 1.
    // `delete(G, 1)` runs.
    // p iterates over G[1].link: nodes 0 and 2.
    // 1. p->adjvex = 0. x=0.
    //    G[0].link is 1->2.
    //    q = G[0].link (points to 1).
    //    q->adjvex == 1 (c). True.
    //    e = q->next (points to 2).
    //    free(q).
    //    G[0].link = e (points to 2).
    //    G[1].link is NOT set to NULL here.
    // 2. p = p->next. p was pointing to node with adjvex 0. But we freed the node in G[0] list? No, we freed the node in G[0] list that pointed to 1.
    //    Wait. `p` is iterating `G[1].link`.
    //    `G[1].link` contains nodes pointing to 0 and 2.
    //    The node `p` points to the entry in G[1]'s list.
    //    The node `q` points to the entry in G[0]'s list.
    //    These are different nodes in memory. Freeing `q` does not invalidate `p`.
    //    So `p=p->next` is safe.
    //    Next iteration: p->adjvex = 2. x=2.
    //    G[2].link is 0->1.
    //    q = G[2].link (points to 0).
    //    q->adjvex == 0 != 1. False.
    //    Else block:
    //    e = q->next (points to 1).
    //    Loop `for (e = q->next; e->adjvex != c; q = e, e = q->next)`
    //    e->adjvex is 1. c is 1. Condition `e->adjvex != c` is false. Loop doesn't run.
    //    r = e->next (NULL).
    //    free(e).
    //    q->next = r (NULL).
    //    G[1].link = NULL.
    
    // After delete:
    // G[0].link -> 2
    // G[1].link -> NULL (set in last step)
    // G[2].link -> 0
    
    // TravelDFS(G, 3):
    // Visited all 0.
    // DFS(G, 0):
    // Visit 0.
    // Neighbors of 0: G[0].link -> 2.
    // Visit 2? Visited[2] is 0.
    // DFS(G, 2):
    // Visit 2.
    // Neighbors of 2: G[2].link -> 0.
    // Visit 0? Visited[0] is 1. Skip.
    // Return.
    // Return.
    // Output: 0 2. Correct.
    
    // TravelBFS(G, 3):
    // Visited all 0.
    // BFS(G, 0):
    // Visit 0. Visited[0]=1. Enqueue 0.
    // Dequeue 0.
    // Neighbors of 0: 2.
    // Visit 2. Visited[2]=1. Enqueue 2.
    // Dequeue 2.
    // Neighbors of 2: 0.
    // Visited[0] is 1. Skip.
    // Queue empty.
    // Output: 0 2. Correct.
    
    // So why Wrong Answer?
    // Look at the expected output vs buggy output.
    // Buggy:
    // 0 1 2 
    // 0 1 2 
    // 0 2 
    // 0 2 
    // Expected:
    // 0 1 2
    // 0 1 2
    // 0 2
    // 0 2
    
    // The content is identical. The difference is trailing spaces or newlines?
    // `visit` prints "%d ".
    // `travelDFS` prints "\n".
    // So output is "0 1 2 \n".
    // Expected is likely "0 1 2\n".
    // Many online judges are strict about trailing spaces.
    
    // Let's check `visit`.
    void visit(Vlink G[],int c)
    {
            printf("%d ", c); // @@ Prints a space after every number, including the last one in the line. This causes Presentation Error or Wrong Answer on strict judges.
    }
    
    // To fix this, we need to avoid printing the trailing space.
    // However, modifying `visit` to know if it's the last element is hard without context.
    // Alternatively, we can trim the output or change the printing strategy.
    // Given the constraint "do not change the original code structure... except for explicit error markers", I should mark the line causing the formatting issue.
    
    // Another possibility: The `delete` function doesn't free the adjacency list of the deleted vertex `c` itself?
    // In the trace above, `G[1].link` became NULL.
    // What if `c` had no neighbors? Not possible in connected graph with n>=3.
    
    // Let's look at `Front`, `Rear`, `Count` initialization.
    // They are global, so initialized to 0.
    // `memset(Q, 0, sizeof(Q))` in `travelBFS`.
    // `Front` and `Rear` are NOT reset in `travelBFS` or `travelDFS`.
    // `Count` is NOT reset.
    
    // In `main`:
    // 1. `travelDFS` (doesn't use queue).
    // 2. `travelBFS`.
    //    `memset(Q, 0...)`.
    //    `BFS(G, 0)`.
    //    `enQueue` uses `Rear` and `Count`.
    //    Initially `Front=0, Rear=MAXSIZE-1`? No, globals are 0.
    //    Wait, `int Front, Rear, Count;` are global. Initialized to 0.
    //    First `enQueue`:
    //    `Rear = (0+1)%256 = 1`. `Q[1]=item`. `Count=1`.
    //    `deQueue`: `e=Q[0]`. `Count=0`. `Front=1`.
    //    Next `enQueue`: `Rear=2`. `Q[2]`. `Count=1`.
    //    This works fine for the first call.
    
    // 3. `delete(G, c)`.
    // 4. `travelDFS`.
    // 5. `travelBFS`.
    //    `memset(Q, 0...)`.
    //    BUT `Front`, `Rear`, `Count` are NOT reset to 0/initial state.
    //    After the first BFS, `Front` and `Rear` have advanced, and `Count` is 0.
    //    If `Count` is 0, `isEmpty` returns true.
    //    `BFS(G, 0)`:
    //    `enQueue(Q, 0)`.
    //    `Rear = (Rear+1)%MAXSIZE`. `Count++`.
    //    This seems okay logically for a circular queue if `Count` is tracked correctly.
    //    However, `memset(Q, 0, sizeof(Q))` clears the data, but `Front` and `Rear` indices remain from previous run.
    //    As long as `Count` is 0, the queue is considered empty, and `Front`/`Rear` positions just determine where the next elements go.
    //    Since `Count` is 0 after the first BFS finishes (all elements dequeued), the second BFS should work correctly using the existing `Front`/`Rear` pointers as the new "start" (logically empty).
    //    So queue state is likely not the issue.
    
    // Back to the trailing space.
    // The problem asks for "vertices should be printed in a single line, separated by spaces."
    // Usually "1 2 3" is expected, not "1 2 3 ".
    
    // Therefore, the error is in `visit` printing a trailing space.
    
}