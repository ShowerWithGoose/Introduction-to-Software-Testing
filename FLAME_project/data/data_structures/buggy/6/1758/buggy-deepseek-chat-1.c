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
            scanf("%d",&s[n]); // @@ Error: No check for stack overflow (n >= 100) before pushing. When the stack is full, pushing should output "error " and not modify the stack.
            
        }
        if(t==0&&n!=-1)
        {
            
            printf("%d ",s[n]); // @@ Error: After popping, the top index should be decremented before printing, or the element at index n should be printed and then n decremented. Currently, it prints s[n] but n is the index of the top element before pop, which is correct, but the logic is flawed because n is not decremented before the next operation. Actually, the issue is that n is decremented after printing, but the condition for empty stack check is incorrect. The correct logic should decrement n after printing, but the empty check should be n == -1 before pop. Here, the condition `t==0&&n!=-1` is correct for non-empty, but the else clause incorrectly prints "error " for any t that is not 0 and not 1, including when t==-1, causing extra output.
            n--;
        }
        else
        {
            if(n==-1)
            {
                 printf("error "); // @@ Error: This else block executes for any t that is not 0 (including t==1 and t==-1) when n==-1, causing "error " to be printed incorrectly. For example, when t==1 and n==-1, it prints "error " even though it's a valid push. Also, when t==-1, it prints "error " if n==-1, which is wrong.
                          
            }
        }
    }
    return 0;
 }