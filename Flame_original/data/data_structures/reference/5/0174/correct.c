#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int a;
    int n;
    struct Node *next;
};
int main()
{
    int aa,nn;
    char c;
    struct Node *heada,*headb,*headc,*p,*q,*r0,*r,*cmp;
    heada = p = NULL;
    do
    {
        scanf("%d%d%c", &aa, &nn, &c);
        q = (struct Node *)malloc(sizeof(struct Node));
        q->a = aa;
        q->n = nn;
        q->next = NULL;
        if( heada == NULL)
            heada = p = q;
        else
        {
            p->next = q;
            p = p->next;
        }
    }
    while ( c != '\n');
    headb =p= NULL;
    do
    {
        scanf("%d%d%c", &aa, &nn, &c);
        q = (struct Node *)malloc(sizeof(struct Node));
        q->a = aa;
        q->n = nn;
        q->next = NULL;
        if( headb == NULL)
            headb = p = q;
        else
        {
            p->next = q;
            p = p->next;
        }
    }
    while ( c != '\n');
    p=heada;
    q=headb;
    cmp=(struct Node *)malloc(sizeof(struct Node));
    cmp->a=(p->a)*(q->a);
    cmp->n=(p->n)+(q->n);
    r=headc=cmp;
    for(p=heada; p!=NULL; p=p->next)
    {
        for(q=headb; q!=NULL; q=q->next)
        {
            cmp=(struct Node *)malloc(sizeof(struct Node));
            cmp->a=(p->a)*(q->a);
            cmp->n=(p->n)+(q->n);
            for (r=headc;r!=NULL;r0=r,r=r->next)
            {
                if (cmp->n>r->n)
                {
                    cmp->next = r;
                    r0->next =cmp;
                    break;
                }
                else if (cmp->n == r->n)
                {
                    r->a += cmp->a;
                    break;
                }
            }
            if (r == NULL)
                r0->next =cmp;
        }
    }
    headc->a/=2;
    for (r=headc;r!=NULL; r=r->next)
        printf("%d %d ",r->a,r->n);
    return 0;
}

