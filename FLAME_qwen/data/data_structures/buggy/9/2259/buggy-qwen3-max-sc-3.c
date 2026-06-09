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
            continue;
            low=1; // @@ [The variable 'low' is reset after the if-else block, but it should be reset in every iteration of the loop regardless of whether the condition was true or false. This causes 'low' to retain its value from previous iterations when the condition is false, leading to incorrect counts.]
        }
    }
    printf("%d %d %d",high,t->a1,t->b1); // @@ [The pointer 't' may be used uninitialized if no segment chain is longer than 1 (i.e., 'high' remains 1 and the if (low > high) block never executes). This leads to undefined behavior.]
    return 0;
}