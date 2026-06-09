#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
typedef struct node
{
    int xi,zh;
    struct node *next;
}LNode,*LinkList;
LinkList CreateList(int n,int a[],int b[])
{
    LinkList p,r,L=NULL;
    int i;
    for(i=0;i<n;i++)
    {
        p=(LNode *)malloc(sizeof(LNode));
        p->xi=a[i];
        p->zh=b[i];
        p->next=NULL;
        if(L==NULL) L=p;
        else r->next=p;
        r=p;
    }
    return L;
};
LinkList InsertbyOrder(LinkList L,int temxi,int temzh)
{
    LNode *p,*q,*r;
    p=(LinkList)malloc(sizeof(LNode));
    p->xi=temxi;
    p->zh=temzh;
    if(L==NULL||temzh<L->zh)
    {
        p->next=L;
        return p;
    }
    else
    {
        q=L;
        while(q!=NULL&&temzh>=q->zh)
        {
            r=q;
            q=q->next;
        }
        if(r->zh==temzh)
        {
            r->xi+=temxi;
        }
        else
        {
            p->next=q;
            r->next=p;
        }
        return L;
    }
};
LinkList InvertList(LinkList L)
{
    LinkList p,q,r;
    p=L;
    q=NULL;
    while(p!=NULL)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    return q;
};
int PutList(LinkList L)
{
    if(L==NULL)
    {
        printf("ERROR");
        return 0;
    }
    LNode *p;
    p=L;
    printf("%d %d\n",p->xi,p->zh);
    while(p->next!=NULL)
    {
        p=p->next;
        printf("%d %d\n",p->xi,p->zh);
    }
    return 1;
};
int main()
{
    int a[100]={0},b[100]={0};
    int i=0;
    int temxi=0,temzh=0;
    LinkList L1,L2,L3=NULL;
    LNode *p,*q,*r;
    char c;
    while(scanf("%d%d%c",&a[i],&b[i],&c)!=EOF)
    {
        i++;
        if(c=='\n') break;
    }
    L1=CreateList(i,a,b);
    i=0;
    while(~scanf("%d%d%c",&a[i],&b[i],&c))
    {
        i++;
        if(c=='\n') break;
    }
    L2=CreateList(i,a,b);
    /*a[1]=10;b[1]=80000;
    a[2]=2;b[2]=6000;
    a[3]=7;b[3]=300;
    a[4]=5;b[4]=10;
    a[5]=18;b[5]=0;
    L1=CreateList(5,a,b);*/
    //PutList(L1);
    /*a[1]=3;b[1]=6000;
    a[2]=5;b[2]=20;
    a[3]=8;b[3]=10;
    a[4]=6;b[4]=0;
    L2=CreateList(4,a,b);*/
    //PutList(L2);
    p=L1;q=L2;
    while(p!=NULL)
    {
        q=L2;
        while(q!=NULL)
        {
            temxi=p->xi*q->xi;
            temzh=p->zh+q->zh;
            L3=InsertbyOrder(L3,temxi,temzh);
            q=q->next;
        }
        p=p->next;
    }
    //PutList(L3);
    r=InvertList(L3);
    while(r!=NULL&&r->xi!=0)
    {
        printf("%d %d ",r->xi,r->zh);
        r=r->next;
    }

    return 0;
}


