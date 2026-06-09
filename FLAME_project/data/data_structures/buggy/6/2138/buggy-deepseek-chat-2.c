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
                printf("%d", *--top); // @@ Missing space after the popped element. The expected output requires a space after each popped element, but this code prints the number without a trailing space, causing concatenation of outputs.
                *top = 0;
            }
        }
    }
    return 0;
}