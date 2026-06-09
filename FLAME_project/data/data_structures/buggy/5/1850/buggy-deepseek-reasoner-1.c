#include<stdio.h>
#include<stdlib.h>
typedef struct shi{
    struct shi* last;
    int xi;
    int zhi;
    struct shi* next;
}shi;
shi* creat(shi* list)
{
    shi *p=NULL,*q=NULL;
    char c[1000];
    gets(c);
    q=(shi*)malloc(sizeof(shi));
    int n=0,j=0;
    for(int i=0;c[i]!='\0';i++)
    {
        if(c[i]!=' ')
        {
            n*=10;
            n+=c[i]-'0';
        }
        else
        {
            if(j%2==0)
            {
                q->xi=n;
                n=0;
                j++;
            }
            else
            {
                q->zhi=n;
                n=0;
                j++;
                q->next=NULL;
                if(list!=NULL)
                {
                    p->next=q;
                    q->last=p;
                    p=q;
                }
                else
                {
                    q->last=NULL;
                    list=q;
                    p=q;
                }
                q=(shi*)malloc(sizeof(shi));
            }
        }
    }
    q->zhi=n;
    q->next=NULL;
    if(p!=NULL)
    {
        p->next=q;
        q->last=p;
    }
    else
    {
        list=q;
    }
    return list;
}
shi* cheng(shi*a,shi*b)
{
    shi *c=NULL,*p,*q,*r=NULL,*h=NULL;
    for(p=a;p->next!=NULL;p=p->next)  // @@ Loop condition skips the last node; for polynomials with one term, loop never runs, leaving h NULL.
    {
        for(q=b;q->next!=NULL;q=q->next)  // @@ Same issue: inner loop skips the last node.
        {
            r=(shi*)malloc(sizeof(shi));
            r->xi=p->xi*q->xi;
            r->zhi=p->zhi+q->zhi;
            r->next=NULL;
            if(c!=NULL)
            {
                h->next=r;
                r->last=h;
                h=r;
            }
            else
            {
                c=r;
                h=r;
            }
        }
        r=(shi*)malloc(sizeof(shi));
        r->xi=p->xi*q->xi;
        r->zhi=p->zhi+q->zhi;
        r->next=NULL;
        h->next=r;  // @@ If h is NULL (as happens with single‑term polynomials), this dereferences NULL, causing a runtime error.
        r->last=h;
        h=r;
    }
    for(q=b;q->next!=NULL;q=q->next)  // @@ Same loop condition error, and h may still be NULL from previous section.
        {
            r=(shi*)malloc(sizeof(shi));
            r->xi=p->xi*q->xi;
            r->zhi=p->zhi+q->zhi;
            r->next=NULL;
            if(c!=NULL)
            {
                h->next=r;
                r->last=h;
                h=r;
            }
            else
            {
                c=r;
                h=r;
            }
        }
        r=(shi*)malloc(sizeof(shi));
        r->xi=p->xi*q->xi;
        r->zhi=p->zhi+q->zhi;
        r->next=NULL;
        h->next=r;  // @@ Same NULL dereference issue.
        r->last=h;
        return c;
}
void sort(shi*c)
{
    shi *r=c;
    int temp;
    int n=1;
    while(r->next!=NULL)
    {
        n++;
        r=r->next;
    }
    for(int i=0;i<n;i++)
    {
        for(r=c;r->next!=NULL;r=r->next)
        {
            if(r->zhi<r->next->zhi)
            {
                temp=r->xi;
                r->xi=r->next->xi;
                r->next->xi=temp;
                temp=r->zhi;
                r->zhi=r->next->zhi;
                r->next->zhi=temp;
            }
        }
    }
    r=c;
    while(r->next!=NULL)
        {
            if(r->zhi==r->next->zhi)
            {
                r->xi+=r->next->xi;
                r->next=r->next->next;
                free(r->next->last);  // @@ After updating r->next, this free pointer is incorrect; it frees the last pointer of the new next node, not the removed node.
                r->next->last=r;
                r=r->last;  // @@ If r is the first node, r->last is NULL, causing subsequent access to NULL.
            }
            r=r->next;
        }
    r=c;
    while(r->next!=NULL)
    {
        printf("%d %d ",r->xi,r->zhi);
        r=r->next;    
    }
    printf("%d %d ",r->xi,r->zhi);
    return ;
}
int main()
{
    shi *a=NULL,*b=NULL,*c=NULL;
    a=creat(a);
    b=creat(b);
    c=cheng(a,b);
    sort(c);
    return 0;
}