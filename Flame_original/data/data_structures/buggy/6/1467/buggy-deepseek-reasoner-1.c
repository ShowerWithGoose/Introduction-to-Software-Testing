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
            room[++flag] = num; // @@ [No overflow check: should check if flag < 100 before incrementing. Also, if flag is -1 from a failed pop, this will place element at index 0 but stack empty flag should be 0.]
        }
        else if (op == 0)
        {
            flag--; // @@ [Decrement before checking empty state. This corrupts flag even if stack is empty. Should check flag>0 first, then decrement and pop.]
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