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
    while(emptyQ(Q)!=1){ // @@ The condition `emptyQ(Q)<0` is incorrect. `emptyQ` returns 1 if empty and -1 if not empty. The loop should continue while the queue is NOT empty (i.e., return value is -1). So the condition should be `!= 1` or `== -1`. With `<0`, it works for non-empty, but let's check logic. If empty, returns 1. 1 < 0 is false. Loop stops. If not empty, returns -1. -1 < 0 is true. Loop continues. Actually, the logic `while(emptyQ(Q)<0)` seems technically correct for continuing when not empty. However, looking at the output format, there is a trailing space issue or newline issue? No, the main issue is likely how the deletion is handled. Let's look further. Wait, the problem says "output the vertex sequences... after deleting". The current code simulates deletion by marking `Visited[aim]=1` before traversal. This prevents visiting the node. However, BFS/DFS still traverse through edges connected to it if not careful? No, if `Visited[aim]` is 1, it won't be pushed/visited. But does it skip the neighbor check correctly? In DFS: `if( !Visited[p->adj] ) DFS...`. If `p->adj` is the deleted node, `Visited` is 1, so it skips. This seems okay for simulation. 
    // Let's re-read the BFS loop condition. `while(emptyQ(Q)<0)`. If queue is empty, `emptyQ` returns 1. 1 < 0 is false. Loop terminates. If queue has items, `emptyQ` returns -1. -1 < 0 is true. Loop continues. This logic is actually correct for "while not empty".
    // Let's look at the output difference.
    // Buggy Output:
    // 0 1 2 
    // 0 1 2 
    // 0 2 
    // 0 2 
    // Expected Output:
    // 0 1 2
    // 0 1 2
    // 0 2
    // 0 2
    // The only difference is the trailing space. The problem usually tolerates trailing spaces unless strictly checked. But wait, "Wrong Answer" suggests logical error or strict formatting.
    // Let's look at `create_graph`. It inserts edges in sorted order.
    // Let's look at `main`.
    // It calls `travelDFS`, prints newline.
    // Calls `travelBFS`, prints newline.
    // Then reads `aim`.
    // Then manually simulates deletion by setting `Visited[aim]=1` and calling `DFS(Head, 0)`.
    // Then prints newline.
    // Then resets Visited, sets `Visited[aim]=1`, calls `BFS(Head, 0)`.
    // It does NOT print a newline after the last BFS!
    // The expected output has 4 lines. The buggy output shows 4 lines in the description, but the code misses the final `printf("\n");` after the last BFS call.
    // Also, the `travelBFS` function calls `BFS(G,0)`. The manual calls also call `BFS(Head,0)`.
    // The missing newline at the end of the program is a very common cause for WA in strict judges.
    
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
    DFS(Head,0);
    printf("\n");
    for(int i=0;i<point;i++) Visited[i]=0;
    Visited[aim]=1;
    BFS(Head,0);
    printf("\n"); // @@ Missing newline after the last BFS output. The expected output format implies 4 lines of output. Without this, the last line may not be properly terminated or matched against expected output which usually expects a newline at the end of each line.
    return 0;
}