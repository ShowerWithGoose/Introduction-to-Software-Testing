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
    lista=(POL *)malloc(sizeof(POL));
    listb=(POL *)malloc(sizeof(POL));
    listc=(POL *)malloc(sizeof(POL));
    p=lista;
    q=listb;
    r=listc;
    p->link=NULL;
    q->link=NULL;
    r->link=NULL;
    scanf("%d%d",&p->a,&p->power);
    while((c=getchar())!='\n')
    {
        p->link=(POL *)malloc(sizeof(POL));
        p=p->link;
        scanf("%d%d",&p->a,&p->power);
        p->link=NULL;
    }
    p=lista;
    scanf("%d%d",&q->a,&q->power);
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
    while(r->link!=NULL) // @@ [This loop prints intermediate unsorted/unmerged results with newlines, which corrupts the final output format. The problem requires a single line of space-separated values. This debug-style printing causes the "Wrong Answer" due to extra lines and values.]
    {
        printf("%d %d\n",r->a,r->power);
        r=r->link;
    }
    while(r!=listc) // @@ [At this point, r is at the end of the list (or NULL if list was empty, but it's not). The condition r!=listc is likely false immediately if r traversed to the end, or logic is flawed for sorting. More critically, the previous loop moved r to the end. The sorting logic below assumes r is a sentinel or end marker, but the initialization `r=listc` followed by the previous `while(r->link!=NULL)` loop leaves `r` pointing to the last node. The condition `while(r!=listc)` will be true if the list has more than 1 element, but the inner logic relies on `p` and `q` traversal. However, the major issue is that the previous print loop already consumed the output buffer with incorrect format. Even if we ignore the previous print, the sorting algorithm is a bubble-sort variant. Let's look at the next error.]
    {
        q=listc;
        p=listc->link;
        jud=0;
        while(p!=r)
        {
            if(p->power<(p->link)->power) // @@ [Potential crash if p->link is NULL. The loop condition is p!=r. If r is the last node, p can become the node before r. Then p->link is r. If r is NULL? No, r is last node. But if the list is not circular, p->link might be NULL if p reaches the end. However, the loop stops at r. If r is the last node, p stops at the node before r. So p->link is r, which is valid. But wait, if the list has only 1 element, the outer loop doesn't run. If it has 2, p=listc->link, r=last. p!=r is false? No, p is second, r is second. So inner loop doesn't run. The logic seems to assume r moves backwards? No, r is fixed in this pass? No, r is updated at the end. This is a bubble sort where r marks the end of the unsorted portion. However, there is a critical bug: if p->link is NULL inside the loop, accessing (p->link)->power crashes. This happens if r is not properly set to the last node initially or if the list structure is broken. But the primary reason for WA is the extra output above.]
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