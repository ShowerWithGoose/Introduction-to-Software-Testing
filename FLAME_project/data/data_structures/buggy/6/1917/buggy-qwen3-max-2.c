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
                scanf("%d ",&a[i]); // @@ [The space after %d in scanf can cause issues by consuming extra whitespace, potentially interfering with the next input read. It should be just "%d".]
                i++;
            }
            else if(i==100)
            {
                printf("error ");
                i++; // @@ [Incrementing i beyond 100 is incorrect. On stack full, we should not modify the stack pointer i. This leads to invalid state (i becomes 101), causing later logic errors.]
            }
        }
        else if(y==0)
        {
            if(i==101) // @@ [This condition tries to correct an invalid state caused by the earlier erroneous i++ when stack was full. However, this is a symptom fix, not a root cause fix. The real issue is allowing i to go beyond 100.]
            i--;
            if(i!=0)
            {
                i--;
                if(i<0) // @@ [This check comes too late: i is decremented before checking if it was already 0. If i was 0, then i-- makes it -1, and then we print "error", but the pop operation should have been rejected before modifying i.]
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