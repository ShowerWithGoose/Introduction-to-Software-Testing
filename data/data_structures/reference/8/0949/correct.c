#include<stdio.h>
#include<stdlib.h>
#define MaxV 128 
typedef struct  edge{ 
       int  adj;
       struct edge  *next;
}ELink;
typedef struct ver{
       ELink *link;
}Vlink;
Vlink graph[MaxV];
int front=1,rear=0,order[MaxV];
ELink *insertEdge(ELink *head, int avex);
void travelDFS(Vlink G[ ], int n);
void travelBFS(Vlink G[ ], int n);
void DFS(Vlink  G[ ], int v);
void BFS(Vlink  G[ ], int v);
void enQueue(int v);
int deQueue();
int emptyQ();
int n,e;
int  Visited[MaxV]={0};
int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    scanf("%d%d",&n,&e);
    int a,b,num;
    for(int i = 0; i < e; i++){
        scanf("%d%d",&a,&b);
        graph[a].link = insertEdge(graph[a].link, b);
        graph[b].link = insertEdge(graph[b].link, a);
    }
    for(int i = 0; i < n; i++) Visited[i] = 0 ;
    travelDFS(graph,n);printf("\n");
    for(int i = 0; i < n; i++) Visited[i] = 0 ;
    travelBFS(graph,n);printf("\n");
    scanf("%d",&num);
    for(int i = 0; i < n; i++) Visited[i] = 0 ;
    Visited[num]=1;
    travelDFS(graph,n);printf("\n");
    for(int i = 0; i < n; i++) Visited[i] = 0 ;
    Visited[num]=1;
    travelBFS(graph,n);printf("\n");
    return 0;
}

ELink *insertEdge(ELink *head, int avex)
{
    ELink *e,*p;
    e = (ELink *)malloc(sizeof(ELink));
    e->adj = avex; e->next = NULL;
    if(head == NULL)
    { 
        head = e; 
        return head; 
    }
    if(head->adj>avex){
        e->next = head;
        head = e;
        return head;
    }
    for(p=head; p->next != NULL; p=p->next)
        if(p->adj<avex&&p->next->adj>avex)
        {
            e->next = p->next;
            p->next = e;
            return head;
        }
    p->next = e;  
    return head;
}
void VISIT(Vlink G[],int v)
{
    printf("%d ",v);
}
void travelDFS(Vlink G[ ], int n)
{
    int i;
    for(i=0; i<n; i++)
        if( !Visited[i] ) DFS(G, i);
}
void travelBFS(Vlink G[ ], int n)
{
    int i;
    for(i=0; i<n; i++)
        if( !Visited[i] ) BFS(G, i);
}
void DFS(Vlink  G[ ], int v)
{
    ELink  *p;
    Visited[v] = 1; //标识某顶点被访问过
    VISIT(G, v); //访问某顶点
    for(p = G[v].link; p !=NULL;  p=p->next)
         if(!Visited[p->adj])
             DFS(G, p->adj);
}
void enQueue(int v)
{
    order[++rear] = v;
}
int deQueue()
{
    return order[front++];
}
int emptyQ()
{
    if(front<=rear)return 0;
    else return 1;
}
void BFS(Vlink  G[ ], int v)
{
    ELink  *p;
    Visited[v] = 1; //标识某顶点已入队
    enQueue(v);
    while( !emptyQ()){
         v = deQueue();  //取出队头元素
         VISIT(G, v); //访问当前顶点
         for(p=G[v].link; p!=NULL; p=p->next ) //访问该顶点的每个邻接顶点
             if( !Visited[p->adj] ) {
                    Visited[p->adj] = 1; //标识某顶点入队
                    enQueue(p->adj);
           }
     }
}

