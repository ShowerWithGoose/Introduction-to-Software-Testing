#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int main()
{
    int t;
    int s[100];
    int n=-1;
    while(scanf("%d",&t)!=-1) // @@ [The loop condition should be while(scanf("%d",&t)==1 && t!=-1) because scanf returns the number of items read, not -1. Additionally, the loop does not terminate when t == -1; it continues reading further input incorrectly.]
    {
        if(t==1)
        {
            n++; // @@ [Missing check for stack full before incrementing n. The stack capacity is 100, so should check if n >= 99 before increment; if full, output "error" and do not push.]
            scanf("%d",&s[n]); // @@ [If n became 100 due to previous increment, this will write out of bounds. Also, the push should only be performed if stack is not full.]
            
        }
        if(t==0&&n!=-1) // @@ [This if-else structure is flawed. The else branch executes for any t that is not 0 (e.g., push operations). When t==1 and n==-1, it incorrectly prints "error" because n==-1 is true. The logic should separate pop and push into separate if-else if branches.]
        {
            
            printf("%d ",s[n]);
            n--;
        }
        else // @@ [This else should only apply when t==0 and the stack is empty, but it currently applies to all non-pop operations, causing spurious error messages on push.]
        {
            if(n==-1)
            {
                 printf("error ");
                          
            }
        }
    }
    return 0;
 }