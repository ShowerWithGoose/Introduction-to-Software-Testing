#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int main()
{
    int stack[100];
    int order;
    int i = -1, flag = 0;
    while (scanf("%d", &order) != EOF) // @@ [The loop does not check for -1 to terminate operations. It should break or return when order == -1.]
    {
        if (order == 1)
        {
            if (i <= 99) // @@ [Condition allows i to increment to 100, causing array out-of-bounds. It should be i < 99 to correctly check if the stack is full.]
            {
                i++;
                scanf("%d", &stack[i]);
                
            }
            else
            {
                printf("error ");
            }
        }
        else // @@ [This else block incorrectly treats -1 as a pop operation. It should be else if (order == 0) to handle pop, and a separate else to terminate on -1.]
        {
            if (i >= 0)
            {
                printf("%d ", stack[i]);
                i--;
            }
            else
            {
                printf("error ");
            }
        }
    }


    return 0;
}