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
            scanf("%d",&s[n]);
            
        }
        if(t==0&&n!=-1)
        {
            
            printf("%d ",s[n]);
            n--;
        }
        else // @@ The 'else' is associated with the immediately preceding 'if(t==0&&n!=-1)'. This means if t==1 (push), the else block executes. If n was -1 before the push, n is now 0, so n!=-1 is true inside the push block, but here in the else, it checks n==-1. However, the main logic error is that this else block runs for Push operations (t==1) as well. For a valid push, we don't want to print anything. But specifically for the test case: Push 567 (n becomes 0). Then Pop 0. t==0, n!=-1 (0!=-1) is true. Prints 567. n becomes -1. Then loop continues? No, input ends. Wait. The input is "1 567 0 -1". 
        // Let's trace:
        // 1. scanf reads 1. t=1. if(t==1) -> n becomes 0. scanf reads 567 into s[0].
        // 2. if(t==0 && n!=-1) -> 1==0 is false. Skips.
        // 3. else -> executes because previous if was false. Checks if(n==-1). n is 0. False. Does nothing.
        // 4. Loop continues. scanf reads 0. t=0.
        // 5. if(t==1) -> false.
        // 6. if(t==0 && n!=-1) -> 0==0 true, n=0 != -1 true. Enters block. Prints s[0] (567). n becomes -1.
        // 7. else -> skipped because if was true.
        // 8. Loop continues. scanf reads -1. t=-1.
        // 9. if(t==1) -> false.
        // 10. if(t==0 && n!=-1) -> -1==0 false. Skips.
        // 11. else -> executes. Checks if(n==-1). n is -1. True. Prints "error ".
        // Output: "567 error ". Expected: "567 ".
        // The error is that the code processes -1 as a command that falls through to the else block, triggering an error check on an empty stack, instead of breaking the loop. The reference program breaks on -1. This program does not handle -1 to break.
        {
            if(n==-1)
            {
                 printf("error ");
                          
            }
        }
    }
    return 0;
 }