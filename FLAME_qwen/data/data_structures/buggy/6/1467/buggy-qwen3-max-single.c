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
            room[++flag] = num; // @@ [Pushes without checking if stack is full; should check flag < 100 before incrementing and assigning]
        }
        else if (op == 0)
        {
            flag--; // @@ [Decrements flag before checking if stack is empty; if stack is empty (flag=0), this makes flag=-1 and then accesses room[0], which is incorrect]
            if (flag < 0)
            {
                printf("error ");
            }
            else
            {
                printf("%d ",room[flag+1]); // @@ [After decrementing flag, room[flag+1] refers to the element just popped, but due to premature decrement, logic is flawed; also, when flag becomes -1, room[0] is printed instead of handling error properly]
            }
        }
    }
    return 0;
}