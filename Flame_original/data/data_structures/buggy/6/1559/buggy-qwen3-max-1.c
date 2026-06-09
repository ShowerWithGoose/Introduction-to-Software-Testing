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
            if (i <= 99) // @@ [The condition should be i < 99 to prevent overflow; when i == 99, the stack is full, so pushing another element would exceed capacity.]
            {
                i++;
                scanf("%d", &stack[i]);
                
            }
            else
            {
                printf("error ");
            }
        }
        else
        {
            if (order == 0) // @@ [Missing explicit check for pop operation (0); current else block handles both 0 and -1, causing -1 to trigger a pop or error instead of terminating.]
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
            else if (order == -1) // @@ [Missing handling for termination signal (-1); program should exit when -1 is encountered.]
            {
                break;
            }
        }
    }


    return 0;
}