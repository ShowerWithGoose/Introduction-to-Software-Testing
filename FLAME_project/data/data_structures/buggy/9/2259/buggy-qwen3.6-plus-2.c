#include<stdio.h>
#include<string.h>
#include<stdlib.h>
    struct line{
        int a1,b1;
        int a2,b2;
        struct line *next;
    };
    struct line l[100];
    int n;
    int num[100];
void link(struct line *a)
{
    int judge=0;
    for(int i=0;i<n;i++)
    {
            if(a->a2==l[i].a1&&a->b2==l[i].b1)
            {
                judge=1;
                a->next=&l[i]; // @@ The function overwrites a->next in every iteration of the loop if a match is found, but more critically, it does not stop after finding the unique next segment (constraint says no 3+ segments share endpoint, but implies unique continuation). However, the main logical error is that `link` is called recursively but doesn't handle the case where `a->next` might have been set by a previous call or needs to be reset. More importantly, the recursion structure is flawed for calculating length later. But the immediate bug causing WA is likely in the counting logic below.
                link(&l[i]);
            }
            else
            continue;
    }
    if(judge==0)
    a->next = NULL;
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d%d%d",&l[i].a1,&l[i].b1,&l[i].a2,&l[i].b2);
    }
    for(int i=0;i<n;i++)
    {
        link(&l[i]);
    }
    int high=1,low=1;
    struct line *temp,*t;
    for(int i=0;i<n;i++)
    {
        temp=&l[i];
        while(temp->next !=NULL)
        {
            temp=temp->next ;
            low++;
        }
        
        {
            if(low>high)
            {
                high=low;
                t=&l[i];
            }
            else
            continue;
            low=1; // @@ This line is unreachable when low > high because of the 'else continue' above it? No, 'else continue' skips the rest of the loop body. If low <= high, it continues. If low > high, it updates high and t, but then falls through to low=1? Wait. The block structure is: if(...) { ... } else continue; low=1;. If the if condition is true, it executes the block, then executes low=1. If false, it continues to next iteration. So low IS reset. HOWEVER, low is not reset to 1 at the START of the loop for each i. It accumulates if the previous segment didn't update high? No, if low <= high, it continues, skipping low=1. So low retains its value from the previous iteration where it might have been large. This is the bug. low must be reset to 1 for EVERY new starting segment i.
        }
    }
    printf("%d %d %d",high,t->a1,t->b1);
    return 0;
}