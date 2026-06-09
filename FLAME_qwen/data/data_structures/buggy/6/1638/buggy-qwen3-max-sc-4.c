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
            scanf("%d ", &num); @@ [The format string "%d " consumes trailing whitespace, which may cause the next input to be read prematurely or block unexpectedly; it should be "%d" without the space. Additionally, the push operation proceeds even when the stack is full, because the assignment `stack[top++] = num;` is not inside an `else` block.]
            if (top > 99)
                printf("error ");
            stack[top++] = num;
            break;
        case 0:
            if (top == 0)
                printf("error ");
            printf("%d ", stack[top-- - 1]); @@ [When the stack is empty (top == 0), this line still executes and accesses stack[-1], causing undefined behavior. The pop print statement must be inside an `else` block.]
        case -1:
            break; @@ [Missing `return 0;` or loop termination: after reading -1, the program should exit immediately as per problem description, but instead it breaks out of the switch and continues the while loop.]
        default:
            break;
        }
    }
    return 0;
}