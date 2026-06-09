#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
struct Edge//lingjiebiao
{
    int pos;
    int weigh;
    struct Edge* next;
};
struct Ver
{
    int vertex;
    struct Edge* link;
} ver[500];
int visit[500]= {0};
int queue[500],front=-1,rear=-1;
struct Edge* insertEdge(struct Edge* head,int pos)
{
    struct Edge*e,*p;
    e=(struct Edge*)malloc(sizeof(struct Edge));
    e->pos=pos;
    //e->weigh=1;//
    e->next=NULL;
    if(head==NULL)
    {
        head=e;
        return head;
    }
    for(p=head; p->next!=NULL; p=p->next)
        p->next=e;
    return head;
}
void DFS(int v)
{
    struct Edge*q;
    if(visit[v]==0)
    {
        visit[v]=1;
        printf("%d ",v);
    }
    for(q=ver[v].link; q!=NULL; q=q->next)
    {
        if(visit[q->pos]==0) DFS(q->pos);
    }

}
void traDFS(int n)
{
    for(int i=0; i<n; i++) visit[i]=0;
    for(int i=0; i<n; i++)
    {
        if(visit[i]==0) DFS(i);
    }
}
void tra2DFS(int n,int v)
{
    for(int i=0; i<n; i++) visit[i]=0;
    for(int i=0; i<n; i++)
    {
        if(visit[i]==0&&i!=v) DFS(i);
    }
}
struct Edge*  findpre(struct Edge* head,int key)
{
    struct Edge*e=head;
    while(1)
    {
        if(e->next==NULL) return e;
        if(key>e->next->pos) e=e->next;
        else if(key<e->next->pos) return e;
    }
}
struct Edge*  findpre2(struct Edge* head,int key)
{
    struct Edge*e=head;
    while(e->next!=NULL)
    {

        if(key==e->next->pos) return e;
        e=e->next;
    }
    return NULL;

}
void BFS(int v)
{
    struct Edge*p;
    if(visit[v]==1) return;
    else
    {
        visit[v]=1;
        queue[++rear]=v;
        while(front!=rear)
        {
            v=queue[++front];
            printf("%d ",v);
            for(p=ver[v].link; p!=NULL; p=p->next)
            {
                if(visit[p->pos]==0)
                {
                    visit[p->pos]=1;
                    queue[++rear]=p->pos;
                }
            }
        }
    }
}
void traBFS(int n)
{
    for(int i=0; i<n; i++) visit[i]=0;
    for(int i=0; i<n; i++)
    {
        if(visit[i]==0) BFS(i);
    }
}
void tra2BFS(int n,int v)
{
    for(int i=0; i<n; i++) visit[i]=0;
    for(int i=0; i<n; i++)
    {
        if(visit[i]==0&&i!=v) BFS(i);
    }
}

void delete(int n,int v)
{
    struct Edge*p,*q,*r;
    p=ver[v].link;
    while(p!=NULL)
    {
        r=p;
        p=p->next;
        free(r);
    }
    for(int i=0; i<n; i++)
    {
        p=ver[i].link;
        if(p->pos==v) ver[i].link=p->next;
        else
        {
            q=findpre2(ver[i].link,v);
            if(q!=NULL)
            {
                r=q->next;
                q->next=r->next;
                free(r);
            }
        }
    }
}
int main() {
    int n,m,v1,v2;
    scanf("%d%d",&n,&m);
    for(int i=0; i<m; i++)
    {
        scanf("%d%d",&v1,&v2);
        struct Edge*p;
        ver[v1].vertex=v1;
        struct Edge* t=(struct Edge*)malloc(sizeof(struct Edge));
        t->pos=v2;
        t->next=NULL;
        if(ver[v1].link==NULL)
        {
            ver[v1].link=t;
        }
        else if(v2<ver[v1].link->pos)
        {
            t->next=ver[v1].link;
            ver[v1].link=t;
        }
        else
        {
            p=findpre(ver[v1].link,v2);
            if(p->next==NULL) p->next=t;
            else
            {
                t->next=p->next;
                p->next=t;
            }
        }

        ver[v2].vertex=v2;
        struct Edge* r=(struct Edge*)malloc(sizeof(struct Edge));
        r->pos=v1;
        r->next=NULL;
        if(ver[v2].link==NULL)
        {
            ver[v2].link=r;
        }
        else if(v1<ver[v2].link->pos)
        {
            r->next=ver[v2].link;
            ver[v2].link=r;
        }
        else
        {
            p=findpre(ver[v2].link,v1);
            if(p->next==NULL) p->next=r;
            else
            {
                r->next=p->next;
                p->next=r;
            }
        }
    }
    traDFS(n);
    printf("\n");
    traBFS(n);
    printf("\n");
    int v3;
    scanf("%d",&v3);
    delete(n,v3);
    tra2DFS(n,v3);
    printf("\n");
    tra2BFS(n,v3);



}
