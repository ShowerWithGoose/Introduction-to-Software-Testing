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
            if (i <= 99) // @@ Error: The condition should check if the stack is not full before pushing. Since i starts at -1 and the maximum index is 99, the condition should be `i < 99` to prevent overflow when i becomes 99. Using `i <= 99` allows pushing when i is 99, which would write to stack[100] (out of bounds).
            {
                i++;
                scanf("%d", &stack[i]);
                
            }
            else
            {
                printf("error ");
            }
        }
        else // @@ Error: This else branch handles both pop (order == 0) and end-of-operations (order == -1). The problem specifies that -1 ends the operations, so the program should check for order == 0 before performing a pop. Currently, when order == -1, it incorrectly attempts to pop from the stack, which may produce wrong output or cause an error.
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