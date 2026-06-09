#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
    int i, n, m, j, stack[100], top = -1;
    scanf("%d", &n); // @@ The program reads only one integer before the loop, but the input may contain multiple operations. This should be inside the loop to read each operation.
    while (n != EOF) // @@ The condition n != EOF is incorrect because scanf returns EOF, not n. The correct condition should be while (scanf("%d", &n) != EOF) or while (~scanf("%d", &n)).
    {
        if (n == 1)
        {
            scanf("%d", &m);
            if (top == 99) // @@ The stack capacity is 100, so the maximum index is 99. However, the condition should check if top >= 99 before incrementing, but the push operation increments top first. The correct check should be if (top >= 99) to prevent overflow.
            {
                printf("error ");
            }
            else
            {
                stack[++top] = m;
            }
        }
        if (n == 0) // @@ This should be else if to avoid checking n == 0 when n == 1 or other values.
        {
            if (top == -1)
            {
                printf("error ");
            }
            else
            {
                printf("%d", stack[top]); // @@ Missing space after the popped element. The output format requires a space after each element.
                stack[top] = 0; // @@ This line is unnecessary and does not affect functionality, but it is not an error per se.
                top--;
            }
        }
    }

    return 0;
}