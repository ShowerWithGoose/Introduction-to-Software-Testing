#include <stdio.h>
#include <stdlib.h>
#define MaxV    256
typedef struct edge{
    int  adj;
    int  wei;
    struct edge  *next;
}ELink;
typedef struct ver{
    ELink  *link;
}Vlink;
ELink  *insertEdge(ELink *head, int avex)
{
    ELink *e,*p;
    e =(ELink *)malloc(sizeof(ELink));
    e->adj= avex; e->wei=1; e->next = NULL;
    if(head == NULL){
        head=e;
        return head;
    }
    if(e->adj<head->adj){
        e->next=head;
        return e;
    }
    for(p=head; p->next != NULL; p=p->next){
        if((p->next->adj)>(e->adj)){
            e->next=p->next;
            p->next=e;
            return head;
        }
    }
    p->next=e;
    return head;
}
void createGraph(Vlink graph[],int n){
    int i,v1,v2;
    for(i=0; i<n; i++){
        scanf("%d %d",&v1,&v2);
        graph[v1].link=insertEdge(graph[v1].link, v2);
        graph[v2].link=insertEdge(graph[v2].link, v1);
    }
}


int  Visited[MaxV]={0}; //标识顶点是否被访问过，N为顶点数
void DFS(Vlink  G[ ], int v)
{
    ELink  *p;
    Visited[v] = 1; //标识某顶点被访问过
    printf("%d ",v);
    for(p = G[v].link; p !=NULL;  p=p->next){
        if( !Visited[p->adj] ){
            DFS(G,p->adj);
        }
    }
}
void  travelDFS(Vlink  G[ ], int n)
{
    int i;
    for(i=0; i<n; i++) Visited[i] = 0 ;
    for(i=0; i<n; i++)
        if( !Visited[i] && G[i].link!=NULL) DFS(G, i);
}

void BFS(Vlink  G[ ], int v,int Q[],int front,int rear)
{
    ELink  *p;
    Visited[v] = 1; //标识某顶点已入队
    Q[++rear]=v;
    while(rear>=front){
        v = Q[front];  //取出队头元素
        front++;
        printf("%d ",v); //访问当前顶点
        for(p=G[v].link; p!=NULL; p=p->next ) //访问该顶点的每个邻接顶点
            if( !Visited[p->adj] ) {
                Visited[p->adj] = 1; //标识某顶点入队
                Q[++rear]=p->adj;
            }
    }
}
void  travelBFS(Vlink  G[ ], int n)
{
    int i;
    for(i=0; i<n; i++) Visited[i] = 0 ;
    int Q[MaxV]={0},front=0,rear=-1;
    for(i=0; i<n; i++)
        if( !Visited[i] && G[i].link!=NULL ) BFS(G, i,Q,front,rear);
}


int main() {
//    freopen("a.in", "r", stdin);
//    freopen("a.out", "w", stdout);
    int dot,line,tmp;
    scanf("%d %d",&dot,&line);
    Vlink graph[MaxV]={NULL};
    createGraph(graph,line);
    scanf("%d",&tmp);
    travelDFS(graph,dot);
    printf("\n");
    travelBFS(graph,dot);
    printf("\n");

    int i;
    ELink *p;
    for(i=0; i<dot; i++){
        if(i==tmp){
            graph[i].link=NULL;
        } else{
            p=graph[i].link;
            if(p->adj==tmp){
                graph[i].link=p->next;
            } else{
                for(; p->next != NULL; p=p->next){
                    if((p->next->adj)==tmp){
                        p->next=p->next->next;
                        break;
                    }
                }
            }
        }
    }
    travelDFS(graph,dot);
    printf("\n");
    travelBFS(graph,dot);
    printf("\n");
    return 0;
}


