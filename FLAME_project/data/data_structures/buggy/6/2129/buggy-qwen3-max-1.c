#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
    int i, n, m, j, stack[100], top = -1;
    scanf("%d", &n);
    while (n != EOF) // @@ [The loop condition is incorrect. It should check for n != -1 as per problem description, not EOF. This causes infinite loop because n never becomes EOF, leading to Time Limit Exceeded.]
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
                printf("%d", stack[top]); // @@ [Missing space after the printed number as required by output format. Should be "%d " instead of "%d".]
                stack[top] = 0;
                top--;
            }
        }
    } // @@ [Missing reading next operation inside loop. After processing current 'n', the next operation must be read via scanf("%d", &n); otherwise, infinite loop occurs.]

    return 0;
}