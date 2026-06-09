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
    while(r->link!=NULL) // @@ [This loop prints intermediate unsorted/unmerged results with newlines, which corrupts the final output format. The problem requires only the final sorted result printed on one line. This block should be removed or commented out.]
    {
        printf("%d %d\n",r->a,r->power);
        r=r->link;
    }
    while(r!=listc) // @@ [Logic error: 'r' is currently at the end of the list (or NULL if list was empty, but here it's end). The condition 'r!=listc' attempts to iterate backwards or use r as a boundary for bubble sort passes, but r is not reset to the end of the list properly for each pass, and the logic for bubble sort boundary update is flawed. Specifically, after the previous while loop, r points to the last node. The intention is likely to perform bubble sort passes. However, standard bubble sort on linked list usually iterates from head. Here, it tries to reduce the range. But 'r' is not updated correctly to the new tail of the unsorted portion inside the loop effectively for the next iteration in all cases, and the inner loop logic relies on p->link being valid.]
    {
        q=listc;
        p=listc->link;
        jud=0;
        while(p!=r)
        {
            if(p->power<(p->link)->power) // @@ [Runtime Error: If p->link is NULL (i.e., p is the last node), accessing (p->link)->power causes a segmentation fault. The loop condition 'p!=r' ensures p doesn't reach r, but if r is the last node, p can become the second-to-last node, making p->link the last node (valid). However, if the list has only 1 element, p starts as listc->link which is NULL. The outer while(r!=listc) might not execute if r==listc initially? No, r is last node. If list has 1 node, r==listc, loop doesn't run. If list has 2 nodes, r is 2nd node. p is 1st node. p!=r is true. p->link is 2nd node (r). Accessing (p->link)->power is safe. The crash likely comes from the previous printing loop modifying nothing but moving r to NULL if list was empty? No, listc is dummy head? No, listc is first node. Wait, listc is allocated and filled. If the multiplication produced only 1 term, jud=1 only once. r is listc. r->link is NULL. The first while(r->link!=NULL) doesn't execute. r is still listc. Then while(r!=listc) is false. So it skips sorting. Then it prints.
            // The actual issue in WA is likely the extra output from the first printing loop.
            // Let's look at the sorting logic again.
            // If p->power < p->link->power, swap.
            // The condition p->link might be NULL if p is the last node in the unsorted part?
            // The loop runs while p != r. r is the boundary.
            // In bubble sort, the largest element bubbles to the end.
            // If we swap p and p->link, p moves forward.
            // If we don't swap, p moves forward.
            // Does p->link ever become NULL inside the loop?
            // If r is the last node, p stops before r. So p->link is at least r (valid).
            // So access is safe IF r is always a valid node in the list.
            // However, the variable 'jud' is used to check if any swaps occurred.
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
        r=q; // @@ [Logic Error: Updating the boundary 'r' to 'q' is incorrect for bubble sort. 'q' trails 'p'. After a full pass, the largest element is at the end of the unsorted portion. The boundary should move to the node before the current boundary 'r' (i.e., the new end of the unsorted list). Setting r=q arbitrarily cuts off the list incorrectly or doesn't shrink the range properly towards the head.]
    }
    r=listc;
    while(r!=NULL)

    {
        printf("%d %d ",r->a,r->power);
        r=r->link;
    }
    return 0;
}