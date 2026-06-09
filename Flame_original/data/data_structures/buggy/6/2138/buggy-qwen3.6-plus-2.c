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
            if ((top - last) == 100) // @@ The integer to be pushed is not consumed from the input stream when the stack is full, causing subsequent reads to be misaligned. The scanf for x should be executed before checking the stack capacity.
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
                printf("%d", *--top); // @@ Missing space after %d in the format string. The output format requires a space after each popped element.
                *top = 0;
            }
        }
    }
    return 0;
}