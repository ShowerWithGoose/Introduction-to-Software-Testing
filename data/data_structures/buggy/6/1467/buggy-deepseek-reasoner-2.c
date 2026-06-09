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
            room[++flag] = num; // @@ Missing check for stack overflow (capacity 100). Should verify flag < 110 before storing.
        }
        else if (op == 0)
        {
            flag--; // @@ Decrement flag before checking if stack is empty. This corrupts the stack state when pop is attempted on an empty stack.
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