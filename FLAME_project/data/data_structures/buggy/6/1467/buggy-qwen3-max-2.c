#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
int main()
{
    int op,num,flag=0,room[110]={0};
    while (~scanf("%d",&op))
    {
        if (op == -1)
        {
            break;
        }
        else if (op == 1)
        {
            scanf("%d",&num);
            room[++flag] = num; @@ [The push operation increments flag before storing, so the stack top is at index flag, but this causes two issues: (1) it uses 1-based indexing which complicates empty/full checks, and (2) it doesn't check for stack overflow when flag reaches 100 (max capacity).]
        }
        else if (op == 0)
        {
            flag--;
            if (flag < 0)
            {
                printf("error ");
            }
            else
            {
                printf("%d ",room[flag+1]); @@ [After decrementing flag, the popped element should be room[flag+1], but because push used pre-increment, the actual top is at room[flag]. However, the real issue is that after a failed pop (flag<0), flag becomes -1, and subsequent operations behave incorrectly. Also, the initial state has flag=0 meaning empty, so first pop makes flag=-1, which is correct for error, but the indexing logic is inconsistent due to using ++flag on push.]
            }
        }
    }
    return 0;
}