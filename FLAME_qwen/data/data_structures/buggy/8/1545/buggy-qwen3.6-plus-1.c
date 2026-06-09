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
struct ver G[105]={}; // @@ Empty braces are not valid for array initialization in standard C; use {0} or omit initialization since global variables are zero-initialized by default.
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
    free(p); // @@ 'p' was reassigned to 'head' in the loop, so this frees the list head, causing the function to return a dangling pointer.
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
    for(int i=0;i<line;i++) // @@ Variable declaration inside for-loop initializer is not allowed in C89/C90; declare 'i' at the beginning of main.
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
    p=(struct edge *)malloc(sizeof(struct edge));
    p=G[deletespot].link; // @@ Overwrites the previously malloc'd pointer, causing a memory leak.
    while(p!=NULL)//删除在其他节点中的deletespot所涉及的边
    {
        int num=p->adj;
        struct edge *q,*ptr;
        q=(struct edge *)malloc(sizeof(struct edge));
        ptr=(struct edge *)malloc(sizeof(struct edge));
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
    free(p); // @@ Frees the head of the adjacency list after traversal; while the program ends immediately, it's unsafe and masks the earlier memory leak.
    return 0;
}