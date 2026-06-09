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
            if(i==-1) // @@ [This condition is never true because i starts at 0 and only increments or decrements; it's redundant and misleading.]
            i++;
            if(i<100)
            {
                scanf("%d ",&a[i]); // @@ [The space after %d in scanf can cause input parsing issues, especially when next input is immediately following without whitespace. It may consume extra whitespace unnecessarily and interfere with subsequent reads.]
                i++;
            }
            else if(i==100)
            {
                printf("error ");
                i++; // @@ [Incrementing i beyond 100 leads to invalid stack state; once stack is full, further pushes should not alter the stack pointer. This causes i to become 101, breaking future logic.]
            }
        }
        else if(y==0)
        {
            if(i==101) // @@ [This condition attempts to correct an invalid state caused by previous erroneous increment, but it's a symptom fix, not a root cause solution. Also, i should never reach 101 if push logic were correct.]
            i--;
            if(i!=0)
            {
                i--;
                if(i<0) // @@ [This check comes too late; i was already decremented, so if i was 0, it becomes -1, triggering "error", but the pop operation should have been rejected before decrementing.]
                printf("error ");
                else
                {
                     printf("%d ",a[i]);
                       a[i]=0;
                } 
            }
            // @@ [Missing else case: if i == 0, nothing is printed, but according to spec, "error " should be printed for pop on empty stack. This leads to silent failure instead of outputting "error ".]
        }
        else if(y==-1)
        break; 
    }
    return 0;
}