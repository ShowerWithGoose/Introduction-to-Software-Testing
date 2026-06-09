#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <ctype.h>

int main()
{
    int zhan[100] = {0};
    int *top, *last;
    top = last = zhan;
    int request, x;
    while (1)
    {
        scanf("%d", &request);
        if (request == -1)
            break;
        else if (request == 1)
        {
            if ((top - last) == 100) // @@ The integer to push is not read when the stack is full; it should be read before this check to keep input synchronized.
            {
                printf("error ");
                continue;
            }
            scanf("%d", &x);
            *top++ = x;
        }
        else if (request == 0)
        {
            if (top == last)
                printf("error ");
            else
            {
                printf("%d", *--top); // @@ Missing a space after the popped element; should be printf("%d ", *--top) to match the required output format.
                *top = 0;
            }
        }
    }
    return 0;
}