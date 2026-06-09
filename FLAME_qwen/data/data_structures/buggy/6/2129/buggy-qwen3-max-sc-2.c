#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
    int i, n, m, j, stack[100], top = -1;
    scanf("%d", &n);
    while (n != EOF) // @@ [The condition 'n != EOF' is incorrect because scanf returns the number of successfully read items, not the value of n. Also, n is never updated inside the loop after the first read, causing an infinite loop or undefined behavior.]
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
        if (n == 0) // @@ [This should be 'else if' to avoid checking pop operation immediately after a push when n is 1, which could lead to unintended behavior. However, the more critical issue is the missing update of 'n' in the loop.]
        {
            if (top == -1)
            {
                printf("error ");
            }
            else
            {
                printf("%d", stack[top]); // @@ [Missing space after %d; output format requires a space after each popped element, including the last one. Should be "%d ".]
                stack[top] = 0;
                top--;
            }
        }
    } // @@ [Loop never reads next operation into 'n', so it runs infinitely or with stale value. Need to read next 'n' at end of loop or in loop condition.]

    return 0;
}