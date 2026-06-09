#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
int main()
{
    int op,num,flag=0,room[110]={0}; // @@ [flag should be initialized to -1, or the pop logic should be adjusted to use flag as count]
    while (~scanf("%d",&op))
    {
        if (op == -1)
        {
            break;
        }
        else if (op == 1)
        {
            scanf("%d",&num);
            room[++flag] = num; // @@ [After an error pop (flag becomes -1), this push places element at index 0, causing offset. Should ensure flag is properly reset.]
        }
        else if (op == 0)
        {
            flag--; // @@ [Decrement before check leads to flag=-1 on empty pop; should check emptiness before decrementing.]
            if (flag < 0) // @@ [Condition should check flag==0 before decrement for empty, not flag<0 after decrement.]
            {
                printf("error ");
            }
            else
            {
                printf("%d ",room[flag+1]); // @@ [This line is logically correct but depends on previous errors; should be room[flag] if check before decrement.]
            }
        }
    }
    return 0;
}