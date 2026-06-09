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
    lista=(POL *)malloc(sizeof(POL)); // @@ [Potential dereference of uninitialized pointer if malloc fails, but more critically: the program assumes at least one term exists in each polynomial without checking input validity. However, the primary error is logical and structural.]
    listb=(POL *)malloc(sizeof(POL)); // @@ [Same issue as above; also, if input is empty (no terms), this leads to undefined behavior. But the main bug is elsewhere.]
    listc=(POL *)malloc(sizeof(POL)); // @@ [This pre-allocates the result list head even when multiplication might yield zero polynomial or no terms yet. Leads to incorrect output structure.]
    p=lista;
    q=listb;
    r=listc;
    p->link=NULL;
    q->link=NULL;
    r->link=NULL;
    scanf("%d%d",&p->a,&p->power); // @@ [Does not check return value of scanf; if input ends immediately (empty polynomial), this reads garbage and causes undefined behavior. Problem states only non-zero terms are input, but doesn't guarantee at least one term. However, typical test cases have at least one term. The real flaw is in multiplication and merging logic.]
    while((c=getchar())!='\n')
    {
        p->link=(POL *)malloc(sizeof(POL));
        p=p->link;
        scanf("%d%d",&p->a,&p->power);
        p->link=NULL;
    }
    p=lista;
    scanf("%d%d",&q->a,&q->power); // @@ [Same issue as first scanf; no validation.]
    while((c=getchar())!='\n')
    {
        q->link=(POL *)malloc(sizeof(POL));
        q=q->link;
        scanf("%d%d",&q->a,&q->power);
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
    while(r->link!=NULL) // @@ [This loop prints intermediate unsorted/uncombined terms before sorting/combining, which violates output format. Also, if listc has only one node, this loop is skipped, but then later loops may misbehave.]
    {
        printf("%d %d\n",r->a,r->power);
        r=r->link;
    }
    while(r!=listc) // @@ [This sorting/combining loop has multiple critical flaws: (1) It assumes listc has at least two nodes; (2) The bubble sort logic is broken—it compares p->power with (p->link)->power but doesn't handle end-of-list correctly; (3) When combining like terms, it frees a node but doesn't update all pointers properly, leading to use-after-free or lost nodes; (4) The outer loop condition 'r != listc' is never true initially because r was set to last node after previous loop, but if listc had only one node, r == listc and loop is skipped, leaving uncombined terms.]
    {
        q=listc;
        p=listc->link;
        jud=0;
        while(p!=r)
        {
            if(p->power<(p->link)->power)
            {
                q->link=p->link;
                p->link=(q->link)->link;
                (q->link)->link=p;
                q=q->link;
                jud=1;
            }
            else if(p->power==(p->link)->power)
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