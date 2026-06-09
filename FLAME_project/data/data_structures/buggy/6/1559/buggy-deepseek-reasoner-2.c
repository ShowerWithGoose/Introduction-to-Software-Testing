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
    while (scanf("%d", &order) != EOF) // @@ This loop does not check for order -1 to terminate; -1 is treated as a regular operation.
    {
        if (order == 1)
        {
            if (i <= 99)
            {
                i++;
                scanf("%d", &stack[i]);
                
            }
            else
            {
                printf("error ");
            }
        }
        else // @@ This branch treats order -1 as a pop operation, but -1 should indicate end of input and not trigger any stack operation.
        {
            if (i >= 0)
            {
                printf("%d ", stack[i]);
                i--;
            }
            else
            {
                printf("error "); // @@ When order is -1 and after a valid pop (i becomes -1), this prints an extra "error " because -1 is mistakenly handled as a pop on empty stack.
            }
        }
    }


    return 0;
}