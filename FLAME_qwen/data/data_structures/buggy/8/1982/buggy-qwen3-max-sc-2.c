#include<stdio.h>
#include<stdlib.h>
#define MaxValue 1000
#define MaxVNum 100
#define MaxV    256
int n1,n2;
int item;
int Queue[1000];
int Queue1[1000];
int rear1=0,front1=0;
int rear=0,front=0;
int  Visited[105]={0};
int  Visited1[105]={0}; //标识顶点是否被访问过，n1为顶点数
typedef struct  edge{ 
       int  adjvex;
       int  wei;
       struct edge *next;
} ELink;
typedef struct ver{
       ELink *link;
} VLink;
VLink  G[MaxV];
//在链表尾插入一个节点
void insert(VLink *p, int a)
{
    ELink *r=NULL;
    ELink *t=NULL;
    ELink *q=NULL;
    if(p->link==NULL){
        r=(ELink*)malloc(sizeof(ELink));
        r->adjvex=a;
        r->next=NULL;
        p->link=r;
        return;
    }
    if(p->link->adjvex>a){
        r=(ELink*)malloc(sizeof(ELink));
        r->adjvex=a;
        r->next=p->link;
        p->link=r;
    }
    else{
    r=p->link->next;
    q=p->link;
    while(r!=NULL){
        if(r->adjvex>a){
            t=(ELink*)malloc(sizeof(ELink));
            t->adjvex=a;
            t->next=r;
            q->next=t;
            return;
        }
            r=r->next;
            q=q->next;
    }
    t=(ELink*)malloc(sizeof(ELink));
    t->adjvex=a;
    q->next=t;
    t->next=NULL;

}
}

void createGraph(VLink graph[]){
  int i,v1,v2;
  scanf("%d%d",&n1,&n2);
  for(i=0; i<n2; i++){
    scanf("%d%d",&v1,&v2);
      insert(&G[v1],v2);
      insert(&G[v2],v1);
    }
  }

void DFS(VLink  G[ ], int v)
{
    ELink  *p;
    p = G[v].link;
    Visited[v] = 1;    //标识某顶点被访问过
     printf("%d ",v);
    for(p = G[v].link; p !=NULL;  p=p->next){
         if( !Visited[p->adjvex] ){
             DFS(G, p->adjvex);
         }
         
}
}
void  travelDFS(VLink  G[], int n)
{
    int i;
    for(i=0; i<n; i++) Visited[i] = 0 ;
    for(i=0; i<n; i++){
        if( !Visited[i] ) {
        DFS(G,i);
    }
}
}
void DFS1(VLink  G[ ], int v,int item)
{
    ELink  *p;
    p = G[v].link;
    Visited[v] = 1;    //标识某顶点被访问过
if(v!=item)
     printf("%d ",v);
    for(p = G[v].link; p !=NULL;  p=p->next){
         if( !Visited[p->adjvex] &&p->adjvex!=item){
             DFS1(G, p->adjvex,item);
         }
         
}
}
void  travelDFS1(VLink  G[], int n,int item)
{
    int i;
    for(i=0; i<n; i++) Visited[i] = 0 ;
    for(i=0; i<n; i++){
        if( !Visited[i] ) {
        DFS1(G,i,item);
    }
}
}

void enQueue(int a){
  Queue[rear++]=a;
}
int deQueue(){
  return Queue[front++];
}
int isEmpty(){
  return front>rear;
}

void BFS(VLink  G[ ], int v)
{
    ELink  *p;
   printf("%d ",v); //访问当前顶点
    Visited[v] = 1; //标识某顶点被访问过
   enQueue(v); // 入口的第一个顶点入队
    while( !isEmpty()){  //  循环，直到队空为止 
         v = deQueue();  //取出队头元素
         p = G[v].link;//获取该顶点第一个邻接顶点
         for(; p != NULL ; p = p->next ) //访问该顶点下的每个邻接顶点
             if( !Visited[p->adjvex] ) {
                   printf("%d ",p->adjvex); //访问当前顶点
                    Visited[p->adjvex] = 1; //标识某顶点被访问过
                    enQueue(p->adjvex); //邻接顶点依次分别入队
           }
     }
}
void  travelBFS(VLink  G[ ], int n)
{
    int i;
    for(i=0; i<n; i++) Visited[i] = 0 ;
    for(i=0; i<n; i++)
        if( !Visited[i] ) BFS(G, i);
}
void enQueue1(int a){
  Queue1[rear1++]=a;
}
int deQueue1(){
  return Queue1[front1++];
}
int isEmpty1(){
  return front1>rear1;
}
void BFS1(VLink  G[ ], int v)
{
    ELink  *p;
    if(v!=item)
   printf("%d ",v); //访问当前顶点
    Visited1[v] = 1; //标识某顶点被访问过
   enQueue1(v); // 入口的第一个顶点入队
    while( !isEmpty1()){  //  循环，直到队空为止 
         v = deQueue1();  //取出队头元素
         p = G[v].link;//获取该顶点第一个邻接顶点
         for(; p != NULL ; p = p->next ) //访问该顶点下的每个邻接顶点
             if( !Visited1[p->adjvex] ) {
                 
                   if(p->adjvex!=item)
               printf("%d ",p->adjvex);
                    Visited1[p->adjvex] = 1; //标识某顶点被访问过
                    enQueue1(p->adjvex);
                     //邻接顶点依次分别入队
           }
           
     }
}
void  travelBFS1(VLink  G[ ], int n)
{
    int i;
    for(i=0; i<n; i++) Visited1[i] = 0;
    for(i=0; i<n; i++)
        if( !Visited1[i] &&i!=item) BFS1(G, i); // @@ [The traversal should always start from vertex 0, but this loop starts from i=0 and skips 'item', which may skip vertex 0 if item==0. However, per problem statement, item != 0, so the real issue is that it doesn't enforce starting at 0. It should only start DFS/BFS from 0, not iterate over all vertices.]
}
int main(){
        createGraph(G);
        scanf("%d",&item);
    travelDFS(G,n1); // @@ [This function traverses all unvisited components starting from every unvisited vertex, but the problem requires traversal to start only from vertex 0.]
    printf("\n");
    travelBFS(G,n1); // @@ [Same issue: should only start from vertex 0, not all unvisited vertices.]
    printf("\n");
    travelDFS1(G,n1,item); // @@ [Same issue: should start only from vertex 0 (if not deleted), not all unvisited vertices.]
    printf("\n");
    travelBFS1(G,n1); // @@ [This calls travelBFS1 without passing 'item', but travelBFS1 uses global 'item'. However, more critically, it should only start from vertex 0, not loop over all vertices. Also, note that travelBFS1's signature doesn't take 'item' as parameter but uses global, which is okay, but the loop is wrong.]
    return 0;    
}