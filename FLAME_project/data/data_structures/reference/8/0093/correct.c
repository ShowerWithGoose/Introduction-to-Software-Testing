#include <string.h>
#include <stdlib.h>
#include <stdio.h>
int flag[105];
typedef struct node1
{
    int id;
    struct node2* edge;
}ver;

typedef struct node2
{
    int id;
    struct node2* next;
}edg;

ver point[105];
edg *p,*q,*h;
int delete=0;
void visit(ver r[],int start)
{
    edg *p;
    flag[start]=1;
    p=r[start].edge;
    if(p!=NULL) printf("%d ",start);
    for(;p!=NULL;p=p->next)
    {
        if(flag[p->id]==0) visit(r,p->id);
    }
}

void deeptravel(ver r[],int sum)
{
    int i;
    for(i=0;i<sum;i++) flag[i]=0;
    if(delete!=0) flag[delete]=1;
    for(i=0;i<sum;i++)
    {
        if(flag[i]==0) visit(r,i);
    }
    printf("\n");
}


ver queue[200];
int first=0,rear=-1;
void BFS(ver r[],int start)
{
    ver t;
    edg *h;
    int i=0;
    flag[start]=1;
    queue[++rear]=r[start];
    while(first<=rear)
    {
        t=queue[first++];
        if(t.edge!=NULL) printf("%d ",t.id);
        for(h=t.edge;h!=NULL;h=h->next)
        {
            if(flag[h->id]==0) 
            {
                queue[++rear]=r[h->id];
                flag[h->id]=1;
            }
        }
    }
}

void queuetravel(ver r[],int sum)
{
    int i;
    for(i=0;i<sum;i++) flag[i]=0;
    if(delete!=0) flag[delete]=1;
    for(i=0;i<sum;i++)
    {
        if(flag[i]==0) BFS(r,i);
    }
    printf("\n");
}


int main()
{
    int n,lnum,i,p1,p2;
    scanf("%d%d",&n,&lnum);
    for(i=0;i<n;i++)
    {
        point[i].id=i;
        point[i].edge=NULL;
    }
    for(i=0;i<lnum;i++)
    {
        scanf("%d%d",&p1,&p2);
        p=(edg*)malloc(sizeof(edg));
        p->id=p1;
        p->next=NULL;
        if(point[p2].edge==NULL) point[p2].edge=p;
        else
        {
            q=point[p2].edge;
            h=q;
            while(q!=NULL&&p->id>q->id)
            {
                h=q;
                q=q->next;
            }
            if(q!=NULL) p->next=q;
            if(h!=q) h->next=p;
            else point[p2].edge=p;
        }

        p=(edg*)malloc(sizeof(edg));
        p->id=p2;
        p->next=NULL;
        if(point[p1].edge==NULL) point[p1].edge=p;
        else
        {
            q=point[p1].edge;
            h=q;
            while(q!=NULL&&p->id>q->id) 
            {
                h=q;
                q=q->next;
            }
            if(q!=NULL) p->next=q;
            if(h!=q) h->next=p;
            else point[p1].edge=p;
        }
    }
    
    deeptravel(point,n);
    queuetravel(point,n);

    /*for(i=0;i<n;i++)
    {
        if(i!=delete)
        {
            for(p=point[i].edge;p->next!=NULL;p=p->next)
            {
                if(p->next->id==delete)
                {
                    q=p->next;
                    if(q->next!=NULL) p->next=q->next;
                    else p->next=NULL;
                    free(q);
                }
            }
        }
    }*/
    scanf("%d",&delete);
    point[delete].edge=NULL;
    deeptravel(point,n);
    queuetravel(point,n);


}

