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
        else // @@ The condition `else` incorrectly handles the termination signal `-1` as a pop operation. When `order` is `-1`, it should stop processing, but instead, it enters this block, checks if the stack is empty (which it might not be, or if it is, prints error), leading to incorrect output like "error" at the end. It should explicitly check for `order == 0` for pop and `order == -1` to break.
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