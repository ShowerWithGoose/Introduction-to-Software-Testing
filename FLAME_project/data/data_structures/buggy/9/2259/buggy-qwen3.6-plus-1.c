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
                a->next=&l[i]; // @@ The logic incorrectly assumes a linear chain and overwrites 'next' if multiple segments could potentially connect (though constraint says max 2 share an endpoint, the recursion structure is flawed for counting). More critically, it doesn't prevent revisiting nodes or handling the graph structure correctly for longest path in a general sense, but specifically here, it modifies the global state 'l[i].next' potentially causing issues if 'l[i]' is visited from another path later, or simply building a single linked list that might not represent the full depth if not careful. However, the primary error is in the main loop's counting logic.
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
            low=1; // @@ This line is unreachable when 'low > high' because of the 'else continue' above it? No, 'else continue' skips the rest of the loop body. But if 'low <= high', it continues. If 'low > high', it updates high/t, then falls through to 'low=1'. Wait, the brace structure is: if(...) { ... } else continue; low=1;. If low>high, it executes block, then executes low=1. If low<=high, it hits continue, skipping low=1. So 'low' is not reset to 1 for the next iteration if the current segment wasn't the best. This causes 'low' to accumulate or remain stale for subsequent iterations.
        }
    }
    printf("%d %d %d",high,t->a1,t->b1);
    return 0;
}