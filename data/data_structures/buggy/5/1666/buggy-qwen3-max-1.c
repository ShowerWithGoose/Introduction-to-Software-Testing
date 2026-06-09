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
    lista=(POL *)malloc(sizeof(POL)); // @@ [Potential dereference of uninitialized pointer if malloc fails; also, input may be empty, leading to reading into unverified allocation]
    listb=(POL *)malloc(sizeof(POL)); // @@ [Same issue: assumes input always has at least one term, but problem allows zero terms? However, problem states "non-zero terms", so at least one term expected. Still, no check for malloc failure.]
    listc=(POL *)malloc(sizeof(POL)); // @@ [Same as above; also, listc is initialized even if result polynomial might be zero (but problem says non-zero input terms, so product non-zero)]
    p=lista;
    q=listb;
    r=listc;
    p->link=NULL;
    q->link=NULL;
    r->link=NULL;
    scanf("%d%d",&p->a,&p->power); // @@ [No check for scanf success; if input is malformed or empty, undefined behavior]
    while((c=getchar())!='\n')
    {
        p->link=(POL *)malloc(sizeof(POL));
        p=p->link;
        scanf("%d%d",&p->a,&p->power); // @@ [Same: no scanf validation; also, getchar() may consume spaces/tabs before newline, causing premature loop exit or extra iterations]
        p->link=NULL;
    }
    p=lista;
    scanf("%d%d",&q->a,&q->power); // @@ [Same scanf issue]
    while((c=getchar())!='\n')
    {
        q->link=(POL *)malloc(sizeof(POL));
        q=q->link;
        scanf("%d%d",&q->a,&q->power); // @@ [Same scanf and getchar issues]
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
    while(r->link!=NULL) // @@ [This loop prints intermediate unsorted/uncombined terms; but problem requires final combined/sorted output only. Also, if only one term, this loop does nothing, which is okay, but logic below may fail]
    {
        printf("%d %d\n",r->a,r->power);
        r=r->link;
    }
    while(r!=listc) // @@ [If the product has only one term, r starts as listc, so r != listc is false, skipping combination/sorting. But more critically, r was advanced in previous loop; now r points to last node, but listc may have only one node -> r == listc, so loop skipped. However, the real error is that the combination/sorting logic is flawed and doesn't handle all cases.]
    {
        q=listc;
        p=listc->link;
        jud=0;
        while(p!=r)
        {
            if(p->power<(p->link)->power) // @@ [This condition tries to bubble sort in ascending order, but problem requires descending. Also, accessing p->link when p might be last node (but loop condition p!=r may prevent that). However, the bigger issue: combination of like terms is only done during sorting pass, but initial list has duplicates not adjacent, so combination may be missed.]
            {
                q->link=p->link;
                p->link=(q->link)->link;
                (q->link)->link=p;
                q=q->link;
                jud=1;
            }
            else if(p->power==(p->link)->power) // @@ [Combines adjacent like terms, but after multiplication, like terms may not be adjacent, so this misses combinations. Also, if p->link is NULL, this crashes. The loop condition p!=r doesn't guarantee p->link exists.]
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