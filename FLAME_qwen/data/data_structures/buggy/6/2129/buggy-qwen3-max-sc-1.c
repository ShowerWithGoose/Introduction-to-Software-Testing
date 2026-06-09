#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
    int i, n, m, j, stack[100], top = -1;
    scanf("%d", &n);
    while (n != EOF) // @@ [The condition `n != EOF` is incorrect because `scanf` returns the number of successfully read items, not the value of `n`. The loop should check the return value of `scanf` to detect end-of-file or input failure. As written, if the first input is -1 (end marker), the loop still runs incorrectly, and EOF is never assigned to `n`.]
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
        if (n == 0) // @@ [This should be `else if (n == 0)` to avoid checking for pop operation when n is 1. As written, after processing a push (n==1), it will also check n==0 in the same iteration, which is logically wrong.]
        {
            if (top == -1)
            {
                printf("error ");
            }
            else
            {
                printf("%d", stack[top]); // @@ [Missing space after the popped value as required by the output format. Should be `printf("%d ", stack[top]);`]
                stack[top] = 0;
                top--;
            }
        }
    } // @@ [The loop never reads the next operation after processing one, so it runs infinitely. There's no `scanf("%d", &n);` at the end of the loop to read the next command.]

    return 0;
}