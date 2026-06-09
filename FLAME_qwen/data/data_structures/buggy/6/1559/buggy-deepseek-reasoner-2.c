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
    while (scanf("%d", &order) != EOF)
    {
        if (order == 1)
        {
            if (i <= 99) // @@ [Error: Condition should be i < 99 to prevent overflow. When i=99, the stack is full, and incrementing i to 100 results in an out-of-bounds write. The push operation should be allowed only when i < 99.]
            {
                i++;
                scanf("%d", &stack[i]);
                
            }
            else
            {
                printf("error ");
            }
        }
        else // @@ [Error: This else branch handles both pop (order == 0) and the end-of-operations marker (order == -1). According to the problem, when order == -1, the program should terminate immediately. However, this code treats -1 the same as 0, causing an incorrect pop and an infinite loop (since -1 is never consumed). The fix is to check for order == 0 inside this else, or add a separate condition for -1.]
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