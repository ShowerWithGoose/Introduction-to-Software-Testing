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
    travelDFS(n); // @@ [Traversal before deletion should occur before reading the vertex to delete, but here it occurs after reading k. According to problem description and reference program, we must output sequences BEFORE deletion first, which requires performing traversals BEFORE reading the vertex to delete.]
    travelBFS(n); // @@ [Same issue as above: BFS before deletion is done after reading k, but should be done before.]
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
    if(G[v].link!=NULL) printf("%d ",v); // @@ [This condition skips printing isolated vertices (which shouldn't happen per problem constraints), but more critically, even if a vertex has no neighbors (after deletion), it should still be printed if visited. However, the bigger issue is that the traversal logic in travelDFS starts from every unvisited vertex, but the problem states the graph remains connected and traversal must start from vertex 0. This implementation may print multiple components or skip 0 if not handled properly. But the immediate visible error is that vertex 0 might not be printed if it becomes isolated after deletion, though problem says graph remains connected. However, the real critical flaw is in traversal order control. But the most evident bug is in the insertion logic below.]
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
    for(i=0;i<n;i++)  // @@ [The problem requires traversal to always start from vertex 0, but this loop starts from every unvisited vertex in order. Since the graph is connected, only i=0 should be used. Starting from other vertices leads to incorrect output when the deleted vertex disconnects parts (but problem says graph remains connected). However, the main issue is that it doesn't enforce starting only at 0. The reference program uses a single DFS/BFS call from 0 (with delv marked visited). This code does full traversal over all components, which violates requirement #3.]
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
        if(G[v].link!=NULL) printf("%d ",v);//访问当前顶点 // @@ [Same issue as DFS: skips printing vertex if it has no adjacent edges, which shouldn't happen per problem constraints but could after deletion. However, problem states graph remains connected after deletion and vertex 0 is never deleted, so 0 will always have neighbors. But if another vertex becomes isolated (which it won't per problem), this would skip it. However, the bigger issue is in traversal initiation.]
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
    for(int i=0;i<n;i++) // @@ [Same as travelDFS: should only start from vertex 0, not iterate through all vertices. This violates requirement #3.]
    {
        tail=head=0;
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
                q->next=p->next; // @@ [When the first edge (p == q == head) matches k, this sets q->next (which is head->next) correctly, but if p is the first node, q is also pointing to head, so this works. However, there's a bug when the first node is the one to delete: the loop initializes p=q=G[i].link, then if p->adj==k, it does q->next = p->next. But since q == p in this case, this sets p->next = p->next, which is harmless, but the head of the list is never updated. So if the first edge is the one to remove, G[i].link still points to the deleted node. This causes dangling pointer or incorrect traversal. The correct approach is to handle head removal separately.]
            }
            q=p;
        }
    }
}