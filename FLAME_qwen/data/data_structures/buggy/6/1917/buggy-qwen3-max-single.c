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
                scanf("%d ",&a[i]); // @@ [The space after %d in scanf can cause input parsing issues by consuming extra whitespace unexpectedly, potentially skipping or misreading subsequent inputs.]
                i++;
            }
            else if(i==100)
            {
                printf("error ");
                i++; // @@ [Incrementing i beyond 100 leads to invalid stack state; once full, further pushes should not alter i. Also, error should be printed without trailing space inconsistency (though minor).]
            }
        }
        else if(y==0)
        {
            if(i==101) // @@ [i will never reach 101 due to prior logic; this check is meaningless and indicates flawed boundary reasoning.]
            i--;
            if(i!=0)
            {
                i--;
                if(i<0) // @@ [This check comes too late; i was just decremented from 0, making it -1, but the condition i!=0 allowed entry when i was 0, which is incorrect. Should check i==0 before decrementing.]
                printf("error ");
                else
                {
                     printf("%d ",a[i]);
                       a[i]=0; // @@ [Unnecessary assignment; does not affect output but shows misunderstanding of stack model. Not an error per se, but distracts from real issues.]
                } 
            }
        }
        else if(y==-1)
        break; 
    }
    return 0;
}