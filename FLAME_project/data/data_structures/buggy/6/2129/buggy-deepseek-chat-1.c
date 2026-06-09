#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
    int i, n, m, j, stack[100], top = -1;
    scanf("%d", &n);
    while (n != EOF) // @@ The loop condition should be n != -1, not n != EOF, because -1 marks the end of operations, not EOF.
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
                printf("%d", stack[top]); // @@ Missing space after the popped element; should be printf("%d ", stack[top]) to match expected output format.
                stack[top] = 0;
                top--;
            }
        }
    } // @@ Missing scanf for next operation inside the loop, causing an infinite loop (Time Limit Exceeded). Need to add scanf("%d", &n); at the end of the while loop.

    return 0;
}