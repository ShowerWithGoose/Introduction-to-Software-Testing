#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define max 10
typedef struct edge{
    int adj;
    int weight;
    struct edge* next;
}Elink;
typedef struct ver{
    int vertex;
    Elink* link;
}Vlink;
int point=0,side=0;
int Visited[max]={0};
int Q[max];
int front=0,rear=max-1,count=0;
Vlink Head[max];

void travelDFS(Vlink G[],int n){
    for(int i=0;i<n;i++) Visited[i]=0;
    for(int i=0;i<n;i++){
        if(!Visited[i]) DFS(G,i);
    }
}
void DFS(Vlink G[],int v){
    Elink* p;
    Visited[v]=1;
    printf("%d ",v);
    for(p = G[v].link; p !=NULL; p=p->next)
    if( !Visited[p->adj] )
        DFS(G, p->adj);
}//深度遍历到此结束


void travelBFS(Vlink G[],int n){
    for(int i=0;i<n;i++) Visited[i]=0;
    BFS(G,0);
}
void BFS(Vlink G[], int v)
{
    Elink *p;
    Visited[v] = 1; //标识某顶点已入队
    enQueue(Q, v);
    while(emptyQ(Q)<0){
        v = deQueue(Q);//取出队头元素
        printf("%d ",v);
        for(p=G[v].link; p!=NULL; p=p->next ) //访问该顶点的每个邻接顶点
            if(Visited[p->adj]==0) {
                Visited[p->adj] = 1; //标识某顶点入队
                enQueue(Q, p->adj);
            }
    }
}
int emptyQ(int Q[]){
    if(count==0) return 1;
    else return -1;
}
void enQueue(int queue[ ],int item){
    rear = (rear+1) % max;
    queue[rear]=item;
    count++;
}
int deQueue(int queue[ ]){
    int e=0;
    e=queue[front];
    count--;
    front = (front+1)% max;
    return e;
}//广度遍历到此结束 


void create_graph(Vlink graph[]){
    int v1,v2;
    for(int i=0;i<side;i++){
        scanf("%d%d",&v1,&v2);
        if(graph[v1].link==NULL){
            Elink* temp_E=NULL;
            temp_E=(Elink*)malloc(sizeof(Elink));
            temp_E->adj=v2;
            temp_E->next=NULL;
            graph[v1].link=temp_E;
        }
        else{
            Elink* temp_E=NULL;
            temp_E=(Elink*)malloc(sizeof(Elink));
            temp_E->adj=v2;
            temp_E->next=NULL;
            if(v2<graph[v1].link->adj){
                temp_E->next=graph[v1].link;
                graph[v1].link=temp_E;
            }
            else{
                Elink* p=NULL,* r=NULL;
                p=graph[v1].link;
                while(p!=NULL&&p->adj<v2){
                    r=p;
                    p=p->next;
                }
                temp_E->next=r->next;
                r->next=temp_E;
            }
        }
        if(graph[v2].link==NULL){
            Elink* temp_E=NULL;
            temp_E=(Elink*)malloc(sizeof(Elink));
            temp_E->adj=v1;
            temp_E->next=NULL;
            graph[v2].link=temp_E;
        }
        else{
            Elink* temp_E=NULL;
            temp_E=(Elink*)malloc(sizeof(Elink));
            temp_E->adj=v1;
            
            if(v1<graph[v2].link->adj){
                temp_E->next=graph[v2].link;
                graph[v2].link=temp_E;
            }
            else{
                Elink* p=NULL,* r=NULL;
                p=graph[v2].link;
                while(p!=NULL&&p->adj<v1){
                    r=p;
                    p=p->next;
                }
                temp_E->next=r->next;
                r->next=temp_E;
            }
        }
    }
}
int main()
{
    scanf("%d%d",&point,&side);
    create_graph(Head);
    for(int i=0;i<point;i++) Visited[i]=0;
    travelDFS(Head,point);
    printf("\n");
    for(int i=0;i<point;i++) Visited[i]=0;
    travelBFS(Head,point);
    printf("\n");
    
    int aim=0;
    scanf("%d",&aim);
    for(int i=0;i<point;i++) Visited[i]=0;
    Visited[aim]=1;
    DFS(Head,0); // @@ [The DFS function assumes traversal starts from unvisited nodes in order, but after marking 'aim' as visited, it directly calls DFS(Head,0). However, the problem requires that before deletion, traversals start from 0 and visit neighbors in ascending order. After deletion, the same applies, but the graph structure should exclude the deleted vertex. However, the current implementation does not actually remove the vertex from the adjacency lists—it only marks it as visited. This causes incorrect traversal because edges to the deleted vertex are still present and may affect neighbor ordering or cause invalid accesses. Additionally, the DFS call here should be part of a full traversal starting at 0, but since other nodes might be unvisited and disconnected (though problem states graph remains connected), this direct call may miss nodes if 0 is connected only through the deleted node—but problem says graph remains connected after deletion, so starting at 0 is valid. However, the bigger issue is that the graph structure itself isn't modified to remove the vertex, so during traversal, when visiting neighbors, the deleted vertex might still appear in adjacency lists, but since it's marked visited, it's skipped. But the ordering of neighbors must be in ascending order excluding the deleted vertex. However, because the adjacency list still contains the deleted vertex, when iterating through neighbors, the presence of the deleted vertex (even if skipped) doesn't affect order, but the insertion logic during graph creation may have inserted edges including the deleted vertex, which is okay as long as we skip it during traversal. However, the real error is that the BFS and DFS after deletion are not using a proper traversal wrapper like travelDFS/travelBFS—they directly call DFS(Head,0) and BFS(Head,0), which is acceptable only if the graph is connected and starts at 0, which it is per problem statement. So this line is not the main error.]

    printf("\n");
    for(int i=0;i<point;i++) Visited[i]=0;
    Visited[aim]=1;
    BFS(Head,0); // @@ [Same issue as above: the graph structure hasn't been modified to remove the vertex 'aim', so during BFS, when exploring neighbors of a node, the adjacency list may include 'aim', but since Visited[aim] is set to 1, it will be skipped. However, the problem requires that the vertex is deleted from the graph, meaning edges incident to it should be removed. The current approach only simulates deletion via visited array, which is acceptable if done correctly. However, the BFS implementation uses a global queue and relies on the emptyQ function. But note: the BFS function calls enQueue and deQueue which use a fixed-size queue of size 'max=10'. However, the number of vertices can be up to 100, so the queue size is insufficient, leading to buffer overflow or incorrect behavior. This is a critical error.]

    return 0;
}
// @@ [Multiple errors exist:
// 1. The macro 'max' is defined as 10, but the problem states n can be up to 100. This causes the Visited array, Q queue, and related structures to be too small, leading to out-of-bounds access.
// 2. In the BFS function, the condition 'while(emptyQ(Q)<0)' is incorrect. The emptyQ function returns 1 when empty and -1 when not empty. So the loop runs while not empty, which is correct logically, but the naming is confusing. However, the real issue is the queue size.
// 3. The graph representation includes a 'weight' field in Elink which is unused, but that's not an error.
// 4. Most critically, the queue 'Q' is of size 'max=10', but up to 100 vertices may be enqueued, causing buffer overflow.
// 5. Additionally, in the 'create_graph' function, when inserting edges in sorted order, there's a potential null pointer dereference: in the 'else' block, after the while loop, 'r' might be NULL if the first element is >= v2, but the code assumes 'r' is valid when doing 'r->next'. For example, if graph[v1].link->adj > v2, the first condition handles it, but in the else branch, the while loop condition is 'p!=NULL && p->adj < v2'. If the first node's adj is already >= v2, the loop doesn't run, so 'r' remains NULL (since initialized to NULL), and then 'r->next' is accessed, causing a segmentation fault.
// Specifically, in create_graph, for the first insertion into a non-empty list where v2 is between the first and second element, 'r' is set correctly, but if v2 is less than the first element, it's handled by the 'if' clause. However, if the list has one element and v2 is greater than that element, the while loop runs once: p starts at head, p->adj < v2 is true, so r=p, then p=p->next becomes NULL, loop exits. Then r is not NULL, so r->next is valid. But if the list has one element and v2 is less than that element, it's caught by the 'if(v2 < graph[v1].link->adj)' clause. The problem arises when the list has multiple elements and v2 is to be inserted at the beginning? No, because the 'if' clause catches when v2 is less than the first. The real bug is when the list is non-empty and v2 is greater than all existing elements: the while loop runs until p becomes NULL, and r points to the last element, so r->next is NULL, and assigning temp_E->next = r->next (which is NULL) is fine. However, what if the list is non-empty and v2 is to be inserted right after the first element? Then r would be the first element, and it works. But consider: if the list has elements [5, 7], and we insert 3: caught by 'if(v2 < graph[v1].link->adj)' -> 3<5, so inserted at front: correct. Insert 6: v2=6, not less than 5, so enter else. p=5, r=NULL initially. while: p!=NULL and 5<6 -> true, so r=p (r=5), p=p->next=7. Now p=7, 7<6 false, loop exits. Then temp_E->next = r->next = 7, and r->next = temp_E: so list becomes [5,6,7]: correct. Insert 8: p=5, r=NULL; 5<8 -> r=5, p=7; 7<8 -> r=7, p=NULL; exit. temp_E->next = r->next = NULL, r->next=temp_E: [5,7,8]: correct. Now insert 4: 4<5 -> handled by if clause: correct. What about inserting into a list with one element [5], inserting 6: else branch, p=5, r=NULL; while: 5<6 -> r=5, p=NULL; then temp_E->next = r->next = NULL, r->next=temp_E: [5,6]: correct. So the insertion logic seems okay. But wait: in the else block, 'r' is initialized to NULL, and if the while loop never runs (i.e., the first element is >= v2), then r remains NULL. But that case should have been caught by the 'if(v2 < graph[v1].link->adj)' clause. So if we are in the else block, it means v2 >= graph[v1].link->adj. Therefore, the while loop will run at least once? Not necessarily: if v2 == graph[v1].link->adj, then p->adj < v2 is false, so loop doesn't run, r remains NULL. Then accessing r->next is invalid. Also, duplicate edges are not supposed to occur per problem, but if v2 equals an existing adj, it shouldn't be inserted, but the code doesn't check for duplicates. However, the problem says edges won't be repeated, so v2 won't equal an existing adj. But what if v2 is greater than the first element but less than the second? Then the loop runs once, r becomes first element, and it works. The only problematic case is when the list has one element and v2 is greater than it: then loop runs once, r becomes that element, and it works. So maybe the insertion is okay. However, the main errors are:
// - Queue size too small (max=10 for up to 100 vertices)
// - The BFS and DFS after deletion do not use the same traversal framework as before (they call DFS/BFS directly instead of travelDFS/travelBFS), but since the graph is connected and starts at 0, it's acceptable. However, the problem requires that after deletion, the traversal starts at 0 and visits in ascending order, which the direct call does, so that's not an error.
// But the compilation error mentioned in the problem is "gcc: not found", which is a system error, not a code error. However, the user says "Error type: Compilation Error", but the provided buggy output is "/bin/sh: 1: gcc: not found", which means the compiler isn't installed. But the task is to find errors in the program that would cause incorrect output, not compilation issues due to environment. However, the reference program has a typo: "struct egde" instead of "struct edge", which would cause a compilation error. But the source code provided for annotation is different.

// Looking at the source code to annotate: it defines max=10, but n can be up to 100. So arrays Visited, Q are too small. This will cause undefined behavior (buffer overflow) during BFS/DFS when n>10.

// Also, in the BFS function, the queue operations use modulo max, but max=10, so for n>10, the queue overflows.

// Additionally, in main(), after reading 'aim', the code does:
//   Visited[aim]=1;
//   DFS(Head,0);
// But DFS expects that the visited array is properly initialized. However, it sets Visited[aim]=1 and leaves others 0, which is correct for simulating deletion. But the DFS function prints the vertex and then recurses. Since the graph is connected without 'aim', starting at 0 is fine.

// However, the critical error is the fixed small size of 'max'. The problem states n up to 100, so max should be at least 105.

// Another error: in the BFS function, the condition is 'while(emptyQ(Q)<0)'. The emptyQ function returns 1 if empty, -1 if not. So when not empty, it returns -1, and -1<0 is true, so loop continues: correct. But the queue implementation is circular with size max=10, which is too small.

// Also, in the create_graph function, when inserting the second edge direction (for v2), the code has:
//   temp_E->adj=v1;
//   ... 
//   if(v1<graph[v2].link->adj){ ... }
// But what if graph[v2].link is NULL? It's checked above: the first if checks if graph[v2].link==NULL, so in the else branch, graph[v2].link is not NULL, so accessing graph[v2].link->adj is safe.

// However, there's a bug in the insertion logic for the else branch of the second part (for v2): it's missing setting temp_E->next=NULL in the else branch? No, it's set before the if-else.

// The main errors are:
// 1. #define max 10 is too small; should be at least 105.
// 2. In the BFS queue, the size is max=10, leading to overflow.
// 3. Additionally, in the main function, after deletion, the code calls DFS(Head,0) and BFS(Head,0) directly, but the DFS function does not reset the visited array for other components—but the problem states the graph is connected after deletion, so it's okay. However, the visited array is manually set before each call, so it's correct.

// But the most immediate error that would cause runtime failure (not compilation) is the small array sizes.

// However, the problem says "Error type: Compilation Error", but the provided source code would compile if max were large enough. With max=10, it compiles but fails at runtime for n>10.

// Given the instructions, we need to mark lines with errors.

// Line with #define max 10: this causes all subsequent arrays to be too small.
// The Visited array declaration: int Visited[max]={0}; -> too small.
// The Q array: int Q[max]; -> too small.
// The queue operations in enQueue/deQueue use max, so they are affected.

// Also, in main, the calls to DFS and BFS after deletion are correct per problem constraints, so not errors.

// Another error: in the BFS function, the initial call enQueue(Q, v) enqueues the vertex v, but then in the loop, it dequeues and prints. However, the visited array is set before enqueuing, which is correct.

// But the critical issue is the small max.

// Additionally, in the create_graph function, when inserting in the else block, the variable 'r' might be used uninitialized if the while loop doesn't run. As reasoned earlier, if we are in the else block, v2 >= first element. If v2 equals the first element, the while loop condition p->adj < v2 is false (since equal), so loop doesn't run, r remains NULL, and then r->next is accessed -> segmentation fault.

// Example: suppose we have an edge (0,1), then later add (0,1) again—but problem says no repeated edges. But what if we add (0,2) then (0,1)? 
// First edge (0,2): graph[0].link = [2]
// Second edge (0,1): 
//   v1=0, v2=1
//   graph[0].link is not NULL, and 1 < 2 -> true, so it goes into the if clause: inserts at front: [1,2] -> correct.
// Now add (0,2) again? Not allowed.
// Now add (0,3): 
//   v2=3, not < 2, so else branch.
//   p=graph[0].link=1, r=NULL
//   while: p!=NULL and 1<3 -> true, so r=1, p=2
//   then 2<3 -> true, r=2, p=NULL
//   then temp_E->next = r->next = NULL, r->next=temp_E: [1,2,3] -> correct.
// Now add (0,2) — not allowed.
// Now consider adding an edge that results in duplicate adj value? Not possible per input.

// But what if we have to insert a value that is equal to an existing one? The problem says no repeated edges, so it won't happen.

// However, there's another scenario: when the list has [2,3] and we insert 1: caught by if (1<2) -> insert at front.
// Insert 4: else branch, loop runs, r ends at 3, insert after.
// Insert 2.5? Not integer.

// So the insertion logic might be safe.

// But consider: list is [3], insert 2: 2<3 -> if clause, insert at front: [2,3].
// Insert 4: else, p=2, 2<4 -> r=2, p=3; 3<4 -> r=3, p=NULL; insert after 3: [2,3,4].
// Insert 1: if clause: [1,2,3,4].
// Insert 5: else, works.

// Now, what if we insert a value that is greater than the first but the list has only one element: [5], insert 6: else branch, p=5, r=NULL; while: 5<6 -> r=5, p=NULL; then r->next = temp_E, which is fine.

// The only potential issue is if the list is [5,7] and we insert 6: 
//   p=5, r=NULL; 5<6 -> r=5, p=7; 7<6 false -> exit.
//   temp_E->next = r->next = 7, r->next=temp_E: [5,6,7] -> correct.

// So insertion seems correct.

// Therefore, the main errors are:
// - #define max 10 is too small for the problem constraints (n up to 100).
// - This causes the Visited array and Q queue to be too small, leading to buffer overflows.

// We should mark the #define line and the array declarations.

// However, the instruction says: "If you think an error may occur on a particular line, add @@ symbol directly after that line"

// So:

// Line: #define max 10
// This line causes max to be 10, but n can be up to 100, so arrays of size max are too small.

// Line: int Visited[max]={0};
// Array too small.

// Line: int Q[max];
// Array too small.

// Also, in the BFS function, the queue operations assume max size, but it's too small.

// Additionally, in main, the calls after deletion are correct, so no error there.

// But note: the problem says the vertex to be deleted is not 0, and graph is connected after deletion, so starting at 0 is fine.

// Another error: in the BFS function, the initial enQueue is done, but the printing happens when dequeuing. However, the visited is set before enqueuing, which is standard.

// However, there's a more subtle error: in the main function, for the after-deletion traversals, the code does:
//   Visited[aim]=1;
//   DFS(Head,0);
// But the DFS function uses the global Visited array, which has Visited[aim]=1 and others 0. This is correct for simulating deletion.

// Similarly for BFS.

// So the only errors are the small array sizes.

// Let's mark the lines: