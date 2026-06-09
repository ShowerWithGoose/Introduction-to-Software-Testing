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
void  travelBFS(struct ver  G[ ], int n);
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
        printf("%d ",dui[k]);
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
        printf("%d ",dui[k]);
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
        if(p->adj<avex&&p->next->adj>avex)
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
void BFS(struct ver  G[ ], int v)
{
    struct edge  *p;
    Visited[v] = 1; //标识某顶点已入队
    dui[last]=v; // @@ [This line enqueues the vertex v again in recursive calls, causing duplicate entries and potential infinite loop. The BFS should enqueue only when first discovering a vertex, not when processing it.]
    last++;
         v = dui[first];
         first++;  //取出队头元素
         for(p=G[v].link; p!=NULL; p=p->next ) //访问该顶点的每个邻接顶点
             if(Visited[p->adj]==0 ) {
                    Visited[p->adj] = 1; //标识某顶点入队
                    dui[last]=p->adj;
                    last++;
           }
    BFS(G,dui[first]); // @@ [This recursive call lacks a base case for an empty queue, leading to out-of-bounds access when first equals last. Additionally, due to the duplicate enqueue above, this recursion may never terminate properly.]
}
void  travelBFS(struct ver  G[ ], int n)
{
    int i;
    for(i=0; i<n; i++)
        if(Visited[i]==0) BFS(G,i);
}