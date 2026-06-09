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
            if ((top - last) == 100) // @@ The integer to be pushed (x) must be read before this check to consume input even when the stack is full; otherwise the next iteration will misinterpret x as a request.
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
                printf("%d", *--top); // @@ Missing space after the popped element. Should be "%d " to match the required output format (space after each element, including the last).
                *top = 0;
            }
        }
    }
    return 0;
}