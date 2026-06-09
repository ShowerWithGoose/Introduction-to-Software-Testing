#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
    int i, n, m, j, stack[100], top = -1;
    scanf("%d", &n);
    while (n != EOF) // @@ [Error: The condition `n != EOF` is incorrect because `scanf` returns the number of items read, not the value read. The loop should check the return value of `scanf` (e.g., `while (scanf("%d", &n) != EOF)` or `while (~scanf("%d", &n))`). As written, this loop will never terminate correctly because `n` is an integer and will never equal `EOF` (which is typically -1) unless the input contains -1, but -1 is a valid operation to end the sequence, not an EOF indicator.]
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
        if (n == 0) // @@ [Error: This should be `else if (n == 0)` to avoid processing `n` as 0 when it is 1 or -1. Without `else`, after a push operation (n==1), the code will also check `if (n == 0)`, which is false, but more critically, when n is -1 (end of operations), the code will still check `if (n == 0)` and skip it, but the loop will continue indefinitely because the input reading is not updated properly.]
        {
            if (top == -1)
            {
                printf("error ");
            }
            else
            {
                printf("%d", stack[top]); // @@ [Error: Missing space after the popped element. The problem requires a space after each output element, including the last one. Should be `printf("%d ", stack[top]);`]
                stack[top] = 0;
                top--;
            }
        }
    } // @@ [Error: The loop does not handle the case when n == -1 (end of operations). According to the problem, -1 should break the loop, but here the loop continues because the condition `n != EOF` is never false for -1, and no break statement is present. Additionally, after processing n, the next input is never read inside the loop, so the loop will run forever with the same n value.]

    return 0;
}