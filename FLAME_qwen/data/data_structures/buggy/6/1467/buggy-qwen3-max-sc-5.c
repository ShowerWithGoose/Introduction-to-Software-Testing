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
            room[++flag] = num; @@ [Pushes without checking stack capacity; should check if flag < 100 before incrementing and assigning]
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
                printf("%d ",room[flag+1]); @@ [After decrementing flag, the top element is at index flag, not flag+1; this prints a stale or uninitialized value]
            }
        }
    }
    return 0;
}