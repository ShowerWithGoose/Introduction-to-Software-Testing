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
    q=(ELink *)malloc(sizeof(ELink));
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
    queue[++head]=0; // @@ [Error: queue index logic is incorrect. The queue should start with rear=0 and head=0, and enqueue at queue[head] then increment head, or use rear to track the front. Here, queue[++head]=0 sets head=1 and queue[1]=0, but rear starts at 1, so the first dequeued element is queue[1] which is 0, but the empty function checks from rear to head inclusive, which is [1,1] and queue[1] is 0 (not -1), so it works accidentally. However, the logic is confusing and may cause issues with the empty function and queue management.]
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
    G[del].link=NULL;
    n--;
    for(int i=0;i<n;i++) // @@ [Error: The loop should iterate over all original vertices (0 to n-1 before deletion), not n-1 after decrementing n. Since n was decremented, this loop only goes to n-2 (original n-2), missing the last vertex. It should be for(int i=0;i<=n;i++) or use the original n value before decrement.]
    {
        ELink *p=NULL,*q;
        q=(ELink *)malloc(sizeof(ELink));
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