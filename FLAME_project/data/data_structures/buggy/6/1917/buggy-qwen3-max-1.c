#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a[101]={0};
    int x,y,i=0;
    while(1)
    {
        scanf("%d",&y);
        if(y==1)
        {
            if(i==-1) // @@ [This condition is never true since i starts at 0 and only increases or decreases within valid bounds; it's redundant and misleading.]
            i++;
            if(i<100)
            {
                scanf("%d ",&a[i]); // @@ [Using "%d " (with trailing space) in scanf can cause unexpected blocking/waiting for extra input; should be "%d" without trailing space.]
                i++;
            }
            else if(i==100)
            {
                printf("error ");
                i++; // @@ [Incrementing i beyond 100 leads to invalid stack state; should not increment i on error.]
            }
        }
        else if(y==0)
        {
            if(i==101) // @@ [i will never be 101 due to prior logic; this check is meaningless and masks the real underflow condition.]
            i--;
            if(i!=0)
            {
                i--;
                if(i<0) // @@ [This check comes too late; i is decremented before checking, so underflow may already have occurred silently. Also, i<0 after decrement means original i was 0, which should have been caught before decrement.]
                printf("error ");
                else
                {
                     printf("%d ",a[i]);
                       a[i]=0;
                } 
            }
        }
        else if(y==-1)
        break; 
    }
    return 0;
}