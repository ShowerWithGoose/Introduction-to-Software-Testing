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
    while(emptyQ(Q)<0){ // @@ The condition `emptyQ(Q)<0` is incorrect. `emptyQ` returns -1 when the queue is NOT empty (count > 0). The loop should continue while the queue is not empty. However, the standard convention is usually `while(!isEmpty())`. Here `emptyQ` returns -1 for non-empty. So `while(emptyQ(Q) != 1)` or `while(count > 0)` would be correct. But wait, if `emptyQ` returns 1 for empty and -1 for non-empty, `while(emptyQ(Q) < 0)` means "while not empty". This logic seems actually correct for continuing the loop. Let's re-read `emptyQ`. `if(count==0) return 1; else return -1;`. So if count > 0, it returns -1. `-1 < 0` is true. So the loop runs while queue is not empty. This part is logically okay for continuation. 
        // However, let's look at the output format. The problem expects no trailing space? Or just sequence?
        // The main issue is likely in how the deletion is handled or the traversal start.
        // Let's look at `main`.
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
    Visited[aim]=1; // @@ This approach to "deleting" a vertex by marking it visited before starting DFS/BFS from 0 is partially correct for preventing traversal INTO the node, but it doesn't remove the node from the adjacency lists. If the deleted node is in the middle of an adjacency list, the traversal might still try to access it if not careful, but since we mark it visited, we won't recurse/enqueue it. HOWEVER, the problem asks to output the sequence AFTER deleting the vertex. The reference implementation physically removes edges. This simulation by marking visited works for connectivity IF the graph remains connected. But there is a subtle bug: if the deleted node is adjacent to 0, it won't be printed. That's correct. But does it affect the order? No, because we skip it. 
    // The real issue might be simpler. Look at the expected output vs buggy output.
    // Buggy: `0 2 ` (with trailing space likely, or just `0 2`)
    // Expected: `0 2`
    // The provided code prints `%d ` always. Trailing spaces are usually ignored in online judges unless strictly checked.
    // Let's look closer at `travelBFS`. It calls `BFS(G, 0)`.
    // Let's look closer at `travelDFS`. It iterates `i` from 0 to n.
    // In the second part (after deletion), `main` manually resets visited, marks `aim` as visited, then calls `DFS(Head, 0)` and `BFS(Head, 0)`.
    // This effectively skips `aim`.
    // Is there an error in `create_graph`?
    // In `create_graph`, when inserting into a sorted list:
    // `while(p!=NULL&&p->adj<v2)` ... `temp_E->next=r->next; r->next=temp_E;`
    // If `p` becomes NULL, `r` is the last node. `r->next` is NULL. `temp_E->next` becomes NULL. `r->next` becomes `temp_E`. This is correct for appending.
    // If `p` stops because `p->adj >= v2`, then `r` is the node before `p`. `temp_E` is inserted between `r` and `p`. Correct.
    // What if `v2` is smaller than head? Handled by `if(v2<graph[v1].link->adj)`. Correct.
    
    // Let's re-evaluate the BFS loop condition.
    // `while(emptyQ(Q)<0)`
    // `emptyQ` returns -1 if count != 0.
    // So while count != 0, loop runs. This is correct.
    
    // Let's look at the output again.
    // Input:
    // 3 3
    // 0 1
    // 1 2
    // 0 2
    // 1
    
    // Graph:
    // 0: 1 -> 2
    // 1: 0 -> 2
    // 2: 0 -> 1
    
    // DFS Before: Start 0. Visit 0. Neighbors 1, 2.
    // Go to 1. Visit 1. Neighbors 0 (visited), 2.
    // Go to 2. Visit 2. Neighbors 0 (visited), 1 (visited).
    // Back to 1. Back to 0.
    // Output: 0 1 2. Correct.
    
    // BFS Before: Start 0. Queue: 0.
    // Deq 0. Print 0. Enq 1, 2. Queue: 1, 2.
    // Deq 1. Print 1. Neighbors 0 (vis), 2 (vis? No, 2 is in queue but marked visited when enqueued).
    // In `BFS`: `Visited[p->adj] = 1` happens BEFORE enqueue.
    // So when processing 0:
    // Neighbor 1: Visited[1]=0. Mark Visited[1]=1. Enqueue 1.
    // Neighbor 2: Visited[2]=0. Mark Visited[2]=1. Enqueue 2.
    // Deq 1. Print 1. Neighbors 0 (Vis), 2 (Vis). Skip.
    // Deq 2. Print 2. Neighbors 0 (Vis), 1 (Vis). Skip.
    // Output: 0 1 2. Correct.
    
    // After Delete 1:
    // Mark Visited[1]=1.
    // DFS Start 0.
    // Visit 0. Print 0.
    // Neighbors of 0: 1, 2.
    // Check 1: Visited[1] is 1. Skip.
    // Check 2: Visited[2] is 0. Recurse DFS(2).
    // Visit 2. Print 2.
    // Neighbors of 2: 0, 1.
    // Check 0: Visited. Skip.
    // Check 1: Visited. Skip.
    // Output: 0 2. Correct.
    
    // BFS Start 0.
    // Visited[0]=1. Enqueue 0.
    // Deq 0. Print 0.
    // Neighbors of 0: 1, 2.
    // Check 1: Visited[1] is 1. Skip.
    // Check 2: Visited[2] is 0. Mark Visited[2]=1. Enqueue 2.
    // Deq 2. Print 2.
    // Neighbors of 2: 0, 1.
    // Check 0: Visited. Skip.
    // Check 1: Visited. Skip.
    // Output: 0 2. Correct.
    
    // So why "Wrong Answer"?
    // Look closely at the `Buggy Output` provided in the prompt:
    // `0 1 2 `
    // `0 1 2 `
    // `0 2 `
    // `0 2 `
    // Note the trailing spaces.
    // And `Expected Output`:
    // `0 1 2`
    // `0 1 2`
    // `0 2`
    // `0 2`
    
    // Often, trailing spaces are acceptable. If it's WA, it might be something else.
    // Wait, look at `create_graph` logic again.
    // `if(graph[v1].link==NULL)` ... `else` ...
    // In the `else` block for insertion:
    // `while(p!=NULL&&p->adj<v2)`
    // If the list is `1 -> 3` and we insert `2`.
    // `p` starts at 1. `1 < 2`. `r=1`, `p=3`.
    // `3 < 2` is false. Loop ends.
    // `temp_E->next = r->next` (which is 3).
    // `r->next = temp_E` (1 -> 2 -> 3). Correct.
    
    // What if we insert `4` into `1 -> 3`.
    // `p=1`. `1<4`. `r=1`, `p=3`.
    // `3<4`. `r=3`, `p=NULL`.
    // Loop ends.
    // `temp_E->next = r->next` (NULL).
    // `r->next = temp_E`. Correct.
    
    // Is it possible `r` is NULL?
    // Only if the loop doesn't run?
    // If `v2 < head->adj`, it's caught by the `if` before.
    // So `r` will always be initialized because `p` starts at head, and if `head->adj < v2`, we enter loop, `r` becomes head.
    
    // Let's check the BFS/DFS function signatures and calls.
    // `travelBFS` calls `BFS(G, 0)`.
    // `BFS` uses global `Q`, `front`, `rear`, `count`.
    // Are these reset?
    // `front=0, rear=max-1, count=0` are initialized globally.
    // In `main`, before the first BFS, they are 0, 9, 0.
    // After first BFS, `count` is 0, `front` and `rear` have moved.
    // Before second BFS (after deletion), `main` does NOT reset `front`, `rear`, `count`.
    // `for(int i=0;i<point;i++) Visited[i]=0;`
    // `Visited[aim]=1;`
    // `BFS(Head,0);`
    
    // Inside `BFS`:
    // `enQueue` uses `rear` and `count`.
    // `deQueue` uses `front` and `count`.
    // If `front` and `rear` are not reset to initial values (0 and max-1), the circular queue indices will be wrong for the new traversal!
    // The queue state persists from the previous BFS.
    // This is the bug.
    
    DFS(Head,0);
    printf("\n");
    for(int i=0;i<point;i++) Visited[i]=0;
    Visited[aim]=1;
    BFS(Head,0);
    return 0;
}