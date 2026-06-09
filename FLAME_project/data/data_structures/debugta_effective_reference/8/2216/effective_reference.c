#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#define MaxV  1000
typedef struct  edge{ 
       int  adj;//相邻顶点编号信息
       //int  wei;//权重
       struct edge  *next;
}ELink;
typedef struct ver{
       //vertype  vertex; 源顶点信息
       ELink  *link;
}VLink;
VLink  G[MaxV];
ELink *Q[MaxV];
int Visited[MaxV];
int N,E,front,rear,delete=105;
void createGraph(VLink graph[]);
ELink *insertEdge(ELink *head, int avex);
void DFS(VLink  G[ ], int v);
void  travelDFS(VLink  G[ ], int N);
void BFS(VLink  G[ ], int v);
void  travelBFS(VLink  G[ ], int N);
int empty(ELink *Q[]);
void enQueue(ELink *G[ ],int adj);
int deQueue(ELink *Q[]);
void deletever(VLink G[]);


int main()
{
    scanf("%d %d",&N,&E);
    createGraph(G);
    travelDFS(G,N);
    printf("\n");
    travelBFS(G,N);
    printf("\n");
    scanf("%d",&delete); 
    deletever(G);
    travelDFS(G,N);
    printf("\n");
    travelBFS(G,N);
    

    return 0;


}
int empty(ELink *Q[])
{
    if(front==rear) return 1;
    else return 0;
}
void enQueue(ELink *Q[ ],int adj)
{
    ELink *e;
    e =(ELink *)malloc(sizeof(ELink));
    e->adj= adj; 
    e->next = NULL;
    Q[rear++]=e;
}
int deQueue(ELink *Q[])
{
    return Q[front++]->adj;
}

void BFS(VLink  G[ ], int v)
{
    ELink  *p;
    Visited[v] = 1; //标识某顶点已入队
    enQueue(Q, v);
    while( !empty(Q)){
         v = deQueue(Q);  //取出队头元素
         //VISIT(G, v); //访问当前顶点
         printf("%d ",v);
         for(p=G[v].link; p!=NULL; p=p->next ) //访问该顶点的每个邻接顶点
             if( !Visited[p->adj] ) {
                    Visited[p->adj] = 1; //标识某顶点入队
                    enQueue(Q, p->adj);
           }
     }
}
void  travelBFS(VLink  G[ ], int N)
{
    int i;
    for(i=0; i<N; i++) Visited[i] = 0 ;
    Visited[delete]=1;
    for(i=0; i<N; i++)
        if( !Visited[i] ) BFS(G, i);
}
void DFS(VLink  G[ ], int v)
{
    ELink  *p;
    Visited[v] = 1; //标识某顶点被访问过
    //VISIT(G, v); //访问某顶点
    printf("%d ",v);
    for(p = G[v].link; p !=NULL;  p=p->next)
         if( !Visited[p->adj] )
             DFS(G, p->adj);
}
void  travelDFS(VLink  G[ ], int N)
{
    int i;
    for(i=0; i<N; i++) Visited[i] = 0 ;
    Visited[delete]=1;
    for(i=0; i<N; i++)
        if( !Visited[i] ) DFS(G, i);
}

void createGraph(VLink graph[]){ 
    
  int i,N,v1,v2;
  /*scanf("%d",&n);
  for(i=0; i<n; i++){
    scanf("%d %d",&v1,&v2);
    while(v2 != -1){
      graph[v1].link=insertEdge(graph[v1].link, v2);//给源顶点添加顶点信息
      graph[v2].link=insertEdge(graph[v2].link, v1);//给新顶点添加源顶点
      scanf("%d",&v2);
    }
  }*/
    for(int i=0;i<E;i++)
    {
        scanf("%d%d",&v1,&v2);
        graph[v1].link=insertEdge(graph[v1].link, v2);//给源顶点添加顶点信息
        graph[v2].link=insertEdge(graph[v2].link, v1);//给新顶点添加源顶点
    }
} 
ELink *insertEdge(ELink *head, int avex)
{
    ELink *e,*p;
    e =(ELink *)malloc(sizeof(ELink));
    e->adj= avex; 
    //e->wei=1; 
    e->next = NULL;
    if(head == NULL)  { head=e; return head; }
    if(head->adj>avex){
        e->next=head;
        head=e;
        return head;
    }
    for(p=head;; p=p->next)
        {
            
            
                if(p->next==NULL)
                {
                    p->next=e;
                    return head;
                }
                else if(avex<p->next->adj)
                {
                    e->next=p->next;
                    p->next=e;
                    return head;
                }
                else continue;
            
        }
}
void deletever(VLink G[])
{
    ELink *p,*q;
    free(G[delete].link);
    G[delete].link=NULL;
    for(int i=0;i<N;i++)
    {
        p=G[i].link;
        if(p==NULL)
        {
            continue;
        }
        if(p->adj==delete)
        {
            G[i].link=p->next;
            free(p);
            continue;
        }
        while(p->next!=NULL)
        {
            if(p->next->adj==delete)
            {
                q=p->next;
                p->next=q->next;
                free(q);
                break;
            }
            p=p->next;
        }
    }
}
