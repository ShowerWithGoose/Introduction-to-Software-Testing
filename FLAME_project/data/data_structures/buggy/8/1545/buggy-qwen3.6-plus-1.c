#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int flag=-1;//用来标记删除的点
struct edge
{
    int adj;
    struct edge *next;
};
struct ver
{
    struct edge *link;
};
struct ver G[105]={};
struct edge *inserted(struct edge *head,int inf)//先小后大逐个插入
{
    struct edge *e,*p,*h;
    p=(struct edge *)malloc(sizeof(struct edge)); // @@ Memory leak: 'p' is allocated but not used correctly in all paths, and often overwritten or lost. Also, 'h' is allocated but logic for insertion is flawed.
    e=(struct edge *)malloc(sizeof(struct edge));
    h=(struct edge *)malloc(sizeof(struct edge)); // @@ Memory leak: 'h' is allocated but its usage is inconsistent and leads to leaks or incorrect linking.
    e->adj=inf;
    e->next=NULL;
    if(head==NULL)
    {
        head=e;
        return head;
    }
    else
    {
        if(head->adj>inf)//循环的特例
        {
            e->next=head;
            return e;
        }
            else
        {
            for(p=head,h=NULL;p->next!=NULL;h=p,p=p->next); // @@ Logic error: The semicolon terminates the loop immediately. The block below executes only once with p pointing to the last node (or head if list has 1 node). This prevents correct sorted insertion in the middle.
            {
                if(p==head&&p->next!=NULL&&p->next->adj>inf)
                {
                        e->next=p->next;
                        p->next=e;
                        return head;
                }
                if(p->adj>inf&&p!=head)
                {
                    e->next=p;
                    h->next=e;
                    return head;
                }
            }
            /*p=head;
            while(1)
            {
                if(p->next==NULL)
                {
                    e->next=NULL;
                    p->next=e;
                    return head;
                }
                else if(p->next->adj>inf)
                {
                    e->adj=inf;
                    e->next=p->next->next;
                    e=p->next;
                    return head;
                }
                p=p->next;

            }*/
            if(p->next==NULL)
            {
                if(p->adj>inf)
                {
                    e->next=p;
                    h->next=e;
                }
                else
                {
                    p->next=e;
                }
                return head;
            }
        }
    }
    free(p); // @@ Logic error: freeing 'p' here is dangerous as it might still be part of the list or invalid. The function structure is fundamentally broken regarding memory management and linked list insertion logic.
};
int visited[105]={0};
void dfs(struct ver G[],int v)
{
    struct edge *p;
    visited[v]=1;
    printf("%d ",v);
    for(p=G[v].link;p!=NULL;p=p->next)
    {
        if(visited[p->adj]==0)
        dfs(G,p->adj);
    }
}
void traveldfs(struct ver G[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(i!=flag)
            visited[i]=0;
        if(i==flag)
            visited[i]=1;
    }
    for(i=0;i<n;i++)
    {
        if(visited[i]==0)
            dfs(G,i);
    }
}
int visited1[105]={0};
int quene[1005]={0};
int front=-1;
int rear=-1;
void bfs(struct ver G[],int v)
{
    struct edge *p;
    visited1[v]=1;
    quene[++front]=v;
    while(rear!=front)
    {
        v=quene[++rear];
        printf("%d ",v);
        for(p=G[v].link;p!=NULL;p=p->next)
        {
            if(!visited1[p->adj])
            {
                visited1[p->adj]=1;
                quene[++front]=p->adj;
            }
        }
    }
}
void travelbfs(struct ver G[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(i!=flag)
            visited1[i]=0;
        if(i==flag)
            visited1[i]=1;
    }
    for(i=0;i<n;i++)
    {
        if(!visited1[i])
            bfs(G,i);
    }
}
int main()
{
    int spot,line;
    scanf("%d %d",&spot,&line);
    for(int i=0;i<line;i++)
    {
        int s1,s2;
        scanf("%d %d",&s1,&s2);
        G[s1].link=inserted(G[s1].link,s2);
        G[s2].link=inserted(G[s2].link,s1);
    }

    int deletespot;
    scanf("%d",&deletespot);
    traveldfs(G,spot);
    printf("\n");
    travelbfs(G,spot);
    printf("\n");
    struct edge *p;
    p=(struct edge *)malloc(sizeof(struct edge)); // @@ Redundant allocation: 'p' is immediately overwritten in the next line, causing a memory leak.
    p=G[deletespot].link;
    while(p!=NULL)//删除在其他节点中的deletespot所涉及的边
    {
        int num=p->adj;
        struct edge *q,*ptr;
        q=(struct edge *)malloc(sizeof(struct edge)); // @@ Memory leak: 'q' is allocated but immediately overwritten by G[num].link.
        ptr=(struct edge *)malloc(sizeof(struct edge)); // @@ Memory leak: 'ptr' is allocated but immediately overwritten by NULL.
        q=G[num].link;
        ptr=NULL;
        if(q->adj==deletespot)
        {
            G[num].link=G[num].link->next;
        }
        else
        {
            while(q->adj!=deletespot)
            {
                ptr=q;
                q=q->next;
            }
            if(q->next==NULL)
                ptr->next=NULL;
            else
            {
                ptr->next=ptr->next->next;
            }
        }
        p=p->next;
    }
    flag=deletespot;//删除该点
    traveldfs(G,spot);
    printf("\n");
    travelbfs(G,spot);
    free(p); // @@ Error: 'p' is NULL here (after the while loop), so free(NULL) is safe but useless. However, the nodes removed from the adjacency lists were NOT freed, causing memory leaks. More importantly, the BFS/DFS output format requires no trailing space, but the current implementation prints a trailing space. The primary issue causing WA is likely the trailing space or the graph modification logic.
    return 0;
}