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
            if ((top - last) == 100)
            {
                printf("error ");
                continue; // @@ Skips reading the integer to be pushed, causing input desynchronization. The value should be read before checking capacity.
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
                printf("%d", *--top); // @@ Missing space after the printed number. Output format requires a space after each popped element.
                *top = 0;
            }
        }
    }
    return 0;
}