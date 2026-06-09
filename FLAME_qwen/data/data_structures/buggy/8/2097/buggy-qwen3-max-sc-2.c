#include<stdio.h>
#include<string.h>
#include<malloc.h>
int visit[1005]={0};
typedef struct  edge{ 
       int  adj;
       int wei;
       struct edge *next;
}Elink;
typedef struct ver{
    int adj; // @@ [This field 'adj' is unused and conflicts with the intended adjacency list structure; it should be removed to match the graph representation used in functions like insertEdge and DFS.]
       Elink *link;
}Vlink;
Vlink G[1005];
Vlink graph[1005];

void DFS(Vlink  G[ ], int v)
{
    Elink  *p;
    visit[v] = 1; 
  
    printf("%d ",v);
    for(Elink *p = G[v].link; p !=NULL;  p=p->next)
         if( visit[p->adj]==0)
             DFS(G, p->adj);
}
void  travelDFS(Vlink  G[ ], int n)
{
    int i;
    for(i=0; i<n; i++) visit[i] = 0 ;
    for(i=0; i<n; i++)
        if(!visit[i]) 
        DFS(G, i);
}
Elink* insertEdge(Elink* head, int avex)
{
    Elink *e,*p,*r=head;
    e =(Elink *)malloc(sizeof(Elink));
    e->adj= avex; e->wei=1; e->next = NULL;
    if(head == NULL)  { head=e; return head; }
    for(p=head; p->next != NULL&&p->adj<=avex; )
        {
            r=p;
            p=p->next;
        }
    
    if(p->adj>avex){
        e->next=r->next;
        r->next=e;
    }
    else{
        p->next=e;
    }
    return head;
}
void createGraph(Vlink graph[]){ 
  int i,v1,v2,m;
  scanf("%d",&m); // @@ [The input format expects both n (number of vertices) and m (number of edges) on the first line, but this code only reads m here. The variable 'n' was read in main before calling createGraph, but 'm' should have been read along with 'n' in main, not inside createGraph. This causes misalignment in input parsing.]
  for(i=0; i<m; i++){
    scanf("%d %d",&v1,&v2);
      graph[v1].link=insertEdge(graph[v1].link, v2);
      graph[v2].link=insertEdge(graph[v2].link, v1);
    
  }
} 
int Q[1005];
int he=0,ta=-1;
void enQueue(int Q[],int v){
    Q[++ta]=v;
}
int emptyQ(){
    if(he<=ta)
    return 0;
    return 1;
}
int deQueue(int Q[]){
    return Q[he++];
}
void  travelBFS(Vlink  G[ ], int n)
{
    int i;
    for(i=0; i<n; i++) 
    visit[i] = 0 ;
    BFS(G, 0);
}
void BFS(Vlink  G[ ], int v)
{
    Elink  *p;
    visit[v] = 1; //标识某顶点已入队
    enQueue(Q, v);
    while( !emptyQ(Q)){
         v = deQueue(Q);  //取出队头元素
        
         printf("%d ",v);
         for(p=G[v].link; p!=NULL; p=p->next ) //访问该顶点的每个邻接顶点
             if( !visit[p->adj] ) {
                    visit[p->adj] = 1; //标识某顶点入队
                    enQueue(Q, p->adj);
           }
     }}

int main(){
    int n,del;
    scanf("%d",&n); // @@ [Only reads 'n', but the problem requires reading both 'n' and 'm' on the first input line. The missing read of 'm' causes the next input (edge count) to be consumed incorrectly inside createGraph, leading to wrong graph construction.]
    createGraph(graph);
    scanf("%d",&del);
    travelDFS(graph,n);
    printf("\n");
    travelBFS(graph,n);
    printf("\n");
    for(int i=0;i<n;i++)
        {
            visit[i]=0;
        }
        visit[del]=1;
    for(int i=0; i<n; i++)
            if(!visit[i]) 
               DFS(graph, i);
        
        printf("\n");
        for(int i=0;i<n;i++)
        {
            visit[i]=0;
        }
        visit[del]=1;
        BFS(graph,0); // @@ [After deletion, traversal must start from vertex 0 only if 0 is not deleted (which is guaranteed), but the BFS function uses a global queue (Q) and global head/tail indices (he, ta) that are not reset before this call. Since 'he' and 'ta' retain values from the previous BFS, the queue state is corrupted, leading to incorrect or no traversal.]
    return 0;
    
}