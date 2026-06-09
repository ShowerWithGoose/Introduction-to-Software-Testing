#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node
{
    int num;
    struct node *link;
};
struct node1
{
    struct node *next;
};
struct node1 g[100];
int v,s;
struct node1 insert(struct node1 g[],int a,int b)
{
    struct node *p=(struct node *)malloc(sizeof(struct node));
    p->link=NULL;
    p->num=b;
    struct node *q;
    if(g[a].next==NULL)
    {
        g[a].next=p;
    }
else{
        if(b<g[a].next->num)
        {
            p->link=g[a].next;
            g[a].next=p;
        }
       else{
        for(q=g[a].next;b>q->num;q=q->link)
        {
            if(q->link==NULL)
            {
                q->link=p;
                break;
            }
            if(b<q->link->num)
            {
                p->link=q->link;
                q->link=p;
                break;
            }
        }
    }}
    return g[a];
};
int visit[100];
void DFS(struct node1 g[],int num1)
{
    struct node *p1;
    visit[num1]=1;
    printf("%d ",num1);
    for(p1=g[num1].next;p1!=NULL;p1=p1->link)
    {
        if(visit[p1->num]==0)
        {
            DFS(g,p1->num);
        }
    }
}
void travlDFS(struct node1 g[],int n,int delv)
{
    for(int i=0;i<n;i++)
    {
        visit[i]=0;
    }
    if(delv>=0)
    {
        visit[delv]=1;
    }
    for(int i=0;i<n;i++)
    {
        if(visit[i]==0)
        {
            DFS(g,i);
        }
    }
    printf("\n");
}
int main()
{
    scanf("%d%d",&v,&s);
    int a,b;
    for(int i=0;i<s;i++)
    {
        scanf("%d%d",&a,&b);
        g[a]=insert(g,a,b);
        g[b]=insert(g,b,a);
    }
scanf("%d",&a);
    struct node *p;
    travlDFS(g,v,-1);
    travlDFS(g,v,a);

    return 0;
}