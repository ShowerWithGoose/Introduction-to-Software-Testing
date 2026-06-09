#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int visited[105]={0},q[105],front=0,rear=0,count,a,b;
typedef struct bian
{
    int end;
    struct bian *next;
}edge;
typedef struct vertex
{
    int num;
    edge *next;
}point;
edge* insertedge(edge *head,int avex)
{
    edge *e=NULL,*p=NULL,*q=NULL;
    e=(edge *)malloc(sizeof(edge));
    e->end=avex;
    e->next=NULL;
    if(head==NULL)
    {
        return e;
    }
    for(p=head;p!=NULL&&avex>p->end;)
    {
        q=p;
        p=p->next;
    }
        if(p==head)
        {
        e->next=p;
        return e;
    }
    else
    {
        q->next=e;
        e->next=p;
        return head;
    }
}
void create(point pic[])
{
    for(int i=0;i<b;i++)
    {
        int v1,v2;
        scanf("%d %d",&v1,&v2);
        pic[v1].next=insertedge(pic[v1].next,v2);
        pic[v2].next=insertedge(pic[v2].next,v1);
    }
}
void depthsearch(point pic[],int v)
{
    edge *p;
    visited[v]=1;
    printf("%d ",v);
    for(p=pic[v].next;p!=NULL;p=p->next)
    {
        if(!visited[p->end])
        {
            depthsearch(pic,p->end);
        }
    }
}
void DFS(point pic[],int n,int x)
{
    int i;
    for(i=0;i<n;i++)
        visited[i]=0 ;
    if(x>=0)
    {
        visited[x]=1;
    }
    for(i=0;i<n;i++)
    {
        if(!visited[i])
        {
            depthsearch(pic,i);
        }
    }
    printf("\n");
}

void initqueue(void)
{
    front=0;
    rear=104;
    count=0;
}
int emptyq(int q[])
{
    if(count==0)
        return 1;
    else
        return 0;
}
int fullq(int q[])
{
    if(count==105)
        return 1;
    else
        return 0;
}
void enqueue(int q[],int v)
{
    if(!fullq(q))
    {
    rear=(rear+1)%105;
    q[rear]=v;
    count++;
    }
}
int dequeue(int q[])
{
    int m;
    if(!emptyq(q))
    {
    m=q[front];
    front=(front+1)%105;
    count--;
    }
    return m;
}
void breadresearch(point pic[],int v)
{
    edge *p;
    initqueue();
    visited[v]=1;
    enqueue(q,v);
    while(!emptyq(q))
    {
        v=dequeue(q);
        printf("%d ",v);
        for(p=pic[v].next;p!=NULL;p=p->next)
        {
            if(!visited[p->end])
            {
                visited[p->end]=1;
                enqueue(q,p->end);
            }
        }
    }
}
void BFS(point pic[],int n,int x)
{
    int i;
    for(i=0;i<n;i++)
        visited[i]=0;
    if(x>=0)
        visited[x]=1;
    for(i=0;i<n;i++)
    {
         if(!visited[i])
        {
            breadresearch(pic,i);
        }
    }
    printf("\n");
}
int main()
{
    point pic[105]={NULL};
    edge *e=NULL,*p=NULL,*m=NULL,*n=NULL;
    int pointa,pointb,i,x;
    scanf("%d %d",&a,&b);
    create(pic);
    DFS(pic,a,-1);
    BFS(pic,a,-1);
    scanf("%d",&x);
    DFS(pic,a,x);
    BFS(pic,a,x);
    return 0;
}

