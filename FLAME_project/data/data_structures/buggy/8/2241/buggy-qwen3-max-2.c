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
    DFS(G, 0);printf("\n");
    for(int i=0;i<=n;i++){
        visited[i] = 0;
    }
    BFS(G, 0);printf("\n");
    for(int i=0;i<=n;i++){
        visited[i] = 0;
    }
    visited[delnum] = 1;
    DFS(G, 0);printf("\n"); // @@ [The DFS function does not skip the deleted vertex during traversal; it only marks it as visited before calling DFS, but DFS itself doesn't check if a neighbor is the deleted vertex. However, the real issue is that the BFS after deletion also fails to skip the deleted vertex properly because the graph structure still includes edges to the deleted vertex. But more critically, in the BFS implementation, the starting vertex is printed before being marked visited and enqueued, which causes inconsistency when the deleted vertex is involved. However, looking at the test output, the main bug is that in the second BFS (after deletion), the program outputs "0 1 2" instead of "0 2". This happens because the BFS function visits and prints the current vertex before checking if it's the deleted one. But actually, the deleted vertex is already marked as visited before calling BFS, so it shouldn't be traversed. The real problem is that the BFS function starts by printing and marking the start vertex (0) without checking if it's deleted—but 0 is never deleted per problem constraints. The actual bug is that the BFS function processes neighbors without considering that some neighbors might be the deleted vertex. However, since the deleted vertex is marked as visited before BFS is called, those neighbors won't be enqueued. But in the test case, after deleting vertex 1, vertex 0 is connected to 1 and 2. When BFS starts at 0, it prints 0, then looks at neighbors: 1 (visited, so skipped) and 2 (not visited, so printed and enqueued). Then from 2, neighbors are 0 (visited) and 1 (visited), so nothing more. So BFS should print "0 2". But the buggy output shows "0 1 2", meaning vertex 1 was printed. That implies that vertex 1 was not properly marked as visited before BFS. Looking at the code: before the second BFS, it does `for(int i=0;i<=n;i++){ visited[i] = 0; }` then `BFS(G, 0);`. Wait, no: the code before the second BFS is:
    for(int i=0;i<=n;i++){
        visited[i] = 0;
    }
    visited[delnum] = 1;
    DFS(G, 0);printf("\n");
    for(int i=0;i<=n;i++){
        visited[i] = 0;
    }
    BFS(G, 0);printf("\n");
So before the second BFS, it resets visited to all 0, then does NOT mark delnum as visited! That's the bug. The DFS after deletion correctly sets visited[delnum]=1 before calling DFS, but the BFS after deletion does not. So during BFS, vertex 1 (delnum=1) is not marked as visited, so when 0's neighbor 1 is considered, it's not visited, so it gets printed and enqueued. Hence the wrong output "0 1 2" instead of "0 2".]
    for(int i=0;i<=n;i++){
        visited[i] = 0;
    } // @@ [This loop resets the visited array to all zeros before the final BFS, but it fails to mark the deleted vertex (delnum) as visited. As a result, during BFS traversal, the deleted vertex is treated as unvisited and gets included in the output, which is incorrect. The deleted vertex should be permanently excluded from traversal by marking it as visited before starting BFS.]
    BFS(G, 0);printf("\n");
    return 0;
}