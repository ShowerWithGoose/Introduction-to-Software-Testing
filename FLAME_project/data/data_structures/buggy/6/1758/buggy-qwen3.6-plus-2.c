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
        else // @@ The 'else' is associated with the immediately preceding 'if(t==0&&n!=-1)'. This means if t==1 (push), the else block executes. Since n != -1 after a push, it doesn't print error, but logically this structure is fragile. However, the main bug is below.
        {
            if(n==-1)
            {
                 printf("error "); // @@ This logic is flawed. When t==0 and n==-1 (stack empty), the condition 'if(t==0&&n!=-1)' is false, so it enters this else block. Then 'if(n==-1)' is true, printing "error ". This part is actually correct for the empty pop case. 
                          
            }
        }
        // The actual issue is that when t==1, we enter the first if. Then we check the second if (t==0...), which is false. Then we go to else. Inside else, we check if n==-1. If we just pushed, n>=0, so nothing happens. This seems okay for push.
        // Let's re-evaluate the test case: 1 567 0 -1
        // 1. Read t=1. n becomes 0. s[0]=567.
        // 2. Check if(t==0 && n!=-1). False.
        // 3. Enter else. Check if(n==-1). False (n is 0). Do nothing.
        // 4. Loop continues. Read t=0.
        // 5. Check if(t==1). False.
        // 6. Check if(t==0 && n!=-1). True (0==0 and 0!=-1).
        // 7. Print s[0] which is 567. n becomes -1.
        // 8. Skip else.
        // 9. Loop continues. Read t=-1.
        // 10. Check if(t==1). False.
        // 11. Check if(t==0 && n!=-1). False (-1!=0).
        // 12. Enter else. Check if(n==-1). True. Print "error ".
        // 13. Output: "567 error ". Expected: "567 ".
        
        // The error is that the code processes -1 as an operation that triggers the else block, checking if the stack is empty. But -1 is the termination signal, not a pop operation.
        // The loop condition `while(scanf("%d",&t)!=-1)` checks for EOF or read error, not the value -1.
        // We need to break when t == -1.
    }
    return 0;
 }