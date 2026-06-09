#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h> 
int n,numofedge;
typedef struct edge
{
    int content;
    int weight;
    struct edge *next;
}elink; 
typedef struct heads
{
    int content;
    elink *link;
}hlink;
hlink h[110];
int cmp(const void*a,const void*b)
{
    int aa=*(int*)a;
    int bb=*(int*)b;
    return aa-bb<0?-1:1;
}
elink *Insert(elink *head,int target)
{
    elink *p,*q;
    p=(elink *)malloc(sizeof(elink));
    p->content=target;
    p->weight=1;
    p->next=NULL;
    if(head==NULL)
    {
        head=p;
        return head;
    }
    for(q=head;q->next!=NULL;q=q->next);
    q->next=p;
    return head;
}
void Delete(int target)
{
    elink *p,*q,*r;
    p=h[target].link;
    for(int i=target+1;i<n;i++)
    {
        h[i-1].content=h[i].content;
        h[i-1].link=h[i].link;
    }
    n--;
    while(p!=NULL)
    {
        r=p;
        p=p->next;
        free(r);
    }
    for(int i=0;i<n;i++)
    {
        p=h[i].link;
        while(p!=NULL)
        {
            if(p->content==target)
            {
                if(h[i].link==p)
                {
                    h[i].link=p->next;
                }
                else
                {
                    q->next=p->next;
                }
                r=p;
                p=p->next;
                free(r);
            }
            else
            {
                if(p->content>target)
                p->content--;
                q=p;
                p=p->next;
            }
        }
    }
}
int visited[110],ans[110],cnt=0;
void dfs(int tar)
{
    elink *p;
    int a[100],cntt=0;
    visited[tar]=1;
    ans[++cnt]=h[tar].content;
    for(p=h[tar].link;p!=NULL;p=p->next)
    {
        if(!visited[p->content])
        {
            a[++cntt]=p->content; 
        }  
    }
    qsort(a+1,cntt,sizeof(int),cmp);
    for(int i=1;i<=cntt;i++)
    {
        if(!visited[a[i]])
        dfs(a[i]);
    }
}
void DFS()
{
    for(int i=0;i<n;i++)
    {
        visited[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        dfs(i);
    }
}
void bfs(int target)
{
    int front,rear;
    hlink Que[500];
    hlink q;
    elink *p;
    visited[target]=1;
    Que[0]=h[target];
    front=0;
    rear=0;
    while(front<=rear)
    {
        int a[500],cntt=0;
        q=Que[front++];
        p=q.link;
        ans[++cnt]=q.content;
        for(;p!=NULL;p=p->next)
        {
            if(!visited[p->content])
            {
                visited[p->content]=1;
                a[++cntt]=p->content;  
            }
        }
        qsort(a+1,cntt,sizeof(int),cmp);
        for(int i=1;i<=cntt;i++)
        {
            Que[++rear]=h[a[i]];
        }
    }
}
void BFS()
{
    for(int i=0;i<n;i++)
    {
        visited[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        bfs(i);
    }
}
int main()
{
    int v1,v2,deletarget;
    scanf("%d%d",&n,&numofedge);
    for(int i=0;i<numofedge;i++)
    {
        h[i].content=i;
        scanf("%d%d",&v1,&v2);
        h[v1].link=Insert(h[v1].link,v2);
        h[v2].link=Insert(h[v2].link,v1);
    }
    scanf("%d",&deletarget);
    DFS();
    for(int i=1;i<cnt;i++)
    {
        printf("%d ",ans[i]);
    }
    printf("%d\n",ans[cnt]);
    cnt=0;
    BFS();
    for(int i=1;i<cnt;i++)
    {
        printf("%d ",ans[i]);
    }
    printf("%d\n",ans[cnt]);
    cnt=0;
    Delete(deletarget);
    DFS();
    for(int i=1;i<cnt;i++)
    {
        printf("%d ",ans[i]);
    }
    printf("%d\n",ans[cnt]);
    cnt=0;
    BFS();
    for(int i=1;i<cnt;i++)
    {
        printf("%d ",ans[i]);
    }
    printf("%d\n",ans[cnt]);
}
