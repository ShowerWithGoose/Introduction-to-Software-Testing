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
    DFS(Head,0); // @@ [The DFS function assumes traversal starts from unvisited nodes in order, but after marking 'aim' as visited, it directly calls DFS(Head,0). However, the problem requires that before deletion, traversals start from 0 and visit neighbors in ascending order. After deletion, the same applies but with the vertex removed. The current approach for "after deletion" only does a single DFS from 0, which is correct per problem, BUT the bigger issue is that the graph structure itself is not modified to remove the vertex 'aim'. The program only marks 'aim' as visited, which prevents visiting it, but its adjacent edges are still present in the adjacency lists of other vertices. This causes the traversal to potentially consider edges to 'aim', even though it's supposed to be deleted. However, since 'aim' is marked visited, it won't be recursed into, so this might work. But the real critical error is below.]

    printf("\n");
    for(int i=0;i<point;i++) Visited[i]=0;
    Visited[aim]=1;
    BFS(Head,0); // @@ [Same issue as above: the graph structure isn't actually modified to remove the vertex 'aim'. However, the more immediate error causing incorrect output is that the BFS and DFS after deletion should only traverse the graph excluding the deleted vertex and its incident edges. By only marking 'aim' as visited, when traversing from 0, if 0 is connected to 'aim', the adjacency list of 0 still contains 'aim', but since 'aim' is marked visited, it's skipped. So logically, this might produce correct output. However, the actual compilation error comes from the fact that the array size 'max' is defined as 10, but the problem states that the number of vertices can be up to 100. Thus, arrays like Visited[max], Q[max], and Head[max] are too small, leading to buffer overflows or undefined behavior. But the user mentioned "Compilation Error" and the test output shows "/bin/sh: 1: gcc: not found", which is a system error, not a code error. However, looking at the code, there's another critical issue:]

    return 0;
}
// @@ [The primary logical error is that the graph is never actually modified to remove the specified vertex. The problem says "after deleting the specified vertex", which means removing the vertex and all its incident edges. The current approach only marks the vertex as visited, which prevents it from being processed, but the adjacency lists of other vertices still contain references to the deleted vertex. While this may coincidentally produce correct traversal sequences (because the deleted vertex is marked visited and thus skipped), it is not a correct implementation of vertex deletion. However, the more pressing issue that likely causes runtime errors (though not compilation errors) is that the constant 'max' is set to 10, but the problem allows up to 100 vertices. This will cause array overflows when n > 10. But the user reported a "Compilation Error", and the given test output indicates the compiler wasn't found, which is external. However, looking closely at the code, there's a deeper issue:]

// @@ [In the BFS function, the condition in the while loop is 'while(emptyQ(Q)<0)'. The function emptyQ returns 1 when the queue is empty and -1 when not. So the loop runs when the queue is NOT empty, which is correct. But the real critical error that would cause incorrect output (not compilation) is the fixed-size array with max=10. However, the problem states n is between 3 and 100, so max=10 is insufficient. This is a semantic/logical error that would cause runtime issues, but not compilation errors.]

// @@ [But wait: the user provided two programs. The first one (reference) has a typo: 'struct egde' instead of 'struct edge', which would cause a compilation error. However, the second program (the buggy one we're annotating) doesn't have that typo. The actual issue in this provided buggy code is that the array size 'max' is only 10, but the problem allows up to 100 vertices. This will lead to buffer overflows. However, the user says the error type is "Compilation Error", but this code would compile fine; it would just crash at runtime for n>10. Given the test case input isn't provided, but the expected behavior is clear, the main error is the insufficient array size.]

// However, re-examining the problem: the user says "Error type: Compilation Error" and the buggy output is "/bin/sh: 1: gcc: not found", which is not a code error but a system configuration issue. But since we must find errors in the code, the only plausible compilation-related issue in the code itself is if there were syntax errors. This code appears syntactically correct. But note: the problem says the reference program correctly implemented, and then provides a different program as the "Source Code" to debug. 

// Looking again at the provided source code to debug: 
// The constant 'max' is 10, but the problem requires handling up to 100 vertices. This is a critical flaw, but it's a runtime error, not compilation.
// However, there's another issue: in the 'create_graph' function, when inserting edges in sorted order, in the 'else' block for the second insertion (for v2), the code does:
//   temp_E->next=r->next;
//   r->next=temp_E;
// But what if 'r' is NULL? This happens when the while loop condition fails immediately, i.e., when graph[v2].link->adj >= v1, but the first condition (v1 < graph[v2].link->adj) was false, so we are in the else block meaning v1 >= graph[v2].link->adj. Then the while loop: p=graph[v2].link; while(p!=NULL && p->adj < v1) ... If graph[v2].link->adj == v1, the loop doesn't run, so r remains NULL (since r is initialized to NULL and the loop body never executes). Then r->next is dereferencing a null pointer, causing a segmentation fault at runtime.

// Specifically, in the 'create_graph' function, for the v2 part:
//     else{
//         Elink* p=NULL,* r=NULL;
//         p=graph[v2].link;
//         while(p!=NULL&&p->adj<v1){
//             r=p;
//             p=p->next;
//         }
//         temp_E->next=r->next;  // @@ [If no node with adj < v1 is found, r remains NULL, so r->next is invalid. This happens when v1 is less than or equal to the first node's adj, but we already handled v1 < first node's adj above, so this else block is for v1 >= first node's adj. If v1 equals the first node's adj, the while loop doesn't run, r is NULL, and this line crashes. Also, if v1 is greater than all, then r would be the last node, which is fine. But if v1 is equal to an existing node, we shouldn't insert a duplicate, but the problem says edges are not repeated, so v1 won't equal an existing adj in the list? Actually, the graph is simple, so no duplicate edges, but the adjacency list for a vertex should not have duplicates. However, the insertion logic is flawed because when v1 is greater than the first element but less than some later element, r is set correctly. But when v1 is greater than all elements, the while loop exits with p=NULL and r=last node, which is correct. The problem is when v1 is equal to an existing adj? But the input doesn't have duplicate edges, so this shouldn't happen. However, the real issue is when the list has one element and v1 is greater than that element: then the while loop runs once? Let's see: p points to the first (and only) node, p->adj < v1 is true, so r=p, then p=p->next becomes NULL, loop exits. Then r is not NULL, so r->next is NULL, and we set temp_E->next = NULL, and r->next = temp_E. That's correct. 

// The actual crash scenario is when the list has multiple nodes, and v1 is less than the second node but greater than the first. Then r becomes the first node, and we insert after r. Correct.

// But what if v1 is less than the first node? That's handled by the 'if' condition above: if(v1<graph[v2].link->adj). So the 'else' block is only entered when v1 >= graph[v2].link->adj. Now, if v1 equals graph[v2].link->adj, the while loop condition p->adj < v1 is false (since equal), so the loop doesn't run, r remains NULL. Then r->next is accessed -> crash.

// However, the problem states: "edges will not be repeated", so we should never have an edge that results in duplicate adj values in the adjacency list. Therefore, v1 should not equal any existing adj in the list for v2. So this situation should not occur. Thus, this might not be the error.

// Given the confusion, the most definite error is the array size 'max' being 10, which is too small for the problem constraints (n up to 100). This will cause buffer overflows. But again, this is a runtime error.

// However, the user insists on "Compilation Error", and the only possible compilation error in this code is if the compiler is missing, but that's not the code's fault. Since we must annotate the code, and the problem says "identify the location of the errors", and given the constraints, the array size is a critical error.

// But note: the problem says the reference program is correct, and the reference program uses graph[105], visited[105], etc. So the buggy program should use at least 105.

// Therefore, the error is that 'max' is defined as 10, but it should be at least 105.

// However, the instruction says: "If you think an error may occur on a particular line, add @@ symbol directly after that line"

// So we should annotate the #define line.

// Also, in main, when doing the after-deletion traversals, the code does:
//   Visited[aim]=1;
//   DFS(Head,0);
// This is okay because DFS starts at 0 and skips aim. But what if 0 is the aim? The problem states: "The vertex to be deleted is not vertex 0." So it's safe.

// Another issue: in the BFS after deletion, it calls BFS(Head,0), which is correct.

// But the real showstopper is the small array size.

// Let's annotate the #define line.

// Also, note that the queue implementation uses a global queue Q of size 'max', and with max=10, for n>10, BFS will overflow the queue.

// So: