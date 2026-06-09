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
    if(G[v].link!=NULL) printf("%d ",v); // @@ The condition `G[v].link!=NULL` incorrectly prevents printing isolated vertices or the last remaining vertex if it has no edges (though problem says connected, after deletion logic might leave nodes with no edges if not handled, but primarily this check is redundant and potentially harmful if a valid vertex in a connected component somehow ends up with NULL link due to bug, but more importantly, standard DFS prints the node regardless of neighbors. However, the critical error is usually in traversal order or visitation. Let's look closer. Actually, if a node is isolated, it should still be printed if visited. But the main issue here is likely that `printf` should happen unconditionally upon visiting.)
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
        if(G[v].link!=NULL) printf("%d ",v);// @@ Similar to DFS, this condition incorrectly suppresses output for vertices that might have had their edges removed or are leaf nodes in a way that makes link NULL? No, leaf nodes have links. But if a vertex is isolated, it won't enter BFS usually. However, the standard requirement is to print the vertex when it is dequeued/visited. The condition `G[v].link!=NULL` is incorrect because a vertex should be printed simply because it is visited, regardless of whether it has outgoing edges.
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
        tail=head=0; // @@ Resetting head and tail inside the loop for each component is correct for separate BFS calls, but since we are iterating through all nodes to find unvisited ones, resetting the queue indices here is actually fine logically for a fresh BFS start, provided `head` and `tail` are global. However, typically queue reset happens once per BFS call. Here it resets for every unvisited node found. This is acceptable.
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
        for(p=q=G[i].link;p!=NULL;p=p->next) // @@ Logic error in linked list deletion. If the first node matches `k`, `q` and `p` are both the head. `q->next = p->next` updates head's next, but `G[i].link` (the head pointer itself) is not updated to skip the first element if the first element is the one to be deleted. Also, if `p` is the first node, `q` is also the first node, so `q->next` modifies the first node's next pointer, but doesn't change `G[i].link`.
        {
            if(p->adj==k) {
                q->next=p->next; // @@ If p is the head (first element), this line fails to update G[i].link. It only updates the next pointer of the current node (which is head). We need to handle the case where the head node itself needs to be removed.
            }
            q=p;
        }
    }
}