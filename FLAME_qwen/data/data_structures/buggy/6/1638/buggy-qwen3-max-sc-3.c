#include <stdio.h>
int main()
{
    int stack[101];
    int c;
    int num;
    int top;
    top = 0;
    while (~scanf("%d", &c))
    {
        switch (c)
        {
        case 1:
            scanf("%d ", &num); // @@ [The format string has an extra space, which can cause scanf to wait for additional non-whitespace input after the number, potentially leading to unexpected blocking or incorrect parsing.]
            if (top > 99)
                printf("error ");
            stack[top++] = num; // @@ [This assignment happens even when the stack is full (top > 99), causing a buffer overflow. It should only occur in the else branch.]
            break;
        case 0:
            if (top == 0)
                printf("error ");
            printf("%d ", stack[top-- - 1]); // @@ [When the stack is empty (top == 0), this line still executes and accesses stack[-1], causing undefined behavior. It should be inside an else block.]
        case -1:
            break; // @@ [Missing 'break;' after case 0 causes fall-through into case -1. Also, case -1 should terminate the program (e.g., return 0;) to stop processing further input, as per problem description.]
        default:
            break;
        }
    }
    return 0;
}