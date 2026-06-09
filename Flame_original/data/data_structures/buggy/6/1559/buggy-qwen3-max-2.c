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
            if (i <= 99) // @@ [This condition allows i to become 100, which leads to out-of-bounds access. It should be i < 99 or i == 99 for error check.]
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