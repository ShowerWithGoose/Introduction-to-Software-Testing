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
        for(p=head;p->next!=NULL && p->next->adj<v;p=p->next); // @@ [Incorrect insertion order when list has exactly one node and v is larger than that node. The loop exits with p still pointing to head, but the code then inserts before head, which is wrong; should insert after head.]
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
    if(G[v].link!=NULL) printf("%d ",v); // @@ [This condition may skip printing a vertex if its adjacency list becomes empty (e.g., after deletion the deleted vertex has NULL link, but that is correct; however, in standard DFS/BFS all vertices visited are printed. While it works for the given connected graph, it is not robust and differs from the reference implementation.]
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
        if(G[v].link!=NULL) printf("%d ",v); // @@ [Same issue as in DFS: this condition may omit printing a vertex, though it works for the given graph. It is inconsistent with the reference program and may lead to missing vertices if the graph structure changes.]
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
        for(p=q=G[i].link;p!=NULL;p=p->next) // @@ [If the first node is k, the head (G[i].link) is not updated, leaving a dangling pointer to the deleted node. Also, when a node is removed, the assignment `q=p;` at the end updates q to the removed node, corrupting the previous pointer for subsequent iterations.]
        {
            if(p->adj==k) {
                q->next=p->next; // @@ [This does not handle removal of the first node; it also does not break after removal, but the real issue is missing head update and incorrect q update.]
            }
            q=p; // @@ [This should only be executed when no removal occurs; otherwise q points to the removed node, breaking future deletions.]
        }
    }
}