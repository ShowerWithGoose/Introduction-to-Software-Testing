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
            if (i <= 99) // @@ [This condition allows i to become 100, which leads to out-of-bounds access. It should be i < 99 or check for i == 99 before incrementing.]
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
            if (order == 0) // @@ [Missing explicit check for order == 0; the else block handles both pop (0) and termination (-1), causing -1 to trigger a pop attempt instead of terminating.]
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
            else if (order == -1) // @@ [Missing handling for termination condition (-1); program should exit when -1 is encountered.]
            {
                break;
            }
        }
    }


    return 0;
}