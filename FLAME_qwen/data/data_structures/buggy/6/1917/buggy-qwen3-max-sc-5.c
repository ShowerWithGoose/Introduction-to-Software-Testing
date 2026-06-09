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
            if(i==-1) // @@ [This condition is never true since i starts at 0 and only increments or decrements in controlled ways; it's logically redundant and misleading.]
            i++;
            if(i<100)
            {
                scanf("%d ",&a[i]); // @@ [The format string "%d " consumes trailing whitespace, which may cause the next input to be read prematurely or block waiting for extra input. It should be "%d" without the space.]
                i++;
            }
            else if(i==100)
            {
                printf("error ");
                i++; // @@ [Incrementing i beyond 100 leads to invalid stack state; once stack is full, further pushes should not alter i. Also, this causes i to become 101, which breaks future logic.]
            }
        }
        else if(y==0)
        {
            if(i==101) // @@ [This condition attempts to correct an invalid i value from earlier error, but it's a flawed fix. The real issue is allowing i to exceed valid bounds (0–100).]
            i--;
            if(i!=0)
            {
                i--;
                if(i<0) // @@ [This check comes too late—i was already decremented, so if i was 0, it becomes -1 and triggers "error", but the pop operation should have been rejected before decrementing.]
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