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
            room[++flag] = num; // @@ Missing check for stack full condition (max capacity 100). Should output "error " and not push when full.
        }
        else if (op == 0)
        {
            flag--; // @@ Decrements the stack pointer before checking if the stack is empty, which corrupts the state and leads to incorrect indexing.
            if (flag < 0) // @@ Checks for underflow after decrementing; should check if flag == 0 before decrementing to properly handle empty stack pops.
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