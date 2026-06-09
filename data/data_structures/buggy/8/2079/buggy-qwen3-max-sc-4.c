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
    for(p=head; p->next != NULL;q=p, p=p->next); // @@ [This loop condition is incorrect. It should compare 'avex' with 'p->adj' to insert in ascending order, but instead it just traverses to the end. This breaks the requirement to visit adjacent vertices in ascending order.]
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
    if(m>0)
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
       return 0; // @@ [Missing return value when queue is empty. The function must always return an int, but in the empty case, nothing is returned before this line. This causes undefined behavior.]
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
    if(m>0)
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
    travelDFS(G,V,0);
    travelBFS(G,V,0); // @@ [The problem states that the vertex to be deleted is not vertex 0, and traversal before deletion should use delV = -1 or equivalent. Here, passing 0 as 'm' marks vertex 0 as visited (deleted), which violates the requirement that deletion happens only after the first two traversals. Also, condition 'if(m>0)' skips marking when m==0, but in the first call m=0, so it doesn't mark anything — however, the bigger issue is conceptual: the first traversal should be with no deletion, so 'm' should be -1 or handled differently. But since condition is 'if(m>0)', and first call uses m=0, it accidentally works. However, the real bug is in the second part: when deleting a vertex like 1, m=1>0, so it's marked. BUT the main logical error is that in the first two calls, we pass 0, which is wrong because 0 is a valid vertex and might be misinterpreted. However, due to 'm>0', vertex 0 is NOT marked in first call, so it's okay. So this line may not be erroneous in effect, but the design is fragile. However, the critical errors are elsewhere.]

    scanf("%d",&z);
    travelDFS(G,V,z);
    travelBFS(G,V,z);
    return 0;
}