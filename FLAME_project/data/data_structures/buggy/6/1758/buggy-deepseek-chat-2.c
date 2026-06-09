#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int main()
{
    int t;
    int s[100];
    int n=-1;
    while(scanf("%d",&t)!=-1)
    {
        if(t==1)
        {
            n++;
            scanf("%d",&s[n]); // @@ Error: No check for stack overflow (n >= 100) before pushing. When the stack is full (n=99), incrementing n to 100 causes out-of-bounds access and missing "error" output.
            
        }
        if(t==0&&n!=-1)
        {
            
            printf("%d ",s[n]); // @@ Error: After popping, the element should be s[n] before decrementing n, but here n is not decremented before printing. The correct order is to print s[n] then decrement n, but the code prints s[n] and then decrements n, which is correct for the pop logic. However, the issue is that when n is -1 (empty stack), this branch is skipped, but the else branch incorrectly prints "error" even for valid operations like t==1 or t==-1.
            n--;
        }
        else
        {
            if(n==-1)
            {
                 printf("error "); // @@ Error: This else branch executes for any t that is not 0 or when n!=-1, including t==1 and t==-1. For example, when t==1 and n!=-1, it incorrectly prints "error". The condition should only check for pop on empty stack.
                          
            }
        }
    }
    return 0;
 }