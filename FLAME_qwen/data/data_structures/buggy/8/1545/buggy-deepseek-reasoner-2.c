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
            for(p=head,h=NULL;p->next!=NULL;h=p,p=p->next);  @@ [分号导致循环体为空，后续花括号内的代码不再属于循环，插入逻辑完全错误]
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
    free(p);  @@ [释放p可能造成野指针，且前面的malloc泄漏]
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
    p=(struct edge *)malloc(sizeof(struct edge));  @@ [分配了内存但立即被覆盖，导致内存泄漏]
    p=G[deletespot].link;
    while(p!=NULL)//删除在其他节点中的deletespot所涉及的边
    {
        int num=p->adj;
        struct edge *q,*ptr;
        q=(struct edge *)malloc(sizeof(struct edge));  @@ [不必要的内存分配，且导致泄漏]
        ptr=(struct edge *)malloc(sizeof(struct edge));  @@ [不必要的内存分配，且导致泄漏]
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
    free(p);  @@ [p此时已经是NULL或指向链表末尾，free无效且可能错误]
    return 0;
}