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
int QUEUE[101];
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
    DFS(G, 0);printf("\n"); // @@ [The DFS and BFS before deletion should traverse the entire graph without skipping any vertex, but the program does not reset visited array properly before the first DFS call. However, since visited is globally initialized to 0, this may not be the main issue. The real problem is that after deletion, the traversal must skip the deleted vertex, but the current DFS/BFS functions do not accept a 'deleted vertex' parameter, so they cannot avoid it during traversal.]
    for(int i=0;i<=n;i++){
        visited[i] = 0;
    }
    BFS(G, 0);printf("\n"); // @@ [Same as above: BFS also lacks mechanism to skip the deleted vertex in the "after deletion" traversals. But more critically, the "before deletion" traversals are correct only because delnum hasn't been marked yet. However, the main bug is in the "after deletion" part.]
    for(int i=0;i<=n;i++){
        visited[i] = 0;
    }
    visited[delnum] = 1;
    DFS(G, 0);printf("\n"); // @@ [This marks delnum as visited to simulate deletion, which prevents DFS from visiting it. This is acceptable in principle, BUT: the BFS below does NOT mark delnum as visited before calling BFS, so BFS will still visit it. Also, note that the loop `for(int i=0;i<=n;i++)` goes up to index n (inclusive), but vertices are 0 to n-1, so it's writing beyond intended range, though harmless due to large visited array. The critical error is that BFS after deletion does not mark delnum as visited before traversal.]
    for(int i=0;i<=n;i++){
        visited[i] = 0;
    }
    BFS(G, 0);printf("\n"); // @@ [Here, visited[delnum] is 0 again because the previous loop reset all including delnum, so BFS will visit the deleted vertex. This causes the wrong output: expected "0 2", but got "0 1 2". The fix would be to set visited[delnum]=1 BEFORE this BFS call, just like was done for DFS.]
    return 0;
}