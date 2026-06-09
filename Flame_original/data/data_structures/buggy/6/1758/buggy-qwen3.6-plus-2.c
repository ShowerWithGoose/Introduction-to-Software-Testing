#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int main()
{
    int t;
    int s[100];
    int n=-1;
    while(scanf("%d",&t)!=-1) // @@ The loop condition incorrectly checks scanf's return value against -1 (EOF) instead of checking if the read value t equals -1, which is the specified terminator for operations.
    {
        if(t==1) // @@ Missing check for stack full condition (n >= 99). Should output "error " if the stack is full, and still consume the next integer from input.
        {
            n++; // @@ Increments the stack pointer without checking capacity, which can lead to array out-of-bounds access when the stack is full.
            scanf("%d",&s[n]); // @@ Reads the value to push. If the stack is full, this should still consume the input value but not store it in the array.
            
        }
        if(t==0&&n!=-1) // @@ Combining the operation check with the empty check here causes the subsequent else block to incorrectly execute for t==1 cases, printing "error " when pushing to an empty stack.
        {
            
            printf("%d ",s[n]);
            n--;
        }
        else // @@ This else block is incorrectly associated with the combined condition above. It should only handle the t==0 case when the stack is empty, not t==1 cases.
        {
            if(n==-1)
            {
                 printf("error ");
                          
            }
        }
    }
    return 0;
 }