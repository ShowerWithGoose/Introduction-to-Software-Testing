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
    travelDFS(n); // @@ [Traversal before deletion should be done before reading k, but k is read before first traversal]
    travelBFS(n); // @@ [Same issue: first traversals must occur before deleting vertex k, but k hasn't been used for deletion yet — however, the real error is that deletion happens AFTER these calls, which is correct. The actual bug is elsewhere.]
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
    if(G[v].link!=NULL) printf("%d ",v); // @@ [Vertex 0 must always be printed even if it has no neighbors after deletion, but condition skips printing isolated vertex 0. However, problem states graph remains connected after deletion and vertex 0 is never deleted, so G[0].link won't be NULL. But more critically: in a connected graph with ≥3 vertices, vertex 0 must have at least one neighbor, so this may not be the core issue.]
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
        if(!visited[i]) DFS(G,i); // @@ [Traversal must start from vertex 0 only, but this loops over all unvisited vertices. Problem requires starting from 0 and graph is connected, so only one component exists. However, after deletion, if implementation marks deleted vertex as visited, this loop might skip 0 if 0 were deleted—but 0 is never deleted. Still, the loop is unnecessary and wrong: should call DFS(G,0) directly.]
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
        if(G[v].link!=NULL) printf("%d ",v);//访问当前顶点 // @@ [Same issue as DFS: conditionally prints vertex only if it has neighbors, but vertex should always be printed when visited. In a connected graph with ≥3 nodes and 0 not deleted, 0 will have neighbors, but after deletion, other vertices might become leaves but still must be printed. However, the real problem is in traversal initiation.]
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
        tail=head=0;
        if(!visited[i]) BFS(G,i); // @@ [Same critical error as travelDFS: must start only from vertex 0, not iterate over all vertices. Graph is connected, so only one component, but this loop causes multiple BFS calls if there were disconnected components (which there aren't), but more importantly, it doesn't enforce starting at 0. If by chance vertex 0 is visited later in the loop, order breaks. But since graph is connected and we reset visited, the first i=0 will trigger BFS from 0 and mark all, so subsequent i won't trigger. So this may actually work. However, the specification says "start from vertex 0", so this loop is logically incorrect even if it works by accident.]
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
                q->next=p->next; // @@ [When the first edge (head) is the one to delete, q equals p (both point to head), so q->next = p->next skips correctly? Let's see: initially q = p = head. If p->adj == k, then q->next = p->next → head->next = p->next, but we need to update G[i].link to p->next. This fails to update the head pointer when the first node is deleted.]
            }
            q=p;
        }
    }
}