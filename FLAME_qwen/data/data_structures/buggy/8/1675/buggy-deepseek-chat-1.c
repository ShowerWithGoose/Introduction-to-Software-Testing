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
    queue[++head]=0; // @@ [Error: queue index logic is incorrect. The queue should start with rear=0 and head=0, then enqueue at queue[head] and dequeue from queue[rear]. The current implementation uses rear as the dequeue index and head as the enqueue index, but initializes rear=1 and head=0, causing the first element to be stored at queue[1] and dequeued from queue[1] incorrectly. Also, the empty() function checks from a to b, but with rear=1 and head=0, the first enqueue at queue[1] means the queue is not empty, but the dequeue starts at rear=1, which is correct for the first element, but the logic is confusing and likely leads to incorrect traversal order or missing vertices.]
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
    for(int i=0;i<n;i++) // @@ [Error: The loop condition i < n is incorrect because after deleting a vertex, the number of vertices is n-1, but the loop should iterate over all original vertices (0 to n-1) to remove edges to the deleted vertex. Using i < n (which is now n-1) will miss the last vertex (index n-1) if it exists. The correct loop should be i < vertex (original n) or i <= n (since n was decremented).]
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