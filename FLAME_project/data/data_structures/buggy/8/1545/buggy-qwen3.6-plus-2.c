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
    p=(struct edge *)malloc(sizeof(struct edge)); // @@ [Memory leak: 'p' is allocated but overwritten immediately in the loop or logic below, and freed at the end. It is not used correctly for traversal initialization.]
    e=(struct edge *)malloc(sizeof(struct edge));
    h=(struct edge *)malloc(sizeof(struct edge)); // @@ [Memory leak: 'h' is allocated but only used as a pointer tracker. If head is not NULL, h is uninitialized or points to garbage if not set in loop. In the loop `for(p=head,h=NULL;...)`, h is set to NULL initially, which is correct for tracking, but the initial allocation here is wasted and leaked.]
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
            for(p=head,h=NULL;p->next!=NULL;h=p,p=p->next); // @@ [Logic Error: The semicolon terminates the for loop immediately. The block following it executes only once with the final values of p and h from the loop (or initial if loop doesn't run). This breaks the sorted insertion logic for intermediate nodes.]
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
    free(p); // @@ [Logic Error: 'p' is freed here, but 'h' and potentially other allocated pointers are leaked. Also, if the function returns early, these frees don't happen, causing leaks. The initial mallocs for p and h are largely unnecessary and incorrect.]
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
    p=(struct edge *)malloc(sizeof(struct edge)); // @@ [Memory Leak/Logic Error: Memory is allocated for p, but then immediately overwritten by `p=G[deletespot].link`. The allocated memory is lost.]
    p=G[deletespot].link;
    while(p!=NULL)//删除在其他节点中的deletespot所涉及的边
    {
        int num=p->adj;
        struct edge *q,*ptr;
        q=(struct edge *)malloc(sizeof(struct edge)); // @@ [Memory Leak: q is allocated but immediately overwritten by `q=G[num].link`.]
        ptr=(struct edge *)malloc(sizeof(struct edge)); // @@ [Memory Leak: ptr is allocated but immediately overwritten by `ptr=NULL`.]
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
    free(p); // @@ [Undefined Behavior: p is NULL here because the while loop terminated when p became NULL. Freeing NULL is safe, but the logic leading here is flawed due to previous memory leaks and potential access issues if the graph structure was corrupted.]
    return 0;
}