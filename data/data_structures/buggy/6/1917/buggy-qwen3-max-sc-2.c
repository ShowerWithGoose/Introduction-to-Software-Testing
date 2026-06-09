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
            if(i==-1) // @@ [This condition is never true since i starts at 0 and only increments; it's logically redundant and misleading]
            i++;
            if(i<100)
            {
                scanf("%d ",&a[i]); // @@ [The space after %d in scanf can cause input parsing issues, especially when next input is immediately following without whitespace]
                i++;
            }
            else if(i==100)
            {
                printf("error ");
                i++; // @@ [Incrementing i beyond 100 leads to invalid stack state; should not increment on error]
            }
        }
        else if(y==0)
        {
            if(i==101) // @@ [i can never be 101 here because max push stops at i==100; this check is meaningless]
            i--;
            if(i!=0)
            {
                i--;
                if(i<0) // @@ [i cannot be <0 here because i!=0 ensures i>=1 before decrement, so i>=0 after; this check is redundant]
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