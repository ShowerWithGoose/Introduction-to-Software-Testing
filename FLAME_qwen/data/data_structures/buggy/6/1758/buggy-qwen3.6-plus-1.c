#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int main()
{
    int t;
    int s[100];
    int n=-1;
    while(scanf("%d",&t)!=-1) // @@ scanf returns the number of successfully read items, not the value of t. The loop should check t != -1 to correctly terminate operations.
    {
        if(t==1) // @@ Missing check for stack full (n == 99). Should print "error " and avoid pushing when capacity is reached.
        {
            n++;
            scanf("%d",&s[n]);
            
        }
        if(t==0&&n!=-1) // @@ Incorrect logic structure. Combining t==0 and n!=-1 causes the following else block to execute for any t != 0 when n == -1, printing "error " incorrectly.
        {
            
            printf("%d ",s[n]);
            n--;
        }
        else // @@ This else is incorrectly attached to the combined if condition. It should only handle the pop operation when the stack is empty (t == 0 && n == -1).
        {
            if(n==-1)
            {
                 printf("error ");
                      
            }
        }
    }
    return 0;
 }