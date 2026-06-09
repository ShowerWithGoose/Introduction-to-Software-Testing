#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct  edge{ 
       int  adj;
       int  wei;
       struct edge *next;
}Elink;
typedef struct ver{
       Elink *link;
}Vlink;
Vlink graph[103];
Elink  *insertEdge(Elink *head, int avex);
int Visited[103];
void  travelDFS(Vlink  G[ ], int n);
void DFS(Vlink  G[ ], int v);
void BFS(Vlink  G[ ], int v);
void  travelBFS(Vlink  G[ ], int n);
void  travelDFS1(Vlink  G[ ], int n);
void DFS1(Vlink  G[ ], int v);
void BFS1(Vlink  G[ ], int v);
void  travelBFS1(Vlink  G[ ], int n);
int dui[103];
int start=0;
int end=-1;
int dui1[103];
    int shan;
int main()
{

    
    int m,n;
    scanf("%d %d",&m,&n); // @@ The input format specifies n (vertices) then m (edges), but the code reads m then n. This swaps the meaning of the variables.
    int i,j,k;
    int v1,v2;
    for(i=0;i<n;i++) // @@ Since m and n were swapped in scanf, this loop runs 'edges' times instead of 'vertices' times? No, wait. If input is "3 3", m=3, n=3. It works by accident for square inputs. But logically, the loop should run m times (number of edges). The variable 'n' here holds the number of edges due to the swap.
    {
        scanf("%d %d",&v1,&v2);
        graph[v1].link=insertEdge(graph[v1].link, v2);
        graph[v2].link=insertEdge(graph[v2].link, v1);
    }
    travelDFS(graph,m); // @@ Passing 'm' (which actually holds vertex count due to swap) as the size 'n' for traversal. If the swap wasn't there, this would be wrong because m is edges. With the swap, m is vertices. So this passes the vertex count. This is consistent with the variable swap error.
    printf("\n");
    for(i=0;i<m;i++)
    {
        Visited[i]=0;
    }
    travelBFS(graph,m);
    printf("\n");
    scanf("%d",&shan);
    Elink *e,*p,*r;
    for(i=0;i<m;i++)
    {
        if(i!=shan)
        {
            for(p=graph[i].link;p!=NULL;p=p->next)
            {
                if(p->adj==shan)
                {
                    if(p->next==NULL)
                    {
                        r->next=NULL; // @@ Logic error: This attempts to remove the last node by setting the previous node's next to NULL. However, 'r' might be uninitialized if the match is the first node, or logic is flawed for middle nodes. More importantly, it doesn't handle the case where the node to delete is the head of the list.
                    }
                    else
                    {
                       ; // @@ Logic error: If the node to delete is not the last one (i.e., it has a next node), this block does nothing. The node is not removed from the linked list.
                    }
                }
                r=p;
            }
            
        }
    }
    for(i=0;i<m;i++)
    {
        Visited[i]=0;
    }
    travelDFS1(graph,m);
    printf("\n");
    start=0;
    end=-1;
    for(i=0;i<m;i++)
    {
        Visited[i]=0;
    }
    travelBFS1(graph,m);
    return 0;
} 
Elink  *insertEdge(Elink *head, int avex)
{
    Elink *e,*p,*r;
    e =(Elink *)malloc(sizeof(Elink));
    e->adj= avex; e->wei=1; e->next = NULL;
    if(head == NULL)  { head=e; return head; }
    for(p=head; p!=NULL; p=p->next)
    {
        if(p->adj>e->adj)
        {
            break;
        }
        r=p;
    }
    if(p==head)
    {
        e->next=p;
        head=e;
    }
    else if(p==NULL)
    {
        r->next=e;
    }
    else
    {
        r->next=e;
        e->next=p;
    }
    return head;
}
void  travelDFS(Vlink  G[ ], int n)
{
    int i;
    for(i=0; i<n; i++) Visited[i] = 0 ;
    for(i=0; i<n; i++)
        if( !Visited[i] ) DFS(G, i);
}
void DFS(Vlink  G[ ], int v)
{
    Elink  *p;
    Visited[v] = 1; //标识某顶点被访问过
    printf("%d ",v);
    for(p=G[v].link;p!=NULL;p=p->next)
         if( !Visited[p->adj] )
             DFS(G, p->adj);
}
void  travelBFS(Vlink  G[ ], int n)
{
    int i;
    for(i=0; i<n; i++) Visited[i] = 0 ;
    for(i=0; i<n; i++)
        if( !Visited[i] ) BFS(G, i);
}
void BFS(Vlink  G[ ], int v)
{
    Elink  *p;
    Visited[v] = 1; //标识某顶点已入队
    dui[++end]=v;
    while(end-start>=0){
         v = dui[start++];  //取出队头元素
         printf("%d ",v); //访问当前顶点
         for(p=G[v].link; p!=NULL; p=p->next ) //访问该顶点的每个邻接顶点
             if( !Visited[p->adj] ) {
                    Visited[p->adj] = 1; //标识某顶点入队
                    dui[++end]=p->adj;
           }
     }
 }
void  travelDFS1(Vlink  G[ ], int n)
{
    int i;
    for(i=0; i<n; i++) Visited[i] = 0 ;
    for(i=0; i<n; i++)
        if( !Visited[i]&&i!=shan ) DFS1(G, i);
}
void DFS1(Vlink  G[ ], int v)
{
    Elink  *p;
    Visited[v] = 1; //标识某顶点被访问过
    if(v!=shan)
    {
        printf("%d ",v);
    }
    for(p=G[v].link;p!=NULL;p=p->next)
         if( !Visited[p->adj] )
             DFS1(G, p->adj);
}
void  travelBFS1(Vlink  G[ ], int n)
{
    int i;
    for(i=0; i<n; i++) Visited[i] = 0 ;
    for(i=0; i<n; i++)
        if( !Visited[i]&&i!=shan) BFS1(G, i);
}
void BFS1(Vlink  G[ ], int v)
{
    Elink  *p;
    Visited[v] = 1; //标识某顶点已入队
    dui1[++end]=v;
    while(end-start>=0){
         v = dui1[start++];  //取出队头元素
         if(v!=shan)
         {
             printf("%d ",v);
         }
          //访问当前顶点
         for(p=G[v].link; p!=NULL; p=p->next ) //访问该顶点的每个邻接顶点
             if( !Visited[p->adj] ) {
                    Visited[p->adj] = 1; //标识某顶点入队
                    dui1[++end]=p->adj;
           }
     }
 }