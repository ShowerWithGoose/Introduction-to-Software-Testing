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
                scanf("%d ",&a[i]); // @@ The space in "%d " may cause issues with input parsing, but more importantly, the index `i` is used before incrementing correctly relative to the stack state.
                i++;
            }
            else if(i==100)
            {
                printf("error ");
                i++; // @@ Incrementing `i` here leads to an invalid stack state (overflow), causing subsequent operations to behave incorrectly.
            }
        }
        else if(y==0)
        {
            if(i==101) // @@ This condition is unreachable or incorrect for checking empty stack. Should check if `i==0`.
            i--;
            if(i!=0) // @@ This condition fails to handle the case when the stack is empty (`i==0`). It should check if `i > 0` to pop, otherwise print "error".
            {
                i--;
                if(i<0) // @@ This check happens after decrementing, which is too late. The emptiness check should happen before attempting to pop.
                printf("error ");
                else
                {
                     printf("%d ",a[i]);
                       a[i]=0;
                } 
            }
            else // @@ Missing else block to handle the error case when stack is empty (i==0). The current structure skips printing "error" when i==0 initially.
            {
                 printf("error "); // @@ This line is missing in the original code, leading to no output for pop on empty stack.
            }
        }
        else if(y==-1)
        break; 
    }
    return 0;
}