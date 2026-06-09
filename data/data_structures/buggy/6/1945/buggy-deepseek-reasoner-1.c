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
            if(i==99) // @@ Full condition should check i==100 to prevent pushing beyond capacity. Currently allows push when i=99, leading to out-of-bounds when i reaches 100.
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
                a[i]=0; // @@ This line should output the popped value and decrement i correctly. It neither outputs nor correctly handles stack pointer. Should be printf("%d ",a[--i]); or similar.
                i--;
            }
        }
        scanf("%d",&x);
    }
    return 0;
}