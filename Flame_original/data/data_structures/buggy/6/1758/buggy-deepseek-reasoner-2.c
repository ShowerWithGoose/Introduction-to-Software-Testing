#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int main()
{
    int t;
    int s[100];
    int n=-1;
    while(scanf("%d",&t)!=-1) // @@ Loop should stop when t == -1, not on EOF. Also missing initial scanf before loop to read first operation.
    {
        if(t==1) // @@ Missing check for stack full (n >= 99) before push; should output "error " and not push if full.
        {
            n++;
            scanf("%d",&s[n]);
            
        }
        if(t==0&&n!=-1) // @@ Logic flawed: the else block below incorrectly triggers for non-pop operations. Should use else if to handle pop empty case specifically.
        {
            
            printf("%d ",s[n]);
            n--;
        }
        else // @@ This else applies when t is not 0 or when t==0 but n==-1. It should only apply to pop operations, not push or termination.
        {
            if(n==-1) // @@ This condition is true for non-pop operations (e.g., push with n=-1 or -1 with empty stack), causing incorrect "error " output.
            {
                 printf("error "); // @@ Prints error for non-pop situations like push (which is valid) or end-of-input, violating specification.
                          
            }
        }
    }
    return 0;
 }