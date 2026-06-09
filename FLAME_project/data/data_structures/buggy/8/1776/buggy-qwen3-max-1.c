#include <stdio.h>
#include <stdlib.h>
#define maxv 110
typedef struct edge{
    int adjvex;//另一个边节点
    int weight;
    struct edge *next;//指针
}ELink;
typedef struct ver{
    //vertype vertex;//顶点结点的数据信息
    ELink *link;//第一个边界点
}VLink;
VLink G[maxv];//顶点结点数组
ELink *insertedge(ELink *head,int avex)
{
    ELink *e,*p;
    e=(ELink*)malloc(sizeof(ELink));
    e->adjvex=avex;
    e->weight=1;
    e->next=NULL;
    if(head==NULL){
        head=e;
        return head;
    }
    for(p=head;p->next!=NULL;p=p->next)
    {
        ;//printf("%d ",1);//p->adjvex
    }
    //printf("\n");
    p->next=e;
    return head;
}
int  Visited[maxv]={0};
int  Visited1[maxv]={0}; //标识顶点是否被访问过，N为顶点数
void DFS(VLink  G[ ], int v)
{
    ELink  *p;
    Visited[v] = 1; //标识某顶点被访问过
    //VISIT(G, v); //访问某顶点
    printf("%d ",v);
    for(p = G[v].link; p !=NULL;  p=p->next)
         if( !Visited[p->adjvex] )
             DFS(G, p->adjvex);
}

void DFS1(VLink  G[ ], int v)
{
    ELink  *p;
    Visited[v] = 1; //标识某顶点被访问过
    //VISIT(G, v);
    if(v>=3) //访问某顶点
    printf("%d ",v+1);
    else
    printf("%d ",v);
    for(p = G[v].link; p !=NULL;  p=p->next)
         if( !Visited[p->adjvex] )
             DFS1(G, p->adjvex);
}

void  travelDFS1(VLink  G[ ], int n)
{
    int i;
    for(i=0; i<n; i++) Visited[i] = 0 ;
    for(i=0; i<n; i++)
        if( !Visited[i] ) DFS1(G, i);
} 
void  travelDFS(VLink  G[ ], int n)
{
    int i;
    for(i=0; i<n; i++) Visited[i] = 0 ;
    for(i=0; i<n; i++)
        if( !Visited[i] ) DFS(G, i);
} 
void bubble(ELink *head);
ELink Q[110];
int rear=-1,front=0;
void enQueue(ELink Q[],int v)
{
    Q[++rear].adjvex=v;
}
int deQueue(ELink Q[])
{
    int temp=Q[0].adjvex;
    int j;
    for(int i=0,j=1;i<rear;i++)
    {
        Q[i].adjvex=Q[j].adjvex;
        j++;
    }
    rear--;
    return temp;
}
int emptyQ(ELink Q[])
{
    if(rear==-1)
    return 0;
    else
    return 1;
}
void BFS(VLink  G[ ], int v)
{
    ELink  *p;
    Visited1[v] = 1; //标识某顶点已入队
    enQueue(Q, v);
    while(rear!=-1){
         v = deQueue(Q);  //取出队头元素
    printf("%d ",v);
         //VISIT(G, v); //访问当前顶点
         for(p=G[v].link; p!=NULL; p=p->next ) //访问该顶点的每个邻接顶点
             if( !Visited1[p->adjvex] ) {
                    Visited1[p->adjvex] = 1; //标识某顶点入队
                    enQueue(Q, p->adjvex);
           }
     }
}
    
void BFS1(VLink  G[ ], int v)
{
    ELink  *p;
    Visited1[v] = 1; //标识某顶点已入队
    enQueue(Q, v);
    while(rear!=-1){
         v = deQueue(Q);  //取出队头元素
         if(v>=3) //访问某顶点
    printf("%d ",v+1);
    else
    printf("%d ",v);
         //VISIT(G, v); //访问当前顶点
         for(p=G[v].link; p!=NULL; p=p->next ) //访问该顶点的每个邻接顶点
             if( !Visited1[p->adjvex] ) {
                    Visited1[p->adjvex] = 1; //标识某顶点入队
                    enQueue(Q, p->adjvex);
           }
     }
}


void  travelBFS1(VLink  G[ ], int n)
{
    int i;
    for(i=0; i<n; i++) Visited1[i] = 0 ;
    for(i=0; i<n; i++)
        if( !Visited1[i] ) BFS1(G, i);
}
void  travelBFS(VLink  G[ ], int n)
{
    int i;
    for(i=0; i<n; i++) Visited1[i] = 0 ;
    for(i=0; i<n; i++)
        if( !Visited1[i] ) BFS(G, i);
}
void delver(VLink G[],int n,int k);








int main() {
     int m,n;
     int a,b;
     int i=0,j=0;
     int k;
     scanf("%d%d",&m,&n);//先是顶点数，再是边数 @@ [The input order is swapped: it should be n (vertices) then m (edges), but the code reads m then n. This causes all subsequent logic to use wrong values for number of vertices and edges.]
     for(i=0;i<n;i++)
     {
         scanf("%d%d",&a,&b);
         G[a].link=insertedge(G[a].link,b);
         G[b].link=insertedge(G[b].link,a);
     }
     for(i=0;i<m;i++)
     {
       bubble(G[i].link);    
     }
     scanf("%d",&k);
  travelDFS(G,m);
  printf("\n");
  travelBFS(G,m);
  
  delver(G,m,k);
  m--; @@ [After deleting vertex k, the graph still has m vertices (original count), but the code decrements m. However, the deletion logic in delver doesn't actually reduce the vertex count properly—it shifts vertices and renumbers, which is incorrect. The problem requires simply removing vertex k and its incident edges, not renumbering remaining vertices.]
  printf("\n");
   travelDFS1(G,m);
    printf("\n");
  travelBFS1(G,m);
  
  
  
    return 0;
}
void delver(VLink G[],int n,int k)
   {
       ELink *p,*q,*r;
       int i;
   
    p=G[k].link;
    for(i=k+1;i<n;i++)
    {
        G[i-1].link=G[i].link; @@ [This shifts all vertices after k down by one index, effectively renumbering them. But the problem does NOT require renumbering vertices—only removing vertex k and its edges. This causes vertex numbers to change (e.g., original vertex 2 becomes vertex 1 after deleting vertex 1), leading to wrong output like "0 1" instead of "0 2".]
    }
    n--;
    while(p!=NULL)
    {
        r=p;
        p=p->next;
        free(r);
    }
    for(i=0;i<n;i++)
    {
        p=G[i].link;
        while(p!=NULL)
        if(p->adjvex==k)
        {
            if(G[i].link==p)
            G[i].link=p->next;
            else
            q->next=p->next;
            r=p;
            p=p->next;
            free(r);
        }
        else{
            if(p->adjvex>k)
            p->adjvex--; @@ [This decrements adjacent vertex numbers greater than k, which is part of the incorrect renumbering. The problem expects original vertex labels to remain unchanged after deletion—only the deleted vertex is removed from adjacency lists.]
            q=p;
            p=p->next;
        }
        
    }

}







void bubble(ELink *head)
{
    ELink*cur,*tail;
    cur=head;
    tail=NULL;
    if(cur==NULL||cur->next==NULL)
    return;
    while(cur!=tail)
    {
        while(cur->next!=tail)
        {
        if(cur->adjvex>cur->next->adjvex)
        {
            int temp=cur->adjvex;
            cur->adjvex=cur->next->adjvex;
            cur->next->adjvex=temp;
        }
        cur=cur->next;
    }
    tail=cur;
    cur=head;
}
}