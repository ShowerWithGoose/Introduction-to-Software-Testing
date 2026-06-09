#include<stdio.h>
#include<stdlib.h>
#define max_size 100
typedef struct edge{
         int adjvex;
         struct edge *next;
}Elink;
typedef struct ver{
        int vertex;
        struct edge *link;
}Vlink;
Vlink G[max_size];
int visited[max_size];
void DFS(int v) {
     Elink *p;
     printf("%d ",v);
     visited[v]=1;
     for(p=G[v].link;p!=NULL;p=p->next) {
        if(visited[p->adjvex]==0) {
            DFS(p->adjvex);
        }
     }
}
int queue[max_size];
/*int front=-1,rear=-1;
int queue[max_size];
int empty(int front,int rear) {
    return front==rear;
}
int getqueue(int queue[],int *front,int *rear) {
    int item;
    if(empty(*front,*rear)) {return 0;}
    item=queue[(*front)+1];
    return item;
}
int addqueue(int queue[],int *rear,int item) {
    queue[++(*rear)]=item;
    return 1;
}
int delqueue(int queue[],int *front,int *rear) {
     int item;
     item=queue[++(*front)];
     return item;
}
void BFS(int v) {
      Elink *p;
      visited[v]=1;
      addqueue(queue,&rear,v);
      while(!empty(front,rear)) {
        printf("%d %d\n",front,rear);
        v=delqueue(queue,&front,&rear);
        //printf("%d ",v);
        for(p=G[v].link;p!=NULL;p=p->next) {
            if(!visited[p->adjvex]) {
                visited[p->adjvex];
                addqueue(queue,&rear,p->adjvex);
            }
        }
      }
}*/
int main() {
     int n,l,del,a,b;
     scanf("%d%d",&n,&l);
     for(int i=0;i<n;i++) {
        G[i].vertex=i;
        G[i].link=NULL;
     }
     for(int i=0;i<l;i++) {
        Elink *p1,*p2,*q1,*q2,*r1,*r2;
        scanf("%d%d",&a,&b);
        p1=(Elink*)malloc(sizeof(Elink));
        p1->adjvex=a;
        p1->next=NULL;
        if(G[b].link==NULL) {
            G[b].link=p1;
        } else {
            q1=G[b].link;
            if(a<q1->adjvex) {
                p1->next=q1;
                G[b].link=p1;
                continue;
            }
            while(q1!=NULL&&a>q1->adjvex) {
                r1=q1;
                q1=q1->next;
            }
            if(q1==NULL) {
                r1->next=p1;
            } else {
                p1->next=q1;
                r1->next=p1;
            }
        }
        Elink *k;
        /*for(int j=0;j<n;j++){
        printf("%d: ",j);
        k=G[j].link;
        while(k!=NULL) {
            printf("%d  ",k->adjvex);
            k=k->next;
        }
        printf("\n");
     }*/

        p2=(Elink*)malloc(sizeof(Elink));
        p2->adjvex=b;
        p2->next=NULL;
        if(G[a].link==NULL) {
            G[a].link=p2;
        } else {
            q2=G[a].link;
            if(b<q2->adjvex) {
                p2->next=q2;
                G[a].link=p2;
                continue;
            }
            while(q2!=NULL && b>q2->adjvex) {
                r2=q2;
                q2=q2->next;
            }
            if(q2==NULL) {
                r2->next=p2;
            } else {
                p2->next=q2;
                r2->next=p2;
            }
        }
    /*for(int j=0;j<n;j++){
        printf("%d: ",j);
        k=G[j].link;
        while(k!=NULL) {
            printf("%d  ",k->adjvex);
            k=k->next;
        }
        printf("\n");
     }*/
     } // 创建列表
     scanf("%d",&del);
     /*Elink *k;
     for(int j=0;j<n;j++){
        printf("%d: ",j);
        k=G[j].link;
        while(k!=NULL) {
            printf("%d  ",k->adjvex);
            k=k->next;
        }
        printf("\n");
     }*/
     DFS(0);
     printf("\n");
     for(int i=0;i<max_size;i++) {
        visited[i]=0;
     }
     int front=-1,rear=-1;
     Elink *p;
     visited[0]=1;
     queue[++rear]=0;
     while(rear!=front) {
        int v;
        v=queue[++front];
        printf("%d ",v);
        for(p=G[v].link;p!=NULL;p=p->next) {
            if(!visited[p->adjvex]) {
                visited[p->adjvex]=1;
                queue[++rear]=p->adjvex;
            }
        }
     }
     printf("\n");
     for(int j=0;j<n;j++) {
        Elink *k,*g;
        k=G[j].link;
        if(G[j].vertex==del) {
            continue;
        }
        if(k!=NULL && k->adjvex==del) { // @@ The original code did not check if k is NULL before accessing k->adjvex, which could cause a crash if the adjacency list is empty. Also, logic for deleting head node needs to be robust.
            G[j].link=k->next;
            free(k);
            continue;
        }
        g = NULL; // @@ Initialize g to NULL to track the previous node correctly.
        while(k!=NULL) {
            if(k->adjvex==del) {
                if (g != NULL) { // @@ Check if g is not NULL before accessing g->next.
                    g->next=k->next;
                }
                free(k);
                break;
            }
            g=k;
            k=k->next;
        }
     }
     // @@ The code above only removes edges connected to 'del'. It does not remove the vertex 'del' from the graph structure itself (i.e., G[del] still exists and might be traversed if indices are not shifted or if traversal logic doesn't skip it). 
     // However, the bigger issue is that the vertices are labeled 0 to n-1. If we delete vertex 'del', the remaining vertices still have their original labels. 
     // The DFS/BFS traversals iterate based on adjacency lists. If we just remove edges to 'del', but 'del' is still in the array G, and we start DFS(0), it won't visit 'del' because it's disconnected (edges removed). 
     // BUT, the problem requires outputting the sequence of vertices. The vertices are identified by their labels. 
     // If we delete vertex 1 from {0, 1, 2}, the remaining vertices are 0 and 2. 
     // The current deletion logic only removes edges. It does not remove the vertex entry from the G array or adjust indices. 
     // Since the graph vertices are 0..n-1, and we are using an array of size max_size, simply ignoring the deleted vertex during traversal is not enough if the traversal logic relies on visiting all nodes or if the adjacency lists contain indices that need shifting (which they don't here, labels are fixed).
     // Wait, if we just remove edges to 'del', then DFS(0) will traverse 0 and its neighbors. If 1 was a neighbor, it's gone. So 0 connects to 2. DFS visits 0, then 2. This seems correct for the traversal content.
     // HOWEVER, look at the expected output: "0 2". The buggy output is "0 ". Why?
     // Let's trace the deletion for input: 3 vertices, edges (0,1), (1,2), (0,2). Delete 1.
     // G[0]: 1 -> 2. G[1]: 0 -> 2. G[2]: 1 -> 0.
     // Delete 1:
     // j=0: G[0].vertex=0 != 1. k=G[0].link points to node(1). k->adjvex==1. Remove head. G[0].link becomes node(2).
     // j=1: G[1].vertex=1 == 1. Continue. (Vertex 1 is skipped, but its entry in G remains).
     // j=2: G[2].vertex=2 != 1. k=G[2].link points to node(1). k->adjvex==1. Remove head. G[2].link becomes node(0).
     // Now G[0] has neighbor 2. G[2] has neighbor 0. G[1] is effectively isolated/ignored.
     // DFS(0): Visit 0. Neighbor 2. Visit 2. Neighbor 0 (visited). End. Output: "0 2 ".
     // Why did the buggy output show "0 "?
     // Let's look at the buggy output again:
     // 0 1 2 
     // 0 1 2 
     // 0 
     // 0
     // The last two lines are wrong.
     // In the deletion loop:
     // for(int j=0;j<n;j++) { ... }
     // If j=1, we `continue`. We do NOT remove edges FROM vertex 1 to others.
     // But more importantly, we do NOT remove edges TO vertex 1 from other vertices properly if the logic is flawed.
     // Let's re-read the deletion code carefully.
     // if(k->adjvex==del) { G[j].link=k->next; free(k); continue; }
     // This handles the head.
     // while(k!=NULL) { if(k->adjvex==del) { g->next=k->next; free(k); break; } g=k; k=k->next; }
     // This handles non-head.
     // Is there a bug in the BFS/DFS after deletion?
     // The DFS/BFS code uses `visited` array.
     // The issue might be that `G` array still has `n` elements, but we are iterating `j` from 0 to `n-1` in deletion.
     // Actually, the main problem is likely that the vertex `del` is not physically removed from the graph structure, but since we don't traverse it (it's not reachable from 0 if edges are cut), it should be fine.
     // Wait, look at the second BFS output in buggy: "0".
     // BFS: Start 0. Queue: 0. Pop 0. Print 0. Neighbors of 0: G[0].link is node(2). Push 2.
     // Pop 2. Print 2. Neighbors of 2: G[2].link is node(0). 0 is visited.
     // Queue empty.
     // So BFS should print "0 2 ".
     // Why did it print "0 "?
     // Maybe the deletion didn't work correctly?
     // Let's check the insertion logic.
     // Input: 0 1.
     // Insert into G[1]: p1->adjvex=0. G[1].link=NULL -> G[1].link=p1.
     // Insert into G[0]: p2->adjvex=1. G[0].link=NULL -> G[0].link=p2.
     // Input: 1 2.
     // Insert into G[2]: p1->adjvex=1. G[2].link=NULL -> G[2].link=p1.
     // Insert into G[1]: p2->adjvex=2. G[1].link=node(0). q1=node(0). 2>0. r1=node(0). q1=NULL. r1->next=p2. G[1]: 0->2.
     // Input: 0 2.
     // Insert into G[2]: p1->adjvex=0. G[2].link=node(1). q1=node(1). 0<1. p1->next=q1. G[2].link=p1. G[2]: 0->1.
     // Insert into G[0]: p2->adjvex=2. G[0].link=node(1). q2=node(1). 2>1. r2=node(1). q2=NULL. r2->next=p2. G[0]: 1->2.
     
     // So initial state:
     // G[0]: 1 -> 2
     // G[1]: 0 -> 2
     // G[2]: 0 -> 1
     
     // Delete 1.
     // j=0. G[0].vertex=0. k=G[0].link (node 1). k->adjvex=1==del.
     // G[0].link = k->next (node 2). Free k.
     // G[0]: 2.
     
     // j=1. G[1].vertex=1==del. Continue.
     
     // j=2. G[2].vertex=2. k=G[2].link (node 0). k->adjvex=0!=del.
     // g=NULL. k=node(0).
     // Loop: k!=NULL. k->adjvex=0!=1. g=node(0). k=k->next (node 1).
     // Loop: k!=NULL. k->adjvex=1==del.
     // g->next = k->next (NULL). Free k. Break.
     // G[2]: 0.
     
     // So after deletion:
     // G[0]: 2
     // G[1]: 0 -> 2 (Not cleaned up, but unreachable from 0 if we don't start there)
     // G[2]: 0
     
     // DFS(0):
     // Visit 0. Mark visited.
     // Neighbors: 2.
     // DFS(2):
     // Visit 2. Mark visited.
     // Neighbors: 0. Visited. Return.
     // Return.
     // Output: 0 2.
     
     // BFS(0):
     // Visit 0. Queue: 0.
     // Pop 0. Print 0.
     // Neighbors: 2. Not visited. Mark visited. Queue: 2.
     // Pop 2. Print 2.
     // Neighbors: 0. Visited.
     // Queue empty.
     // Output: 0 2.
     
     // So logically, the code SHOULD produce 0 2.
     // Why does the buggy output say "0 "?
     // Is it possible that `G[j].vertex==del` check is failing or something?
     // Or maybe `visited` array wasn't cleared properly?
     // `for(int i=0;i<max_size;i++) visited[i]=0;` is called.
     
     // Let's look closely at the BFS loop in the code provided.
     // `while(rear!=front)`
     // `v=queue[++front];`
     // `printf("%d ",v);`
     // `for(p=G[v].link;p!=NULL;p=p->next)`
     // `if(!visited[p->adjvex])`
     // `visited[p->adjvex]=1;`
     // `queue[++rear]=p->adjvex;`
     
     // This looks correct.
     
     // What if the deletion loop didn't execute correctly?
     // `for(int j=0;j<n;j++)`
     // If `n` is 3. j=0,1,2.
     
     // Is it possible that `G[j].link` was NULL?
     // In our trace, G[0] had link. G[2] had link.
     
     // Let's look at the `DFS` function.
     // `printf("%d ",v);`
     // It prints a space after every number.
     // Expected output: "0 2" (no trailing space specified in problem description usually, but often accepted).
     // The expected output block shows:
     // 0 2
     // 0 2
     // The buggy output shows:
     // 0 
     // 0
     // This implies only 0 was printed.
     // This means vertex 2 was NOT visited.
     // Why?
     // If G[0].link was NULL after deletion, then 2 wouldn't be visited.
     // Did the deletion remove the edge to 2 incorrectly?
     
     // In j=0 iteration:
     // k=G[0].link (node 1).
     // if(k->adjvex==del) -> 1==1. True.
     // G[0].link = k->next.
     // k->next was node 2.
     // So G[0].link becomes node 2.
     // This is correct.
     
     // Is it possible that `free(k)` invalidated something? No, k is the node being removed.
     
     // Wait! Look at the `DFS` function definition.
     // `void DFS(int v)`
     // It uses global `G`.
     
     // Look at the `main` function's deletion loop again.
     // `Elink *k,*g;`
     // `k=G[j].link;`
     // `if(G[j].vertex==del) { continue; }`
     // `if(k->adjvex==del) { ... }`
     
     // If `G[j].link` is NULL, `k` is NULL.
     // `if(k->adjvex==del)` will crash or behave undefinedly if k is NULL.
     // In our specific case, G[0] and G[2] were not NULL.
     
     // However, there is a subtle bug in the `else` part of the deletion (the while loop).
     // `g` is uninitialized if the head node is not deleted.
     // `g=k;` happens inside the loop.
     // If the list is `A -> B -> C` and we delete `B`.
     // k=A. g=NULL.
     // Loop 1: k=A. adjvex!=del. g=A. k=B.
     // Loop 2: k=B. adjvex==del. g->next = B->next (C). Free B.
     // This works.
     
     // What if the list is `A -> C` and we delete `B` (not present)?
     // Loop finishes. Nothing happens. Correct.
     
     // Let's look at the test case input again.
     // 3 3
     // 0 1
     // 1 2
     // 0 2
     // 1
     
     // Is it possible the order of edges in adjacency list is different?
     // The insertion sort logic:
     // `while(q1!=NULL&&a>q1->adjvex)`
     // This sorts in ascending order.
     
     // There is one major issue: **The vertex `del` is still in the `G` array.**
     // When we run DFS/BFS, we start at 0.
     // We traverse to neighbors.
     // If the graph was larger, and we deleted a vertex in the middle, the indices of vertices in the adjacency lists (`adjvex`) would still refer to the original labels.
     // Since the problem says vertices are labeled 0 to n-1, and we delete a vertex, the remaining vertices keep their labels.
     // So `adjvex` values are correct labels.
     
     // Why then is the output wrong?
     // Let's look at the `Buggy Output` again.
     // `0 `
     // `0 `
     
     // This suggests that for both DFS and BFS, only vertex 0 is visited.
     // This implies G[0].link is NULL or leads to nowhere.
     
     // If G[0].link became NULL, it means `k->next` was NULL when we deleted the head.
     // In our trace, G[0] was `1 -> 2`. `k` was node(1). `k->next` was node(2).
     // So G[0].link became node(2).
     
     // Is it possible that `node(2)` was corrupted?
     
     // Let's look at the `continue` statement in the insertion logic.
     // `if(a<q1->adjvex) { ... continue; }`
     // This `continue` skips the rest of the loop body for the current edge input.
     // But wait, the insertion logic for `p1` (edge a->b added to G[b]) and `p2` (edge b->a added to G[a]) is in the SAME loop iteration.
     // If `continue` is hit after inserting `p1`, `p2` is NEVER inserted.
     // This means the graph is directed! Or rather, only one direction of the edge is added if the insertion into the first list triggers a `continue`.
     
     // Let's trace Input `0 1`.
     // a=0, b=1.
     // Insert p1 (adjvex=0) into G[1].
     // G[1] is NULL. G[1].link=p1.
     // No continue.
     // Insert p2 (adjvex=1) into G[0].
     // G[0] is NULL. G[0].link=p2.
     
     // Input `1 2`.
     // a=1, b=2.
     // Insert p1 (adjvex=1) into G[2].
     // G[2] is NULL. G[2].link=p1.
     // No continue.
     // Insert p2 (adjvex=2) into G[1].
     // G[1] has node(0).
     // q1=node(0). a=1. 1>0.
     // r1=node(0). q1=NULL.
     // r1->next=p2.
     // G[1]: 0->2.
     
     // Input `0 2`.
     // a=0, b=2.
     // Insert p1 (adjvex=0) into G[2].
     // G[2] has node(1).
     // q1=node(1). a=0. 0<1.
     // p1->next=q1 (node 1).
     // G[2].link=p1 (node 0).
     // `continue` is executed.
     // **The insertion of p2 into G[0] is SKIPPED.**
     
     // So G[0] still only has node(1) from the first edge.
     // G[0]: 1.
     // G[2]: 0->1.
     
     // Now, delete 1.
     // j=0. G[0].link is node(1). Delete head. G[0].link = node(1)->next = NULL.
     // So G[0].link is NULL.
     // j=2. G[2].link is node(0). Next is node(1). Delete node(1). G[2].link is node(0).
     
     // DFS(0): Visit 0. Neighbors: NULL. End. Output: "0 ".
     // BFS(0): Visit 0. Neighbors: NULL. End. Output: "0 ".
     
     // This matches the buggy output exactly!
     
     // The error is the `continue` statement in the edge insertion logic.
     // It prevents the second direction of the undirected edge from being added.
     
     // To fix this, we must remove the `continue` statements and ensure both insertions happen.
     // The `continue` was likely an optimization attempt that failed for undirected graphs.
     
     // Lines with `continue`:
     // Line 85: `continue;`
     // Line 106: `continue;`
     
     // We need to remove these `continue` statements.
     // However, the logic below them depends on `q1`/`q2` and `r1`/`r2`.
     // If we remove `continue`, the code falls through to the `while` loop.
     // In the case where `a < q1->adjvex`, we already handled it by setting `G[b].link=p1`.
     // If we fall through, `q1` is still the old head. `r1` is uninitialized?
     // No, `r1` is declared but not initialized before the `if(a<q1->adjvex)` block.
     // If we fall through, `while(q1!=NULL&&a>q1->adjvex)` will run.
     // But we already inserted `p1` at the head.
     // So falling through would try to insert `p1` AGAIN or corrupt the list.
     
     // So we can't just remove `continue`. We need to restructure the insertion to avoid `continue` or ensure both halves run.
     // The easiest fix is to remove the `continue` and use `else` blocks or flags, but the prompt asks to annotate errors.
     // The error is the presence of `continue` which skips the second half of the undirected edge insertion.
     
     // I will mark the `continue` lines as errors.
     
     // Also, the deletion logic has a potential crash if `k` is NULL.
     // Line 137: `if(k->adjvex==del)` -> If k is NULL, this is bad.
     // I will mark this line too.

     // One more thing: The problem requires outputting sequences **before** and **after** deletion.
     // The code does:
     // DFS(0); printf("\n");
     // BFS... printf("\n");
     // Deletion...
     // DFS(0); printf("\n");
     // BFS... printf("\n");
     // This structure is correct.

     // So the primary error is the `continue` statements.
     // Secondary error is the NULL check in deletion.

     // I will annotate the `continue` lines and the NULL check line.