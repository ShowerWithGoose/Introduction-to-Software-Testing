#include <stdio.h>
#include <stdlib.h>

typedef struct pol
{
    int a;
    int power;
    struct pol *link;
} POL;
int main()
{
    POL *lista=NULL,*listb=NULL;
    POL *p=NULL,*q=NULL;
    POL *listc=NULL,*r=NULL;
    char c;
    lista=(POL *)malloc(sizeof(POL)); // @@ [If the first input line is empty (no terms), this initial allocation leads to undefined behavior as scanf will fail and the node remains uninitialized. Also, no check for malloc failure.]
    listb=(POL *)malloc(sizeof(POL)); // @@ [Same issue: assumes at least one term in second polynomial; fails on empty input.]
    listc=(POL *)malloc(sizeof(POL)); // @@ [Assumes multiplication result has at least one term; if either input is empty (zero polynomial), this causes incorrect output or crash.]
    p=lista;
    q=listb;
    r=listc;
    p->link=NULL;
    q->link=NULL;
    r->link=NULL;
    scanf("%d%d",&p->a,&p->power); // @@ [No validation of scanf return value; if input is empty or malformed, behavior is undefined.]
    while((c=getchar())!='\n')
    {
        p->link=(POL *)malloc(sizeof(POL));
        p=p->link;
        scanf("%d%d",&p->a,&p->power); // @@ [Same issue: no check for scanf success; may read beyond available input.]
        p->link=NULL;
    }
    p=lista;
    scanf("%d%d",&q->a,&q->power); // @@ [Same unchecked scanf; also assumes second polynomial has at least one term.]
    while((c=getchar())!='\n')
    {
        q->link=(POL *)malloc(sizeof(POL));
        q=q->link;
        scanf("%d%d",&q->a,&q->power); // @@ [Unchecked scanf again.]
        q->link=NULL;
    }
    q=listb;
    int jud=0;
    while(p!=NULL)
    {
        while(q!=NULL)
        {
            if(jud==0)
            {
                r->a=p->a*q->a;
                r->power=p->power+q->power;
                jud=1;
            }
            else
            {
                r->link=(POL *)malloc(sizeof(POL));
                r=r->link;
                r->a=p->a*q->a;
                r->power=p->power+q->power;
                r->link=NULL;
            }
            q=q->link;
        }
        p=p->link;
        q=listb;
    }
    r=listc;
    p=listc;
    q=listc;
    while(r->link!=NULL) // @@ [This loop prints intermediate unsorted/uncombined terms with newline, which violates output format (should only print final result once).]
    {
        printf("%d %d\n",r->a,r->power);
        r=r->link;
    }
    while(r!=listc) // @@ [Logic error: r starts at last node (from previous loop), but condition r!=listc may never hold if listc has only one node, skipping sorting/combining entirely.]
    {
        q=listc;
        p=listc->link;
        jud=0;
        while(p!=r)
        {
            if(p->power<(p->link)->power) // @@ [Sorting logic flawed: compares p->power with (p->link)->power but accesses p->link without ensuring it's not NULL; also sorts in ascending order then prints descending?]
            {
                q->link=p->link;
                p->link=(q->link)->link;
                (q->link)->link=p;
                q=q->link;
                jud=1;
            }
            else if(p->power==(p->link)->power) // @@ [Again, p->link may be NULL here, causing segmentation fault. Also, combining like terms during sort is error-prone and incomplete.]
            {
                (p->link)->a+=p->a;
                q->link=p->link;
                free(p);
                p=q->link;
            }
            else
            {
                p=p->link;
                q=q->link;
            }
        }
        if(jud==0)
        {
            break;
        }
        r=q;
    }
    r=listc;
    while(r!=NULL)

    {
        printf("%d %d ",r->a,r->power);
        r=r->link;
    }
    return 0;
}