#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
    int i, n, m, j, stack[100], top = -1;
    scanf("%d", &n); // @@ Error: reads only the first operation; subsequent operations not read, causing infinite loop or misalignment.
    while (n != EOF) // @@ Error: condition never updates n; should read next operation inside loop and break on -1.
    {
        if (n == 1)
        {
            scanf("%d", &m); // @@ Error: reads a value but does not read next operation after push; leads to incorrect parsing.
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
                printf("%d", stack[top]); // @@ Error: missing space after popped element; expected format requires a trailing space.
                stack[top] = 0;
                top--;
            }
        }
    }

    return 0;
}