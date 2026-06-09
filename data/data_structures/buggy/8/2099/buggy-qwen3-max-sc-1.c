#include <stdio.h>
#include <stdlib.h>

#define MaxV 256
#define MAXSIZE 1000

int dots, bian,v1,v2,delete,V,E; // @@ [Using 'delete' as a variable name is invalid in C++ but allowed in C; however, it may cause issues with some compilers or tools that treat it as a keyword. More critically, this line declares unused variables V and E which is not an error but poor practice. However, the real bug is elsewhere.]
int Visited[MaxV];
int Q[MAXSIZE];
int front,rear,count;

typedef struct  edge{ 
  int  adj;
  int  wei;
  struct edge  *next;
}ELink;

typedef struct ver{
    ELink *link;
}VLink;

VLink  G[MaxV];

ELink  *insertEdge(ELink *head, int avex)
{
  ELink *e,*p,*q = NULL;
    e =(ELink *)malloc(sizeof(ELink)); 
    e->adj= avex; e->wei=1; e->next = NULL;
    if(head == NULL)  return e;
    for(p=head; p != NULL && avex > p->adj;  q = p, p = p->next) 
        ;
    if( p == head){ 
        e->next = p;
        return e;
    }
    else{     
        q->next = e;
        e->next = p;
        return head;
    }
}

void initQueue()
{
  front=0;
  rear=MAXSIZE-1;
  count=0;
}
int isEmpty()
{
  return count==0;
}
int isFull()
{
  return count==MAXSIZE;
}
void enQueue(int queue[],int item)
{
  if(isFull()) printf("FULL!");
  else{
    rear=(rear+1)%MAXSIZE;
    queue[rear]=item;
    count++;
  }
}
int deQueue(int queue[])
{
  int e;
  if(isEmpty()) printf("EMPTY!");
  else{
    e=queue[front];
    count--;
    front=(front+1)%MAXSIZE;
    return e;
  }
  return 0; // @@ [This return 0 after printing "EMPTY!" causes undefined behavior when queue is empty because caller expects a valid vertex number. However, in our problem context, graph is connected and deletion doesn't disconnect it, so BFS/DFS should never try to dequeue from empty queue during traversal. So this might not be the main bug.]
}

void createGraph(VLink graph[]){ 
  for(int i=0;i<bian;i++){
    scanf("%d %d",&v1,&v2);
    graph[v1].link=insertEdge(graph[v1].link, v2);
    graph[v2].link=insertEdge(graph[v2].link, v1);
  }
} 

void DFS(VLink  G[ ], int v)
{
  ELink  *p;
  Visited[v] = 1;
  printf("%d ",v);
  for(p = G[v].link; p !=NULL;  p=p->next)
    if( !Visited[p->adj] )
      DFS(G, p->adj);
}

void BFS(VLink G[ ], int v)
{
    ELink  *p;
    initQueue();
    Visited[v] = 1; //标识某顶点已入队
    enQueue(Q, v);
    while(!isEmpty()){
         v = deQueue(Q);  //取出队头元素
         printf("%d ",v);
         for(p=G[v].link; p!=NULL; p=p->next ) //访问该顶点的每个邻接顶点
             if( !Visited[p->adj] ) {
                Visited[p->adj] = 1; //标识某顶点入队
                enQueue(Q, p->adj);
           }
     }
}

void tDFS(VLink G[],int n,int delV)
{
  for(int i=0;i<n;i++) Visited[i]=0;
  if(delV>=0) Visited[delV]=1;
  for(int i=0;i<n;i++){
    if(!Visited[i]) DFS(G,i);
  }
  printf("\n");
}

void tBFS(VLink G[],int n,int delV)
{
  int i;
  for(i=0; i<n; i++) Visited[i] = 0 ;
  if(delV>=0) Visited[i]=1; // @@ [BUG: After the loop, i equals n. So Visited[i] = Visited[n], which is out of bounds (valid indices are 0 to n-1). This writes beyond the array, causing undefined behavior. It should be Visited[delV]=1.]
  for(i=0; i<n; i++)
    if( !Visited[i] ) BFS(G, i);
  printf("\n");
}

int main()
{
    scanf("%d %d",&dots,&bian);
    createGraph(G);
    tDFS(G,dots,-1);
    tBFS(G,dots,-1);
    scanf("%d",&delete); // @@ [Using 'delete' as a variable name is problematic in some contexts, but in pure C it's allowed. However, the real critical bug is in tBFS function above.]
    tDFS(G,dots,delete);
    tBFS(G,dots,delete);
    return 0;
}