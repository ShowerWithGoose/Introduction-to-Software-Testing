#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
    int i, n, m, j, stack[100], top = -1;
    scanf("%d", &n);
    while (n != EOF) @@ // [Loop condition should be n != -1; n is never updated, causing infinite loop and Time Limit Exceeded]
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
                printf("%d", stack[top]); @@ // [Missing space after popped element; expected output "567 "]
                stack[top] = 0;
                top--;
            }
        }
    }

    return 0;
}