#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
    int i, n, m, j, stack[100], top = -1;
    scanf("%d", &n);
    while (n != EOF) // @@ [The condition 'n != EOF' is incorrect because scanf returns the number of successfully read items, not the value of n. Also, if scanf fails (e.g., at end of input), n remains unchanged, leading to infinite loop. Should check return value of scanf instead.]
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
        if (n == 0) // @@ [This should be 'else if' to avoid checking pop operation immediately after a push when n==1, which could cause unintended behavior if input sequence has consecutive operations. However, more critically, the loop never reads next operation after processing one, so it will infinitely process the same n.]
        {
            if (top == -1)
            {
                printf("error ");
            }
            else
            {
                printf("%d", stack[top]); // @@ [Missing space after %d as required by output format; should be "%d "]
                stack[top] = 0;
                top--;
            }
        }
    } // @@ [No code inside loop reads the next operation; 'n' never updates after initial read, causing infinite loop.]

    return 0;
}