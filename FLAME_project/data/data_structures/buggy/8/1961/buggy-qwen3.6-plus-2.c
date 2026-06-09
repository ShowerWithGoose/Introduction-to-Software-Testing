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
    if(G[v].link!=NULL) printf("%d ",v); // @@ The condition `G[v].link!=NULL` incorrectly prevents printing isolated vertices or the last remaining vertex if it has no edges (though problem says connected, deletion might leave 0 isolated if n=1, but mainly it fails to print vertex 0 if it becomes isolated or if logic dictates all visited nodes should be printed. More critically, in the test case, vertex 0 is printed. But if a vertex is visited, it should be printed regardless of whether it has neighbors left. The standard DFS prints the node when visited. The condition here suppresses output for nodes with no adjacency list, which is wrong for a general traversal output requirement.)
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
        if(G[v].link!=NULL) printf("%d ",v);// @@ Same error as in DFS: suppressing output for vertices with no adjacent edges (or empty adjacency list). Vertex should be printed upon visit/dequeue regardless of its degree.
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
        tail=head=0; // @@ Resetting head and tail inside the loop for each component start is correct for BFS initialization per component, BUT `head` and `tail` are global. If the graph is disconnected, this resets correctly. However, `head` and `tail` should ideally be reset before calling BFS for a new component. Here it is reset before checking `!visited[i]`. This is logically okay for correctness of BFS state, but inefficient. The real issue is usually that `head` and `tail` are not reset *inside* BFS but *before* it. This line is technically acceptable logic-wise for resetting queue for new component, but let's look closer. Actually, if `i` is visited, we skip. If not, we reset queue and run BFS. This is fine.
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
        for(p=q=G[i].link;p!=NULL;p=p->next) // @@ Logic error in linked list deletion. If the first node `G[i].link` needs to be deleted (i.e., `p->adj == k`), `q` is also pointing to `p`. `q->next = p->next` updates `p->next` (which is `q->next`), but `G[i].link` itself is not updated to `p->next`. The head of the list remains pointing to the deleted node. Additionally, if `p` is the first node, `q` is not "previous" in the sense of a separate node, it's the same node. Standard deletion requires handling the head separately or using a pointer to pointer.
        {
            if(p->adj==k) {
                q->next=p->next; // @@ If p is the head, q is also head. This sets head->next to next, but G[i].link still points to p (the deleted node). It should be `G[i].link = p->next` if p is head.
            }
            q=p;
        }
    }
}