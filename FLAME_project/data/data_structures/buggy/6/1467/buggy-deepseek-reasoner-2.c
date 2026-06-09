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
            room[++flag] = num; // @@ Error: Missing capacity check (max 100). Also pre-increment causes index misalignment when flag is negative (after pop on empty stack).
        }
        else if (op == 0)
        {
            flag--; // @@ Error: Decrementing before checking emptiness. Should only decrement after confirming stack is not empty.
            if (flag < 0)
            {
                printf("error ");
            }
            else
            {
                printf("%d ",room[flag+1]);
            }
        }
    }
    return 0;
}