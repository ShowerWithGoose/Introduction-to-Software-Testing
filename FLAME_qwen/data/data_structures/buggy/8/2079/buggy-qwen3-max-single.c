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
    for(p=head; p->next != NULL;q=p, p=p->next); // @@ [This loop condition is incorrect: it stops before the last node, causing insertion to always happen at the end regardless of order, violating the requirement to insert in ascending order. It should compare `avex` with `p->adj` during traversal.]
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
    if(m>0) // @@ [Incorrect condition: should be `m >= 0` because vertex 0 is never deleted (per problem), but deletion vertex can be any non-zero, including possibly 0 in logic? However, problem says "vertex to be deleted is not vertex 0", so `m>0` may seem okay, BUT in first call from main, m=0 is passed to mean "no deletion", and this skips marking any vertex as deleted. However, when m=0, we should NOT mark vertex 0 as deleted. But the real issue is: in the first two calls, we pass m=0 to indicate no deletion, and this condition `if(m>0)` correctly avoids deleting anything. So this line is actually correct. However, note that in the reference program, they use `delV >= 0` to mean "delete mode", and set `Visited[delV]=1`. In this buggy code, when m=0 (first call), it does NOT mark vertex 0 as deleted — which is correct. But wait: what if the deleted vertex is passed as 0? Problem says it won't be. So this is okay. However, there's a deeper issue: in the main function, the first two calls pass 0 as the third argument, intending to mean "no deletion", but the function interprets m=0 as "do not delete any vertex", which is correct. So this line is NOT erroneous. The real error is elsewhere.]
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
             printf("empty queue!"); // @@ [When queue is empty, this prints an error but does not return a value. The function is expected to return an int. This leads to undefined behavior. Also, the calling code assumes a valid vertex is returned. Moreover, the problem guarantees connectivity and valid input, so queue shouldn't be empty during BFS, but the function still must return a value in all paths. Missing return after error.]
       else{
             e=queue[front];
             count--;                             /* 队非空，删除成功 */
       front = (front+1)%100;
       return e;
       }
} // @@ [Missing return statement for the case when queue is empty. Function must return an int in all control paths.]
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
    if(m>0) // @@ [Same as in travelDFS: actually correct per problem constraints, since m=0 means no deletion and deleted vertex ≠ 0, so m>0 correctly identifies when to delete. Not an error.]
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
    travelDFS(G,V,0); // @@ [Passing 0 as the deletion vertex indicator for "no deletion" is acceptable only if the function treats m=0 as no deletion. However, note: what if the graph has vertex 0 and we pass m=0? The function does `if(m>0) visited[m]=1;` so it skips — correct. But the bigger issue: the adjacency lists are not sorted in ascending order due to faulty insertEdge, so DFS/BFS won't traverse neighbors in ascending order, violating requirement #3.]
    travelBFS(G,V,0);
    scanf("%d",&z);
    travelDFS(G,V,z);
    travelBFS(G,V,z);
    return 0;
}