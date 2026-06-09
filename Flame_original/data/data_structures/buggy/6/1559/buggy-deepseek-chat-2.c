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
            if (i <= 99) // @@ Error: The condition should be `i < 99` to check if the stack is full. When i is 99, the stack is already full (indices 0-99), so pushing should be rejected. Using `i <= 99` allows a push when i=99, causing an out-of-bounds write.
            {
                i++;
                scanf("%d", &stack[i]);
                
            }
            else
            {
                printf("error ");
            }
        }
        else // @@ Error: This else branch handles both pop (order == 0) and end-of-operations (order == -1). It should only handle pop (order == 0). When order == -1, the program should terminate immediately without performing any pop operation. The reference program uses `else if(b==0)` and a separate `else` for -1.
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