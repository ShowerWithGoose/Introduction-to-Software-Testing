#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct MATH
    {
        long long xi;
        long long zhi;
        struct MATH * next;
    }math, *LinkList;

void INSERTLINK(LinkList * list, long long zhi, long long xi) //建立有序链表
{
    LinkList p,q,r; // p为前 q为后 r为读入
    r = (LinkList)malloc(sizeof(math));
    r->zhi = zhi;
    r->xi = xi;
    r->next = NULL;
    if(*list == NULL || zhi > (*list)->zhi)
    {
        p = *list;
        r->next = p;
        *list = r; 
    }
    else
    {
        p = *list;
        while(zhi < p->zhi && p != NULL) //不能给等于，若给等于，p到下一个（接下）
        {
            q = p;  p = p->next;
        }
        if(zhi == p->zhi) //（接上，此处不可做）
        {
            p->xi = p->xi + xi;  return;
        }
        else
        {
            q->next = r;  r->next = p;
        }
    }
}

LinkList mul(LinkList x1, LinkList x2) //乘法运算
{
    LinkList C;
    LinkList pa=x1; LinkList pb=x2;
    C = (LinkList)malloc(sizeof(math));
    C->xi =0;
    C->zhi = 0;
    C->next = NULL;
    while(pa!=NULL)
    {
        pb = x2;
        while(pb!=NULL)
        {
            INSERTLINK(&C, (pa->zhi + pb->zhi),(pa->xi * pb->xi));
            pb = pb->next;
        }
        pa = pa->next;
    }
    return C;
}

int main()
{
    LinkList x1=NULL,x2=NULL;
    LinkList c;
    LinkList pa,qa=x1,pb,qb=x2;
    long long xi; long long zhi;
    int flag = 1;
    while((scanf("%lld%lld",&xi,&zhi))!=EOF)
    {
        if(flag)
        {
            pa = (LinkList)malloc(sizeof(math));
            if(x1==NULL)
                x1 = pa;
            else
                qa->next = pa;
            pa->xi = xi;
            pa->zhi = zhi;
            qa = pa;
            pa->next = NULL;
        }
        else
        {  
            pb = (LinkList)malloc(sizeof(math));
            if(x2==NULL)
                x2 = pb;
            else
                qb->next = pb;
            pb->xi = xi;
            pb->zhi = zhi;
            qb = pb;
            pb->next = NULL;
        }
        if(getchar()=='\n') flag=0;
    }
    c = mul(x1,x2);
    LinkList g = c;
    while(g!=NULL)
    {
        if(g->xi != 0)
            printf("%lld %lld ",g->xi,g->zhi);
        g = g->next;
    }
}
