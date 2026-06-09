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
            room[++flag] = num; @@ [Pushes without checking if stack is full (max capacity is 100). Also uses pre-increment, so flag becomes 1 after first push, but room[1] is used instead of room[0], wasting index 0 and potentially exceeding capacity when flag reaches 100.]
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
                printf("%d ",room[flag+1]); @@ [After decrementing flag, it prints room[flag+1], which is the element just popped, but due to using 1-based indexing (from ++flag during push), this logic is inconsistent and may access uninitialized memory or skip correct top element. Also fails to check underflow before decrementing flag.]
            }
        }
    }
    return 0;
}