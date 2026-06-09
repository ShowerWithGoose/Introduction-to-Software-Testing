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
            if(i==99) // @@ The stack capacity is 100, so the condition should be i == 100 to correctly detect when the stack is full.
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
                a[i]=0; // @@ This line should output the popped element using printf("%d ", a[i-1]); instead of assigning 0.
                i--;
            }
        }
        scanf("%d",&x);
    }
    return 0;
}