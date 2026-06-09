#include <stdio.h>
#include <stdlib.h>
struct node{
int num;
struct node *next;
};
struct node op[100],*p,*q;
int visit[100],tp[100][100];
int que[100],head=0,tail=0;
void travelD(struct node G[],int n)
{
    int i;
    for(i=0;i<n;i++)visit[i]=0;
    for(i=0;i<n;i++)
        if(!visit[i])DFS(G,i);
}
void DFS(struct node G[],int v)
{
    struct node *g;
    visit[v]=1;
    printf("%d ",G[v].num);
    for(g=G[v].next;g!=NULL;g=g->next)
        if(!visit[g->num])
        DFS(G,g->num);
}
void travelB(struct node G[],int n)
{
    int i;
    head=0;tail=0;
    for(i=0;i<n;i++)visit[i]=0;
    for(i=0;i<n;i++)
        if(!visit[i])BFS(G,i,n);
}
void BFS(struct node G[],int v)
{
    struct node *h;
    visit[v]=1;
    que[tail++]=v;
    while(head!=tail)
    {
        v=que[head++];
        printf("%d ",G[v].num);
        for(h=G[v].next;h!=NULL;h=h->next)
            if(!visit[h->num])
        {
            visit[h->num]=1;
            que[tail++]=h->num;
        }
    }
}

int main()
{
        int n,m,i,a,b,j,x;
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
            tp[i][j]=0;
        for(i=0;i<n;i++)
            {op[i].num=i;op[i].next=NULL;}
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&a,&b);
            tp[a][b]=1;
            tp[b][a]=1;
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
                if(tp[i][j]==1)
            {
                p=&op[i];
            while(p->next!=NULL)p=p->next;
            q=(struct node*)malloc(sizeof(struct node));
            q->next=NULL;
            q->num=j;
            p->next=q;
            }
        }
        scanf("%d",&x);
        travelD(op,n);
        printf("\n");
        travelB(op,n);
        printf("\n");

        for(i=0;i<n;i++)
        {
            tp[x][i]=0;
            tp[i][x]=0;
        }
        for(i=0;i<n-1;i++)
            {
                if(i<x)
                {op[i].num=i;op[i].next=NULL;}
                if(i>=x)
                {
                    op[i].num=i+1;
                    op[i].next=NULL;
                }
            }
            for(i=0;i<n-1;i++)
        {
            for(j=0;j<n-1;j++)
                if(tp[op[i].num][op[j].num]==1)
            {
                p=&op[i];
            while(p->next!=NULL)p=p->next;
            q=(struct node*)malloc(sizeof(struct node));
            q->next=NULL;
            q->num=j;
            p->next=q;
            }
        }
        travelD(op,n-1);
        printf("\n");
        travelB(op,n-1);
        printf("\n");


    return 0;
}

