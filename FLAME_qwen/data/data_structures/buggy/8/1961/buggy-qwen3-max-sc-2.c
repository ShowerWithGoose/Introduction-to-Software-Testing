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
        for(p=head;p->next!=NULL && p->next->adj<v;p=p->next);
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
    if(G[v].link!=NULL) printf("%d ",v); // @@ [Incorrect condition: vertex 0 should always be printed even if it has no neighbors after deletion, but more critically, isolated vertices (like after deletion) might not be printed at all. However, the real issue is that the problem requires traversal starting from 0 and visiting all reachable nodes, but this condition skips printing vertices with no edges, which violates output requirements.]
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
        if(G[v].link!=NULL) printf("%d ",v);//访问当前顶点 // @@ [Same error as in DFS: vertices with no edges (like possibly after deletion) won't be printed, but they should be included in traversal if reachable (and since graph remains connected and we start from 0, all non-deleted vertices must be printed).]
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
        tail=head=0; // @@ [Resetting queue pointers inside loop causes BFS to restart queue for each unvisited component, but since graph is connected, only one component exists. However, after deletion, if vertex 0 is still present, we must start from 0 only. The loop from i=0 to n-1 will attempt BFS on every unvisited node, but problem requires starting from 0 always. So if i>0 and visited[0] is already set, it's okay, but if 0 is unvisited, it starts at 0. However, the bigger issue is that after deletion, if the deleted vertex is marked as visited implicitly by removing its edges, but not skipped in the loop, it might try to BFS on deleted vertex if not handled. But the main logical error is that traversal must always start from vertex 0, not from every unvisited vertex. The loop should only start from 0, not iterate over all vertices.]
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
        for(p=q=G[i].link;p!=NULL;p=p->next)
        {
            if(p->adj==k) {
                q->next=p->next; // @@ [When the first edge (head) is the one to delete, q equals p initially, so q->next = p->next effectively does nothing because q is p. This fails to update G[i].link when the first node is the target. Should handle head deletion separately.]
            }
            q=p;
        }
    }
}