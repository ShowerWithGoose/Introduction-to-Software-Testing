#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

struct node {
    int num;
    struct node* next;
};
struct node A[101];

int Visited[101] = {0};
int Queue[201] = {0};

void AddEdge(int a,int b);
void DFS(struct node A[ ], int v);
void BFS(struct node A[ ], int v);
void DelVer(struct node A[ ],int delver);
void Fr (int u,int v);

int main() {
    int i=0,j=0,n,vercount,edgecount,v1,v2,delver;
    scanf("%d%d",&vercount,&edgecount);
    
    for (i=0;i<vercount;i++) {
        A[i].num = i;
        A[i].next = NULL;
    }
    
    for (i=0;i<edgecount;i++) {
        scanf("%d%d",&v1,&v2);
        AddEdge(v1,v2);
        AddEdge(v2,v1);
    }
    
    scanf("%d",&delver);
    
    DFS(A,0);
    printf("\n");
    memset(Visited,0,sizeof(int)*101);
    
    BFS(A,0);
    printf("\n");
    memset(Visited,0,sizeof(int)*101);
    memset(Queue,0,sizeof(int)*201);
    
    DelVer(A,delver);
    
    DFS(A,0);
    printf("\n");
    memset(Visited,0,sizeof(int)*101);
    
    BFS(A,0);
    printf("\n");
    
    return 0;
}

void AddEdge(a,b) { // @@ Missing parameter types in function definition. Should be void AddEdge(int a, int b). This causes compilation errors or undefined behavior in strict C standards.
    struct node* p,*prep,*q;
    if ( A[a].next == NULL ) {
        q = (struct node*)malloc(sizeof(struct node));
        q->num = b;
        q->next = NULL;
        A[a].next = q;
    }
    else {
        prep = &A[a];
        p = A[a].next;
        while ( p->next!=NULL && p->num < b ) {
            prep = p;
            p = p->next;
        }
        
        if ( p->next == NULL && p->num < b ) {
            q = (struct node*)malloc(sizeof(struct node));
            q->num = b;
            q->next = NULL;
            p->next = q;
        }
        else {
            q = (struct node*)malloc(sizeof(struct node));
            q->num = b;
            q->next = p;
            prep->next = q;
        }
    }
}

void DFS(struct node A[ ], int v) {
    struct node* p;
    Visited[v] = 1; //标识某顶点被访问过
    printf("%d ",v);
    for (p = A[v].next; p!=NULL;  p = p->next) {
        if ( Visited[p->num]==0 )
            DFS(A, p->num);
    }
}

void BFS(struct node A[ ], int v) {
    struct node* p;
    int front=0,rear=1;
    Visited[v] = 1;
    Queue[0] = v;
    while ( front!=rear ) {
        v = Queue[front]; //取出队头元素
        front++;
        printf("%d ",v); //访问当前顶点
        for ( p = A[v].next; p!=NULL; p = p->next ) //访问该顶点的每个邻接顶点
            if ( Visited[p->num] == 0 ) {
                Queue[rear] = p->num;
                rear++;
                Visited[p->num] = 1; //标识某顶点入队
            }
    }
}

void DelVer(struct node A[ ],int v) {
    struct node* p,*prep;
    A[v].num = 0;
    p = A[v].next;
    while (p->next != NULL) {
        Fr(p->num,v);
        prep = p;
        p = p->next;
        free(prep);
    }
    Fr(p->num,v);
    free(p);
    A[v].next = NULL; // @@ The adjacency list head for the deleted vertex is not set to NULL after freeing its nodes. This leaves a dangling pointer or invalid state, which might cause issues if the vertex is accessed again or if traversal logic checks for non-NULL heads. Although the problem says we start from 0 and don't delete 0, cleaning up properly is good practice. More critically, if the graph traversal iterates through all vertices (like in the reference code's loop), accessing A[v] when it's not properly nullified but its contents are freed is dangerous. However, the main issue here is likely that the node structure A[v] itself isn't fully reset, but since we don't traverse FROM v after deletion, this might be less critical than the next error.
}

void Fr (int u,int v) {
    struct node* q,*preq;
    preq = &A[u];
    q = A[u].next;
    while ( q->next != NULL ) { // @@ This loop condition fails to check if q itself is NULL before accessing q->next. If the list has only one node or the target is the last node, q->next might be NULL, but the loop exits. However, if the target node is the ONLY node (q->next is NULL initially), the loop doesn't run. The code after the loop handles freeing q. But if q is NULL initially (empty list), this crashes. Given the graph is connected, lists shouldn't be empty for connected nodes, but safety is key. More importantly, if the node to delete is the first node in the adjacency list of u, this logic is flawed because it assumes preq starts at head and q starts at first element. If q->num == v immediately, the loop doesn't run, and it falls through to free(q). This part is actually okay for the first node IF the loop condition was just checking existence. Wait, if q->next is NULL, the loop `while(q->next != NULL)` terminates immediately. Then it executes `preq->next = NULL; free(q);`. This correctly removes the last node or the only node. So the logic for finding and removing is mostly correct EXCEPT it misses the case where the list becomes empty? No, `preq` is `&A[u]`. If `q` is the first node and matches, loop doesn't run. `preq->next` (which is `A[u].next`) is set to NULL. `q` is freed. This works.
    // The real error in Fr is often related to how it's called or if it handles the head correctly. 
    // Let's look closer. If the node to delete is in the middle, the loop runs.
    // If the node to delete is the last one, the loop runs until q is the last one (q->next is NULL). The loop terminates. Then it frees q. Correct.
    // Is there an error? 
    // Actually, the previous analysis of DelVer showed that it frees the nodes in A[v]'s list.
    // The function Fr removes v from u's adjacency list.
    // One potential issue: if `q` is NULL at the start (empty list), `q->next` crashes. But graph is connected.
    // Let's re-read the "Wrong Answer".
    // Input: 3 3, edges 0-1, 1-2, 0-2. Delete 1.
    // Before Delete:
    // DFS: 0 -> 1 -> 2. Output: 0 1 2.
    // BFS: 0 -> 1, 2. Output: 0 1 2.
    // After Delete 1:
    // Graph has 0-2 edge.
    // DFS from 0: 0 -> 2. Output: 0 2.
    // BFS from 0: 0 -> 2. Output: 0 2.
    // Expected: 0 2 \n 0 2.
    // Buggy Output: 0 2 \n 0 2.
    // Wait, the provided buggy output in the prompt is:
    // 0 1 2 
    // 0 1 2 
    // 0 2 
    // 0 2
    // Expected:
    // 0 1 2
    // 0 1 2
    // 0 2
    // 0 2
    // They look identical except for trailing spaces/newlines?
    // "0 1 2 " vs "0 1 2". The printf uses "%d ". This adds a trailing space.
    // Usually online judges ignore trailing whitespace, but some are strict.
    // However, the prompt asks to identify LOGICAL/SEMANTIC errors.
    // Let's look at `AddEdge` again.
    // `void AddEdge(a,b)` without types. This is a K&R style declaration or implicit int. In C99+, this is an error. If compiled as C89, it might work but is bad practice. If the compiler defaults to int, it works.
    // But wait, look at `DelVer`.
    // `A[v].num = 0;`
    // `p = A[v].next;`
    // `while (p->next != NULL)` ... `free(prep)`
    // `Fr(p->num,v); free(p);`
    // This frees the adjacency list of the deleted vertex.
    // And `Fr` removes the deleted vertex from other vertices' adjacency lists.
    
    // Is there a logical error in traversal?
    // In `DFS` and `BFS`, we iterate.
    // If `AddEdge` fails to sort correctly, the order might be wrong.
    // `AddEdge` inserts in sorted order.
    // `while ( p->next!=NULL && p->num < b )`
    // If we insert 2, then 1 into A[0].
    // Insert 2: A[0].next is NULL. Creates node 2. A[0]->2.
    // Insert 1: A[0].next is 2. prep=&A[0], p=2.
    // p->next is NULL. p->num (2) < b (1) is False.
    // Loop doesn't run.
    // `if ( p->next == NULL && p->num < b )` -> False.
    // Else: q=new(1), q->next=p(2), prep->next=q.
    // List: 1->2. Correct.
    
    // What if we insert 1, then 2?
    // Insert 1: A[0].next NULL. Creates 1. A[0]->1.
    // Insert 2: A[0].next is 1. prep=&A[0], p=1.
    // p->next is NULL. p->num (1) < b (2) is True.
    // Loop condition: `p->next!=NULL` is False. Loop doesn't run.
    // `if ( p->next == NULL && p->num < b )` -> True.
    // Creates node 2, appends to p. List: 1->2. Correct.
    
    // So sorting seems correct.
    
    // Let's look at the output format again.
    // Printf("%d ", v).
    // Expected output usually doesn't have trailing space.
    // If the judge is strict, this is the error.
    // But typically "Wrong Answer" implies content mismatch.
    
    // Let's look at `DelVer` again.
    // It frees the nodes of the deleted vertex.
    // It calls `Fr` to remove the vertex from others.
    // Does `Fr` handle the case where the node to remove is the HEAD of the adjacency list correctly?
    // `preq = &A[u]`. `q = A[u].next`.
    // If `q->num == v`, and `q->next != NULL`?
    // The loop `while ( q->next != NULL )` checks `q->next`.
    // If the list is `v -> something`, `q` is `v`. `q->next` is not NULL.
    // Inside loop: `if ( q->num == v )`. Yes.
    // `preq->next = q->next`. `A[u].next` becomes `something`.
    // `free(q)`. Returns.
    // This works for head node IF it has a next node.
    
    // What if the list is `v` (only node)?
    // `q` is `v`. `q->next` is NULL.
    // Loop `while ( q->next != NULL )` does NOT run.
    // Falls through to:
    // `preq->next = NULL;` (`A[u].next` becomes NULL).
    // `free(q);`
    // This also works.
    
    // So `Fr` seems correct.
    
    // Is there an error in `main`?
    // `memset(Visited,0,sizeof(int)*101);`
    // `memset(Queue,0,sizeof(int)*201);`
    
    // Wait, look at `AddEdge` definition line again.
    // `void AddEdge(a,b)`
    // In standard C (C99 and later), this is INVALID. Parameters must have types.
    // If the compiler is old (C89), it assumes `int`.
    // If the environment is modern, this is a Compilation Error, not Wrong Answer.
    // But the prompt says "Wrong Answer". This implies it compiled and ran.
    
    // Let's look closely at the `BFS` output.
    // `printf("%d ",v);`
    // If the expected output is "0 1 2" and actual is "0 1 2 ", some judges fail this.
    
    // However, there is a subtle bug in `DelVer`.
    // `A[v].num = 0;`
    // Why set num to 0? The node struct for the head `A[v]` is not dynamically allocated, it's part of the array.
    // The `num` field of the head node `A[v]` is set to `v` in main.
    // Setting it to 0 doesn't affect traversal because we access `A[v]` by index `v`.
    // But if we had a traversal that iterated through all `A[i]` and checked validity, it might matter.
    // Here, DFS/BFS start from 0.
    
    // Let's look at the `Fr` function again.
    // `void Fr (int u,int v)`
    // It removes `v` from `u`'s list.
    
    // Is it possible that `AddEdge` creates duplicates?
    // The problem says "edges will not be repeated".
    
    // Let's look at the `DFS` function.
    // `printf("%d ",v);`
    
    // There is a known issue with `scanf` and newlines? No.
    
    // Let's reconsider the `AddEdge` signature.
    // If the code compiled, it treated a,b as ints.
    
    // What if the error is in `DelVer` not setting `A[v].next` to NULL?
    // In `DelVer`:
    // After the loop and final free, `A[v].next` still points to the memory that was freed (dangling pointer).
    // Although we don't traverse FROM `v` (since `v` is deleted and we start from 0), if `v` was 0, it would crash. But problem says "vertex to be deleted is not vertex 0".
    // So dangling pointer in `A[v]` is not accessed.
    
    // However, look at `Fr`.
    // If `u` has an adjacency list, and we remove `v`.
    
    // Is there a case where `AddEdge` fails to sort?
    // `while ( p->next!=NULL && p->num < b )`
    // If `p->num == b`, the loop stops.
    // Then `if ( p->next == NULL && p->num < b )` is false.
    // Else: inserts BEFORE `p`.
    // If `p->num == b`, we insert a duplicate?
    // The problem states no repeated edges. So `b` won't equal `p->num` if the edge already exists.
    
    // Let's look at the output difference again.
    // Buggy: `0 1 2 ` (space at end)
    // Expected: `0 1 2` (no space at end)
    
    // If the judge is strict about whitespace, the error is the `printf` format.
    // Line: `printf("%d ",v);` in DFS and BFS.
    // Also `printf("%d ",A[a]->id);` in reference.
    
    // In the provided buggy code:
    // `printf("%d ",v);` in DFS.
    // `printf("%d ",v);` in BFS.
    
    // To fix trailing space, one usually prints the first element separately or uses a different format.
    // Since I must annotate the error location:
    
    // The most likely "Wrong Answer" cause in strict judges is the trailing space.
    
    // Another possibility: `AddEdge` logic for insertion at the end.
    // `if ( p->next == NULL && p->num < b )`
    // If `p` is the last node and `p->num < b`, we append.
    // Else, we insert before `p`.
    // What if `p->num > b`? We insert before `p`. Correct.
    // What if `p->num == b`? We insert before `p` (duplicate). But input guarantees no duplicates.
    
    // I will annotate the `printf` lines as the source of formatting error if strict, but usually "Wrong Answer" allows trailing spaces.
    
    // Wait! Look at `DelVer` again.
    // `A[v].num = 0;`
    // If the DFS/BFS logic relied on `A[i].num` being valid for ALL nodes, this might be an issue?
    // No, DFS/BFS uses the index `v` passed to it, and accesses `A[v].next`.
    
    // Let's look at `main`.
    // `memset(Visited,0,sizeof(int)*101);`
    
    // Is it possible the graph is not symmetric?
    // `AddEdge(v1,v2); AddEdge(v2,v1);`
    
    // I suspect the error is indeed the trailing space or the `AddEdge` signature causing undefined behavior in some compilers leading to wrong execution.
    // But given "Wrong Answer", I'll bet on the output format.
    
    // However, there is one more logical error.
    // In `DelVer`, `A[v].next` is not set to NULL.
    // If `BFS` or `DFS` were to iterate over ALL vertices (like the reference code does: `for(i=0;i<n;i++) if(!v[i]&&A[i])`), they check `A[i]`.
    // In the buggy code, `DFS(A,0)` and `BFS(A,0)` are called directly with start node 0. They do NOT iterate over all vertices to find components. They assume connectivity.
    // The problem states: "The graph is connected both before and after deleting".
    // So starting from 0 is sufficient.
    
    // Therefore, the dangling pointer in `A[v]` is never dereferenced.
    
    // Final check: `AddEdge` signature.
    // If this is C++, it's an error. If C89, it's warning.
    // If the compiler is GCC with default settings, it might compile.
    
    // I will mark the `printf` statements for trailing space.
    
    // Actually, looking at the reference code, it also prints with space: `printf("%d ",A[a]->id);`.
    // If the reference code is "correctly implemented", then trailing space is acceptable?
    // But the reference code output isn't shown, just the code.
    // The "Expected Output" in the prompt does NOT have trailing spaces.
    // "0 1 2"
    
    // If the reference code produces "0 1 2 " and is considered correct, then the judge ignores spaces.
    // If the judge expects "0 1 2", then the reference code would also fail?
    // Unless the reference code handles spacing differently?
    // Reference: `printf("%d ", ...)` inside the loop. It WILL produce trailing space.
    
    // So if the reference code is correct, the judge MUST accept trailing spaces.
    
    // Then what is the error?
    
    // Look at `DelVer` in the buggy code vs `destory` in reference.
    // Reference `destory`:
    // Iterates through `A[a]->next`. For each neighbor `p->id`, it searches `A[p->id]` for `a` and removes it.
    // Then sets `A[a] = NULL`.
    
    // Buggy `DelVer`:
    // Sets `A[v].num = 0`.
    // Iterates through `A[v].next`. Calls `Fr(p->num, v)`. Frees nodes.
    // Does NOT set `A[v].next = NULL`.
    
    // If `A[v].next` is not NULL, and if any code checks `A[v].next`, it accesses freed memory.
    // But we established we don't access `A[v]` after deletion.
    
    // Is it possible `Fr` is incorrect?
    // `Fr` removes `v` from `u`.
    
    // Let's look at `AddEdge` again.
    // `void AddEdge(a,b)`
    
    // If I must find an error, and the output looks identical visually (ignoring trailing space), maybe the error is `AddEdge` signature causing stack corruption or argument passing issues on some platforms?
    
    // Or, is `memset` correct?
    // `memset(Visited,0,sizeof(int)*101);`
    // `Visited` is `int[101]`. Size is `101 * sizeof(int)`. Correct.
    
    // I will annotate the `AddEdge` definition line as it is non-standard and potentially dangerous/erroneous depending on compiler, and the `printf` lines for potential formatting strictness.
    
    // However, the most distinct "logic" error that differs from the reference is `A[v].next` not being NULLed. Even if not accessed now, it's bad state.
    
    // Let's annotate the `AddEdge` line.
}