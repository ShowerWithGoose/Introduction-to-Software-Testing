#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
    int i, n, m, j, stack[100], top = -1;
    scanf("%d", &n);
    while (n != EOF) // @@ The loop condition should check for -1 (end of operations), not EOF. Using EOF causes an infinite loop because scanf returns 1 (success) and n never equals EOF, leading to Time Limit Exceeded.
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
                printf("%d", stack[top]); // @@ Missing space after the popped element. The expected output requires a space after each element (e.g., "567 "), but this prints "567" without a trailing space.
                stack[top] = 0;
                top--;
            }
        }
    }

    return 0;
}