#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define MAXV 1000
typedef struct edge
{
    int adj;
    struct edge *next;
}Elink;
typedef struct ver{
    int vertex;
    Elink *link;
}Vlink; 
Vlink G[MAXV];
int visited[MAXV],Q[MAXV];
int head=0,tail=0;
Elink* insertEdge(Elink *head,int v);
void creatEdge(Vlink G[],int m);
void deleteEdge(int n,int k);
void DFS(Vlink G[],int v);
void travelDFS(int n);
void BFS(Vlink G[],int v);
void travelBFS(int n);
int main()
{
    int m,n;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) G[i].link=NULL;
    creatEdge(G,m);
    int k;
    scanf("%d",&k);
    travelDFS(n);
    travelBFS(n);
    deleteEdge(n,k);
    travelDFS(n);
    travelBFS(n);
    return 0;
}
Elink* insertEdge(Elink *head,int v)
{
    Elink *e,*p;
    e=(Elink*)malloc(sizeof(Elink));
    e->next=NULL;
    e->adj=v;
    if(head==NULL){
        head=e;
        return head;
    }
    else {
        for(p=head;p->next!=NULL && p->next->adj<v;p=p->next); // @@ [Error: When inserting into a non-empty list, if the new vertex v is smaller than the first element, the loop condition p->next->adj<v will fail because p starts at head and p->next is not NULL, but the loop will not execute, and then the code inserts after p (head) instead of before head. This causes incorrect ordering when v is smaller than the first element. The correct logic should handle insertion at the head separately.]
        e->next=p->next;
        p->next=e;
        return head;
    }
}
void creatEdge(Vlink G[],int m)
{
    int v1,v2;
    while(m--)
    {
        scanf("%d%d",&v1,&v2);
        G[v1].link=insertEdge(G[v1].link,v2);
        G[v2].link=insertEdge(G[v2].link,v1);
    }
}
void DFS(Vlink G[],int v)
{
    Elink *p;
    visited[v]=1;
    if(G[v].link!=NULL) printf("%d ",v); // @@ [Error: This condition causes vertex 0 to not be printed if it has no outgoing edges (but the graph is connected, so it should have edges). However, the main issue is that if a vertex has no adjacent vertices (e.g., after deletion, a vertex might become isolated? But problem says graph remains connected after deletion, so this is not the main error. The real error is that this condition incorrectly suppresses output for vertices that have no edges, but in a connected graph all vertices have at least one edge. However, the bigger issue is that the condition is unnecessary and can cause missing output if a vertex's link is NULL due to deletion logic. The correct approach is to always print the vertex when visited.]
    for(p=G[v].link;p!=NULL;p=p->next)
    {
        if(!visited[p->adj]) {
            DFS(G,p->adj);
        } 
    }
}
void travelDFS(int n)
{
    int i;
    for(i=0;i<n;i++) visited[i]=0;
    for(i=0;i<n;i++) 
        if(!visited[i]) DFS(G,i);
    printf("\n");
}
void BFS(Vlink G[],int v)
{
    Elink *p;
    visited[v]=1;
    Q[tail++]=v;
    while(head<tail)
    {
        v=Q[head++];//从队列取出元素
        if(G[v].link!=NULL) printf("%d ",v);//访问当前顶点 // @@ [Error: Same issue as in DFS - this condition may suppress printing of vertices that have no outgoing edges. In a connected graph, all vertices have edges, but after deletion, the deleted vertex's link is set to NULL, but it is not visited because visited[delv] is not set. However, the condition is still incorrect because it could skip printing a vertex that has no edges (which shouldn't happen in a connected graph, but the code's logic is flawed). The correct approach is to always print the vertex when it is dequeued.]
        for(p=G[v].link;p!=NULL;p=p->next)
        {
            if(!visited[p->adj])
            {
                visited[p->adj]=1;
                Q[tail++]=p->adj;
            }
        }
    }
}
void travelBFS(int n)
{
    for(int i=0;i<n;i++) visited[i]=0;
    for(int i=0;i<n;i++)
    {
        tail=head=0; // @@ [Error: Resetting head and tail inside the loop is incorrect. This causes the queue to be reinitialized for each starting vertex, but the visited array is not reset, so BFS will only run for the first unvisited vertex. However, the problem requires traversing all vertices starting from 0, and since the graph is connected, only one BFS call is needed. But if the graph were disconnected (which it is not), this would be wrong. The main issue is that resetting head and tail here is unnecessary and can cause problems if multiple BFS calls are made (though in a connected graph only one call happens). The correct approach is to initialize head and tail once before the loop.]
        if(!visited[i]) BFS(G,i);
    }
    printf("\n");
}
void deleteEdge(int n,int k)
{
    G[k].link=NULL;
    Elink *p,*q;
    int i;
    for(i=0;i<n;i++)
    {
        for(p=q=G[i].link;p!=NULL;p=p->next) // @@ [Error: The initialization p=q=G[i].link is incorrect. If G[i].link is NULL, then p and q are NULL, and the loop condition p!=NULL fails immediately, which is fine. But if the first edge's adj equals k, then q is not updated before the deletion, causing q to be NULL when trying to set q->next. This leads to a segmentation fault. The correct approach is to handle the case where the first edge is the one to delete separately, or use a different pointer management strategy.]
        {
            if(p->adj==k) {
                q->next=p->next; // @@ [Error: If p is the first node (q is NULL), this dereferences NULL pointer, causing a crash.]
            }
            q=p;
        }
    }
}