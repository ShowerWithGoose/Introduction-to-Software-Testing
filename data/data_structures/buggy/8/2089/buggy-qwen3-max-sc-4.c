#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct edge{ 
       int  adj;
       int  wei;
       struct edge*next;
};
struct ver{
       struct edge* link;
};
struct ver g[105];
int  Visited[105]={0};
int dui[105],first=0,last=0;
struct edge  *insertEdge(struct edge *head, int avex);
void  travelDFS(struct ver  G[ ], int n);
void  travelBFS(struct ver  G[ ], int n);
void  travelBFS(struct ver  G[ ], int n); // @@ [Duplicate function declaration: 'travelBFS' is declared twice, which is unnecessary but not a compilation error by itself. However, it indicates possible confusion in code structure.]
void DFS(struct ver  G[ ], int v);
int main()
{
    int ndian,nbian,a1,a2,shan;
    scanf("%d %d",&ndian,&nbian);
    for(int i=0;i<nbian;i++)
    {
        scanf("%d %d",&a1,&a2);
        //printf("%d %d\n",a1,a2);
        g[a1].link=insertEdge(g[a1].link, a2);
        g[a2].link=insertEdge(g[a2].link, a1);
    }
    scanf("%d",&shan);
    //struct edge*p;
    //for(p=g[5].link; p!= NULL; p=p->next)
    //printf("%d\n",p->adj);
    //
    for(int i=0; i<ndian; i++) Visited[i] = 0 ;
    travelDFS(g,ndian);
    printf("\n");
    //
    for(int i=0; i<ndian; i++) Visited[i] = 0 ;
    travelBFS(g,ndian);
    for(int k=0;k<ndian;k++)
    {
        printf("%d ",dui[k]); // @@ [Incorrect BFS output logic: The BFS traversal result should be printed during traversal, not by dumping the entire 'dui' array afterward. This leads to wrong output format and content.]
    }
    printf("\n");
    //
    for(int i=0; i<ndian; i++) Visited[i] = 0 ;
    Visited[shan] =1 ;
    travelDFS(g,ndian);
    printf("\n");
    //
    for(int i=0; i<ndian; i++)
    {
        Visited[i] = 0 ;
        dui[i]=-1;
    }
    first=0;
    last=0;
    Visited[shan] =1 ;
    travelBFS(g,ndian);
    for(int k=0;k<ndian;k++)
    {
        if(dui[k]!=-1)
        printf("%d ",dui[k]); // @@ [Same issue as above: BFS result is incorrectly printed from 'dui' array instead of during traversal. Also, after deletion, some entries may remain from previous runs if not fully cleared.]
    }
    printf("\n");
}
struct edge  *insertEdge(struct edge *head, int avex)
{
    struct edge *e,*p;
    int t=0;
    e =(struct edge *)malloc(sizeof(struct edge));
    e->adj= avex; e->wei=1; e->next = NULL;
    if(head == NULL)  { head=e; return head; }
    if(avex<head->adj)
    {
        e->next=head;
        return e;
    }else 
    {
    for(p=head; p->next != NULL; p=p->next)
    {
        if(p->adj<avex&&p->next->adj>avex) // @@ [Logic flaw in insertion sort: It assumes list is sorted, but condition 'p->adj < avex' is always true in a sorted list, so this check is redundant and may skip correct insertion point. Should compare only with next node. Also, fails to handle case where avex equals existing node (though problem says no duplicate edges).]
        {
            e->next=p->next;
            p->next=e;
            t=1;
            break;
        }
    }
    if(t==0) p->next = e;  
    return head;
    }
}
void  travelDFS(struct ver G[ ], int n)
{
    int i;
    for(i=0; i<n; i++)
        if(Visited[i]==0) DFS(G, i);
}
void DFS(struct ver G[ ], int v)
{
    struct edge  *p;
    Visited[v] = 1; //标识某顶点被访问过
    printf("%d ",v);
    for(p = G[v].link; p !=NULL;  p=p->next)
         if(Visited[p->adj]==0)
             DFS(G, p->adj);
}
void BFS(struct ver  G[ ], int v) // @@ [Recursive BFS implementation is fundamentally flawed: BFS should be iterative using a queue. This recursive approach does not correctly simulate BFS order and will cause stack overflow or incorrect traversal. Also, queue state ('first', 'last') is global and gets corrupted across calls.]
{
    struct edge  *p;
    Visited[v] = 1; //标识某顶点已入队
    dui[last]=v;
    last++;
         v = dui[first];
         first++;  //取出队头元素
         for(p=G[v].link; p!=NULL; p=p->next ) //访问该顶点的每个邻接顶点
             if(Visited[p->adj]==0 ) {
                    Visited[p->adj] = 1; //标识某顶点入队
                    dui[last]=p->adj;
                    last++;
           }
    BFS(G,dui[first]); // @@ [Recursive call uses 'dui[first]' which may be out of bounds or uninitialized, leading to undefined behavior. Also, recursion depth equals number of vertices, which may exceed stack limit.]
}
void  travelBFS(struct ver  G[ ], int n)
{
    int i;
    for(i=0; i<n; i++)
        if(Visited[i]==0) BFS(G,i); // @@ [Because BFS is implemented recursively and uses global queue state, multiple calls (e.g., if graph were disconnected) would corrupt traversal. But problem states graph is connected, so this may not trigger error, but design is still wrong.]
}