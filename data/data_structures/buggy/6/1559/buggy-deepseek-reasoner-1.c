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
            if (i <= 99) // @@ Condition should be i < 99; when i==99 the stack is full and this still allows push, leading to out-of-bounds access
            {
                i++;
                scanf("%d", &stack[i]);
                
            }
            else
            {
                printf("error ");
            }
        }
        else // @@ This else also handles the terminating operation -1, which should instead end the program; only operation 0 should be treated as pop
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