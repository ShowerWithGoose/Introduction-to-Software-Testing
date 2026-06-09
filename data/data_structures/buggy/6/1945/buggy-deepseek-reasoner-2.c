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
            if(i==99) // @@ Error: condition for full stack should be i==100 (since array size is 100 and i is the next free index). With i==99, push is incorrectly rejected when 99 elements are present.
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
                a[i]=0; // @@ Error: Missing output of the popped element. Should print the top element before decrementing, e.g., printf("%d ",a[--i]);
                i--;
            }
        }
        scanf("%d",&x);
    }
    return 0;
}