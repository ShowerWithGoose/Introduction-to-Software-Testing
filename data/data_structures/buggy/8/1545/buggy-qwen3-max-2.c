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
    p=(struct edge *)malloc(sizeof(struct edge));
    e=(struct edge *)malloc(sizeof(struct edge));
    h=(struct edge *)malloc(sizeof(struct edge));
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
            for(p=head,h=NULL;p->next!=NULL;h=p,p=p->next);
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
    free(p); // @@ [This line is unreachable because all code paths above return before reaching it. Additionally, 'p' was allocated but not necessarily used correctly, and freeing it here may cause undefined behavior or memory issues.]
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
            dfs(G,i); // @@ [The problem requires traversal to always start from vertex 0, but this loop starts DFS from every unvisited node in order, which violates the requirement. It should only start from 0.]
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
            bfs(G,i); // @@ [Same issue as traveldfs: BFS must start only from vertex 0, not from every unvisited vertex. This violates the problem's requirement.]
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
    p=(struct edge *)malloc(sizeof(struct edge)); // @@ [Unnecessary allocation: 'p' is immediately overwritten by 'p = G[deletespot].link;' below, causing a memory leak.]
    p=G[deletespot].link;
    while(p!=NULL)//删除在其他节点中的deletespot所涉及的边
    {
        int num=p->adj;
        struct edge *q,*ptr;
        q=(struct edge *)malloc(sizeof(struct edge)); // @@ [Unnecessary allocation: 'q' is immediately overwritten by 'q = G[num].link;', causing a memory leak.]
        ptr=(struct edge *)malloc(sizeof(struct edge)); // @@ [Unnecessary allocation: 'ptr' is used as a pointer but never freed, and its initial malloc is pointless since it's assigned NULL later logically (though not in code). This causes memory leaks.]
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
                ptr->next=ptr->next->next; // @@ [Incorrect pointer update: should be 'ptr->next = q->next;' instead of 'ptr->next->next'. This may skip nodes or cause crashes.]
            }
        }
        p=p->next;
    }
    flag=deletespot;//删除该点
    traveldfs(G,spot);
    printf("\n");
    travelbfs(G,spot);
    free(p); // @@ [Double-free risk or invalid free: 'p' points to graph structure memory that was not allocated with malloc in this scope (it came from G[deletespot].link), so freeing it is undefined behavior. Also, earlier unnecessary malloc makes this even more problematic.]
    return 0;
}