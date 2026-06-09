#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
    int i, n, m, j, stack[100], top = -1;
    scanf("%d", &n); // @@ The input reading is placed outside the loop, so n is never updated during iteration, causing an infinite loop. It should be part of the loop condition or placed at the end of the loop body.
    while (n != EOF) // @@ n is not updated within the loop, leading to an infinite loop. The condition should check the return value of scanf and properly handle the -1 termination signal.
    {
        if (n == 1)
        {
            scanf("%d", &m);
            if (top == 99)
            {
                printf("error ");
            }
            else
            {
                stack[++top] = m;
            }
        }
        if (n == 0)
        {
            if (top == -1)
            {
                printf("error ");
            }
            else
            {
                printf("%d", stack[top]); // @@ Missing a trailing space after the printed number as required by the output format ("Ensure there is a space after the last element").
                stack[top] = 0;
                top--;
            }
        }
    }

    return 0;
}