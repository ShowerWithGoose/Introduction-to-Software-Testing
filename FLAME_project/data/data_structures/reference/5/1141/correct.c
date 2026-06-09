#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node{
    int xi;
    int mi;
    struct node *next;
};
struct res{
    int xr;
    int mr;
    struct res *link;
};
int main()
{
    struct node *first = NULL, *p, *q,*p0;
    struct res *firstr = NULL, *pr, *qr,*pr0,*p1;
    int a,b;
    char c;
    while(scanf("%d%d%c",&a,&b,&c))
    {
        q = (struct node *)malloc(sizeof(struct node));
        q->xi = a;
        q->mi = b;
        q->next = NULL;
        if (first == NULL)
            first = p = q;
        else
        {
            p->next = q;
            p = p->next;
        }
        if(c=='\n')
            break;
    }
    int a1, b1;
    while (scanf("%d%d%c", &a, &b, &c))
    {
        for (p = first; p!= NULL; p = p->next)
        {
            a1 = a * p->xi;
            b1 = b + p->mi;
            qr = (struct res *)malloc(sizeof(struct res));
            qr->xr = a1;
            qr->mr = b1;
            qr->link = NULL;
            if (firstr == NULL)
            firstr = pr = qr;
            for (p1 = firstr; p1 != NULL;pr0=p1,p1=p1->link)
            {
                if(qr->mr>p1->mr)
                {
                    if(p1==firstr)
                    {
                        qr->link = firstr;
                        firstr = qr;
                        break;
                    }
                    else
                    {
                        qr->link = p1;
                        pr0->link = qr;
                        break;
                    }
                }
                else if(qr->mr==p1->mr)
                {
                    p1->xr+=qr->xr;
                    break;
                }
            }
            if(p1==NULL)
                    pr0->link = qr;
        }
        if (c == '\n')
            break;
    }
    for (pr = firstr; pr != NULL;pr=pr->link)
    {
        if(pr==firstr)
        printf("%d %d ", pr->xr/2, pr->mr);
        else
        printf("%d %d ", pr->xr, pr->mr);
    }
    return 0;
}
