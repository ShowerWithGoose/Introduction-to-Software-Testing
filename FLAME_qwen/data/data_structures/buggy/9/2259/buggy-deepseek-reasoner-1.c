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
                a->next=&l[i];
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
            continue; // @@ [Logical error: The continue statement skips the subsequent reset of low for this iteration, causing low to accumulate incorrectly for following segments.]
            low=1; // @@ [Logical error: The reset of low should occur before the if statement and independently of the condition, or the continue should be removed. As placed, low is only reset when low>high, not when low<=high due to continue.]
        }
    }
    printf("%d %d %d",high,t->a1,t->b1); // @@ [Potential undefined behavior: t may be uninitialized if no chain length exceeds 1, leading to dereferencing of indeterminate pointer.]
    return 0;
}