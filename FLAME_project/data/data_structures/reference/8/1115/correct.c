#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct edge{
    int adj1;
    int adj2;
    struct edge *next;
};
struct ver{
    int no;
    char flag1,flag2,flag3;
    char flag5,flag6;
    struct edge *link;
}V[101];

struct edge *insert(struct edge* head,int v1,int v2)
{
    struct edge *q,*m,*p=(struct edge*)malloc(sizeof(struct edge));
    p->adj1=v1;p->adj2=v2; p->next=NULL;
    if(head==NULL)
    {
        return p;
    }
    for(q=head;q!=NULL;m=q,q=q->next)
    {
        if((q->adj2)>v2)
        {
            if(q==head)
            {
                p->next=head;
                return p;
            }else
            {
                m->next=p;
                p->next=q;
                return head;
            }
        }
    }
    m->next=p;
    return head;
}

void read1(struct ver *p)
{
    if(p->flag1)
    printf("%d ",p->no);
}
void read2(struct ver *p)
{
    if(p->flag3)  printf("%d ",p->no);
}
void perread1(struct ver *p)
{
    struct edge *q;
    if(p->flag1)
    {
        read1(p);
        p->flag1=0;
        for(q=p->link;q!=NULL;q=q->next)
        {
            perread1(&V[q->adj2]);
            
        }
    }
}
void perread2(struct ver *p)
{
    struct edge *q;
    if(p->flag2==0) return;
    if(p->flag3)
    {
        read2(p);
        p->flag3=0;
        for(q=p->link;q!=NULL;q=q->next)
        {
            perread2(&V[q->adj2]);
            
        }
    }
}

int stack[100];
int num=1;
int front=0;
int rear=0;
void mread1(struct ver *p)
{
    num--;
        front++;
    if(p->flag5==0) return;
    if(p->flag5) printf("%d ",p->no);
    p->flag5=0;
    
    struct edge *q;
    for(q=p->link;q!=NULL;q=q->next)
    {
        if(V[q->adj2].flag5==0) continue;
      
        stack[++rear]=q->adj2;
        num++;
    }
}
void mread2(struct ver *p)
{
    num--;
    front++;
    if(p->flag6==0) return;
    if(p->flag6) printf("%d ",p->no);
    p->flag6=0;
    
    struct edge *q;
    for(q=p->link;q!=NULL;q=q->next)
    {
        if(V[q->adj2].flag6==0) continue;
        if(V[q->adj2].flag2==0) continue;
        stack[++rear]=q->adj2;
        num++;
    }
}
int main()
{
    int n,m;
    int i,j;
    int vm;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
    {
        V[i].no=i;
        V[i].flag1=1;
        V[i].flag2=1;
        V[i].flag3=1;
        V[i].flag5=1;
        V[i].flag6=1;
    }
    int v1,v2;
    for(i=0;i<m;i++)
    {
        scanf("%d %d",&v1,&v2);
        V[v1].link=insert(V[v1].link,v1,v2);
        V[v2].link=insert(V[v2].link,v2,v1);
    }
    scanf(" %d",&vm);
    V[vm].flag2=0;
    perread1(&V[0]);
    printf("\n");
    
    while(num)
    {
        mread1(&V[stack[front]]);
    }
    printf("\n");
    perread2(&V[0]);
    printf("\n");
    num=1;
    rear=front=0;
    while(num)
    {
        mread2(&V[stack[front]]);
    }

    return 0;
}
