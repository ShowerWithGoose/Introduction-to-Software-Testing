#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct edge
{
    int ad;
    struct edge *next;
}Elink;
typedef struct ver
{
    int vert;
    Elink *link;
}Vlink;
void dfs(Vlink s[],int v);
void bfs(Vlink s[],int v);
int visit[100];
int que[1000];
int front=-1,rear=-1;
int main()
{
    int ed,ve,de;
    int k=-1;
    int i=0;
     Vlink s[100];
     struct edge *p=NULL;
        struct edge* q=NULL;
            struct edge* r=NULL;
    scanf("%d%d",&ve,&ed);
    for(i=0;i<ve;i++)
    {
        s[i].vert=i;
        s[i].link=NULL;
    }
    for(i=0;i<ed;i++)
    {
        int a,b;
        int c,d;
        scanf("%d%d",&a,&b);
        p=(Elink*)malloc(sizeof(Elink));
        p->ad=b;
        p->next=NULL;
        if(!s[a].link)
        {
            s[a].link=p;
        }
        else
        {
            if(p->ad<s[a].link->ad)
            {
                p->next=s[a].link;
                s[a].link=p;
            }
            else
            {
                
                q=s[a].link;
                while(p->ad>q->ad&&q->next!=NULL)
                {
                    q=q->next;
                }
                p->next=q->next;
                q->next=p;
                
            }
        }
        r=(Elink*)malloc(sizeof(Elink));
        r->ad=a;
        r->next=NULL;
        if(!s[b].link)
        {
            s[b].link=r;
        }
        else
        {
            if(r->ad<s[b].link->ad)
            {
                r->next=s[b].link;
                s[b].link=r;
            }
            else
            {
                
                q=s[b].link;
                while(r->ad>q->ad&&q->next!=NULL)
                {
                    q=q->next;
                }
                r->next=q->next;
                q->next=r;
                
            }
        }
    }
    scanf("%d",&de);
    for(i=0;i<ve;i++)
    {
        visit[i]=0;
    }
    for(i=0;i<ve;i++)
    {
        if(visit[i]==0)
        {
            dfs(s,i);
        }
    }
    printf("\n");
    for(i=0;i<ve;i++)
    {
        visit[i]=0;
    }
    for(i=0;i<ve;i++)
    {
        if(visit[i]==0)
        {
            bfs(s,i);
        }
    }
    printf("\n");
    for(i=0;i<ve;i++)
    {
        visit[i]=0;
    }
    visit[de]=1; // @@ [Error: The vertex to be deleted should be removed from the graph, not just marked as visited. The adjacency lists of other vertices still contain edges to the deleted vertex, so traversals may incorrectly skip the deleted vertex but still consider its connections. The correct approach is to physically remove all edges incident to the deleted vertex from the adjacency lists before traversing.]
    for(i=0;i<ve;i++)
    {
        if(visit[i]==0)
        {
            dfs(s,i);
        }
    }
    printf("\n");
    for(i=0;i<ve;i++)
    {
        visit[i]=0;
    }
    visit[de]=1; // @@ [Same error as above: marking the deleted vertex as visited does not remove its edges from the graph. The BFS traversal will still encounter edges to the deleted vertex from other vertices, potentially causing incorrect traversal order or missing vertices.]
    for(i=0;i<ve;i++)
    {
        if(visit[i]==0)
        {
            bfs(s,i);
        }
    }
    printf("\n");
    return 0;
}
void dfs( Vlink s[],int v)
{
    int w;
    struct edge* q=NULL;
    printf("%d ",v);
    visit[v]=1;
    for(q=s[v].link;q!=NULL;q=q->next)
    {
        if(visit[q->ad]==0)
        {
            dfs(s,q->ad);
        }
    }
}
void bfs(Vlink s[],int v)
{
    int w;
    struct edge* q=NULL;
    printf("%d ",s[v].vert);
    visit[v]=1;
    que[++rear]=v;
    while(front!=rear)
    {
        v=que[++front];
        q=s[v].link;
        if(q==NULL)
        {
            w=-1;
        }
        else
        {
            w=q->ad;
        }
        while(w!=-1)
        {
            if(visit[w]==0)
            {
                printf("%d ",s[w].vert);
                que[++rear]=w;
                visit[w]=1;
            }
            q=q->next;
            if(q==NULL)
        {
            w=-1;
        }
        else
        {
            w=q->ad;
        }
        }
    }
}