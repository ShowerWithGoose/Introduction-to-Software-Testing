#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MaxV 150
typedef struct edge{ 
    int adj;
    struct edge *next;
}ELink;
typedef struct ver{
    ELink *link;
}VLink;
VLink G[MaxV];
int visit[MaxV];
ELink *insertEdge(ELink *head,int a)
{
    ELink *e,*p,*q;
    e=(ELink *)malloc(sizeof(ELink));
    e->adj=a;
    e->next=NULL;
    if(head==NULL)
    {
        head=e;
        return head;
    }
    p=head;
    q=(ELink *)malloc(sizeof(ELink)); // @@ [Memory leak: allocated memory for q is not used correctly and never freed. Also, logic for insertion is flawed.]
    q->next=p;
    while(p!=NULL)
    {
        if(p->adj>a)
            break;
        p=p->next;
        q=q->next;
    }
    if(p==head)
    {
        e->next=p;
        head=e;
    }
    else if(p!=NULL)
    {
        e->next=q->next;
        q->next=e;
    }
    else
        q->next=e;
    return head;
}
void DFS(int x)
{
    ELink *p;
    visit[x]=1;
    printf("%d ",x);
    for(p=G[x].link;p!=NULL;p=p->next)
        if(!visit[p->adj])
            DFS(p->adj);
}
int queue[MaxV];
int empty(int a,int b)
{
    for(int i=a;i<=b;i++)
        if(queue[i]!=-1)
            return 1;
    return 0;
}
void BFS()
{
    memset(queue,-1,sizeof(int)*MaxV);
    ELink *p;
    visit[0]=1; 
    int rear=1,head=0;
    queue[++head]=0;
    while(empty(rear,head)!=0)
    {
        int v=queue[rear]; 
        rear++;
        printf("%d ",v);
        for(p=G[v].link;p!=NULL;p=p->next)
            if(!visit[p->adj]) 
            {
                visit[p->adj]=1;
                queue[++head]=p->adj;
            }
    }
}
int main()
{
    int n,edge,v1,v2,del;
    scanf("%d%d",&n,&edge);
    for(int i=0;i<edge;i++)
    {
        scanf("%d %d",&v1,&v2);
        G[v1].link=insertEdge(G[v1].link,v2);
        G[v2].link=insertEdge(G[v2].link,v1);
    }
    scanf("%d",&del);
    DFS(0);
    printf("\n");
    memset(visit,0,sizeof(int)*MaxV);
    BFS();
    printf("\n");
    G[del].link=NULL; // @@ [This only sets the deleted vertex's list to NULL but does not free the memory, causing a leak. More importantly, it doesn't remove edges pointing TO del from other vertices yet.]
    n--; // @@ [Decreasing n here is incorrect for the subsequent loop which iterates based on original vertex indices to clean up edges. The graph still has 'n' vertices conceptually until cleanup is done, and we need to iterate over all original vertices to remove references to 'del'.]
    for(int i=0;i<n;i++) // @@ [Loop bound should be the original number of vertices (before decrement) to ensure all vertices are checked for edges pointing to 'del'. Since n was decremented, the last vertex is skipped.]
    {
        ELink *p=NULL,*q;
        q=(ELink *)malloc(sizeof(ELink)); // @@ [Memory leak: q is allocated but its usage is part of a flawed deletion logic. It should likely be a pointer to the previous node, not a newly allocated node.]
        q->adj=-1;
        p=G[i].link;
        q->next=p;
        while(p!=NULL)
        {
            if(p->adj==del)
            {
                if(q->adj!=-1)
                    q->next=p->next;
                else
                    G[i].link=p->next;
                free(p);
                break;
            }
            p=p->next;
            q=q->next;
        }
    }
    memset(visit,0,sizeof(int)*MaxV);
    DFS(0);
    printf("\n");
    memset(visit,0,sizeof(int)*MaxV);
    BFS();
    printf("\n");
    return 0;
}