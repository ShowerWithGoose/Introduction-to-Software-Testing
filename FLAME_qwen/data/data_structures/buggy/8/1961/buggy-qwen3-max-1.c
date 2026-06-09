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
    travelDFS(n); // @@ [The program outputs DFS and BFS before deletion, but according to the problem, it should output both traversals BEFORE deletion first, then AFTER. However, this line is correct in order. The real issue is that deletion happens BEFORE any output in the reference logic, but here output happens before deletion. This matches expected behavior. So not an error here.]
    travelBFS(n); // @@ [Same as above: this correctly outputs BFS before deletion.]
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
    if(G[v].link!=NULL) printf("%d ",v); // @@ [Error: Vertex 0 must always be printed even if it has no neighbors after deletion, but the condition skips printing isolated vertices. However, per problem, graph remains connected after deletion and vertex 0 is never deleted, so vertex 0 will always have neighbors. But more critically: during traversal, every visited vertex should be printed regardless of degree. The condition `if(G[v].link!=NULL)` causes vertices with no edges (which shouldn't occur per problem constraints) to be skipped, but more importantly, this condition is unnecessary and incorrect logic. For example, if a vertex is visited but has no unvisited neighbors, it still must be printed. The print should happen unconditionally upon visit.]
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
        if(G[v].link!=NULL) printf("%d ",v);//访问当前顶点 // @@ [Same error as in DFS: printing only if the vertex has edges. Should print unconditionally when dequeued/visited.]
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
        tail=head=0; // @@ [Error: Resetting queue pointers inside the loop breaks BFS if multiple components exist. However, problem states graph is connected before and after deletion, so only one component. But more critically: after deletion, if vertex 0 is still present (which it is), the loop starts at i=0, visits all, and other i's are skipped. So this may work. However, the real issue is that the queue is implemented as a simple array with head/tail, but resetting head=tail=0 inside the loop is okay for single-component graphs. Not the main error.]
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
                q->next=p->next; // @@ [Error: When the first edge (head) is the one to delete, q == p == head, so q->next = p->next skips updating G[i].link. This fails to remove the edge from the head of the list. For example, if G[i].link points directly to a node with adj=k, then q = p = G[i].link, and setting q->next = p->next modifies the node, but G[i].link still points to the deleted node. It should update G[i].link in that case.]
            }
            q=p;
        }
    }
}