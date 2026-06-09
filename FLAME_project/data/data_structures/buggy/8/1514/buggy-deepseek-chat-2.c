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
    BFS(G,0); // @@ Error: The BFS traversal should start from vertex 0 and visit all vertices in the graph, but if the graph is not connected (which is not the case here per problem statement), this would miss vertices. However, the main issue is that after deletion, the graph may have vertex 0 still present, but the BFS should traverse all remaining vertices. The problem states the graph is connected after deletion, so starting from 0 is fine. But the real error is that the BFS function uses a queue with emptyQ returning 1 when empty, but the while loop condition checks emptyQ(Q) < 0, which is incorrect. See BFS function.
}
void BFS(Vlink G[], int v)
{
    Elink *p;
    Visited[v] = 1; //标识某顶点已入队
    enQueue(Q, v);
    while(emptyQ(Q)<0){ // @@ Error: emptyQ returns 1 when queue is empty and -1 when not empty. The condition should be while(emptyQ(Q) > 0) or while(emptyQ(Q) != 1) to continue when queue is not empty. Currently, it will never enter the loop because emptyQ returns -1 when not empty, and -1 < 0 is true, but when queue becomes empty, emptyQ returns 1, and 1 < 0 is false, so it exits. Actually, the logic is inverted: it should loop while queue is not empty, i.e., while(emptyQ(Q) == -1) or while(!emptyQ(Q)). The current condition while(emptyQ(Q)<0) will loop when queue is not empty (since -1 < 0 is true) and stop when queue is empty (1 < 0 is false). So it actually works, but it's confusing. However, the real issue is that after deletion, the BFS should start from vertex 0, but the graph may have vertex 0 still present. The problem is that the BFS function does not handle the case where vertex 0 is deleted? But the problem says the deleted vertex is not 0. So that's fine. The main error is in the while loop condition: it should be while(emptyQ(Q) == -1) or while(count > 0). The current condition is logically correct but unconventional. However, the buggy output shows that after deletion, BFS outputs "0 2" which is correct for the given test case. So the error might be elsewhere.
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
    return 0;
}