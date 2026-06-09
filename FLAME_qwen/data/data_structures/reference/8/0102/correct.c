#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node * link;
}pnode,* plist;
plist a[1005];
int visited[1005];

void dfs(int v)
{
    plist p;
    printf("%d ",v);
    visited[v]=1;
    p=a[v];
    while (p->link!=NULL)
    {
        p=p->link;
        if (!visited[p->data]) dfs(p->data);
    }
}

void depthsearch(int dn,int del)
{
    int i;
    for (i=0;i<dn;i++)
    {
        visited[i]=0;
    }
    if (del>=0) visited[del]=1;
    for (i=0;i<dn;i++)
    {
        if (!visited[i])
        {
            dfs(i);
        }
    }
}

void bfs(int v)
{
    plist p;
    int queue[1005],front=-1,rear=0;
    queue[0]=v;
    visited[v]=1;
    printf("%d ",v);
    while (front<rear)
    {
        front++;
        p=a[queue[front]];
        while (p->link!=NULL)
        {
            p=p->link;
            if (!visited[p->data])
            {
                visited[p->data]=1;
                printf("%d ",p->data);
                queue[++rear]=p->data;
            }
        }
    }
}

void widthsearch(int dn,int del)
{
    int i;
    for (i=0;i<dn;i++)
    {
        visited[i]=0;
    }
    if (del>=0) visited[del]=1;
    for (i=0;i<dn;i++)
    {
        if(!visited[i])
        {
            bfs(i);
        }
    }
}

int main()
{
    int dn,ln,i,u,v,del;
    plist p,q,r;
    scanf("%d%d",&dn,&ln);
    for (i=0;i<ln;i++)
    {
        scanf("%d%d",&u,&v);
        q=(plist)malloc(sizeof(pnode));
        q->data=v;
        q->link=NULL;
        p=a[u];
        if (p==NULL)
        {
            p=(plist)malloc(sizeof(pnode));
            p->link=q;
            a[u]=p;
        }
        else
        {
            r=a[u];
            p=a[u]->link;
            while (p!=NULL&&p->data<q->data)
            {
                p=p->link;
                r=r->link;
            }
            q->link=p;
            r->link=q;
        }
        q=(plist)malloc(sizeof(pnode));
        q->data=u;
        q->link=NULL;
        p=a[v];
        if (p==NULL)
        {
            p=(plist)malloc(sizeof(pnode));
            p->link=q;
            a[v]=p;
        }
        else
        {
            r=a[v];
            p=a[v]->link;
            while (p!=NULL&&p->data<q->data)
            {
                p=p->link;
                r=r->link;
            }
            q->link=p;
            r->link=q;
        }
    }
    scanf("%d",&del);
    depthsearch(dn,-1);
    putchar('\n');
    widthsearch(dn,-1);
    putchar('\n');
    depthsearch(dn,del);
    putchar('\n');
    widthsearch(dn,del);
}

