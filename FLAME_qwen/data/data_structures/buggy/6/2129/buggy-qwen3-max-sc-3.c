#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
    int i, n, m, j, stack[100], top = -1;
    scanf("%d", &n);
    while (n != EOF) // @@ [The condition `n != EOF` is incorrect because `scanf` returns the number of successfully read items, not the value of `n`. The loop should check the return value of `scanf` to detect end-of-file or input failure. Also, after reading `-1`, the loop should break per problem description, but this code never reads new values of `n` inside the loop, causing an infinite loop.]
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
        if (n == 0) // @@ [This should be `else if (n == 0)` to avoid checking pop operation when n is 1. As written, if n is 1, it will execute push and then also check if n == 0 (which it isn't), so logically okay here, but more critically, the loop never reads the next operation after handling one, so it gets stuck on the first `n` forever.]
        {
            if (top == -1)
            {
                printf("error ");
            }
            else
            {
                printf("%d", stack[top]); // @@ [Missing space after the popped value as required by output format; should be `printf("%d ", stack[top]);`]
                stack[top] = 0;
                top--;
            }
        }
    } // @@ [The loop never reads a new `n` after the first one, so it will run infinitely on the same `n`. Also, it does not handle the termination condition `-1` to break out of the loop.]

    return 0;
}