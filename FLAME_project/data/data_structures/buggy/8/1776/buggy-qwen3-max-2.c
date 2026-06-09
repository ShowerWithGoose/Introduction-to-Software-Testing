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
     scanf("%d%d",&m,&n);//先是顶点数，再是边数
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
  m--;
  printf("\n");
   travelDFS1(G,m); // @@ [Uses DFS1 which incorrectly adjusts vertex numbers (adds 1 for v>=3), but the graph after deletion still uses original labels except the deleted one is removed. The traversal should output original vertex labels excluding the deleted vertex, not remapped ones.]
    printf("\n");
  travelBFS1(G,m); // @@ [Same issue as DFS1: BFS1 also incorrectly adjusts vertex numbers based on arbitrary condition (v>=3), leading to wrong output like "0 1" instead of "0 2".]
  
  
  
    return 0;
}
void delver(VLink G[],int n,int k)
   {
       ELink *p,*q,*r;
       int i;
   
    p=G[k].link;
    for(i=k+1;i<n;i++)
    {
        G[i-1].link=G[i].link;
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
            q->next=p->next; // @@ [Use of uninitialized variable 'q' when G[i].link != p. If the first node isn't the one to delete, 'q' hasn't been set before being used, leading to undefined behavior.]
            r=p;
            p=p->next;
            free(r);
        }
        else{
            if(p->adjvex>k)
            p->adjvex--; // @@ [After deleting vertex k, all vertices with index > k are shifted down by 1 in the array, so their labels should be decremented. However, this changes the actual vertex labels, which breaks the requirement that vertices are labeled 0 to n-1 and traversals use original labels (excluding deleted). The problem expects the graph to have the same labels except the deleted vertex is absent; it does NOT expect relabeling of remaining vertices. This causes adjacency lists to refer to wrong (decremented) labels, leading to incorrect traversal.]
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