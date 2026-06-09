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
            room[++flag] = num; // @@ [Pushes element even when stack is full (flag can exceed 99), and uses pre-increment causing room[1] to be first element instead of room[0], leading to incorrect indexing and missing capacity check]
        }
        else if (op == 0)
        {
            flag--; // @@ [Decrements flag before checking if stack is empty, which causes underflow check to be off-by-one and prints wrong element index]
            if (flag < 0)
            {
                printf("error ");
            }
            else
            {
                printf("%d ",room[flag+1]); // @@ [Prints room[flag+1] which is the element beyond current top due to earlier pre-increment in push and premature decrement in pop, leading to incorrect output or reading uninitialized memory]
            }
        }
    }
    return 0;
}