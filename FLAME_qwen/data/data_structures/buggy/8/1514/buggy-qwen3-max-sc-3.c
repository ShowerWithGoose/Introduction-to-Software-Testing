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
    DFS(Head,0); // @@ [The DFS function is called directly on vertex 0 without ensuring all unvisited components are traversed. However, since the graph is connected and vertex 0 is not deleted, this is acceptable. But more critically, the 'weight' field in Elink is unused and may cause memory/layout issues, though not a compilation error. The real issue is that the queue size 'max=10' is too small for graphs up to 100 vertices, causing buffer overflow in BFS after deletion. Also, the BFS implementation uses a global queue with fixed size 'max=10', which is insufficient when point can be up to 100. This leads to undefined behavior, but the immediate compilation error is not present. However, the test case shows "gcc: not found", which is environment-related. But given the problem context, the logical errors are: (1) queue size too small, (2) missing initialization of Head[].vertex, (3) inconsistent traversal logic before/after deletion. Yet the prompt says "Compilation Error", but the provided code compiles. Re-examining: the original reference program had a typo "struct egde" which causes compilation error, but this code doesn't have that. However, in this submitted code, the BFS after deletion calls BFS(Head,0) which uses global queue variables that are not reset properly (front, rear, count are global and not reinitialized before second BFS). But the most critical issue causing incorrect output is that the queue size 'max=10' is less than the maximum possible vertices (100), leading to buffer overflow. However, the problem states the error type is "Compilation Error", but this code actually compiles. Given the discrepancy, the likely intended error is the insufficient queue size and improper handling of graph deletion. But per instructions, we mark lines with potential errors. The main logical flaw is using a fixed-size queue of 10 for up to 100 vertices. Also, in create_graph, when inserting edges, if the list is non-empty and the new node is larger than all, the insertion logic may dereference NULL (e.g., if r remains NULL). Specifically, in the 'else' block of edge insertion, if the while loop condition fails immediately (p->adj >= v2), then r is still NULL, and r->next is invalid.]
    printf("\n");
    for(int i=0;i<point;i++) Visited[i]=0;
    Visited[aim]=1;
    BFS(Head,0); // @@ [Same issue: global queue variables (front, rear, count) are not reset before this BFS call. The previous BFS left them in an arbitrary state. Also, the queue size 'max=10' is too small for graphs with more than 10 vertices, causing buffer overflow. Additionally, the BFS function assumes the graph is connected and starts at 0, which is correct per problem, but the queue implementation is flawed due to fixed small size and lack of reinitialization.]
    return 0;
}