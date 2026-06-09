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
            if(i==-1) // @@ [This condition is never true since i starts at 0 and only increments or decrements; it's logically redundant and misleading]
            i++;
            if(i<100)
            {
                scanf("%d ",&a[i]); // @@ [The space after %d in scanf can cause input parsing issues by consuming extra whitespace unexpectedly, potentially skipping next operation tokens]
                i++;
            }
            else if(i==100)
            {
                printf("error ");
                i++; // @@ [Incrementing i beyond 100 leads to invalid stack state; once full, further pushes should not alter stack pointer]
            }
        }
        else if(y==0)
        {
            if(i==101) // @@ [i can never be 101 due to prior logic; this check is meaningless and indicates flawed boundary reasoning]
            i--;
            if(i!=0)
            {
                i--;
                if(i<0) // @@ [i is decremented before this check, so if i was 0, it becomes -1, but the outer if(i!=0) prevents that path; however, if i was 1, it becomes 0 and passes, so this i<0 check is unreachable and incorrect logic for underflow]
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