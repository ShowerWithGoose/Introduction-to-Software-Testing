#include<stdio.h>
int a[100]={0};
int main()
{
    int x,i=0;
    scanf("%d",&x);
    while(x!=-1)
    {
        if(x==1)
        {
            scanf("%d",&x);
            if(i==99)
            {
                printf("error ");
            }
            else
            {
                a[i]=x;
                i++;
            }
        }
        else
        {
            if(i==0)
            {
                printf("error ");
            }
            else
            {
                i--; // @@ The original code incorrectly assigns 0 to a[i] before decrementing, failing to output the popped element. It should print a[i-1] (the top element) and then decrement i.
                printf("%d ", a[i]); // @@ Added to output the popped element as required by the problem description.
            }
        }
        scanf("%d",&x);
    }
    return 0;
}