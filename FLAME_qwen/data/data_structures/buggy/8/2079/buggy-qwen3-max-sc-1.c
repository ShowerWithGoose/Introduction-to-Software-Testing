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
    for(p=head; p->next != NULL;q=p, p=p->next); @@ [This loop condition is incorrect. It should compare 'avex' with 'p->adj' to insert in ascending order, but instead it just traverses to the end. This breaks the requirement to visit adjacent vertices in ascending order.]
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
    visited[m]=1; @@ [The condition should be 'm >= 0' because vertex 0 is never deleted (per problem), but deletion vertex can be any non-zero including possibly 0? However, per problem: "vertex to be deleted is not vertex 0", so m won't be 0 in deletion call. But in first call from main, m=0 is passed to mean "no deletion", yet this sets visited[0]=1 which skips traversal! This is a critical logic error.]
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
} @@ [Missing return value when queue is empty. Function should always return an int, but in empty case it doesn't return anything, leading to undefined behavior.]
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
    visited[m]=1; @@ [Same issue as in travelDFS: when m=0 (first call), this incorrectly marks vertex 0 as visited, preventing traversal from starting at 0. Should use 'm >= 0' and only skip if m is the deletion vertex, but more importantly, the first call passes m=0 intending NO deletion, so this logic is inverted.]
    for(i=0;i<n; i++)
        if( !visited[i] ) BFS(G, i);
    printf("\n");
}
int main()
{
    int z;
    scanf("%d%d",&V,&E);
    createGraph(G);
    travelDFS(G,V,0); @@ [Passing 0 here means "no deletion", but travelDFS interprets m>0 as deletion. So m=0 causes no vertex to be marked as deleted, which is correct. BUT wait: in travelDFS, condition is 'if(m>0) visited[m]=1;'. So for m=0, it does NOT mark anything, which is correct. However, in the problem, the first two traversals are BEFORE deletion, so deletion vertex should be ignored. So passing 0 is okay ONLY IF 0 is not the deletion vertex (which it isn't). However, the real bug is in the insertion function not maintaining sorted adjacency lists, causing DFS/BFS to not traverse neighbors in ascending order. Also, note that in the reference program, they pass -1 for no deletion, but here we pass 0. Since vertex 0 is never deleted, using 0 as "no deletion" conflicts because if by accident deletion vertex was 0 (which it won't be per problem), but more critically, the logic in travelDFS/BFS uses 'm>0' which excludes 0, so for deletion vertex 0 (which shouldn't happen) it wouldn't delete, but the bigger issue is that the first call passes 0 and that's fine. However, the main logical error is in insertEdge not sorting properly.]
    travelBFS(G,V,0);
    scanf("%d",&z);
    travelDFS(G,V,z);
    travelBFS(G,V,z);
    return 0;
}