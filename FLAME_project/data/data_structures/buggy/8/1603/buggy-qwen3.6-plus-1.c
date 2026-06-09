#include<stdio.h>
#include<stdlib.h>
int visited[105] = {0};
int deletever;

int Q[105] = {-1};
int top = 0;
int end = 0;

void enQueue(int Q[], int b)
{
    Q[end++] = b;
}
int deQueue(int Q[])
{
    int a;
    a = Q[top++];
    Q[top - 1] = -1;
    return a;
}

typedef struct _edge
{
    int flag;
    int adjver;
    struct _edge *next;
} edge,*Pedge;


typedef struct _ver
{
    int flag;
    edge *link;
} ver,*Pver;

ver G[105];

void visit(ver G[], int v)
{
    printf("%d ",v);
}

void DFS(ver G[], int v)
{
    Pedge p;
    visited[v] = 1; //标识某顶点被访问过
    visit(G,v);
    for (p = G[v].link; p != NULL; p = p->next)
    {
        if (!visited[p->adjver])
        {
            DFS(G, p->adjver);
        }
    }

}

void DFS1(ver G[], int v,int deletever)
{
    Pedge p;
    Pedge k;
    visited[v] = 1; //标识某顶点被访问过
    p = G[v].link;
    if(p != NULL && p->adjver == deletever)
    {
        k = p->next;
        G[v].link = k;
    }
    //visit(G,v);
    for (p = G[v].link; p != NULL; p = p->next)
    {
        if(p->next != NULL && p->next->adjver == deletever)
        {
            k = p->next->next;
            p->next = k;
        }

        if (!visited[p->adjver])
        {
            DFS1(G, p->adjver,deletever);
        }

    }

}


void BFS(ver G[], int v)
{
    Pedge p;

    visit(G, v); //访问当前顶点
    visited[v] = 1; //标识某顶点被访问过
    enQueue(Q, v);
    while (top < end)
    {
        v = deQueue(Q); //取出队头元素
        p = G[v].link; //获取该顶点第一个邻接顶点

        for (; p != NULL; p = p->next)
        {
            if (!visited[p->adjver])
            {
                visit(G,p->adjver);//访问当前顶点
                visited[p->adjver] = 1; //标识某顶点被访问过
                enQueue(Q, p->adjver);
            }
        }
    }
}


Pedge create(int a)
{
    Pedge p;
    p = (Pedge)malloc(sizeof(edge));
    p->flag = 1;
    p->adjver = a;
    p->next = NULL;
    return p;
}

void insert(ver G[], Pedge p, int a)
{

    Pedge k, q ;
    if(G[a].link == NULL)
    {
        G[a].link = p;
    }
    else
    {
        k = G[a].link;
        while(k != NULL)
        {
            if(k->adjver > p->adjver)
            {
                q = k;
                k = q->next;
                break;
            }
            if(k->next != NULL && k->next->adjver > p->adjver)
            {
                q = k;
                k = q->next;
                break;
            }
            q = k;
            k = q->next;
        }
        p->next = k;
        q->next = p;
    }

    /*int i;
    for(i = 0 ; i < 9 ;i++)//
    {
        printf("%d ",i);
        q = G[i].link;
        while(q != NULL)
        {
            printf("%d ",q->adjver);
            p = q;
            q = p->next;
        }
        printf("\n");
    }*/
}

int main ()
{
    int i;
    int a, b;
    int vetn,edgen;

    Pedge p,  k;
    scanf("%d %d",&vetn,&edgen);

    for(i = 0 ; i < vetn ; i++)
    {
        G[i].flag = 1;
    }
    for(i = 0 ; i < edgen ; i++)
    {
        scanf("%d %d",&a, &b);

        p = create(b);
        //printf("aaaaaaaaaaaaaaaa%d",p->adjver);
        insert(G, p, a);


        k = create(a);
        //printf("aaaaaaaaaaaaaaaa%d",k->adjver);
        insert(G, k, b);

    }

    /*for(i = 0 ; i < vetn ;i++)
    {
        printf("%d ",i);
        q = G[i].link;
        while(q != NULL)
        {
            printf("%d ",q->adjver);
            p = q;
            q = p->next;
        }
        printf("\n");
    }*/

    scanf("%d",&deletever);

    DFS(G,0);
    printf("\n");
    for(i = 0 ; i < 105 ; i++)
    {
        visited[i] = 0;
    }
    BFS(G,0);
    printf("\n");
    for(i = 0 ; i < 105 ; i++)
    {
        visited[i] = 0;
    }

    DFS1(G,0,deletever); // @@ The function DFS1 attempts to modify the graph structure during traversal but fails to correctly remove all edges connected to the deleted vertex, and it does not skip the deleted vertex itself if encountered. More importantly, the subsequent DFS call uses the original DFS function which does not know about the deletion. The graph modification in DFS1 is incomplete and buggy (e.g., it doesn't handle the case where the head node needs deletion correctly in all recursive steps, and it modifies the list while iterating). However, the primary issue is that the problem requires outputting the traversal *after* deleting the vertex. The reference approach usually involves either marking the vertex as deleted and checking flags during traversal, or physically removing it from the adjacency lists before traversing. The current code tries to do physical removal inside a DFS traversal (DFS1), which is logically flawed because it mixes traversal state (visited) with structural modification. Then it calls standard DFS again. The standard DFS will still traverse edges to the deleted vertex if they weren't removed correctly, or crash/access invalid memory if they were. But looking at the expected output, the second DFS/BFS should simply ignore the deleted vertex. The current implementation of DFS1 is intended to remove edges, but it's called *instead* of a proper deletion step before the second pair of traversals. The second pair of traversals uses the original `DFS` and `BFS` functions. If `DFS1` successfully removed all edges pointing to `deletever`, then `DFS` would work. However, `DFS1` is buggy. It only removes edges from the current vertex's list if they point to `deletever`. It recurses. But it doesn't remove the `deletever` node's own outgoing edges (though they won't be visited if `deletever` is not reached). The critical flaw is that `DFS1` modifies the graph structure. If it fails to remove an edge to `deletever`, the subsequent `DFS` will try to visit `deletever`. Since `visited` is reset, it will visit it. This is wrong. Also, `DFS1` marks nodes as visited. The subsequent `DFS` resets visited. So the structural change is the only effect. The logic in `insert` is also suspect for sorted insertion. Let's look at `insert`. It tries to keep the list sorted.
    
    The main error is that the program does not correctly implement the "deletion" of the vertex for the second part of the output. It calls `DFS1` which is a broken attempt at deleting edges during a traversal. A correct approach would be to have a separate function to remove the vertex and its edges from the adjacency lists completely, or modify `DFS`/`BFS` to accept a `deleted_vertex` parameter and skip it. Given the structure, the easiest fix is to make sure the graph is properly modified before the second set of traversals. The current `DFS1` is insufficient and incorrect.
    
    However, looking closely at the provided "Buggy Output" vs "Expected Output":
    Buggy:
    0 1 2 
    0 1 2 
    0 2 
    0 2 
    
    Expected:
    0 1 2
    0 1 2
    0 2
    0 2
    
    The outputs are actually identical in terms of numbers. The difference might be trailing spaces or newlines.
    Let's check the print statements.
    `visit` prints "%d ".
    `DFS` prints "0 1 2 ". Then `printf("\n")`.
    So line 1: "0 1 2 \n"
    Line 3: "0 2 \n"
    
    The expected output usually doesn't care about trailing spaces in many judges, but sometimes it does.
    Wait, look at the last line of Buggy Output: `0 2`.
    Look at the last line of Expected Output: `0 2`.
    
    Let's re-read the prompt carefully.
    "Identify the location of the errors... If you think an error may occur on a particular line, add @@ symbol..."
    
    Is there a logical error?
    In `DFS1`, the logic for removing edges is flawed.
    `if(p != NULL && p->adjver == deletever)` handles the head.
    Inside the loop: `if(p->next != NULL && p->next->adjver == deletever)` handles subsequent nodes.
    But `DFS1` is called with `visited` array. It marks nodes as visited.
    Then `visited` is reset.
    Then `DFS(G,0)` is called.
    
    If `DFS1` correctly removed all edges TO `deletever`, then `DFS(G,0)` would not reach `deletever`.
    Does `DFS1` remove ALL edges to `deletever`?
    It traverses the graph starting from 0. It removes edges pointing to `deletever` from the adjacency lists of the nodes it visits.
    Since the graph is connected, it visits all reachable nodes (excluding `deletever` if it's not reached, but `deletever` is reachable in the first place).
    Wait, `DFS1` skips visiting `deletever`?
    `if (!visited[p->adjver]) DFS1(...)`.
    If `p->adjver` is `deletever`, and `deletever` hasn't been visited (it won't be, as we don't call visit on it explicitly in DFS1? No, `visit` is commented out).
    But `visited` array is local to the logic.
    If `p->adjver == deletever`, `visited[deletever]` is 0. So it WILL recurse into `deletever` if not handled.
    Inside `DFS1(deletever)`:
    It will try to remove edges FROM `deletever` to others? No, it removes edges pointing TO `deletever` from the perspective of the current node.
    When inside `DFS1(deletever)`, `v` is `deletever`.
    It iterates `G[deletever].link`.
    It removes edges where `adjver == deletever` (self loops? unlikely).
    It recurses to neighbors.
    
    The problem is that `DFS1` modifies the graph structure.
    If `DFS1` runs, it removes edges pointing to `deletever` from all nodes visited.
    Since it starts at 0 and the graph is connected, it visits all nodes except potentially `deletever` if the edge to it is removed before recursion?
    No, the check `if (!visited[p->adjver])` happens AFTER the removal logic for `p->next`.
    But for the head `G[v].link`, if it points to `deletever`, it is removed.
    Then the loop starts.
    
    Actually, the biggest issue is likely that `DFS1` is not a standard deletion. It's a traversal that side-effects the graph.
    
    Let's look at the `insert` function.
    It maintains a sorted linked list.
    
    Let's look at the `BFS` function.
    It uses a global queue.
    
    The "Wrong Answer" might be due to the fact that the second DFS/BFS traversals are performed on a graph that has been partially modified by `DFS1`, but `DFS1` is buggy.
    
    Specifically, in `DFS1`:
    `if(p != NULL && p->adjver == deletever)` -> removes head if it is deletever.
    Then `for (p = G[v].link; ...)`
    Inside loop: `if(p->next != NULL && p->next->adjver == deletever)` -> removes next if it is deletever.
    
    This logic seems to cover removing edges pointing to `deletever`.
    
    However, the `DFS1` function also recursively calls itself.
    If `p->adjver` is NOT `deletever`, it recurses.
    If `p->adjver` IS `deletever`, it does NOT recurse (because `visited[deletever]` is 0, but wait... if we didn't remove the edge, we would recurse. If we DID remove the edge, `p` moves to next.
    
    Wait, if `G[v].link` was `deletever`, we removed it. `p` becomes the new link.
    Then the loop continues.
    
    The issue is that `DFS1` does NOT prevent entering `deletever` if there are multiple paths?
    No, if all edges TO `deletever` are removed, `deletever` becomes unreachable.
    
    So, does `DFS1` remove ALL edges to `deletever`?
    It visits every node reachable from 0.
    For each node, it scans its adjacency list and removes entries equal to `deletever`.
    Yes, this should work logically to isolate `deletever`.
    
    So why is it Wrong Answer?
    
    Let's check the output format again.
    Buggy: `0 2 ` (space at end)
    Expected: `0 2` (no space at end?)
    
    Many online judges are sensitive to trailing spaces.
    The `visit` function prints `%d `.
    This always adds a space after the number.
    
    To fix this, one usually prints the first element without a space, or prints a space before subsequent elements, or trims the output.
    
    Given the strict "Wrong Answer" and the visual similarity, trailing whitespace is a very common cause.
    
    Let's annotate the `visit` function or the print calls.
    
    However, I must annotate specific lines.
    
    Line: `printf("%d ",v);` in `visit`.
    
    Another possibility: The `DFS1` function corrupts the graph structure in a way that causes the second `DFS` to behave incorrectly?
    In the test case:
    3 3
    0 1
    1 2
    0 2
    Delete 1.
    
    Graph:
    0: 1 -> 2
    1: 0 -> 2
    2: 0 -> 1
    
    `DFS1(G, 0, 1)`:
    v=0. visited[0]=1.
    p = G[0].link (points to 1).
    Head check: p->adjver == 1 (deletever).
    k = p->next (points to 2).
    G[0].link = k (points to 2).
    
    Loop: p = G[0].link (points to 2).
    p->next is NULL.
    Check p->next... false.
    visited[2] is 0.
    Recurse DFS1(G, 2, 1).
    
    Inside DFS1(G, 2, 1):
    v=2. visited[2]=1.
    p = G[2].link (points to 0? No, sorted. 0 < 1. So 0 -> 1).
    Wait, insert order:
    Edge 0-1:
    Insert 1 into 0. G[0]: 1.
    Insert 0 into 1. G[1]: 0.
    Edge 1-2:
    Insert 2 into 1. G[1]: 0 -> 2.
    Insert 1 into 2. G[2]: 1.
    Edge 0-2:
    Insert 2 into 0. G[0]: 1 -> 2. (1 < 2, so append).
    Insert 0 into 2. G[2]: 0 -> 1. (0 < 1, so prepend? Let's check `insert`).
    
    `insert(G, p, a)`:
    If G[a].link == NULL, set it.
    Else:
    k = G[a].link.
    While k != NULL:
    if k->adjver > p->adjver: break.
    if k->next != NULL && k->next->adjver > p->adjver: break.
    q=k; k=q->next;
    
    Insert 0 into 2 (G[2] currently has 1):
    k points to 1.
    k->adjver (1) > p->adjver (0)? Yes.
    Break.
    q is uninitialized?
    Wait. `q` is declared `Pedge k, q;`.
    If the loop breaks immediately, `q` is uninitialized.
    Then `p->next = k` (0->next = 1).
    `q->next = p` (CRASH or garbage).
    
    This is a bug in `insert`. `q` is not initialized before the loop if the insertion happens at the head.
    
    Let's trace `insert` for head insertion.
    k = G[a].link.
    Loop condition `k != NULL`.
    Inside:
    `if(k->adjver > p->adjver)` -> True.
    `q = k;` -> q points to head.
    `k = q->next;` -> k points to next.
    `break;`
    
    Then `p->next = k`.
    `q->next = p`.
    
    So if inserting at head:
    q becomes the old head.
    p->next becomes old head's next.
    q->next (old head's next) becomes p.
    
    This effectively inserts p AFTER q (the old head).
    This is WRONG for sorted insertion at the head. It should replace the head.
    
    Example: List: 1. Insert 0.
    k=1. 1>0. q=1. k=NULL. Break.
    p->next = NULL.
    q->next = p. (1->next = 0).
    List becomes 1 -> 0.
    This is NOT sorted. And G[a].link still points to 1.
    
    So the adjacency lists are not sorted correctly.
    
    This affects the traversal order.
    Requirement: "visit them in ascending order of their vertex numbers."
    
    If the lists are not sorted, the DFS/BFS order might be wrong.
    
    In the test case:
    G[2] became 1 -> 0 instead of 0 -> 1.
    
    First DFS (before deletion):
    Start 0.
    G[0]: 1 -> 2.
    Visit 0.
    Neighbor 1. Visit 1.
    G[1]: 0 -> 2.
    Neighbor 0 (visited).
    Neighbor 2. Visit 2.
    G[2]: 1 -> 0 (due to bug).
    Neighbor 1 (visited).
    Neighbor 0 (visited).
    Order: 0 1 2. Correct.
    
    First BFS:
    Queue: 0.
    Dequeue 0. Neighbors 1, 2.
    Visit 1, Enqueue 1.
    Visit 2, Enqueue 2.
    Dequeue 1. Neighbors 0, 2. Both visited.
    Dequeue 2. Neighbors 1, 0. Both visited.
    Order: 0 1 2. Correct.
    
    Delete 1.
    `DFS1` modifies graph.
    
    Second DFS:
    Start 0.
    G[0] had 1->2. `DFS1` removed 1. G[0] is 2.
    Visit 0.
    Neighbor 2. Visit 2.
    G[2] had 1->0. `DFS1` at node 2:
    v=2.
    p = G[2].link (1).
    Head check: p->adjver == 1 (deletever).
    Remove head. G[2].link becomes 0.
    Loop p=0.
    Recurse? visited[0] is 1. No.
    
    So G[2] is 0.
    Back to DFS(0).
    At 2.
    Neighbor 0 (visited).
    Order: 0 2. Correct.
    
    Second BFS:
    Queue 0.
    Dequeue 0. Neighbor 2.
    Visit 2. Enqueue 2.
    Dequeue 2. Neighbor 0 (visited).
    Order: 0 2. Correct.
    
    So despite the `insert` bug, the output matches the expected numbers.
    
    Therefore, the error is almost certainly the **trailing space**.
    
    The `visit` function prints `%d `.
    
    I will annotate the `visit` function.