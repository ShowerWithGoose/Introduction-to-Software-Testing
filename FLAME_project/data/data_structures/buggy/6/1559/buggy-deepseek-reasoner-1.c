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
    while (scanf("%d", &order) != EOF) // @@ This loop does not stop when order is -1; it continues to process -1 as a pop operation, causing incorrect output. Should check order before processing.
    {
        if (order == 1)
        {
            if (i <= 99) // @@ Condition should be i < 99 to avoid out-of-bounds access when i becomes 100.
            {
                i++;
                scanf("%d", &stack[i]);
                
            }
            else
            {
                printf("error ");
            }
        }
        else // @@ This else branch also handles order == -1, which should terminate the program, not perform a pop.
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