#include<stdio.h>
#include<stdlib.h>
int visited[100]={0};
int V,E;
typedef struct  edge{ 
    int  adj;
    int  wei;
    struct edge* next;
}ELink;
typedef struct ver{
       ELink* link;
}VLink;
VLink G[100];
ELink  *insertEdge(ELink *head, int avex)
{
    ELink *e,*p,*q=NULL;
    e =(ELink *)malloc(sizeof(ELink));
    e->adj= avex; e->wei=1; e->next = NULL;
    if(head == NULL)  { head=e; return head; }
    for(p=head; p->next != NULL;q=p, p=p->next); // @@ This loop goes to the end of the list, not inserting in ascending order. The problem requires visiting adjacent vertices in ascending order, so edges should be inserted in sorted order. The reference program inserts in ascending order using a different loop.
    if(p==head){
        e->next=p;
        return e;
    }
    else{
        q->next=e;
        e->next=p;
        return head;
    }
}
void createGraph(VLink graph[]){ 
int v1,v2; 
  for(int i=0; i<E; i++){
    scanf("%d%d",&v1,&v2);
      graph[v1].link=insertEdge(graph[v1].link, v2);
      graph[v2].link=insertEdge(graph[v2].link, v1);
  }
} 
void DFS(VLink  G[ ], int v)
{
    ELink  *p;
    visited[v] = 1; //标识某顶点被访问过
    printf("%d ",v);
    for(p = G[v].link; p !=NULL;  p=p->next)
         if( !visited[p->adj] )
             DFS(G,p->adj);
}
void  travelDFS(VLink  G[ ], int n,int m)
{
    int i;
    for(i=0; i<n; i++) visited[i] = 0 ;
    if(m>0) // @@ This condition is incorrect. It should be `if(m>=0)` to mark the deleted vertex as visited (since vertex 0 can be deleted? But problem says deleted vertex is not 0, but m could be 0? Actually m is the vertex to delete, and if m=0, it should be marked visited, but problem says deleted vertex is not 0, so m>0 works here, but the logic is fragile. More importantly, the reference program uses `if(s>=0)` to mark the deleted vertex, which is correct for any non-negative vertex. Here m>0 fails if m=0, but since deleted vertex is not 0, it's okay. However, the main issue is that the function parameter order is wrong in calls.
    visited[m]=1;
    for(i=0; i<n; i++)
        if( !visited[i] ) DFS(G, i);
    printf("\n");
}
int Q[100];
int front,rear,count;
void  initQueue(  ) 
{
    front = 0;
    rear = 100-1;
    count = 0;
}
int  isEmpty( )
{
    return count == 0;
}
int  isFull( )
{
        return count ==100;
}
void enQueue(int queue[ ], int item)
{
       if(isFull())                       /* 队满，插入失败 */  
             printf("Full queue!");
       else{
             rear = (rear+1) % 100; 
             queue[rear]=item;
             count++;                                   /* 队未满，插入成功 */ 
       }
 }
int deQueue(int queue[ ])
{ 
   int e;
       if(isEmpty())
             printf("empty queue!");
       else{
             e=queue[front];
             count--;                             /* 队非空，删除成功 */
       front = (front+1)%100;
       return e;
       }
}
void BFS(VLink  G[ ], int v)
{
    ELink  *p;
    initQueue();
    visited[v] = 1; //标识某顶点已入队
    enQueue(Q, v);
    while( !isEmpty()){
         v = deQueue(Q);  //取出队头元素
         printf("%d ",v);
         for(p=G[v].link; p!=NULL; p=p->next ) //访问该顶点的每个邻接顶点
             if( !visited[p->adj] ) {
                    visited[p->adj] = 1; //标识某顶点入队
                    enQueue(Q, p->adj);
           }
     }
}
void  travelBFS(VLink  G[ ], int n,int m)
{
    int i;
    for(i=0; i<n; i++) visited[i] = 0 ;
    if(m>0) // @@ Same issue as in travelDFS: should be `if(m>=0)` for consistency, but since deleted vertex is not 0, it works. However, the parameter order in calls is wrong.
    visited[m]=1;
    for(i=0;i<n; i++)
        if( !visited[i] ) BFS(G, i);
    printf("\n");
}
int main()
{
    int z;
    scanf("%d%d",&V,&E);
    createGraph(G);
    travelDFS(G,V,0); // @@ The function signature is travelDFS(VLink G[], int n, int m), but here the third argument is 0, which means marking vertex 0 as visited (since m>0 is false, it won't mark anything). The intention is to pass -1 for no deletion, but 0 is passed. This causes the traversal to start from vertex 0 correctly but the condition `if(m>0)` prevents marking vertex 0 as visited, which is fine. However, the real issue is that the function expects the deleted vertex as third argument, but here 0 is passed as the "deleted vertex", which is incorrect. Should be -1.
    travelBFS(G,V,0); // @@ Same issue: should pass -1 for no deletion.
    scanf("%d",&z);
    travelDFS(G,V,z); // @@ This passes z as the deleted vertex, which is correct.
    travelBFS(G,V,z); // @@ Correct.
    return 0;
}