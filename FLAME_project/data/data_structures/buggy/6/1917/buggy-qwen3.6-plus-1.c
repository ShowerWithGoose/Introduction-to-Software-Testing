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
            if(i==-1) // @@ The condition `i==-1` is incorrect for checking stack fullness; it should check if the stack is full (e.g., `i==100`) before pushing. Also, logic for handling push when full is flawed.
            i++;
            if(i<100)
            {
                scanf("%d ",&a[i]); // @@ The space in format string "%d " may cause issues with input parsing, though less critical than logic errors. More importantly, `i` is incremented after assignment, which is correct for 0-indexed if `i` starts at 0, but the boundary checks are inconsistent.
                i++;
            }
            else if(i==100)
            {
                printf("error ");
                i++; // @@ Incrementing `i` when the stack is full leads to an invalid state (i becomes 101), causing subsequent operations to behave incorrectly. It should not increment `i` on error.
            }
        }
        else if(y==0)
        {
            if(i==101) // @@ This check `i==101` is arbitrary and results from the previous error. It doesn't correctly handle the empty stack condition.
            i--;
            if(i!=0) // @@ Checking `i!=0` is incorrect for determining if the stack is empty. If `i` represents the count of elements or the next index, an empty stack should be handled when `i==0`. This logic fails to print "error" when popping from an empty stack (when `i` is 0).
            {
                i--;
                if(i<0)
                printf("error ");
                else
                {
                     printf("%d ",a[i]);
                       a[i]=0;
                } 
            }
            else // @@ Missing else block to handle the case when `i==0` (empty stack). When `i==0`, it should print "error ". Currently, it does nothing, leading to missing "error" output.
            {
                printf("error ");
            }
        }
        else if(y==-1)
        break; 
    }
    return 0;
}