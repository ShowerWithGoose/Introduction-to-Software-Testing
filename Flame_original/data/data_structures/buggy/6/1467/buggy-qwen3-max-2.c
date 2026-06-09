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
            room[++flag] = num; // @@ [Pushes without checking stack capacity; may overflow beyond 100 elements]
        }
        else if (op == 0)
        {
            flag--; // @@ [Decrements flag before checking if stack is empty, leading to incorrect index and logic]
            if (flag < 0)
            {
                printf("error ");
            }
            else
            {
                printf("%d ",room[flag+1]); // @@ [Prints room[flag+1] which is the element after decrement, but due to premature decrement, this may access invalid or wrong element]
            }
        }
    }
    return 0;
}