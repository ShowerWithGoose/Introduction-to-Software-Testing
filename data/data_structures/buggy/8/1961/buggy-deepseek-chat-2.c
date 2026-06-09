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
        for(p=head;p->next!=NULL && p->next->adj<v;p=p->next); // @@ [Error: When inserting into a sorted linked list, the loop condition should check p->next->adj < v, but if the new vertex v is smaller than the first element (head->adj), this loop will not execute correctly because p starts at head and checks p->next, so it will never insert before the head. The correct approach is to handle insertion before head separately, or use a different loop structure.]
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
    if(G[v].link!=NULL) printf("%d ",v); // @@ [Error: The condition `if(G[v].link!=NULL)` incorrectly suppresses output for isolated vertices. According to the problem, all vertices should be printed during traversal, even if they have no adjacent edges. This condition should be removed so that vertex v is always printed.]
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
        if(G[v].link!=NULL) printf("%d ",v);//访问当前顶点 // @@ [Error: Same issue as in DFS - the condition `if(G[v].link!=NULL)` incorrectly suppresses output for isolated vertices. This condition should be removed so that vertex v is always printed.]
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
        tail=head=0; // @@ [Error: Resetting tail and head inside the loop is incorrect. This causes the queue to be reinitialized for each starting vertex, but the visited array is not reset, so BFS will only run once. The queue should be initialized once before the loop, or the loop should be restructured to avoid resetting the queue for each component.]
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
        for(p=q=G[i].link;p!=NULL;p=p->next) // @@ [Error: In the inner loop, `q` is not properly initialized before the loop. When `p` points to the first node, `q` is also set to that node, but if the first node is the one to be deleted, `q->next` would be invalid. Additionally, the deletion logic `q->next=p->next` is incorrect because it does not update the head pointer of the list when the first node is deleted. The correct approach is to handle deletion of the first node separately or use a pointer to pointer.]
        {
            if(p->adj==k) {
                q->next=p->next; // @@ [Error: This line attempts to remove node p by linking q->next to p->next, but if p is the first node, q equals p, so q->next is p->next, which does not actually remove p from the list. Also, the head pointer G[i].link is never updated when the first node is deleted.]
            }
            q=p;
        }
    }
}