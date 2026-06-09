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
            if(i==-1) // @@ [This condition is never true since i starts at 0 and only increments; it's logically redundant and misleading.]
            i++;
            if(i<100)
            {
                scanf("%d ",&a[i]); // @@ [The space after %d in scanf can cause input parsing issues, especially when next input is immediately following without whitespace.]
                i++;
            }
            else if(i==100)
            {
                printf("error ");
                i++; // @@ [Incrementing i beyond 100 leads to invalid stack state; once full, further pushes should not alter i.]
            }
        }
        else if(y==0)
        {
            if(i==101) // @@ [i will never be 101 due to prior logic; this check is meaningless and masks real underflow condition.]
            i--;
            if(i!=0)
            {
                i--;
                if(i<0) // @@ [This check comes too late; i was already decremented, so underflow (i==0 before pop) isn't caught correctly.]
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