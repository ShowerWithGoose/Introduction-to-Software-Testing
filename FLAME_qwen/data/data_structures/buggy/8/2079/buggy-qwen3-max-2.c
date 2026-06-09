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
    for(p=head; p->next != NULL;q=p, p=p->next); @@ [The loop condition should compare vertex numbers to insert in ascending order, but it only checks p->next != NULL, causing incorrect insertion order.]
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
    visited[m]=1; @@ [Should mark the deleted vertex as visited even if m==0, but problem states deleted vertex is not 0. However, condition should be m>=0 to match reference program logic. But main issue is in main() calling with m=0 incorrectly.]
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
} @@ [Missing return value when queue is empty; function must always return an int. This causes undefined behavior.]
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
    visited[m]=1; @@ [Same issue as in travelDFS: condition should be m>=0, but more critically, main() passes 0 for initial traversal which incorrectly marks vertex 0 as deleted.]
    for(i=0;i<n; i++)
        if( !visited[i] ) BFS(G, i);
    printf("\n");
}
int main()
{
    int z;
    scanf("%d%d",&V,&E);
    createGraph(G);
    travelDFS(G,V,0); @@ [Passing 0 as deletion vertex for initial traversal is wrong. Should pass a negative value or special flag (like -1) to indicate no deletion, as in reference program. This causes vertex 0 to be skipped in first traversals.]
    travelBFS(G,V,0); @@ [Same error: passing 0 deletes vertex 0, but problem states traversal must start at 0 and deleted vertex is not 0.]
    scanf("%d",&z);
    travelDFS(G,V,z);
    travelBFS(G,V,z);
    return 0;
}