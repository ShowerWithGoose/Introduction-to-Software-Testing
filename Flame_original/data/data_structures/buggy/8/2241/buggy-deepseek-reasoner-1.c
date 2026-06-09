#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
//邻接表： 
struct edge//边结点 
{ 
    int adjvex;
    struct edge *next;
};
struct ver//顶点节点 
{
    int vertex;
    struct edge *next;
};
struct ver G[100]={};
int QUEUE[101]; // @@ Array size is insufficient for modulo 10000 operations; should be at least 10000.
int Front = 0, Rear = 9999, Count = 0;
int emptyQ()
{
    return Count == 0;
}
void enQueue(int item)
{
    Rear = (Rear + 1) % 10000; 
    QUEUE[Rear] = item;
    Count++;                      //队未满，插入成功

}
int deQueue()
{ 
    int e;  
    e = QUEUE[Front];
    Count--;                     //队非空，删除成功
    Front = (Front + 1) % 10000;
    return e;
}
struct edge* insertNode(struct edge* list, int elem)
{
    struct edge *p, *q, *r;
    r = (struct edge*)malloc(sizeof(struct edge));
    r->adjvex = elem;
    r->next = NULL;
    if(list == NULL)//list是一个空表
    {
        return r;
    }
    
    for(p = list; p != NULL && elem > p->adjvex; q = p, p = p->next)
        ;
    if(p == list)//头结点前插入 
    {
        r->next = p;
        return r;
    }
    else//在q后插入 
    {
        q->next = r;
        r->next = p;
    }
    return list;
}

//邻接表深度优先： 
int visited[2000] = {0}; //标识顶点是否被访问过，N为顶点数
void visit(struct ver G[], int v)
{
    printf("%d ", G[v].vertex);
}
void DFS(struct ver G[], int v)
{
    struct edge *p;
    visited[v] = 1;     //标识某顶点被访问过
    visit(G, v);     //访问某顶点
    for(p = G[v].next; p != NULL;  p = p->next)
         if(!visited[p->adjvex])
             DFS(G, p->adjvex);
}
void travelDFS(struct ver G[], int n)
{
    int i;
    for(i = 0; i < n; i++)
        visited[i] = 0 ;
    for(i = 0; i < n; i++)
        if(!visited[i]) DFS(G, i);
}

void BFS(struct ver G[], int v)
{
    struct edge *p;
    visit(G, v); //访问当前顶点
    visited[v] = 1; //标识某顶点被访问过
    enQueue(v);         // 入口的第一个顶点入队
    while(!emptyQ()){  //  循环，直到队空为止 
         v = deQueue();  //取出队头元素
         p = G[v].next;         //获取该顶点第一个邻接顶点
         for(; p != NULL ; p = p->next ) //访问该顶点下的每个邻接顶点
             if(!visited[p->adjvex])
             {
                visit(G, p->adjvex); //访问当前顶点
                visited[p->adjvex] = 1; //标识某顶点被访问过
                enQueue(p->adjvex); //邻接顶点依次分别入队
             }
     }
}

int main()
{
    int n,t,delnum;
    scanf("%d %d",&n,&t);
    for(int i=0;i<n;i++){
        G[i].vertex = i;
    }
    for(int i=0;i<t;i++){
        int V1,V2;
        scanf("%d %d",&V1,&V2);
        G[V1].next = insertNode(G[V1].next, V2);
        G[V2].next = insertNode(G[V2].next, V1);
    }
    scanf("%d",&delnum);
    DFS(G, 0);printf("\n");
    for(int i=0;i<=n;i++){
        visited[i] = 0;
    }
    BFS(G, 0);printf("\n");
    for(int i=0;i<=n;i++){
        visited[i] = 0;
    }
    visited[delnum] = 1;
    DFS(G, 0);printf("\n");
    for(int i=0;i<=n;i++){
        visited[i] = 0;
    }
    BFS(G, 0);printf("\n"); // @@ Missing reset of queue indices (Front, Rear, Count) before this BFS; may cause out‑of‑bounds access due to leftover indices from previous BFS.
    return 0;
}