#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
    int co;
    int time;
    struct node *link;
}*Linklist;
struct cal
{
    int c;
    int t;
};
Linklist creat();
Linklist insert(Linklist list,int itemc,int itemt);
Linklist lsort(struct cal a[],int n);
void catch(Linklist list,int *num);
int main()
{
    Linklist list1,list2=NULL;
    Linklist p,r,l1,l2,list3=NULL;
    int len=0;
    list1=creat();
    list2=creat();
    l1=list1;
    l2=list2;
    while(l1!=NULL)
    {
        while(l2!=NULL)
        {
            p=(Linklist)malloc(sizeof(Linklist));
            memset(p,0,sizeof(struct node));
            p->co=(l1->co)*(l2->co);
            p->time=(l1->time)+(l2->time);
            p->link=NULL;
            if(list3==NULL)
            list3=p;
            else
            r->link=p;
            r=p;
            l2=l2->link;
            len++;
        }
        l1=l1->link;
        l2=list2;
    }
    struct cal a[105];
    int i;
    p=list3;
    for(i=0;p!=NULL;i++)
    {
        a[i].c=p->co;
        a[i].t=p->time;
        p=p->link;
    }
    Linklist l4;
    l4= lsort(a,len);
    catch(l4,&len);
    p=l4;
    for(i=0;i<len;i++)
    {
        printf("%d ",p->co);
        printf("%d ",p->time);
        p=p->link;
    }
    return 0;
}
Linklist creat()
{
    int ch=0;
    Linklist p,r,list=NULL;
    do
    {
        p=(Linklist)malloc(sizeof(Linklist));
        memset(p,0,sizeof(struct node));
        scanf("%d %d",&(p->co),&(p->time));
        p->link=NULL;
        if(list==NULL)
        {
            list=p;
        }
        else
        {
            r->link=p;
        }
        r=p;
        ch=getchar();
    }while(ch!='\n');//caution!
    return list;
}
Linklist insert(Linklist list,int itemc,int itemt)
{
    Linklist p,q,r;
    p=(Linklist)malloc(sizeof(Linklist));
    memset(p,0,sizeof(struct node));
    p->co=itemc;
    p->time=itemt;
    if(list==NULL||itemt>list->time)
    {
        p->link=list;
        list=p;
    }
    else
    {
        q=list;
        while(q!=NULL&&itemt<=q->time)
        {
            r=q;
            q=q->link;
        }
        p->link=q;
        r->link=p;
    }
    return list;
}
Linklist lsort(struct cal a[],int n)
{
    Linklist list=NULL;
    int i;
    for(i=0;i<n;i++)
    list=insert(list,a[i].c,a[i].t);
    return list;
}
void catch(Linklist list,int *num)
{
    Linklist r,p=NULL;
    r=list;
    p=list->link;
    while(p!=NULL)
    {
        if(p->time==r->time)
        {
           ( *num)--;
            r->co+=p->co;
            r->link=p->link;
            free(p);
            p=r->link;
        }
        else
        {
            r=p;
            p=p->link;
        }
    }
}
