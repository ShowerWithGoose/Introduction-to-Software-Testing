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
    travelDFS(n); // @@ [The problem requires outputting traversal sequences BEFORE deletion first, but this code outputs DFS and BFS before reading the vertex to delete. However, the vertex `k` is read BEFORE calling travelDFS/travelBFS, so this part is actually correct. The real issue is in DFS/BFS printing condition.]
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
    if(G[v].link!=NULL) printf("%d ",v); // @@ [This condition skips printing isolated vertices (degree 0). But after deletion, a vertex might become isolated yet still needs to be printed if it's reachable (and graph remains connected per problem, so vertex 0 must be printed even if it had only one edge to deleted vertex). Also, before deletion, all vertices are connected, so no isolated vertices, but after deletion, the graph is still connected, so vertex 0 must appear. However, if vertex 0 becomes isolated after deletion (which shouldn't happen per problem constraints), this would skip it. More critically: the problem says start from 0 and traverse connected component. Since graph is connected, we should always print all non-deleted vertices. But this condition prevents printing a vertex with no edges, which violates the requirement to output the sequence of visited vertices regardless of degree.]
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
        if(!visited[i]) DFS(G,i); // @@ [The problem states traversal must start from vertex 0. This loop starts from 0, but if vertex 0 is marked visited (e.g., after deletion if 0 was connected only to deleted vertex and now isolated), it might skip. However, the bigger issue is that after deletion, the graph is still connected, so only one component exists, and we must start at 0. But this loop will start at 0 only if not visited. However, the real error is in DFS printing condition above.]
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
        if(G[v].link!=NULL) printf("%d ",v);//访问当前顶点 // @@ [Same error as in DFS: skips printing vertices with no edges (degree 0). Even if a vertex has no edges, if it's part of the traversal (i.e., it's the starting vertex 0 and the graph has only one vertex after deletion), it must be printed. Problem states graph remains connected after deletion, so if n>1 after deletion, 0 must have edges, but if original n=3 and delete one neighbor of 0, 0 might still have other edges. However, the condition is logically wrong because traversal should print every visited vertex, regardless of its degree.]
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
        if(!visited[i]) BFS(G,i); // @@ [Same as DFS: should only start from 0, not loop through all vertices. But since graph is connected, only i=0 will be unvisited. However, the printing condition inside BFS is the critical error.]
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
                q->next=p->next; // @@ [When the first edge (head) is the one to delete, q is set to head initially, so q->next = p->next would work only if q is the previous node. But when p is the first node (p == G[i].link), then q == p, so q->next = p->next sets G[i].link->next, but doesn't update G[i].link itself. Thus, if the first adjacent vertex is k, it won't be removed from the list because G[i].link still points to the deleted node. This causes the deleted vertex to still appear in adjacency lists, leading to incorrect traversal.]
            }
            q=p;
        }
    }
}