#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
    int i, n, m, j, stack[100], top = -1;
    scanf("%d", &n);
    while (n != EOF) // @@ [The condition `n != EOF` is incorrect because `scanf` returns the number of successfully read items, not the value of `n`. The loop should check the return value of `scanf`, not compare `n` to EOF. This causes infinite loop or undefined behavior.]
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
        if (n == 0) // @@ [This should be `else if (n == 0)` to avoid checking pop operation after a push operation in the same iteration. As written, if `n == 1`, after handling push, it will also check `if (n == 0)` which is false, but if input were malformed or reused, it could cause logic errors. However, more critically, the main loop never reads next `n` after processing an operation, so it loops infinitely with the same `n`.]
        {
            if (top == -1)
            {
                printf("error ");
            }
            else
            {
                printf("%d", stack[top]); // @@ [Missing space after popped value as required by output format; should be `printf("%d ", stack[top]);`]
                stack[top] = 0;
                top--;
            }
        }
    } // @@ [No new operation is read inside the loop, so `n` never changes, leading to infinite loop.]

    return 0;
}