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

LinkList mul(LinkList a, LinkList b) //乘法运算
{
    LinkList C;
    LinkList pa=a; LinkList pb=b;
    C = (LinkList)malloc(sizeof(math));
    C->xi =0;
    C->zhi = 0;
    C->next = NULL;
    while(pa!=NULL)
    {
        pb = b;
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
    LinkList a=NULL,b=NULL;
    LinkList c;
    LinkList pa,qa=a,pb,qb=b;
    long long XI; long long ZHI;
    int flag = 1;
    while((scanf("%lld%lld",&XI,&ZHI))!=EOF)
    {
        if(flag)
        {
            pa = (LinkList)malloc(sizeof(math));
            if(a==NULL)
                a = pa;
            else
                qa->next = pa;
            pa->xi = XI;
            pa->zhi = ZHI;
            qa = pa;
            pa->next = NULL;
        }
        else
        {  
            pb = (LinkList)malloc(sizeof(math));
            if(b==NULL)
                b = pb;
            else
                qb->next = pb;
            pb->xi = XI;
            pb->zhi = ZHI;
            qb = pb;
            pb->next = NULL;
        }
        if(getchar()=='\n') flag=0;
    }
    c = mul(a,b);
    LinkList t = c;
    while(t!=NULL)
    {
        if(t->xi != 0)
            printf("%lld %lld ",t->xi,t->zhi);
        t = t->next;
    }
}
